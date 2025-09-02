#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void demonstrate_memory_leaks(void);
void demonstrate_double_free_error(void);
void demonstrate_use_after_free(void);
void demonstrate_buffer_overflow(void);
void demonstrate_uninitialized_memory(void);
void demonstrate_safe_practices(void);
void demonstrate_debugging_techniques(void);
void leak_function(void);

// Safe memory management functions
void* safe_malloc(size_t size);
void safe_free(void **ptr);
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} SafeArray;
SafeArray* create_safe_array(size_t initial_capacity);
void destroy_safe_array(SafeArray **arr);
int add_to_safe_array(SafeArray *arr, int value);

// Global counters for tracking
static size_t allocations = 0;
static size_t deallocations = 0;

int main(void) {
    printf("=== Memory Leaks & Debugging Demo ===\n\n");
    
    printf("Note: This demo shows common memory errors for educational purposes.\n");
    printf("In production code, these patterns should be avoided!\n\n");
    
    demonstrate_memory_leaks();
    demonstrate_double_free_error();
    demonstrate_use_after_free();
    demonstrate_buffer_overflow();
    demonstrate_uninitialized_memory();
    demonstrate_safe_practices();
    demonstrate_debugging_techniques();
    
    printf("=== Demo Complete ===\n");
    printf("Final allocation stats: %zu allocations, %zu deallocations\n", 
           allocations, deallocations);
    if (allocations != deallocations) {
        printf("⚠️  Memory leak detected: %zu unfreed allocations\n", 
               allocations - deallocations);
    } else {
        printf("✅ All memory properly freed\n");
    }
    
    return 0;
}

void demonstrate_memory_leaks(void) {
    printf("1. MEMORY LEAKS\n");
    printf("----------------------------------------\n");
    
    printf("Example 1: Simple memory leak\n");
    {
        int *leaked_ptr = malloc(sizeof(int));
        if (leaked_ptr) {
            *leaked_ptr = 42;
            printf("  Allocated memory for int: %d\n", *leaked_ptr);
            // Missing free(leaked_ptr) - INTENTIONAL LEAK for demo
            allocations++;
            printf("  ⚠️  Memory not freed - this is a leak!\n");
        }
    }
    
    printf("\nExample 2: Loop-based memory leak\n");
    for (int i = 0; i < 3; i++) {
        char *buffer = malloc(100);
        if (buffer) {
            snprintf(buffer, 100, "Buffer %d", i);
            printf("  Created: %s\n", buffer);
            allocations++;
            // Missing free(buffer) - INTENTIONAL LEAK for demo
        }
    }
    printf("  ⚠️  3 buffers leaked in loop!\n");
    
    printf("\nExample 3: Function-scope leak\n");
    leak_function();
    printf("  ⚠️  Function returned without freeing memory!\n");
    
    printf("\nExample 4: Conditional leak\n");
    int *conditional_ptr = malloc(sizeof(int));
    if (conditional_ptr) {
        *conditional_ptr = 100;
        allocations++;
        
        if (*conditional_ptr > 50) {
            printf("  Value %d is greater than 50\n", *conditional_ptr);
            // Early return without free - LEAK
            printf("  ⚠️  Early return causes memory leak!\n");
            goto skip_free;  // Simulating early return
        }
        
        free(conditional_ptr);
        deallocations++;
        skip_free:;
    }
    printf("\n");
}

void demonstrate_double_free_error(void) {
    printf("2. DOUBLE FREE ERROR\n");
    printf("----------------------------------------\n");
    
    printf("Example: Double free (commented out to prevent crash)\n");
    int *ptr = malloc(sizeof(int));
    if (ptr) {
        *ptr = 123;
        printf("  Allocated and set value: %d\n", *ptr);
        allocations++;
        
        free(ptr);
        deallocations++;
        printf("  ✅ First free() successful\n");
        
        // free(ptr);  // ERROR: Double free - commented out to prevent crash
        printf("  ⚠️  Second free(ptr) would cause double-free error!\n");
        printf("  This line is commented out to prevent program crash\n");
        
        // ptr = NULL;  // This would prevent the double free
        printf("  💡 Setting ptr = NULL after free prevents double free\n");
    }
    printf("\n");
}

void demonstrate_use_after_free(void) {
    printf("3. USE AFTER FREE\n");
    printf("----------------------------------------\n");
    
    printf("Example: Use after free (dangerous - may show garbage or crash)\n");
    int *ptr = malloc(sizeof(int));
    if (ptr) {
        *ptr = 456;
        printf("  Original value: %d\n", *ptr);
        allocations++;
        
        free(ptr);
        deallocations++;
        printf("  ✅ Memory freed\n");
        
        // *ptr = 789;  // ERROR: Use after free - commented out
        printf("  ⚠️  Writing to freed memory (*ptr = 789) is undefined behavior!\n");
        printf("  This could corrupt memory or crash the program\n");
        
        // printf("  Freed memory contains: %d\n", *ptr);  // Also dangerous
        printf("  ⚠️  Reading freed memory is also undefined behavior!\n");
        
        ptr = NULL;  // Good practice
        printf("  ✅ Pointer set to NULL to prevent accidental use\n");
    }
    printf("\n");
}

void demonstrate_buffer_overflow(void) {
    printf("4. BUFFER OVERFLOW\n");
    printf("----------------------------------------\n");
    
    printf("Example 1: Array bounds overflow\n");
    int *arr = malloc(5 * sizeof(int));
    if (arr) {
        allocations++;
        
        // Initialize array properly
        for (int i = 0; i < 5; i++) {
            arr[i] = i * 10;
        }
        
        printf("  Array contents: [");
        for (int i = 0; i < 5; i++) {
            printf("%d", arr[i]);
            if (i < 4) printf(", ");
        }
        printf("]\n");
        
        // arr[10] = 999;  // ERROR: Buffer overflow - commented out
        printf("  ⚠️  Writing arr[10] = 999 would overflow the 5-element array!\n");
        printf("  This could corrupt adjacent memory\n");
        
        // Safe bounds checking
        int index = 10;
        if (index >= 0 && index < 5) {
            arr[index] = 999;
        } else {
            printf("  ✅ Bounds check prevented overflow at index %d\n", index);
        }
        
        free(arr);
        deallocations++;
    }
    
    printf("\nExample 2: String buffer overflow\n");
    char *buffer = malloc(10);
    if (buffer) {
        allocations++;
        
        // Safe string copy
        const char *source = "Hello";
        strncpy(buffer, source, 9);
        buffer[9] = '\0';  // Ensure null termination
        printf("  Safe copy: \"%s\"\n", buffer);
        
        // strcpy(buffer, "This string is way too long for the buffer");  // OVERFLOW
        printf("  ⚠️  Copying long string would overflow 10-byte buffer!\n");
        printf("  Always use strncpy() or check string length\n");
        
        free(buffer);
        deallocations++;
    }
    printf("\n");
}

void demonstrate_uninitialized_memory(void) {
    printf("5. UNINITIALIZED MEMORY\n");
    printf("----------------------------------------\n");
    
    printf("Example: Reading uninitialized memory\n");
    int *uninit_ptr = malloc(sizeof(int));
    if (uninit_ptr) {
        allocations++;
        
        // printf("Uninitialized value: %d\n", *uninit_ptr);  // Garbage value
        printf("  ⚠️  Reading uninitialized memory gives garbage values!\n");
        printf("  Always initialize allocated memory\n");
        
        // Proper initialization
        *uninit_ptr = 0;  // or any meaningful value
        printf("  ✅ After initialization: %d\n", *uninit_ptr);
        
        free(uninit_ptr);
        deallocations++;
    }
    
    printf("\nComparison: malloc vs calloc\n");
    printf("  malloc: Allocates uninitialized memory (faster)\n");
    printf("  calloc: Allocates zero-initialized memory (safer)\n");
    
    int *malloc_array = malloc(3 * sizeof(int));
    int *calloc_array = calloc(3, sizeof(int));
    
    if (malloc_array && calloc_array) {
        allocations += 2;
        
        printf("  calloc array: [%d, %d, %d] (guaranteed zeros)\n", 
               calloc_array[0], calloc_array[1], calloc_array[2]);
        
        // Initialize malloc array for safe printing
        malloc_array[0] = malloc_array[1] = malloc_array[2] = 0;
        printf("  malloc array after manual init: [%d, %d, %d]\n", 
               malloc_array[0], malloc_array[1], malloc_array[2]);
        
        free(malloc_array);
        free(calloc_array);
        deallocations += 2;
    }
    printf("\n");
}

void demonstrate_safe_practices(void) {
    printf("6. SAFE MEMORY MANAGEMENT PRACTICES\n");
    printf("----------------------------------------\n");
    
    printf("Practice 1: Safe allocation wrapper\n");
    int *safe_ptr = (int*)safe_malloc(sizeof(int));
    if (safe_ptr) {
        *safe_ptr = 777;
        printf("  ✅ Safe allocation successful: %d\n", *safe_ptr);
        safe_free((void**)&safe_ptr);
        printf("  ✅ Safe deallocation, pointer is now NULL\n");
    }
    
    printf("\nPractice 2: RAII-style resource management\n");
    SafeArray *arr = create_safe_array(5);
    if (arr) {
        printf("  ✅ Created safe array with capacity %zu\n", arr->capacity);
        
        // Add some elements
        for (int i = 0; i < 3; i++) {
            if (add_to_safe_array(arr, i * 100) == 0) {
                printf("  Added element: %d\n", i * 100);
            }
        }
        
        printf("  Array contents: [");
        for (size_t i = 0; i < arr->size; i++) {
            printf("%d", arr->data[i]);
            if (i < arr->size - 1) printf(", ");
        }
        printf("]\n");
        
        destroy_safe_array(&arr);
        printf("  ✅ Safe array destroyed, pointer is now NULL\n");
    }
    
    printf("\nPractice 3: Defensive programming\n");
    char *test_ptr = malloc(20);
    if (test_ptr) {
        allocations++;
        strcpy(test_ptr, "Test");
        printf("  Created string: \"%s\"\n", test_ptr);
        
        // Defensive free
        if (test_ptr) {
            free(test_ptr);
            test_ptr = NULL;
            deallocations++;
            printf("  ✅ Defensively freed and nullified pointer\n");
        }
        
        // Safe to call again
        if (test_ptr) {
            free(test_ptr);  // Won't execute
        } else {
            printf("  ✅ Second free attempt safely skipped (pointer is NULL)\n");
        }
    }
    printf("\n");
}

void demonstrate_debugging_techniques(void) {
    printf("7. DEBUGGING TECHNIQUES\n");
    printf("----------------------------------------\n");
    
    printf("Technique 1: Allocation tracking\n");
    printf("  Current stats: %zu allocations, %zu deallocations\n", 
           allocations, deallocations);
    printf("  Outstanding allocations: %zu\n", allocations - deallocations);
    
    printf("\nTechnique 2: Debug output\n");
    #ifdef DEBUG
    printf("  DEBUG mode enabled - verbose output active\n");
    #else
    printf("  Compile with -DDEBUG for verbose debugging output\n");
    #endif
    
    printf("\nTechnique 3: Valgrind usage\n");
    printf("  Compile: gcc -g -o program program.c\n");
    printf("  Run: valgrind --leak-check=full ./program\n");
    printf("  Look for: 'definitely lost', 'possibly lost' messages\n");
    
    printf("\nTechnique 4: AddressSanitizer\n");
    printf("  Compile: gcc -fsanitize=address -g -o program program.c\n");
    printf("  Run: ./program\n");
    printf("  Provides immediate feedback on memory errors\n");
    
    printf("\nTechnique 5: Static analysis\n");
    printf("  Enable warnings: gcc -Wall -Wextra -Werror\n");
    printf("  Use tools: clang-static-analyzer, cppcheck\n");
    printf("  Regular code reviews\n");
    
    printf("\nTechnique 6: Testing strategies\n");
    printf("  Test with small allocations\n");
    printf("  Test with large allocations\n");
    printf("  Test allocation failures\n");
    printf("  Test edge cases and boundary conditions\n");
    printf("\n");
}

// Safe memory management implementations
void* safe_malloc(size_t size) {
    if (size == 0) {
        return NULL;
    }
    
    void *ptr = malloc(size);
    if (ptr) {
        allocations++;
        memset(ptr, 0, size);  // Initialize to zero
    }
    return ptr;
}

void safe_free(void **ptr) {
    if (ptr && *ptr) {
        free(*ptr);
        *ptr = NULL;
        deallocations++;
    }
}

SafeArray* create_safe_array(size_t initial_capacity) {
    if (initial_capacity == 0) {
        return NULL;
    }
    
    SafeArray *arr = malloc(sizeof(SafeArray));
    if (!arr) {
        return NULL;
    }
    allocations++;
    
    arr->data = malloc(initial_capacity * sizeof(int));
    if (!arr->data) {
        free(arr);
        deallocations++;
        return NULL;
    }
    allocations++;
    
    arr->size = 0;
    arr->capacity = initial_capacity;
    
    return arr;
}

void destroy_safe_array(SafeArray **arr) {
    if (arr && *arr) {
        if ((*arr)->data) {
            free((*arr)->data);
            deallocations++;
        }
        free(*arr);
        deallocations++;
        *arr = NULL;
    }
}

int add_to_safe_array(SafeArray *arr, int value) {
    if (!arr || !arr->data) {
        return -1;  // Invalid array
    }
    
    if (arr->size >= arr->capacity) {
        return -2;  // Array full
    }
    
    arr->data[arr->size] = value;
    arr->size++;
    return 0;  // Success
}

void leak_function(void) {
    double *data = malloc(10 * sizeof(double));
    if (data) {
        data[0] = 3.14159;
        printf("  Function allocated array, first element: %.5f\n", data[0]);
        allocations++;
        // Function returns without freeing - LEAK
    }
}

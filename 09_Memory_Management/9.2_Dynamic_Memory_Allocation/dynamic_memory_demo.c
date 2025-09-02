#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void demonstrate_malloc_free(void);
void demonstrate_calloc(void);
void demonstrate_realloc(void);
void demonstrate_dynamic_strings(void);
void demonstrate_dynamic_2d_arrays(void);
void demonstrate_error_handling(void);
int* safe_malloc_int_array(size_t count);
void print_array(const char* name, int* arr, size_t size);

int main(void) {
    printf("=== Dynamic Memory Allocation Demo ===\n\n");
    
    demonstrate_malloc_free();
    demonstrate_calloc();
    demonstrate_realloc();
    demonstrate_dynamic_strings();
    demonstrate_dynamic_2d_arrays();
    demonstrate_error_handling();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_malloc_free(void) {
    printf("1. MALLOC AND FREE\n");
    printf("----------------------------------------\n");
    
    // Basic malloc usage
    printf("Basic malloc usage:\n");
    int *single_int = malloc(sizeof(int));
    if (single_int != NULL) {
        *single_int = 42;
        printf("  Allocated int: %d at address %p\n", *single_int, (void*)single_int);
        free(single_int);
        single_int = NULL;  // Good practice
        printf("  Memory freed and pointer set to NULL\n");
    }
    
    // Array allocation
    printf("\nArray allocation:\n");
    int size = 5;
    int *array = malloc(size * sizeof(int));
    if (array != NULL) {
        printf("  Allocated array of %d integers\n", size);
        
        // Initialize array
        for (int i = 0; i < size; i++) {
            array[i] = (i + 1) * 10;
        }
        
        printf("  Array contents: [");
        for (int i = 0; i < size; i++) {
            printf("%d", array[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]\n");
        
        printf("  Array address: %p\n", (void*)array);
        printf("  Element addresses:\n");
        for (int i = 0; i < size; i++) {
            printf("    array[%d]: %p\n", i, (void*)&array[i]);
        }
        
        free(array);
        array = NULL;
        printf("  Array memory freed\n");
    }
    
    // Large allocation
    printf("\nLarge allocation:\n");
    size_t large_size = 1000000;  // 1 million integers
    int *large_array = malloc(large_size * sizeof(int));
    if (large_array != NULL) {
        printf("  Successfully allocated %zu MB\n", 
               (large_size * sizeof(int)) / (1024 * 1024));
        
        // Initialize first and last elements
        large_array[0] = 1;
        large_array[large_size - 1] = 999999;
        
        printf("  First element: %d\n", large_array[0]);
        printf("  Last element: %d\n", large_array[large_size - 1]);
        
        free(large_array);
        printf("  Large array freed\n");
    }
    printf("\n");
}

void demonstrate_calloc(void) {
    printf("2. CALLOC (ZERO-INITIALIZED ALLOCATION)\n");
    printf("----------------------------------------\n");
    
    int size = 8;
    
    // malloc vs calloc comparison
    printf("malloc vs calloc comparison:\n");
    
    // Using malloc (uninitialized)
    int *malloc_array = malloc(size * sizeof(int));
    if (malloc_array != NULL) {
        printf("  malloc array (uninitialized): [");
        for (int i = 0; i < size; i++) {
            printf("%d", malloc_array[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]\n");
        free(malloc_array);
    }
    
    // Using calloc (zero-initialized)
    int *calloc_array = calloc(size, sizeof(int));
    if (calloc_array != NULL) {
        printf("  calloc array (zero-initialized): [");
        for (int i = 0; i < size; i++) {
            printf("%d", calloc_array[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]\n");
        
        // Modify some elements
        calloc_array[0] = 100;
        calloc_array[size - 1] = 200;
        
        printf("  After modification: [");
        for (int i = 0; i < size; i++) {
            printf("%d", calloc_array[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]\n");
        
        free(calloc_array);
    }
    
    // Practical calloc usage
    printf("\nPractical calloc usage:\n");
    typedef struct {
        int id;
        char name[20];
        float score;
    } Student;
    
    int num_students = 3;
    Student *students = calloc(num_students, sizeof(Student));
    if (students != NULL) {
        printf("  Allocated %d student records (zero-initialized)\n", num_students);
        
        // Initialize student data
        students[0] = (Student){1, "Alice", 95.5f};
        students[1] = (Student){2, "Bob", 87.2f};
        students[2] = (Student){3, "Charlie", 92.8f};
        
        printf("  Student records:\n");
        for (int i = 0; i < num_students; i++) {
            printf("    ID: %d, Name: %s, Score: %.1f\n", 
                   students[i].id, students[i].name, students[i].score);
        }
        
        free(students);
        printf("  Student records freed\n");
    }
    printf("\n");
}

void demonstrate_realloc(void) {
    printf("3. REALLOC (RESIZE ALLOCATION)\n");
    printf("----------------------------------------\n");
    
    // Start with small array
    int initial_size = 3;
    int *dynamic_array = malloc(initial_size * sizeof(int));
    if (dynamic_array == NULL) {
        printf("  Initial allocation failed\n");
        return;
    }
    
    // Initialize initial array
    for (int i = 0; i < initial_size; i++) {
        dynamic_array[i] = i + 1;
    }
    
    printf("Initial array (size %d):\n", initial_size);
    print_array("  dynamic_array", dynamic_array, initial_size);
    printf("  Address: %p\n", (void*)dynamic_array);
    
    // Expand array
    int new_size = 6;
    printf("\nExpanding to size %d:\n", new_size);
    int *temp = realloc(dynamic_array, new_size * sizeof(int));
    if (temp != NULL) {
        dynamic_array = temp;
        printf("  Realloc successful\n");
        printf("  New address: %p\n", (void*)dynamic_array);
        
        // Initialize new elements
        for (int i = initial_size; i < new_size; i++) {
            dynamic_array[i] = (i + 1) * 10;
        }
        
        print_array("  expanded_array", dynamic_array, new_size);
    } else {
        printf("  Realloc failed - original array still valid\n");
        free(dynamic_array);
        return;
    }
    
    // Shrink array
    int smaller_size = 4;
    printf("\nShrinking to size %d:\n", smaller_size);
    temp = realloc(dynamic_array, smaller_size * sizeof(int));
    if (temp != NULL) {
        dynamic_array = temp;
        printf("  Shrink successful\n");
        printf("  Address: %p\n", (void*)dynamic_array);
        print_array("  shrunk_array", dynamic_array, smaller_size);
    }
    
    // Demonstrate realloc with NULL (equivalent to malloc)
    printf("\nrealloc with NULL pointer (equivalent to malloc):\n");
    int *new_array = realloc(NULL, 5 * sizeof(int));
    if (new_array != NULL) {
        for (int i = 0; i < 5; i++) {
            new_array[i] = i * i;
        }
        print_array("  new_array", new_array, 5);
        free(new_array);
    }
    
    // Demonstrate realloc with size 0 (equivalent to free)
    printf("\nrealloc with size 0 (equivalent to free):\n");
    dynamic_array = realloc(dynamic_array, 0);
    printf("  Array freed using realloc(ptr, 0)\n");
    printf("\n");
}

void demonstrate_dynamic_strings(void) {
    printf("4. DYNAMIC STRING MANIPULATION\n");
    printf("----------------------------------------\n");
    
    // Dynamic string creation
    printf("Dynamic string creation:\n");
    const char *source = "Hello, World!";
    size_t len = strlen(source);
    char *dynamic_string = malloc(len + 1);  // +1 for null terminator
    
    if (dynamic_string != NULL) {
        strcpy(dynamic_string, source);
        printf("  Created string: \"%s\"\n", dynamic_string);
        printf("  Length: %zu, Allocated: %zu bytes\n", strlen(dynamic_string), len + 1);
        
        // String concatenation with realloc
        const char *append = " How are you?";
        size_t append_len = strlen(append);
        size_t new_len = len + append_len;
        
        char *temp = realloc(dynamic_string, new_len + 1);
        if (temp != NULL) {
            dynamic_string = temp;
            strcat(dynamic_string, append);
            printf("  After concatenation: \"%s\"\n", dynamic_string);
            printf("  New length: %zu, Allocated: %zu bytes\n", 
                   strlen(dynamic_string), new_len + 1);
        }
        
        free(dynamic_string);
    }
    
    // Dynamic string array
    printf("\nDynamic string array:\n");
    int num_strings = 4;
    char **string_array = malloc(num_strings * sizeof(char*));
    
    if (string_array != NULL) {
        // Allocate individual strings
        string_array[0] = malloc(strlen("Apple") + 1);
        string_array[1] = malloc(strlen("Banana") + 1);
        string_array[2] = malloc(strlen("Cherry") + 1);
        string_array[3] = malloc(strlen("Date") + 1);
        
        // Copy strings
        strcpy(string_array[0], "Apple");
        strcpy(string_array[1], "Banana");
        strcpy(string_array[2], "Cherry");
        strcpy(string_array[3], "Date");
        
        printf("  String array contents:\n");
        for (int i = 0; i < num_strings; i++) {
            printf("    [%d]: \"%s\" at %p\n", i, string_array[i], (void*)string_array[i]);
        }
        
        // Free individual strings
        for (int i = 0; i < num_strings; i++) {
            free(string_array[i]);
        }
        free(string_array);
        printf("  All strings freed\n");
    }
    printf("\n");
}

void demonstrate_dynamic_2d_arrays(void) {
    printf("5. DYNAMIC 2D ARRAYS\n");
    printf("----------------------------------------\n");
    
    int rows = 3, cols = 4;
    
    printf("Creating %dx%d matrix:\n", rows, cols);
    
    // Allocate array of row pointers
    int **matrix = malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("  Failed to allocate row pointers\n");
        return;
    }
    
    // Allocate each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("  Failed to allocate row %d\n", i);
            // Free previously allocated rows
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return;
        }
    }
    
    printf("  Matrix allocated successfully\n");
    
    // Initialize matrix
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }
    
    // Print matrix
    printf("  Matrix contents:\n");
    for (int i = 0; i < rows; i++) {
        printf("    [");
        for (int j = 0; j < cols; j++) {
            printf("%2d", matrix[i][j]);
            if (j < cols - 1) printf(", ");
        }
        printf("]\n");
    }
    
    // Print addresses
    printf("  Row addresses:\n");
    for (int i = 0; i < rows; i++) {
        printf("    matrix[%d]: %p\n", i, (void*)matrix[i]);
    }
    
    // Free matrix (reverse order)
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    printf("  Matrix freed\n");
    
    // Alternative: Single allocation for 2D array
    printf("\nAlternative: Single allocation approach:\n");
    int *flat_matrix = malloc(rows * cols * sizeof(int));
    if (flat_matrix != NULL) {
        printf("  Allocated flat array for %dx%d matrix\n", rows, cols);
        
        // Initialize using 2D indexing: matrix[i][j] = flat_matrix[i * cols + j]
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                flat_matrix[i * cols + j] = (i + 1) * 10 + (j + 1);
            }
        }
        
        printf("  Matrix contents (flat allocation):\n");
        for (int i = 0; i < rows; i++) {
            printf("    [");
            for (int j = 0; j < cols; j++) {
                printf("%2d", flat_matrix[i * cols + j]);
                if (j < cols - 1) printf(", ");
            }
            printf("]\n");
        }
        
        free(flat_matrix);
        printf("  Flat matrix freed\n");
    }
    printf("\n");
}

void demonstrate_error_handling(void) {
    printf("6. ERROR HANDLING\n");
    printf("----------------------------------------\n");
    
    printf("Proper error handling examples:\n");
    
    // Example 1: Check malloc return value
    printf("\n1. Always check malloc return value:\n");
    size_t huge_size = SIZE_MAX / 2;  // Very large allocation
    void *ptr = malloc(huge_size);
    if (ptr == NULL) {
        printf("  ✓ malloc failed gracefully (expected for huge allocation)\n");
        printf("  ✓ Program continues safely\n");
    } else {
        printf("  Unexpected: huge allocation succeeded\n");
        free(ptr);
    }
    
    // Example 2: Safe allocation function
    printf("\n2. Safe allocation wrapper:\n");
    int *safe_array = safe_malloc_int_array(10);
    if (safe_array != NULL) {
        printf("  ✓ Safe allocation succeeded\n");
        for (int i = 0; i < 10; i++) {
            safe_array[i] = i * i;
        }
        print_array("  safe_array", safe_array, 10);
        free(safe_array);
        printf("  ✓ Memory freed\n");
    }
    
    // Example 3: Avoiding double free
    printf("\n3. Avoiding double free:\n");
    int *test_ptr = malloc(sizeof(int));
    if (test_ptr != NULL) {
        *test_ptr = 123;
        printf("  Allocated and initialized: %d\n", *test_ptr);
        
        free(test_ptr);
        test_ptr = NULL;  // Prevent accidental reuse
        printf("  ✓ Memory freed and pointer nullified\n");
        
        // This is now safe (no-op)
        free(test_ptr);
        printf("  ✓ Second free() is safe (no-op with NULL)\n");
    }
    
    // Example 4: Memory leak prevention
    printf("\n4. Memory leak prevention:\n");
    printf("  Always pair malloc/calloc with free\n");
    printf("  Set pointers to NULL after freeing\n");
    printf("  Use tools like Valgrind to detect leaks\n");
    printf("  Consider using static analysis tools\n");
    printf("\n");
}

// Helper functions
int* safe_malloc_int_array(size_t count) {
    if (count == 0) {
        return NULL;
    }
    
    // Check for overflow
    if (count > SIZE_MAX / sizeof(int)) {
        printf("  Error: Array size too large\n");
        return NULL;
    }
    
    int *array = malloc(count * sizeof(int));
    if (array == NULL) {
        printf("  Error: Memory allocation failed\n");
        return NULL;
    }
    
    // Initialize to zero
    for (size_t i = 0; i < count; i++) {
        array[i] = 0;
    }
    
    return array;
}

void print_array(const char* name, int* arr, size_t size) {
    printf("%s: [", name);
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

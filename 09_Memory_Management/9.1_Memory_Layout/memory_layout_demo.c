#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

// Global variables (Data segment)
int global_initialized = 100;
char global_string[] = "Hello World";

// Global uninitialized variables (BSS segment)
int global_uninitialized;
static int static_uninitialized;
static int static_initialized = 200;

// Function prototypes
void demonstrate_stack_growth(int depth);
void demonstrate_memory_segments(void);
void demonstrate_stack_vs_heap(void);
void demonstrate_memory_alignment(void);
void print_address_info(const char* name, void* addr, const char* segment);

int main(void) {
    printf("=== Memory Layout Demo ===\n\n");
    
    demonstrate_memory_segments();
    demonstrate_stack_vs_heap();
    demonstrate_stack_growth(0);
    demonstrate_memory_alignment();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_memory_segments(void) {
    printf("1. MEMORY SEGMENTS\n");
    printf("----------------------------------------\n");
    
    // Local variables (Stack)
    int local_var = 42;
    char local_array[10] = "test";
    
    // Dynamic allocation (Heap)
    int *heap_var = malloc(sizeof(int));
    *heap_var = 300;
    
    printf("Memory segment addresses:\n\n");
    
    // Code segment
    print_address_info("main function", (void*)main, "Code Segment");
    print_address_info("demonstrate_memory_segments", (void*)demonstrate_memory_segments, "Code Segment");
    
    printf("\n");
    
    // Data segment
    print_address_info("global_initialized", &global_initialized, "Data Segment");
    print_address_info("global_string", global_string, "Data Segment");
    print_address_info("static_initialized", &static_initialized, "Data Segment");
    
    printf("\n");
    
    // BSS segment
    print_address_info("global_uninitialized", &global_uninitialized, "BSS Segment");
    print_address_info("static_uninitialized", &static_uninitialized, "BSS Segment");
    
    printf("\n");
    
    // Stack
    print_address_info("local_var", &local_var, "Stack");
    print_address_info("local_array", local_array, "Stack");
    
    printf("\n");
    
    // Heap
    print_address_info("heap_var (content)", heap_var, "Heap");
    print_address_info("heap_var (pointer)", &heap_var, "Stack");
    
    printf("\nValues:\n");
    printf("  global_initialized = %d\n", global_initialized);
    printf("  global_uninitialized = %d (auto-initialized to 0)\n", global_uninitialized);
    printf("  local_var = %d\n", local_var);
    printf("  *heap_var = %d\n", *heap_var);
    
    free(heap_var);
    printf("\n");
}

void demonstrate_stack_vs_heap(void) {
    printf("2. STACK VS HEAP COMPARISON\n");
    printf("----------------------------------------\n");
    
    // Stack allocation
    printf("Stack allocation:\n");
    int stack_array[1000];  // 4KB on stack
    printf("  stack_array[0] address: %p\n", (void*)&stack_array[0]);
    printf("  stack_array[999] address: %p\n", (void*)&stack_array[999]);
    printf("  Size: %zu bytes\n", sizeof(stack_array));
    printf("  Allocation: Automatic, fast\n");
    printf("  Deallocation: Automatic when function exits\n");
    
    printf("\nHeap allocation:\n");
    int *heap_array = malloc(1000 * sizeof(int));  // 4KB on heap
    if (heap_array != NULL) {
        printf("  heap_array[0] address: %p\n", (void*)&heap_array[0]);
        printf("  heap_array[999] address: %p\n", (void*)&heap_array[999]);
        printf("  Size: %zu bytes\n", 1000 * sizeof(int));
        printf("  Allocation: Manual, slower\n");
        printf("  Deallocation: Manual with free()\n");
        
        // Initialize some values
        heap_array[0] = 100;
        heap_array[999] = 200;
        printf("  Values: heap_array[0] = %d, heap_array[999] = %d\n", 
               heap_array[0], heap_array[999]);
        
        free(heap_array);
    }
    
    // Address comparison
    int stack_var = 10;
    int *heap_var = malloc(sizeof(int));
    *heap_var = 20;
    
    printf("\nAddress comparison:\n");
    printf("  Stack variable address: %p\n", (void*)&stack_var);
    printf("  Heap variable address:  %p\n", (void*)heap_var);
    
    // Calculate approximate distance
    ptrdiff_t distance = (char*)&stack_var - (char*)heap_var;
    printf("  Distance: %td bytes\n", distance);
    
    if ((char*)&stack_var > (char*)heap_var) {
        printf("  Stack is at higher addresses than heap\n");
    } else {
        printf("  Heap is at higher addresses than stack\n");
    }
    
    free(heap_var);
    printf("\n");
}

void demonstrate_stack_growth(int depth) {
    if (depth == 0) {
        printf("3. STACK GROWTH DEMONSTRATION\n");
        printf("----------------------------------------\n");
    }
    
    int local_var = depth;
    
    printf("Depth %d: local_var at %p, value = %d\n", 
           depth, (void*)&local_var, local_var);
    
    if (depth < 5) {
        demonstrate_stack_growth(depth + 1);
    } else {
        printf("\nStack growth analysis:\n");
        printf("  Stack grows downward (higher to lower addresses)\n");
        printf("  Each function call adds a new stack frame\n");
        printf("  Local variables are allocated in stack frames\n");
    }
    
    if (depth == 0) {
        printf("\n");
    }
}

void demonstrate_memory_alignment(void) {
    printf("4. MEMORY ALIGNMENT\n");
    printf("----------------------------------------\n");
    
    // Structure to demonstrate alignment
    struct AlignmentDemo {
        char c1;        // 1 byte
        int i;          // 4 bytes
        char c2;        // 1 byte
        double d;       // 8 bytes
        char c3;        // 1 byte
    };
    
    struct AlignmentDemo demo = {'A', 42, 'B', 3.14, 'C'};
    
    printf("Structure memory layout:\n");
    printf("  struct AlignmentDemo size: %zu bytes\n", sizeof(struct AlignmentDemo));
    printf("  Expected minimum size: %zu bytes\n", 
           sizeof(char) + sizeof(int) + sizeof(char) + sizeof(double) + sizeof(char));
    
    printf("\nMember addresses and offsets:\n");
    printf("  c1 (char):   %p, offset: %zu\n", 
           (void*)&demo.c1, (char*)&demo.c1 - (char*)&demo);
    printf("  i (int):     %p, offset: %zu\n", 
           (void*)&demo.i, (char*)&demo.i - (char*)&demo);
    printf("  c2 (char):   %p, offset: %zu\n", 
           (void*)&demo.c2, (char*)&demo.c2 - (char*)&demo);
    printf("  d (double):  %p, offset: %zu\n", 
           (void*)&demo.d, (char*)&demo.d - (char*)&demo);
    printf("  c3 (char):   %p, offset: %zu\n", 
           (void*)&demo.c3, (char*)&demo.c3 - (char*)&demo);
    
    printf("\nAlignment analysis:\n");
    printf("  Padding added for alignment efficiency\n");
    printf("  Most systems align data to word boundaries\n");
    printf("  Larger types require stricter alignment\n");
    
    // Demonstrate different data type alignments
    printf("\nData type sizes and typical alignments:\n");
    printf("  char:   %zu byte(s)\n", sizeof(char));
    printf("  short:  %zu byte(s)\n", sizeof(short));
    printf("  int:    %zu byte(s)\n", sizeof(int));
    printf("  long:   %zu byte(s)\n", sizeof(long));
    printf("  float:  %zu byte(s)\n", sizeof(float));
    printf("  double: %zu byte(s)\n", sizeof(double));
    printf("  void*:  %zu byte(s)\n", sizeof(void*));
    
    // Array alignment
    printf("\nArray alignment:\n");
    int int_array[3] = {1, 2, 3};
    printf("  int_array[0]: %p\n", (void*)&int_array[0]);
    printf("  int_array[1]: %p (offset: %td)\n", 
           (void*)&int_array[1], (char*)&int_array[1] - (char*)&int_array[0]);
    printf("  int_array[2]: %p (offset: %td)\n", 
           (void*)&int_array[2], (char*)&int_array[2] - (char*)&int_array[0]);
    
    printf("\n");
}

void print_address_info(const char* name, void* addr, const char* segment) {
    printf("  %-25s: %p (%s)\n", name, addr, segment);
}

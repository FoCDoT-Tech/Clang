#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

// Function prototypes
void demonstrate_multi_level_pointers(void);
void demonstrate_function_pointers(void);
void demonstrate_pointer_arithmetic(void);
void demonstrate_void_pointers(void);
void demonstrate_complex_expressions(void);
void demonstrate_pointer_algorithms(void);
void demonstrate_memory_management(void);
void demonstrate_pointer_safety(void);

// Structures for demonstrations
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    void* data;
    size_t size;
    size_t capacity;
    size_t element_size;
} GenericArray;

typedef struct RefCountedData {
    int ref_count;
    void* data;
    void (*destructor)(void*);
} RefCountedData;

#define POOL_SIZE 1024
typedef struct {
    char pool[POOL_SIZE];
    size_t offset;
} MemoryPool;

// Callback function type
typedef void (*EventCallback)(int event_type, void* data);

// Mathematical operations for function pointers
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide_safe(int a, int b) { return b != 0 ? a / b : 0; }

// Event handler functions
void button_click_handler(int event_type, void* data) {
    printf("  Button clicked! Event: %d, Data: %s\n", event_type, (char*)data);
}

void mouse_hover_handler(int event_type, void* data) {
    printf("  Mouse hover! Event: %d, Data: %s\n", event_type, (char*)data);
}

// Higher-order function
int apply_operation(int a, int b, int (*op)(int, int)) {
    return op(a, b);
}

// Function returning function pointer
int (*get_operation(char op))(int, int) {
    switch (op) {
        case '+': return add;
        case '-': return subtract;
        case '*': return multiply;
        case '/': return divide_safe;
        default: return NULL;
    }
}

// Generic swap function
void swap(void* a, void* b, size_t size) {
    char* temp = malloc(size);
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

// Generic array functions
GenericArray* create_generic_array(size_t element_size) {
    GenericArray* arr = malloc(sizeof(GenericArray));
    if (arr == NULL) return NULL;
    
    arr->data = malloc(element_size * 2);
    if (arr->data == NULL) {
        free(arr);
        return NULL;
    }
    
    arr->size = 0;
    arr->capacity = 2;
    arr->element_size = element_size;
    return arr;
}

void* get_element(GenericArray* arr, size_t index) {
    if (index >= arr->size) return NULL;
    return (char*)arr->data + (index * arr->element_size);
}

bool add_element(GenericArray* arr, void* element) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        void* new_data = realloc(arr->data, arr->capacity * arr->element_size);
        if (new_data == NULL) return false;
        arr->data = new_data;
    }
    
    void* dest = (char*)arr->data + (arr->size * arr->element_size);
    memcpy(dest, element, arr->element_size);
    arr->size++;
    return true;
}

void free_generic_array(GenericArray* arr) {
    if (arr) {
        free(arr->data);
        free(arr);
    }
}

// Linked list functions
Node* create_node(int data) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

Node* reverse_list(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

bool has_cycle(Node* head) {
    if (head == NULL) return false;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    
    return false;
}

Node* find_middle(Node* head) {
    if (head == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_list(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Memory pool functions
void init_pool(MemoryPool* pool) {
    pool->offset = 0;
}

void* pool_alloc(MemoryPool* pool, size_t size) {
    if (pool->offset + size > POOL_SIZE) {
        return NULL;
    }
    
    void* ptr = pool->pool + pool->offset;
    pool->offset += size;
    return ptr;
}

void pool_reset(MemoryPool* pool) {
    pool->offset = 0;
}

// Reference counting functions
void simple_destructor(void* data) {
    free(data);
}

RefCountedData* create_ref_data(void* data, void (*destructor)(void*)) {
    RefCountedData* ref_data = malloc(sizeof(RefCountedData));
    if (ref_data == NULL) return NULL;
    
    ref_data->ref_count = 1;
    ref_data->data = data;
    ref_data->destructor = destructor;
    return ref_data;
}

void retain(RefCountedData* ref_data) {
    if (ref_data) {
        ref_data->ref_count++;
    }
}

void release(RefCountedData* ref_data) {
    if (ref_data && --ref_data->ref_count == 0) {
        if (ref_data->destructor && ref_data->data) {
            ref_data->destructor(ref_data->data);
        }
        free(ref_data);
    }
}

// Safety functions
int safe_access(int* ptr) {
    if (ptr == NULL) {
        return -1;
    }
    return *ptr;
}

void safe_free(void** ptr) {
    if (ptr && *ptr) {
        free(*ptr);
        *ptr = NULL;
    }
}

bool is_valid_pointer(void* ptr) {
    if (ptr == NULL) return false;
    
    // Check alignment (example for pointer alignment)
    if ((uintptr_t)ptr % sizeof(void*) != 0) return false;
    
    return true;
}

int main(void) {
    printf("=== Advanced Pointer Techniques Demo ===\n\n");
    
    demonstrate_multi_level_pointers();
    demonstrate_function_pointers();
    demonstrate_pointer_arithmetic();
    demonstrate_void_pointers();
    demonstrate_complex_expressions();
    demonstrate_pointer_algorithms();
    demonstrate_memory_management();
    demonstrate_pointer_safety();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_multi_level_pointers(void) {
    printf("1. MULTI-LEVEL POINTERS\n");
    printf("----------------------------------------\n");
    
    // Double pointers
    int value = 42;
    int* ptr = &value;
    int** double_ptr = &ptr;
    
    printf("Original value: %d\n", value);
    printf("Through pointer: %d\n", *ptr);
    printf("Through double pointer: %d\n", **double_ptr);
    
    // Modify through double pointer
    **double_ptr = 100;
    printf("After modification through double pointer: %d\n", value);
    
    // Triple pointer
    int*** triple_ptr = &double_ptr;
    printf("Through triple pointer: %d\n", ***triple_ptr);
    
    // Dynamic 2D array
    printf("\nDynamic 2D Array:\n");
    int rows = 3, cols = 4;
    int** matrix = malloc(rows * sizeof(int*));
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }
    
    printf("Matrix contents:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Free 2D array
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    printf("\n");
}

void demonstrate_function_pointers(void) {
    printf("2. FUNCTION POINTERS\n");
    printf("----------------------------------------\n");
    
    // Basic function pointer
    int (*operation)(int, int) = add;
    printf("Using function pointer for addition: %d + %d = %d\n", 
           5, 3, operation(5, 3));
    
    // Array of function pointers
    int (*operations[])(int, int) = {add, subtract, multiply, divide_safe};
    const char* op_names[] = {"add", "subtract", "multiply", "divide"};
    
    printf("\nArray of function pointers:\n");
    for (int i = 0; i < 4; i++) {
        int result = operations[i](20, 4);
        printf("  %s(20, 4) = %d\n", op_names[i], result);
    }
    
    // Higher-order function
    printf("\nHigher-order function:\n");
    printf("  apply_operation(15, 5, add) = %d\n", 
           apply_operation(15, 5, add));
    printf("  apply_operation(15, 5, multiply) = %d\n", 
           apply_operation(15, 5, multiply));
    
    // Function returning function pointer
    printf("\nFunction returning function pointer:\n");
    int (*op_add)(int, int) = get_operation('+');
    int (*op_mul)(int, int) = get_operation('*');
    
    if (op_add) printf("  get_operation('+')(7, 3) = %d\n", op_add(7, 3));
    if (op_mul) printf("  get_operation('*')(7, 3) = %d\n", op_mul(7, 3));
    
    // Callback functions
    printf("\nCallback functions:\n");
    EventCallback callbacks[] = {button_click_handler, mouse_hover_handler};
    
    callbacks[0](1, "Button1");
    callbacks[1](2, "Element1");
    
    printf("\n");
}

void demonstrate_pointer_arithmetic(void) {
    printf("3. POINTER ARITHMETIC\n");
    printf("----------------------------------------\n");
    
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;
    
    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Pointer arithmetic:\n");
    printf("  ptr points to: %d\n", *ptr);
    
    ptr += 2;
    printf("  ptr += 2, now points to: %d\n", *ptr);
    
    ptr--;
    printf("  ptr--, now points to: %d\n", *ptr);
    
    // Pointer difference
    int* start = arr;
    int* end = arr + 4;
    ptrdiff_t diff = end - start;
    printf("  Difference between end and start: %td\n", diff);
    
    // Pointer comparison
    int* ptr1 = &arr[1];
    int* ptr2 = &arr[3];
    
    if (ptr2 > ptr1) {
        printf("  ptr2 (%p) > ptr1 (%p)\n", (void*)ptr2, (void*)ptr1);
        printf("  Distance: %td elements\n", ptr2 - ptr1);
    }
    
    printf("\n");
}

void demonstrate_void_pointers(void) {
    printf("4. VOID POINTERS AND GENERIC PROGRAMMING\n");
    printf("----------------------------------------\n");
    
    // Generic swap
    printf("Generic swap function:\n");
    int x = 10, y = 20;
    printf("  Before swap: x=%d, y=%d\n", x, y);
    swap(&x, &y, sizeof(int));
    printf("  After swap: x=%d, y=%d\n", x, y);
    
    double dx = 1.5, dy = 2.5;
    printf("  Before swap: dx=%.1f, dy=%.1f\n", dx, dy);
    swap(&dx, &dy, sizeof(double));
    printf("  After swap: dx=%.1f, dy=%.1f\n", dx, dy);
    
    // Generic array
    printf("\nGeneric array:\n");
    GenericArray* int_array = create_generic_array(sizeof(int));
    
    int values[] = {100, 200, 300};
    for (int i = 0; i < 3; i++) {
        add_element(int_array, &values[i]);
    }
    
    printf("  Integer array contents: ");
    for (size_t i = 0; i < int_array->size; i++) {
        int* element = (int*)get_element(int_array, i);
        if (element) printf("%d ", *element);
    }
    printf("\n");
    
    free_generic_array(int_array);
    
    printf("\n");
}

void demonstrate_complex_expressions(void) {
    printf("5. COMPLEX POINTER EXPRESSIONS\n");
    printf("----------------------------------------\n");
    
    // Array of pointers vs pointer to array
    printf("Array of pointers vs pointer to array:\n");
    
    // Array of pointers
    int a = 1, b = 2, c = 3;
    int* ptr_array[3] = {&a, &b, &c};
    printf("  Array of pointers: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", *ptr_array[i]);
    }
    printf("\n");
    
    // Pointer to array
    int arr[3] = {10, 20, 30};
    int (*array_ptr)[3] = &arr;
    printf("  Pointer to array: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", (*array_ptr)[i]);
    }
    printf("\n");
    
    // Complex function pointer
    printf("\nComplex function pointer usage:\n");
    int (*selected_op)(int, int) = get_operation('+');
    if (selected_op) {
        printf("  Dynamic operation selection: %d\n", selected_op(8, 4));
    }
    
    printf("\n");
}

void demonstrate_pointer_algorithms(void) {
    printf("6. POINTER-BASED ALGORITHMS\n");
    printf("----------------------------------------\n");
    
    // Create a linked list
    Node* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);
    
    printf("Original list: ");
    print_list(head);
    
    // Find middle
    Node* middle = find_middle(head);
    printf("Middle element: %d\n", middle ? middle->data : -1);
    
    // Reverse list
    head = reverse_list(head);
    printf("Reversed list: ");
    print_list(head);
    
    // Check for cycle (no cycle in this case)
    printf("Has cycle: %s\n", has_cycle(head) ? "Yes" : "No");
    
    // Create a cycle for demonstration
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head->next;  // Create cycle
    
    printf("After creating cycle, has cycle: %s\n", 
           has_cycle(head) ? "Yes" : "No");
    
    // Break cycle to free memory safely
    tail->next = NULL;
    free_list(head);
    
    printf("\n");
}

void demonstrate_memory_management(void) {
    printf("7. ADVANCED MEMORY MANAGEMENT\n");
    printf("----------------------------------------\n");
    
    // Memory pool
    printf("Memory pool allocation:\n");
    MemoryPool pool;
    init_pool(&pool);
    
    int* pool_int1 = (int*)pool_alloc(&pool, sizeof(int));
    int* pool_int2 = (int*)pool_alloc(&pool, sizeof(int));
    char* pool_str = (char*)pool_alloc(&pool, 20);
    
    if (pool_int1 && pool_int2 && pool_str) {
        *pool_int1 = 100;
        *pool_int2 = 200;
        strcpy(pool_str, "Pool string");
        
        printf("  Pool allocated values: %d, %d, '%s'\n", 
               *pool_int1, *pool_int2, pool_str);
        printf("  Pool offset: %zu bytes\n", pool.offset);
    }
    
    pool_reset(&pool);
    printf("  Pool reset, offset: %zu bytes\n", pool.offset);
    
    // Reference counting
    printf("\nReference counting:\n");
    int* shared_data = malloc(sizeof(int));
    *shared_data = 42;
    
    RefCountedData* ref1 = create_ref_data(shared_data, simple_destructor);
    printf("  Created ref_data, ref_count: %d\n", ref1->ref_count);
    
    retain(ref1);
    printf("  After retain, ref_count: %d\n", ref1->ref_count);
    
    RefCountedData* ref2 = ref1;
    retain(ref2);
    printf("  After second retain, ref_count: %d\n", ref1->ref_count);
    
    release(ref1);
    printf("  After first release, ref_count: %d\n", ref2->ref_count);
    
    release(ref2);
    printf("  After final release, data freed\n");
    
    printf("\n");
}

void demonstrate_pointer_safety(void) {
    printf("8. POINTER SAFETY\n");
    printf("----------------------------------------\n");
    
    // Null pointer checks
    printf("Null pointer safety:\n");
    int* null_ptr = NULL;
    int valid_value = 42;
    int* valid_ptr = &valid_value;
    
    printf("  safe_access(NULL): %d\n", safe_access(null_ptr));
    printf("  safe_access(valid_ptr): %d\n", safe_access(valid_ptr));
    
    // Safe free
    printf("\nSafe free demonstration:\n");
    int* dynamic_ptr = malloc(sizeof(int));
    *dynamic_ptr = 123;
    printf("  Before safe_free: ptr = %p\n", (void*)dynamic_ptr);
    
    safe_free((void**)&dynamic_ptr);
    printf("  After safe_free: ptr = %p\n", (void*)dynamic_ptr);
    
    // Pointer validation
    printf("\nPointer validation:\n");
    printf("  is_valid_pointer(NULL): %s\n", 
           is_valid_pointer(NULL) ? "Valid" : "Invalid");
    printf("  is_valid_pointer(&valid_value): %s\n", 
           is_valid_pointer(&valid_value) ? "Valid" : "Invalid");
    
    // Const correctness demonstration
    printf("\nConst correctness:\n");
    const int const_value = 100;
    const int* ptr_to_const = &const_value;
    printf("  Reading through const pointer: %d\n", *ptr_to_const);
    
    int mutable_value = 200;
    int* const const_ptr = &mutable_value;
    *const_ptr = 300;  // Can modify data
    printf("  Modified through const pointer: %d\n", *const_ptr);
    
    printf("\n");
}

# 13.2 Advanced Pointer Techniques

Advanced pointer concepts including multi-level pointers, function pointers, and complex pointer manipulations.

## Multi-level Pointers

### **Double Pointers (Pointer to Pointer)**
```c
int value = 42;
int* ptr = &value;
int** double_ptr = &ptr;

printf("Value: %d\n", **double_ptr);  // 42
printf("Address of ptr: %p\n", (void*)double_ptr);
```

### **Triple Pointers**
```c
int*** triple_ptr = &double_ptr;
printf("Value through triple pointer: %d\n", ***triple_ptr);
```

### **Dynamic 2D Arrays**
```c
// Allocate array of pointers
int** matrix = malloc(rows * sizeof(int*));
for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(cols * sizeof(int));
}

// Access: matrix[i][j]
// Free in reverse order
for (int i = 0; i < rows; i++) {
    free(matrix[i]);
}
free(matrix);
```

## Function Pointers

### **Basic Function Pointers**
```c
// Function declaration
int add(int a, int b) {
    return a + b;
}

// Function pointer declaration and assignment
int (*operation)(int, int) = add;

// Call through function pointer
int result = operation(5, 3);  // 8
```

### **Array of Function Pointers**
```c
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

// Array of function pointers
int (*operations[])(int, int) = {add, subtract, multiply};

// Usage
int result = operations[0](10, 5);  // add: 15
result = operations[1](10, 5);      // subtract: 5
result = operations[2](10, 5);      // multiply: 50
```

### **Function Pointers as Parameters**
```c
// Higher-order function
int apply_operation(int a, int b, int (*op)(int, int)) {
    return op(a, b);
}

// Usage
int sum = apply_operation(10, 20, add);
int diff = apply_operation(10, 20, subtract);
```

### **Callback Functions**
```c
typedef void (*EventCallback)(int event_type, void* data);

typedef struct {
    EventCallback on_click;
    EventCallback on_hover;
} EventHandlers;

void register_handlers(EventHandlers* handlers) {
    // Register callbacks for events
}

void button_click_handler(int event_type, void* data) {
    printf("Button clicked! Event: %d\n", event_type);
}
```

## Pointer Arithmetic

### **Advanced Arithmetic**
```c
int arr[] = {10, 20, 30, 40, 50};
int* ptr = arr;

// Pointer arithmetic
ptr += 2;           // Points to arr[2] (30)
int value = *ptr;   // 30
ptr--;              // Points to arr[1] (20)

// Pointer difference
int* start = arr;
int* end = arr + 4;
ptrdiff_t diff = end - start;  // 4
```

### **Pointer Comparison**
```c
int* ptr1 = &arr[1];
int* ptr2 = &arr[3];

if (ptr2 > ptr1) {
    printf("ptr2 points to higher address\n");
}

// Distance between pointers
size_t distance = ptr2 - ptr1;  // 2
```

## Void Pointers and Generic Programming

### **Generic Functions with Void Pointers**
```c
void swap(void* a, void* b, size_t size) {
    char* temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

// Usage
int x = 10, y = 20;
swap(&x, &y, sizeof(int));

double dx = 1.5, dy = 2.5;
swap(&dx, &dy, sizeof(double));
```

### **Generic Data Structures**
```c
typedef struct {
    void* data;
    size_t size;
    size_t capacity;
    size_t element_size;
} GenericArray;

GenericArray* create_array(size_t element_size) {
    GenericArray* arr = malloc(sizeof(GenericArray));
    arr->data = malloc(element_size * 2);
    arr->size = 0;
    arr->capacity = 2;
    arr->element_size = element_size;
    return arr;
}

void* get_element(GenericArray* arr, size_t index) {
    if (index >= arr->size) return NULL;
    return (char*)arr->data + (index * arr->element_size);
}
```

## Complex Pointer Expressions

### **Pointer to Array vs Array of Pointers**
```c
// Array of pointers
int* ptr_array[5];  // 5 pointers to int

// Pointer to array
int (*array_ptr)[5];  // Pointer to array of 5 ints

int arr[5] = {1, 2, 3, 4, 5};
array_ptr = &arr;
printf("Third element: %d\n", (*array_ptr)[2]);  // 3
```

### **Function Returning Pointer to Function**
```c
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

// Function returning function pointer
int (*get_operation(char op))(int, int) {
    switch (op) {
        case '+': return add;
        case '*': return multiply;
        default: return NULL;
    }
}

// Usage
int (*op)(int, int) = get_operation('+');
int result = op(5, 3);  // 8
```

## Pointer-based Algorithms

### **Linked List Reversal**
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;

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
    
    return prev;  // New head
}
```

### **Fast and Slow Pointers (Floyd's Algorithm)**
```c
// Detect cycle in linked list
bool has_cycle(Node* head) {
    if (head == NULL) return false;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;  // Cycle detected
        }
    }
    
    return false;
}

// Find middle of linked list
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
```

## Memory Pool Management

### **Custom Memory Allocator**
```c
#define POOL_SIZE 1024

typedef struct {
    char pool[POOL_SIZE];
    size_t offset;
    bool used_blocks[POOL_SIZE];
} MemoryPool;

void* pool_alloc(MemoryPool* pool, size_t size) {
    if (pool->offset + size > POOL_SIZE) {
        return NULL;  // Pool exhausted
    }
    
    void* ptr = pool->pool + pool->offset;
    pool->offset += size;
    return ptr;
}

void pool_reset(MemoryPool* pool) {
    pool->offset = 0;
    memset(pool->used_blocks, 0, sizeof(pool->used_blocks));
}
```

### **Reference Counting**
```c
typedef struct RefCountedData {
    int ref_count;
    void* data;
    void (*destructor)(void*);
} RefCountedData;

RefCountedData* create_ref_data(void* data, void (*destructor)(void*)) {
    RefCountedData* ref_data = malloc(sizeof(RefCountedData));
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
        if (ref_data->destructor) {
            ref_data->destructor(ref_data->data);
        }
        free(ref_data);
    }
}
```

## Pointer Safety and Best Practices

### **Null Pointer Checks**
```c
// Always check before dereferencing
int safe_access(int* ptr) {
    if (ptr == NULL) {
        return -1;  // Error code
    }
    return *ptr;
}

// Defensive programming
void safe_free(void** ptr) {
    if (ptr && *ptr) {
        free(*ptr);
        *ptr = NULL;  // Prevent double free
    }
}
```

### **Const Correctness**
```c
// Pointer to constant data
const int* ptr_to_const = &value;
// *ptr_to_const = 10;  // Error: cannot modify data

// Constant pointer
int* const const_ptr = &value;
// const_ptr = &other;  // Error: cannot modify pointer

// Constant pointer to constant data
const int* const const_ptr_to_const = &value;
// Neither pointer nor data can be modified
```

### **Pointer Validation**
```c
bool is_valid_pointer(void* ptr, size_t size) {
    // Basic checks (platform-specific implementation needed)
    if (ptr == NULL) return false;
    
    // Check alignment (example for 4-byte alignment)
    if ((uintptr_t)ptr % 4 != 0) return false;
    
    // Additional platform-specific checks would go here
    return true;
}
```

## Performance Considerations

### **Cache-friendly Access Patterns**
```c
// Row-major access (cache-friendly)
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        matrix[i][j] = i * cols + j;
    }
}

// Column-major access (cache-unfriendly)
for (int j = 0; j < cols; j++) {
    for (int i = 0; i < rows; i++) {
        matrix[i][j] = i * cols + j;  // Poor cache locality
    }
}
```

### **Pointer Prefetching**
```c
// Manual prefetching hint (compiler-specific)
void process_array(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        // Prefetch next cache line
        if (i + 8 < size) {
            __builtin_prefetch(&arr[i + 8], 0, 1);
        }
        
        // Process current element
        arr[i] = arr[i] * 2;
    }
}
```

## Code Example

Run the demo to see advanced pointer techniques:
```bash
make run
```

The demo demonstrates:
- Multi-level pointer operations
- Function pointer arrays and callbacks
- Generic programming with void pointers
- Advanced pointer arithmetic
- Pointer-based algorithms (list reversal, cycle detection)
- Memory pool management
- Pointer safety techniques

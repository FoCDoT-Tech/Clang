# 13.1 Complex Data Structures

Advanced data structures that build upon basic arrays and pointers to create efficient, reusable components.

## Linked Lists

### **Singly Linked List**
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create new node
Node* create_node(int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
```

### **Doubly Linked List**
```c
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;
```

### **Operations**
- Insert at beginning/end/position
- Delete by value/position
- Search and traversal
- Reverse list

## Stacks (LIFO)

### **Array-based Stack**
```c
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void push(Stack* s, int item) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = item;
    }
}

int pop(Stack* s) {
    if (s->top >= 0) {
        return s->items[s->top--];
    }
    return -1; // Error value
}
```

### **Linked List Stack**
```c
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStack;
```

## Queues (FIFO)

### **Circular Array Queue**
```c
#define QUEUE_SIZE 100

typedef struct {
    int items[QUEUE_SIZE];
    int front, rear;
    int count;
} Queue;

void enqueue(Queue* q, int item) {
    if (q->count < QUEUE_SIZE) {
        q->items[q->rear] = item;
        q->rear = (q->rear + 1) % QUEUE_SIZE;
        q->count++;
    }
}
```

### **Linked List Queue**
```c
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} LinkedQueue;
```

## Binary Trees

### **Binary Tree Node**
```c
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
```

### **Binary Search Tree Operations**
```c
// Insert node
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return create_tree_node(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Search node
TreeNode* search(TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}
```

### **Tree Traversals**
```c
// Inorder: Left -> Root -> Right
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder: Root -> Left -> Right
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder: Left -> Right -> Root
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
```

## Hash Tables

### **Simple Hash Table**
```c
#define HASH_SIZE 101

typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode* buckets[HASH_SIZE];
} HashTable;

// Hash function
int hash(int key) {
    return key % HASH_SIZE;
}

// Insert key-value pair
void hash_insert(HashTable* ht, int key, int value) {
    int index = hash(key);
    HashNode* new_node = malloc(sizeof(HashNode));
    new_node->key = key;
    new_node->value = value;
    new_node->next = ht->buckets[index];
    ht->buckets[index] = new_node;
}
```

### **Collision Handling**
- **Chaining**: Use linked lists at each bucket
- **Open Addressing**: Linear/quadratic probing

## Graphs

### **Adjacency List Representation**
```c
typedef struct AdjNode {
    int dest;
    struct AdjNode* next;
} AdjNode;

typedef struct {
    AdjNode* head;
} AdjList;

typedef struct {
    int vertices;
    AdjList* array;
} Graph;
```

### **Graph Operations**
```c
// Add edge
void add_edge(Graph* graph, int src, int dest) {
    AdjNode* new_node = malloc(sizeof(AdjNode));
    new_node->dest = dest;
    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;
    
    // For undirected graph, add reverse edge
    new_node = malloc(sizeof(AdjNode));
    new_node->dest = src;
    new_node->next = graph->array[dest].head;
    graph->array[dest].head = new_node;
}
```

### **Graph Traversals**
```c
// Depth-First Search (DFS)
void dfs_util(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    AdjNode* temp = graph->array[vertex].head;
    while (temp) {
        if (!visited[temp->dest]) {
            dfs_util(graph, temp->dest, visited);
        }
        temp = temp->next;
    }
}

// Breadth-First Search (BFS)
void bfs(Graph* graph, int start) {
    bool* visited = calloc(graph->vertices, sizeof(bool));
    Queue queue = {0};
    
    visited[start] = true;
    enqueue(&queue, start);
    
    while (queue.count > 0) {
        int vertex = dequeue(&queue);
        printf("%d ", vertex);
        
        AdjNode* temp = graph->array[vertex].head;
        while (temp) {
            if (!visited[temp->dest]) {
                visited[temp->dest] = true;
                enqueue(&queue, temp->dest);
            }
            temp = temp->next;
        }
    }
    
    free(visited);
}
```

## Memory Management

### **Generic Data Structure**
```c
typedef struct {
    void* data;
    size_t size;
    size_t capacity;
    size_t element_size;
} DynamicArray;

// Create dynamic array
DynamicArray* create_array(size_t element_size) {
    DynamicArray* arr = malloc(sizeof(DynamicArray));
    arr->data = malloc(element_size * 2);
    arr->size = 0;
    arr->capacity = 2;
    arr->element_size = element_size;
    return arr;
}

// Resize array
void resize_array(DynamicArray* arr) {
    arr->capacity *= 2;
    arr->data = realloc(arr->data, arr->capacity * arr->element_size);
}
```

## Performance Considerations

### **Time Complexities**
- **Linked List**: Insert O(1), Search O(n), Delete O(n)
- **Stack/Queue**: Push/Pop/Enqueue/Dequeue O(1)
- **Binary Search Tree**: Insert/Search/Delete O(log n) average, O(n) worst
- **Hash Table**: Insert/Search/Delete O(1) average, O(n) worst
- **Graph Traversal**: DFS/BFS O(V + E)

### **Space Complexities**
- **Array-based**: O(n) fixed space
- **Linked structures**: O(n) + pointer overhead
- **Hash Table**: O(n) + bucket overhead

## Best Practices

### **Memory Management**
```c
// Always check malloc return
Node* node = malloc(sizeof(Node));
if (node == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
}

// Free all allocated memory
void free_list(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
```

### **Error Handling**
```c
// Return error codes
typedef enum {
    SUCCESS = 0,
    ERROR_NULL_POINTER,
    ERROR_OUT_OF_MEMORY,
    ERROR_NOT_FOUND
} Result;

Result stack_push(Stack* s, int item) {
    if (s == NULL) return ERROR_NULL_POINTER;
    if (s->top >= MAX_SIZE - 1) return ERROR_OUT_OF_MEMORY;
    
    s->items[++s->top] = item;
    return SUCCESS;
}
```

## Code Example

Run the demo to see complex data structures in action:
```bash
make run
```

The demo demonstrates:
- Linked list operations and traversal
- Stack and queue implementations
- Binary search tree operations
- Hash table with collision handling
- Graph creation and traversal algorithms
- Memory management best practices

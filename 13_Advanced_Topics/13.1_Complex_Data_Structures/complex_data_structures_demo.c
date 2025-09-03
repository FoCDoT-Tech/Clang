#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
void demonstrate_linked_lists(void);
void demonstrate_stacks(void);
void demonstrate_queues(void);
void demonstrate_binary_trees(void);
void demonstrate_hash_tables(void);
void demonstrate_graphs(void);

// Linked List structures
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// Stack structures
#define STACK_SIZE 100
typedef struct {
    int items[STACK_SIZE];
    int top;
} ArrayStack;

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStack;

// Queue structures
#define QUEUE_SIZE 100
typedef struct {
    int items[QUEUE_SIZE];
    int front, rear;
    int count;
} CircularQueue;

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} LinkedQueue;

// Binary Tree structures
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Hash Table structures
#define HASH_SIZE 7
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode* buckets[HASH_SIZE];
} HashTable;

// Graph structures
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

// Linked List functions
Node* create_node(int data) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(Node** head, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(Node** head, int data) {
    Node* new_node = create_node(data);
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

bool delete_by_value(Node** head, int data) {
    if (*head == NULL) return false;
    
    if ((*head)->data == data) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return true;
    }
    
    Node* current = *head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    
    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
        return true;
    }
    
    return false;
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

// Stack functions
void init_array_stack(ArrayStack* s) {
    s->top = -1;
}

bool push_array_stack(ArrayStack* s, int item) {
    if (s->top >= STACK_SIZE - 1) {
        return false;
    }
    s->items[++s->top] = item;
    return true;
}

bool pop_array_stack(ArrayStack* s, int* item) {
    if (s->top < 0) {
        return false;
    }
    *item = s->items[s->top--];
    return true;
}

void init_linked_stack(LinkedStack* s) {
    s->top = NULL;
}

void push_linked_stack(LinkedStack* s, int item) {
    StackNode* new_node = malloc(sizeof(StackNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_node->data = item;
    new_node->next = s->top;
    s->top = new_node;
}

bool pop_linked_stack(LinkedStack* s, int* item) {
    if (s->top == NULL) {
        return false;
    }
    StackNode* temp = s->top;
    *item = temp->data;
    s->top = s->top->next;
    free(temp);
    return true;
}

void free_linked_stack(LinkedStack* s) {
    while (s->top != NULL) {
        StackNode* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

// Queue functions
void init_circular_queue(CircularQueue* q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

bool enqueue_circular(CircularQueue* q, int item) {
    if (q->count >= QUEUE_SIZE) {
        return false;
    }
    q->items[q->rear] = item;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->count++;
    return true;
}

bool dequeue_circular(CircularQueue* q, int* item) {
    if (q->count == 0) {
        return false;
    }
    *item = q->items[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    return true;
}

void init_linked_queue(LinkedQueue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue_linked(LinkedQueue* q, int item) {
    QueueNode* new_node = malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_node->data = item;
    new_node->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

bool dequeue_linked(LinkedQueue* q, int* item) {
    if (q->front == NULL) {
        return false;
    }
    
    QueueNode* temp = q->front;
    *item = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return true;
}

void free_linked_queue(LinkedQueue* q) {
    while (q->front != NULL) {
        QueueNode* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
}

// Binary Tree functions
TreeNode* create_tree_node(int data) {
    TreeNode* new_node = malloc(sizeof(TreeNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

TreeNode* insert_bst(TreeNode* root, int data) {
    if (root == NULL) {
        return create_tree_node(data);
    }
    
    if (data < root->data) {
        root->left = insert_bst(root->left, data);
    } else if (data > root->data) {
        root->right = insert_bst(root->right, data);
    }
    
    return root;
}

TreeNode* search_bst(TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return search_bst(root->left, data);
    }
    return search_bst(root->right, data);
}

void inorder_traversal(TreeNode* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void preorder_traversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(TreeNode* root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

void free_tree(TreeNode* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

// Hash Table functions
int hash_function(int key) {
    return key % HASH_SIZE;
}

void init_hash_table(HashTable* ht) {
    for (int i = 0; i < HASH_SIZE; i++) {
        ht->buckets[i] = NULL;
    }
}

void hash_insert(HashTable* ht, int key, int value) {
    int index = hash_function(key);
    HashNode* new_node = malloc(sizeof(HashNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    
    new_node->key = key;
    new_node->value = value;
    new_node->next = ht->buckets[index];
    ht->buckets[index] = new_node;
}

bool hash_search(HashTable* ht, int key, int* value) {
    int index = hash_function(key);
    HashNode* current = ht->buckets[index];
    
    while (current != NULL) {
        if (current->key == key) {
            *value = current->value;
            return true;
        }
        current = current->next;
    }
    
    return false;
}

bool hash_delete(HashTable* ht, int key) {
    int index = hash_function(key);
    HashNode* current = ht->buckets[index];
    HashNode* prev = NULL;
    
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                ht->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    
    return false;
}

void print_hash_table(HashTable* ht) {
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("Bucket %d: ", i);
        HashNode* current = ht->buckets[i];
        while (current != NULL) {
            printf("(%d,%d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }
}

void free_hash_table(HashTable* ht) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* current = ht->buckets[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

// Graph functions
Graph* create_graph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    if (graph == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    graph->vertices = vertices;
    graph->array = malloc(vertices * sizeof(AdjList));
    if (graph->array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}

void add_edge(Graph* graph, int src, int dest) {
    AdjNode* new_node = malloc(sizeof(AdjNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_node->dest = dest;
    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;
    
    // For undirected graph, add reverse edge
    new_node = malloc(sizeof(AdjNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_node->dest = src;
    new_node->next = graph->array[dest].head;
    graph->array[dest].head = new_node;
}

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

void dfs(Graph* graph, int start) {
    bool* visited = calloc(graph->vertices, sizeof(bool));
    if (visited == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    
    dfs_util(graph, start, visited);
    free(visited);
}

void bfs(Graph* graph, int start) {
    bool* visited = calloc(graph->vertices, sizeof(bool));
    if (visited == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    
    LinkedQueue queue;
    init_linked_queue(&queue);
    
    visited[start] = true;
    enqueue_linked(&queue, start);
    
    while (queue.front != NULL) {
        int vertex;
        dequeue_linked(&queue, &vertex);
        printf("%d ", vertex);
        
        AdjNode* temp = graph->array[vertex].head;
        while (temp) {
            if (!visited[temp->dest]) {
                visited[temp->dest] = true;
                enqueue_linked(&queue, temp->dest);
            }
            temp = temp->next;
        }
    }
    
    free_linked_queue(&queue);
    free(visited);
}

void print_graph(Graph* graph) {
    for (int v = 0; v < graph->vertices; v++) {
        printf("Vertex %d: ", v);
        AdjNode* temp = graph->array[v].head;
        while (temp) {
            printf("%d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

void free_graph(Graph* graph) {
    for (int v = 0; v < graph->vertices; v++) {
        AdjNode* current = graph->array[v].head;
        while (current) {
            AdjNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}

int main(void) {
    printf("=== Complex Data Structures Demo ===\n\n");
    
    demonstrate_linked_lists();
    demonstrate_stacks();
    demonstrate_queues();
    demonstrate_binary_trees();
    demonstrate_hash_tables();
    demonstrate_graphs();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_linked_lists(void) {
    printf("1. LINKED LISTS\n");
    printf("----------------------------------------\n");
    
    Node* head = NULL;
    
    printf("Creating singly linked list:\n");
    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_beginning(&head, 5);
    
    printf("  List: ");
    print_list(head);
    
    printf("Deleting value 20:\n");
    if (delete_by_value(&head, 20)) {
        printf("  List after deletion: ");
        print_list(head);
    }
    
    printf("Searching for value 30: %s\n", 
           (search_bst != NULL) ? "Found" : "Not found");
    
    free_list(head);
    printf("\n");
}

void demonstrate_stacks(void) {
    printf("2. STACKS (LIFO)\n");
    printf("----------------------------------------\n");
    
    // Array-based stack
    printf("Array-based Stack:\n");
    ArrayStack array_stack;
    init_array_stack(&array_stack);
    
    push_array_stack(&array_stack, 10);
    push_array_stack(&array_stack, 20);
    push_array_stack(&array_stack, 30);
    
    printf("  Pushed: 10, 20, 30\n");
    
    int item;
    printf("  Popping: ");
    while (pop_array_stack(&array_stack, &item)) {
        printf("%d ", item);
    }
    printf("\n");
    
    // Linked list stack
    printf("Linked List Stack:\n");
    LinkedStack linked_stack;
    init_linked_stack(&linked_stack);
    
    push_linked_stack(&linked_stack, 100);
    push_linked_stack(&linked_stack, 200);
    push_linked_stack(&linked_stack, 300);
    
    printf("  Pushed: 100, 200, 300\n");
    printf("  Popping: ");
    while (pop_linked_stack(&linked_stack, &item)) {
        printf("%d ", item);
    }
    printf("\n");
    
    free_linked_stack(&linked_stack);
    printf("\n");
}

void demonstrate_queues(void) {
    printf("3. QUEUES (FIFO)\n");
    printf("----------------------------------------\n");
    
    // Circular array queue
    printf("Circular Array Queue:\n");
    CircularQueue circular_queue;
    init_circular_queue(&circular_queue);
    
    enqueue_circular(&circular_queue, 10);
    enqueue_circular(&circular_queue, 20);
    enqueue_circular(&circular_queue, 30);
    
    printf("  Enqueued: 10, 20, 30\n");
    
    int item;
    printf("  Dequeuing: ");
    while (dequeue_circular(&circular_queue, &item)) {
        printf("%d ", item);
    }
    printf("\n");
    
    // Linked list queue
    printf("Linked List Queue:\n");
    LinkedQueue linked_queue;
    init_linked_queue(&linked_queue);
    
    enqueue_linked(&linked_queue, 100);
    enqueue_linked(&linked_queue, 200);
    enqueue_linked(&linked_queue, 300);
    
    printf("  Enqueued: 100, 200, 300\n");
    printf("  Dequeuing: ");
    while (dequeue_linked(&linked_queue, &item)) {
        printf("%d ", item);
    }
    printf("\n");
    
    free_linked_queue(&linked_queue);
    printf("\n");
}

void demonstrate_binary_trees(void) {
    printf("4. BINARY SEARCH TREES\n");
    printf("----------------------------------------\n");
    
    TreeNode* root = NULL;
    
    printf("Inserting values: 50, 30, 70, 20, 40, 60, 80\n");
    root = insert_bst(root, 50);
    root = insert_bst(root, 30);
    root = insert_bst(root, 70);
    root = insert_bst(root, 20);
    root = insert_bst(root, 40);
    root = insert_bst(root, 60);
    root = insert_bst(root, 80);
    
    printf("Inorder traversal (sorted): ");
    inorder_traversal(root);
    printf("\n");
    
    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");
    
    printf("Searching for 40: %s\n", 
           search_bst(root, 40) ? "Found" : "Not found");
    printf("Searching for 90: %s\n", 
           search_bst(root, 90) ? "Found" : "Not found");
    
    free_tree(root);
    printf("\n");
}

void demonstrate_hash_tables(void) {
    printf("5. HASH TABLES\n");
    printf("----------------------------------------\n");
    
    HashTable ht;
    init_hash_table(&ht);
    
    printf("Inserting key-value pairs:\n");
    hash_insert(&ht, 1, 10);
    hash_insert(&ht, 8, 80);  // Will collide with key 1 (8 % 7 = 1)
    hash_insert(&ht, 2, 20);
    hash_insert(&ht, 9, 90);  // Will collide with key 2 (9 % 7 = 2)
    hash_insert(&ht, 3, 30);
    
    printf("Hash table contents:\n");
    print_hash_table(&ht);
    
    int value;
    printf("Searching for key 8: ");
    if (hash_search(&ht, 8, &value)) {
        printf("Found value %d\n", value);
    } else {
        printf("Not found\n");
    }
    
    printf("Deleting key 8\n");
    hash_delete(&ht, 8);
    
    printf("Hash table after deletion:\n");
    print_hash_table(&ht);
    
    free_hash_table(&ht);
    printf("\n");
}

void demonstrate_graphs(void) {
    printf("6. GRAPHS\n");
    printf("----------------------------------------\n");
    
    Graph* graph = create_graph(5);
    
    printf("Creating graph with edges:\n");
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    
    printf("Adjacency list representation:\n");
    print_graph(graph);
    
    printf("DFS traversal starting from vertex 0: ");
    dfs(graph, 0);
    printf("\n");
    
    printf("BFS traversal starting from vertex 0: ");
    bfs(graph, 0);
    printf("\n");
    
    free_graph(graph);
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definitions
struct Point {
    int x;
    int y;
};

struct Student {
    int id;
    char name[50];
    float gpa;
    int age;
};

struct Node {
    int data;
    struct Node *next;
};

// Function prototypes
void demonstrate_pointer_to_structure(void);
void demonstrate_arrow_operator(void);
void demonstrate_dynamic_allocation(void);
void demonstrate_function_parameters(void);
void demonstrate_self_referential_structures(void);
void demonstrate_array_of_pointers(void);

// Helper functions
void print_point_by_value(struct Point p);
void print_point_by_pointer(struct Point *p);
void modify_point(struct Point *p);
struct Point* create_point(int x, int y);
struct Student* create_student(int id, const char* name, float gpa, int age);
void print_student(struct Student *s);
void free_student(struct Student **s);

int main(void) {
    printf("=== Pointers and Structures Demo ===\n\n");
    
    demonstrate_pointer_to_structure();
    demonstrate_arrow_operator();
    demonstrate_dynamic_allocation();
    demonstrate_function_parameters();
    demonstrate_self_referential_structures();
    demonstrate_array_of_pointers();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_pointer_to_structure(void) {
    printf("1. POINTER TO STRUCTURE\n");
    printf("----------------------------------------\n");
    
    // Create a structure
    struct Point point = {10, 20};
    printf("Original point: (%d, %d)\n", point.x, point.y);
    printf("Point address: %p\n", (void*)&point);
    
    // Create pointer to structure
    struct Point *ptr = &point;
    printf("Pointer value: %p\n", (void*)ptr);
    printf("Pointer address: %p\n", (void*)&ptr);
    
    // Access through pointer
    printf("Access through pointer:\n");
    printf("  (*ptr).x = %d\n", (*ptr).x);
    printf("  (*ptr).y = %d\n", (*ptr).y);
    
    // Modify through pointer
    (*ptr).x = 100;
    (*ptr).y = 200;
    printf("After modification through pointer:\n");
    printf("  point = (%d, %d)\n", point.x, point.y);
    printf("  (*ptr) = (%d, %d)\n", (*ptr).x, (*ptr).y);
    
    // Pointer arithmetic with structure arrays
    struct Point points[3] = {{1, 2}, {3, 4}, {5, 6}};
    struct Point *array_ptr = points;
    
    printf("\nPointer arithmetic with structure array:\n");
    for (int i = 0; i < 3; i++) {
        printf("  points[%d] = (%d, %d) at %p\n", 
               i, (array_ptr + i)->x, (array_ptr + i)->y, (void*)(array_ptr + i));
    }
    
    // Alternative traversal
    printf("\nTraversing with pointer increment:\n");
    struct Point *current = points;
    for (int i = 0; i < 3; i++) {
        printf("  Point %d: (%d, %d)\n", i, current->x, current->y);
        current++;
    }
    printf("\n");
}

void demonstrate_arrow_operator(void) {
    printf("2. ARROW OPERATOR (->)\n");
    printf("----------------------------------------\n");
    
    struct Student student = {12345, "Alice Johnson", 3.85f, 20};
    struct Student *ptr = &student;
    
    printf("Two ways to access structure members through pointer:\n");
    
    // Method 1: Dereference then access
    printf("Method 1 - (*ptr).member:\n");
    printf("  (*ptr).id = %d\n", (*ptr).id);
    printf("  (*ptr).name = %s\n", (*ptr).name);
    printf("  (*ptr).gpa = %.2f\n", (*ptr).gpa);
    printf("  (*ptr).age = %d\n", (*ptr).age);
    
    // Method 2: Arrow operator (preferred)
    printf("\nMethod 2 - ptr->member (preferred):\n");
    printf("  ptr->id = %d\n", ptr->id);
    printf("  ptr->name = %s\n", ptr->name);
    printf("  ptr->gpa = %.2f\n", ptr->gpa);
    printf("  ptr->age = %d\n", ptr->age);
    
    // Modifying through arrow operator
    printf("\nModifying through arrow operator:\n");
    ptr->id = 54321;
    strcpy(ptr->name, "Bob Wilson");
    ptr->gpa = 3.92f;
    ptr->age = 22;
    
    printf("  Updated student: %s (ID: %d, GPA: %.2f, Age: %d)\n",
           ptr->name, ptr->id, ptr->gpa, ptr->age);
    
    // Verify original structure was modified
    printf("  Original structure: %s (ID: %d, GPA: %.2f, Age: %d)\n",
           student.name, student.id, student.gpa, student.age);
    printf("\n");
}

void demonstrate_dynamic_allocation(void) {
    printf("3. DYNAMIC ALLOCATION OF STRUCTURES\n");
    printf("----------------------------------------\n");
    
    // Single structure allocation
    printf("Allocating single structure:\n");
    struct Point *point_ptr = malloc(sizeof(struct Point));
    if (point_ptr == NULL) {
        printf("  Memory allocation failed!\n");
        return;
    }
    
    point_ptr->x = 50;
    point_ptr->y = 75;
    printf("  Allocated point: (%d, %d) at %p\n", 
           point_ptr->x, point_ptr->y, (void*)point_ptr);
    
    free(point_ptr);
    point_ptr = NULL;
    printf("  Memory freed and pointer nullified\n");
    
    // Array of structures allocation
    printf("\nAllocating array of structures:\n");
    int count = 5;
    struct Student *students = malloc(count * sizeof(struct Student));
    if (students == NULL) {
        printf("  Array allocation failed!\n");
        return;
    }
    
    // Initialize array elements
    for (int i = 0; i < count; i++) {
        students[i].id = 1000 + i;
        snprintf(students[i].name, sizeof(students[i].name), "Student %d", i + 1);
        students[i].gpa = 3.0f + (float)i * 0.2f;
        students[i].age = 18 + i;
    }
    
    printf("  Allocated array of %d students:\n", count);
    for (int i = 0; i < count; i++) {
        printf("    [%d] %s (ID: %d, GPA: %.1f, Age: %d)\n",
               i, students[i].name, students[i].id, students[i].gpa, students[i].age);
    }
    
    free(students);
    students = NULL;
    printf("  Array memory freed\n");
    
    // Using helper function for allocation
    printf("\nUsing helper function for allocation:\n");
    struct Point *dynamic_point = create_point(100, 150);
    if (dynamic_point != NULL) {
        printf("  Created point: (%d, %d)\n", dynamic_point->x, dynamic_point->y);
        free(dynamic_point);
        printf("  Point freed\n");
    }
    printf("\n");
}

void demonstrate_function_parameters(void) {
    printf("4. FUNCTION PARAMETERS\n");
    printf("----------------------------------------\n");
    
    struct Point original = {10, 20};
    printf("Original point: (%d, %d)\n", original.x, original.y);
    
    // Pass by value (copy)
    printf("\nPassing by value (copy):\n");
    printf("  Before: ");
    print_point_by_value(original);
    printf("  Original after function call: (%d, %d)\n", original.x, original.y);
    
    // Pass by pointer (reference)
    printf("\nPassing by pointer (reference):\n");
    printf("  Before: ");
    print_point_by_pointer(&original);
    
    printf("  Modifying through pointer...\n");
    modify_point(&original);
    printf("  After modification: (%d, %d)\n", original.x, original.y);
    
    // Performance comparison
    printf("\nPerformance considerations:\n");
    printf("  Pass by value: Copies entire structure (%zu bytes)\n", sizeof(struct Point));
    printf("  Pass by pointer: Copies only pointer (%zu bytes)\n", sizeof(struct Point*));
    
    // Large structure example
    struct Student large_student = {99999, "Large Structure Test", 4.0f, 25};
    printf("  Large structure size: %zu bytes\n", sizeof(struct Student));
    printf("  Pointer size: %zu bytes\n", sizeof(struct Student*));
    printf("  Passing large structures by pointer is more efficient\n");
    
    // Function returning pointer
    printf("\nFunction returning pointer to structure:\n");
    struct Student *new_student = create_student(77777, "Dynamic Student", 3.75f, 21);
    if (new_student != NULL) {
        print_student(new_student);
        free_student(&new_student);
        printf("  Student freed and pointer nullified\n");
    }
    printf("\n");
}

void demonstrate_self_referential_structures(void) {
    printf("5. SELF-REFERENTIAL STRUCTURES\n");
    printf("----------------------------------------\n");
    
    printf("Creating a simple linked list:\n");
    
    // Create nodes
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));
    
    if (head == NULL || second == NULL || third == NULL) {
        printf("  Memory allocation failed!\n");
        free(head);
        free(second);
        free(third);
        return;
    }
    
    // Initialize nodes
    head->data = 10;
    head->next = second;
    
    second->data = 20;
    second->next = third;
    
    third->data = 30;
    third->next = NULL;
    
    printf("  Node addresses and connections:\n");
    printf("    head:   %p -> data: %d, next: %p\n", 
           (void*)head, head->data, (void*)head->next);
    printf("    second: %p -> data: %d, next: %p\n", 
           (void*)second, second->data, (void*)second->next);
    printf("    third:  %p -> data: %d, next: %p\n", 
           (void*)third, third->data, (void*)third->next);
    
    // Traverse the list
    printf("\nTraversing the linked list:\n");
    struct Node *current = head;
    int position = 0;
    while (current != NULL) {
        printf("  Node %d: data = %d\n", position, current->data);
        current = current->next;
        position++;
    }
    
    // Calculate total and find maximum
    printf("\nList operations:\n");
    int total = 0;
    int max_value = head->data;
    current = head;
    while (current != NULL) {
        total += current->data;
        if (current->data > max_value) {
            max_value = current->data;
        }
        current = current->next;
    }
    printf("  Total sum: %d\n", total);
    printf("  Maximum value: %d\n", max_value);
    
    // Free the list
    current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    printf("  All nodes freed\n");
    printf("\n");
}

void demonstrate_array_of_pointers(void) {
    printf("6. ARRAY OF POINTERS TO STRUCTURES\n");
    printf("----------------------------------------\n");
    
    // Create array of pointers
    const int num_students = 4;
    struct Student *class[num_students];
    
    printf("Creating array of pointers to structures:\n");
    
    // Allocate and initialize each student
    class[0] = create_student(2001, "Alice Cooper", 3.9f, 19);
    class[1] = create_student(2002, "Bob Dylan", 3.7f, 20);
    class[2] = create_student(2003, "Carol King", 3.8f, 18);
    class[3] = create_student(2004, "David Bowie", 3.6f, 21);
    
    // Check for allocation failures
    for (int i = 0; i < num_students; i++) {
        if (class[i] == NULL) {
            printf("  Failed to allocate student %d\n", i);
            // Clean up already allocated students
            for (int j = 0; j < i; j++) {
                free(class[j]);
            }
            return;
        }
    }
    
    printf("  Successfully created %d students\n", num_students);
    
    // Display all students
    printf("\nClass roster:\n");
    for (int i = 0; i < num_students; i++) {
        printf("  [%d] ", i);
        print_student(class[i]);
    }
    
    // Sort by GPA (simple bubble sort)
    printf("\nSorting by GPA (descending):\n");
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (class[j]->gpa < class[j + 1]->gpa) {
                // Swap pointers
                struct Student *temp = class[j];
                class[j] = class[j + 1];
                class[j + 1] = temp;
            }
        }
    }
    
    printf("  Sorted class roster:\n");
    for (int i = 0; i < num_students; i++) {
        printf("    %d. ", i + 1);
        print_student(class[i]);
    }
    
    // Calculate class statistics
    float total_gpa = 0.0f;
    int total_age = 0;
    for (int i = 0; i < num_students; i++) {
        total_gpa += class[i]->gpa;
        total_age += class[i]->age;
    }
    
    printf("\nClass statistics:\n");
    printf("  Average GPA: %.2f\n", total_gpa / num_students);
    printf("  Average age: %.1f\n", (float)total_age / num_students);
    
    // Free all students
    for (int i = 0; i < num_students; i++) {
        free_student(&class[i]);
    }
    printf("  All students freed\n");
    printf("\n");
}

// Helper function implementations
void print_point_by_value(struct Point p) {
    printf("Point (by value): (%d, %d)\n", p.x, p.y);
}

void print_point_by_pointer(struct Point *p) {
    if (p != NULL) {
        printf("Point (by pointer): (%d, %d)\n", p->x, p->y);
    }
}

void modify_point(struct Point *p) {
    if (p != NULL) {
        p->x *= 2;
        p->y *= 2;
    }
}

struct Point* create_point(int x, int y) {
    struct Point *p = malloc(sizeof(struct Point));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

struct Student* create_student(int id, const char* name, float gpa, int age) {
    struct Student *s = malloc(sizeof(struct Student));
    if (s != NULL) {
        s->id = id;
        strncpy(s->name, name, sizeof(s->name) - 1);
        s->name[sizeof(s->name) - 1] = '\0';  // Ensure null termination
        s->gpa = gpa;
        s->age = age;
    }
    return s;
}

void print_student(struct Student *s) {
    if (s != NULL) {
        printf("%s (ID: %d, GPA: %.1f, Age: %d)\n", 
               s->name, s->id, s->gpa, s->age);
    }
}

void free_student(struct Student **s) {
    if (s != NULL && *s != NULL) {
        free(*s);
        *s = NULL;
    }
}

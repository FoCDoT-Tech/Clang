#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure definitions
struct Point {
    int x;
    int y;
};

// Function prototypes
void demonstrate_basic_structures(void);
void demonstrate_structure_initialization(void);
void demonstrate_nested_structures(void);
void demonstrate_array_of_structures(void);
void demonstrate_structure_operations(void);
void demonstrate_memory_layout(void);
void print_point(struct Point p);

struct Rectangle {
    struct Point top_left;
    struct Point bottom_right;
};

struct Student {
    int id;
    char name[50];
    float gpa;
    int age;
};

struct Address {
    char street[100];
    char city[50];
    char state[20];
    int zipcode;
};

struct Person {
    char name[50];
    int age;
    struct Address address;
    float salary;
};

struct Book {
    char title[100];
    char author[50];
    int year;
    float price;
    int pages;
};

int main(void) {
    printf("=== Structures Demo ===\n\n");
    
    demonstrate_basic_structures();
    demonstrate_structure_initialization();
    demonstrate_nested_structures();
    demonstrate_array_of_structures();
    demonstrate_structure_operations();
    demonstrate_memory_layout();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_structures(void) {
    printf("1. BASIC STRUCTURE USAGE\n");
    printf("----------------------------------------\n");
    
    // Basic structure declaration and usage
    struct Point origin;
    origin.x = 0;
    origin.y = 0;
    
    printf("Basic point structure:\n");
    printf("  origin.x = %d\n", origin.x);
    printf("  origin.y = %d\n", origin.y);
    printf("  Point address: %p\n", (void*)&origin);
    printf("  Member addresses: x=%p, y=%p\n", (void*)&origin.x, (void*)&origin.y);
    
    // Creating and using multiple points
    struct Point p1, p2, p3;
    p1.x = 10; p1.y = 20;
    p2.x = 30; p2.y = 40;
    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;
    
    printf("\nPoint operations:\n");
    printf("  p1 = (%d, %d)\n", p1.x, p1.y);
    printf("  p2 = (%d, %d)\n", p2.x, p2.y);
    printf("  p3 = p1 + p2 = (%d, %d)\n", p3.x, p3.y);
    
    // Student structure example
    struct Student student1;
    student1.id = 12345;
    strcpy(student1.name, "Alice Johnson");
    student1.gpa = 3.85f;
    student1.age = 20;
    
    printf("\nStudent record:\n");
    printf("  ID: %d\n", student1.id);
    printf("  Name: %s\n", student1.name);
    printf("  GPA: %.2f\n", student1.gpa);
    printf("  Age: %d\n", student1.age);
    printf("\n");
}

void demonstrate_structure_initialization(void) {
    printf("2. STRUCTURE INITIALIZATION\n");
    printf("----------------------------------------\n");
    
    // Different initialization methods
    printf("Initialization methods:\n");
    
    // Method 1: Initialize during declaration
    struct Point p1 = {5, 10};
    printf("  p1 (direct init): (%d, %d)\n", p1.x, p1.y);
    
    // Method 2: Designated initializers
    struct Point p2 = {.y = 25, .x = 15};
    printf("  p2 (designated): (%d, %d)\n", p2.x, p2.y);
    
    // Method 3: Partial initialization
    struct Point p3 = {100};  // Only x initialized, y becomes 0
    printf("  p3 (partial): (%d, %d)\n", p3.x, p3.y);
    
    // Method 4: Zero initialization
    struct Point p4 = {0};    // All members become 0
    printf("  p4 (zero init): (%d, %d)\n", p4.x, p4.y);
    
    // Complex structure initialization
    struct Student student = {
        .id = 54321,
        .name = "Bob Smith",
        .gpa = 3.92f,
        .age = 22
    };
    
    printf("\nComplex initialization:\n");
    printf("  Student: %s (ID: %d, GPA: %.2f, Age: %d)\n",
           student.name, student.id, student.gpa, student.age);
    
    // Array initialization within structure
    struct Book book = {
        "The C Programming Language",
        "Kernighan & Ritchie",
        1988,
        45.99f,
        272
    };
    
    printf("\nBook structure:\n");
    printf("  Title: %s\n", book.title);
    printf("  Author: %s\n", book.author);
    printf("  Year: %d\n", book.year);
    printf("  Price: $%.2f\n", book.price);
    printf("  Pages: %d\n", book.pages);
    printf("\n");
}

void demonstrate_nested_structures(void) {
    printf("3. NESTED STRUCTURES\n");
    printf("----------------------------------------\n");
    
    // Creating nested structure
    struct Person person = {
        "John Doe",
        35,
        {"123 Main St", "Springfield", "IL", 62701},
        75000.0f
    };
    
    printf("Person with nested address:\n");
    printf("  Name: %s\n", person.name);
    printf("  Age: %d\n", person.age);
    printf("  Salary: $%.2f\n", person.salary);
    printf("  Address:\n");
    printf("    Street: %s\n", person.address.street);
    printf("    City: %s\n", person.address.city);
    printf("    State: %s\n", person.address.state);
    printf("    ZIP: %d\n", person.address.zipcode);
    
    // Modifying nested structure members
    strcpy(person.address.street, "456 Oak Avenue");
    person.address.zipcode = 62702;
    
    printf("\nAfter address update:\n");
    printf("  New street: %s\n", person.address.street);
    printf("  New ZIP: %d\n", person.address.zipcode);
    
    // Rectangle with nested points
    struct Rectangle rect = {
        {0, 0},      // top_left
        {100, 50}    // bottom_right
    };
    
    printf("\nRectangle structure:\n");
    printf("  Top-left: (%d, %d)\n", rect.top_left.x, rect.top_left.y);
    printf("  Bottom-right: (%d, %d)\n", rect.bottom_right.x, rect.bottom_right.y);
    printf("  Width: %d\n", rect.bottom_right.x - rect.top_left.x);
    printf("  Height: %d\n", rect.bottom_right.y - rect.top_left.y);
    printf("  Area: %d\n", (rect.bottom_right.x - rect.top_left.x) * 
                           (rect.bottom_right.y - rect.top_left.y));
    printf("\n");
}

void demonstrate_array_of_structures(void) {
    printf("4. ARRAY OF STRUCTURES\n");
    printf("----------------------------------------\n");
    
    // Array of students
    struct Student class[5] = {
        {1001, "Alice Brown", 3.8f, 19},
        {1002, "Bob Wilson", 3.6f, 20},
        {1003, "Carol Davis", 3.9f, 18},
        {1004, "David Miller", 3.4f, 21},
        {1005, "Eva Garcia", 3.7f, 19}
    };
    
    printf("Class roster:\n");
    for (int i = 0; i < 5; i++) {
        printf("  %d. %s (ID: %d, GPA: %.1f, Age: %d)\n",
               i + 1, class[i].name, class[i].id, class[i].gpa, class[i].age);
    }
    
    // Calculate class statistics
    float total_gpa = 0.0f;
    int total_age = 0;
    float highest_gpa = class[0].gpa;
    int youngest = class[0].age;
    
    for (int i = 0; i < 5; i++) {
        total_gpa += class[i].gpa;
        total_age += class[i].age;
        if (class[i].gpa > highest_gpa) {
            highest_gpa = class[i].gpa;
        }
        if (class[i].age < youngest) {
            youngest = class[i].age;
        }
    }
    
    printf("\nClass statistics:\n");
    printf("  Average GPA: %.2f\n", total_gpa / 5);
    printf("  Average age: %.1f\n", (float)total_age / 5);
    printf("  Highest GPA: %.1f\n", highest_gpa);
    printf("  Youngest student: %d years old\n", youngest);
    
    // Array of points forming a polygon
    struct Point polygon[6] = {
        {0, 0}, {10, 0}, {15, 8}, {10, 16}, {0, 16}, {-5, 8}
    };
    
    printf("\nPolygon vertices:\n");
    for (int i = 0; i < 6; i++) {
        printf("  Vertex %d: (%d, %d)\n", i, polygon[i].x, polygon[i].y);
    }
    printf("\n");
}

void demonstrate_structure_operations(void) {
    printf("5. STRUCTURE OPERATIONS\n");
    printf("----------------------------------------\n");
    
    // Structure assignment
    struct Point p1 = {10, 20};
    struct Point p2;
    
    p2 = p1;  // Copy entire structure
    printf("Structure assignment:\n");
    printf("  p1 = (%d, %d)\n", p1.x, p1.y);
    printf("  p2 = p1 = (%d, %d)\n", p2.x, p2.y);
    
    // Modify p2 to show they're independent
    p2.x = 100;
    p2.y = 200;
    printf("  After modifying p2:\n");
    printf("    p1 = (%d, %d) (unchanged)\n", p1.x, p1.y);
    printf("    p2 = (%d, %d) (modified)\n", p2.x, p2.y);
    
    // Structure comparison (manual)
    struct Student s1 = {123, "John", 3.5f, 20};
    struct Student s2 = {123, "John", 3.5f, 20};
    
    printf("\nStructure comparison:\n");
    printf("  s1: ID=%d, Name=%s, GPA=%.1f, Age=%d\n", 
           s1.id, s1.name, s1.gpa, s1.age);
    printf("  s2: ID=%d, Name=%s, GPA=%.1f, Age=%d\n", 
           s2.id, s2.name, s2.gpa, s2.age);
    
    // Manual comparison (structures can't be compared with ==)
    int are_equal = (s1.id == s2.id) && 
                   (strcmp(s1.name, s2.name) == 0) &&
                   (s1.gpa == s2.gpa) && 
                   (s1.age == s2.age);
    
    printf("  Are structures equal? %s\n", are_equal ? "Yes" : "No");
    
    // Structure as function parameter (by value)
    printf("\nPassing structure to function:\n");
    struct Point test_point = {50, 75};
    print_point(test_point);
    
    // Structure size and alignment
    printf("\nStructure sizes:\n");
    printf("  sizeof(struct Point): %zu bytes\n", sizeof(struct Point));
    printf("  sizeof(struct Student): %zu bytes\n", sizeof(struct Student));
    printf("  sizeof(struct Person): %zu bytes\n", sizeof(struct Person));
    printf("  sizeof(struct Rectangle): %zu bytes\n", sizeof(struct Rectangle));
    printf("\n");
}

void demonstrate_memory_layout(void) {
    printf("6. MEMORY LAYOUT AND ALIGNMENT\n");
    printf("----------------------------------------\n");
    
    struct Point point = {10, 20};
    
    printf("Point structure memory layout:\n");
    printf("  Structure address: %p\n", (void*)&point);
    printf("  point.x address:   %p (offset: %zu)\n", 
           (void*)&point.x, (char*)&point.x - (char*)&point);
    printf("  point.y address:   %p (offset: %zu)\n", 
           (void*)&point.y, (char*)&point.y - (char*)&point);
    printf("  Structure size: %zu bytes\n", sizeof(point));
    
    struct Student student = {12345, "Test Student", 3.5f, 20};
    
    printf("\nStudent structure memory layout:\n");
    printf("  Structure address: %p\n", (void*)&student);
    printf("  id address:        %p (offset: %zu)\n", 
           (void*)&student.id, (char*)&student.id - (char*)&student);
    printf("  name address:      %p (offset: %zu)\n", 
           (void*)&student.name, (char*)&student.name - (char*)&student);
    printf("  gpa address:       %p (offset: %zu)\n", 
           (void*)&student.gpa, (char*)&student.gpa - (char*)&student);
    printf("  age address:       %p (offset: %zu)\n", 
           (void*)&student.age, (char*)&student.age - (char*)&student);
    printf("  Structure size: %zu bytes\n", sizeof(student));
    
    // Demonstrate padding
    struct PaddingExample {
        char c;      // 1 byte
        int i;       // 4 bytes
        char c2;     // 1 byte
        double d;    // 8 bytes
    } padded = {'A', 42, 'B', 3.14159};
    
    printf("\nPadding demonstration:\n");
    printf("  Expected minimum size: %zu bytes\n", 
           sizeof(char) + sizeof(int) + sizeof(char) + sizeof(double));
    printf("  Actual structure size: %zu bytes\n", sizeof(padded));
    printf("  Member offsets:\n");
    printf("    c:  offset %zu\n", (char*)&padded.c - (char*)&padded);
    printf("    i:  offset %zu\n", (char*)&padded.i - (char*)&padded);
    printf("    c2: offset %zu\n", (char*)&padded.c2 - (char*)&padded);
    printf("    d:  offset %zu\n", (char*)&padded.d - (char*)&padded);
    printf("  Padding added for alignment efficiency\n");
    
    // Array of structures memory layout
    struct Point points[3] = {{1, 2}, {3, 4}, {5, 6}};
    
    printf("\nArray of structures:\n");
    printf("  Array address: %p\n", (void*)points);
    for (int i = 0; i < 3; i++) {
        printf("  points[%d]: %p (offset: %zu)\n", 
               i, (void*)&points[i], (char*)&points[i] - (char*)points);
    }
    printf("  Each structure: %zu bytes apart\n", sizeof(struct Point));
    printf("\n");
}

void print_point(struct Point p) {
    printf("    Point: (%d, %d)\n", p.x, p.y);
}

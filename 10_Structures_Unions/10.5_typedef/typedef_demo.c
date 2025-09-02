#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Basic typedef examples
typedef int Integer;
typedef float Real;
typedef char Character;
typedef unsigned char Byte;

// Structure typedefs
typedef struct {
    int x, y;
} Point;

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

typedef struct node {
    int data;
    struct node *next;  // Must use struct name for self-reference
} Node;

// Union typedef
typedef union {
    int i;
    float f;
    char c;
} Value;

// Enum typedef
typedef enum {
    RED, GREEN, BLUE
} Color;

typedef enum {
    FALSE, TRUE
} Boolean;

// Pointer typedefs
typedef int* IntPtr;
typedef char* String;
typedef Employee* EmployeePtr;

// Array typedefs
typedef int Matrix[3][3];
typedef char Buffer[256];
typedef float Vector[3];

// Function pointer typedefs
typedef int (*BinaryOperation)(int, int);
typedef void (*Callback)(void);
typedef Boolean (*Predicate)(int);

// Function prototypes
void demonstrate_basic_typedef(void);
void demonstrate_structure_typedef(void);
void demonstrate_pointer_typedef(void);
void demonstrate_array_typedef(void);
void demonstrate_function_pointer_typedef(void);
void demonstrate_practical_applications(void);
void demonstrate_common_pitfalls(void);
void apply_operation(Integer x, Integer y, BinaryOperation op, String name);

// Practical application typedefs
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef size_t Length;
typedef FILE* FileHandle;

// Complex typedef examples
typedef struct {
    String name;
    Integer age;
    Real salary;
    Boolean active;
} Person;

typedef struct {
    Point position;
    Color color;
    Real radius;
} Circle;

// Function implementations for function pointer demo
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }
int subtract(int a, int b) { return a - b; }

void cleanup(void) { printf("    Cleanup function called\n"); }
void initialize(void) { printf("    Initialize function called\n"); }

Boolean is_positive(int x) { return x > 0 ? TRUE : FALSE; }
Boolean is_even(int x) { return x % 2 == 0 ? TRUE : FALSE; }

int main(void) {
    printf("=== typedef Demo ===\n\n");
    
    demonstrate_basic_typedef();
    demonstrate_structure_typedef();
    demonstrate_pointer_typedef();
    demonstrate_array_typedef();
    demonstrate_function_pointer_typedef();
    demonstrate_practical_applications();
    demonstrate_common_pitfalls();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_typedef(void) {
    printf("1. BASIC typedef USAGE\n");
    printf("----------------------------------------\n");
    
    printf("Basic type aliases:\n");
    printf("  typedef int Integer;\n");
    printf("  typedef float Real;\n");
    printf("  typedef char Character;\n");
    printf("  typedef unsigned char Byte;\n");
    
    // Use typedef aliases
    Integer count = 42;
    Real temperature = 98.6f;
    Character grade = 'A';
    Byte flags = 0xFF;
    
    printf("\nUsing typedef aliases:\n");
    printf("  Integer count = %d\n", count);
    printf("  Real temperature = %.1f\n", temperature);
    printf("  Character grade = %c\n", grade);
    printf("  Byte flags = 0x%02X\n", flags);
    
    printf("\nSize comparison:\n");
    printf("  sizeof(Integer) = %zu bytes (same as int: %zu)\n", 
           sizeof(Integer), sizeof(int));
    printf("  sizeof(Real) = %zu bytes (same as float: %zu)\n", 
           sizeof(Real), sizeof(float));
    printf("  sizeof(Character) = %zu bytes (same as char: %zu)\n", 
           sizeof(Character), sizeof(char));
    printf("  sizeof(Byte) = %zu bytes (same as unsigned char: %zu)\n", 
           sizeof(Byte), sizeof(unsigned char));
    
    // Enum typedef
    Color primary = RED;
    Boolean flag = TRUE;
    
    printf("\nEnum typedefs:\n");
    printf("  Color primary = RED (%d)\n", primary);
    printf("  Boolean flag = TRUE (%d)\n", flag);
    
    // Demonstrate type equivalence
    int regular_int = count;  // typedef is just an alias
    printf("  Type compatibility: Integer -> int = %d\n", regular_int);
    printf("\n");
}

void demonstrate_structure_typedef(void) {
    printf("2. STRUCTURE typedef\n");
    printf("----------------------------------------\n");
    
    printf("Structure typedef patterns:\n");
    
    // Anonymous structure typedef
    printf("1. Anonymous structure:\n");
    printf("   typedef struct { int x, y; } Point;\n");
    
    Point p1 = {10, 20};
    Point p2 = {30, 40};
    
    printf("   Point p1 = {%d, %d}\n", p1.x, p1.y);
    printf("   Point p2 = {%d, %d}\n", p2.x, p2.y);
    
    // Named structure typedef
    printf("\n2. Named structure (for self-reference):\n");
    printf("   typedef struct node { int data; struct node *next; } Node;\n");
    
    Node *head = malloc(sizeof(Node));
    Node *second = malloc(sizeof(Node));
    
    if (head && second) {
        head->data = 100;
        head->next = second;
        second->data = 200;
        second->next = NULL;
        
        printf("   Linked list: %d -> %d -> NULL\n", head->data, second->data);
        
        free(head);
        free(second);
    }
    
    // Complex structure typedef
    printf("\n3. Complex structure:\n");
    Employee emp = {"Alice Johnson", 30, 75000.0f};
    printf("   Employee: %s, Age: %d, Salary: $%.2f\n", 
           emp.name, emp.age, emp.salary);
    
    // Union typedef
    printf("\n4. Union typedef:\n");
    Value val;
    val.i = 42;
    printf("   Value as int: %d\n", val.i);
    val.f = 3.14f;
    printf("   Value as float: %.2f\n", val.f);
    val.c = 'X';
    printf("   Value as char: %c\n", val.c);
    
    printf("   sizeof(Value) = %zu bytes\n", sizeof(Value));
    printf("\n");
}

void demonstrate_pointer_typedef(void) {
    printf("3. POINTER typedef\n");
    printf("----------------------------------------\n");
    
    printf("Pointer type aliases:\n");
    printf("  typedef int* IntPtr;\n");
    printf("  typedef char* String;\n");
    printf("  typedef Employee* EmployeePtr;\n");
    
    // Integer pointer typedef
    Integer value = 42;
    IntPtr ptr = &value;
    printf("\n  IntPtr usage:\n");
    printf("    value = %d\n", value);
    printf("    *ptr = %d\n", *ptr);
    printf("    ptr address = %p\n", (void*)ptr);
    
    // String typedef
    String message = "Hello, typedef!";
    printf("\n  String usage:\n");
    printf("    message = \"%s\"\n", message);
    printf("    message[0] = '%c'\n", message[0]);
    printf("    strlen(message) = %zu\n", strlen(message));
    
    // Structure pointer typedef
    Employee emp = {"Bob Wilson", 35, 80000.0f};
    EmployeePtr emp_ptr = &emp;
    
    printf("\n  EmployeePtr usage:\n");
    printf("    emp_ptr->name = \"%s\"\n", emp_ptr->name);
    printf("    emp_ptr->age = %d\n", emp_ptr->age);
    printf("    emp_ptr->salary = $%.2f\n", emp_ptr->salary);
    
    // Demonstrate pointer arithmetic
    Integer numbers[] = {10, 20, 30, 40, 50};
    IntPtr num_ptr = numbers;
    
    printf("\n  Pointer arithmetic with typedef:\n");
    for (int i = 0; i < 5; i++) {
        printf("    numbers[%d] = %d (via typedef pointer)\n", i, *(num_ptr + i));
    }
    
    // Multiple pointer declarations
    printf("\n  Multiple declarations:\n");
    IntPtr p1, p2;  // Both are int* due to typedef
    printf("    IntPtr p1, p2; // Both are int* pointers\n");
    printf("    This is different from: int* p1, p2; // Only p1 is pointer\n");
    printf("\n");
}

void demonstrate_array_typedef(void) {
    printf("4. ARRAY typedef\n");
    printf("----------------------------------------\n");
    
    printf("Array type aliases:\n");
    printf("  typedef int Matrix[3][3];\n");
    printf("  typedef char Buffer[256];\n");
    printf("  typedef float Vector[3];\n");
    
    // Matrix typedef
    Matrix m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("\n  Matrix usage:\n");
    for (int i = 0; i < 3; i++) {
        printf("    [");
        for (int j = 0; j < 3; j++) {
            printf("%2d", m[i][j]);
            if (j < 2) printf(" ");
        }
        printf("]\n");
    }
    
    // Buffer typedef
    Buffer buf;
    strcpy(buf, "This is a buffer with typedef");
    printf("\n  Buffer usage:\n");
    printf("    Buffer content: \"%s\"\n", buf);
    printf("    Buffer size: %zu bytes\n", sizeof(buf));
    
    // Vector typedef
    Vector v = {1.0f, 2.0f, 3.0f};
    printf("\n  Vector usage:\n");
    printf("    Vector: [%.1f, %.1f, %.1f]\n", v[0], v[1], v[2]);
    
    // Calculate vector magnitude
    Real magnitude = 0.0f;
    for (int i = 0; i < 3; i++) {
        magnitude += v[i] * v[i];
    }
    magnitude = sqrtf(magnitude);
    printf("    Magnitude: %.2f\n", magnitude);
    
    printf("    sizeof(Vector) = %zu bytes\n", sizeof(Vector));
    printf("\n");
}

void demonstrate_function_pointer_typedef(void) {
    printf("5. FUNCTION POINTER typedef\n");
    printf("----------------------------------------\n");
    
    printf("Function pointer type aliases:\n");
    printf("  typedef int (*BinaryOperation)(int, int);\n");
    printf("  typedef void (*Callback)(void);\n");
    printf("  typedef Boolean (*Predicate)(int);\n");
    
    // Binary operation typedef
    BinaryOperation ops[] = {add, subtract, multiply};
    String op_names[] = {"add", "subtract", "multiply"};
    
    printf("\n  BinaryOperation usage:\n");
    Integer a = 15, b = 7;
    for (int i = 0; i < 3; i++) {
        Integer result = ops[i](a, b);
        printf("    %s(%d, %d) = %d\n", op_names[i], a, b, result);
    }
    
    // Callback typedef
    Callback callbacks[] = {initialize, cleanup};
    String callback_names[] = {"initialize", "cleanup"};
    
    printf("\n  Callback usage:\n");
    for (int i = 0; i < 2; i++) {
        printf("    Calling %s:\n", callback_names[i]);
        callbacks[i]();
    }
    
    // Predicate typedef
    Predicate tests[] = {is_positive, is_even};
    String test_names[] = {"is_positive", "is_even"};
    Integer test_values[] = {-5, 0, 3, 8, -2};
    
    printf("\n  Predicate usage:\n");
    for (int i = 0; i < 2; i++) {
        printf("    %s test:\n", test_names[i]);
        for (int j = 0; j < 5; j++) {
            Boolean result = tests[i](test_values[j]);
            printf("      %s(%d) = %s\n", 
                   test_names[i], test_values[j], result ? "TRUE" : "FALSE");
        }
    }
    
    // Function pointer as parameter (defined at end of file)
    
    printf("\n  Function pointer as parameter:\n");
    apply_operation(10, 5, add, "addition");
    apply_operation(10, 5, multiply, "multiplication");
    printf("\n");
}

void demonstrate_practical_applications(void) {
    printf("6. PRACTICAL APPLICATIONS\n");
    printf("----------------------------------------\n");
    
    printf("Real-world typedef usage:\n");
    
    // Platform abstraction
    printf("\n1. Platform abstraction:\n");
    uint32_t large_number = 4294967295U;
    uint16_t medium_number = 65535;
    uint8_t small_number = 255;
    
    printf("   uint32_t: %u (%zu bytes)\n", large_number, sizeof(uint32_t));
    printf("   uint16_t: %u (%zu bytes)\n", medium_number, sizeof(uint16_t));
    printf("   uint8_t: %u (%zu bytes)\n", small_number, sizeof(uint8_t));
    
    // API design
    printf("\n2. Clean API design:\n");
    Person person = {"Charlie Brown", 25, 50000.0f, TRUE};
    printf("   Person: %s, %d years old, $%.2f salary, %s\n",
           person.name, person.age, person.salary, 
           person.active ? "active" : "inactive");
    
    Circle circle = {{100, 200}, BLUE, 50.0f};
    printf("   Circle: center(%d,%d), color=%d, radius=%.1f\n",
           circle.position.x, circle.position.y, circle.color, circle.radius);
    
    // File handling
    printf("\n3. File handling abstraction:\n");
    FileHandle file = fopen("test.txt", "w");
    if (file) {
        fprintf(file, "Hello from typedef demo!\n");
        fclose(file);
        printf("   File written successfully using FileHandle typedef\n");
        
        // Clean up
        remove("test.txt");
    } else {
        printf("   Could not create file\n");
    }
    
    // Size and length abstraction
    printf("\n4. Size and length abstraction:\n");
    Length str_len = strlen("Hello, World!");
    Integer sample_array[] = {1, 2, 3, 4, 5};
    Length array_len = sizeof(sample_array) / sizeof(sample_array[0]);
    
    printf("   String length: %zu characters\n", str_len);
    printf("   Array length: %zu elements\n", array_len);
    
    printf("\n5. Benefits demonstrated:\n");
    printf("   ✓ Code is more readable and self-documenting\n");
    printf("   ✓ Types can be changed in one place\n");
    printf("   ✓ Platform-specific types are abstracted\n");
    printf("   ✓ Complex types have simple names\n");
    printf("   ✓ API design is cleaner and more intuitive\n");
    printf("\n");
}

void demonstrate_common_pitfalls(void) {
    printf("7. COMMON PITFALLS AND BEST PRACTICES\n");
    printf("----------------------------------------\n");
    
    printf("Common mistakes and how to avoid them:\n");
    
    // Pitfall 1: Pointer confusion
    printf("\n1. Pointer typedef confusion:\n");
    printf("   typedef int* IntPtr;\n");
    printf("   IntPtr a, b;  // Both a and b are int* (GOOD)\n");
    printf("   \n");
    printf("   Compare with:\n");
    printf("   int* a, b;    // Only a is int*, b is int (CONFUSING)\n");
    
    IntPtr ptr_a, ptr_b;
    Integer val1 = 10, val2 = 20;
    ptr_a = &val1;
    ptr_b = &val2;
    
    printf("   Demonstration:\n");
    printf("     *ptr_a = %d, *ptr_b = %d\n", *ptr_a, *ptr_b);
    printf("     Both are properly declared as pointers\n");
    
    // Pitfall 2: Hiding complexity
    printf("\n2. Hiding too much complexity:\n");
    printf("   typedef struct Node* NodePtr;  // Hides pointer nature\n");
    printf("   NodePtr node;  // Not obvious this is a pointer\n");
    printf("   \n");
    printf("   Better approach:\n");
    printf("   typedef struct Node Node;  // Clear structure type\n");
    printf("   Node* node;  // Obviously a pointer\n");
    
    // Pitfall 3: Inconsistent naming
    printf("\n3. Naming conventions:\n");
    printf("   Good practices:\n");
    printf("     • Use consistent naming (CamelCase or snake_case)\n");
    printf("     • Make names descriptive and meaningful\n");
    printf("     • Consider using _t suffix for type names\n");
    printf("     • Avoid single-letter or cryptic names\n");
    
    // Pitfall 4: Forward declaration issues
    printf("\n4. Forward declaration with self-referential structures:\n");
    printf("   typedef struct Node Node;  // Forward declaration\n");
    printf("   struct Node {\n");
    printf("       int data;\n");
    printf("       Node* next;  // Can use typedef name\n");
    printf("   };\n");
    
    // Best practices summary
    printf("\n5. Best practices summary:\n");
    printf("   ✓ Use typedef to improve readability\n");
    printf("   ✓ Choose descriptive names\n");
    printf("   ✓ Be consistent with naming conventions\n");
    printf("   ✓ Don't hide pointer nature unnecessarily\n");
    printf("   ✓ Use for platform abstraction\n");
    printf("   ✓ Document complex typedefs\n");
    printf("   ✗ Don't overuse typedef\n");
    printf("   ✗ Don't make code less clear\n");
    printf("   ✗ Don't hide important type information\n");
    
    // Performance note
    printf("\n6. Performance considerations:\n");
    printf("   • typedef creates NO runtime overhead\n");
    printf("   • It's purely a compile-time feature\n");
    printf("   • Generated code is identical to original types\n");
    printf("   • Use freely for code clarity\n");
    printf("\n");
}

void apply_operation(Integer x, Integer y, BinaryOperation op, String name) {
    Integer result = op(x, y);
    printf("    Applied %s: %d\n", name, result);
}

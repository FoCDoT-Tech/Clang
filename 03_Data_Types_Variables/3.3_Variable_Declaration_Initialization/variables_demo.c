/*
 * variables_demo.c - Demonstrates variable declaration, initialization, and scope
 * Shows different storage classes and scope rules
 */

#include <stdio.h>

// Global variables (accessible everywhere)
int global_var = 100;           // Initialized global variable
int uninitialized_global;      // Automatically initialized to 0

// Function declarations
void demonstrate_local_scope(void);
void demonstrate_static_variables(void);
void demonstrate_storage_classes(void);

int main() {
    printf("=== Variables Declaration & Initialization Demo ===\n\n");
    
    // 1. BASIC DECLARATION AND INITIALIZATION
    printf("1. DECLARATION AND INITIALIZATION:\n");
    
    // Declaration only (undefined initial value for local variables)
    int uninitialized_local;
    
    // Declaration with initialization
    int age = 25;
    char grade = 'A';
    float price = 19.99f;
    
    // Multiple declarations
    int a, b, c;                    // All uninitialized
    int x = 10, y = 20, z;          // x and y initialized, z uninitialized
    
    printf("- Initialized variables:\n");
    printf("  age = %d\n", age);
    printf("  grade = %c\n", grade);
    printf("  price = %.2f\n", price);
    printf("  x = %d, y = %d\n", x, y);
    
    // Assignment after declaration
    a = 100;
    b = 200;
    c = 300;
    z = 30;
    
    printf("- Assigned after declaration:\n");
    printf("  a = %d, b = %d, c = %d, z = %d\n", a, b, c, z);
    
    // Warning: uninitialized local variables have garbage values
    printf("- Uninitialized local variable: %d (garbage value!)\n", uninitialized_local);
    printf("\n");
    
    // 2. GLOBAL VARIABLES
    printf("2. GLOBAL VARIABLES:\n");
    printf("- global_var = %d (initialized)\n", global_var);
    printf("- uninitialized_global = %d (auto-initialized to 0)\n", uninitialized_global);
    
    // Modify global variable
    global_var = 500;
    printf("- Modified global_var = %d\n", global_var);
    printf("\n");
    
    // 3. SCOPE DEMONSTRATION
    printf("3. VARIABLE SCOPE:\n");
    demonstrate_local_scope();
    
    // 4. STATIC VARIABLES
    printf("4. STATIC VARIABLES:\n");
    demonstrate_static_variables();
    demonstrate_static_variables();  // Call again to show persistence
    demonstrate_static_variables();  // Call third time
    
    // 5. STORAGE CLASSES
    printf("5. STORAGE CLASSES:\n");
    demonstrate_storage_classes();
    
    printf("\n✓ All variable concepts demonstrated!\n");
    return 0;
}

void demonstrate_local_scope(void) {
    int local_var = 42;             // Local to this function
    
    printf("- Inside function: local_var = %d\n", local_var);
    printf("- Inside function: global_var = %d\n", global_var);
    
    // Block scope example
    {
        int block_var = 99;         // Only exists in this block
        int local_var = 777;        // Shadows the outer local_var
        
        printf("- Inside block: block_var = %d\n", block_var);
        printf("- Inside block: local_var = %d (shadows outer)\n", local_var);
    }
    // block_var not accessible here
    
    printf("- After block: local_var = %d (outer scope restored)\n", local_var);
    printf("\n");
}

void demonstrate_static_variables(void) {
    static int static_counter = 0;  // Initialized only once
    int auto_counter = 0;           // Reinitialized every call
    
    static_counter++;
    auto_counter++;
    
    printf("- Static counter: %d (persists between calls)\n", static_counter);
    printf("- Auto counter: %d (reset every call)\n", auto_counter);
}

void demonstrate_storage_classes(void) {
    // auto (default for local variables)
    auto int auto_var = 10;         // 'auto' keyword rarely used
    
    // static (retains value, initialized once)
    static int static_var = 0;
    static_var += 5;
    
    // register (hint to store in CPU register)
    register int fast_var = 100;    // Compiler may ignore this hint
    
    printf("- auto variable: %d\n", auto_var);
    printf("- static variable: %d (incremented each call)\n", static_var);
    printf("- register variable: %d\n", fast_var);
    
    // extern example (global_var is defined globally)
    extern int global_var;          // Refers to the global variable
    printf("- extern reference to global_var: %d\n", global_var);
    
    printf("\n");
}

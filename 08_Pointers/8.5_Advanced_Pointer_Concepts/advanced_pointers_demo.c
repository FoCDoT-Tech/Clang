#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void demonstrate_pointer_to_pointer(void);
void demonstrate_array_of_pointers(void);
void demonstrate_pointer_to_array(void);
void demonstrate_const_with_pointers(void);
void demonstrate_complex_declarations(void);
void demonstrate_practical_applications(void);

// Helper functions
void print_matrix(int **matrix, int rows, int cols);
void modify_through_pointer(int *ptr);
void try_modify_const(const int *ptr);

int main() {
    printf("=== Advanced Pointer Concepts Demo ===\n\n");
    
    demonstrate_pointer_to_pointer();
    demonstrate_array_of_pointers();
    demonstrate_pointer_to_array();
    demonstrate_const_with_pointers();
    demonstrate_complex_declarations();
    demonstrate_practical_applications();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_pointer_to_pointer(void) {
    printf("1. POINTER TO POINTER\n");
    printf("----------------------------------------\n");
    
    // Basic pointer to pointer
    int value = 42;
    int *ptr = &value;
    int **ptr_to_ptr = &ptr;
    
    printf("Multi-level indirection:\n");
    printf("  value = %d (at address %p)\n", value, (void*)&value);
    printf("  *ptr = %d (ptr points to %p)\n", *ptr, (void*)ptr);
    printf("  **ptr_to_ptr = %d (ptr_to_ptr points to %p)\n", **ptr_to_ptr, (void*)ptr_to_ptr);
    
    printf("\nAddress chain:\n");
    printf("  &value = %p\n", (void*)&value);
    printf("  ptr = %p (same as &value)\n", (void*)ptr);
    printf("  &ptr = %p\n", (void*)&ptr);
    printf("  ptr_to_ptr = %p (same as &ptr)\n", (void*)ptr_to_ptr);
    
    // Modifying value through double pointer
    printf("\nModifying through double pointer:\n");
    printf("  Original value: %d\n", value);
    **ptr_to_ptr = 100;
    printf("  After **ptr_to_ptr = 100: %d\n", value);
    
    // Triple pointer example
    int ***triple_ptr = &ptr_to_ptr;
    printf("\nTriple pointer:\n");
    printf("  ***triple_ptr = %d\n", ***triple_ptr);
    ***triple_ptr = 200;
    printf("  After ***triple_ptr = 200: value = %d\n", value);
    
    // Array of values with pointer to pointer
    printf("\nArray access through pointer to pointer:\n");
    int numbers[] = {10, 20, 30, 40, 50};
    int *array_ptr = numbers;
    int **ptr_to_array_ptr = &array_ptr;
    
    printf("  Array: [");
    for (int i = 0; i < 5; i++) {
        printf("%d", (*ptr_to_array_ptr)[i]);
        if (i < 4) printf(", ");
    }
    printf("]\n");
    
    printf("  Accessing via **ptr_to_array_ptr: %d\n", **ptr_to_array_ptr);
    printf("  Accessing via *(*ptr_to_array_ptr + 2): %d\n", *(*ptr_to_array_ptr + 2));
    printf("\n");
}

void demonstrate_array_of_pointers(void) {
    printf("2. ARRAY OF POINTERS\n");
    printf("----------------------------------------\n");
    
    // Array of pointers to integers
    int a = 10, b = 20, c = 30, d = 40;
    int *int_ptrs[4] = {&a, &b, &c, &d};
    
    printf("Array of pointers to integers:\n");
    for (int i = 0; i < 4; i++) {
        printf("  int_ptrs[%d] points to %d at address %p\n", 
               i, *int_ptrs[i], (void*)int_ptrs[i]);
    }
    
    // Modify values through array of pointers
    printf("\nModifying values through pointer array:\n");
    for (int i = 0; i < 4; i++) {
        *int_ptrs[i] *= 10;
    }
    printf("  After multiplication: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    
    // Array of pointers to strings
    printf("\nArray of pointers to strings:\n");
    char *fruits[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int fruit_count = sizeof(fruits) / sizeof(fruits[0]);
    
    printf("  Fruits: ");
    for (int i = 0; i < fruit_count; i++) {
        printf("\"%s\"", fruits[i]);
        if (i < fruit_count - 1) printf(", ");
    }
    printf("\n");
    
    printf("  String details:\n");
    for (int i = 0; i < fruit_count; i++) {
        printf("    fruits[%d] = \"%s\" (length: %zu, address: %p)\n", 
               i, fruits[i], strlen(fruits[i]), (void*)fruits[i]);
    }
    
    // Dynamic array of pointers
    printf("\nDynamic array of pointers:\n");
    int **dynamic_ptrs = malloc(3 * sizeof(int*));
    int x = 100, y = 200, z = 300;
    
    dynamic_ptrs[0] = &x;
    dynamic_ptrs[1] = &y;
    dynamic_ptrs[2] = &z;
    
    printf("  Dynamic pointer array: [");
    for (int i = 0; i < 3; i++) {
        printf("%d", *dynamic_ptrs[i]);
        if (i < 2) printf(", ");
    }
    printf("]\n");
    
    free(dynamic_ptrs);
    printf("\n");
}

void demonstrate_pointer_to_array(void) {
    printf("3. POINTER TO ARRAY\n");
    printf("----------------------------------------\n");
    
    // Pointer to array of integers
    int arr[5] = {1, 2, 3, 4, 5};
    int (*ptr_to_array)[5] = &arr;
    
    printf("Pointer to array of 5 integers:\n");
    printf("  Array: [");
    for (int i = 0; i < 5; i++) {
        printf("%d", arr[i]);
        if (i < 4) printf(", ");
    }
    printf("]\n");
    
    printf("  ptr_to_array points to: %p\n", (void*)ptr_to_array);
    printf("  &arr = %p (same address)\n", (void*)&arr);
    
    printf("  Accessing elements through pointer to array:\n");
    for (int i = 0; i < 5; i++) {
        printf("    (*ptr_to_array)[%d] = %d\n", i, (*ptr_to_array)[i]);
    }
    
    // Pointer to 2D array
    printf("\nPointer to 2D array:\n");
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int (*ptr_to_2d)[3][4] = &matrix;
    
    printf("  Matrix:\n");
    for (int i = 0; i < 3; i++) {
        printf("    [");
        for (int j = 0; j < 4; j++) {
            printf("%2d", (*ptr_to_2d)[i][j]);
            if (j < 3) printf(", ");
        }
        printf("]\n");
    }
    
    // Array of arrays vs pointer to array
    printf("\nArray of arrays vs pointer to array:\n");
    int row1[] = {10, 20, 30};
    int row2[] = {40, 50, 60};
    int row3[] = {70, 80, 90};
    
    int *rows[3] = {row1, row2, row3};  // Array of pointers
    int grid[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};  // 2D array
    int (*ptr_to_grid)[3] = grid;  // Pointer to array
    
    printf("  Array of pointers approach:\n");
    for (int i = 0; i < 3; i++) {
        printf("    Row %d: [", i);
        for (int j = 0; j < 3; j++) {
            printf("%d", rows[i][j]);
            if (j < 2) printf(", ");
        }
        printf("]\n");
    }
    
    printf("  Pointer to array approach:\n");
    for (int i = 0; i < 3; i++) {
        printf("    Row %d: [", i);
        for (int j = 0; j < 3; j++) {
            printf("%d", (*(ptr_to_grid + i))[j]);
            if (j < 2) printf(", ");
        }
        printf("]\n");
    }
    printf("\n");
}

void demonstrate_const_with_pointers(void) {
    printf("4. CONST WITH POINTERS\n");
    printf("----------------------------------------\n");
    
    int value1 = 10, value2 = 20;
    
    // 1. Pointer to constant
    printf("1. Pointer to constant (const int *):\n");
    const int *ptr_to_const = &value1;
    printf("  *ptr_to_const = %d\n", *ptr_to_const);
    printf("  Can reassign pointer: ");
    ptr_to_const = &value2;
    printf("*ptr_to_const = %d\n", *ptr_to_const);
    printf("  Cannot modify value through pointer: *ptr_to_const = 30; // ERROR\n");
    
    // 2. Constant pointer
    printf("\n2. Constant pointer (int *const):\n");
    int *const const_ptr = &value1;
    printf("  *const_ptr = %d\n", *const_ptr);
    printf("  Can modify value: ");
    *const_ptr = 30;
    printf("*const_ptr = %d\n", *const_ptr);
    printf("  Cannot reassign pointer: const_ptr = &value2; // ERROR\n");
    
    // 3. Constant pointer to constant
    printf("\n3. Constant pointer to constant (const int *const):\n");
    const int *const const_ptr_to_const = &value1;
    printf("  *const_ptr_to_const = %d\n", *const_ptr_to_const);
    printf("  Cannot modify value: *const_ptr_to_const = 40; // ERROR\n");
    printf("  Cannot reassign pointer: const_ptr_to_const = &value2; // ERROR\n");
    
    // 4. Regular pointer for comparison
    printf("\n4. Regular pointer (int *):\n");
    int *regular_ptr = &value1;
    printf("  *regular_ptr = %d\n", *regular_ptr);
    printf("  Can modify value: ");
    *regular_ptr = 50;
    printf("*regular_ptr = %d\n", *regular_ptr);
    printf("  Can reassign pointer: ");
    regular_ptr = &value2;
    printf("*regular_ptr = %d\n", *regular_ptr);
    
    // Const with arrays
    printf("\nConst with arrays:\n");
    int numbers[] = {1, 2, 3, 4, 5};
    const int *const_array_ptr = numbers;
    
    printf("  Array: [");
    for (int i = 0; i < 5; i++) {
        printf("%d", const_array_ptr[i]);
        if (i < 4) printf(", ");
    }
    printf("]\n");
    printf("  Cannot modify elements through const pointer\n");
    
    // Function parameter examples
    printf("\nFunction parameter examples:\n");
    int test_value = 100;
    printf("  Original value: %d\n", test_value);
    
    modify_through_pointer(&test_value);
    printf("  After modify_through_pointer: %d\n", test_value);
    
    try_modify_const(&test_value);
    printf("  try_modify_const cannot change the value\n");
    printf("\n");
}

void demonstrate_complex_declarations(void) {
    printf("5. COMPLEX POINTER DECLARATIONS\n");
    printf("----------------------------------------\n");
    
    // Various complex pointer types
    printf("Complex pointer declaration examples:\n");
    
    // Array of pointers to int
    int a = 1, b = 2, c = 3;
    int *ptr_array[3] = {&a, &b, &c};
    printf("  int *ptr_array[3]: Array of 3 pointers to int\n");
    printf("    Values: [%d, %d, %d]\n", *ptr_array[0], *ptr_array[1], *ptr_array[2]);
    
    // Pointer to array of int
    int arr[3] = {10, 20, 30};
    int (*array_ptr)[3] = &arr;
    printf("  int (*array_ptr)[3]: Pointer to array of 3 ints\n");
    printf("    Values: [%d, %d, %d]\n", (*array_ptr)[0], (*array_ptr)[1], (*array_ptr)[2]);
    
    // Array of pointers to arrays
    int row1[2] = {1, 2};
    int row2[2] = {3, 4};
    int (*row_ptrs[2])[2] = {&row1, &row2};
    printf("  int (*row_ptrs[2])[2]: Array of 2 pointers to arrays of 2 ints\n");
    printf("    Matrix:\n");
    for (int i = 0; i < 2; i++) {
        printf("      [%d, %d]\n", (*row_ptrs[i])[0], (*row_ptrs[i])[1]);
    }
    
    // Pointer to array of pointers
    int x = 100, y = 200, z = 300;
    int *values[3] = {&x, &y, &z};
    int *(*ptr_to_ptr_array)[3] = &values;
    printf("  int *(*ptr_to_ptr_array)[3]: Pointer to array of 3 pointers to int\n");
    printf("    Values: [%d, %d, %d]\n", 
           *(*ptr_to_ptr_array)[0], *(*ptr_to_ptr_array)[1], *(*ptr_to_ptr_array)[2]);
    
    // Using typedef for clarity
    printf("\nUsing typedef for clarity:\n");
    typedef int* IntPtr;
    typedef IntPtr IntPtrArray[3];
    typedef IntPtrArray* PtrToIntPtrArray;
    
    IntPtrArray simple_array = {&a, &b, &c};
    PtrToIntPtrArray simple_ptr = &simple_array;
    
    printf("  typedef makes complex types readable\n");
    printf("  Values through typedef'd pointer: [%d, %d, %d]\n", 
           *(*simple_ptr)[0], *(*simple_ptr)[1], *(*simple_ptr)[2]);
    printf("\n");
}

void demonstrate_practical_applications(void) {
    printf("6. PRACTICAL APPLICATIONS\n");
    printf("----------------------------------------\n");
    
    // Application 1: Dynamic 2D array
    printf("Application 1: Dynamic 2D array\n");
    int rows = 3, cols = 4;
    
    // Allocate array of pointers
    int **dynamic_matrix = malloc(rows * sizeof(int*));
    
    // Allocate each row
    for (int i = 0; i < rows; i++) {
        dynamic_matrix[i] = malloc(cols * sizeof(int));
        // Initialize with values
        for (int j = 0; j < cols; j++) {
            dynamic_matrix[i][j] = i * cols + j + 1;
        }
    }
    
    printf("  Dynamic matrix (%dx%d):\n", rows, cols);
    print_matrix(dynamic_matrix, rows, cols);
    
    // Free memory
    for (int i = 0; i < rows; i++) {
        free(dynamic_matrix[i]);
    }
    free(dynamic_matrix);
    
    // Application 2: Command line argument processing
    printf("\nApplication 2: Command line argument simulation\n");
    char *argv[] = {"program", "-v", "--input", "file.txt", "--debug"};
    int argc = sizeof(argv) / sizeof(argv[0]);
    char **arg_ptr = argv;
    
    printf("  Processing arguments:\n");
    for (int i = 0; i < argc; i++) {
        printf("    argv[%d] = \"%s\"\n", i, *(arg_ptr + i));
    }
    
    // Application 3: String array manipulation
    printf("\nApplication 3: String array manipulation\n");
    char *languages[] = {"C", "Python", "Java", "JavaScript", "Go"};
    int lang_count = sizeof(languages) / sizeof(languages[0]);
    char **lang_ptr = languages;
    
    printf("  Programming languages:\n");
    for (int i = 0; i < lang_count; i++) {
        printf("    %d. %s (length: %zu)\n", i + 1, lang_ptr[i], strlen(lang_ptr[i]));
    }
    
    // Find longest language name
    char **longest = &languages[0];
    for (int i = 1; i < lang_count; i++) {
        if (strlen(languages[i]) > strlen(*longest)) {
            longest = &languages[i];
        }
    }
    printf("  Longest language name: \"%s\"\n", *longest);
    
    // Application 4: Function pointer arrays with const
    printf("\nApplication 4: Function pointer table\n");
    int (*operations[])(int, int) = {
        [0] = NULL,  // Placeholder
        [1] = NULL,  // Placeholder  
        [2] = NULL,  // Placeholder
        [3] = NULL   // Placeholder
    };
    
    printf("  Function pointer table structure created\n");
    printf("  (Would contain actual function pointers in real application)\n");
    
    // Application 5: Multi-level configuration
    printf("\nApplication 5: Configuration hierarchy\n");
    
    typedef struct {
        char *name;
        int value;
    } Config;
    
    Config global_config = {"global", 100};
    Config user_config = {"user", 200};
    Config local_config = {"local", 300};
    
    Config *config_levels[] = {&global_config, &user_config, &local_config};
    Config **config_ptr = config_levels;
    
    printf("  Configuration hierarchy:\n");
    for (int i = 0; i < 3; i++) {
        printf("    Level %d: %s = %d\n", i, config_ptr[i]->name, config_ptr[i]->value);
    }
    
    // Find highest priority config (last in array)
    Config **highest_priority = &config_levels[2];
    printf("  Highest priority config: %s = %d\n", 
           (*highest_priority)->name, (*highest_priority)->value);
}

// Helper function implementations
void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("    [");
        for (int j = 0; j < cols; j++) {
            printf("%2d", matrix[i][j]);
            if (j < cols - 1) printf(", ");
        }
        printf("]\n");
    }
}

void modify_through_pointer(int *ptr) {
    if (ptr != NULL) {
        *ptr = 999;  // Can modify value
    }
}

void try_modify_const(const int *ptr) {
    if (ptr != NULL) {
        // *ptr = 888;  // ERROR: Cannot modify const value
        printf("    Function received const pointer - cannot modify value\n");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void demonstrate_array_pointer_equivalence(void);
void demonstrate_pointer_indexing(void);
void demonstrate_array_vs_pointer(void);
void demonstrate_multidimensional_arrays(void);
void demonstrate_array_of_pointers(void);
void demonstrate_pointer_to_array(void);
void demonstrate_string_arrays(void);
void demonstrate_practical_applications(void);

int main() {
    printf("=== Pointers and Arrays Demo ===\n\n");
    
    demonstrate_array_pointer_equivalence();
    demonstrate_pointer_indexing();
    demonstrate_array_vs_pointer();
    demonstrate_multidimensional_arrays();
    demonstrate_array_of_pointers();
    demonstrate_pointer_to_array();
    demonstrate_string_arrays();
    demonstrate_practical_applications();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_array_pointer_equivalence(void) {
    printf("1. ARRAY NAME AS POINTER\n");
    printf("----------------------------------------\n");
    
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;  // Array name is pointer to first element
    
    printf("Array: [%d, %d, %d, %d, %d]\n", 
           numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
    
    printf("\nArray name equivalences:\n");
    printf("  numbers == &numbers[0]: %s\n", (numbers == &numbers[0]) ? "true" : "false");
    printf("  ptr == numbers: %s\n", (ptr == numbers) ? "true" : "false");
    printf("  ptr == &numbers[0]: %s\n", (ptr == &numbers[0]) ? "true" : "false");
    
    printf("\nAddress comparisons:\n");
    printf("  numbers address: %p\n", (void*)numbers);
    printf("  &numbers[0] address: %p\n", (void*)&numbers[0]);
    printf("  ptr address: %p\n", (void*)ptr);
    
    printf("\nValue access:\n");
    printf("  *numbers = %d\n", *numbers);
    printf("  *ptr = %d\n", *ptr);
    printf("  numbers[0] = %d\n", numbers[0]);
    printf("  ptr[0] = %d\n", ptr[0]);
    printf("\n");
}

void demonstrate_pointer_indexing(void) {
    printf("2. POINTER INDEXING\n");
    printf("----------------------------------------\n");
    
    int data[] = {100, 200, 300, 400, 500};
    int *ptr = data;
    
    printf("Array: [%d, %d, %d, %d, %d]\n", 
           data[0], data[1], data[2], data[3], data[4]);
    
    printf("\nEquivalent ways to access elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("  Element %d:\n", i);
        printf("    data[%d] = %d\n", i, data[i]);
        printf("    *(data+%d) = %d\n", i, *(data+i));
        printf("    ptr[%d] = %d\n", i, ptr[i]);
        printf("    *(ptr+%d) = %d\n", i, *(ptr+i));
        printf("\n");
    }
    
    printf("All methods produce identical results!\n\n");
}

void demonstrate_array_vs_pointer(void) {
    printf("3. ARRAY VS POINTER DIFFERENCES\n");
    printf("----------------------------------------\n");
    
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    
    printf("Key differences:\n");
    printf("  sizeof(arr) = %zu bytes (entire array)\n", sizeof(arr));
    printf("  sizeof(ptr) = %zu bytes (pointer size)\n", sizeof(ptr));
    printf("  Array elements: %zu\n", sizeof(arr) / sizeof(arr[0]));
    
    printf("\nAssignment capabilities:\n");
    printf("  ptr = arr;        // OK - pointer can be reassigned\n");
    printf("  ptr = arr + 2;    // OK - pointer can point elsewhere\n");
    printf("  // arr = ptr;     // ERROR - array name cannot be reassigned\n");
    
    // Demonstrate pointer reassignment
    printf("\nPointer reassignment:\n");
    printf("  Initially ptr points to: %d\n", *ptr);
    ptr = arr + 2;
    printf("  After ptr = arr + 2: %d\n", *ptr);
    ptr = &arr[4];
    printf("  After ptr = &arr[4]: %d\n", *ptr);
    
    printf("\nArray name is constant, pointer is variable:\n");
    printf("  arr always points to: %p\n", (void*)arr);
    printf("  ptr can point to: %p (currently)\n", (void*)ptr);
    printf("\n");
}

void demonstrate_multidimensional_arrays(void) {
    printf("4. MULTIDIMENSIONAL ARRAYS\n");
    printf("----------------------------------------\n");
    
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("Matrix (3x4):\n");
    for (int i = 0; i < 3; i++) {
        printf("  [");
        for (int j = 0; j < 4; j++) {
            printf("%2d", matrix[i][j]);
            if (j < 3) printf(", ");
        }
        printf("]\n");
    }
    
    // Treat as 1D array using pointer
    int *ptr = &matrix[0][0];
    printf("\nLinear access using pointer:\n");
    printf("  Elements: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    
    printf("\nAccessing matrix[1][2] different ways:\n");
    printf("  matrix[1][2] = %d\n", matrix[1][2]);
    printf("  *(*(matrix+1)+2) = %d\n", *(*(matrix+1)+2));
    printf("  *(&matrix[0][0] + 1*4 + 2) = %d\n", *(&matrix[0][0] + 1*4 + 2));
    printf("  ptr[1*4 + 2] = %d\n", ptr[1*4 + 2]);
    
    printf("\nRow pointers:\n");
    for (int i = 0; i < 3; i++) {
        printf("  Row %d starts at: %p, first element: %d\n", 
               i, (void*)matrix[i], matrix[i][0]);
    }
    printf("\n");
}

void demonstrate_array_of_pointers(void) {
    printf("5. ARRAY OF POINTERS\n");
    printf("----------------------------------------\n");
    
    int a = 10, b = 20, c = 30, d = 40;
    int *ptr_array[4] = {&a, &b, &c, &d};
    
    printf("Individual variables: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    printf("Array of pointers to these variables:\n");
    
    for (int i = 0; i < 4; i++) {
        printf("  ptr_array[%d] points to %d at address %p\n", 
               i, *ptr_array[i], (void*)ptr_array[i]);
    }
    
    printf("\nModifying values through pointer array:\n");
    *ptr_array[0] = 100;  // Change a
    *ptr_array[2] = 300;  // Change c
    
    printf("  After modification: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    
    // Array of pointers to different arrays
    printf("\nArray of pointers to different arrays:\n");
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int arr3[] = {7, 8, 9};
    
    int *arrays[3] = {arr1, arr2, arr3};
    
    for (int i = 0; i < 3; i++) {
        printf("  Array %d: [", i);
        for (int j = 0; j < 3; j++) {
            printf("%d", arrays[i][j]);
            if (j < 2) printf(", ");
        }
        printf("]\n");
    }
    printf("\n");
}

void demonstrate_pointer_to_array(void) {
    printf("6. POINTER TO ARRAY\n");
    printf("----------------------------------------\n");
    
    int arr[5] = {10, 20, 30, 40, 50};
    int (*ptr_to_array)[5] = &arr;  // Pointer to entire array
    
    printf("Array: [%d, %d, %d, %d, %d]\n", 
           arr[0], arr[1], arr[2], arr[3], arr[4]);
    
    printf("\nPointer to array:\n");
    printf("  ptr_to_array points to entire array at: %p\n", (void*)ptr_to_array);
    printf("  Array starts at: %p\n", (void*)arr);
    printf("  Same address: %s\n", (ptr_to_array == &arr) ? "true" : "false");
    
    printf("\nAccessing elements through pointer to array:\n");
    for (int i = 0; i < 5; i++) {
        printf("  (*ptr_to_array)[%d] = %d\n", i, (*ptr_to_array)[i]);
    }
    
    // Array of arrays using pointer to array
    printf("\nArray of arrays:\n");
    int matrix[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int (*row_ptr)[4] = matrix;  // Points to first row
    
    for (int i = 0; i < 3; i++) {
        printf("  Row %d: [", i);
        for (int j = 0; j < 4; j++) {
            printf("%d", (*(row_ptr + i))[j]);
            if (j < 3) printf(", ");
        }
        printf("]\n");
    }
    printf("\n");
}

void demonstrate_string_arrays(void) {
    printf("7. STRING ARRAYS\n");
    printf("----------------------------------------\n");
    
    // Array of string literals (array of char pointers)
    char *fruits[] = {"apple", "banana", "orange", "grape", "kiwi"};
    int num_fruits = sizeof(fruits) / sizeof(fruits[0]);
    
    printf("Array of string pointers:\n");
    for (int i = 0; i < num_fruits; i++) {
        printf("  fruits[%d] = \"%s\" at address %p\n", 
               i, fruits[i], (void*)fruits[i]);
    }
    
    printf("\nString lengths:\n");
    for (int i = 0; i < num_fruits; i++) {
        printf("  \"%s\" has %zu characters\n", fruits[i], strlen(fruits[i]));
    }
    
    // 2D character array vs array of pointers
    printf("\n2D character array vs array of pointers:\n");
    char names1[][10] = {"Alice", "Bob", "Charlie"};  // 2D array
    char *names2[] = {"Alice", "Bob", "Charlie"};     // Array of pointers
    
    printf("  2D array memory usage: %zu bytes\n", sizeof(names1));
    printf("  Array of pointers: %zu bytes\n", sizeof(names2));
    
    printf("  2D array (fixed width):\n");
    for (int i = 0; i < 3; i++) {
        printf("    names1[%d] = \"%-9s\" at %p\n", 
               i, names1[i], (void*)names1[i]);
    }
    
    printf("  Array of pointers (variable width):\n");
    for (int i = 0; i < 3; i++) {
        printf("    names2[%d] = \"%-9s\" at %p\n", 
               i, names2[i], (void*)names2[i]);
    }
    printf("\n");
}

void demonstrate_practical_applications(void) {
    printf("8. PRACTICAL APPLICATIONS\n");
    printf("----------------------------------------\n");
    
    // Application 1: Generic array processing
    printf("Application 1: Generic array processing\n");
    int data[] = {5, 2, 8, 1, 9, 3};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("  Original array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", data[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    // Find min and max using pointers
    int *min_ptr = data, *max_ptr = data;
    for (int *ptr = data + 1; ptr < data + size; ptr++) {
        if (*ptr < *min_ptr) min_ptr = ptr;
        if (*ptr > *max_ptr) max_ptr = ptr;
    }
    
    printf("  Minimum: %d at index %ld\n", *min_ptr, min_ptr - data);
    printf("  Maximum: %d at index %ld\n", *max_ptr, max_ptr - data);
    
    // Application 2: Command line argument simulation
    printf("\nApplication 2: Command line arguments simulation\n");
    char *argv[] = {"program", "-v", "--input", "file.txt", "--output", "result.txt"};
    int argc = sizeof(argv) / sizeof(argv[0]);
    
    printf("  argc = %d\n", argc);
    printf("  argv contents:\n");
    for (int i = 0; i < argc; i++) {
        printf("    argv[%d] = \"%s\"\n", i, argv[i]);
    }
    
    // Application 3: Matrix operations using pointers
    printf("\nApplication 3: Matrix operations\n");
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    printf("  Original matrix:\n");
    for (int i = 0; i < 3; i++) {
        printf("    [");
        for (int j = 0; j < 3; j++) {
            printf("%d", matrix[i][j]);
            if (j < 2) printf(", ");
        }
        printf("]\n");
    }
    
    // Calculate diagonal sum using pointers
    int *ptr = &matrix[0][0];
    int diagonal_sum = 0;
    for (int i = 0; i < 3; i++) {
        diagonal_sum += *(ptr + i * 3 + i);  // matrix[i][i]
    }
    printf("  Diagonal sum: %d\n", diagonal_sum);
    
    // Application 4: Dynamic string array
    printf("\nApplication 4: Dynamic string processing\n");
    char *words[] = {"programming", "is", "fun", "and", "challenging"};
    int word_count = sizeof(words) / sizeof(words[0]);
    
    printf("  Words: ");
    for (int i = 0; i < word_count; i++) {
        printf("\"%s\"", words[i]);
        if (i < word_count - 1) printf(", ");
    }
    printf("\n");
    
    // Find longest word
    char *longest = words[0];
    for (int i = 1; i < word_count; i++) {
        if (strlen(words[i]) > strlen(longest)) {
            longest = words[i];
        }
    }
    printf("  Longest word: \"%s\" (%zu characters)\n", longest, strlen(longest));
    
    // Count total characters
    size_t total_chars = 0;
    for (int i = 0; i < word_count; i++) {
        total_chars += strlen(words[i]);
    }
    printf("  Total characters: %zu\n", total_chars);
    
    // Application 5: Array bounds checking
    printf("\nApplication 5: Safe array access\n");
    int safe_array[] = {10, 20, 30, 40, 50};
    int array_size = sizeof(safe_array) / sizeof(safe_array[0]);
    int *start = safe_array;
    int *end = safe_array + array_size;
    
    printf("  Array bounds: %p to %p\n", (void*)start, (void*)end);
    printf("  Safe access examples:\n");
    
    int *test_ptr = safe_array + 2;
    if (test_ptr >= start && test_ptr < end) {
        printf("    Accessing index %ld: %d (SAFE)\n", test_ptr - start, *test_ptr);
    }
    
    test_ptr = safe_array + 10;  // Beyond bounds
    if (test_ptr >= start && test_ptr < end) {
        printf("    Accessing index %ld: %d (SAFE)\n", test_ptr - start, *test_ptr);
    } else {
        printf("    Index %ld is out of bounds (UNSAFE)\n", test_ptr - start);
    }
}

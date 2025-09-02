#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

// Function prototypes
void demonstrate_basic_arithmetic(void);
void demonstrate_increment_decrement(void);
void demonstrate_addition_subtraction(void);
void demonstrate_pointer_comparison(void);
void demonstrate_pointer_difference(void);
void demonstrate_different_types(void);
void demonstrate_practical_applications(void);

int main() {
    printf("=== Pointer Arithmetic Demo ===\n\n");
    
    demonstrate_basic_arithmetic();
    demonstrate_increment_decrement();
    demonstrate_addition_subtraction();
    demonstrate_pointer_comparison();
    demonstrate_pointer_difference();
    demonstrate_different_types();
    demonstrate_practical_applications();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_arithmetic(void) {
    printf("1. BASIC POINTER ARITHMETIC CONCEPTS\n");
    printf("----------------------------------------\n");
    
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;  // Points to first element
    
    printf("Array: [%d, %d, %d, %d, %d]\n", 
           numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
    printf("Array starts at address: %p\n", (void*)numbers);
    
    printf("\nPointer arithmetic scale factors:\n");
    printf("  int size: %zu bytes\n", sizeof(int));
    printf("  ptr points to: %d at address %p\n", *ptr, (void*)ptr);
    printf("  ptr + 1 points to: %d at address %p\n", *(ptr + 1), (void*)(ptr + 1));
    printf("  ptr + 2 points to: %d at address %p\n", *(ptr + 2), (void*)(ptr + 2));
    
    printf("\nAddress differences:\n");
    printf("  (ptr + 1) - ptr = %ld bytes\n", (char*)(ptr + 1) - (char*)ptr);
    printf("  (ptr + 2) - (ptr + 1) = %ld bytes\n", (char*)(ptr + 2) - (char*)(ptr + 1));
    printf("  Each increment moves by sizeof(int) = %zu bytes\n\n", sizeof(int));
}

void demonstrate_increment_decrement(void) {
    printf("2. INCREMENT AND DECREMENT OPERATIONS\n");
    printf("----------------------------------------\n");
    
    int data[] = {100, 200, 300, 400, 500};
    int *ptr = &data[2];  // Start at middle element
    
    printf("Array: [%d, %d, %d, %d, %d]\n", 
           data[0], data[1], data[2], data[3], data[4]);
    printf("Starting at index 2: *ptr = %d\n", *ptr);
    
    // Pre-increment
    printf("\nPre-increment (++ptr):\n");
    printf("  Before: *ptr = %d at index %ld\n", *ptr, ptr - data);
    ++ptr;
    printf("  After:  *ptr = %d at index %ld\n", *ptr, ptr - data);
    
    // Post-increment
    printf("\nPost-increment (ptr++):\n");
    printf("  Before: *ptr = %d at index %ld\n", *ptr, ptr - data);
    int old_value = *ptr++;
    printf("  After:  *ptr = %d at index %ld (old value was %d)\n", 
           *ptr, ptr - data, old_value);
    
    // Pre-decrement
    printf("\nPre-decrement (--ptr):\n");
    printf("  Before: *ptr = %d at index %ld\n", *ptr, ptr - data);
    --ptr;
    printf("  After:  *ptr = %d at index %ld\n", *ptr, ptr - data);
    
    // Post-decrement
    printf("\nPost-decrement (ptr--):\n");
    printf("  Before: *ptr = %d at index %ld\n", *ptr, ptr - data);
    old_value = *ptr--;
    printf("  After:  *ptr = %d at index %ld (old value was %d)\n", 
           *ptr, ptr - data, old_value);
    printf("\n");
}

void demonstrate_addition_subtraction(void) {
    printf("3. ADDITION AND SUBTRACTION\n");
    printf("----------------------------------------\n");
    
    int sequence[] = {5, 10, 15, 20, 25, 30, 35, 40};
    int *base = sequence;
    
    printf("Array: [");
    for (int i = 0; i < 8; i++) {
        printf("%d", sequence[i]);
        if (i < 7) printf(", ");
    }
    printf("]\n");
    
    printf("\nPointer + integer operations:\n");
    for (int i = 0; i < 8; i++) {
        printf("  base + %d = %d (at address %p)\n", 
               i, *(base + i), (void*)(base + i));
    }
    
    printf("\nPointer - integer operations:\n");
    int *end = base + 7;  // Point to last element
    printf("  end points to: %d\n", *end);
    for (int i = 0; i < 4; i++) {
        printf("  end - %d = %d (at address %p)\n", 
               i, *(end - i), (void*)(end - i));
    }
    
    printf("\nCompound assignment operators:\n");
    int *ptr = base + 2;  // Start at index 2
    printf("  Initial: *ptr = %d at index %ld\n", *ptr, ptr - base);
    
    ptr += 3;
    printf("  After ptr += 3: *ptr = %d at index %ld\n", *ptr, ptr - base);
    
    ptr -= 2;
    printf("  After ptr -= 2: *ptr = %d at index %ld\n", *ptr, ptr - base);
    printf("\n");
}

void demonstrate_pointer_comparison(void) {
    printf("4. POINTER COMPARISON\n");
    printf("----------------------------------------\n");
    
    int values[] = {11, 22, 33, 44, 55};
    int *p1 = &values[1];  // Points to 22
    int *p2 = &values[3];  // Points to 44
    int *p3 = &values[1];  // Also points to 22
    
    printf("Array: [%d, %d, %d, %d, %d]\n", 
           values[0], values[1], values[2], values[3], values[4]);
    printf("p1 points to: %d (index %ld)\n", *p1, p1 - values);
    printf("p2 points to: %d (index %ld)\n", *p2, p2 - values);
    printf("p3 points to: %d (index %ld)\n", *p3, p3 - values);
    
    printf("\nComparison operations:\n");
    printf("  p1 == p2: %s\n", (p1 == p2) ? "true" : "false");
    printf("  p1 == p3: %s\n", (p1 == p3) ? "true" : "false");
    printf("  p1 != p2: %s\n", (p1 != p2) ? "true" : "false");
    printf("  p1 < p2:  %s\n", (p1 < p2) ? "true" : "false");
    printf("  p1 > p2:  %s\n", (p1 > p2) ? "true" : "false");
    printf("  p2 >= p1: %s\n", (p2 >= p1) ? "true" : "false");
    
    printf("\nOrdering pointers:\n");
    int *ptrs[] = {&values[4], &values[0], &values[2], &values[1], &values[3]};
    printf("  Unsorted pointer values: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptrs[i]);
    }
    printf("\n");
    
    // Simple bubble sort for pointers
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (ptrs[j] > ptrs[j + 1]) {
                int *temp = ptrs[j];
                ptrs[j] = ptrs[j + 1];
                ptrs[j + 1] = temp;
            }
        }
    }
    
    printf("  Sorted by address: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptrs[i]);
    }
    printf("\n\n");
}

void demonstrate_pointer_difference(void) {
    printf("5. POINTER DIFFERENCE\n");
    printf("----------------------------------------\n");
    
    int array[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
    int *start = &array[2];   // Points to 9
    int *middle = &array[5];  // Points to 36
    int *end = &array[8];     // Points to 81
    
    printf("Array: [");
    for (int i = 0; i < 10; i++) {
        printf("%d", array[i]);
        if (i < 9) printf(", ");
    }
    printf("]\n");
    
    printf("Pointer positions:\n");
    printf("  start points to: %d (index %ld)\n", *start, start - array);
    printf("  middle points to: %d (index %ld)\n", *middle, middle - array);
    printf("  end points to: %d (index %ld)\n", *end, end - array);
    
    printf("\nPointer differences:\n");
    ptrdiff_t diff1 = middle - start;
    ptrdiff_t diff2 = end - middle;
    ptrdiff_t diff3 = end - start;
    
    printf("  middle - start = %ld elements\n", diff1);
    printf("  end - middle = %ld elements\n", diff2);
    printf("  end - start = %ld elements\n", diff3);
    
    printf("\nByte differences:\n");
    printf("  (middle - start) * sizeof(int) = %ld bytes\n", diff1 * sizeof(int));
    printf("  (end - middle) * sizeof(int) = %ld bytes\n", diff2 * sizeof(int));
    printf("  (end - start) * sizeof(int) = %ld bytes\n", diff3 * sizeof(int));
    
    printf("\nUsing pointer difference for range:\n");
    printf("  Elements from start to middle: ");
    for (int *ptr = start; ptr < middle; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n  Count: %ld elements\n\n", middle - start);
}

void demonstrate_different_types(void) {
    printf("6. ARITHMETIC WITH DIFFERENT TYPES\n");
    printf("----------------------------------------\n");
    
    // Different data types
    char chars[] = {'A', 'B', 'C', 'D', 'E'};
    int ints[] = {10, 20, 30, 40, 50};
    double doubles[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    
    char *char_ptr = chars;
    int *int_ptr = ints;
    double *double_ptr = doubles;
    
    printf("Type sizes:\n");
    printf("  sizeof(char) = %zu bytes\n", sizeof(char));
    printf("  sizeof(int) = %zu bytes\n", sizeof(int));
    printf("  sizeof(double) = %zu bytes\n", sizeof(double));
    
    printf("\nPointer arithmetic scaling:\n");
    printf("  char_ptr: %p -> %p (diff: %ld bytes)\n", 
           (void*)char_ptr, (void*)(char_ptr + 1), 
           (char*)(char_ptr + 1) - (char*)char_ptr);
    
    printf("  int_ptr: %p -> %p (diff: %ld bytes)\n", 
           (void*)int_ptr, (void*)(int_ptr + 1), 
           (char*)(int_ptr + 1) - (char*)int_ptr);
    
    printf("  double_ptr: %p -> %p (diff: %ld bytes)\n", 
           (void*)double_ptr, (void*)(double_ptr + 1), 
           (char*)(double_ptr + 1) - (char*)double_ptr);
    
    printf("\nTraversing different types:\n");
    printf("  chars: ");
    for (int i = 0; i < 5; i++) {
        printf("%c ", *(char_ptr + i));
    }
    printf("\n");
    
    printf("  ints: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(int_ptr + i));
    }
    printf("\n");
    
    printf("  doubles: ");
    for (int i = 0; i < 5; i++) {
        printf("%.1f ", *(double_ptr + i));
    }
    printf("\n\n");
}

void demonstrate_practical_applications(void) {
    printf("7. PRACTICAL APPLICATIONS\n");
    printf("----------------------------------------\n");
    
    // Application 1: Array sum using pointer arithmetic
    printf("Application 1: Array sum\n");
    int numbers[] = {5, 10, 15, 20, 25, 30};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int sum = 0;
    
    printf("  Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", numbers[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    for (int *ptr = numbers; ptr < numbers + size; ptr++) {
        sum += *ptr;
    }
    printf("  Sum using pointer arithmetic: %d\n", sum);
    
    // Application 2: String length calculation
    printf("\nApplication 2: String length\n");
    char *text = "Hello, World!";
    char *start = text;
    char *end = text;
    
    while (*end != '\0') {
        end++;
    }
    
    printf("  String: \"%s\"\n", text);
    printf("  Length using pointer arithmetic: %ld\n", end - start);
    printf("  Length using strlen(): %zu\n", strlen(text));
    
    // Application 3: Finding element in array
    printf("\nApplication 3: Finding element\n");
    int data[] = {3, 7, 11, 15, 19, 23, 27, 31};
    int target = 19;
    int *found = NULL;
    
    printf("  Array: [");
    for (int i = 0; i < 8; i++) {
        printf("%d", data[i]);
        if (i < 7) printf(", ");
    }
    printf("]\n");
    printf("  Searching for: %d\n", target);
    
    for (int *ptr = data; ptr < data + 8; ptr++) {
        if (*ptr == target) {
            found = ptr;
            break;
        }
    }
    
    if (found != NULL) {
        printf("  Found %d at index %ld\n", target, found - data);
    } else {
        printf("  %d not found\n", target);
    }
    
    // Application 4: Reversing array using pointers
    printf("\nApplication 4: Array reversal\n");
    int original[] = {1, 2, 3, 4, 5, 6};
    int reversed[6];
    int len = 6;
    
    printf("  Original: [");
    for (int i = 0; i < len; i++) {
        printf("%d", original[i]);
        if (i < len - 1) printf(", ");
    }
    printf("]\n");
    
    // Copy in reverse using pointer arithmetic
    int *src = original + len - 1;  // Point to last element
    int *dst = reversed;
    
    for (int i = 0; i < len; i++) {
        *dst++ = *src--;
    }
    
    printf("  Reversed: [");
    for (int i = 0; i < len; i++) {
        printf("%d", reversed[i]);
        if (i < len - 1) printf(", ");
    }
    printf("]\n");
    
    // Application 5: Matrix traversal
    printf("\nApplication 5: Matrix traversal\n");
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("  Matrix:\n");
    for (int i = 0; i < 3; i++) {
        printf("    [");
        for (int j = 0; j < 4; j++) {
            printf("%2d", matrix[i][j]);
            if (j < 3) printf(", ");
        }
        printf("]\n");
    }
    
    printf("  Linear traversal using pointer arithmetic: ");
    int *ptr = &matrix[0][0];
    for (int i = 0; i < 12; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

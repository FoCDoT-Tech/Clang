#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes for demonstration
int factorial(int n);
int find_in_array(int arr[], int size, int target);
void process_file(const char* filename);
int validate_input(int value);

int main() {
    printf("=== Jump Statements Demo ===\n\n");
    
    // 1. BREAK STATEMENT
    printf("1. BREAK STATEMENT\n");
    printf("Finding first even number in range 1-10:\n");
    
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            printf("First even number found: %d\n", i);
            break;  // Exit the loop immediately
        }
        printf("Checking %d (odd)\n", i);
    }
    
    // Break in nested loops (only breaks innermost)
    printf("\nBreak in nested loops:\n");
    for (int i = 1; i <= 3; i++) {
        printf("Outer loop: i = %d\n", i);
        for (int j = 1; j <= 5; j++) {
            if (j == 3) {
                printf("  Breaking inner loop at j = %d\n", j);
                break;  // Only breaks inner loop
            }
            printf("  Inner loop: j = %d\n", j);
        }
    }
    
    // 2. CONTINUE STATEMENT
    printf("\n2. CONTINUE STATEMENT\n");
    printf("Printing only odd numbers from 1-10:\n");
    
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // Skip even numbers
        }
        printf("%d ", i);
    }
    printf("\n");
    
    // Continue in while loop
    printf("\nSkipping multiples of 3 in range 1-15:\n");
    int num = 0;
    while (num < 15) {
        num++;
        if (num % 3 == 0) {
            continue;  // Skip multiples of 3
        }
        printf("%d ", num);
    }
    printf("\n");
    
    // 3. SWITCH WITH BREAK
    printf("\n3. SWITCH WITH BREAK\n");
    printf("Grade evaluation:\n");
    
    char grades[] = {'A', 'B', 'C', 'D', 'F'};
    for (int i = 0; i < 5; i++) {
        char grade = grades[i];
        printf("Grade %c: ", grade);
        
        switch (grade) {
            case 'A':
                printf("Excellent (90-100)");
                break;  // Prevents fall-through
            case 'B':
                printf("Good (80-89)");
                break;
            case 'C':
                printf("Average (70-79)");
                break;
            case 'D':
                printf("Below Average (60-69)");
                break;
            case 'F':
                printf("Fail (0-59)");
                break;
            default:
                printf("Invalid grade");
                break;
        }
        printf("\n");
    }
    
    // 4. RETURN STATEMENT
    printf("\n4. RETURN STATEMENT\n");
    
    // Testing factorial function with early returns
    int test_values[] = {5, -3, 0, 7};
    for (int i = 0; i < 4; i++) {
        int result = factorial(test_values[i]);
        if (result == -1) {
            printf("Factorial of %d: Invalid (negative number)\n", test_values[i]);
        } else {
            printf("Factorial of %d: %d\n", test_values[i], result);
        }
    }
    
    // 5. ARRAY SEARCH WITH RETURN
    printf("\n5. ARRAY SEARCH WITH RETURN\n");
    int numbers[] = {10, 25, 30, 45, 50, 65, 70};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    int search_targets[] = {30, 99, 10};
    for (int i = 0; i < 3; i++) {
        int index = find_in_array(numbers, size, search_targets[i]);
        if (index != -1) {
            printf("Found %d at index %d\n", search_targets[i], index);
        } else {
            printf("%d not found in array\n", search_targets[i]);
        }
    }
    
    // 6. GOTO STATEMENT (Error Handling Example)
    printf("\n6. GOTO STATEMENT (Error Handling)\n");
    printf("Processing files with error handling:\n");
    
    const char* files[] = {"data.txt", "config.txt", "log.txt"};
    for (int i = 0; i < 3; i++) {
        process_file(files[i]);
    }
    
    // 7. GOTO FOR BREAKING NESTED LOOPS
    printf("\n7. GOTO FOR NESTED LOOP BREAK\n");
    printf("Finding first pair (i,j) where i*j > 20:\n");
    
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i * j > 20) {
                printf("Found pair: (%d, %d) = %d\n", i, j, i * j);
                goto found_pair;  // Break out of both loops
            }
        }
    }
    
    found_pair:
    printf("Search completed.\n");
    
    // 8. PRACTICAL LOOP CONTROL PATTERNS
    printf("\n8. PRACTICAL LOOP CONTROL PATTERNS\n");
    
    // Menu system with break
    printf("Simple menu simulation:\n");
    int choice = 0;
    int menu_items[] = {1, 2, 3, 0};  // Simulate user choices
    
    for (int i = 0; i < 4; i++) {
        choice = menu_items[i];
        printf("User selected: %d - ", choice);
        
        switch (choice) {
            case 1:
                printf("Option 1 selected\n");
                break;
            case 2:
                printf("Option 2 selected\n");
                break;
            case 3:
                printf("Option 3 selected\n");
                break;
            case 0:
                printf("Exit selected\n");
                goto menu_exit;  // Exit menu loop
            default:
                printf("Invalid option\n");
                break;
        }
    }
    
    menu_exit:
    printf("Menu system exited.\n");
    
    // 9. INPUT VALIDATION WITH CONTINUE
    printf("\n9. INPUT VALIDATION PATTERN\n");
    printf("Validating a series of inputs:\n");
    
    int inputs[] = {15, -5, 25, 101, 50};  // Simulate user inputs
    int valid_count = 0;
    
    for (int i = 0; i < 5; i++) {
        int input = inputs[i];
        printf("Processing input: %d - ", input);
        
        if (!validate_input(input)) {
            printf("Invalid, skipping\n");
            continue;  // Skip invalid inputs
        }
        
        printf("Valid, processing\n");
        valid_count++;
    }
    
    printf("Processed %d valid inputs out of 5\n", valid_count);
    
    printf("\n=== Demo Complete ===\n");
    return 0;
}

// Function with early return for error checking
int factorial(int n) {
    if (n < 0) {
        return -1;  // Early return for invalid input
    }
    
    if (n == 0 || n == 1) {
        return 1;   // Early return for base cases
    }
    
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    
    return result;  // Normal return
}

// Function with early return in loop
int find_in_array(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Early return when found
        }
    }
    return -1;  // Return -1 if not found
}

// Function demonstrating goto for error handling
void process_file(const char* filename) {
    printf("Processing file: %s\n", filename);
    
    // Simulate file operations with potential errors
    if (strcmp(filename, "data.txt") == 0) {
        printf("  Opening file...\n");
        // Simulate error
        printf("  Error: File not found\n");
        goto cleanup;  // Jump to cleanup code
    }
    
    if (strcmp(filename, "config.txt") == 0) {
        printf("  Opening file...\n");
        printf("  Reading configuration...\n");
        // Simulate another error
        printf("  Error: Invalid format\n");
        goto cleanup;  // Jump to cleanup code
    }
    
    // Normal processing
    printf("  File processed successfully\n");
    return;  // Normal exit
    
    cleanup:
    printf("  Cleaning up resources\n");
    printf("  Error logged\n");
    return;  // Exit after cleanup
}

// Input validation function
int validate_input(int value) {
    // Valid range: 0-100
    if (value < 0 || value > 100) {
        return 0;  // Invalid
    }
    return 1;  // Valid
}

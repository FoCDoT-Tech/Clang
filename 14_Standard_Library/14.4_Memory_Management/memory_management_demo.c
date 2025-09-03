#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void demonstrate_dynamic_memory(void);
void demonstrate_string_conversion(void);
void demonstrate_random_numbers(void);
void demonstrate_utility_functions(void);
void demonstrate_sorting_searching(void);
void demonstrate_system_functions(void);

// Helper functions for sorting/searching
int compare_ints(const void *a, const void *b);
int compare_strings(const void *a, const void *b);

int main(void) {
    printf("=== Memory Management Demo ===\n\n");
    
    demonstrate_dynamic_memory();
    demonstrate_string_conversion();
    demonstrate_random_numbers();
    demonstrate_utility_functions();
    demonstrate_sorting_searching();
    demonstrate_system_functions();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_dynamic_memory(void) {
    printf("1. DYNAMIC MEMORY ALLOCATION\n");
    printf("----------------------------------------\n");
    
    // malloc - allocate uninitialized memory
    int *numbers = (int*)malloc(5 * sizeof(int));
    if (numbers != NULL) {
        printf("malloc: Allocated memory for 5 integers\n");
        
        // Initialize and display
        for (int i = 0; i < 5; i++) {
            numbers[i] = (i + 1) * 10;
        }
        
        printf("Values: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
        
        free(numbers);
        printf("Memory freed with free()\n");
    }
    
    // calloc - allocate zero-initialized memory
    double *values = (double*)calloc(4, sizeof(double));
    if (values != NULL) {
        printf("\ncalloc: Allocated zero-initialized memory for 4 doubles\n");
        printf("Initial values: ");
        for (int i = 0; i < 4; i++) {
            printf("%.1f ", values[i]);
        }
        printf("\n");
        
        // Set some values
        values[0] = 1.1;
        values[1] = 2.2;
        values[2] = 3.3;
        values[3] = 4.4;
        
        printf("After assignment: ");
        for (int i = 0; i < 4; i++) {
            printf("%.1f ", values[i]);
        }
        printf("\n");
        
        // realloc - resize memory block
        values = (double*)realloc(values, 6 * sizeof(double));
        if (values != NULL) {
            printf("realloc: Resized to 6 doubles\n");
            
            // Initialize new elements
            values[4] = 5.5;
            values[5] = 6.6;
            
            printf("After realloc: ");
            for (int i = 0; i < 6; i++) {
                printf("%.1f ", values[i]);
            }
            printf("\n");
        }
        
        free(values);
        printf("Memory freed\n");
    }
    
    // Dynamic string allocation
    char *dynamic_string = (char*)malloc(50 * sizeof(char));
    if (dynamic_string != NULL) {
        strcpy(dynamic_string, "Dynamic string allocation");
        printf("\nDynamic string: \"%s\"\n", dynamic_string);
        
        // Resize for longer string
        dynamic_string = (char*)realloc(dynamic_string, 100 * sizeof(char));
        if (dynamic_string != NULL) {
            strcat(dynamic_string, " - resized!");
            printf("After resize: \"%s\"\n", dynamic_string);
        }
        
        free(dynamic_string);
    }
    
    printf("\n");
}

void demonstrate_string_conversion(void) {
    printf("2. STRING TO NUMBER CONVERSION\n");
    printf("----------------------------------------\n");
    
    // Basic conversion functions
    const char *int_str = "12345";
    const char *float_str = "3.14159";
    const char *mixed_str = "42abc";
    const char *negative_str = "-789";
    
    printf("String conversions:\n");
    printf("atoi(\"%s\") = %d\n", int_str, atoi(int_str));
    printf("atol(\"%s\") = %ld\n", int_str, atol(int_str));
    printf("atof(\"%s\") = %f\n", float_str, atof(float_str));
    printf("atoi(\"%s\") = %d (stops at non-digit)\n", mixed_str, atoi(mixed_str));
    printf("atoi(\"%s\") = %d\n", negative_str, atoi(negative_str));
    
    // Advanced conversion with error checking
    printf("\nAdvanced conversions with error checking:\n");
    
    const char *test_strings[] = {
        "123",
        "456.789",
        "0xFF",     // Hex
        "777",      // Octal
        "invalid",
        "123abc",
        ""
    };
    
    for (int i = 0; i < 7; i++) {
        char *endptr;
        const char *str = test_strings[i];
        
        // strtol - string to long with error checking
        long long_val = strtol(str, &endptr, 10);  // Base 10
        printf("strtol(\"%s\", base 10): ", str);
        if (*endptr == '\0' && endptr != str) {
            printf("%ld (valid)\n", long_val);
        } else {
            printf("invalid (stopped at '%s')\n", endptr);
        }
        
        // strtod - string to double with error checking
        double double_val = strtod(str, &endptr);
        printf("strtod(\"%s\"): ", str);
        if (*endptr == '\0' && endptr != str) {
            printf("%f (valid)\n", double_val);
        } else {
            printf("invalid (stopped at '%s')\n", endptr);
        }
    }
    
    // Different bases
    printf("\nDifferent number bases:\n");
    const char *hex_str = "FF";
    const char *octal_str = "77";
    const char *binary_str = "1010";
    
    printf("strtol(\"%s\", base 16) = %ld\n", hex_str, strtol(hex_str, NULL, 16));
    printf("strtol(\"%s\", base 8) = %ld\n", octal_str, strtol(octal_str, NULL, 8));
    printf("strtol(\"%s\", base 2) = %ld\n", binary_str, strtol(binary_str, NULL, 2));
    printf("strtol(\"0xFF\", base 0) = %ld (auto-detect)\n", strtol("0xFF", NULL, 0));
    
    printf("\n");
}

void demonstrate_random_numbers(void) {
    printf("3. RANDOM NUMBER GENERATION\n");
    printf("----------------------------------------\n");
    
    printf("RAND_MAX = %d\n", RAND_MAX);
    
    // Seed the random number generator
    srand((unsigned int)time(NULL));
    
    // Generate random numbers
    printf("\nRandom integers (0 to RAND_MAX):\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", rand());
    }
    printf("\n");
    
    // Random numbers in specific range
    printf("\nRandom numbers 1-10:\n");
    for (int i = 0; i < 10; i++) {
        int random_1_to_10 = (rand() % 10) + 1;
        printf("%d ", random_1_to_10);
    }
    printf("\n");
    
    // Random floating point numbers 0.0 to 1.0
    printf("\nRandom floats (0.0 to 1.0):\n");
    for (int i = 0; i < 5; i++) {
        double random_float = (double)rand() / RAND_MAX;
        printf("%.4f ", random_float);
    }
    printf("\n");
    
    // Random floats in range
    printf("\nRandom floats (-5.0 to 5.0):\n");
    for (int i = 0; i < 5; i++) {
        double random_range = ((double)rand() / RAND_MAX) * 10.0 - 5.0;
        printf("%.2f ", random_range);
    }
    printf("\n");
    
    // Demonstrate seeding effect
    printf("\nDemonstrating seeding:\n");
    printf("Seed 123: ");
    srand(123);
    for (int i = 0; i < 5; i++) {
        printf("%d ", rand() % 100);
    }
    printf("\n");
    
    printf("Seed 123 again: ");
    srand(123);
    for (int i = 0; i < 5; i++) {
        printf("%d ", rand() % 100);
    }
    printf(" (same sequence)\n");
    
    printf("\n");
}

void demonstrate_utility_functions(void) {
    printf("4. UTILITY FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    // Absolute value functions
    printf("Absolute value functions:\n");
    int int_vals[] = {-5, 0, 5, -42, 100};
    long long_vals[] = {-1000000L, 0L, 1000000L};
    
    for (int i = 0; i < 5; i++) {
        printf("abs(%d) = %d\n", int_vals[i], abs(int_vals[i]));
    }
    
    for (int i = 0; i < 3; i++) {
        printf("labs(%ld) = %ld\n", long_vals[i], labs(long_vals[i]));
    }
    
    // Division functions
    printf("\nDivision with quotient and remainder:\n");
    int dividends[] = {17, -17, 100, 7};
    int divisors[] = {5, 5, 7, 3};
    
    for (int i = 0; i < 4; i++) {
        div_t result = div(dividends[i], divisors[i]);
        printf("div(%d, %d) -> quotient: %d, remainder: %d\n",
               dividends[i], divisors[i], result.quot, result.rem);
    }
    
    // Long division
    long long_dividend = 1000000L;
    long long_divisor = 7L;
    ldiv_t long_result = ldiv(long_dividend, long_divisor);
    printf("ldiv(%ld, %ld) -> quotient: %ld, remainder: %ld\n",
           long_dividend, long_divisor, long_result.quot, long_result.rem);
    
    printf("\n");
}

void demonstrate_sorting_searching(void) {
    printf("5. SORTING AND SEARCHING\n");
    printf("----------------------------------------\n");
    
    // Sorting integers
    int numbers[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int num_count = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original array: ");
    for (int i = 0; i < num_count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Sort using qsort
    qsort(numbers, num_count, sizeof(int), compare_ints);
    
    printf("After qsort: ");
    for (int i = 0; i < num_count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Binary search
    int search_key = 25;
    int *found = (int*)bsearch(&search_key, numbers, num_count, sizeof(int), compare_ints);
    
    if (found != NULL) {
        printf("bsearch found %d at position %ld\n", search_key, found - numbers);
    } else {
        printf("bsearch: %d not found\n", search_key);
    }
    
    // Search for non-existent element
    search_key = 99;
    found = (int*)bsearch(&search_key, numbers, num_count, sizeof(int), compare_ints);
    if (found == NULL) {
        printf("bsearch: %d not found (as expected)\n", search_key);
    }
    
    // Sorting strings
    printf("\nSorting strings:\n");
    const char *fruits[] = {"banana", "apple", "orange", "grape", "kiwi"};
    const char *sorted_fruits[5];
    
    // Copy pointers for sorting
    for (int i = 0; i < 5; i++) {
        sorted_fruits[i] = fruits[i];
    }
    
    printf("Original: ");
    for (int i = 0; i < 5; i++) {
        printf("%s ", fruits[i]);
    }
    printf("\n");
    
    qsort(sorted_fruits, 5, sizeof(char*), compare_strings);
    
    printf("Sorted: ");
    for (int i = 0; i < 5; i++) {
        printf("%s ", sorted_fruits[i]);
    }
    printf("\n");
    
    // Search in sorted strings
    const char *search_fruit = "grape";
    const char **found_fruit = (const char**)bsearch(&search_fruit, sorted_fruits, 5, sizeof(char*), compare_strings);
    
    if (found_fruit != NULL) {
        printf("Found \"%s\" in sorted array\n", *found_fruit);
    }
    
    printf("\n");
}

void demonstrate_system_functions(void) {
    printf("6. SYSTEM FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    // Environment variables
    printf("Environment variable examples:\n");
    char *path = getenv("PATH");
    if (path != NULL) {
        printf("PATH exists (length: %zu)\n", strlen(path));
        // Show first 50 characters
        printf("PATH (first 50 chars): %.50s...\n", path);
    }
    
    char *home = getenv("HOME");
    if (home != NULL) {
        printf("HOME = %s\n", home);
    }
    
    char *nonexistent = getenv("NONEXISTENT_VAR");
    if (nonexistent == NULL) {
        printf("NONEXISTENT_VAR is not set\n");
    }
    
    // System command execution (be careful with this)
    printf("\nSystem command execution:\n");
    printf("Executing 'echo Hello from system()'\n");
    int result = system("echo Hello from system()");
    printf("system() returned: %d\n", result);
    
    // Date command
    printf("Current date/time:\n");
    system("date");
    
    // Exit functions demonstration (commented out to not exit)
    printf("\nExit functions (demonstrated but not called):\n");
    printf("exit(0) - normal termination\n");
    printf("exit(1) - error termination\n");
    printf("abort() - abnormal termination\n");
    
    // atexit registration (demonstration)
    printf("atexit() can register cleanup functions\n");
    
    printf("\n");
}

// Helper function for integer comparison
int compare_ints(const void *a, const void *b) {
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;
    
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

// Helper function for string comparison
int compare_strings(const void *a, const void *b) {
    const char *str_a = *(const char**)a;
    const char *str_b = *(const char**)b;
    
    return strcmp(str_a, str_b);
}

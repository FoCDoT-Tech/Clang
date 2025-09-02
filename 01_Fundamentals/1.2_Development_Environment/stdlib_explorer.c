#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to demonstrate stdlib.h documentation exploration
void explore_stdlib_functions(void);
void demonstrate_memory_functions(void);
void demonstrate_conversion_functions(void);
void demonstrate_utility_functions(void);

int main() {
    printf("=== stdlib.h Library Explorer ===\n\n");
    
    printf("This program demonstrates how to explore and document C library functions.\n");
    printf("We'll explore stdlib.h - one of the most important C standard libraries.\n\n");
    
    // Show how to find library documentation
    printf("📚 HOW TO EXPLORE C LIBRARIES:\n");
    printf("1. Use 'man' command: man 3 malloc, man 3 printf\n");
    printf("2. Check header files: /usr/include/stdlib.h (on Unix/Linux)\n");
    printf("3. Online references: cppreference.com, gnu.org documentation\n");
    printf("4. IDE help: Most IDEs show function signatures on hover\n\n");
    
    explore_stdlib_functions();
    demonstrate_memory_functions();
    demonstrate_conversion_functions();
    demonstrate_utility_functions();
    
    return 0;
}

void explore_stdlib_functions(void) {
    printf("🔍 STDLIB.H MAIN CATEGORIES:\n");
    printf("┌─────────────────────────────────────────────────────────────┐\n");
    printf("│ Category          │ Functions                               │\n");
    printf("├─────────────────────────────────────────────────────────────┤\n");
    printf("│ Memory Management │ malloc(), calloc(), realloc(), free()  │\n");
    printf("│ String Conversion │ atoi(), atof(), strtol(), strtod()     │\n");
    printf("│ Random Numbers    │ rand(), srand()                        │\n");
    printf("│ Process Control   │ exit(), abort(), atexit()              │\n");
    printf("│ Environment       │ getenv(), system()                     │\n");
    printf("│ Searching/Sorting │ qsort(), bsearch()                     │\n");
    printf("│ Math Utilities    │ abs(), labs(), div(), ldiv()           │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");
}

void demonstrate_memory_functions(void) {
    printf("💾 MEMORY MANAGEMENT FUNCTIONS:\n");
    
    // malloc() - allocate memory
    printf("1. malloc(size_t size) - Allocates memory block\n");
    int *ptr = malloc(sizeof(int) * 5);  // Allocate array of 5 integers
    if (ptr != NULL) {
        printf("   ✓ malloc() allocated memory at: %p\n", (void*)ptr);
        printf("   ✓ Size requested: %zu bytes\n", sizeof(int) * 5);
        
        // Initialize allocated memory
        for (int i = 0; i < 5; i++) {
            ptr[i] = (i + 1) * 10;
        }
        printf("   ✓ Memory initialized with values: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", ptr[i]);
        }
        printf("\n");
    }
    
    // calloc() - allocate and zero-initialize
    printf("2. calloc(num, size) - Allocates zero-initialized memory\n");
    int *zero_ptr = calloc(3, sizeof(int));  // Allocate 3 integers, set to 0
    if (zero_ptr != NULL) {
        printf("   ✓ calloc() allocated and zeroed memory\n");
        printf("   ✓ Values: %d, %d, %d (auto-zeroed)\n", 
               zero_ptr[0], zero_ptr[1], zero_ptr[2]);
    }
    
    // realloc() - resize memory block
    printf("3. realloc(ptr, new_size) - Resizes memory block\n");
    ptr = realloc(ptr, sizeof(int) * 8);  // Expand to 8 integers
    if (ptr != NULL) {
        printf("   ✓ realloc() expanded memory to 8 integers\n");
        printf("   ✓ Original values preserved: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", ptr[i]);
        }
        printf("\n");
    }
    
    // free() - deallocate memory
    printf("4. free(ptr) - Deallocates memory\n");
    free(ptr);
    free(zero_ptr);
    printf("   ✓ Memory freed - prevents memory leaks\n\n");
}

void demonstrate_conversion_functions(void) {
    printf("🔄 STRING CONVERSION FUNCTIONS:\n");
    
    // atoi() - string to integer
    char num_str[] = "12345";
    int converted_int = atoi(num_str);
    printf("1. atoi(\"%s\") = %d\n", num_str, converted_int);
    
    // atof() - string to float
    char float_str[] = "3.14159";
    double converted_float = atof(float_str);
    printf("2. atof(\"%s\") = %.5f\n", float_str, converted_float);
    
    // strtol() - string to long (with error checking)
    char *endptr;
    char mixed_str[] = "123abc";
    long converted_long = strtol(mixed_str, &endptr, 10);
    printf("3. strtol(\"%s\", &endptr, 10) = %ld\n", mixed_str, converted_long);
    printf("   ✓ Stopped at: '%s' (non-numeric part)\n", endptr);
    
    // Demonstrate different bases
    char hex_str[] = "FF";
    long hex_value = strtol(hex_str, NULL, 16);  // Base 16
    printf("4. strtol(\"%s\", NULL, 16) = %ld (hex to decimal)\n", hex_str, hex_value);
    
    printf("\n");
}

void demonstrate_utility_functions(void) {
    printf("🛠️  UTILITY FUNCTIONS:\n");
    
    // abs() - absolute value
    int negative = -42;
    printf("1. abs(%d) = %d\n", negative, abs(negative));
    
    // Random numbers
    printf("2. Random number generation:\n");
    srand(42);  // Seed for reproducible results
    printf("   ✓ srand(42) - seed set\n");
    printf("   ✓ rand() values: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", rand() % 100);  // Random 0-99
    }
    printf("\n");
    
    // Environment variable
    printf("3. getenv(\"PATH\") - Environment variable access:\n");
    char *path = getenv("PATH");
    if (path != NULL) {
        printf("   ✓ PATH found (first 50 chars): %.50s...\n", path);
    } else {
        printf("   ✗ PATH not found\n");
    }
    
    // Exit functions (demonstrated but not called)
    printf("4. Process control functions:\n");
    printf("   • exit(0) - Normal program termination\n");
    printf("   • abort() - Abnormal program termination\n");
    printf("   • atexit(func) - Register cleanup function\n");
    
    printf("\n📖 TO LEARN MORE:\n");
    printf("• Run: man 3 stdlib\n");
    printf("• Visit: https://en.cppreference.com/w/c/header/stdlib\n");
    printf("• Check: /usr/include/stdlib.h on your system\n");
}

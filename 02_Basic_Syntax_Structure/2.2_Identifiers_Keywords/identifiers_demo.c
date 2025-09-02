/*
 * identifiers_demo.c - Demonstrates identifiers, keywords, and naming conventions
 * Shows valid/invalid examples and best practices
 */

#include <stdio.h>

// Function declarations demonstrating different naming styles
void demonstrate_valid_identifiers(void);
void demonstrate_naming_conventions(void);
void demonstrate_case_sensitivity(void);
void show_keywords_usage(void);

// Global constants using UPPER_CASE convention
#define MAX_STUDENTS 100
#define PI_VALUE 3.14159

int main() {
    printf("=== Identifiers & Keywords Demo ===\n\n");
    
    demonstrate_valid_identifiers();
    demonstrate_naming_conventions();
    demonstrate_case_sensitivity();
    show_keywords_usage();
    
    printf("✓ Identifiers and keywords demonstration complete!\n");
    return 0;
}

void demonstrate_valid_identifiers(void) {
    printf("Valid Identifiers:\n");
    
    // Valid identifier examples
    int age = 25;                    // Simple name
    int student_count = 50;          // snake_case with underscore
    int maxValue = 100;              // camelCase
    int _private_var = 42;           // Starting with underscore
    int num2 = 2;                    // Contains digit (not at start)
    char first_letter = 'A';         // Descriptive name
    
    printf("- age: %d\n", age);
    printf("- student_count: %d\n", student_count);
    printf("- maxValue: %d\n", maxValue);
    printf("- _private_var: %d\n", _private_var);
    printf("- num2: %d\n", num2);
    printf("- first_letter: %c\n", first_letter);
    
    /* Invalid examples (commented out to avoid compilation errors):
     * int 2num;          // ERROR: Starts with digit
     * int student-count; // ERROR: Contains hyphen
     * int for;           // ERROR: Reserved keyword
     * int my var;        // ERROR: Contains space
     * int class;         // ERROR: Reserved keyword (C++)
     */
    
    printf("\n");
}

void demonstrate_naming_conventions(void) {
    printf("Naming Conventions:\n");
    
    // snake_case style
    int total_score = 95;
    int max_attempts = 3;
    
    // camelCase style
    int totalScore = 95;
    int maxAttempts = 3;
    
    // Constants (UPPER_CASE)
    printf("- Constants: MAX_STUDENTS = %d, PI_VALUE = %.5f\n", MAX_STUDENTS, PI_VALUE);
    printf("- snake_case: total_score = %d, max_attempts = %d\n", total_score, max_attempts);
    printf("- camelCase: totalScore = %d, maxAttempts = %d\n", totalScore, maxAttempts);
    
    printf("\n");
}

void demonstrate_case_sensitivity(void) {
    printf("Case Sensitivity Examples:\n");
    
    // These are all different variables due to case sensitivity
    int variable = 10;
    int Variable = 20;
    int VARIABLE = 30;
    int variABLE = 40;
    
    printf("- variable (lowercase): %d\n", variable);
    printf("- Variable (capitalized): %d\n", Variable);
    printf("- VARIABLE (uppercase): %d\n", VARIABLE);
    printf("- variABLE (mixed case): %d\n", variABLE);
    
    // Function names are also case sensitive
    printf("- printf() works, Printf() would cause error\n");
    
    printf("\n");
}

void show_keywords_usage(void) {
    printf("Reserved Keywords in Use:\n");
    
    // Demonstrate some common keywords
    int count;                    // 'int' keyword
    for (count = 1; count <= 3; count++) {  // 'for' keyword
        if (count == 2) {         // 'if' keyword
            continue;             // 'continue' keyword
        }
        printf("- Loop iteration: %d\n", count);
    }
    
    // Other keywords in context
    const int readonly = 100;     // 'const' keyword
    static int persistent = 0;    // 'static' keyword
    persistent++;
    
    printf("- const variable: %d\n", readonly);
    printf("- static variable: %d\n", persistent);
    
    // Keywords that cannot be used as identifiers:
    printf("- Reserved: auto, break, case, char, const, continue, default, do\n");
    printf("- Reserved: double, else, enum, extern, float, for, goto, if\n");
    printf("- Reserved: int, long, register, return, short, signed, sizeof\n");
    printf("- Reserved: static, struct, switch, typedef, union, unsigned\n");
    printf("- Reserved: void, volatile, while, restrict\n");
    
    printf("\n");
}

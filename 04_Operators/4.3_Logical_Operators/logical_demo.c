#include <stdio.h>

// Function prototypes
void demonstrate_logical_and(void);
void demonstrate_logical_or(void);
void demonstrate_logical_not(void);
void demonstrate_short_circuit_evaluation(void);
void demonstrate_truth_tables(void);
void demonstrate_practical_applications(void);
void demonstrate_operator_precedence(void);

int main() {
    printf("=== Logical Operators Demo ===\n\n");
    
    demonstrate_logical_and();
    demonstrate_logical_or();
    demonstrate_logical_not();
    demonstrate_short_circuit_evaluation();
    demonstrate_truth_tables();
    demonstrate_practical_applications();
    demonstrate_operator_precedence();
    
    printf("✓ All logical operators demonstrated!\n");
    return 0;
}

void demonstrate_logical_and(void) {
    printf("1. LOGICAL AND (&&) OPERATOR:\n");
    
    int a = 1, b = 1, c = 0;
    printf("Given: a = %d (true), b = %d (true), c = %d (false)\n", a, b, c);
    
    printf("a && b = %d && %d = %d (both true)\n", a, b, a && b);
    printf("a && c = %d && %d = %d (one false)\n", a, c, a && c);
    printf("c && c = %d && %d = %d (both false)\n", c, c, c && c);
    
    // Practical example: range checking
    int age = 25;
    printf("\nRange checking example (age = %d):\n", age);
    if (age >= 18 && age <= 65) {
        printf("Eligible for employment (18-65 years)\n");
    } else {
        printf("Not in employment age range\n");
    }
    printf("\n");
}

void demonstrate_logical_or(void) {
    printf("2. LOGICAL OR (||) OPERATOR:\n");
    
    int x = 1, y = 0, z = 0;
    printf("Given: x = %d (true), y = %d (false), z = %d (false)\n", x, y, z);
    
    printf("x || y = %d || %d = %d (one true)\n", x, y, x || y);
    printf("y || z = %d || %d = %d (both false)\n", y, z, y || z);
    printf("x || x = %d || %d = %d (both true)\n", x, x, x || x);
    
    // Practical example: multiple valid conditions
    char grade = 'B';
    printf("\nGrade validation example (grade = '%c'):\n", grade);
    if (grade == 'A' || grade == 'B' || grade == 'C') {
        printf("Passing grade\n");
    } else {
        printf("Failing grade\n");
    }
    printf("\n");
}

void demonstrate_logical_not(void) {
    printf("3. LOGICAL NOT (!) OPERATOR:\n");
    
    int true_val = 1, false_val = 0, number = 42;
    printf("Given: true_val = %d, false_val = %d, number = %d\n", 
           true_val, false_val, number);
    
    printf("!true_val = !%d = %d\n", true_val, !true_val);
    printf("!false_val = !%d = %d\n", false_val, !false_val);
    printf("!number = !%d = %d (any non-zero is true)\n", number, !number);
    
    // Double negation
    printf("!!number = !!%d = %d (converts to 1 or 0)\n", number, !!number);
    
    // Practical example: toggling flags
    int is_logged_in = 1;
    printf("\nFlag toggling example:\n");
    printf("Before: is_logged_in = %d\n", is_logged_in);
    is_logged_in = !is_logged_in;  // Toggle
    printf("After toggle: is_logged_in = %d\n", is_logged_in);
    printf("\n");
}

void demonstrate_short_circuit_evaluation(void) {
    printf("4. SHORT-CIRCUIT EVALUATION:\n");
    
    int a = 0, b = 5;
    printf("Given: a = %d, b = %d\n", a, b);
    
    // AND short-circuit: if first is false, second is not evaluated
    printf("AND short-circuit: a && (b = 10)\n");
    printf("Before: b = %d\n", b);
    int result1 = a && (b = 10);  // b = 10 is not executed
    printf("After: b = %d (unchanged - second expression not evaluated)\n", b);
    printf("Result: %d\n", result1);
    
    // OR short-circuit: if first is true, second is not evaluated
    a = 1;  // Reset a to true
    printf("\nOR short-circuit: a || (b = 20)\n");
    printf("Before: a = %d, b = %d\n", a, b);
    int result2 = a || (b = 20);  // b = 20 is not executed
    printf("After: b = %d (unchanged - second expression not evaluated)\n", b);
    printf("Result: %d\n", result2);
    
    // Practical use: safe pointer access
    int *ptr = NULL;
    printf("\nSafe pointer access example:\n");
    if (ptr != NULL && *ptr > 0) {  // *ptr is not evaluated if ptr is NULL
        printf("Pointer value is positive\n");
    } else {
        printf("Pointer is NULL or value is not positive\n");
    }
    printf("\n");
}

void demonstrate_truth_tables(void) {
    printf("5. TRUTH TABLES:\n");
    
    printf("AND (&&) Truth Table:\n");
    printf("A | B | A && B\n");
    printf("--|---|-------\n");
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("%d | %d |   %d\n", a, b, a && b);
        }
    }
    
    printf("\nOR (||) Truth Table:\n");
    printf("A | B | A || B\n");
    printf("--|---|-------\n");
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            printf("%d | %d |   %d\n", a, b, a || b);
        }
    }
    
    printf("\nNOT (!) Truth Table:\n");
    printf("A | !A\n");
    printf("--|---\n");
    for (int a = 0; a <= 1; a++) {
        printf("%d |  %d\n", a, !a);
    }
    printf("\n");
}

void demonstrate_practical_applications(void) {
    printf("6. PRACTICAL APPLICATIONS:\n");
    
    // User authentication system
    int has_username = 1, has_password = 1, is_verified = 0;
    printf("Authentication system:\n");
    printf("has_username = %d, has_password = %d, is_verified = %d\n", 
           has_username, has_password, is_verified);
    
    if (has_username && has_password && is_verified) {
        printf("Access granted\n");
    } else if (has_username && has_password && !is_verified) {
        printf("Please verify your account\n");
    } else {
        printf("Invalid credentials\n");
    }
    
    // Game state checking
    int player_alive = 1, has_ammo = 0, has_health_pack = 1;
    printf("\nGame state checking:\n");
    printf("player_alive = %d, has_ammo = %d, has_health_pack = %d\n", 
           player_alive, has_ammo, has_health_pack);
    
    if (!player_alive) {
        printf("Game Over\n");
    } else if (has_ammo || has_health_pack) {
        printf("Player can continue fighting\n");
    } else {
        printf("Player should retreat\n");
    }
    
    // Input validation
    int age = 25;
    char category = 'A';
    printf("\nInput validation (age = %d, category = '%c'):\n", age, category);
    
    if ((age >= 18 && age <= 65) && (category == 'A' || category == 'B')) {
        printf("Valid application\n");
    } else {
        printf("Invalid application\n");
    }
    printf("\n");
}

void demonstrate_operator_precedence(void) {
    printf("7. OPERATOR PRECEDENCE:\n");
    
    int a = 1, b = 0, c = 1;
    printf("Given: a = %d, b = %d, c = %d\n", a, b, c);
    
    // NOT has higher precedence than AND/OR
    int result1 = !a && b;  // (!a) && b
    printf("!a && b = (!%d) && %d = %d && %d = %d\n", a, b, !a, b, result1);
    
    // AND has higher precedence than OR
    int result2 = a || b && c;  // a || (b && c)
    printf("a || b && c = %d || (%d && %d) = %d || %d = %d\n", 
           a, b, c, b && c, result2);
    
    // Using parentheses for clarity
    int result3 = (a || b) && c;
    printf("(a || b) && c = (%d || %d) && %d = %d && %d = %d\n", 
           a, b, c, a || b, result3);
    
    printf("Precedence: ! > && > ||\n");
    printf("Always use parentheses for complex expressions!\n\n");
}

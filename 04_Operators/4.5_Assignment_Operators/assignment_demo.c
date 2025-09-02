#include <stdio.h>

// Function prototypes
void demonstrate_basic_assignment(void);
void demonstrate_compound_arithmetic(void);
void demonstrate_compound_bitwise(void);
void demonstrate_assignment_properties(void);
void demonstrate_practical_applications(void);
void demonstrate_common_mistakes(void);

int main() {
    printf("=== Assignment Operators Demo ===\n\n");
    
    demonstrate_basic_assignment();
    demonstrate_compound_arithmetic();
    demonstrate_compound_bitwise();
    demonstrate_assignment_properties();
    demonstrate_practical_applications();
    demonstrate_common_mistakes();
    
    printf("✓ All assignment operators demonstrated!\n");
    return 0;
}

void demonstrate_basic_assignment(void) {
    printf("1. BASIC ASSIGNMENT (=):\n");
    
    int a, b, c;
    
    // Simple assignment
    a = 10;
    printf("a = 10; → a = %d\n", a);
    
    // Chain assignment (right to left)
    a = b = c = 5;
    printf("a = b = c = 5; → a = %d, b = %d, c = %d\n", a, b, c);
    
    // Assignment in expressions
    int x = 0;
    if ((x = 15) > 10) {  // Assignment returns the assigned value
        printf("Assignment in condition: x = %d (assigned and compared)\n", x);
    }
    
    printf("Assignment operator returns the assigned value\n\n");
}

void demonstrate_compound_arithmetic(void) {
    printf("2. COMPOUND ARITHMETIC ASSIGNMENT:\n");
    
    int value = 10;
    printf("Initial value: %d\n", value);
    
    // Addition assignment
    value += 5;  // Equivalent to: value = value + 5
    printf("value += 5; → %d\n", value);
    
    // Subtraction assignment
    value -= 3;  // Equivalent to: value = value - 3
    printf("value -= 3; → %d\n", value);
    
    // Multiplication assignment
    value *= 2;  // Equivalent to: value = value * 2
    printf("value *= 2; → %d\n", value);
    
    // Division assignment
    value /= 4;  // Equivalent to: value = value / 4
    printf("value /= 4; → %d\n", value);
    
    // Modulo assignment
    value %= 3;  // Equivalent to: value = value % 3
    printf("value %%= 3; → %d\n", value);
    
    // Floating-point example
    float price = 100.0f;
    printf("\nFloating-point example (price = %.2f):\n", price);
    price *= 1.15f;  // Apply 15% tax
    printf("price *= 1.15; → %.2f (with tax)\n", price);
    printf("\n");
}

void demonstrate_compound_bitwise(void) {
    printf("3. COMPOUND BITWISE ASSIGNMENT:\n");
    
    unsigned char flags = 0b00001010;  // Binary literal (if supported)
    printf("Initial flags: %d (binary: ", flags);
    for (int i = 7; i >= 0; i--) printf("%d", (flags >> i) & 1);
    printf(")\n");
    
    // Bitwise AND assignment
    flags &= 0b00001111;  // Keep only lower 4 bits
    printf("flags &= 0b00001111; → %d (", flags);
    for (int i = 7; i >= 0; i--) printf("%d", (flags >> i) & 1);
    printf(")\n");
    
    // Bitwise OR assignment
    flags |= 0b00000101;  // Set bits 0 and 2
    printf("flags |= 0b00000101; → %d (", flags);
    for (int i = 7; i >= 0; i--) printf("%d", (flags >> i) & 1);
    printf(")\n");
    
    // Bitwise XOR assignment
    flags ^= 0b00000011;  // Toggle bits 0 and 1
    printf("flags ^= 0b00000011; → %d (", flags);
    for (int i = 7; i >= 0; i--) printf("%d", (flags >> i) & 1);
    printf(")\n");
    
    // Shift assignments
    unsigned int num = 8;
    printf("\nShift operations (num = %d):\n", num);
    num <<= 2;  // Left shift by 2 (multiply by 4)
    printf("num <<= 2; → %d (multiply by 4)\n", num);
    
    num >>= 1;  // Right shift by 1 (divide by 2)
    printf("num >>= 1; → %d (divide by 2)\n", num);
    printf("\n");
}

void demonstrate_assignment_properties(void) {
    printf("4. ASSIGNMENT PROPERTIES:\n");
    
    // Right-to-left associativity
    int a, b, c, d;
    a = b = c = d = 42;
    printf("Chain assignment: a = b = c = d = 42\n");
    printf("Result: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    
    // Assignment returns value
    int x = 0, y = 0;
    y = (x = 10) + 5;  // x gets 10, y gets 15
    printf("y = (x = 10) + 5; → x=%d, y=%d\n", x, y);
    
    // Precedence demonstration
    int result;
    result = 2 + 3 * 4;  // Multiplication before assignment
    printf("result = 2 + 3 * 4; → %d (multiplication first)\n", result);
    
    // Assignment vs equality
    int test = 5;
    printf("test = 5 (assignment) → test = %d\n", test);
    printf("test == 5 (comparison) → %s\n", (test == 5) ? "true" : "false");
    printf("\n");
}

void demonstrate_practical_applications(void) {
    printf("5. PRACTICAL APPLICATIONS:\n");
    
    // Running totals
    int sum = 0;
    int numbers[] = {10, 20, 30, 40, 50};
    printf("Calculating sum of array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
        sum += numbers[i];  // Accumulate
    }
    printf("= %d\n", sum);
    
    // Counter with different increments
    int score = 0;
    printf("Game scoring:\n");
    score += 100;  // Basic points
    printf("Basic points: %d\n", score);
    score *= 2;    // Double bonus
    printf("Double bonus: %d\n", score);
    score -= 50;   // Penalty
    printf("After penalty: %d\n", score);
    
    // Bit flag management
    unsigned int permissions = 0;
    #define READ_FLAG    1  // 001
    #define WRITE_FLAG   2  // 010
    #define EXECUTE_FLAG 4  // 100
    
    printf("\nPermission management:\n");
    permissions |= READ_FLAG;    // Grant read
    permissions |= WRITE_FLAG;   // Grant write
    printf("Granted read+write: %d\n", permissions);
    
    permissions &= ~WRITE_FLAG;  // Revoke write
    printf("Revoked write: %d\n", permissions);
    
    // String building (character by character)
    char buffer[20] = "";
    char *ptr = buffer;
    *ptr++ = 'H';  // Assign and increment pointer
    *ptr++ = 'i';
    *ptr++ = '!';
    *ptr = '\0';   // Null terminate
    printf("Built string: \"%s\"\n", buffer);
    printf("\n");
}

void demonstrate_common_mistakes(void) {
    printf("6. COMMON MISTAKES:\n");
    
    // Assignment vs comparison
    int value = 10;
    printf("Original value: %d\n", value);
    
    // This is assignment, not comparison!
    if (value = 5) {  // Warning: should be ==
        printf("Mistake: used = instead of == (value is now %d)\n", value);
    }
    
    value = 10;  // Reset
    
    // Correct comparison
    if (value == 10) {
        printf("Correct: used == for comparison (value is %d)\n", value);
    }
    
    // Compound assignment efficiency
    int array[] = {1, 2, 3, 4, 5};
    int index = 2;
    
    // Less efficient (evaluates array[index] twice)
    printf("Before: array[%d] = %d\n", index, array[index]);
    array[index] = array[index] + 10;
    printf("Long form: array[%d] = %d\n", index, array[index]);
    
    // More efficient (evaluates array[index] once)
    array[index] += 10;
    printf("Compound form: array[%d] = %d\n", index, array[index]);
    
    // Operator precedence confusion
    int a = 5, b = 3;
    int result1 = a += b * 2;  // a += (b * 2), then result1 = a
    printf("a += b * 2 with a=5, b=3: a=%d, result=%d\n", a, result1);
    
    printf("Always use parentheses when in doubt!\n\n");
}

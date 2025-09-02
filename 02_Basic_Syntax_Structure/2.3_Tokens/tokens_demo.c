/*
 * tokens_demo.c - Demonstrates all types of tokens in C
 * Shows keywords, identifiers, constants, strings, operators, and special symbols
 */

#include <stdio.h>
#include <string.h>

// Function declarations (identifiers)
void demonstrate_keywords(void);
void demonstrate_constants(void);
void demonstrate_strings(void);
void demonstrate_operators(void);
void demonstrate_special_symbols(void);

int main() {
    printf("=== C Tokens Demonstration ===\n\n");
    
    demonstrate_keywords();
    demonstrate_constants();
    demonstrate_strings();
    demonstrate_operators();
    demonstrate_special_symbols();
    
    printf("✓ All token types demonstrated!\n");
    return 0;
}

void demonstrate_keywords(void) {
    printf("1. KEYWORDS (Reserved Words):\n");
    
    // Keywords in action
    int number = 10;              // 'int' keyword
    const float pi = 3.14f;       // 'const' and 'float' keywords
    
    if (number > 5) {             // 'if' keyword
        printf("- Keywords used: int, const, float, if\n");
        for (int i = 0; i < 3; i++) {  // 'for' keyword
            // Loop body - 'break' and 'continue' are also keywords
        }
    }
    
    // Other common keywords: while, do, switch, case, default, return
    // struct, union, enum, typedef, static, extern, auto, register
    // void, char, short, long, signed, unsigned, double
    // sizeof, volatile, restrict
    
    printf("- Total C keywords: 32 (C90) + additional in C99/C11\n\n");
}

void demonstrate_constants(void) {
    printf("2. CONSTANTS (Literal Values):\n");
    
    // Integer constants
    int decimal = 42;             // Decimal constant
    int octal = 052;              // Octal constant (starts with 0)
    int hex = 0x2A;               // Hexadecimal constant (starts with 0x)
    long long_num = 42L;          // Long constant
    unsigned int unsigned_num = 42U; // Unsigned constant
    
    printf("- Integer constants:\n");
    printf("  Decimal: %d, Octal: %d, Hex: %d\n", decimal, octal, hex);
    printf("  Long: %ld, Unsigned: %u\n", long_num, unsigned_num);
    
    // Floating-point constants
    float float_num = 3.14f;      // Float constant
    double double_num = 3.14159;  // Double constant
    double scientific = 1.5e10;   // Scientific notation
    
    printf("- Floating-point constants:\n");
    printf("  Float: %.2f, Double: %.5f, Scientific: %.2e\n", 
           float_num, double_num, scientific);
    
    // Character constants
    char letter = 'A';            // Character constant
    char newline = '\n';          // Escape sequence constant
    char null_char = '\0';        // Null character constant
    
    printf("- Character constants:\n");
    printf("  Letter: %c, ASCII: %d\n", letter, letter);
    printf("  Newline: ASCII %d, Null: ASCII %d\n", newline, null_char);
    
    printf("\n");
}

void demonstrate_strings(void) {
    printf("3. STRING LITERALS:\n");
    
    // String literals
    char greeting[] = "Hello World";     // String literal
    char empty[] = "";                   // Empty string literal
    char multiline[] = "Line 1\n"        // String concatenation
                      "Line 2\n"
                      "Line 3";
    
    printf("- String examples:\n");
    printf("  Greeting: \"%s\"\n", greeting);
    printf("  Empty string length: %zu\n", strlen(empty));
    printf("  Multi-line string:\n%s\n", multiline);
    
    // String with escape sequences
    char escaped[] = "Tab:\t Quote:\" Backslash:\\ Newline:\n";
    printf("- Escape sequences: %s", escaped);
    
    printf("\n");
}

void demonstrate_operators(void) {
    printf("4. OPERATORS:\n");
    
    int a = 10, b = 3;
    
    // Arithmetic operators
    printf("- Arithmetic operators (a=10, b=3):\n");
    printf("  a + b = %d\n", a + b);     // + operator
    printf("  a - b = %d\n", a - b);     // - operator
    printf("  a * b = %d\n", a * b);     // * operator
    printf("  a / b = %d\n", a / b);     // / operator
    printf("  a %% b = %d\n", a % b);    // % operator
    
    // Relational operators
    printf("- Relational operators:\n");
    printf("  a > b: %d\n", a > b);      // > operator
    printf("  a == b: %d\n", a == b);    // == operator
    printf("  a != b: %d\n", a != b);    // != operator
    
    // Logical operators
    printf("- Logical operators:\n");
    printf("  (a > 5) && (b < 5): %d\n", (a > 5) && (b < 5));  // && operator
    printf("  (a < 5) || (b > 1): %d\n", (a < 5) || (b > 1));  // || operator
    printf("  !(a == b): %d\n", !(a == b));                    // ! operator
    
    // Assignment operators
    int c = a;                    // = operator
    c += b;                       // += operator
    printf("- Assignment: c = a + b = %d\n", c);
    
    printf("\n");
}

void demonstrate_special_symbols(void) {
    printf("5. SPECIAL SYMBOLS (Punctuators):\n");
    
    // Demonstrate various special symbols
    printf("- Semicolon (;): Terminates statements\n");
    printf("- Comma (,): Separates items in lists\n");
    printf("- Parentheses (): Function calls, grouping\n");
    printf("- Braces {}: Code blocks\n");
    printf("- Brackets []: Array indexing\n");
    
    // Array example showing brackets
    int numbers[] = {1, 2, 3, 4, 5};    // {} and [] symbols
    printf("- Array access: numbers[0] = %d\n", numbers[0]);
    
    // Structure example (if we had one)
    printf("- Dot (.): Member access for structures\n");
    printf("- Arrow (->): Member access for pointers to structures\n");
    
    // Preprocessor symbols
    printf("- Hash (#): Preprocessor directives\n");
    
    printf("\nToken separation by whitespace:\n");
    printf("int x=5; // Tokens: 'int', 'x', '=', '5', ';'\n");
    printf("int x = 5; // Same tokens, better formatting\n");
    
    printf("\n");
}

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
void demonstrate_character_testing(void);
void demonstrate_character_conversion(void);
void demonstrate_text_processing(void);
void demonstrate_input_validation(void);
void demonstrate_string_analysis(void);

int main(void) {
    printf("=== Character Classification Demo ===\n\n");
    
    demonstrate_character_testing();
    demonstrate_character_conversion();
    demonstrate_text_processing();
    demonstrate_input_validation();
    demonstrate_string_analysis();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_character_testing(void) {
    printf("1. CHARACTER TESTING FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    // Test characters including special cases
    char test_chars[] = {'A', 'z', '5', ' ', '\t', '\n', '!', '@', 'F', '9', '\x07'};
    int num_chars = sizeof(test_chars) / sizeof(test_chars[0]);
    
    printf("Char | Alpha | Digit | Alnum | Space | Punct | Upper | Lower | Print | Cntrl | Graph | Xdigit\n");
    printf("-----|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------\n");
    
    for (int i = 0; i < num_chars; i++) {
        char ch = test_chars[i];
        
        // Handle non-printable characters for display
        if (isprint(ch)) {
            printf("'%c'  ", ch);
        } else if (ch == '\t') {
            printf("\\t   ");
        } else if (ch == '\n') {
            printf("\\n   ");
        } else {
            printf("0x%02X ", (unsigned char)ch);
        }
        
        printf("|   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c\n",
               isalpha(ch) ? 'Y' : 'N',
               isdigit(ch) ? 'Y' : 'N',
               isalnum(ch) ? 'Y' : 'N',
               isspace(ch) ? 'Y' : 'N',
               ispunct(ch) ? 'Y' : 'N',
               isupper(ch) ? 'Y' : 'N',
               islower(ch) ? 'Y' : 'N',
               isprint(ch) ? 'Y' : 'N',
               iscntrl(ch) ? 'Y' : 'N',
               isgraph(ch) ? 'Y' : 'N',
               isxdigit(ch) ? 'Y' : 'N');
    }
    
    // Demonstrate ranges
    printf("\nCharacter ranges:\n");
    
    // Count different character types in ASCII range
    int alpha_count = 0, digit_count = 0, punct_count = 0, space_count = 0;
    
    for (int i = 0; i < 128; i++) {
        if (isalpha(i)) alpha_count++;
        if (isdigit(i)) digit_count++;
        if (ispunct(i)) punct_count++;
        if (isspace(i)) space_count++;
    }
    
    printf("In ASCII (0-127): %d alphabetic, %d digits, %d punctuation, %d whitespace\n",
           alpha_count, digit_count, punct_count, space_count);
    
    printf("\n");
}

void demonstrate_character_conversion(void) {
    printf("2. CHARACTER CONVERSION\n");
    printf("----------------------------------------\n");
    
    const char *test_string = "Hello, World! 123 ABC xyz";
    
    printf("Original: \"%s\"\n", test_string);
    
    // Convert to uppercase
    printf("Uppercase: \"");
    for (int i = 0; test_string[i]; i++) {
        putchar(toupper(test_string[i]));
    }
    printf("\"\n");
    
    // Convert to lowercase
    printf("Lowercase: \"");
    for (int i = 0; test_string[i]; i++) {
        putchar(tolower(test_string[i]));
    }
    printf("\"\n");
    
    // Demonstrate conversion behavior
    printf("\nConversion examples:\n");
    char conversion_chars[] = {'A', 'z', '5', ' ', '!', 'M', 'n'};
    
    for (int i = 0; i < 7; i++) {
        char ch = conversion_chars[i];
        printf("'%c' -> toupper: '%c', tolower: '%c'\n", 
               ch, toupper(ch), tolower(ch));
    }
    
    // Case-insensitive comparison using conversion
    printf("\nCase-insensitive string comparison:\n");
    const char *str1 = "Hello";
    const char *str2 = "HELLO";
    const char *str3 = "World";
    
    // Manual case-insensitive comparison
    int equal = 1;
    if (strlen(str1) == strlen(str2)) {
        for (int i = 0; str1[i]; i++) {
            if (tolower(str1[i]) != tolower(str2[i])) {
                equal = 0;
                break;
            }
        }
    } else {
        equal = 0;
    }
    
    printf("\"%s\" vs \"%s\": %s\n", str1, str2, equal ? "equal" : "different");
    
    equal = 1;
    if (strlen(str1) == strlen(str3)) {
        for (int i = 0; str1[i]; i++) {
            if (tolower(str1[i]) != tolower(str3[i])) {
                equal = 0;
                break;
            }
        }
    } else {
        equal = 0;
    }
    
    printf("\"%s\" vs \"%s\": %s\n", str1, str3, equal ? "equal" : "different");
    
    printf("\n");
}

void demonstrate_text_processing(void) {
    printf("3. TEXT PROCESSING APPLICATIONS\n");
    printf("----------------------------------------\n");
    
    const char *text = "The Quick Brown Fox Jumps Over 123 Lazy Dogs!";
    
    printf("Text: \"%s\"\n", text);
    
    // Count different character types
    int letters = 0, digits = 0, spaces = 0, punctuation = 0, others = 0;
    int uppercase = 0, lowercase = 0;
    
    for (int i = 0; text[i]; i++) {
        char ch = text[i];
        
        if (isalpha(ch)) {
            letters++;
            if (isupper(ch)) uppercase++;
            if (islower(ch)) lowercase++;
        } else if (isdigit(ch)) {
            digits++;
        } else if (isspace(ch)) {
            spaces++;
        } else if (ispunct(ch)) {
            punctuation++;
        } else {
            others++;
        }
    }
    
    printf("\nCharacter analysis:\n");
    printf("  Letters: %d (uppercase: %d, lowercase: %d)\n", letters, uppercase, lowercase);
    printf("  Digits: %d\n", digits);
    printf("  Spaces: %d\n", spaces);
    printf("  Punctuation: %d\n", punctuation);
    printf("  Others: %d\n", others);
    printf("  Total: %d\n", (int)strlen(text));
    
    // Extract only letters
    printf("\nLetters only: \"");
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            putchar(text[i]);
        }
    }
    printf("\"\n");
    
    // Extract only digits
    printf("Digits only: \"");
    for (int i = 0; text[i]; i++) {
        if (isdigit(text[i])) {
            putchar(text[i]);
        }
    }
    printf("\"\n");
    
    // Title case conversion
    printf("Title case: \"");
    int capitalize_next = 1;
    for (int i = 0; text[i]; i++) {
        char ch = text[i];
        
        if (isalpha(ch)) {
            if (capitalize_next) {
                putchar(toupper(ch));
                capitalize_next = 0;
            } else {
                putchar(tolower(ch));
            }
        } else {
            putchar(ch);
            if (isspace(ch)) {
                capitalize_next = 1;
            }
        }
    }
    printf("\"\n");
    
    printf("\n");
}

void demonstrate_input_validation(void) {
    printf("4. INPUT VALIDATION\n");
    printf("----------------------------------------\n");
    
    // Simulate various input strings for validation
    const char *test_inputs[] = {
        "12345",           // Valid integer
        "123.45",          // Valid float
        "abc123",          // Mixed
        "HELLO",           // All letters
        "hello world",     // Letters with space
        "",                // Empty
        "   ",             // Only spaces
        "user@email.com",  // Email-like
        "Password123!",    // Password-like
        "0xFF"             // Hex-like
    };
    
    int num_inputs = sizeof(test_inputs) / sizeof(test_inputs[0]);
    
    for (int i = 0; i < num_inputs; i++) {
        const char *input = test_inputs[i];
        printf("Input: \"%s\"\n", input);
        
        // Check if all digits (valid integer)
        int all_digits = 1;
        int has_content = 0;
        
        for (int j = 0; input[j]; j++) {
            has_content = 1;
            if (!isdigit(input[j])) {
                all_digits = 0;
                break;
            }
        }
        
        if (has_content && all_digits) {
            printf("  ✓ Valid integer\n");
        }
        
        // Check if valid float (digits with optional decimal point)
        int valid_float = 1;
        int decimal_count = 0;
        has_content = 0;
        
        for (int j = 0; input[j]; j++) {
            has_content = 1;
            if (input[j] == '.') {
                decimal_count++;
                if (decimal_count > 1) {
                    valid_float = 0;
                    break;
                }
            } else if (!isdigit(input[j])) {
                valid_float = 0;
                break;
            }
        }
        
        if (has_content && valid_float && strlen(input) > 0) {
            printf("  ✓ Valid float format\n");
        }
        
        // Check if all alphabetic
        int all_alpha = 1;
        has_content = 0;
        
        for (int j = 0; input[j]; j++) {
            has_content = 1;
            if (!isalpha(input[j])) {
                all_alpha = 0;
                break;
            }
        }
        
        if (has_content && all_alpha) {
            printf("  ✓ All alphabetic\n");
        }
        
        // Check if alphanumeric
        int all_alnum = 1;
        has_content = 0;
        
        for (int j = 0; input[j]; j++) {
            has_content = 1;
            if (!isalnum(input[j])) {
                all_alnum = 0;
                break;
            }
        }
        
        if (has_content && all_alnum) {
            printf("  ✓ Alphanumeric\n");
        }
        
        // Check if valid hex
        int valid_hex = 1;
        has_content = 0;
        int start_idx = 0;
        
        // Skip 0x prefix if present
        if (strlen(input) > 2 && input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) {
            start_idx = 2;
        }
        
        for (int j = start_idx; input[j]; j++) {
            has_content = 1;
            if (!isxdigit(input[j])) {
                valid_hex = 0;
                break;
            }
        }
        
        if (has_content && valid_hex && strlen(input) > (size_t)start_idx) {
            printf("  ✓ Valid hexadecimal\n");
        }
        
        printf("\n");
    }
}

void demonstrate_string_analysis(void) {
    printf("5. STRING ANALYSIS\n");
    printf("----------------------------------------\n");
    
    const char *sentences[] = {
        "Hello, World!",
        "The quick brown fox jumps over the lazy dog.",
        "Programming in C is fun and educational!",
        "12345 67890",
        "MixedCASE string WITH numbers 123"
    };
    
    int num_sentences = sizeof(sentences) / sizeof(sentences[0]);
    
    for (int i = 0; i < num_sentences; i++) {
        const char *sentence = sentences[i];
        printf("Analyzing: \"%s\"\n", sentence);
        
        // Comprehensive analysis
        int total_chars = strlen(sentence);
        int words = 0;
        int vowels = 0;
        int consonants = 0;
        int uppercase_letters = 0;
        int lowercase_letters = 0;
        int digits = 0;
        int punctuation = 0;
        int whitespace = 0;
        
        int in_word = 0;
        
        for (int j = 0; sentence[j]; j++) {
            char ch = sentence[j];
            
            if (isalpha(ch)) {
                // Count vowels and consonants
                char lower_ch = tolower(ch);
                if (lower_ch == 'a' || lower_ch == 'e' || lower_ch == 'i' || 
                    lower_ch == 'o' || lower_ch == 'u') {
                    vowels++;
                } else {
                    consonants++;
                }
                
                if (isupper(ch)) uppercase_letters++;
                if (islower(ch)) lowercase_letters++;
                
                if (!in_word) {
                    words++;
                    in_word = 1;
                }
            } else {
                in_word = 0;
                
                if (isdigit(ch)) digits++;
                else if (ispunct(ch)) punctuation++;
                else if (isspace(ch)) whitespace++;
            }
        }
        
        printf("  Length: %d characters\n", total_chars);
        printf("  Words: %d\n", words);
        printf("  Letters: %d (uppercase: %d, lowercase: %d)\n", 
               uppercase_letters + lowercase_letters, uppercase_letters, lowercase_letters);
        printf("  Vowels: %d, Consonants: %d\n", vowels, consonants);
        printf("  Digits: %d\n", digits);
        printf("  Punctuation: %d\n", punctuation);
        printf("  Whitespace: %d\n", whitespace);
        
        // Calculate readability metrics
        if (words > 0) {
            double avg_word_length = (double)(uppercase_letters + lowercase_letters) / words;
            printf("  Average word length: %.1f letters\n", avg_word_length);
        }
        
        printf("\n");
    }
}

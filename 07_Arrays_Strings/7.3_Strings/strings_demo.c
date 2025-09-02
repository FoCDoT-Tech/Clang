#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes for string operations
void print_string_info(const char* str);
void print_char_array(const char arr[], int size);
int manual_strlen(const char* str);
void manual_strcpy(char* dest, const char* src);
void reverse_string(char* str);
void to_uppercase(char* str);
void to_lowercase(char* str);
int count_vowels(const char* str);
int count_words(const char* str);
void remove_spaces(char* str);

int main() {
    printf("=== Strings Demo ===\n\n");
    
    // 1. STRING DECLARATION AND INITIALIZATION
    printf("1. STRING DECLARATION AND INITIALIZATION\n");
    printf("----------------------------------------\n");
    
    // Different ways to create strings
    char str1[] = "Hello World";                    // Array initialization
    char str2[20] = "Programming";                  // Fixed size array
    char str3[] = {'C', ' ', 'L', 'a', 'n', 'g', '\0'}; // Manual character array
    char str4[50] = {0};                           // Initialize all to null
    char *str5 = "String Literal";                 // String literal pointer
    
    printf("str1: \"%s\"\n", str1);
    printf("str2: \"%s\"\n", str2);
    printf("str3: \"%s\"\n", str3);
    printf("str4: \"%s\"\n", str4);
    printf("str5: \"%s\"\n", str5);
    
    // String information
    printf("\nString information:\n");
    print_string_info(str1);
    print_string_info(str2);
    print_string_info(str3);
    printf("\n");
    
    // 2. CHARACTER ARRAYS VS STRINGS
    printf("2. CHARACTER ARRAYS VS STRINGS\n");
    printf("----------------------------------------\n");
    
    char chars[] = {'A', 'B', 'C', 'D', 'E'};      // Character array (no null terminator)
    char string[] = {'A', 'B', 'C', 'D', 'E', '\0'}; // String (null-terminated)
    
    printf("Character array: ");
    print_char_array(chars, 5);
    printf("String: \"%s\"\n", string);
    
    printf("Attempting to print char array as string: \"%s\"\n", chars);
    printf("(Note: May print garbage after 'ABCDE' due to missing null terminator)\n\n");
    
    // 3. STRING INPUT AND OUTPUT
    printf("3. STRING INPUT AND OUTPUT\n");
    printf("----------------------------------------\n");
    
    char input_buffer[100];
    
    // Simulate user input (in real program, use scanf or fgets)
    strcpy(input_buffer, "Sample User Input");
    printf("Simulated input: \"%s\"\n", input_buffer);
    
    // Different output methods
    printf("Using printf: %s\n", input_buffer);
    printf("Using puts: ");
    puts(input_buffer);
    
    // Character by character output
    printf("Character by character: ");
    for (int i = 0; input_buffer[i] != '\0'; i++) {
        putchar(input_buffer[i]);
    }
    printf("\n\n");
    
    // 4. STRING MANIPULATION
    printf("4. STRING MANIPULATION\n");
    printf("----------------------------------------\n");
    
    char modifiable[] = "hello world programming";
    printf("Original: \"%s\"\n", modifiable);
    
    // Convert to uppercase
    char uppercase[50];
    strcpy(uppercase, modifiable);
    to_uppercase(uppercase);
    printf("Uppercase: \"%s\"\n", uppercase);
    
    // Convert to lowercase (already lowercase, but demonstrates function)
    char lowercase[50];
    strcpy(lowercase, "HELLO WORLD PROGRAMMING");
    to_lowercase(lowercase);
    printf("Lowercase: \"%s\"\n", lowercase);
    
    // Reverse string
    char reversed[50];
    strcpy(reversed, modifiable);
    reverse_string(reversed);
    printf("Reversed: \"%s\"\n", reversed);
    
    // Remove spaces
    char no_spaces[50];
    strcpy(no_spaces, modifiable);
    remove_spaces(no_spaces);
    printf("No spaces: \"%s\"\n", no_spaces);
    printf("\n");
    
    // 5. STRING ANALYSIS
    printf("5. STRING ANALYSIS\n");
    printf("----------------------------------------\n");
    
    const char* sample_text = "The Quick Brown Fox Jumps Over The Lazy Dog";
    printf("Sample text: \"%s\"\n", sample_text);
    
    printf("Length (manual): %d\n", manual_strlen(sample_text));
    printf("Length (library): %zu\n", strlen(sample_text));
    printf("Vowels: %d\n", count_vowels(sample_text));
    printf("Words: %d\n", count_words(sample_text));
    
    // Character frequency
    int char_count[256] = {0};  // ASCII character count
    for (int i = 0; sample_text[i] != '\0'; i++) {
        char_count[(unsigned char)sample_text[i]]++;
    }
    
    printf("Character frequencies:\n");
    for (int i = 'A'; i <= 'Z'; i++) {
        if (char_count[i] > 0) {
            printf("  %c: %d\n", i, char_count[i]);
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (char_count[i] > 0) {
            printf("  %c: %d\n", i, char_count[i]);
        }
    }
    printf("  Space: %d\n", char_count[' ']);
    printf("\n");
    
    // 6. STRING COPYING AND CONCATENATION
    printf("6. STRING COPYING AND CONCATENATION\n");
    printf("----------------------------------------\n");
    
    char source[] = "Hello";
    char dest[20];
    
    // Manual string copy
    manual_strcpy(dest, source);
    printf("Manual copy: \"%s\"\n", dest);
    
    // Library string copy
    strcpy(dest, "World");
    printf("Library copy: \"%s\"\n", dest);
    
    // String concatenation simulation (manual)
    char result[50] = "Hello";
    char append[] = " World!";
    
    // Find end of first string
    int len = strlen(result);
    for (int i = 0; append[i] != '\0'; i++) {
        result[len + i] = append[i];
    }
    result[len + strlen(append)] = '\0';  // Add null terminator
    
    printf("Manual concatenation: \"%s\"\n", result);
    printf("\n");
    
    // 7. STRING ARRAYS
    printf("7. STRING ARRAYS\n");
    printf("----------------------------------------\n");
    
    // Array of string pointers
    const char* days[] = {
        "Monday", "Tuesday", "Wednesday", "Thursday",
        "Friday", "Saturday", "Sunday"
    };
    
    printf("Days of the week:\n");
    for (int i = 0; i < 7; i++) {
        printf("  %d. %s\n", i + 1, days[i]);
    }
    
    // 2D character array for strings
    char months[][12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    
    printf("\nMonths of the year:\n");
    for (int i = 0; i < 12; i++) {
        printf("  %2d. %-10s (Length: %zu)\n", i + 1, months[i], strlen(months[i]));
    }
    printf("\n");
    
    // 8. PRACTICAL EXAMPLE - TEXT PROCESSING
    printf("8. PRACTICAL EXAMPLE - TEXT PROCESSING\n");
    printf("----------------------------------------\n");
    
    char document[] = "C programming is powerful and efficient. "
                     "It provides low-level control and high performance. "
                     "Many system programs are written in C.";
    
    printf("Document: \"%s\"\n", document);
    printf("\nDocument statistics:\n");
    printf("  Total characters: %zu\n", strlen(document));
    printf("  Total words: %d\n", count_words(document));
    printf("  Total vowels: %d\n", count_vowels(document));
    
    // Count sentences (periods)
    int sentences = 0;
    for (int i = 0; document[i] != '\0'; i++) {
        if (document[i] == '.') {
            sentences++;
        }
    }
    printf("  Total sentences: %d\n", sentences);
    
    // Find specific words
    const char* search_words[] = {"C", "programming", "system", "Java"};
    for (int i = 0; i < 4; i++) {
        if (strstr(document, search_words[i]) != NULL) {
            printf("  Found word: \"%s\"\n", search_words[i]);
        } else {
            printf("  Word not found: \"%s\"\n", search_words[i]);
        }
    }
    
    // 9. STRING MEMORY CONCEPTS
    printf("\n9. STRING MEMORY CONCEPTS\n");
    printf("----------------------------------------\n");
    
    char stack_string[] = "Stack String";
    char *literal_string = "Literal String";
    
    printf("Stack string: \"%s\" (Address: %p)\n", stack_string, (void*)stack_string);
    printf("Literal string: \"%s\" (Address: %p)\n", literal_string, (void*)literal_string);
    
    printf("Stack string is modifiable: ");
    stack_string[0] = 's';  // Change 'S' to 's'
    printf("\"%s\"\n", stack_string);
    
    printf("Literal string is read-only (cannot modify safely)\n");
    
    // Size information
    printf("\nMemory usage:\n");
    printf("  Stack string array size: %zu bytes\n", sizeof(stack_string));
    printf("  Pointer size: %zu bytes\n", sizeof(literal_string));
    printf("  Actual string lengths: %zu and %zu characters\n", 
           strlen(stack_string), strlen(literal_string));
    
    printf("\n=== Demo Complete ===\n");
    return 0;
}

// Function implementations

void print_string_info(const char* str) {
    printf("  \"%s\" - Length: %zu, Size needed: %zu bytes\n", 
           str, strlen(str), strlen(str) + 1);
}

void print_char_array(const char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c", arr[i]);
    }
    printf(" (no null terminator)\n");
}

int manual_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void manual_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Add null terminator
}

void reverse_string(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

void to_uppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

void to_lowercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

int count_vowels(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

int count_words(const char* str) {
    int words = 0;
    int in_word = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            if (!in_word) {
                words++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
    return words;
}

void remove_spaces(char* str) {
    int write_pos = 0;
    for (int read_pos = 0; str[read_pos] != '\0'; read_pos++) {
        if (str[read_pos] != ' ') {
            str[write_pos] = str[read_pos];
            write_pos++;
        }
    }
    str[write_pos] = '\0';
}

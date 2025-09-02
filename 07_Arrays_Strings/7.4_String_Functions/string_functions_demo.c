#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes for custom string utilities
void safe_strcpy(char* dest, const char* src, size_t dest_size);
void safe_strcat(char* dest, const char* src, size_t dest_size);
char* trim_whitespace(char* str);
int count_substring(const char* text, const char* pattern);
void replace_char(char* str, char old_char, char new_char);
void print_string_analysis(const char* str);

int main() {
    printf("=== String Functions Demo ===\n\n");
    
    // 1. STRING LENGTH FUNCTIONS
    printf("1. STRING LENGTH FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    const char* samples[] = {
        "Hello",
        "Programming",
        "",
        "C Language Learning",
        "A very long string with many characters to test length calculation"
    };
    
    for (int i = 0; i < 5; i++) {
        printf("strlen(\"%s\") = %zu\n", samples[i], strlen(samples[i]));
    }
    printf("\n");
    
    // 2. STRING COPY FUNCTIONS
    printf("2. STRING COPY FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    char dest1[50], dest2[50], dest3[50];
    const char* source = "Hello World Programming";
    
    // strcpy - copies entire string
    strcpy(dest1, source);
    printf("strcpy result: \"%s\"\n", dest1);
    
    // strncpy - copies n characters
    strncpy(dest2, source, 10);
    dest2[10] = '\0';  // Ensure null termination
    printf("strncpy(10 chars): \"%s\"\n", dest2);
    
    // Safe copy demonstration
    safe_strcpy(dest3, source, sizeof(dest3));
    printf("Safe copy: \"%s\"\n", dest3);
    printf("\n");
    
    // 3. STRING CONCATENATION FUNCTIONS
    printf("3. STRING CONCATENATION FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    char concat1[100] = "Hello";
    char concat2[100] = "Good";
    char concat3[100] = "Start";
    
    // strcat - concatenate strings
    strcat(concat1, " World");
    printf("After strcat: \"%s\"\n", concat1);
    
    strcat(concat1, "!");
    printf("After second strcat: \"%s\"\n", concat1);
    
    // strncat - concatenate n characters
    strncat(concat2, " Morning Everyone", 8);
    printf("After strncat(8): \"%s\"\n", concat2);
    
    // Safe concatenation
    safe_strcat(concat3, " Programming", sizeof(concat3));
    safe_strcat(concat3, " Journey", sizeof(concat3));
    printf("Safe concatenation: \"%s\"\n", concat3);
    printf("\n");
    
    // 4. STRING COMPARISON FUNCTIONS
    printf("4. STRING COMPARISON FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    const char* str_pairs[][2] = {
        {"apple", "banana"},
        {"hello", "hello"},
        {"zebra", "apple"},
        {"ABC", "abc"},
        {"test123", "test124"}
    };
    
    for (int i = 0; i < 5; i++) {
        const char* s1 = str_pairs[i][0];
        const char* s2 = str_pairs[i][1];
        int result = strcmp(s1, s2);
        
        printf("strcmp(\"%s\", \"%s\") = %d ", s1, s2, result);
        if (result < 0) printf("(s1 < s2)\n");
        else if (result > 0) printf("(s1 > s2)\n");
        else printf("(s1 == s2)\n");
    }
    
    // strncmp example
    printf("\nstrncmp examples:\n");
    printf("strncmp(\"hello\", \"help\", 3) = %d\n", strncmp("hello", "help", 3));
    printf("strncmp(\"hello\", \"help\", 4) = %d\n", strncmp("hello", "help", 4));
    printf("\n");
    
    // 5. STRING SEARCH FUNCTIONS
    printf("5. STRING SEARCH FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    const char* search_text = "The quick brown fox jumps over the lazy dog";
    printf("Search text: \"%s\"\n", search_text);
    
    // strchr - find character
    char* found_char = strchr(search_text, 'q');
    if (found_char) {
        printf("strchr('q'): Found at position %ld\n", found_char - search_text);
    }
    
    found_char = strchr(search_text, 'z');
    if (found_char) {
        printf("strchr('z'): Found at position %ld\n", found_char - search_text);
    }
    
    // strrchr - find last occurrence
    found_char = strrchr(search_text, 'o');
    if (found_char) {
        printf("strrchr('o'): Last 'o' at position %ld\n", found_char - search_text);
    }
    
    // strstr - find substring
    char* found_str = strstr(search_text, "fox");
    if (found_str) {
        printf("strstr(\"fox\"): Found at position %ld\n", found_str - search_text);
    }
    
    found_str = strstr(search_text, "cat");
    if (found_str) {
        printf("strstr(\"cat\"): Found\n");
    } else {
        printf("strstr(\"cat\"): Not found\n");
    }
    printf("\n");
    
    // 6. FORMATTED STRING FUNCTIONS
    printf("6. FORMATTED STRING FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    char formatted[200];
    int age = 25;
    double height = 5.9;
    const char* name = "Alice";
    
    // sprintf - format string
    sprintf(formatted, "Name: %s, Age: %d, Height: %.1f ft", name, age, height);
    printf("sprintf result: \"%s\"\n", formatted);
    
    // More complex formatting
    sprintf(formatted, "Date: %02d/%02d/%04d, Time: %02d:%02d", 
            15, 8, 2024, 14, 30);
    printf("Date formatting: \"%s\"\n", formatted);
    
    // sscanf - parse string
    const char* data = "John 30 6.2";
    char parsed_name[50];
    int parsed_age;
    double parsed_height;
    
    int items_parsed = sscanf(data, "%s %d %lf", parsed_name, &parsed_age, &parsed_height);
    printf("sscanf parsed %d items from \"%s\":\n", items_parsed, data);
    printf("  Name: %s, Age: %d, Height: %.1f\n", parsed_name, parsed_age, parsed_height);
    
    // Parse CSV-like data
    const char* csv_line = "Apple,1.50,Red,Fresh";
    char product[50], color[20], condition[20];
    double price;
    
    sscanf(csv_line, "%[^,],%lf,%[^,],%s", product, &price, color, condition);
    printf("CSV parsing: Product=%s, Price=%.2f, Color=%s, Condition=%s\n", 
           product, price, color, condition);
    printf("\n");
    
    // 7. PRACTICAL STRING PROCESSING
    printf("7. PRACTICAL STRING PROCESSING\n");
    printf("----------------------------------------\n");
    
    // Text analysis
    const char* document = "C programming language was developed by Dennis Ritchie. "
                          "It is widely used for system programming and embedded systems. "
                          "C provides low-level access to memory and efficient performance.";
    
    printf("Document analysis:\n");
    print_string_analysis(document);
    
    // Word frequency (simplified)
    const char* keywords[] = {"C", "programming", "system", "memory", "performance"};
    printf("\nKeyword frequency:\n");
    for (int i = 0; i < 5; i++) {
        int count = count_substring(document, keywords[i]);
        printf("  \"%s\": %d occurrences\n", keywords[i], count);
    }
    printf("\n");
    
    // 8. STRING MANIPULATION UTILITIES
    printf("8. STRING MANIPULATION UTILITIES\n");
    printf("----------------------------------------\n");
    
    char manipulate[] = "  Hello World Programming  ";
    printf("Original: \"%s\"\n", manipulate);
    
    // Trim whitespace
    char* trimmed = trim_whitespace(manipulate);
    printf("Trimmed: \"%s\"\n", trimmed);
    
    // Replace characters
    char replace_demo[] = "Hello-World-Programming";
    printf("Before replace: \"%s\"\n", replace_demo);
    replace_char(replace_demo, '-', ' ');
    printf("After replace: \"%s\"\n", replace_demo);
    
    // Case conversion using standard library
    char case_demo[] = "Mixed Case String";
    printf("Original: \"%s\"\n", case_demo);
    
    for (int i = 0; case_demo[i]; i++) {
        case_demo[i] = tolower(case_demo[i]);
    }
    printf("Lowercase: \"%s\"\n", case_demo);
    
    for (int i = 0; case_demo[i]; i++) {
        case_demo[i] = toupper(case_demo[i]);
    }
    printf("Uppercase: \"%s\"\n", case_demo);
    printf("\n");
    
    // 9. PRACTICAL EXAMPLE - LOG PARSER
    printf("9. PRACTICAL EXAMPLE - LOG PARSER\n");
    printf("----------------------------------------\n");
    
    const char* log_entries[] = {
        "2024-08-15 10:30:25 INFO User login successful",
        "2024-08-15 10:31:15 ERROR Database connection failed",
        "2024-08-15 10:32:00 WARN Memory usage high",
        "2024-08-15 10:33:45 INFO File uploaded successfully"
    };
    
    printf("Log Analysis:\n");
    for (int i = 0; i < 4; i++) {
        char date[20], time[20], level[10], message[100];
        
        // Parse log entry
        sscanf(log_entries[i], "%s %s %s %[^\n]", date, time, level, message);
        
        printf("Entry %d:\n", i + 1);
        printf("  Date: %s\n", date);
        printf("  Time: %s\n", time);
        printf("  Level: %s\n", level);
        printf("  Message: %s\n", message);
        
        // Check for specific conditions
        if (strstr(level, "ERROR")) {
            printf("  ⚠️  ERROR detected!\n");
        } else if (strstr(level, "WARN")) {
            printf("  ⚠️  WARNING detected!\n");
        }
        printf("\n");
    }
    
    // 10. STRING VALIDATION AND UTILITIES
    printf("10. STRING VALIDATION AND UTILITIES\n");
    printf("----------------------------------------\n");
    
    const char* test_strings[] = {
        "hello@example.com",
        "user123",
        "192.168.1.1",
        "2024-08-15",
        "+1-555-123-4567"
    };
    
    printf("String pattern analysis:\n");
    for (int i = 0; i < 5; i++) {
        const char* str = test_strings[i];
        printf("\"%s\":\n", str);
        
        // Check for email pattern (simplified)
        if (strchr(str, '@') && strchr(str, '.')) {
            printf("  Looks like email\n");
        }
        
        // Check for IP pattern (simplified)
        if (strstr(str, ".") && isdigit(str[0])) {
            printf("  Looks like IP address\n");
        }
        
        // Check for date pattern
        if (strlen(str) == 10 && str[4] == '-' && str[7] == '-') {
            printf("  Looks like date (YYYY-MM-DD)\n");
        }
        
        // Check for phone pattern
        if (strchr(str, '-') && (str[0] == '+' || isdigit(str[0]))) {
            printf("  Looks like phone number\n");
        }
        printf("\n");
    }
    
    printf("=== Demo Complete ===\n");
    return 0;
}

// Function implementations

void safe_strcpy(char* dest, const char* src, size_t dest_size) {
    if (dest_size > 0) {
        strncpy(dest, src, dest_size - 1);
        dest[dest_size - 1] = '\0';
    }
}

void safe_strcat(char* dest, const char* src, size_t dest_size) {
    size_t dest_len = strlen(dest);
    if (dest_len < dest_size - 1) {
        strncat(dest, src, dest_size - dest_len - 1);
    }
}

char* trim_whitespace(char* str) {
    // Trim leading whitespace
    while (isspace(*str)) {
        str++;
    }
    
    // Trim trailing whitespace
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';
    
    return str;
}

int count_substring(const char* text, const char* pattern) {
    int count = 0;
    const char* pos = text;
    
    while ((pos = strstr(pos, pattern)) != NULL) {
        count++;
        pos += strlen(pattern);
    }
    
    return count;
}

void replace_char(char* str, char old_char, char new_char) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == old_char) {
            str[i] = new_char;
        }
    }
}

void print_string_analysis(const char* str) {
    printf("  Length: %zu characters\n", strlen(str));
    
    int words = 0, sentences = 0, vowels = 0, digits = 0;
    int in_word = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        
        // Count words
        if (!isspace(c) && !in_word) {
            words++;
            in_word = 1;
        } else if (isspace(c)) {
            in_word = 0;
        }
        
        // Count sentences
        if (c == '.' || c == '!' || c == '?') {
            sentences++;
        }
        
        // Count vowels
        if (strchr("aeiouAEIOU", c)) {
            vowels++;
        }
        
        // Count digits
        if (isdigit(c)) {
            digits++;
        }
    }
    
    printf("  Words: %d\n", words);
    printf("  Sentences: %d\n", sentences);
    printf("  Vowels: %d\n", vowels);
    printf("  Digits: %d\n", digits);
}

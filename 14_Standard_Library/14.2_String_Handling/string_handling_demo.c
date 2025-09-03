#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function prototypes
void demonstrate_string_length(void);
void demonstrate_string_copy(void);
void demonstrate_string_concatenation(void);
void demonstrate_string_comparison(void);
void demonstrate_string_search(void);
void demonstrate_string_tokenization(void);
void demonstrate_memory_operations(void);
void demonstrate_error_handling(void);

int main(void) {
    printf("=== String Handling Demo ===\n\n");
    
    demonstrate_string_length();
    demonstrate_string_copy();
    demonstrate_string_concatenation();
    demonstrate_string_comparison();
    demonstrate_string_search();
    demonstrate_string_tokenization();
    demonstrate_memory_operations();
    demonstrate_error_handling();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_string_length(void) {
    printf("1. STRING LENGTH\n");
    printf("----------------------------------------\n");
    
    const char *strings[] = {
        "Hello",
        "World!",
        "",
        "This is a longer string with spaces",
        "Unicode: αβγ"
    };
    
    for (int i = 0; i < 5; i++) {
        printf("String: \"%s\" -> Length: %zu\n", strings[i], strlen(strings[i]));
    }
    
    // Demonstrate with arrays
    char buffer[100] = "Dynamic content";
    printf("Buffer content: \"%s\" -> Length: %zu\n", buffer, strlen(buffer));
    
    printf("\n");
}

void demonstrate_string_copy(void) {
    printf("2. STRING COPY\n");
    printf("----------------------------------------\n");
    
    char dest[50];
    const char *source = "Hello, World!";
    
    // strcpy - copy entire string
    strcpy(dest, source);
    printf("strcpy result: \"%s\"\n", dest);
    
    // strncpy - copy n characters
    char partial[10];
    strncpy(partial, source, 5);
    partial[5] = '\0';  // Ensure null termination
    printf("strncpy(5) result: \"%s\"\n", partial);
    
    // Safe copying with bounds checking
    char safe_dest[10];
    strncpy(safe_dest, source, sizeof(safe_dest) - 1);
    safe_dest[sizeof(safe_dest) - 1] = '\0';
    printf("Safe copy result: \"%s\"\n", safe_dest);
    
    // Demonstrate potential issue with strncpy
    char no_null[5];
    strncpy(no_null, "12345", 5);  // No null terminator added
    printf("strncpy without null terminator (unsafe): ");
    for (int i = 0; i < 5; i++) {
        printf("%c", no_null[i]);
    }
    printf("\n");
    
    printf("\n");
}

void demonstrate_string_concatenation(void) {
    printf("3. STRING CONCATENATION\n");
    printf("----------------------------------------\n");
    
    char result[100] = "Hello";
    const char *addition = ", World!";
    
    // strcat - concatenate strings
    strcat(result, addition);
    printf("strcat result: \"%s\"\n", result);
    
    // strncat - concatenate n characters
    char limited[20] = "Start";
    strncat(limited, " and more text", 5);
    printf("strncat(5) result: \"%s\"\n", limited);
    
    // Building strings step by step
    char sentence[100] = "";
    strcat(sentence, "The");
    strcat(sentence, " quick");
    strcat(sentence, " brown");
    strcat(sentence, " fox");
    printf("Built sentence: \"%s\"\n", sentence);
    
    // Safe concatenation
    char safe_buffer[15] = "Start";
    size_t remaining = sizeof(safe_buffer) - strlen(safe_buffer) - 1;
    strncat(safe_buffer, " with more text", remaining);
    printf("Safe concatenation: \"%s\"\n", safe_buffer);
    
    printf("\n");
}

void demonstrate_string_comparison(void) {
    printf("4. STRING COMPARISON\n");
    printf("----------------------------------------\n");
    
    const char *str1 = "apple";
    const char *str2 = "banana";
    const char *str3 = "apple";
    const char *str4 = "Apple";
    
    // strcmp - compare entire strings
    printf("strcmp(\"%s\", \"%s\") = %d\n", str1, str2, strcmp(str1, str2));
    printf("strcmp(\"%s\", \"%s\") = %d\n", str1, str3, strcmp(str1, str3));
    printf("strcmp(\"%s\", \"%s\") = %d\n", str1, str4, strcmp(str1, str4));
    
    // strncmp - compare n characters
    printf("strncmp(\"%s\", \"%s\", 3) = %d\n", str1, str2, strncmp(str1, str2, 3));
    
    // Practical comparison usage
    if (strcmp(str1, str3) == 0) {
        printf("\"%s\" and \"%s\" are equal\n", str1, str3);
    }
    
    if (strcmp(str1, str2) < 0) {
        printf("\"%s\" comes before \"%s\" alphabetically\n", str1, str2);
    }
    
    // Case-insensitive comparison (manual implementation)
    printf("Manual case-insensitive comparison:\n");
    char lower1[20], lower2[20];
    strcpy(lower1, str1);
    strcpy(lower2, str4);
    
    // Convert to lowercase (simple version)
    for (int i = 0; lower1[i]; i++) {
        if (lower1[i] >= 'A' && lower1[i] <= 'Z') {
            lower1[i] += 32;
        }
    }
    for (int i = 0; lower2[i]; i++) {
        if (lower2[i] >= 'A' && lower2[i] <= 'Z') {
            lower2[i] += 32;
        }
    }
    
    if (strcmp(lower1, lower2) == 0) {
        printf("\"%s\" and \"%s\" are equal (case-insensitive)\n", str1, str4);
    }
    
    printf("\n");
}

void demonstrate_string_search(void) {
    printf("5. STRING SEARCH\n");
    printf("----------------------------------------\n");
    
    const char *text = "The quick brown fox jumps over the lazy dog";
    
    // strchr - find first occurrence of character
    char *pos = strchr(text, 'q');
    if (pos) {
        printf("First 'q' found at position: %ld\n", pos - text);
        printf("Substring from 'q': \"%s\"\n", pos);
    }
    
    // strrchr - find last occurrence of character
    pos = strrchr(text, 'o');
    if (pos) {
        printf("Last 'o' found at position: %ld\n", pos - text);
    }
    
    // strstr - find substring
    pos = strstr(text, "brown");
    if (pos) {
        printf("\"brown\" found at position: %ld\n", pos - text);
        printf("Substring from \"brown\": \"%s\"\n", pos);
    }
    
    // Search for non-existent substring
    pos = strstr(text, "elephant");
    if (pos == NULL) {
        printf("\"elephant\" not found in text\n");
    }
    
    // Multiple occurrences
    const char *search_text = "the cat and the dog";
    pos = strstr(search_text, "the");
    printf("First \"the\" in \"%s\" at position: %ld\n", search_text, pos - search_text);
    
    // Find second occurrence
    pos = strstr(pos + 1, "the");
    if (pos) {
        printf("Second \"the\" at position: %ld\n", pos - search_text);
    }
    
    printf("\n");
}

void demonstrate_string_tokenization(void) {
    printf("6. STRING TOKENIZATION\n");
    printf("----------------------------------------\n");
    
    // strtok modifies the original string, so use a copy
    char text[] = "apple,banana;orange:grape";
    const char *delimiters = ",;:";
    
    printf("Original string: \"%s\"\n", text);
    printf("Delimiters: \"%s\"\n", delimiters);
    printf("Tokens:\n");
    
    char *token = strtok(text, delimiters);
    int token_count = 0;
    
    while (token != NULL) {
        printf("  %d: \"%s\"\n", ++token_count, token);
        token = strtok(NULL, delimiters);
    }
    
    // Tokenize CSV-like data
    char csv_data[] = "John,25,Engineer;Jane,30,Doctor;Bob,28,Artist";
    char csv_copy[100];
    strcpy(csv_copy, csv_data);
    
    printf("\nCSV-like data parsing:\n");
    printf("Data: \"%s\"\n", csv_data);
    
    char *record = strtok(csv_copy, ";");
    int record_num = 1;
    
    while (record != NULL) {
        printf("Record %d: %s\n", record_num++, record);
        
        // Parse individual record
        char record_copy[50];
        strcpy(record_copy, record);
        
        char *field = strtok(record_copy, ",");
        int field_num = 1;
        printf("  Fields: ");
        
        while (field != NULL) {
            printf("[%d]%s ", field_num++, field);
            field = strtok(NULL, ",");
        }
        printf("\n");
        
        record = strtok(NULL, ";");
    }
    
    printf("\n");
}

void demonstrate_memory_operations(void) {
    printf("7. MEMORY OPERATIONS\n");
    printf("----------------------------------------\n");
    
    // memset - set memory to value
    char buffer[20];
    memset(buffer, 'A', 10);
    buffer[10] = '\0';
    printf("memset result: \"%s\"\n", buffer);
    
    // memcpy - copy memory blocks
    int source_array[] = {1, 2, 3, 4, 5};
    int dest_array[5];
    
    memcpy(dest_array, source_array, sizeof(source_array));
    printf("memcpy result: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dest_array[i]);
    }
    printf("\n");
    
    // memmove - safe memory move (handles overlapping regions)
    char overlap[] = "ABCDEFGHIJ";
    printf("Before memmove: \"%s\"\n", overlap);
    
    memmove(overlap + 2, overlap, 5);  // Move first 5 chars to position 2
    printf("After memmove: \"%s\"\n", overlap);
    
    // memcmp - compare memory blocks
    char block1[] = "Hello";
    char block2[] = "Hello";
    char block3[] = "World";
    
    printf("memcmp(\"%s\", \"%s\") = %d\n", block1, block2, memcmp(block1, block2, 5));
    printf("memcmp(\"%s\", \"%s\") = %d\n", block1, block3, memcmp(block1, block3, 5));
    
    // memchr - find byte in memory
    char data[] = "Find the X in this text";
    char *found = (char*)memchr(data, 'X', strlen(data));
    if (found) {
        printf("Found 'X' at position: %ld\n", found - data);
    }
    
    // Binary data operations
    unsigned char binary_data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    unsigned char binary_copy[5];
    
    memcpy(binary_copy, binary_data, 5);
    printf("Binary data copied: ");
    for (int i = 0; i < 5; i++) {
        printf("0x%02X ", binary_copy[i]);
    }
    printf("\n");
    
    printf("\n");
}

void demonstrate_error_handling(void) {
    printf("8. ERROR HANDLING\n");
    printf("----------------------------------------\n");
    
    // strerror - get error message string
    printf("Error messages for common error codes:\n");
    
    for (int err = 1; err <= 5; err++) {
        printf("Error %d: %s\n", err, strerror(err));
    }
    
    // Simulate an error condition
    FILE *file = fopen("nonexistent_file.txt", "r");
    if (file == NULL) {
        printf("File open failed: %s\n", strerror(errno));
    }
    
    // String processing error checking
    char small_buffer[5];
    const char *large_string = "This string is too long";
    
    // Demonstrate safe string handling
    if (strlen(large_string) >= sizeof(small_buffer)) {
        printf("Warning: String too long for buffer\n");
        printf("String length: %zu, Buffer size: %zu\n", 
               strlen(large_string), sizeof(small_buffer));
        
        // Safe copy
        strncpy(small_buffer, large_string, sizeof(small_buffer) - 1);
        small_buffer[sizeof(small_buffer) - 1] = '\0';
        printf("Truncated string: \"%s\"\n", small_buffer);
    }
    
    printf("\n");
}

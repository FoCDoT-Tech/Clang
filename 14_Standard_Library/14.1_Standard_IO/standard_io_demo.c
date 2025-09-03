#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void demonstrate_console_io(void);
void demonstrate_file_operations(void);
void demonstrate_formatted_io(void);
void demonstrate_file_positioning(void);
void demonstrate_error_handling(void);
void demonstrate_binary_io(void);

int main(void) {
    printf("=== Standard I/O Demo ===\n\n");
    
    demonstrate_console_io();
    demonstrate_formatted_io();
    demonstrate_file_operations();
    demonstrate_file_positioning();
    demonstrate_binary_io();
    demonstrate_error_handling();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_console_io(void) {
    printf("1. CONSOLE I/O\n");
    printf("----------------------------------------\n");
    
    // Character I/O
    printf("Character output with putchar(): ");
    putchar('H');
    putchar('e');
    putchar('l');
    putchar('l');
    putchar('o');
    putchar('\n');
    
    // String output
    puts("String output with puts()");
    
    // Formatted output variations
    printf("Integer: %d, Float: %.2f, String: %s\n", 42, 3.14159, "Hello");
    printf("Hex: 0x%X, Octal: %o, Scientific: %e\n", 255, 64, 1234.5);
    
    // Field width and alignment
    printf("Right-aligned: '%10s'\n", "test");
    printf("Left-aligned:  '%-10s'\n", "test");
    printf("Zero-padded:   '%05d'\n", 42);
    
    printf("\n");
}

void demonstrate_formatted_io(void) {
    printf("2. FORMATTED I/O\n");
    printf("----------------------------------------\n");
    
    // sprintf - format to string
    char buffer[100];
    int count = sprintf(buffer, "Formatted: %d + %d = %d", 5, 3, 8);
    printf("sprintf result: %s (wrote %d chars)\n", buffer, count);
    
    // snprintf - safe formatting
    char safe_buffer[20];
    snprintf(safe_buffer, sizeof(safe_buffer), "Long string that gets truncated");
    printf("snprintf result: %s\n", safe_buffer);
    
    // sscanf - parse from string
    const char *data = "123 45.67 hello";
    int num;
    float fnum;
    char str[20];
    int parsed = sscanf(data, "%d %f %s", &num, &fnum, str);
    printf("sscanf parsed %d items: %d, %.2f, %s\n", parsed, num, fnum, str);
    
    printf("\n");
}

void demonstrate_file_operations(void) {
    printf("3. FILE OPERATIONS\n");
    printf("----------------------------------------\n");
    
    const char *filename = "test_file.txt";
    FILE *file;
    
    // Write to file
    file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "Line 1: Hello, File!\n");
        fprintf(file, "Line 2: Number %d\n", 42);
        fprintf(file, "Line 3: Float %.2f\n", 3.14);
        fclose(file);
        printf("Successfully wrote to %s\n", filename);
    }
    
    // Read from file
    file = fopen(filename, "r");
    if (file != NULL) {
        char line[100];
        int line_num = 1;
        
        printf("Reading from %s:\n", filename);
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("  %d: %s", line_num++, line);
        }
        fclose(file);
    }
    
    // Append to file
    file = fopen(filename, "a");
    if (file != NULL) {
        fprintf(file, "Line 4: Appended text\n");
        fclose(file);
        printf("Appended to %s\n", filename);
    }
    
    // Clean up
    remove(filename);
    printf("Cleaned up %s\n", filename);
    
    printf("\n");
}

void demonstrate_file_positioning(void) {
    printf("4. FILE POSITIONING\n");
    printf("----------------------------------------\n");
    
    const char *filename = "position_test.txt";
    FILE *file;
    
    // Create test file
    file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "0123456789ABCDEFGHIJ");
        fclose(file);
    }
    
    // Demonstrate positioning
    file = fopen(filename, "r");
    if (file != NULL) {
        char ch;
        
        // Read from beginning
        ch = fgetc(file);
        printf("Character at position 0: %c\n", ch);
        printf("Current position: %ld\n", ftell(file));
        
        // Seek to middle
        fseek(file, 10, SEEK_SET);
        ch = fgetc(file);
        printf("Character at position 10: %c\n", ch);
        printf("Current position: %ld\n", ftell(file));
        
        // Seek relative
        fseek(file, -5, SEEK_CUR);
        ch = fgetc(file);
        printf("Character 5 positions back: %c\n", ch);
        
        // Seek from end
        fseek(file, -3, SEEK_END);
        ch = fgetc(file);
        printf("Character 3 from end: %c\n", ch);
        
        // Rewind
        rewind(file);
        ch = fgetc(file);
        printf("After rewind: %c\n", ch);
        
        fclose(file);
    }
    
    remove(filename);
    printf("\n");
}

void demonstrate_binary_io(void) {
    printf("5. BINARY I/O\n");
    printf("----------------------------------------\n");
    
    const char *filename = "binary_test.dat";
    FILE *file;
    
    // Data to write
    int numbers[] = {1, 2, 3, 4, 5};
    double values[] = {1.1, 2.2, 3.3};
    
    // Write binary data
    file = fopen(filename, "wb");
    if (file != NULL) {
        size_t written;
        
        written = fwrite(numbers, sizeof(int), 5, file);
        printf("Wrote %zu integers\n", written);
        
        written = fwrite(values, sizeof(double), 3, file);
        printf("Wrote %zu doubles\n", written);
        
        fclose(file);
    }
    
    // Read binary data
    file = fopen(filename, "rb");
    if (file != NULL) {
        int read_numbers[5];
        double read_values[3];
        size_t read;
        
        read = fread(read_numbers, sizeof(int), 5, file);
        printf("Read %zu integers: ", read);
        for (int i = 0; i < 5; i++) {
            printf("%d ", read_numbers[i]);
        }
        printf("\n");
        
        read = fread(read_values, sizeof(double), 3, file);
        printf("Read %zu doubles: ", read);
        for (int i = 0; i < 3; i++) {
            printf("%.1f ", read_values[i]);
        }
        printf("\n");
        
        fclose(file);
    }
    
    remove(filename);
    printf("\n");
}

void demonstrate_error_handling(void) {
    printf("6. ERROR HANDLING\n");
    printf("----------------------------------------\n");
    
    FILE *file;
    
    // Try to open non-existent file
    file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        printf("Failed to open nonexistent.txt\n");
        perror("Error details");
    }
    
    // Create a file and demonstrate error checking
    const char *filename = "error_test.txt";
    file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "Test data\n");
        
        // Check for errors
        if (ferror(file)) {
            printf("Write error occurred\n");
        } else {
            printf("Write successful\n");
        }
        
        fclose(file);
    }
    
    // Read and check EOF
    file = fopen(filename, "r");
    if (file != NULL) {
        char buffer[100];
        
        fgets(buffer, sizeof(buffer), file);
        printf("Read: %s", buffer);
        
        // Try to read past EOF
        fgets(buffer, sizeof(buffer), file);
        if (feof(file)) {
            printf("Reached end of file\n");
        }
        
        if (ferror(file)) {
            printf("Read error occurred\n");
        }
        
        fclose(file);
    }
    
    remove(filename);
    printf("\n");
}

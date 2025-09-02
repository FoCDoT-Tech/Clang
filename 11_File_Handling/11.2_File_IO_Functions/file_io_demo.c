#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for binary I/O demonstration
typedef struct {
    int id;
    char name[32];
    float salary;
    int department;
} Employee;

// Function prototypes
void demonstrate_character_io(void);
void demonstrate_string_io(void);
void demonstrate_formatted_io(void);
void demonstrate_binary_io(void);
void demonstrate_performance_comparison(void);
void demonstrate_error_handling(void);
void demonstrate_practical_examples(void);

// Utility functions
void create_sample_text_file(void);
void create_sample_binary_file(void);
void cleanup_test_files(void);

int main(void) {
    printf("=== File I/O Functions Demo ===\n\n");
    
    // Create sample files for demonstrations
    create_sample_text_file();
    create_sample_binary_file();
    
    demonstrate_character_io();
    demonstrate_string_io();
    demonstrate_formatted_io();
    demonstrate_binary_io();
    demonstrate_performance_comparison();
    demonstrate_error_handling();
    demonstrate_practical_examples();
    
    // Clean up test files
    cleanup_test_files();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_character_io(void) {
    printf("1. CHARACTER I/O FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    printf("Using fgetc() and fputc() for character operations:\n\n");
    
    // Reading characters with fgetc()
    printf("1. Reading characters with fgetc():\n");
    FILE *file = fopen("sample.txt", "r");
    if (file) {
        printf("   First 20 characters: ");
        for (int i = 0; i < 20; i++) {
            int c = fgetc(file);
            if (c == EOF) break;
            if (c == '\n') {
                printf("\\n");
            } else {
                printf("%c", c);
            }
        }
        printf("\n");
        fclose(file);
    }
    
    // Writing characters with fputc()
    printf("2. Writing characters with fputc():\n");
    file = fopen("char_output.txt", "w");
    if (file) {
        const char *message = "Hello, Character I/O!";
        for (int i = 0; message[i]; i++) {
            fputc(message[i], file);
        }
        fputc('\n', file);
        fclose(file);
        printf("   ✓ Written message using fputc()\n");
    }
    
    // Character counting example
    printf("3. Counting characters in file:\n");
    file = fopen("sample.txt", "r");
    if (file) {
        int char_count = 0;
        int line_count = 0;
        int c;
        
        while ((c = fgetc(file)) != EOF) {
            char_count++;
            if (c == '\n') line_count++;
        }
        
        printf("   Characters: %d, Lines: %d\n", char_count, line_count);
        fclose(file);
    }
    
    // Using ungetc()
    printf("4. Using ungetc() to push back character:\n");
    file = fopen("sample.txt", "r");
    if (file) {
        int c1 = fgetc(file);
        int c2 = fgetc(file);
        printf("   Read: '%c' and '%c'\n", c1, c2);
        
        ungetc(c2, file);  // Push back second character
        int c3 = fgetc(file);
        printf("   After ungetc, next read: '%c'\n", c3);
        fclose(file);
    }
    
    printf("\n");
}

void demonstrate_string_io(void) {
    printf("2. STRING I/O FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    printf("Using fgets() and fputs() for string operations:\n\n");
    
    // Reading lines with fgets()
    printf("1. Reading lines with fgets():\n");
    FILE *file = fopen("sample.txt", "r");
    if (file) {
        char buffer[256];
        int line_num = 1;
        
        printf("   File contents (first 3 lines):\n");
        while (fgets(buffer, sizeof(buffer), file) && line_num <= 3) {
            // Remove newline for cleaner output
            buffer[strcspn(buffer, "\n")] = '\0';
            printf("   Line %d: %s\n", line_num++, buffer);
        }
        fclose(file);
    }
    
    // Writing lines with fputs()
    printf("2. Writing lines with fputs():\n");
    file = fopen("string_output.txt", "w");
    if (file) {
        fputs("First line written with fputs()\n", file);
        fputs("Second line - no automatic newline\n", file);
        fputs("Third line with manual newline\n", file);
        fclose(file);
        printf("   ✓ Written 3 lines using fputs()\n");
    }
    
    // Safe string reading with size limit
    printf("3. Safe string reading with buffer limits:\n");
    file = fopen("string_output.txt", "r");
    if (file) {
        char small_buffer[20];  // Intentionally small buffer
        
        printf("   Reading with small buffer (20 chars):\n");
        while (fgets(small_buffer, sizeof(small_buffer), file)) {
            printf("   Chunk: '%s'\n", small_buffer);
        }
        fclose(file);
    }
    
    // Processing CSV-like data
    printf("4. Processing structured text data:\n");
    file = fopen("csv_data.txt", "w");
    if (file) {
        fputs("Name,Age,City\n", file);
        fputs("Alice,25,New York\n", file);
        fputs("Bob,30,San Francisco\n", file);
        fputs("Carol,28,Chicago\n", file);
        fclose(file);
    }
    
    file = fopen("csv_data.txt", "r");
    if (file) {
        char line[256];
        int row = 0;
        
        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = '\0';  // Remove newline
            printf("   Row %d: %s\n", row++, line);
        }
        fclose(file);
    }
    
    printf("\n");
}

void demonstrate_formatted_io(void) {
    printf("3. FORMATTED I/O FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    printf("Using fscanf() and fprintf() for formatted data:\n\n");
    
    // Writing formatted data with fprintf()
    printf("1. Writing formatted data with fprintf():\n");
    FILE *file = fopen("formatted_data.txt", "w");
    if (file) {
        fprintf(file, "Student Records\n");
        fprintf(file, "===============\n");
        fprintf(file, "%3s %-15s %5s %6s\n", "ID", "Name", "Grade", "Score");
        fprintf(file, "%3d %-15s %5c %6.1f\n", 101, "Alice Johnson", 'A', 95.5);
        fprintf(file, "%3d %-15s %5c %6.1f\n", 102, "Bob Smith", 'B', 87.2);
        fprintf(file, "%3d %-15s %5c %6.1f\n", 103, "Carol Davis", 'A', 92.8);
        fclose(file);
        printf("   ✓ Written formatted student records\n");
    }
    
    // Reading formatted data with fscanf()
    printf("2. Reading formatted data with fscanf():\n");
    file = fopen("formatted_data.txt", "r");
    if (file) {
        char buffer[256];
        
        // Skip header lines
        fgets(buffer, sizeof(buffer), file);  // "Student Records"
        fgets(buffer, sizeof(buffer), file);  // "==============="
        fgets(buffer, sizeof(buffer), file);  // Column headers
        
        printf("   Parsed student data:\n");
        int id;
        char name[20];
        char grade;
        float score;
        
        while (fscanf(file, "%d %19s %c %f", &id, name, &grade, &score) == 4) {
            printf("   ID: %d, Name: %s, Grade: %c, Score: %.1f\n", 
                   id, name, grade, score);
        }
        fclose(file);
    }
    
    // Mixed formatted and string I/O
    printf("3. Mixed formatted and string operations:\n");
    file = fopen("mixed_data.txt", "w");
    if (file) {
        fprintf(file, "# Configuration File\n");
        fprintf(file, "debug_level = %d\n", 2);
        fprintf(file, "max_connections = %d\n", 100);
        fprintf(file, "server_name = %s\n", "production-server");
        fprintf(file, "timeout = %.2f\n", 30.5);
        fclose(file);
    }
    
    file = fopen("mixed_data.txt", "r");
    if (file) {
        char line[256];
        printf("   Configuration settings:\n");
        
        while (fgets(line, sizeof(line), file)) {
            if (line[0] == '#') {
                printf("   Comment: %s", line);
            } else if (strstr(line, "=")) {
                printf("   Setting: %s", line);
            }
        }
        fclose(file);
    }
    
    printf("\n");
}

void demonstrate_binary_io(void) {
    printf("4. BINARY I/O FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    printf("Using fread() and fwrite() for binary data:\n\n");
    
    // Writing binary data
    printf("1. Writing binary data with fwrite():\n");
    FILE *file = fopen("employees.bin", "wb");
    if (file) {
        Employee employees[] = {
            {1001, "Alice Johnson", 75000.0, 1},
            {1002, "Bob Smith", 68000.0, 2},
            {1003, "Carol Davis", 82000.0, 1},
            {1004, "David Wilson", 71000.0, 3}
        };
        
        size_t count = sizeof(employees) / sizeof(employees[0]);
        size_t written = fwrite(employees, sizeof(Employee), count, file);
        fclose(file);
        
        printf("   ✓ Written %zu employee records to binary file\n", written);
    }
    
    // Reading binary data
    printf("2. Reading binary data with fread():\n");
    file = fopen("employees.bin", "rb");
    if (file) {
        Employee emp;
        int record_num = 1;
        
        printf("   Employee records from binary file:\n");
        while (fread(&emp, sizeof(Employee), 1, file) == 1) {
            printf("   %d. ID: %d, Name: %s, Salary: $%.2f, Dept: %d\n",
                   record_num++, emp.id, emp.name, emp.salary, emp.department);
        }
        fclose(file);
    }
    
    // Writing arrays of different types
    printf("3. Writing arrays of different data types:\n");
    file = fopen("arrays.bin", "wb");
    if (file) {
        // Write integer array
        int numbers[] = {10, 20, 30, 40, 50};
        fwrite(numbers, sizeof(int), 5, file);
        
        // Write float array
        float values[] = {1.1f, 2.2f, 3.3f};
        fwrite(values, sizeof(float), 3, file);
        
        // Write character array
        char text[] = "Binary Data";
        fwrite(text, sizeof(char), strlen(text), file);
        
        fclose(file);
        printf("   ✓ Written mixed data types to binary file\n");
    }
    
    // Reading mixed binary data
    printf("4. Reading mixed binary data:\n");
    file = fopen("arrays.bin", "rb");
    if (file) {
        // Read integer array
        int numbers[5];
        size_t int_count = fread(numbers, sizeof(int), 5, file);
        printf("   Integers (%zu): ", int_count);
        for (size_t i = 0; i < int_count; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
        
        // Read float array
        float values[3];
        size_t float_count = fread(values, sizeof(float), 3, file);
        printf("   Floats (%zu): ", float_count);
        for (size_t i = 0; i < float_count; i++) {
            printf("%.1f ", values[i]);
        }
        printf("\n");
        
        // Read character array
        char text[20];
        size_t char_count = fread(text, sizeof(char), 11, file);
        text[char_count] = '\0';  // Null terminate
        printf("   Text (%zu chars): %s\n", char_count, text);
        
        fclose(file);
    }
    
    printf("\n");
}

void demonstrate_performance_comparison(void) {
    printf("5. PERFORMANCE COMPARISON\n");
    printf("----------------------------------------\n");
    
    printf("Comparing performance of different I/O methods:\n\n");
    
    const int DATA_SIZE = 10000;
    
    // Create test data
    printf("Creating test data (%d integers)...\n", DATA_SIZE);
    
    // Method 1: Character-by-character (slowest)
    printf("1. Character-by-character I/O:\n");
    clock_t start = clock();
    
    FILE *file = fopen("perf_char.txt", "w");
    if (file) {
        for (int i = 0; i < 1000; i++) {  // Smaller dataset for char I/O
            char buffer[20];
            sprintf(buffer, "%d\n", i);
            for (int j = 0; buffer[j]; j++) {
                fputc(buffer[j], file);
            }
        }
        fclose(file);
    }
    
    clock_t char_time = clock() - start;
    printf("   Time: %.3f seconds\n", (double)char_time / CLOCKS_PER_SEC);
    
    // Method 2: String I/O (medium speed)
    printf("2. String I/O:\n");
    start = clock();
    
    file = fopen("perf_string.txt", "w");
    if (file) {
        for (int i = 0; i < DATA_SIZE; i++) {
            char buffer[20];
            sprintf(buffer, "%d\n", i);
            fputs(buffer, file);
        }
        fclose(file);
    }
    
    clock_t string_time = clock() - start;
    printf("   Time: %.3f seconds\n", (double)string_time / CLOCKS_PER_SEC);
    
    // Method 3: Formatted I/O (medium speed)
    printf("3. Formatted I/O:\n");
    start = clock();
    
    file = fopen("perf_formatted.txt", "w");
    if (file) {
        for (int i = 0; i < DATA_SIZE; i++) {
            fprintf(file, "%d\n", i);
        }
        fclose(file);
    }
    
    clock_t formatted_time = clock() - start;
    printf("   Time: %.3f seconds\n", (double)formatted_time / CLOCKS_PER_SEC);
    
    // Method 4: Binary I/O (fastest)
    printf("4. Binary I/O:\n");
    start = clock();
    
    file = fopen("perf_binary.bin", "wb");
    if (file) {
        for (int i = 0; i < DATA_SIZE; i++) {
            fwrite(&i, sizeof(int), 1, file);
        }
        fclose(file);
    }
    
    clock_t binary_time = clock() - start;
    printf("   Time: %.3f seconds\n", (double)binary_time / CLOCKS_PER_SEC);
    
    // Performance summary
    printf("\nPerformance Summary (relative to binary I/O):\n");
    double binary_sec = (double)binary_time / CLOCKS_PER_SEC;
    if (binary_sec > 0) {
        printf("   Binary I/O:    1.0x (baseline)\n");
        printf("   Formatted I/O: %.1fx slower\n", 
               ((double)formatted_time / CLOCKS_PER_SEC) / binary_sec);
        printf("   String I/O:    %.1fx slower\n", 
               ((double)string_time / CLOCKS_PER_SEC) / binary_sec);
    }
    
    printf("\n");
}

void demonstrate_error_handling(void) {
    printf("6. ERROR HANDLING\n");
    printf("----------------------------------------\n");
    
    printf("Proper error handling for I/O operations:\n\n");
    
    // fgets error handling
    printf("1. fgets() error handling:\n");
    FILE *file = fopen("sample.txt", "r");
    if (file) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file)) {
            // Process line
        }
        
        if (feof(file)) {
            printf("   ✓ Reached end of file normally\n");
        } else if (ferror(file)) {
            printf("   ✗ Read error occurred\n");
        }
        fclose(file);
    }
    
    // fscanf error handling
    printf("2. fscanf() error handling:\n");
    file = fopen("formatted_data.txt", "r");
    if (file) {
        char buffer[256];
        fgets(buffer, sizeof(buffer), file);  // Skip header
        fgets(buffer, sizeof(buffer), file);  // Skip separator
        fgets(buffer, sizeof(buffer), file);  // Skip column names
        
        int id;
        char name[20];
        char grade;
        float score;
        int items_read;
        
        while ((items_read = fscanf(file, "%d %19s %c %f", 
                                   &id, name, &grade, &score)) > 0) {
            if (items_read == 4) {
                printf("   ✓ Successfully read: %d %s %c %.1f\n", 
                       id, name, grade, score);
            } else {
                printf("   ✗ Partial read: only %d items\n", items_read);
                break;
            }
        }
        fclose(file);
    }
    
    // fread/fwrite error handling
    printf("3. Binary I/O error handling:\n");
    file = fopen("employees.bin", "rb");
    if (file) {
        Employee emp;
        size_t items_read;
        int count = 0;
        
        while ((items_read = fread(&emp, sizeof(Employee), 1, file)) > 0) {
            count++;
        }
        
        if (feof(file)) {
            printf("   ✓ Successfully read %d employee records\n", count);
        } else if (ferror(file)) {
            printf("   ✗ Error reading binary data\n");
        }
        fclose(file);
    }
    
    printf("\n");
}

void demonstrate_practical_examples(void) {
    printf("7. PRACTICAL EXAMPLES\n");
    printf("----------------------------------------\n");
    
    printf("Real-world file processing examples:\n\n");
    
    // Log file processing
    printf("1. Log file processing:\n");
    FILE *log_file = fopen("application.log", "w");
    if (log_file) {
        fprintf(log_file, "2024-01-15 10:30:00 INFO Application started\n");
        fprintf(log_file, "2024-01-15 10:30:01 INFO Loading configuration\n");
        fprintf(log_file, "2024-01-15 10:30:02 WARN High memory usage: 85%%\n");
        fprintf(log_file, "2024-01-15 10:30:03 ERROR Database connection failed\n");
        fprintf(log_file, "2024-01-15 10:30:04 INFO Retrying connection\n");
        fclose(log_file);
    }
    
    // Parse log file
    FILE *file = fopen("application.log", "r");
    if (file) {
        char line[256];
        int info_count = 0, warn_count = 0, error_count = 0;
        
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, " INFO ")) info_count++;
            else if (strstr(line, " WARN ")) warn_count++;
            else if (strstr(line, " ERROR ")) error_count++;
        }
        
        printf("   Log analysis: %d INFO, %d WARN, %d ERROR messages\n",
               info_count, warn_count, error_count);
        fclose(file);
    }
    
    // Configuration file processing
    printf("2. Configuration file processing:\n");
    FILE *config = fopen("app.conf", "w");
    if (config) {
        fprintf(config, "# Application Configuration\n");
        fprintf(config, "port=8080\n");
        fprintf(config, "host=localhost\n");
        fprintf(config, "debug=true\n");
        fprintf(config, "max_clients=50\n");
        fclose(config);
    }
    
    // Parse configuration
    file = fopen("app.conf", "r");
    if (file) {
        char line[256];
        printf("   Configuration settings:\n");
        
        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = '\0';  // Remove newline
            
            if (line[0] == '#' || line[0] == '\0') {
                continue;  // Skip comments and empty lines
            }
            
            char *equals = strchr(line, '=');
            if (equals) {
                *equals = '\0';  // Split at '='
                printf("     %s = %s\n", line, equals + 1);
            }
        }
        fclose(file);
    }
    
    // Data export/import
    printf("3. Data export/import:\n");
    
    // Export data to CSV
    FILE *csv = fopen("export.csv", "w");
    if (csv) {
        fprintf(csv, "Product,Price,Quantity\n");
        fprintf(csv, "Laptop,999.99,10\n");
        fprintf(csv, "Mouse,29.99,50\n");
        fprintf(csv, "Keyboard,79.99,25\n");
        fclose(csv);
    }
    
    // Import and process CSV
    file = fopen("export.csv", "r");
    if (file) {
        char line[256];
        fgets(line, sizeof(line), file);  // Skip header
        
        float total_value = 0.0;
        int total_items = 0;
        
        while (fgets(line, sizeof(line), file)) {
            char product[50];
            float price;
            int quantity;
            
            if (sscanf(line, "%49[^,],%f,%d", product, &price, &quantity) == 3) {
                float item_value = price * quantity;
                total_value += item_value;
                total_items += quantity;
                printf("     %s: $%.2f x %d = $%.2f\n", 
                       product, price, quantity, item_value);
            }
        }
        
        printf("   Total inventory: %d items worth $%.2f\n", 
               total_items, total_value);
        fclose(file);
    }
    
    printf("\n");
}

void create_sample_text_file(void) {
    FILE *file = fopen("sample.txt", "w");
    if (file) {
        fprintf(file, "This is a sample text file for demonstration.\n");
        fprintf(file, "It contains multiple lines of text.\n");
        fprintf(file, "Each line demonstrates different concepts.\n");
        fprintf(file, "File I/O operations are essential in C programming.\n");
        fprintf(file, "This file will be used for various read operations.\n");
        fclose(file);
    }
}

void create_sample_binary_file(void) {
    FILE *file = fopen("sample.bin", "wb");
    if (file) {
        int data[] = {100, 200, 300, 400, 500};
        fwrite(data, sizeof(int), 5, file);
        fclose(file);
    }
}

void cleanup_test_files(void) {
    printf("Cleaning up test files...\n");
    const char *files[] = {
        "sample.txt", "sample.bin", "char_output.txt", "string_output.txt",
        "csv_data.txt", "formatted_data.txt", "mixed_data.txt", "employees.bin",
        "arrays.bin", "perf_char.txt", "perf_string.txt", "perf_formatted.txt",
        "perf_binary.bin", "application.log", "app.conf", "export.csv"
    };
    
    int cleaned = 0;
    for (size_t i = 0; i < sizeof(files) / sizeof(files[0]); i++) {
        if (remove(files[i]) == 0) {
            cleaned++;
        }
    }
    
    printf("✓ Cleaned up %d test files\n", cleaned);
}

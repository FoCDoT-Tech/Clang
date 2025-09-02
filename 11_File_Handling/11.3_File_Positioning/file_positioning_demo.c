#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for random access demonstration
typedef struct {
    int id;
    char name[32];
    float salary;
    int department;
} Employee;

// Function prototypes
void demonstrate_basic_positioning(void);
void demonstrate_file_size_calculation(void);
void demonstrate_random_access(void);
void demonstrate_reverse_reading(void);
void demonstrate_status_functions(void);
void demonstrate_practical_examples(void);
void demonstrate_error_handling(void);

// Utility functions
void create_sample_files(void);
void create_employee_database(void);
long get_file_size(FILE *file);
void print_file_info(FILE *file, const char *filename);
int safe_seek(FILE *f, long offset, int whence);
void cleanup_test_files(void);

int main(void) {
    printf("=== File Positioning Demo ===\n\n");
    
    // Create sample files for demonstrations
    create_sample_files();
    create_employee_database();
    
    demonstrate_basic_positioning();
    demonstrate_file_size_calculation();
    demonstrate_random_access();
    demonstrate_reverse_reading();
    demonstrate_status_functions();
    demonstrate_practical_examples();
    demonstrate_error_handling();
    
    // Clean up test files
    cleanup_test_files();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_positioning(void) {
    printf("1. BASIC FILE POSITIONING\n");
    printf("----------------------------------------\n");
    
    printf("Using fseek(), ftell(), and rewind():\n\n");
    
    FILE *file = fopen("sample_text.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return;
    }
    
    // Show initial position
    printf("1. Initial file position:\n");
    printf("   Position: %ld bytes\n", ftell(file));
    
    // Read some characters and show position change
    printf("2. Reading characters and tracking position:\n");
    for (int i = 0; i < 5; i++) {
        int c = fgetc(file);
        printf("   Read '%c', position now: %ld\n", c, ftell(file));
    }
    
    // Demonstrate fseek with different whence values
    printf("3. Using fseek() with different origins:\n");
    
    // SEEK_SET - from beginning
    fseek(file, 10, SEEK_SET);
    printf("   fseek(file, 10, SEEK_SET) -> position: %ld\n", ftell(file));
    
    // SEEK_CUR - from current position
    fseek(file, 5, SEEK_CUR);
    printf("   fseek(file, 5, SEEK_CUR) -> position: %ld\n", ftell(file));
    
    // SEEK_END - from end of file
    fseek(file, 0, SEEK_END);
    printf("   fseek(file, 0, SEEK_END) -> position: %ld (file size)\n", ftell(file));
    
    // Move backward from end
    fseek(file, -10, SEEK_END);
    printf("   fseek(file, -10, SEEK_END) -> position: %ld\n", ftell(file));
    
    // Demonstrate rewind()
    printf("4. Using rewind():\n");
    rewind(file);
    printf("   After rewind() -> position: %ld\n", ftell(file));
    
    // Show content at different positions
    printf("5. Reading content at different positions:\n");
    fseek(file, 0, SEEK_SET);
    char buffer[20];
    fgets(buffer, sizeof(buffer), file);
    printf("   At position 0: \"%.15s...\"\n", buffer);
    
    fseek(file, 20, SEEK_SET);
    fgets(buffer, sizeof(buffer), file);
    printf("   At position 20: \"%.15s...\"\n", buffer);
    
    fclose(file);
    printf("\n");
}

void demonstrate_file_size_calculation(void) {
    printf("2. FILE SIZE CALCULATION\n");
    printf("----------------------------------------\n");
    
    printf("Different methods to calculate file size:\n\n");
    
    // Method 1: Using fseek and ftell
    printf("1. Using fseek() and ftell():\n");
    FILE *file = fopen("sample_text.txt", "r");
    if (file) {
        long size = get_file_size(file);
        printf("   File size: %ld bytes\n", size);
        fclose(file);
    }
    
    // Method 2: Reading to end and counting
    printf("2. Counting bytes by reading to EOF:\n");
    file = fopen("sample_text.txt", "r");
    if (file) {
        long count = 0;
        while (fgetc(file) != EOF) {
            count++;
        }
        printf("   Byte count: %ld bytes\n", count);
        fclose(file);
    }
    
    // Method 3: For binary files
    printf("3. Binary file size calculation:\n");
    file = fopen("employees.bin", "rb");
    if (file) {
        long size = get_file_size(file);
        long record_count = size / sizeof(Employee);
        printf("   Binary file size: %ld bytes\n", size);
        printf("   Number of Employee records: %ld\n", record_count);
        fclose(file);
    }
    
    // Compare sizes of different files
    printf("4. Comparing file sizes:\n");
    const char *files[] = {"sample_text.txt", "employees.bin", "large_text.txt"};
    for (int i = 0; i < 3; i++) {
        FILE *f = fopen(files[i], "rb");
        if (f) {
            long size = get_file_size(f);
            printf("   %s: %ld bytes\n", files[i], size);
            fclose(f);
        }
    }
    
    printf("\n");
}

void demonstrate_random_access(void) {
    printf("3. RANDOM ACCESS TO STRUCTURED DATA\n");
    printf("----------------------------------------\n");
    
    printf("Accessing records at specific positions:\n\n");
    
    FILE *file = fopen("employees.bin", "r+b");
    if (!file) {
        printf("Error opening employee database\n");
        return;
    }
    
    // Calculate number of records
    long file_size = get_file_size(file);
    long num_records = file_size / sizeof(Employee);
    printf("Employee database contains %ld records\n\n", num_records);
    
    // Read specific records by index
    printf("1. Reading specific records by index:\n");
    int indices[] = {0, 2, 4, 1, 3};  // Random order
    
    for (int i = 0; i < 5; i++) {
        int index = indices[i];
        if (index < num_records) {
            // Seek to record position
            fseek(file, index * sizeof(Employee), SEEK_SET);
            
            Employee emp;
            if (fread(&emp, sizeof(Employee), 1, file) == 1) {
                printf("   Record %d: ID=%d, Name=%s, Salary=$%.2f\n",
                       index, emp.id, emp.name, emp.salary);
            }
        }
    }
    
    // Modify a specific record
    printf("\n2. Modifying a specific record:\n");
    int modify_index = 2;
    fseek(file, modify_index * sizeof(Employee), SEEK_SET);
    
    Employee emp;
    fread(&emp, sizeof(Employee), 1, file);
    printf("   Original: ID=%d, Name=%s, Salary=$%.2f\n",
           emp.id, emp.name, emp.salary);
    
    // Modify salary
    emp.salary += 5000.0;
    
    // Seek back to write position
    fseek(file, modify_index * sizeof(Employee), SEEK_SET);
    fwrite(&emp, sizeof(Employee), 1, file);
    
    // Verify modification
    fseek(file, modify_index * sizeof(Employee), SEEK_SET);
    fread(&emp, sizeof(Employee), 1, file);
    printf("   Modified: ID=%d, Name=%s, Salary=$%.2f\n",
           emp.id, emp.name, emp.salary);
    
    // Insert new record at end
    printf("\n3. Appending new record:\n");
    Employee new_emp = {1006, "Frank Miller", 78000.0, 2};
    
    fseek(file, 0, SEEK_END);
    long pos_before = ftell(file);
    fwrite(&new_emp, sizeof(Employee), 1, file);
    long pos_after = ftell(file);
    
    printf("   Added record at position %ld (size increased by %ld bytes)\n",
           pos_before, pos_after - pos_before);
    
    // Read records in reverse order
    printf("\n4. Reading records in reverse order:\n");
    long total_records = get_file_size(file) / sizeof(Employee);
    
    for (long i = total_records - 1; i >= total_records - 3 && i >= 0; i--) {
        fseek(file, i * sizeof(Employee), SEEK_SET);
        fread(&emp, sizeof(Employee), 1, file);
        printf("   Record %ld: %s (ID: %d)\n", i, emp.name, emp.id);
    }
    
    fclose(file);
    printf("\n");
}

void demonstrate_reverse_reading(void) {
    printf("4. REVERSE FILE READING\n");
    printf("----------------------------------------\n");
    
    printf("Reading files backwards:\n\n");
    
    // Create a simple text file for reverse reading
    FILE *file = fopen("reverse_test.txt", "w");
    if (file) {
        fprintf(file, "Line 1: First line\n");
        fprintf(file, "Line 2: Second line\n");
        fprintf(file, "Line 3: Third line\n");
        fclose(file);
    }
    
    // Method 1: Read characters in reverse
    printf("1. Reading characters in reverse:\n");
    file = fopen("reverse_test.txt", "r");
    if (file) {
        fseek(file, -1, SEEK_END);  // Start from last character
        printf("   Reverse characters: ");
        
        while (ftell(file) > 0) {
            int c = fgetc(file);
            if (c != '\n') printf("%c", c);
            fseek(file, -2, SEEK_CUR);  // Move back 2 positions
        }
        
        // Read the first character
        rewind(file);
        int c = fgetc(file);
        if (c != '\n') printf("%c", c);
        printf("\n");
        fclose(file);
    }
    
    // Method 2: Read lines in reverse order
    printf("2. Reading lines in reverse order:\n");
    file = fopen("reverse_test.txt", "r");
    if (file) {
        // Find all line positions first
        long line_positions[10];
        int line_count = 0;
        
        line_positions[line_count++] = 0;  // First line starts at 0
        
        int c;
        while ((c = fgetc(file)) != EOF) {
            if (c == '\n' && line_count < 10) {
                line_positions[line_count++] = ftell(file);
            }
        }
        line_count--;  // Last position is EOF, not a line start
        
        // Read lines in reverse order
        for (int i = line_count - 1; i >= 0; i--) {
            fseek(file, line_positions[i], SEEK_SET);
            char buffer[256];
            if (fgets(buffer, sizeof(buffer), file)) {
                buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline
                printf("   %s\n", buffer);
            }
        }
        fclose(file);
    }
    
    // Method 3: Tail-like functionality (last N lines)
    printf("3. Reading last N lines (tail functionality):\n");
    file = fopen("large_text.txt", "r");
    if (file) {
        const int N = 3;
        long line_positions[N];
        int lines_found = 0;
        
        // Start from end and work backwards to find last N line starts
        fseek(file, -1, SEEK_END);
        long pos = ftell(file);
        
        while (pos > 0 && lines_found < N) {
            fseek(file, pos, SEEK_SET);
            int c = fgetc(file);
            
            if (c == '\n') {
                // Found a line ending, next position is line start
                if (pos + 1 < get_file_size(file)) {
                    // Shift existing positions
                    for (int i = N - 1; i > 0; i--) {
                        line_positions[i] = line_positions[i - 1];
                    }
                    line_positions[0] = pos + 1;
                    lines_found++;
                }
            }
            pos--;
        }
        
        // If we didn't find enough newlines, include beginning of file
        if (lines_found < N) {
            for (int i = N - 1; i > 0; i--) {
                line_positions[i] = line_positions[i - 1];
            }
            line_positions[0] = 0;
            lines_found++;
        }
        
        printf("   Last %d lines:\n", lines_found);
        for (int i = N - lines_found; i < N; i++) {
            fseek(file, line_positions[i], SEEK_SET);
            char buffer[256];
            if (fgets(buffer, sizeof(buffer), file)) {
                buffer[strcspn(buffer, "\n")] = '\0';
                printf("     %s\n", buffer);
            }
        }
        fclose(file);
    }
    
    printf("\n");
}

void demonstrate_status_functions(void) {
    printf("5. FILE STATUS FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    printf("Using feof(), ferror(), and clearerr():\n\n");
    
    // Demonstrate feof()
    printf("1. End-of-file detection with feof():\n");
    FILE *file = fopen("sample_text.txt", "r");
    if (file) {
        int char_count = 0;
        int c;
        
        while ((c = fgetc(file)) != EOF) {
            char_count++;
        }
        
        printf("   Read %d characters\n", char_count);
        printf("   feof() returns: %d (non-zero = EOF reached)\n", feof(file));
        printf("   ferror() returns: %d (non-zero = error occurred)\n", ferror(file));
        
        fclose(file);
    }
    
    // Demonstrate error detection
    printf("2. Error detection with ferror():\n");
    file = fopen("sample_text.txt", "r");
    if (file) {
        // Try to write to a read-only file (should cause error)
        int result = fputc('X', file);
        
        printf("   Attempted write to read-only file\n");
        printf("   fputc() returned: %d (EOF indicates error)\n", result);
        printf("   ferror() returns: %d\n", ferror(file));
        printf("   feof() returns: %d\n", feof(file));
        
        // Clear error indicators
        clearerr(file);
        printf("   After clearerr():\n");
        printf("   ferror() returns: %d\n", ferror(file));
        printf("   feof() returns: %d\n", feof(file));
        
        fclose(file);
    }
    
    // Demonstrate proper error handling in read loop
    printf("3. Proper error handling in read operations:\n");
    file = fopen("sample_text.txt", "r");
    if (file) {
        char buffer[256];
        int line_count = 0;
        
        while (fgets(buffer, sizeof(buffer), file)) {
            line_count++;
        }
        
        // Check why loop ended
        if (feof(file)) {
            printf("   Successfully read %d lines (EOF reached)\n", line_count);
        } else if (ferror(file)) {
            printf("   Error occurred after reading %d lines\n", line_count);
        }
        
        fclose(file);
    }
    
    // Demonstrate status checking with binary I/O
    printf("4. Status checking with binary I/O:\n");
    file = fopen("employees.bin", "rb");
    if (file) {
        Employee emp;
        int record_count = 0;
        
        while (fread(&emp, sizeof(Employee), 1, file) == 1) {
            record_count++;
        }
        
        printf("   Read %d employee records\n", record_count);
        
        if (feof(file)) {
            printf("   File read completely (EOF)\n");
        } else if (ferror(file)) {
            printf("   Read error occurred\n");
        } else {
            printf("   Partial record at end of file\n");
        }
        
        fclose(file);
    }
    
    printf("\n");
}

void demonstrate_practical_examples(void) {
    printf("6. PRACTICAL EXAMPLES\n");
    printf("----------------------------------------\n");
    
    printf("Real-world file positioning applications:\n\n");
    
    // Example 1: Simple database with index
    printf("1. Simple indexed database:\n");
    
    // Create index file
    FILE *index_file = fopen("employee.idx", "w");
    FILE *data_file = fopen("employees.bin", "rb");
    
    if (index_file && data_file) {
        Employee emp;
        long position = 0;
        
        fprintf(index_file, "ID,Position\n");
        while (fread(&emp, sizeof(Employee), 1, data_file) == 1) {
            fprintf(index_file, "%d,%ld\n", emp.id, position);
            position = ftell(data_file);
        }
        
        fclose(index_file);
        fclose(data_file);
        printf("   ✓ Created index file with ID->position mapping\n");
    }
    
    // Use index for fast lookup
    printf("2. Fast record lookup using index:\n");
    int search_id = 1003;
    
    index_file = fopen("employee.idx", "r");
    data_file = fopen("employees.bin", "rb");
    
    if (index_file && data_file) {
        char line[256];
        fgets(line, sizeof(line), index_file);  // Skip header
        
        long found_position = -1;
        int id;
        long pos;
        
        while (fgets(line, sizeof(line), index_file)) {
            if (sscanf(line, "%d,%ld", &id, &pos) == 2) {
                if (id == search_id) {
                    found_position = pos;
                    break;
                }
            }
        }
        
        if (found_position >= 0) {
            fseek(data_file, found_position, SEEK_SET);
            Employee emp;
            if (fread(&emp, sizeof(Employee), 1, data_file) == 1) {
                printf("   Found ID %d: %s, $%.2f\n", 
                       emp.id, emp.name, emp.salary);
            }
        } else {
            printf("   ID %d not found\n", search_id);
        }
        
        fclose(index_file);
        fclose(data_file);
    }
    
    // Example 2: Log file rotation check
    printf("3. Log file size monitoring:\n");
    FILE *log_file = fopen("application.log", "a");
    if (log_file) {
        long current_size = get_file_size(log_file);
        const long MAX_SIZE = 1000;  // 1KB limit for demo
        
        printf("   Current log size: %ld bytes\n", current_size);
        
        if (current_size > MAX_SIZE) {
            printf("   Log file exceeds limit, rotation needed\n");
            
            // Simple rotation: rename current log and start new one
            fclose(log_file);
            rename("application.log", "application.log.old");
            
            log_file = fopen("application.log", "w");
            fprintf(log_file, "Log rotated - new file started\n");
        } else {
            fprintf(log_file, "Normal log entry\n");
        }
        
        fclose(log_file);
        printf("   ✓ Log file updated\n");
    }
    
    // Example 3: Configuration file parser with position tracking
    printf("4. Configuration parser with error reporting:\n");
    FILE *config = fopen("config.txt", "w");
    if (config) {
        fprintf(config, "# Configuration file\n");
        fprintf(config, "port=8080\n");
        fprintf(config, "host=localhost\n");
        fprintf(config, "invalid_line_without_equals\n");
        fprintf(config, "timeout=30\n");
        fclose(config);
    }
    
    config = fopen("config.txt", "r");
    if (config) {
        char line[256];
        int line_number = 0;
        
        while (fgets(line, sizeof(line), config)) {
            line_number++;
            long line_start = ftell(config) - strlen(line);
            
            line[strcspn(line, "\n")] = '\0';  // Remove newline
            
            if (line[0] == '#' || line[0] == '\0') {
                continue;  // Skip comments and empty lines
            }
            
            if (strchr(line, '=') == NULL) {
                printf("   Error at line %d (position %ld): Missing '=' in '%s'\n",
                       line_number, line_start, line);
            } else {
                char *equals = strchr(line, '=');
                *equals = '\0';
                printf("   Config: %s = %s\n", line, equals + 1);
            }
        }
        
        fclose(config);
    }
    
    printf("\n");
}

void demonstrate_error_handling(void) {
    printf("7. ERROR HANDLING\n");
    printf("----------------------------------------\n");
    
    printf("Proper error handling for positioning functions:\n\n");
    
    // Test fseek error handling
    printf("1. fseek() error handling:\n");
    FILE *file = fopen("sample_text.txt", "r");
    if (file) {
        // Valid seek
        if (fseek(file, 10, SEEK_SET) == 0) {
            printf("   ✓ fseek(file, 10, SEEK_SET) succeeded\n");
        } else {
            printf("   ✗ fseek failed\n");
            perror("fseek");
        }
        
        // Invalid seek (beyond file)
        if (fseek(file, 999999, SEEK_SET) == 0) {
            printf("   ✓ fseek(file, 999999, SEEK_SET) succeeded\n");
        } else {
            printf("   ✗ fseek to large offset failed\n");
            perror("fseek");
        }
        
        fclose(file);
    }
    
    // Test ftell error handling
    printf("2. ftell() error handling:\n");
    file = fopen("sample_text.txt", "r");
    if (file) {
        long pos = ftell(file);
        if (pos != -1L) {
            printf("   ✓ ftell() returned position: %ld\n", pos);
        } else {
            printf("   ✗ ftell() failed\n");
            perror("ftell");
        }
        
        fclose(file);
        
        // Try ftell on closed file (should fail)
        pos = ftell(file);
        if (pos == -1L) {
            printf("   ✓ ftell() correctly failed on closed file\n");
        }
    }
    
    // Test positioning with different file modes
    printf("3. Positioning with different file modes:\n");
    
    // Text mode positioning
    file = fopen("sample_text.txt", "r");
    if (file) {
        printf("   Text mode positioning:\n");
        long pos1 = ftell(file);
        fseek(file, 5, SEEK_SET);
        long pos2 = ftell(file);
        printf("     Initial: %ld, After seek(5): %ld\n", pos1, pos2);
        fclose(file);
    }
    
    // Binary mode positioning
    file = fopen("employees.bin", "rb");
    if (file) {
        printf("   Binary mode positioning:\n");
        long pos1 = ftell(file);
        fseek(file, sizeof(Employee), SEEK_SET);
        long pos2 = ftell(file);
        printf("     Initial: %ld, After seek(%zu): %ld\n", 
               pos1, sizeof(Employee), pos2);
        fclose(file);
    }
    
    // Safe positioning function example
    printf("4. Safe positioning wrapper:\n");
    file = fopen("sample_text.txt", "r");
    if (file) {
        if (safe_seek(file, 10, SEEK_SET) == 0) {
            printf("   ✓ Safe seek succeeded\n");
        } else {
            printf("   ✗ Safe seek failed\n");
        }
        
        fclose(file);
    }
    
    printf("\n");
}

// Utility function implementations
void create_sample_files(void) {
    // Create sample text file
    FILE *file = fopen("sample_text.txt", "w");
    if (file) {
        fprintf(file, "This is a sample text file for positioning demonstrations.\n");
        fprintf(file, "It contains multiple lines to test various operations.\n");
        fprintf(file, "Each line has different content for testing purposes.\n");
        fprintf(file, "File positioning allows random access to any part.\n");
        fclose(file);
    }
    
    // Create larger text file
    file = fopen("large_text.txt", "w");
    if (file) {
        for (int i = 1; i <= 10; i++) {
            fprintf(file, "Line %d: This is line number %d in the large text file.\n", i, i);
        }
        fclose(file);
    }
}

void create_employee_database(void) {
    FILE *file = fopen("employees.bin", "wb");
    if (file) {
        Employee employees[] = {
            {1001, "Alice Johnson", 75000.0, 1},
            {1002, "Bob Smith", 68000.0, 2},
            {1003, "Carol Davis", 82000.0, 1},
            {1004, "David Wilson", 71000.0, 3},
            {1005, "Eve Brown", 79000.0, 2}
        };
        
        size_t count = sizeof(employees) / sizeof(employees[0]);
        fwrite(employees, sizeof(Employee), count, file);
        fclose(file);
    }
}

long get_file_size(FILE *file) {
    long current_pos = ftell(file);  // Save current position
    if (current_pos == -1L) return -1L;
    
    if (fseek(file, 0, SEEK_END) != 0) return -1L;
    long size = ftell(file);
    
    fseek(file, current_pos, SEEK_SET);  // Restore position
    return size;
}

void print_file_info(FILE *file, const char *filename) {
    printf("File: %s\n", filename);
    printf("  Current position: %ld\n", ftell(file));
    printf("  File size: %ld bytes\n", get_file_size(file));
    printf("  EOF indicator: %d\n", feof(file));
    printf("  Error indicator: %d\n", ferror(file));
}

int safe_seek(FILE *f, long offset, int whence) {
    long old_pos = ftell(f);
    if (old_pos == -1L) return -1;
    
    if (fseek(f, offset, whence) != 0) {
        return -1;
    }
    
    return 0;
}

void cleanup_test_files(void) {
    printf("Cleaning up test files...\n");
    const char *files[] = {
        "sample_text.txt", "large_text.txt", "employees.bin",
        "reverse_test.txt", "employee.idx", "application.log",
        "application.log.old", "config.txt"
    };
    
    int cleaned = 0;
    for (size_t i = 0; i < sizeof(files) / sizeof(files[0]); i++) {
        if (remove(files[i]) == 0) {
            cleaned++;
        }
    }
    
    printf("✓ Cleaned up %d test files\n", cleaned);
}

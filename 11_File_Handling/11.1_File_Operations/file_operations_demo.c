#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function prototypes
void demonstrate_file_opening(void);
void demonstrate_file_modes(void);
void demonstrate_error_handling(void);
void demonstrate_file_creation(void);
void demonstrate_safe_operations(void);
void demonstrate_file_utilities(void);

// Utility functions
FILE* safe_fopen(const char *filename, const char *mode);
int file_exists(const char *filename);
long get_file_size(const char *filename);
void cleanup_test_files(void);

int main(void) {
    printf("=== File Operations Demo ===\n\n");
    
    demonstrate_file_opening();
    demonstrate_file_modes();
    demonstrate_error_handling();
    demonstrate_file_creation();
    demonstrate_safe_operations();
    demonstrate_file_utilities();
    
    // Clean up test files
    cleanup_test_files();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_file_opening(void) {
    printf("1. BASIC FILE OPENING\n");
    printf("----------------------------------------\n");
    
    printf("Opening files with fopen():\n");
    printf("  FILE *fopen(const char *filename, const char *mode);\n\n");
    
    // Create a test file first
    FILE *file = fopen("test.txt", "w");
    if (file) {
        fprintf(file, "Hello, File Operations!\n");
        fprintf(file, "This is a test file.\n");
        fclose(file);
        printf("✓ Created test.txt for demonstration\n");
    }
    
    // Open for reading
    file = fopen("test.txt", "r");
    if (file) {
        printf("✓ Successfully opened test.txt for reading\n");
        printf("  File pointer: %p\n", (void*)file);
        
        // Read and display content
        char buffer[100];
        printf("  File contents:\n");
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("    %s", buffer);
        }
        
        fclose(file);
        printf("✓ File closed successfully\n");
    } else {
        printf("✗ Failed to open test.txt\n");
    }
    
    // Attempt to open non-existent file
    file = fopen("nonexistent.txt", "r");
    if (file) {
        printf("✓ Opened nonexistent.txt\n");
        fclose(file);
    } else {
        printf("✗ Failed to open nonexistent.txt (expected)\n");
        printf("  Error: %s\n", strerror(errno));
    }
    
    printf("\n");
}

void demonstrate_file_modes(void) {
    printf("2. FILE MODES\n");
    printf("----------------------------------------\n");
    
    printf("Different file opening modes:\n\n");
    
    // Write mode - creates new file or overwrites existing
    printf("1. Write mode (\"w\"):\n");
    FILE *file = fopen("write_test.txt", "w");
    if (file) {
        fprintf(file, "Written in write mode\n");
        fclose(file);
        printf("   ✓ Created write_test.txt\n");
    }
    
    // Append mode - creates new file or appends to existing
    printf("2. Append mode (\"a\"):\n");
    file = fopen("write_test.txt", "a");
    if (file) {
        fprintf(file, "Appended text\n");
        fclose(file);
        printf("   ✓ Appended to write_test.txt\n");
    }
    
    // Read mode - file must exist
    printf("3. Read mode (\"r\"):\n");
    file = fopen("write_test.txt", "r");
    if (file) {
        printf("   ✓ Opened write_test.txt for reading\n");
        printf("   Contents:\n");
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("     %s", buffer);
        }
        fclose(file);
    }
    
    // Read-write mode
    printf("4. Read-write mode (\"r+\"):\n");
    file = fopen("write_test.txt", "r+");
    if (file) {
        printf("   ✓ Opened for read-write\n");
        
        // Read current content
        char buffer[100];
        fgets(buffer, sizeof(buffer), file);
        printf("   First line: %s", buffer);
        
        // Write at current position (overwrites)
        fprintf(file, "Modified line\n");
        fclose(file);
        printf("   ✓ Modified file content\n");
    }
    
    // Binary mode
    printf("5. Binary mode (\"wb\"):\n");
    file = fopen("binary_test.bin", "wb");
    if (file) {
        int numbers[] = {1, 2, 3, 4, 5};
        size_t written = fwrite(numbers, sizeof(int), 5, file);
        fclose(file);
        printf("   ✓ Written %zu integers to binary file\n", written);
    }
    
    printf("\n");
}

void demonstrate_error_handling(void) {
    printf("3. ERROR HANDLING\n");
    printf("----------------------------------------\n");
    
    printf("Proper error handling techniques:\n\n");
    
    // Check return value
    printf("1. Checking fopen() return value:\n");
    FILE *file = fopen("/nonexistent/path/file.txt", "r");
    if (file == NULL) {
        printf("   ✗ fopen() returned NULL\n");
        printf("   Error code: %d (%s)\n", errno, strerror(errno));
    } else {
        printf("   ✓ File opened successfully\n");
        fclose(file);
    }
    
    // Using perror for error messages
    printf("\n2. Using perror() for error messages:\n");
    file = fopen("/root/protected.txt", "w");
    if (file == NULL) {
        printf("   ");
        perror("fopen failed");
    } else {
        fclose(file);
    }
    
    // Check fclose return value
    printf("\n3. Checking fclose() return value:\n");
    file = fopen("close_test.txt", "w");
    if (file) {
        fprintf(file, "Test content\n");
        int close_result = fclose(file);
        if (close_result == 0) {
            printf("   ✓ File closed successfully\n");
        } else {
            printf("   ✗ Error closing file: %s\n", strerror(errno));
        }
    }
    
    // Multiple error conditions
    printf("\n4. Comprehensive error checking:\n");
    const char *filename = "error_test.txt";
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "   Error: Cannot create %s: %s\n", 
                filename, strerror(errno));
    } else {
        printf("   ✓ File %s created successfully\n", filename);
        
        // Write operation with error check
        if (fprintf(file, "Test data\n") < 0) {
            fprintf(stderr, "   Error: Write failed: %s\n", strerror(errno));
        } else {
            printf("   ✓ Data written successfully\n");
        }
        
        // Close with error check
        if (fclose(file) != 0) {
            fprintf(stderr, "   Error: Close failed: %s\n", strerror(errno));
        } else {
            printf("   ✓ File closed successfully\n");
        }
    }
    
    printf("\n");
}

void demonstrate_file_creation(void) {
    printf("4. FILE CREATION AND WRITING\n");
    printf("----------------------------------------\n");
    
    printf("Creating and writing to files:\n\n");
    
    // Create a data file
    printf("1. Creating a data file:\n");
    FILE *data_file = fopen("student_data.txt", "w");
    if (data_file) {
        fprintf(data_file, "Student Records\n");
        fprintf(data_file, "===============\n");
        fprintf(data_file, "ID    Name           Grade\n");
        fprintf(data_file, "001   Alice Johnson  A\n");
        fprintf(data_file, "002   Bob Smith      B+\n");
        fprintf(data_file, "003   Carol Davis    A-\n");
        fclose(data_file);
        printf("   ✓ Created student_data.txt\n");
    }
    
    // Create a configuration file
    printf("2. Creating a configuration file:\n");
    FILE *config_file = fopen("config.ini", "w");
    if (config_file) {
        fprintf(config_file, "[Settings]\n");
        fprintf(config_file, "debug=true\n");
        fprintf(config_file, "max_connections=100\n");
        fprintf(config_file, "timeout=30\n");
        fprintf(config_file, "\n[Database]\n");
        fprintf(config_file, "host=localhost\n");
        fprintf(config_file, "port=5432\n");
        fclose(config_file);
        printf("   ✓ Created config.ini\n");
    }
    
    // Create a log file
    printf("3. Creating a log file:\n");
    FILE *log_file = fopen("application.log", "w");
    if (log_file) {
        fprintf(log_file, "[2024-01-15 10:30:00] INFO: Application started\n");
        fprintf(log_file, "[2024-01-15 10:30:01] INFO: Loading configuration\n");
        fprintf(log_file, "[2024-01-15 10:30:02] INFO: Database connected\n");
        fprintf(log_file, "[2024-01-15 10:30:03] WARN: High memory usage detected\n");
        fclose(log_file);
        printf("   ✓ Created application.log\n");
    }
    
    // Verify files were created
    printf("\n4. Verifying created files:\n");
    const char *files[] = {"student_data.txt", "config.ini", "application.log"};
    for (int i = 0; i < 3; i++) {
        if (file_exists(files[i])) {
            long size = get_file_size(files[i]);
            printf("   ✓ %s exists (%ld bytes)\n", files[i], size);
        } else {
            printf("   ✗ %s not found\n", files[i]);
        }
    }
    
    printf("\n");
}

void demonstrate_safe_operations(void) {
    printf("5. SAFE FILE OPERATIONS\n");
    printf("----------------------------------------\n");
    
    printf("Using safe file operation patterns:\n\n");
    
    // Safe file opening with utility function
    printf("1. Safe file opening:\n");
    FILE *file = safe_fopen("safe_test.txt", "w");
    fprintf(file, "Safely created and written\n");
    fclose(file);
    printf("   ✓ File created using safe_fopen()\n");
    
    // File existence check before operations
    printf("2. File existence checking:\n");
    if (file_exists("safe_test.txt")) {
        printf("   ✓ safe_test.txt exists\n");
        file = fopen("safe_test.txt", "r");
        char buffer[100];
        if (fgets(buffer, sizeof(buffer), file)) {
            printf("   Content: %s", buffer);
        }
        fclose(file);
    } else {
        printf("   ✗ safe_test.txt does not exist\n");
    }
    
    // Backup before overwriting
    printf("3. Creating backup before overwriting:\n");
    if (file_exists("safe_test.txt")) {
        // Create backup
        FILE *src = fopen("safe_test.txt", "r");
        FILE *dst = fopen("safe_test.txt.backup", "w");
        if (src && dst) {
            char buffer[1024];
            size_t bytes;
            while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
                fwrite(buffer, 1, bytes, dst);
            }
            fclose(src);
            fclose(dst);
            printf("   ✓ Backup created: safe_test.txt.backup\n");
        }
    }
    
    // Atomic file operations (write to temp, then rename)
    printf("4. Atomic file writing:\n");
    FILE *temp_file = fopen("temp_atomic.tmp", "w");
    if (temp_file) {
        fprintf(temp_file, "Atomic write operation\n");
        fprintf(temp_file, "This ensures data integrity\n");
        fclose(temp_file);
        
        // Rename temp file to final name
        if (rename("temp_atomic.tmp", "atomic_file.txt") == 0) {
            printf("   ✓ Atomic write completed successfully\n");
        } else {
            printf("   ✗ Atomic write failed during rename\n");
            perror("rename");
        }
    }
    
    printf("\n");
}

void demonstrate_file_utilities(void) {
    printf("6. FILE UTILITY FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    printf("Useful file utility operations:\n\n");
    
    // File size checking
    printf("1. File size information:\n");
    const char *test_files[] = {"test.txt", "student_data.txt", "config.ini"};
    for (int i = 0; i < 3; i++) {
        if (file_exists(test_files[i])) {
            long size = get_file_size(test_files[i]);
            printf("   %s: %ld bytes\n", test_files[i], size);
        }
    }
    
    // File copying
    printf("\n2. File copying:\n");
    FILE *src = fopen("test.txt", "r");
    FILE *dst = fopen("test_copy.txt", "w");
    if (src && dst) {
        char buffer[1024];
        size_t bytes_read;
        size_t total_copied = 0;
        
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
            size_t bytes_written = fwrite(buffer, 1, bytes_read, dst);
            total_copied += bytes_written;
        }
        
        fclose(src);
        fclose(dst);
        printf("   ✓ Copied %zu bytes to test_copy.txt\n", total_copied);
    }
    
    // File comparison
    printf("\n3. File comparison:\n");
    FILE *file1 = fopen("test.txt", "r");
    FILE *file2 = fopen("test_copy.txt", "r");
    if (file1 && file2) {
        int identical = 1;
        int c1, c2;
        
        while ((c1 = fgetc(file1)) != EOF && (c2 = fgetc(file2)) != EOF) {
            if (c1 != c2) {
                identical = 0;
                break;
            }
        }
        
        // Check if both files ended at the same time
        if (identical && fgetc(file1) == EOF && fgetc(file2) == EOF) {
            printf("   ✓ Files are identical\n");
        } else {
            printf("   ✗ Files are different\n");
        }
        
        fclose(file1);
        fclose(file2);
    }
    
    printf("\n");
}

// Utility function implementations
FILE* safe_fopen(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (!file) {
        fprintf(stderr, "Error: Cannot open %s in mode %s: %s\n", 
                filename, mode, strerror(errno));
        exit(1);
    }
    return file;
}

int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

long get_file_size(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return -1;
    
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);
    
    return size;
}

void cleanup_test_files(void) {
    printf("Cleaning up test files...\n");
    const char *files[] = {
        "test.txt", "write_test.txt", "binary_test.bin",
        "close_test.txt", "error_test.txt", "student_data.txt",
        "config.ini", "application.log", "safe_test.txt",
        "safe_test.txt.backup", "atomic_file.txt", "test_copy.txt"
    };
    
    int cleaned = 0;
    for (size_t i = 0; i < sizeof(files) / sizeof(files[0]); i++) {
        if (remove(files[i]) == 0) {
            cleaned++;
        }
    }
    
    printf("✓ Cleaned up %d test files\n", cleaned);
}

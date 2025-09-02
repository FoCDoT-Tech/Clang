#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configuration structure
typedef struct {
    int verbose;
    int help;
    char *input_file;
    char *output_file;
    int count;
    int port;
    char *host;
} Config;

// Function prototypes
void demonstrate_basic_arguments(int argc, char *argv[]);
void demonstrate_argument_parsing(int argc, char *argv[]);
void demonstrate_file_processing(int argc, char *argv[]);
void demonstrate_advanced_parsing(int argc, char *argv[]);
void demonstrate_error_handling(int argc, char *argv[]);
void demonstrate_practical_examples(int argc, char *argv[]);

// Utility functions
void show_help(const char *program_name);
void show_usage(const char *program_name);
Config parse_arguments(int argc, char *argv[]);
int process_file(const char *filename, int verbose);
void create_sample_files(void);
void cleanup_test_files(void);

int main(int argc, char *argv[]) {
    printf("=== Command Line Arguments Demo ===\n\n");
    
    // Create sample files for demonstrations
    create_sample_files();
    
    demonstrate_basic_arguments(argc, argv);
    demonstrate_argument_parsing(argc, argv);
    demonstrate_file_processing(argc, argv);
    demonstrate_advanced_parsing(argc, argv);
    demonstrate_error_handling(argc, argv);
    demonstrate_practical_examples(argc, argv);
    
    // Clean up test files
    cleanup_test_files();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_arguments(int argc, char *argv[]) {
    printf("1. BASIC ARGUMENT STRUCTURE\n");
    printf("----------------------------------------\n");
    
    printf("Program execution details:\n");
    printf("  argc (argument count): %d\n", argc);
    printf("  Program name (argv[0]): %s\n", argv[0]);
    
    if (argc > 1) {
        printf("  Command line arguments:\n");
        for (int i = 1; i < argc; i++) {
            printf("    argv[%d]: \"%s\"\n", i, argv[i]);
        }
    } else {
        printf("  No command line arguments provided\n");
        printf("  Try running: ./command_line_demo arg1 arg2 -v --help\n");
    }
    
    // Demonstrate argv array structure
    printf("\nArgument vector structure:\n");
    for (int i = 0; i < argc; i++) {
        printf("  argv[%d] = \"%s\" (length: %zu)\n", 
               i, argv[i], strlen(argv[i]));
    }
    
    // Show that argv[argc] is NULL
    printf("  argv[%d] = %s (NULL terminator)\n", argc, 
           argv[argc] ? "NOT NULL" : "NULL");
    
    printf("\n");
}

void demonstrate_argument_parsing(int argc, char *argv[]) {
    printf("2. ARGUMENT PARSING\n");
    printf("----------------------------------------\n");
    
    printf("Parsing different types of arguments:\n\n");
    
    // Initialize flags and options
    int verbose = 0;
    int help = 0;
    int quiet = 0;
    char *output_file = NULL;
    char *input_file = NULL;
    int count = 0;
    
    // Parse arguments manually
    printf("1. Manual argument parsing:\n");
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            verbose = 1;
            printf("   Found verbose flag: %s\n", argv[i]);
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            help = 1;
            printf("   Found help flag: %s\n", argv[i]);
        } else if (strcmp(argv[i], "-q") == 0 || strcmp(argv[i], "--quiet") == 0) {
            quiet = 1;
            printf("   Found quiet flag: %s\n", argv[i]);
        } else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output") == 0) {
            if (i + 1 < argc) {
                output_file = argv[++i];
                printf("   Found output option: %s\n", output_file);
            } else {
                printf("   Error: -o requires a filename\n");
            }
        } else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--count") == 0) {
            if (i + 1 < argc) {
                count = atoi(argv[++i]);
                printf("   Found count option: %d\n", count);
            } else {
                printf("   Error: -c requires a number\n");
            }
        } else if (argv[i][0] == '-') {
            printf("   Unknown option: %s\n", argv[i]);
        } else {
            if (!input_file) {
                input_file = argv[i];
                printf("   Found input file: %s\n", input_file);
            } else {
                printf("   Additional positional argument: %s\n", argv[i]);
            }
        }
    }
    
    // Show parsed configuration
    printf("\n2. Parsed configuration:\n");
    printf("   Verbose: %s\n", verbose ? "enabled" : "disabled");
    printf("   Help: %s\n", help ? "requested" : "not requested");
    printf("   Quiet: %s\n", quiet ? "enabled" : "disabled");
    printf("   Output file: %s\n", output_file ? output_file : "not specified");
    printf("   Input file: %s\n", input_file ? input_file : "not specified");
    printf("   Count: %d\n", count);
    
    // Handle conflicting options
    if (verbose && quiet) {
        printf("   Warning: Both verbose and quiet flags specified!\n");
    }
    
    printf("\n");
}

void demonstrate_file_processing(int argc, char *argv[]) {
    printf("3. FILE PROCESSING WITH ARGUMENTS\n");
    printf("----------------------------------------\n");
    
    printf("Processing files specified as arguments:\n\n");
    
    // Look for file arguments
    int files_processed = 0;
    int verbose = 0;
    
    // Check for verbose flag first
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
            break;
        }
    }
    
    printf("1. Processing files from command line:\n");
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {  // Skip options, process files
            if (process_file(argv[i], verbose)) {
                files_processed++;
            }
        }
    }
    
    if (files_processed == 0) {
        printf("   No valid files found in arguments\n");
        printf("   Available test files: sample1.txt, sample2.txt, data.csv\n");
        
        // Process default files for demonstration
        printf("\n2. Processing default test files:\n");
        const char *test_files[] = {"sample1.txt", "sample2.txt", "data.csv"};
        for (int i = 0; i < 3; i++) {
            if (process_file(test_files[i], verbose)) {
                files_processed++;
            }
        }
    }
    
    printf("\nTotal files processed: %d\n", files_processed);
    printf("\n");
}

void demonstrate_advanced_parsing(int argc, char *argv[]) {
    printf("4. ADVANCED ARGUMENT PARSING\n");
    printf("----------------------------------------\n");
    
    printf("Advanced parsing techniques:\n\n");
    
    // Handle long options with equals sign
    printf("1. Long options with values (--option=value):\n");
    for (int i = 1; i < argc; i++) {
        if (strncmp(argv[i], "--", 2) == 0) {
            char *equals = strchr(argv[i], '=');
            if (equals) {
                *equals = '\0';  // Temporarily split
                char *option = argv[i] + 2;  // Skip "--"
                char *value = equals + 1;
                printf("   Option: %s, Value: %s\n", option, value);
                *equals = '=';  // Restore original string
            } else {
                printf("   Long option: %s (no value)\n", argv[i] + 2);
            }
        }
    }
    
    // Handle combined short options
    printf("2. Combined short options (-abc = -a -b -c):\n");
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] != '-' && strlen(argv[i]) > 2) {
            printf("   Combined option: %s\n", argv[i]);
            for (size_t j = 1; j < strlen(argv[i]); j++) {
                printf("     Individual flag: -%c\n", argv[i][j]);
            }
        }
    }
    
    // Subcommand parsing
    printf("3. Subcommand detection:\n");
    if (argc > 1 && argv[1][0] != '-') {
        const char *subcommands[] = {"create", "delete", "list", "help"};
        int is_subcommand = 0;
        
        for (int i = 0; i < 4; i++) {
            if (strcmp(argv[1], subcommands[i]) == 0) {
                printf("   Detected subcommand: %s\n", argv[1]);
                printf("   Remaining arguments for subcommand:\n");
                for (int j = 2; j < argc; j++) {
                    printf("     %s\n", argv[j]);
                }
                is_subcommand = 1;
                break;
            }
        }
        
        if (!is_subcommand) {
            printf("   First argument '%s' is not a recognized subcommand\n", argv[1]);
        }
    } else {
        printf("   No subcommand provided\n");
    }
    
    // Environment variable integration
    printf("4. Environment variable integration:\n");
    char *env_config = getenv("DEMO_CONFIG");
    if (env_config) {
        printf("   Environment config: %s\n", env_config);
    } else {
        printf("   No DEMO_CONFIG environment variable set\n");
    }
    
    // Check for config file override
    char *config_file = "default.conf";
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--config") == 0 && i + 1 < argc) {
            config_file = argv[++i];
            break;
        }
    }
    printf("   Using config file: %s\n", config_file);
    
    printf("\n");
}

void demonstrate_error_handling(int argc, char *argv[]) {
    printf("5. ERROR HANDLING\n");
    printf("----------------------------------------\n");
    
    printf("Proper error handling for command line arguments:\n\n");
    
    // Required argument checking
    printf("1. Required argument validation:\n");
    int has_required = 0;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            has_required = 1;
            break;
        }
    }
    
    if (!has_required) {
        printf("   No input file specified (would show usage in real program)\n");
        show_usage(argv[0]);
    } else {
        printf("   ✓ Input file requirement satisfied\n");
    }
    
    // Numeric argument validation
    printf("2. Numeric argument validation:\n");
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--number") == 0) {
            if (i + 1 < argc) {
                char *endptr;
                long value = strtol(argv[i + 1], &endptr, 10);
                
                if (*endptr == '\0' && value >= 0) {
                    printf("   ✓ Valid number: %ld\n", value);
                } else {
                    printf("   ✗ Invalid number: %s\n", argv[i + 1]);
                }
                i++;  // Skip the number argument
            } else {
                printf("   ✗ Missing number after %s\n", argv[i]);
            }
        }
    }
    
    // File existence validation
    printf("3. File existence validation:\n");
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {  // Positional argument (likely filename)
            FILE *file = fopen(argv[i], "r");
            if (file) {
                printf("   ✓ File exists: %s\n", argv[i]);
                fclose(file);
            } else {
                printf("   ✗ File not found: %s\n", argv[i]);
            }
        }
    }
    
    // Option conflict detection
    printf("4. Option conflict detection:\n");
    int verbose = 0, quiet = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) verbose = 1;
        if (strcmp(argv[i], "-q") == 0) quiet = 1;
    }
    
    if (verbose && quiet) {
        printf("   ✗ Conflicting options: -v (verbose) and -q (quiet)\n");
    } else {
        printf("   ✓ No conflicting options detected\n");
    }
    
    // Unknown option detection
    printf("5. Unknown option detection:\n");
    const char *known_options[] = {"-v", "--verbose", "-q", "--quiet", 
                                  "-h", "--help", "-o", "--output", 
                                  "-c", "--count", "-n", "--number"};
    int known_count = sizeof(known_options) / sizeof(known_options[0]);
    
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            int is_known = 0;
            for (int j = 0; j < known_count; j++) {
                if (strcmp(argv[i], known_options[j]) == 0) {
                    is_known = 1;
                    break;
                }
            }
            
            if (!is_known) {
                printf("   ✗ Unknown option: %s\n", argv[i]);
                printf("     Try '%s --help' for available options\n", argv[0]);
            }
        }
    }
    
    printf("\n");
}

void demonstrate_practical_examples(int argc, char *argv[]) {
    printf("6. PRACTICAL EXAMPLES\n");
    printf("----------------------------------------\n");
    
    printf("Real-world command line processing patterns:\n\n");
    
    // Example 1: File converter
    printf("1. File converter pattern:\n");
    char *input_file = NULL;
    char *output_file = NULL;
    char *format = "txt";
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            format = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            output_file = argv[++i];
        } else if (argv[i][0] != '-' && !input_file) {
            input_file = argv[i];
        }
    }
    
    printf("   Input: %s\n", input_file ? input_file : "stdin");
    printf("   Output: %s\n", output_file ? output_file : "stdout");
    printf("   Format: %s\n", format);
    
    // Example 2: Server configuration
    printf("2. Server configuration pattern:\n");
    Config config = parse_arguments(argc, argv);
    printf("   Host: %s\n", config.host);
    printf("   Port: %d\n", config.port);
    printf("   Verbose: %s\n", config.verbose ? "yes" : "no");
    
    // Example 3: Batch file processor
    printf("3. Batch file processor pattern:\n");
    int file_count = 0;
    char *files[100];  // Max 100 files
    
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' && file_count < 100) {
            files[file_count++] = argv[i];
        }
    }
    
    printf("   Files to process: %d\n", file_count);
    for (int i = 0; i < file_count && i < 5; i++) {  // Show first 5
        printf("     %d. %s\n", i + 1, files[i]);
    }
    if (file_count > 5) {
        printf("     ... and %d more files\n", file_count - 5);
    }
    
    // Example 4: Help system
    printf("4. Help system:\n");
    int show_help_flag = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            show_help_flag = 1;
            break;
        }
    }
    
    if (show_help_flag) {
        printf("   Help requested - would show:\n");
        show_help(argv[0]);
    } else {
        printf("   No help requested\n");
    }
    
    printf("\n");
}

// Utility function implementations
void show_help(const char *program_name) {
    printf("     Usage: %s [OPTIONS] [FILES...]\n", program_name);
    printf("     \n");
    printf("     OPTIONS:\n");
    printf("       -v, --verbose     Enable verbose output\n");
    printf("       -q, --quiet       Suppress output\n");
    printf("       -o, --output FILE Output to FILE\n");
    printf("       -c, --count NUM   Set count to NUM\n");
    printf("       -h, --help        Show this help\n");
    printf("       --host HOST       Set server host\n");
    printf("       --port PORT       Set server port\n");
    printf("     \n");
    printf("     EXAMPLES:\n");
    printf("       %s file.txt              Process file.txt\n", program_name);
    printf("       %s -v -o out.txt in.txt  Verbose processing\n", program_name);
    printf("       %s --host=localhost      Set host\n", program_name);
}

void show_usage(const char *program_name) {
    printf("   Usage: %s [OPTIONS] <input_file>\n", program_name);
    printf("   Try '%s --help' for more information.\n", program_name);
}

Config parse_arguments(int argc, char *argv[]) {
    Config config = {0, 0, NULL, NULL, 10, 8080, "localhost"};
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            config.verbose = 1;
        } else if (strcmp(argv[i], "-h") == 0) {
            config.help = 1;
        } else if (strncmp(argv[i], "--host=", 7) == 0) {
            config.host = argv[i] + 7;
        } else if (strncmp(argv[i], "--port=", 7) == 0) {
            config.port = atoi(argv[i] + 7);
        } else if (strcmp(argv[i], "--port") == 0 && i + 1 < argc) {
            config.port = atoi(argv[++i]);
        }
    }
    
    return config;
}

int process_file(const char *filename, int verbose) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        if (verbose) {
            printf("   ✗ Cannot open: %s\n", filename);
        }
        return 0;
    }
    
    // Count lines and characters
    int lines = 0, chars = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        chars++;
        if (c == '\n') lines++;
    }
    
    fclose(file);
    
    if (verbose) {
        printf("   ✓ Processed: %s (%d lines, %d chars)\n", 
               filename, lines, chars);
    } else {
        printf("   ✓ %s\n", filename);
    }
    
    return 1;
}

void create_sample_files(void) {
    // Create sample1.txt
    FILE *file = fopen("sample1.txt", "w");
    if (file) {
        fprintf(file, "This is sample file 1.\n");
        fprintf(file, "It contains some text for testing.\n");
        fprintf(file, "Command line arguments can specify this file.\n");
        fclose(file);
    }
    
    // Create sample2.txt
    file = fopen("sample2.txt", "w");
    if (file) {
        fprintf(file, "Sample file number 2.\n");
        fprintf(file, "Different content for variety.\n");
        fclose(file);
    }
    
    // Create data.csv
    file = fopen("data.csv", "w");
    if (file) {
        fprintf(file, "Name,Age,City\n");
        fprintf(file, "Alice,25,New York\n");
        fprintf(file, "Bob,30,San Francisco\n");
        fclose(file);
    }
}

void cleanup_test_files(void) {
    printf("Cleaning up test files...\n");
    const char *files[] = {"sample1.txt", "sample2.txt", "data.csv"};
    
    int cleaned = 0;
    for (size_t i = 0; i < sizeof(files) / sizeof(files[0]); i++) {
        if (remove(files[i]) == 0) {
            cleaned++;
        }
    }
    
    printf("✓ Cleaned up %d test files\n", cleaned);
}

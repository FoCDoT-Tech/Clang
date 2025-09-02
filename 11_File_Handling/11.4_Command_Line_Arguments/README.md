# 11.4 Command Line Arguments

Command line arguments allow programs to receive input parameters when executed, enabling flexible and interactive program behavior.

## Main Function Parameters

### **Standard Form**
```c
int main(int argc, char *argv[])
```
- `argc` - Argument count (includes program name)
- `argv` - Argument vector (array of string pointers)

### **Alternative Forms**
```c
int main(int argc, char **argv)     // Equivalent pointer notation
int main(void)                      // No arguments
```

## Argument Structure

### **argv Array Layout**
- `argv[0]` - Program name (or path)
- `argv[1]` - First argument
- `argv[2]` - Second argument
- ...
- `argv[argc-1]` - Last argument
- `argv[argc]` - NULL pointer

### **Example Command**
```bash
./program file.txt -v --output result.txt
```
- `argc = 5`
- `argv[0] = "./program"`
- `argv[1] = "file.txt"`
- `argv[2] = "-v"`
- `argv[3] = "--output"`
- `argv[4] = "result.txt"`

## Basic Processing

### **Argument Iteration**
```c
for (int i = 1; i < argc; i++) {
    printf("Argument %d: %s\n", i, argv[i]);
}
```

### **Simple Flag Detection**
```c
int verbose = 0;
for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-v") == 0) {
        verbose = 1;
    }
}
```

## Argument Types

### **Flags (Boolean Options)**
- `-v`, `--verbose` - Enable verbose output
- `-h`, `--help` - Show help
- `-q`, `--quiet` - Suppress output

### **Options with Values**
- `-o filename` - Output file
- `--input=file.txt` - Input file
- `-n 10` - Numeric parameter

### **Positional Arguments**
- Input files: `program file1.txt file2.txt`
- Required parameters in specific order

## Parsing Strategies

### **Manual Parsing**
```c
for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
        // Handle option
        if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 < argc) {
                output_file = argv[++i];
            }
        }
    } else {
        // Handle positional argument
        input_files[file_count++] = argv[i];
    }
}
```

### **getopt() Function** (POSIX)
```c
#include <unistd.h>

int opt;
while ((opt = getopt(argc, argv, "vo:h")) != -1) {
    switch (opt) {
        case 'v': verbose = 1; break;
        case 'o': output_file = optarg; break;
        case 'h': show_help(); break;
    }
}
```

## Error Handling

### **Argument Validation**
```c
if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
}
```

### **File Existence Check**
```c
FILE *file = fopen(argv[1], "r");
if (!file) {
    fprintf(stderr, "Error: Cannot open %s\n", argv[1]);
    return 1;
}
```

### **Numeric Conversion**
```c
int number = atoi(argv[2]);
if (number == 0 && strcmp(argv[2], "0") != 0) {
    fprintf(stderr, "Error: Invalid number %s\n", argv[2]);
    return 1;
}
```

## Common Patterns

### **Help System**
```c
void show_help(const char *program_name) {
    printf("Usage: %s [OPTIONS] <files...>\n", program_name);
    printf("Options:\n");
    printf("  -v, --verbose    Enable verbose output\n");
    printf("  -o FILE          Output to FILE\n");
    printf("  -h, --help       Show this help\n");
}
```

### **Configuration Override**
```c
// Default values
int port = 8080;
char *host = "localhost";

// Override from command line
for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--port") == 0 && i + 1 < argc) {
        port = atoi(argv[++i]);
    } else if (strcmp(argv[i], "--host") == 0 && i + 1 < argc) {
        host = argv[++i];
    }
}
```

### **File Processing**
```c
// Process all files given as arguments
for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {  // Skip options
        process_file(argv[i]);
    }
}
```

## Advanced Features

### **Long Options**
```c
// Handle --option=value format
char *equals = strchr(argv[i], '=');
if (equals) {
    *equals = '\0';  // Split at '='
    char *option = argv[i];
    char *value = equals + 1;
}
```

### **Environment Integration**
```c
// Combine command line with environment
char *config_file = getenv("CONFIG_FILE");
if (argc > 1) {
    config_file = argv[1];  // Override with command line
}
```

### **Subcommands**
```c
if (argc > 1) {
    if (strcmp(argv[1], "create") == 0) {
        handle_create(argc - 1, argv + 1);
    } else if (strcmp(argv[1], "delete") == 0) {
        handle_delete(argc - 1, argv + 1);
    }
}
```

## Best Practices

### **Validate Early**
```c
// Check arguments before processing
if (argc < 2) {
    show_help(argv[0]);
    return 1;
}
```

### **Provide Good Error Messages**
```c
fprintf(stderr, "Error: File '%s' not found\n", argv[1]);
fprintf(stderr, "Try '%s --help' for usage information\n", argv[0]);
```

### **Support Standard Conventions**
- Use `-h` or `--help` for help
- Use `-v` or `--verbose` for verbose output
- Use `-o` for output file specification
- Return 0 for success, non-zero for errors

### **Handle Edge Cases**
```c
// Empty arguments
if (argc > 1 && strlen(argv[1]) == 0) {
    fprintf(stderr, "Error: Empty argument\n");
    return 1;
}

// Very long arguments
if (argc > 1 && strlen(argv[1]) > MAX_PATH) {
    fprintf(stderr, "Error: Argument too long\n");
    return 1;
}
```

## Code Example

Run the demo to see command line argument processing:
```bash
make run
```

The demo demonstrates:
- Basic argument parsing and validation
- Different argument types (flags, options, positional)
- Error handling and help systems
- File processing with command line input
- Advanced parsing techniques
- Real-world usage patterns

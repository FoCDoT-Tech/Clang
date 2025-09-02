# 11.1 File Operations

File operations enable reading from and writing to files, providing persistent data storage beyond program execution.

## Opening Files

The `fopen()` function opens a file and returns a file pointer:
```c
FILE *fopen(const char *filename, const char *mode);
```

## File Modes

### **Text Modes**
- `"r"` - Read only (file must exist)
- `"w"` - Write only (creates new/overwrites existing)
- `"a"` - Append (creates new/appends to existing)
- `"r+"` - Read and write (file must exist)
- `"w+"` - Read and write (creates new/overwrites existing)
- `"a+"` - Read and append (creates new/appends to existing)

### **Binary Modes**
Add `b` to any mode for binary operations:
- `"rb"`, `"wb"`, `"ab"`, `"r+b"`, `"w+b"`, `"a+b"`

## Closing Files

Always close files with `fclose()`:
```c
int fclose(FILE *stream);
```

## Error Handling

Check for NULL return from `fopen()`:
```c
FILE *file = fopen("data.txt", "r");
if (file == NULL) {
    perror("Error opening file");
    return -1;
}
```

## File Pointer

`FILE *` is an opaque pointer that:
- Tracks current position in file
- Maintains file state and buffers
- Required for all file operations

## Best Practices

### **Always Check for Errors**
```c
FILE *file = fopen("file.txt", "r");
if (!file) {
    perror("fopen failed");
    exit(1);
}
```

### **Close Files Properly**
```c
if (fclose(file) != 0) {
    perror("fclose failed");
}
```

### **Use Appropriate Modes**
- Use binary mode for non-text files
- Use append mode to preserve existing data
- Use read-write modes carefully

## Common Patterns

### **Safe File Opening**
```c
FILE *safe_fopen(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (!file) {
        fprintf(stderr, "Cannot open %s: ", filename);
        perror("");
        exit(1);
    }
    return file;
}
```

### **File Existence Check**
```c
int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}
```

## Code Example

Run the demo to see file operations in action:
```bash
make run
```

The demo demonstrates:
- Opening files with different modes
- Error handling for file operations
- Creating, reading, and writing files
- Proper file closure and cleanup
- File existence checking
- Safe file operation patterns

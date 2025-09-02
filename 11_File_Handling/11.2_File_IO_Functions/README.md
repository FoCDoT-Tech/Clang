# 11.2 File I/O Functions

File I/O functions provide different methods to read from and write to files, each optimized for specific data types and use cases.

## Character I/O

### **Reading Characters**
```c
int fgetc(FILE *stream);    // Read single character
int getc(FILE *stream);     // Faster macro version
```

### **Writing Characters**
```c
int fputc(int c, FILE *stream);    // Write single character
int putc(int c, FILE *stream);     // Faster macro version
```

### **Unget Character**
```c
int ungetc(int c, FILE *stream);   // Push character back
```

## String I/O

### **Reading Strings**
```c
char *fgets(char *str, int n, FILE *stream);
```
- Reads up to `n-1` characters or until newline
- Null-terminates the string
- Includes newline character if found

### **Writing Strings**
```c
int fputs(const char *str, FILE *stream);
```
- Writes string without adding newline
- Returns non-negative on success

## Formatted I/O

### **Formatted Input**
```c
int fscanf(FILE *stream, const char *format, ...);
```
- Similar to `scanf()` but reads from file
- Returns number of items successfully read

### **Formatted Output**
```c
int fprintf(FILE *stream, const char *format, ...);
```
- Similar to `printf()` but writes to file
- Returns number of characters written

## Binary I/O

### **Reading Binary Data**
```c
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
```
- Reads `count` items of `size` bytes each
- Returns number of items successfully read

### **Writing Binary Data**
```c
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
```
- Writes `count` items of `size` bytes each
- Returns number of items successfully written

## Function Comparison

| Function | Use Case | Advantages | Disadvantages |
|----------|----------|------------|---------------|
| `fgetc/fputc` | Single characters | Simple, precise control | Slow for large data |
| `fgets/fputs` | Text lines | Handles strings naturally | Text-only |
| `fscanf/fprintf` | Formatted data | Easy parsing/formatting | Complex format strings |
| `fread/fwrite` | Binary data | Fast, any data type | No automatic formatting |

## Best Practices

### **Choose Right Function**
- Use `fgetc/fputc` for character-by-character processing
- Use `fgets/fputs` for line-based text processing
- Use `fscanf/fprintf` for structured data
- Use `fread/fwrite` for binary data and performance

### **Error Checking**
```c
// Check return values
if (fgets(buffer, sizeof(buffer), file) == NULL) {
    if (feof(file)) {
        printf("End of file reached\n");
    } else {
        perror("Read error");
    }
}
```

### **Buffer Management**
```c
// Always provide buffer size
char buffer[256];
fgets(buffer, sizeof(buffer), file);  // Safe

// Remove newline if present
char *newline = strchr(buffer, '\n');
if (newline) *newline = '\0';
```

### **Binary Data Handling**
```c
// Check actual bytes read/written
size_t items_read = fread(data, sizeof(int), count, file);
if (items_read != count) {
    if (feof(file)) {
        printf("End of file: read %zu items\n", items_read);
    } else {
        perror("Read error");
    }
}
```

## Common Patterns

### **Line Processing**
```c
char line[256];
while (fgets(line, sizeof(line), file)) {
    // Remove newline
    line[strcspn(line, "\n")] = '\0';
    // Process line
    process_line(line);
}
```

### **Binary File Processing**
```c
struct record data;
while (fread(&data, sizeof(data), 1, file) == 1) {
    process_record(&data);
}
```

### **Formatted Data Processing**
```c
int id;
char name[50];
float grade;
while (fscanf(file, "%d %49s %f", &id, name, &grade) == 3) {
    process_student(id, name, grade);
}
```

## Code Example

Run the demo to see file I/O functions in action:
```bash
make run
```

The demo demonstrates:
- Character I/O operations with `fgetc/fputc`
- String I/O with `fgets/fputs`
- Formatted I/O using `fscanf/fprintf`
- Binary I/O with `fread/fwrite`
- Error handling and best practices
- Performance comparisons between methods

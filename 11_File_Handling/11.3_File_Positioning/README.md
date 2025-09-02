# 11.3 File Positioning

File positioning functions allow you to move the file pointer to specific locations, enabling random access to file data.

## File Position Functions

### **fseek() - Set File Position**
```c
int fseek(FILE *stream, long offset, int whence);
```
- `offset`: Number of bytes to move
- `whence`: Starting position reference

### **Whence Values**
- `SEEK_SET` (0) - Beginning of file
- `SEEK_CUR` (1) - Current position
- `SEEK_END` (2) - End of file

### **ftell() - Get Current Position**
```c
long ftell(FILE *stream);
```
- Returns current file position as bytes from beginning
- Returns -1L on error

### **rewind() - Reset to Beginning**
```c
void rewind(FILE *stream);
```
- Equivalent to `fseek(stream, 0L, SEEK_SET)`
- Also clears error indicators

## File Status Functions

### **feof() - Check End of File**
```c
int feof(FILE *stream);
```
- Returns non-zero if end-of-file indicator is set
- Use after read operations to distinguish EOF from errors

### **ferror() - Check Error Status**
```c
int ferror(FILE *stream);
```
- Returns non-zero if error indicator is set
- Use to detect I/O errors

### **clearerr() - Clear Indicators**
```c
void clearerr(FILE *stream);
```
- Clears both EOF and error indicators
- Useful for continuing after errors

## Position Examples

### **Absolute Positioning**
```c
fseek(file, 100, SEEK_SET);    // Go to byte 100
fseek(file, 0, SEEK_SET);      // Go to beginning
fseek(file, 0, SEEK_END);      // Go to end
```

### **Relative Positioning**
```c
fseek(file, 10, SEEK_CUR);     // Move forward 10 bytes
fseek(file, -5, SEEK_CUR);     // Move backward 5 bytes
fseek(file, -10, SEEK_END);    // 10 bytes before end
```

### **Getting File Size**
```c
fseek(file, 0, SEEK_END);
long size = ftell(file);
rewind(file);
```

## Binary vs Text Mode

### **Binary Mode**
- Positioning works with exact byte offsets
- All positioning operations are reliable
- Use for structured data and random access

### **Text Mode**
- Positioning may not work reliably on all systems
- Line ending translations can affect positions
- Use `fseek()` with caution in text mode

## Common Patterns

### **Random Access Records**
```c
typedef struct {
    int id;
    char name[32];
    float value;
} Record;

// Read record at specific index
void read_record(FILE *file, int index, Record *rec) {
    fseek(file, index * sizeof(Record), SEEK_SET);
    fread(rec, sizeof(Record), 1, file);
}
```

### **File Size Calculation**
```c
long get_file_size(FILE *file) {
    long current = ftell(file);  // Save current position
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, current, SEEK_SET);  // Restore position
    return size;
}
```

### **Reverse File Reading**
```c
void read_backwards(FILE *file) {
    fseek(file, -1, SEEK_END);
    while (ftell(file) > 0) {
        int c = fgetc(file);
        printf("%c", c);
        fseek(file, -2, SEEK_CUR);  // Move back 2 positions
    }
}
```

## Error Handling

### **Check fseek() Return Value**
```c
if (fseek(file, offset, SEEK_SET) != 0) {
    perror("fseek failed");
    return -1;
}
```

### **Validate ftell() Result**
```c
long pos = ftell(file);
if (pos == -1L) {
    perror("ftell failed");
    return -1;
}
```

### **Handle EOF vs Error**
```c
if (fgetc(file) == EOF) {
    if (feof(file)) {
        printf("End of file reached\n");
    } else if (ferror(file)) {
        printf("Read error occurred\n");
    }
}
```

## Best Practices

### **Save and Restore Position**
```c
long saved_pos = ftell(file);
// Do operations that change position
fseek(file, saved_pos, SEEK_SET);  // Restore
```

### **Use Binary Mode for Random Access**
```c
FILE *file = fopen("data.bin", "r+b");  // Binary mode
```

### **Check Bounds Before Seeking**
```c
long file_size = get_file_size(file);
if (offset >= 0 && offset < file_size) {
    fseek(file, offset, SEEK_SET);
}
```

## Limitations

### **Large Files**
- `ftell()` and `fseek()` use `long` (32-bit on some systems)
- Use `fgetpos()` and `fsetpos()` for large files
- Consider platform-specific extensions

### **Text Mode Issues**
- Line ending conversions affect positioning
- Seeking to arbitrary positions may fail
- Use binary mode for reliable positioning

## Code Example

Run the demo to see file positioning in action:
```bash
make run
```

The demo demonstrates:
- Basic positioning with `fseek()` and `ftell()`
- Random access to structured data
- File size calculation techniques
- Reverse file reading
- Error handling and status checking
- Performance considerations for different access patterns

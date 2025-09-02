# 7.3 Strings

Strings in C are arrays of characters terminated by a null character (`\0`). Understanding string representation and manipulation is essential for text processing and user interaction.

## String Fundamentals

### 1. **String Representation**
```c
char str1[] = "Hello";           // Character array with null terminator
char str2[6] = {'H','e','l','l','o','\0'};  // Manual initialization
char str3[10] = "World";         // Extra space for modifications
char *str4 = "Constant";         // String literal (read-only)
```

### 2. **String Literals**
- Enclosed in double quotes: `"Hello World"`
- Automatically null-terminated by compiler
- Stored in read-only memory section
- Can be assigned to `char*` pointers

### 3. **Character Arrays vs Strings**
```c
char chars[] = {'A', 'B', 'C'};        // Character array (no null terminator)
char string[] = {'A', 'B', 'C', '\0'}; // String (null-terminated)
char string2[] = "ABC";                 // Equivalent to above
```

### 4. **Null Terminator**
- Special character `\0` (ASCII value 0)
- Marks the end of string
- Not counted in string length but occupies memory
- Essential for string functions to work correctly

## Key Concepts

### **String Properties**
- **Mutable**: Character arrays can be modified
- **Immutable**: String literals cannot be changed
- **Length**: Number of characters before null terminator
- **Size**: Total memory including null terminator

### **String Operations**
- **Input**: `scanf()`, `fgets()`, `getchar()`
- **Output**: `printf()`, `puts()`, `putchar()`
- **Access**: Individual characters via indexing
- **Modification**: Change characters directly

### **Memory Considerations**
- Always allocate space for null terminator
- Avoid buffer overflows with proper sizing
- String literals stored in read-only memory
- Character arrays stored on stack or heap

## Best Practices

- Always null-terminate manually created strings
- Use `fgets()` instead of `gets()` for safe input
- Check string bounds before modifications
- Initialize string arrays to avoid garbage values
- Use `const char*` for read-only string parameters

## Code Examples

Run the demo to see strings in action:
```bash
make run
```

The demo covers:
- String declaration and initialization methods
- String input and output operations
- Character array manipulation
- String length and memory concepts
- Practical examples with text processing

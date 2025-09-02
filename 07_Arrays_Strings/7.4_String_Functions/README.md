# 7.4 String Functions

The C standard library provides powerful functions for string manipulation. These functions handle common string operations efficiently and safely when used correctly.

## Standard String Functions

### 1. **String Length**
```c
#include <string.h>
size_t strlen(const char *str);
```
- Returns number of characters before null terminator
- Does not count the null terminator itself

### 2. **String Copy**
```c
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
```
- `strcpy()`: Copies entire string including null terminator
- `strncpy()`: Copies at most n characters (safer)

### 3. **String Concatenation**
```c
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);
```
- `strcat()`: Appends src to end of dest
- `strncat()`: Appends at most n characters

### 4. **String Comparison**
```c
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t n);
```
- Returns: negative (str1 < str2), zero (equal), positive (str1 > str2)
- `strncmp()`: Compares first n characters only

### 5. **String Search**
```c
char *strchr(const char *str, int c);
char *strrchr(const char *str, int c);
char *strstr(const char *haystack, const char *needle);
```
- `strchr()`: Find first occurrence of character
- `strrchr()`: Find last occurrence of character
- `strstr()`: Find first occurrence of substring

### 6. **Formatted String Operations**
```c
int sprintf(char *str, const char *format, ...);
int sscanf(const char *str, const char *format, ...);
```
- `sprintf()`: Write formatted data to string
- `sscanf()`: Read formatted data from string

## Key Concepts

### **Safety Considerations**
- Always ensure destination buffer is large enough
- Use `strncpy()`, `strncat()`, `strncmp()` for bounds checking
- Check for NULL pointers before using string functions
- Be aware of buffer overflow vulnerabilities

### **Return Values**
- Most functions return pointers to destination or found location
- Comparison functions return integer values
- Always check return values for error conditions

### **Performance**
- String functions are optimized in standard library
- Avoid repeated `strlen()` calls in loops
- Consider custom functions for specific needs

## Best Practices

- Use safer variants (`strncpy`, `strncat`) when possible
- Always null-terminate strings when using `strncpy`
- Check buffer sizes before string operations
- Use `const` for read-only string parameters
- Handle NULL pointer cases gracefully

## Code Examples

Run the demo to see string functions in action:
```bash
make run
```

The demo covers:
- All major string library functions with examples
- Safe string manipulation techniques
- Formatted string operations and parsing
- Text processing and analysis applications
- Custom string utilities building on standard functions

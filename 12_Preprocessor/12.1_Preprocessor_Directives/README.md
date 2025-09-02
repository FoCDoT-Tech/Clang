# 12.1 Preprocessor Directives

Preprocessor directives are commands processed before compilation, enabling code inclusion, macro definition, and conditional compilation.

## #include Directive

### **File Inclusion**
```c
#include <stdio.h>      // System headers (angle brackets)
#include "myheader.h"   // User headers (quotes)
```

### **Search Paths**
- `<>` - System include directories
- `""` - Current directory first, then system directories

### **Common System Headers**
- `<stdio.h>` - Input/output functions
- `<stdlib.h>` - Standard library functions
- `<string.h>` - String manipulation
- `<math.h>` - Mathematical functions

## #define Directive

### **Object-like Macros**
```c
#define PI 3.14159
#define MAX_SIZE 100
#define BUFFER_SIZE 1024
```

### **Function-like Macros**
```c
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define DEBUG_PRINT(msg) printf("DEBUG: %s\n", msg)
```

### **Multi-line Macros**
```c
#define SWAP(a, b) do { \
    typeof(a) temp = (a); \
    (a) = (b); \
    (b) = temp; \
} while(0)
```

## #undef Directive

### **Undefining Macros**
```c
#define TEMP_MACRO 42
// Use TEMP_MACRO
#undef TEMP_MACRO
// TEMP_MACRO no longer defined
```

## Conditional Directives

### **#ifdef / #ifndef**
```c
#ifdef DEBUG
    printf("Debug mode enabled\n");
#endif

#ifndef MAX_BUFFER
    #define MAX_BUFFER 512
#endif
```

### **#if / #elif / #else**
```c
#if VERSION >= 2
    // Version 2+ code
#elif VERSION == 1
    // Version 1 code
#else
    // Default code
#endif
```

### **Defined Operator**
```c
#if defined(WINDOWS) || defined(WIN32)
    // Windows-specific code
#endif
```

## Practical Examples

### **Header Guards**
```c
#ifndef MYHEADER_H
#define MYHEADER_H

// Header content here

#endif /* MYHEADER_H */
```

### **Configuration Macros**
```c
#define VERSION_MAJOR 1
#define VERSION_MINOR 2
#define VERSION_PATCH 3

#define STRINGIFY(x) #x
#define VERSION_STRING STRINGIFY(VERSION_MAJOR.VERSION_MINOR.VERSION_PATCH)
```

### **Platform Detection**
```c
#ifdef _WIN32
    #define PLATFORM "Windows"
#elif defined(__linux__)
    #define PLATFORM "Linux"
#elif defined(__APPLE__)
    #define PLATFORM "macOS"
#else
    #define PLATFORM "Unknown"
#endif
```

## Best Practices

### **Macro Naming**
- Use UPPERCASE for constants
- Use descriptive names
- Avoid common words that might conflict

### **Parentheses in Macros**
```c
#define BAD_SQUARE(x) x * x           // Dangerous
#define GOOD_SQUARE(x) ((x) * (x))    // Safe
```

### **Side Effects**
```c
#define BAD_MAX(a, b) ((a) > (b) ? (a) : (b))  // Evaluates twice
// Better to use inline functions for complex operations
```

### **Include Guards vs #pragma once**
```c
// Traditional (portable)
#ifndef HEADER_H
#define HEADER_H
// content
#endif

// Modern (compiler-specific)
#pragma once
// content
```

## Code Example

Run the demo to see preprocessor directives in action:
```bash
make run
```

The demo demonstrates:
- File inclusion with different header types
- Object-like and function-like macro definitions
- Conditional compilation based on defines
- Macro undefining and redefinition
- Header guard implementation
- Platform-specific code compilation

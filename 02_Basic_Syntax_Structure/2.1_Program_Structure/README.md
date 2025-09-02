# 2.1 Program Structure

## Include Directives

### Purpose
- Include header files containing function declarations
- Provide access to standard library functions
- Enable code reuse and modularity

### Syntax
```c
#include <stdio.h>      // System headers (angle brackets)
#include "myheader.h"   // User headers (quotes)
```

### Common Headers
- `<stdio.h>` - Input/output functions
- `<stdlib.h>` - Memory allocation, conversions
- `<string.h>` - String manipulation
- `<math.h>` - Mathematical functions

## Main Function

### Standard Form
```c
int main() {
    // Program code
    return 0;
}
```

### With Command Line Arguments
```c
int main(int argc, char *argv[]) {
    // argc = argument count
    // argv = argument values
    return 0;
}
```

### Key Points
- Entry point of every C program
- Must return `int` (exit status)
- `return 0` indicates success
- Non-zero return indicates error

## Function Declarations vs Definitions

### Declaration (Prototype)
```c
int add(int a, int b);  // Tells compiler function exists
```

### Definition
```c
int add(int a, int b) { // Actual implementation
    return a + b;
}
```

## Comments

### Single-line Comments
```c
// This is a single-line comment
int x = 5;  // Comment at end of line
```

### Multi-line Comments
```c
/*
 * This is a multi-line comment
 * Used for longer explanations
 */
```

### Best Practices
- Explain **why**, not **what**
- Keep comments concise and relevant
- Update comments when code changes

## Code Example

The [`program_structure_demo.c`](program_structure_demo.c) demonstrates all essential components of C program structure.

**Run the code:**
```bash
gcc program_structure_demo.c -o program_structure_demo && ./program_structure_demo
```

# 1.3 First Program

## Hello World Program

Every C program starts with the classic "Hello World" example. This simple program demonstrates the basic structure of C code.

## Program Structure

### Essential Components
1. **Preprocessor Directives**: `#include` statements
2. **Main Function**: Entry point of every C program
3. **Statements**: Instructions ending with semicolons
4. **Return Statement**: Exit status of the program

### Basic Template
```c
#include <stdio.h>

int main() {
    // Your code here
    return 0;
}
```

## Compilation Process

### Steps in Compilation
1. **Preprocessing**: Handle `#include`, `#define` directives
2. **Compilation**: Convert C code to assembly
3. **Assembly**: Convert assembly to object code
4. **Linking**: Combine object files and libraries

### Command Line Process
```bash
# Single step compilation
gcc hello.c -o hello

# Step-by-step process
gcc -E hello.c -o hello.i    # Preprocessing
gcc -S hello.i -o hello.s    # Compilation
gcc -c hello.s -o hello.o    # Assembly
gcc hello.o -o hello         # Linking
```

## Linking Process

### What is Linking?
- Combines your object code with standard library functions
- Resolves external function calls (like `printf`)
- Creates final executable file

### Types of Linking
- **Static Linking**: Libraries included in executable
- **Dynamic Linking**: Libraries loaded at runtime

## Common Beginner Mistakes

1. **Missing semicolon**: Every statement needs `;`
2. **Wrong main signature**: Use `int main()` not `void main()`
3. **Missing return**: Always `return 0;` for success
4. **Case sensitivity**: `Printf` ≠ `printf`
5. **Missing includes**: Need `#include <stdio.h>` for `printf`

## Code Examples

### Hello World - [`hello_world.c`](hello_world.c)
The classic first C program demonstrating basic structure.

**Run the code:**
```bash
gcc hello_world.c -o hello_world && ./hello_world
```

### Program Structure - [`program_structure.c`](program_structure.c)
Detailed breakdown of C program components with explanations.

**Run the code:**
```bash
gcc program_structure.c -o program_structure && ./program_structure
```

### Compilation Process - [`compilation_demo.c`](compilation_demo.c)
Demonstrates how preprocessor, compiler, and linker work together.

**Run the code:**
```bash
gcc compilation_demo.c -o compilation_demo -lm && ./compilation_demo
```

### Run All Examples
**Run all programs:**
```bash
make run-all
```

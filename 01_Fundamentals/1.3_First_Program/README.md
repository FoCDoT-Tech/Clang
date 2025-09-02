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
gcc hello_world.c -o hello_world

# Step-by-step process
gcc -E hello_world.c -o hello_world.i    # Preprocessing
gcc -S hello_world.i -o hello_world.s    # Compilation
gcc -c hello_world.s -o hello_world.o    # Assembly
gcc hello_world.o -o hello_world         # Linking
```

### Practical Example: Step-by-Step Compilation

Let's see what each compilation step does to our `hello_world.c` program:

**1. Preprocessing (`-E` flag):**
```bash
gcc -E hello_world.c -o hello_world.i
head -20 hello_world.i  # View first 20 lines
```
- Expands `#include <stdio.h>` (adds ~800 lines of standard library code)
- Processes `#define` macros and conditional compilation
- Removes comments
- Creates `.i` file with expanded source

**2. Compilation (`-S` flag):**
```bash
gcc -S hello_world.i -o hello_world.s
cat hello_world.s  # View assembly code
```
- Converts C code to assembly language
- Creates `.s` file with human-readable assembly instructions
- Shows `call printf` instruction for our `printf()` function

**3. Assembly (`-c` flag):**
```bash
gcc -c hello_world.s -o hello_world.o
file hello_world.o  # Check file type
objdump -t hello_world.o  # View object file symbols
```
- Converts assembly to machine code (binary)
- Creates `.o` object file (not executable yet)
- Contains unresolved references to external functions like `printf`

**4. Linking (final step):**
```bash
gcc hello_world.o -o hello_world
./hello_world  # Run the executable
```
- Links object file with standard library
- Resolves external function calls (`printf` from libc)
- Creates final executable file

**View the differences:**
```bash
# Compare file sizes
ls -la hello_world.*
# hello_world.c   314 bytes   (source code)
# hello_world.i   24KB        (after preprocessing - 567 lines!)
# hello_world.s   945 bytes   (assembly code)
# hello_world.o   744 bytes   (object file)
# hello_world     33KB        (final executable)
```

**Try it yourself:**
```bash
# Run all compilation steps
gcc -E hello_world.c -o hello_world.i
gcc -S hello_world.i -o hello_world.s  
gcc -c hello_world.s -o hello_world.o
gcc hello_world.o -o hello_world_step_by_step

# Verify it works
./hello_world_step_by_step
# Output: Hello, World!

# See how preprocessing expands the code
wc -l hello_world.c hello_world.i
# hello_world.c: 15 lines → hello_world.i: 567 lines

# Peek at the assembly code
head -10 hello_world.s
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

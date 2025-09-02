# 1.2 Development Environment

## Compiler Setup

### GCC (GNU Compiler Collection)
**Most popular C compiler, available on all platforms**

**macOS Installation:**
```bash
# Install Xcode Command Line Tools
xcode-select --install

# Or install via Homebrew
brew install gcc
```

**Linux Installation:**
```bash
# Ubuntu/Debian
sudo apt update && sudo apt install gcc

# CentOS/RHEL
sudo yum install gcc
```

**Windows Installation:**
- Install MinGW-w64 or use WSL (Windows Subsystem for Linux)

### Clang
**Modern compiler with excellent error messages**
```bash
# macOS (comes with Xcode)
clang --version

# Linux
sudo apt install clang
```

## Basic Compilation

### Command Line Compilation
```bash
# Compile source to executable
gcc program.c -o program

# Run the program
./program

# Compile with debugging info
gcc -g program.c -o program

# Compile with warnings
gcc -Wall -Wextra program.c -o program
```

### Compilation Flags
- `-o filename`: Specify output filename
- `-g`: Include debugging information
- `-Wall`: Enable all common warnings
- `-Wextra`: Enable extra warnings
- `-std=c99`: Use C99 standard
- `-O2`: Optimize for speed

## IDEs and Editors

### Lightweight Editors
- **VS Code**: Excellent C/C++ extension
- **Vim/Neovim**: Powerful with plugins
- **Emacs**: Highly customizable

### Full IDEs
- **CLion**: JetBrains C/C++ IDE
- **Code::Blocks**: Free, cross-platform
- **Dev-C++**: Windows-focused

## Makefile Basics

Makefiles automate the build process for larger projects.

### Simple Makefile Structure
```makefile
# Target: dependencies
#     command

program: program.c
	gcc -Wall program.c -o program

clean:
	rm -f program

.PHONY: clean
```

## Code Examples

### Environment Verification
The [`setup_check.c`](setup_check.c) program verifies your C development environment is properly configured.

**Run the code:**
```bash
make run
```

### Library Documentation Explorer
The [`stdlib_explorer.c`](stdlib_explorer.c) demonstrates how to explore and document C standard library functions using `stdlib.h` as an example.

**Features:**
- Shows how to find library documentation (`man` pages, header files, online resources)
- Demonstrates all major `stdlib.h` function categories
- Working examples of memory management, string conversion, utilities
- Interactive exploration of library functions with practical code

**Run the code:**
```bash
make run-explorer
```

**What you'll learn:**
- Memory management: `malloc()`, `calloc()`, `realloc()`, `free()`
- String conversion: `atoi()`, `atof()`, `strtol()` with different bases
- Utility functions: `abs()`, `rand()`, `getenv()`
- How to explore any C library systematically

## How to Explore C Libraries

### Documentation Methods
1. **Manual pages**: `man 3 malloc`, `man 3 printf`
2. **Header files**: `/usr/include/stdlib.h` (Unix/Linux systems)
3. **Online references**: [cppreference.com](https://en.cppreference.com/w/c/header/stdlib), GNU documentation
4. **IDE help**: Most modern IDEs show function signatures on hover

### Library Categories in stdlib.h
- **Memory Management**: Dynamic allocation and deallocation
- **String Conversion**: Convert strings to numbers with error handling
- **Random Numbers**: Pseudo-random number generation
- **Process Control**: Program termination and cleanup
- **Environment**: Access system environment variables
- **Searching/Sorting**: Built-in algorithms for data manipulation

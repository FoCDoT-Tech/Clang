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

## Code Example

The [`setup_check.c`](setup_check.c) program verifies your C development environment is properly configured.

**Run the code:**
```bash
make run
```

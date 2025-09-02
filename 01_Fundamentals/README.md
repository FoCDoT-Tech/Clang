# Chapter 1: Fundamentals

This chapter covers the essential foundations of C programming. Each section includes concise explanations and working code examples.

## Sections

### [1.1 Introduction to C](1.1_Introduction_to_C/)
- What is C and why learn it
- C vs other programming languages
- Applications and key characteristics
- **Code**: [`history_demo.c`](1.1_Introduction_to_C/history_demo.c) - Demonstrates C's key features
- **Run**: `gcc history_demo.c -o history_demo && ./history_demo`

### [1.2 Development Environment](1.2_Development_Environment/)
- Compiler setup (GCC, Clang)
- Command line compilation
- IDEs and Makefile basics
- **Code**: [`setup_check.c`](1.2_Development_Environment/setup_check.c) - Verify your environment
- **Run**: `make run` or `gcc setup_check.c -o setup_check && ./setup_check`

### [1.3 First Program](1.3_First_Program/)
- Hello World program structure
- Compilation and linking process
- Common beginner mistakes
- **Code**: [`hello_world.c`](1.3_First_Program/hello_world.c) - Classic first program
- **Run**: `make run-all` or `gcc hello_world.c -o hello_world && ./hello_world`

## Quick Start

```bash
# Navigate to any section
cd 1.1_Introduction_to_C

# Compile and run
gcc *.c -o demo && ./demo

# Or use Makefile
make run
```

## Learning Path

1. **Start with 1.1** - Understand what C is and why it matters
2. **Setup in 1.2** - Get your development environment ready
3. **Code in 1.3** - Write and understand your first programs

Each section builds foundational knowledge needed for the next chapters.

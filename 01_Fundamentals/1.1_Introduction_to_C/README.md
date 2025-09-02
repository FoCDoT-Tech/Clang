# 1.1 Introduction to C

## What is C?

C is a general-purpose programming language created by Dennis Ritchie at Bell Labs in 1972. It's a low-level language that provides direct access to memory and hardware while maintaining high-level programming constructs.

## Why Learn C?

- **Foundation**: C is the foundation for many modern languages (C++, Java, JavaScript)
- **Performance**: Produces fast, efficient code close to assembly language
- **Portability**: Code runs on virtually any platform with minimal changes
- **System Programming**: Used for operating systems, embedded systems, and drivers
- **Understanding**: Teaches fundamental programming concepts and memory management

## C vs Other Languages

| Feature | C | Python | Java |
|---------|---|--------|------|
| Speed | Very Fast | Slow | Medium |
| Memory Control | Manual | Automatic | Automatic |
| Learning Curve | Steep | Easy | Medium |
| Use Cases | Systems, Embedded | Scripting, AI | Enterprise, Web |

## Applications of C

- **Operating Systems**: Linux, Windows kernel components
- **Embedded Systems**: Microcontrollers, IoT devices
- **Compilers**: GCC, Clang
- **Databases**: MySQL, PostgreSQL core components
- **Game Engines**: Performance-critical components
- **Network Programming**: Low-level network protocols

## Key Characteristics

- **Procedural**: Function-based programming approach
- **Compiled**: Source code compiled to machine code
- **Static Typing**: Variable types declared at compile time
- **Manual Memory Management**: Programmer controls memory allocation/deallocation
- **Minimal Runtime**: Small runtime overhead

## Code Example

The [`history_demo.c`](history_demo.c) program demonstrates C's key features including manual memory management, system information access, and portability.

**Run the code:**
```bash
gcc history_demo.c -o history_demo && ./history_demo
```

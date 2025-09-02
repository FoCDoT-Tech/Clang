# C Language Comprehensive Index

## Table of Contents

1. [Fundamentals](#1-fundamentals)
2. [Basic Syntax & Structure](#2-basic-syntax--structure)
3. [Data Types & Variables](#3-data-types--variables)
4. [Operators](#4-operators)
5. [Control Flow](#5-control-flow)
6. [Functions](#6-functions)
7. [Arrays & Strings](#7-arrays--strings)
8. [Pointers](#8-pointers)
9. [Memory Management](#9-memory-management)
10. [Structures & Unions](#10-structures--unions)
11. [File Handling](#11-file-handling)
12. [Preprocessor](#12-preprocessor)
13. [Advanced Topics](#13-advanced-topics)
14. [Standard Library](#14-standard-library)
15. [Debugging & Tools](#15-debugging--tools)
16. [Best Practices](#16-best-practices)
17. [Recommended Learning Path](#17-recommended-learning-path)
18. [Project Ideas by Difficulty](#18-project-ideas-by-difficulty)
19. [Alphabetical C Language Reference](#19-alphabetical-c-language-reference)

---

## 1. Fundamentals

### 1.1 Introduction to C

- History and evolution of C
- Why learn C?
- C vs other programming languages
- Applications of C

### 1.2 Development Environment

- Setting up compiler (GCC, Clang, MSVC)
- IDEs and text editors
- Command line compilation
- Makefiles basics

### 1.3 First Program

- Hello World program
- Program structure
- Compilation process
- Linking process

---

## 2. Basic Syntax & Structure

### 2.1 Program Structure

- `#include` directives
- `main()` function
- Function declarations and definitions
- Comments (single-line `//`, multi-line `/* */`)

### 2.2 Identifiers & Keywords

- Naming conventions
- Reserved keywords
- Case sensitivity
- Valid identifier rules

### 2.3 Tokens

- Keywords
- Identifiers
- Constants
- String literals
- Operators
- Special symbols

---

## 3. Data Types & Variables

### 3.1 Basic Data Types

- `char` (character)
- `int` (integer)
- `float` (single precision)
- `double` (double precision)
- `void`

### 3.2 Type Modifiers

- `signed` / `unsigned`
- `short` / `long`
- `long long`
- Size variations across platforms

### 3.3 Variable Declaration & Initialization

- Declaration syntax
- Initialization
- Multiple declarations
- Scope and lifetime
- Storage classes (`auto`, `register`, `static`, `extern`)

### 3.4 Constants

- Literal constants
- `const` keyword
- `#define` preprocessor
- `enum` enumeration

### 3.5 Type Conversion

- Implicit conversion
- Explicit casting
- Type promotion rules

---

## 4. Operators

### 4.1 Arithmetic Operators

- `+`, `-`, `*`, `/`, `%`
- Unary operators (`+`, `-`)
- Increment/Decrement (`++`, `--`)

### 4.2 Relational Operators

- `<`, `>`, `<=`, `>=`
- `==`, `!=`

### 4.3 Logical Operators

- `&&` (AND)
- `||` (OR)
- `!` (NOT)

### 4.4 Bitwise Operators

- `&` (AND)
- `|` (OR)
- `^` (XOR)
- `~` (NOT)
- `<<` (left shift)
- `>>` (right shift)

### 4.5 Assignment Operators

- `=`
- Compound assignment (`+=`, `-=`, `*=`, `/=`, `%=`)
- Bitwise compound assignment

### 4.6 Other Operators

- Conditional operator (`? :`)
- `sizeof` operator
- Address operator (`&`)
- Dereference operator (`*`)
- Member access (`.`, `->`)

### 4.7 Operator Precedence & Associativity

---

## 5. Control Flow

### 5.1 Conditional Statements

- `if` statement
- `if-else` statement
- `else if` ladder
- Nested `if` statements
- `switch-case` statement

### 5.2 Loops

- `for` loop
- `while` loop
- `do-while` loop
- Nested loops

### 5.3 Jump Statements

- `break`
- `continue`
- `goto`
- `return`

---

## 6. Functions

### 6.1 Function Basics

- Function definition
- Function declaration (prototype)
- Function call
- Return statement

### 6.2 Parameters & Arguments

- Formal parameters
- Actual arguments
- Pass by value
- Pass by reference (using pointers)

### 6.3 Function Types

- `void` functions
- Functions returning values
- Functions with no parameters

### 6.4 Advanced Function Concepts

- Recursive functions
- Function pointers
- Callback functions
- Variable arguments (`stdarg.h`)

### 6.5 Scope & Storage Classes

- Local variables
- Global variables
- Static variables
- External variables

---

## 7. Arrays & Strings

### 7.1 Arrays

- One-dimensional arrays
- Array declaration and initialization
- Array indexing
- Array bounds
- Passing arrays to functions

### 7.2 Multi-dimensional Arrays

- Two-dimensional arrays
- Multi-dimensional arrays
- Memory layout
- Initialization techniques

### 7.3 Strings

- String representation
- String literals
- Character arrays vs strings
- Null terminator

### 7.4 String Functions

- `strlen()`, `strcpy()`, `strcat()`
- `strcmp()`, `strstr()`, `strchr()`
- `sprintf()`, `sscanf()`
- String manipulation techniques

---

## 8. Pointers

### 8.1 Pointer Basics

- What are pointers?
- Pointer declaration
- Address operator (`&`)
- Dereference operator (`*`)
- Null pointers

### 8.2 Pointer Arithmetic

- Increment/Decrement
- Addition/Subtraction
- Pointer comparison
- Pointer difference

### 8.3 Pointers and Arrays

- Array name as pointer
- Pointer indexing
- Pointer vs array notation

### 8.4 Pointers and Functions

- Passing pointers to functions
- Returning pointers from functions
- Function pointers

### 8.5 Advanced Pointer Concepts

- Pointer to pointer
- Array of pointers
- Pointer to array
- `const` with pointers

---

## 9. Memory Management

### 9.1 Memory Layout

- Stack vs Heap
- Code segment
- Data segment
- BSS segment

### 9.2 Dynamic Memory Allocation

- `malloc()`
- `calloc()`
- `realloc()`
- `free()`

### 9.3 Memory Leaks & Debugging

- Common memory errors
- Valgrind and memory debugging tools
- Best practices for memory management

---

## 10. Structures & Unions

### 10.1 Structures

- Structure declaration
- Structure initialization
- Accessing structure members
- Nested structures
- Array of structures

### 10.2 Pointers and Structures

- Pointer to structure
- Arrow operator (`->`)
- Dynamic allocation of structures

### 10.3 Unions

- Union declaration
- Union vs structure
- Memory sharing in unions

### 10.4 Bit Fields

- Bit field declaration
- Memory optimization
- Practical applications

### 10.5 `typedef`

- Creating type aliases
- Simplifying complex declarations
- Best practices

---

## 11. File Handling

### 11.1 File Operations

- Opening files (`fopen()`)
- Closing files (`fclose()`)
- File modes
- Error handling

### 11.2 File I/O Functions

- Character I/O (`fgetc()`, `fputc()`)
- String I/O (`fgets()`, `fputs()`)
- Formatted I/O (`fprintf()`, `fscanf()`)
- Binary I/O (`fread()`, `fwrite()`)

### 11.3 File Positioning

- `fseek()`, `ftell()`, `rewind()`
- `feof()`, `ferror()`

### 11.4 Command Line Arguments

- `argc` and `argv`
- Processing command line arguments

---

## 12. Preprocessor

### 12.1 Preprocessor Directives

- `#include`
- `#define`
- `#undef`
- `#ifdef`, `#ifndef`, `#endif`
- `#if`, `#elif`, `#else`

### 12.2 Macros

- Object-like macros
- Function-like macros
- Macro parameters
- Stringizing (`#`)
- Token pasting (`##`)

### 12.3 Conditional Compilation

- Platform-specific code
- Debug vs release builds
- Feature toggles

### 12.4 Predefined Macros

- `__FILE__`, `__LINE__`
- `__DATE__`, `__TIME__`
- `__STDC__`

---

## 13. Advanced Topics

### 13.1 Complex Data Structures

- Linked lists
- Stacks and queues
- Trees and graphs
- Hash tables

### 13.2 Advanced Pointer Techniques

- Function pointers and callbacks
- Pointer arrays and array pointers
- Multi-level pointers

### 13.3 Bit Manipulation

- Bit operations
- Bit masks
- Practical applications

### 13.4 Variable Arguments

- `stdarg.h` library
- `va_list`, `va_start`, `va_arg`, `va_end`

### 13.5 Signal Handling

- `signal.h`
- Signal types
- Signal handlers

### 13.6 Multi-file Programs

- Header files
- Separate compilation
- Linking object files
- Static vs dynamic libraries

---

## 14. Standard Library

### 14.1 Standard I/O (`stdio.h`)

- Input/output functions
- File operations
- Formatted I/O

### 14.2 String Handling (`string.h`)

- String manipulation functions
- Memory functions (`memcpy`, `memset`)

### 14.3 Math Library (`math.h`)

- Mathematical functions
- Trigonometric functions
- Logarithmic functions

### 14.4 Memory Management (`stdlib.h`)

- Dynamic memory allocation
- Random number generation
- Conversion functions

### 14.5 Character Classification (`ctype.h`)

- Character testing functions
- Character conversion functions

### 14.6 Time Functions (`time.h`)

- Time manipulation
- Date formatting

---

## 15. Debugging & Tools

### 15.1 Debugging Techniques

- `printf()` debugging
- Using debuggers (GDB)
- Static analysis tools

### 15.2 Common Errors

- Syntax errors
- Runtime errors
- Logic errors
- Memory errors

### 15.3 Development Tools

- Compilers (GCC, Clang)
- Make and build systems
- Version control (Git)
- Profiling tools

---

## 16. Best Practices

### 16.1 Code Style

- Naming conventions
- Indentation and formatting
- Comments and documentation

### 16.2 Error Handling

- Return codes
- Error checking
- Defensive programming

### 16.3 Performance Considerations

- Algorithm efficiency
- Memory usage
- Compiler optimizations

### 16.4 Portability

- Platform-independent code
- Standard compliance
- Avoiding undefined behavior

---

## 17. Recommended Learning Path

### Phase 1: Foundation (Weeks 1-2)

1. Development environment setup
2. Basic syntax and program structure
3. Data types and variables
4. Basic operators
5. Simple input/output

### Phase 2: Control & Functions (Weeks 3-4)

1. Control flow statements
2. Loops and iterations
3. Function basics
4. Parameter passing
5. Scope and storage classes

### Phase 3: Data Structures (Weeks 5-6)

1. Arrays and strings
2. Multi-dimensional arrays
3. String manipulation
4. Basic algorithms

### Phase 4: Pointers & Memory (Weeks 7-8)

1. Pointer fundamentals
2. Pointer arithmetic
3. Pointers with arrays and functions
4. Dynamic memory allocation

### Phase 5: Advanced Concepts (Weeks 9-10)

1. Structures and unions
2. File handling
3. Preprocessor directives
4. Multi-file programs

### Phase 6: Mastery (Weeks 11-12)

1. Advanced pointers
2. Data structures implementation
3. Debugging and optimization
4. Real-world projects

---

## 18. Project Ideas by Difficulty

### Beginner Level

- **Calculator**: Basic arithmetic operations
- **Temperature Converter**: Celsius/Fahrenheit conversion
- **Number Guessing Game**: Random number generation
- **Simple Banking System**: Basic account operations
- **Student Grade Manager**: Array-based grade storage

### Intermediate Level

- **Text File Analyzer**: Word count, character frequency
- **Contact Management System**: Using structures and files
- **Simple Inventory System**: CRUD operations
- **Matrix Operations**: Addition, multiplication, transpose
- **Basic Encryption/Decryption**: Caesar cipher implementation

### Advanced Level

- **Memory Allocator**: Custom malloc/free implementation
- **Data Structure Library**: Linked lists, stacks, queues
- **File Compression Tool**: Basic compression algorithms
- **Simple Database**: B-tree implementation
- **Network Programming**: Socket-based client-server

### Expert Level

- **Operating System Components**: Process scheduler simulation
- **Compiler Frontend**: Lexical analyzer and parser
- **Game Engine**: 2D graphics and physics
- **Embedded System Project**: Microcontroller programming
- **Performance Profiler**: Code analysis tool

---

## Notes for Learning

- Practice coding daily
- Start with simple programs and gradually increase complexity
- Focus on understanding concepts rather than memorizing syntax
- Debug your own code to learn from mistakes
- Read and analyze existing C code
- Join C programming communities and forums
- Work on projects that interest you

---

## 19. Alphabetical C Language Reference

### Keywords and Operators

- **\_Alignas**: Keyword (C11) - Alignment specifier.
- **\_Alignof**: Keyword (C11) - Query alignment.
- **\_Atomic**: Keyword (C11) - Atomic type qualifier.
- **\_Bool**: Data type (C99) - Boolean type.
- **\_Complex**: Data type (C99) - Complex numbers.
- **\_Generic**: Keyword (C11) - Generic selection.
- **\_Imaginary**: Data type (C99) - Imaginary numbers.
- **\_Noreturn**: Keyword (C11) - Function does not return.
- **\_Static_assert**: Keyword (C11) - Compile-time assertion.
- **\_Thread_local**: Keyword (C11) - Thread-local storage.
- **&&**: Operator - Logical AND.
- **&**: Operator - Bitwise AND; address-of.
- **&=**: Operator - Bitwise AND assignment.
- **!**: Operator - Logical NOT.
- **!=**: Operator - Not equal.
- **%**: Operator - Modulo.
- **%=**: Operator - Modulo assignment.
- **()**: Operator - Function call; grouping.
- **\***: Operator - Multiplication; dereference.
- \***\*=**: Operator - Multiplication assignment.
- **+**: Operator - Addition; unary plus.
- **++**: Operator - Increment (prefix/postfix).
- **+=**: Operator - Addition assignment.
- **,**: Operator - Comma (sequencing).
- **-**: Operator - Subtraction; unary minus.
- **--**: Operator - Decrement (prefix/postfix).
- **-=**: Operator - Subtraction assignment.
- **->**: Operator - Member access (pointer).
- **.**: Operator - Member access.
- **/**: Operator - Division.
- **/=**: Operator - Division assignment.
- **<**: Operator - Less than.
- **<<**: Operator - Left shift.
- **<<=**: Operator - Left shift assignment.
- **<=**: Operator - Less than or equal.
- **=**: Operator - Assignment.
- **==**: Operator - Equal.
- **>**: Operator - Greater than.
- **>=**: Operator - Greater than or equal.
- **>>**: Operator - Right shift.
- **>>=**: Operator - Right shift assignment.
- **? :**: Operator - Conditional (ternary).
- **[ ]**: Operator - Array subscript.
- **^**: Operator - Bitwise XOR.
- **^=**: Operator - Bitwise XOR assignment.
- **alignas**: Keyword (C11) - Alignment specifier.
- **alignof**: Keyword (C11) - Query alignment.
- **assert**: Keyword (C23) - Runtime assertion.
- **auto**: Keyword - Automatic storage.
- **bitand**: Keyword (alternative) - Bitwise AND.
- **bitor**: Keyword (alternative) - Bitwise OR.
- **bool**: Keyword (C23) - Boolean type.
- **break**: Keyword - Exit loop/switch.
- **case**: Keyword - Switch label.
- **char**: Data type - Character.
- **compl**: Keyword (alternative) - Bitwise NOT.
- **const**: Qualifier - Constant.
- **continue**: Keyword - Skip loop iteration.
- **default**: Keyword - Switch default.
- **do**: Keyword - Loop start.
- **double**: Data type - Double precision float.
- **else**: Keyword - Alternative branch.
- **enum**: Keyword - Enumeration.
- **extern**: Keyword - External linkage.
- **false**: Keyword (C23) - Boolean false.
- **float**: Data type - Single precision float.
- **for**: Keyword - Loop.
- **goto**: Keyword - Jump to label.
- **if**: Keyword - Conditional.
- **inline**: Keyword (C99) - Inline function.
- **int**: Data type - Integer.
- **long**: Data type modifier - Long int.
- **noreturn**: Keyword (C23) - Function does not return.
- **not**: Keyword (alternative) - Logical NOT.
- **not_eq**: Keyword (alternative) - Not equal.
- **or**: Keyword (alternative) - Logical OR.
- **register**: Keyword - Register storage.
- **restrict**: Qualifier (C99) - Restricted pointer.
- **return**: Keyword - Return from function.
- **short**: Data type modifier - Short int.
- **signed**: Data type modifier - Signed type.
- **sizeof**: Operator - Size of.
- **static**: Keyword - Static storage.
- **struct**: Keyword - Structure.
- **switch**: Keyword - Switch statement.
- **true**: Keyword (C23) - Boolean true.
- **typedef**: Keyword - Type definition.
- **union**: Keyword - Union.
- **unsigned**: Data type modifier - Unsigned type.
- **void**: Keyword/Data type - No value.
- **volatile**: Qualifier - Volatile.
- **while**: Keyword - Loop.
- **xor**: Keyword (alternative) - Bitwise XOR.
- **xor_eq**: Keyword (alternative) - Bitwise XOR assignment.
- **~**: Operator - Bitwise NOT.
- **|**: Operator - Bitwise OR.
- **|=**: Operator - Bitwise OR assignment.
- **||**: Operator - Logical OR.

### Standard Library Functions

#### <assert.h>

- **assert()**: Macro - Runtime assertion.

#### <ctype.h>

- **isalnum()**: Function - Alphanumeric check.
- **isalpha()**: Function - Alphabetic check.
- **iscntrl()**: Function - Control char check.
- **isdigit()**: Function - Digit check.
- **isgraph()**: Function - Graphical char check.
- **islower()**: Function - Lowercase check.
- **isprint()**: Function - Printable check.
- **ispunct()**: Function - Punctuation check.
- **isspace()**: Function - Whitespace check.
- **isupper()**: Function - Uppercase check.
- **isxdigit()**: Function - Hex digit check.
- **tolower()**: Function - To lowercase.
- **toupper()**: Function - To uppercase.

#### <errno.h>

- **errno**: Macro - Error number.

#### <float.h>

- **DBL_DIG**: Macro - Double digits.
- **DBL_MAX**: Macro - Max double.
- **DBL_MIN**: Macro - Min double.
- **FLT_DIG**: Macro - Float digits.
- **FLT_MAX**: Macro - Max float.
- **FLT_MIN**: Macro - Min float.
- **LDBL_DIG**: Macro - Long double digits.
- **LDBL_MAX**: Macro - Max long double.
- **LDBL_MIN**: Macro - Min long double.

#### <limits.h>

- **CHAR_BIT**: Macro - Bits in char.
- **CHAR_MAX**: Macro - Max char value.
- **CHAR_MIN**: Macro - Min char value.
- **INT_MAX**: Macro - Max int.
- **INT_MIN**: Macro - Min int.
- **LONG_MAX**: Macro - Max long.
- **LONG_MIN**: Macro - Min long.
- **MB_LEN_MAX**: Macro - Max multibyte length.
- **SHRT_MAX**: Macro - Max short.
- **SHRT_MIN**: Macro - Min short.
- **UCHAR_MAX**: Macro - Max unsigned char.
- **UINT_MAX**: Macro - Max unsigned int.
- **ULLONG_MAX**: Macro - Max unsigned long long.
- **ULONG_MAX**: Macro - Max unsigned long.
- **USHRT_MAX**: Macro - Max unsigned short.

#### <locale.h>

- **localeconv()**: Function - Locale info.
- **setlocale()**: Function - Set locale.

#### <math.h>

- **acos()**: Function - Arc cosine.
- **asin()**: Function - Arc sine.
- **atan()**: Function - Arc tangent.
- **atan2()**: Function - Arc tangent (two args).
- **ceil()**: Function - Ceiling.
- **cos()**: Function - Cosine.
- **cosh()**: Function - Hyperbolic cosine.
- **exp()**: Function - Exponential.
- **fabs()**: Function - Absolute float.
- **floor()**: Function - Floor.
- **fmod()**: Function - Modulo float.
- **frexp()**: Function - Split float.
- **ldexp()**: Function - Load exponent.
- **log()**: Function - Natural log.
- **log10()**: Function - Log base 10.
- **modf()**: Function - Split fractional.
- **pow()**: Function - Power.
- **sin()**: Function - Sine.
- **sinh()**: Function - Hyperbolic sine.
- **sqrt()**: Function - Square root.
- **tan()**: Function - Tangent.
- **tanh()**: Function - Hyperbolic tangent.

#### <setjmp.h>

- **longjmp()**: Function - Non-local jump.
- **setjmp()**: Function - Set jump.
- **setjmp**: Type - Jump buffer.

#### <signal.h>

- **raise()**: Function - Raise signal.
- **signal()**: Function - Set signal handler.
- **sig_atomic_t**: Type - Signal atomic.
- **SIG_DFL**: Macro - Default signal.
- **SIG_ERR**: Macro - Signal error.
- **SIG_IGN**: Macro - Ignore signal.
- **SIGABRT**: Macro - Abort signal.
- **SIGFPE**: Macro - Floating point error.
- **SIGILL**: Macro - Illegal instruction.
- **SIGINT**: Macro - Interrupt.
- **SIGSEGV**: Macro - Segmentation fault.
- **SIGTERM**: Macro - Termination.

#### <stdarg.h>

- **va_arg()**: Macro - Variable arg.
- **va_end()**: Macro - End variable args.
- **va_list**: Type - Variable arg list.
- **va_start()**: Macro - Start variable args.

#### <stddef.h>

- **NULL**: Macro - Null pointer.
- **offsetof()**: Macro - Structure offset.
- **ptrdiff_t**: Type - Pointer difference.
- **size_t**: Type - Size type.
- **wchar_t**: Type - Wide char.

#### <stdio.h>

- **BUFSIZ**: Macro - Buffer size.
- **clearerr()**: Function - Clear error.
- **fclose()**: Function - Close file.
- **feof()**: Function - End of file.
- **ferror()**: Function - File error.
- **fflush()**: Function - Flush stream.
- **fgetc()**: Function - Get char from file.
- **fgetpos()**: Function - Get file position.
- **fgets()**: Function - Get string from file.
- **FILE**: Type - File stream.
- **fopen()**: Function - Open file.
- **fprintf()**: Function - Formatted write to file.
- **fputc()**: Function - Put char to file.
- **fputs()**: Function - Put string to file.
- **fread()**: Function - Read from file.
- **freopen()**: Function - Reopen file.
- **fscanf()**: Function - Formatted read from file.
- **fseek()**: Function - Seek in file.
- **fsetpos()**: Function - Set file position.
- **ftell()**: Function - Tell file position.
- **fwrite()**: Function - Write to file.
- **getc()**: Function - Get char from stream.
- **getchar()**: Function - Get char from stdin.
- **gets()**: Function - Get string from stdin (deprecated).
- **perror()**: Function - Print error.
- **printf()**: Function - Formatted print.
- **putc()**: Function - Put char to stream.
- **putchar()**: Function - Put char to stdout.
- **puts()**: Function - Put string to stdout.
- **remove()**: Function - Remove file.
- **rename()**: Function - Rename file.
- **rewind()**: Function - Rewind file.
- **scanf()**: Function - Formatted scan.
- **SEEK_CUR**: Macro - Seek current.
- **SEEK_END**: Macro - Seek end.
- **SEEK_SET**: Macro - Seek set.
- **setbuf()**: Function - Set buffer.
- **setvbuf()**: Function - Set buffer mode.
- **sprintf()**: Function - Formatted string print.
- **sscanf()**: Function - Formatted string scan.
- **stderr**: Macro - Standard error.
- **stdin**: Macro - Standard input.
- **stdout**: Macro - Standard output.
- **tmpfile()**: Function - Temp file.
- **tmpnam()**: Function - Temp name.
- **ungetc()**: Function - Unget char.
- **vfprintf()**: Function - Variable formatted print file.
- **vprintf()**: Function - Variable formatted print.
- **vsprintf()**: Function - Variable formatted string print.

#### <stdlib.h>

- **abort()**: Function - Abnormal termination.
- **abs()**: Function - Absolute value (int).
- **atexit()**: Function - Register exit handler.
- **atof()**: Function - String to float.
- **atoi()**: Function - String to int.
- **atol()**: Function - String to long.
- **bsearch()**: Function - Binary search.
- **calloc()**: Function - Allocate and zero memory.
- **div()**: Function - Integer division.
- **div_t**: Type - Division result.
- **EXIT_FAILURE**: Macro - Exit failure.
- **EXIT_SUCCESS**: Macro - Exit success.
- **free()**: Function - Free memory.
- **getenv()**: Function - Get environment var.
- **labs()**: Function - Absolute long.
- **ldiv()**: Function - Long division.
- **ldiv_t**: Type - Long div result.
- **malloc()**: Function - Allocate memory.
- **mblen()**: Function - Multibyte length.
- **mbstowcs()**: Function - Multibyte to wide char.
- **mbtowc()**: Function - Multibyte to wide char.
- **qsort()**: Function - Quick sort.
- **rand()**: Function - Random number.
- **RAND_MAX**: Macro - Max random.
- **realloc()**: Function - Reallocate memory.
- **srand()**: Function - Seed random.
- **strtod()**: Function - String to double.
- **strtol()**: Function - String to long.
- **strtoll()**: Function - String to long long.
- **strtoul()**: Function - String to unsigned long.
- **system()**: Function - System command.
- **wcstombs()**: Function - Wide to multibyte.
- **wctomb()**: Function - Wide to multibyte char.

#### <string.h>

- **memchr()**: Function - Memory char search.
- **memcmp()**: Function - Memory compare.
- **memcpy()**: Function - Memory copy.
- **memmove()**: Function - Memory move.
- **memset()**: Function - Memory set.
- **strcat()**: Function - String concatenate.
- **strchr()**: Function - String char search.
- **strcmp()**: Function - String compare.
- **strcoll()**: Function - String collate.
- **strcpy()**: Function - String copy.
- **strcspn()**: Function - String span complement.
- **strerror()**: Function - String error.
- **strlen()**: Function - String length.
- **strncat()**: Function - String n concatenate.
- **strncmp()**: Function - String n compare.
- **strncpy()**: Function - String n copy.
- **strpbrk()**: Function - String pointer break.
- **strrchr()**: Function - String reverse char.
- **strspn()**: Function - String span.
- **strstr()**: Function - String search string.
- **strtok()**: Function - String token.

#### <time.h>

- **asctime()**: Function - Convert time to string.
- **clock()**: Function - Processor time.
- **CLOCKS_PER_SEC**: Macro - Clock ticks per second.
- **clock_t**: Type - Clock type.
- **ctime()**: Function - Convert time to string.
- **difftime()**: Function - Time difference.
- **gmtime()**: Function - GMT time.
- **localtime()**: Function - Local time.
- **mktime()**: Function - Make time.
- **strftime()**: Function - Format time string.
- **time()**: Function - Current time.
- **time_t**: Type - Time type.

### Preprocessor Directives

- **#define**: Define macro.
- **#elif**: Else if conditional.
- **#else**: Else conditional.
- **#endif**: End conditional.
- **#error**: Generate error.
- **#if**: If conditional.
- **#ifdef**: If defined.
- **#ifndef**: If not defined.
- **#include**: Include file.
- **#line**: Set line number.
- **#pragma**: Compiler directive.
- **#undef**: Undefine macro.

### Standard Headers

- **<assert.h>**: Assertions.
- **<ctype.h>**: Character handling.
- **<errno.h>**: Errors.
- **<float.h>**: Floating-point limits.
- **<inttypes.h>**: Integer types (C99).
- **<iso646.h>**: Alternative operators.
- **<limits.h>**: Integer limits.
- **<locale.h>**: Localization.
- **<math.h>**: Mathematics.
- **<setjmp.h>**: Non-local jumps.
- **<signal.h>**: Signals.
- **<stdalign.h>**: Alignment (C11).
- **<stdarg.h>**: Variable arguments.
- **<stdatomic.h>**: Atomics (C11).
- **<stdbool.h>**: Booleans (C99).
- **<stddef.h>**: Definitions.
- **<stdint.h>**: Integer types (C99).
- **<stdio.h>**: Input/output.
- **<stdlib.h>**: General utilities.
- **<stdnoreturn.h>**: Noreturn (C11).
- **<string.h>**: Strings.
- **<tgmath.h>**: Type-generic math (C99).
- **<threads.h>**: Threads (C11).
- **<time.h>**: Time.
- **<uchar.h>**: Unicode (C11).
- **<wchar.h>**: Wide characters.
- **<wctype.h>**: Wide character classification.

---

_This comprehensive index serves as both a learning roadmap and complete reference for your C language journey. The alphabetical reference section provides quick lookup for all C language elements, while the structured learning path ensures systematic progression from fundamentals to mastery._

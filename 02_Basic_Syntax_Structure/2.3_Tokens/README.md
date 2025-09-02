# 2.3 Tokens

## What are Tokens?

Tokens are the smallest individual units of a C program that are meaningful to the compiler. Every C program is a sequence of tokens.

## Token Types

### 1. Keywords
Reserved words with special meaning to the compiler.
```c
int, for, if, while, return, struct, etc.
```

### 2. Identifiers
Names for variables, functions, arrays, etc.
```c
main, printf, variable_name, calculateSum
```

### 3. Constants
Fixed values that don't change during execution.

#### Integer Constants
```c
42        // Decimal
052       // Octal (starts with 0)
0x2A      // Hexadecimal (starts with 0x)
42L       // Long integer
42U       // Unsigned integer
```

#### Floating-point Constants
```c
3.14      // Double
3.14f     // Float
1.5e10    // Scientific notation
```

#### Character Constants
```c
'A'       // Single character
'\n'      // Escape sequence
'\0'      // Null character
```

### 4. String Literals
Sequence of characters enclosed in double quotes.
```c
"Hello World"
"C Programming"
""            // Empty string
```

### 5. Operators
Symbols that perform operations on operands.
```c
+  -  *  /  %     // Arithmetic
<  >  ==  !=      // Relational
&&  ||  !         // Logical
&  |  ^  ~        // Bitwise
```

### 6. Special Symbols
Punctuation and delimiters.
```c
;  ,  .  ()  []  {}  ->
```

## Token Recognition

### Whitespace
Spaces, tabs, and newlines separate tokens but are otherwise ignored.
```c
int x=5;          // Same as
int x = 5;        // This (better formatting)
```

### Comments
Not tokens - removed during preprocessing.
```c
int x = 5;  // This comment is ignored
```

## Code Example

The [`tokens_demo.c`](tokens_demo.c) demonstrates all token types with practical examples.

**Run the code:**
```bash
gcc tokens_demo.c -o tokens_demo && ./tokens_demo
```

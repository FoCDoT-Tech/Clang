# 3.3 Variable Declaration & Initialization

## Declaration Syntax

### Basic Declaration
```c
type variable_name;
```

### Multiple Declarations
```c
int a, b, c;                    // Multiple variables of same type
int x = 10, y = 20, z;          // Mixed declaration and initialization
```

## Initialization vs Assignment

### Initialization (at declaration)
```c
int count = 0;                  // Initialize when declaring
char grade = 'A';               // Set initial value
```

### Assignment (after declaration)
```c
int number;                     // Declare first
number = 42;                    // Assign value later
```

## Variable Scope

### Local Variables
- Declared inside functions or blocks
- Only accessible within that scope
- Automatically destroyed when scope ends

### Global Variables
- Declared outside all functions
- Accessible from anywhere in the program
- Exist for entire program duration

### Block Scope
```c
{
    int local_var = 10;         // Only exists in this block
}
// local_var not accessible here
```

## Storage Classes

### auto (Default)
- Local variables stored on stack
- Automatically managed
```c
auto int local_num = 5;         // 'auto' usually omitted
```

### static
- Retains value between function calls
- Initialized only once
```c
static int counter = 0;         // Keeps value between calls
```

### extern
- Declares variable defined elsewhere
- Used for global variables across files
```c
extern int global_var;          // Defined in another file
```

### register
- Suggests storing in CPU register for speed
- Rarely used in modern C
```c
register int fast_var = 100;    // Hint to compiler
```

## Initialization Rules

### Automatic Variables
- Local variables have undefined initial values
- Must be explicitly initialized

### Static/Global Variables
- Automatically initialized to zero
- Can be explicitly initialized

## Code Example

The [`variables_demo.c`](variables_demo.c) demonstrates variable declaration, initialization, scope, and storage classes.

**Run the code:**
```bash
gcc variables_demo.c -o variables_demo && ./variables_demo
```

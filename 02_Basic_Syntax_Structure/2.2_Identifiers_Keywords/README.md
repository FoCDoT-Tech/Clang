# 2.2 Identifiers & Keywords

## Identifiers

### Definition
Names given to variables, functions, arrays, and other user-defined items.

### Naming Rules
1. **Start with**: Letter (a-z, A-Z) or underscore (_)
2. **Followed by**: Letters, digits (0-9), or underscores
3. **Case sensitive**: `variable` ≠ `Variable`
4. **No keywords**: Cannot use reserved words
5. **No spaces**: Use underscores or camelCase

### Valid Examples
```c
int age;           // Simple name
int student_count; // Underscore separation
int maxValue;      // camelCase
int _private;      // Starting with underscore
int num2;          // Contains digit
```

### Invalid Examples
```c
int 2num;          // Starts with digit
int student-count; // Contains hyphen
int for;           // Reserved keyword
int my var;        // Contains space
```

## Naming Conventions

### Variables and Functions
- **snake_case**: `student_count`, `calculate_average()`
- **camelCase**: `studentCount`, `calculateAverage()`
- Choose one style and be consistent

### Constants
- **UPPER_CASE**: `MAX_SIZE`, `PI_VALUE`

### Private/Internal
- **Leading underscore**: `_internal_function()`

## Reserved Keywords

### C Keywords (32 total)
```c
auto     break    case     char     const    continue
default  do       double   else     enum     extern
float    for      goto     if       inline   int
long     register return   short    signed   sizeof
static   struct   switch   typedef  union    unsigned
void     volatile while    restrict
```

### C99 Keywords
```c
_Bool    _Complex _Imaginary
```

### C11 Keywords
```c
_Alignas    _Alignof    _Atomic     _Generic
_Noreturn   _Static_assert _Thread_local
```

## Case Sensitivity

C is **case-sensitive**:
- `Variable` and `variable` are different
- `Printf` will cause error (should be `printf`)
- `MAIN` is not the same as `main`

## Code Example

The [`identifiers_demo.c`](identifiers_demo.c) demonstrates valid/invalid identifiers and naming conventions.

**Run the code:**
```bash
gcc identifiers_demo.c -o identifiers_demo && ./identifiers_demo
```

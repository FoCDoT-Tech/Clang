# Chapter 3: Data Types & Variables

This chapter covers the fundamental data types and variable concepts in C programming. Each section includes concise explanations and working code examples.

## Sections

### [3.1 Basic Data Types](3.1_Basic_Data_Types/)
- Five fundamental types: char, int, float, double, void
- Memory sizes and ranges
- Platform differences and usage guidelines
- **Code**: [`basic_types_demo.c`](3.1_Basic_Data_Types/basic_types_demo.c) - All basic types with sizes and ranges
- **Run**: `gcc basic_types_demo.c -o basic_types_demo && ./basic_types_demo`

### [3.2 Type Modifiers](3.2_Type_Modifiers/)
- Sign modifiers: signed/unsigned
- Size modifiers: short/long/long long
- Modifier combinations and platform variations
- **Code**: [`type_modifiers_demo.c`](3.2_Type_Modifiers/type_modifiers_demo.c) - All modifier combinations with examples
- **Run**: `gcc type_modifiers_demo.c -o type_modifiers_demo && ./type_modifiers_demo`

### [3.3 Variable Declaration & Initialization](3.3_Variable_Declaration_Initialization/)
- Declaration syntax and initialization
- Variable scope (local, global, block)
- Storage classes (auto, static, extern, register)
- **Code**: [`variables_demo.c`](3.3_Variable_Declaration_Initialization/variables_demo.c) - Scope and storage class examples
- **Run**: `gcc variables_demo.c -o variables_demo && ./variables_demo`

### [3.4 Constants](3.4_Constants/)
- Literal constants (integer, float, character, string)
- const keyword usage
- #define preprocessor constants
- enum enumerations
- **Code**: [`constants_demo.c`](3.4_Constants/constants_demo.c) - All constant types and usage
- **Run**: `gcc constants_demo.c -o constants_demo && ./constants_demo`

### [3.5 Type Conversion](3.5_Type_Conversion/)
- Implicit vs explicit conversion
- Type promotion rules
- Casting and potential pitfalls
- **Code**: [`type_conversion_demo.c`](3.5_Type_Conversion/type_conversion_demo.c) - Conversion examples and issues
- **Run**: `gcc type_conversion_demo.c -o type_conversion_demo && ./type_conversion_demo`

## Quick Start

```bash
# Navigate to any section
cd 3.1_Basic_Data_Types

# Compile and run
gcc *.c -o demo && ./demo

# Or use Makefile
make run
```

## Learning Path

1. **Start with 3.1** - Understand the five basic data types
2. **Learn 3.2** - Master type modifiers for different ranges
3. **Study 3.3** - Learn proper variable declaration and scope
4. **Explore 3.4** - Use constants effectively in your code
5. **Master 3.5** - Understand type conversions and avoid pitfalls

This chapter builds on Basic Syntax & Structure and prepares you for operators and expressions in the next chapter.

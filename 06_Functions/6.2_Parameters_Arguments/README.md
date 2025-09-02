# 6.2 Parameters & Arguments

Parameters and arguments are how functions receive input data. Understanding the difference between formal parameters and actual arguments, plus how data is passed, is crucial for effective function usage.

## Key Concepts

### 1. **Formal Parameters vs Actual Arguments**
- **Formal Parameters**: Variables in function definition that receive values
- **Actual Arguments**: Values passed to function during call
- Parameters are placeholders, arguments are actual data

### 2. **Pass by Value**
- C passes copies of argument values to functions
- Changes to parameters inside function don't affect original variables
- Default mechanism for all basic data types

### 3. **Pass by Reference (using Pointers)**
- Pass memory addresses instead of values
- Function can modify original variables through pointers
- Required for arrays and when you need to modify caller's data

### 4. **Array Parameters**
- Arrays are automatically passed by reference (address of first element)
- Array size information is lost - must pass size separately
- Function receives pointer to array's first element

## Parameter Types

### **Basic Types**
- `int`, `float`, `double`, `char` - passed by value
- Modifications don't affect original variables

### **Pointer Parameters**
- `int*`, `char*`, `double*` - passed by value (address copied)
- Can modify data at the address

### **Array Parameters**
- `int arr[]` or `int* arr` - receives array address
- Always passed by reference

### **Const Parameters**
- `const int*` - prevents function from modifying data
- Good practice for read-only parameters

## Best Practices

- Use `const` for parameters that shouldn't be modified
- Pass large structures by pointer to avoid copying
- Always validate pointer parameters before use
- Pass array size as separate parameter
- Use descriptive parameter names

## Code Examples

Run the demo to see parameter passing in action:
```bash
make run
```

The demo covers:
- Pass by value vs pass by reference
- Array parameter passing
- Pointer parameters and modifications
- Const parameters for safety
- Practical examples with different parameter types

# 6.1 Function Basics

Functions are fundamental building blocks that encapsulate code into reusable units. They take inputs, process them, and optionally return results.

## Function Components

### 1. **Function Definition**
Complete implementation of a function including:
- Return type
- Function name
- Parameter list
- Function body

### 2. **Function Declaration (Prototype)**
Tells compiler about function's signature before definition:
- Return type
- Function name  
- Parameter types (names optional)
- Ends with semicolon

### 3. **Function Call**
Executes the function by:
- Using function name
- Passing required arguments
- Receiving return value (if any)

### 4. **Return Statement**
- Exits function and optionally returns a value
- Must match declared return type
- `void` functions can use `return;` or omit return

## Function Syntax

```c
// Function declaration (prototype)
return_type function_name(parameter_list);

// Function definition
return_type function_name(parameter_list) {
    // Function body
    return value; // if not void
}

// Function call
result = function_name(arguments);
```

## Key Concepts

- **Modularity**: Break complex problems into smaller functions
- **Reusability**: Write once, use multiple times
- **Scope**: Variables inside functions are local by default
- **Stack**: Function calls use stack for local variables and parameters

## Best Practices

- Use descriptive function names (verbs for actions)
- Keep functions focused on single tasks
- Declare prototypes in header files
- Return meaningful values or use `void`
- Add comments for complex functions

## Code Examples

Run the demo to see function basics in action:
```bash
make run
```

The demo covers:
- Function definitions and declarations
- Different return types and parameter combinations
- Function calls and return value usage
- Local vs global scope
- Practical function examples (calculator, utilities)

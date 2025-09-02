# Chapter 2: Basic Syntax & Structure

This chapter covers the fundamental syntax and structural elements of C programming. Each section includes concise explanations and working code examples.

## Sections

### [2.1 Program Structure](2.1_Program_Structure/)
- Include directives and headers
- Main function structure
- Function declarations vs definitions
- Comment types and best practices
- **Code**: [`program_structure_demo.c`](2.1_Program_Structure/program_structure_demo.c) - Complete program breakdown
- **Run**: `gcc program_structure_demo.c -o program_structure_demo && ./program_structure_demo`

### [2.2 Identifiers & Keywords](2.2_Identifiers_Keywords/)
- Naming rules and conventions
- Reserved keywords
- Case sensitivity examples
- Valid vs invalid identifiers
- **Code**: [`identifiers_demo.c`](2.2_Identifiers_Keywords/identifiers_demo.c) - Naming examples and rules
- **Run**: `gcc identifiers_demo.c -o identifiers_demo && ./identifiers_demo`

### [2.3 Tokens](2.3_Tokens/)
- Token types: keywords, identifiers, constants
- String literals and operators
- Special symbols and punctuators
- **Code**: [`tokens_demo.c`](2.3_Tokens/tokens_demo.c) - All token types with examples
- **Run**: `gcc tokens_demo.c -o tokens_demo && ./tokens_demo`

## Quick Start

```bash
# Navigate to any section
cd 2.1_Program_Structure

# Compile and run
gcc *.c -o demo && ./demo

# Or use Makefile
make run
```

## Learning Path

1. **Start with 2.1** - Understand how C programs are structured
2. **Learn 2.2** - Master naming rules and avoid keyword conflicts
3. **Study 2.3** - Recognize all token types for better code understanding

This chapter builds on the Fundamentals and prepares you for data types and variables in the next chapter.

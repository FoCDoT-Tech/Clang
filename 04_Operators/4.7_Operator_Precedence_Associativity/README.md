# 4.7 Operator Precedence & Associativity

Understanding operator precedence and associativity is crucial for writing correct expressions and avoiding bugs.

## Operator Precedence Table

| Precedence | Operators | Associativity | Description |
|------------|-----------|---------------|-------------|
| 1 (Highest) | `()` `[]` `->` `.` | Left to Right | Postfix |
| 2 | `!` `~` `++` `--` `+` `-` `*` `&` `sizeof` | Right to Left | Unary |
| 3 | `*` `/` `%` | Left to Right | Multiplicative |
| 4 | `+` `-` | Left to Right | Additive |
| 5 | `<<` `>>` | Left to Right | Shift |
| 6 | `<` `<=` `>` `>=` | Left to Right | Relational |
| 7 | `==` `!=` | Left to Right | Equality |
| 8 | `&` | Left to Right | Bitwise AND |
| 9 | `^` | Left to Right | Bitwise XOR |
| 10 | `\|` | Left to Right | Bitwise OR |
| 11 | `&&` | Left to Right | Logical AND |
| 12 | `\|\|` | Left to Right | Logical OR |
| 13 | `? :` | Right to Left | Conditional |
| 14 | `=` `+=` `-=` `*=` `/=` `%=` `&=` `\|=` `^=` `<<=` `>>=` | Right to Left | Assignment |
| 15 (Lowest) | `,` | Left to Right | Comma |

## Key Concepts

### Precedence Rules
- Higher precedence operators are evaluated first
- Use parentheses to override default precedence
- When in doubt, use parentheses for clarity

### Associativity Rules
- **Left to Right**: `a + b + c` = `(a + b) + c`
- **Right to Left**: `a = b = c` = `a = (b = c)`

### Common Pitfalls
```c
// Misleading without parentheses
int result = 2 + 3 * 4;        // 14, not 20
int mask = 1 << 2 + 1;         // 8, not 6
int check = x & 1 == 0;        // Wrong! Use (x & 1) == 0
```

## Best Practices

1. **Use parentheses** for complex expressions
2. **Break complex expressions** into multiple statements
3. **Learn common patterns** (like `(x & 1) == 0` for even numbers)
4. **Be explicit** rather than relying on precedence knowledge

## Code Example

The [`precedence_demo.c`](precedence_demo.c) program demonstrates operator precedence and associativity with practical examples.

**Run the code:**
```bash
make run
```

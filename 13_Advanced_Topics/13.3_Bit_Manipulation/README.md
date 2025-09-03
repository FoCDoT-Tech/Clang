# 13.3 Bit Manipulation

Low-level bit operations for efficient algorithms, embedded programming, and system optimization.

## Basic Bit Operations

### **Bitwise Operators**
```c
int a = 0b1010;  // 10 in decimal
int b = 0b1100;  // 12 in decimal

// AND: both bits must be 1
int and_result = a & b;     // 0b1000 = 8

// OR: at least one bit must be 1
int or_result = a | b;      // 0b1110 = 14

// XOR: bits must be different
int xor_result = a ^ b;     // 0b0110 = 6

// NOT: flip all bits
int not_result = ~a;        // 0b...11110101

// Left shift: multiply by 2^n
int left_shift = a << 2;    // 0b101000 = 40

// Right shift: divide by 2^n
int right_shift = a >> 1;   // 0b0101 = 5
```

### **Bit Manipulation Macros**
```c
#define SET_BIT(x, pos)     ((x) |= (1U << (pos)))
#define CLEAR_BIT(x, pos)   ((x) &= ~(1U << (pos)))
#define TOGGLE_BIT(x, pos)  ((x) ^= (1U << (pos)))
#define CHECK_BIT(x, pos)   (((x) >> (pos)) & 1U)

// Usage
unsigned int flags = 0;
SET_BIT(flags, 3);      // Set bit 3
CLEAR_BIT(flags, 1);    // Clear bit 1
TOGGLE_BIT(flags, 5);   // Toggle bit 5
bool is_set = CHECK_BIT(flags, 3);  // Check if bit 3 is set
```

## Common Bit Tricks

### **Power of Two Operations**
```c
// Check if number is power of 2
bool is_power_of_two(unsigned int n) {
    return n && !(n & (n - 1));
}

// Next power of 2
unsigned int next_power_of_2(unsigned int n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}

// Count trailing zeros (position of first set bit)
int count_trailing_zeros(unsigned int n) {
    if (n == 0) return 32;
    int count = 0;
    while (!(n & 1)) {
        n >>= 1;
        count++;
    }
    return count;
}
```

### **Bit Counting**
```c
// Count set bits (population count)
int popcount(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Brian Kernighan's algorithm (faster)
int popcount_fast(unsigned int n) {
    int count = 0;
    while (n) {
        n &= n - 1;  // Clear lowest set bit
        count++;
    }
    return count;
}

// Using lookup table (fastest for repeated calls)
static const int popcount_table[256] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
    // ... (complete table would have 256 entries)
};

int popcount_table_lookup(unsigned int n) {
    return popcount_table[n & 0xFF] +
           popcount_table[(n >> 8) & 0xFF] +
           popcount_table[(n >> 16) & 0xFF] +
           popcount_table[(n >> 24) & 0xFF];
}
```

### **Bit Reversal**
```c
// Reverse bits in 32-bit integer
unsigned int reverse_bits(unsigned int n) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

// Faster bit reversal using lookup table
unsigned int reverse_bits_fast(unsigned int n) {
    static const unsigned char reverse_table[256] = {
        0x00, 0x80, 0x40, 0xC0, 0x20, 0xA0, 0x60, 0xE0,
        // ... (complete reverse lookup table)
    };
    
    return (reverse_table[n & 0xFF] << 24) |
           (reverse_table[(n >> 8) & 0xFF] << 16) |
           (reverse_table[(n >> 16) & 0xFF] << 8) |
           (reverse_table[(n >> 24) & 0xFF]);
}
```

## Bit Fields and Flags

### **Flag Management**
```c
// Permission flags
#define READ_PERMISSION     0x01  // 0b00000001
#define WRITE_PERMISSION    0x02  // 0b00000010
#define EXECUTE_PERMISSION  0x04  // 0b00000100
#define DELETE_PERMISSION   0x08  // 0b00001000

typedef struct {
    unsigned int permissions;
} FilePermissions;

// Set multiple permissions
void set_permissions(FilePermissions* fp, unsigned int perms) {
    fp->permissions |= perms;
}

// Check if has permission
bool has_permission(FilePermissions* fp, unsigned int perm) {
    return (fp->permissions & perm) != 0;
}

// Remove permission
void remove_permission(FilePermissions* fp, unsigned int perm) {
    fp->permissions &= ~perm;
}
```

### **Bit Fields in Structures**
```c
// Packed structure using bit fields
typedef struct {
    unsigned int red   : 5;   // 5 bits for red (0-31)
    unsigned int green : 6;   // 6 bits for green (0-63)
    unsigned int blue  : 5;   // 5 bits for blue (0-31)
} RGB565;

// Status register simulation
typedef struct {
    unsigned int ready     : 1;
    unsigned int error     : 1;
    unsigned int overflow  : 1;
    unsigned int underflow : 1;
    unsigned int reserved  : 4;
} StatusRegister;

void print_status(StatusRegister* status) {
    printf("Ready: %d, Error: %d, Overflow: %d, Underflow: %d\n",
           status->ready, status->error, status->overflow, status->underflow);
}
```

## Advanced Bit Algorithms

### **Bit Manipulation Puzzles**
```c
// Swap two numbers without temporary variable
void swap_xor(int* a, int* b) {
    if (a != b) {  // Avoid self-assignment
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

// Find single number in array where all others appear twice
int find_single(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    return result;
}

// Check if two integers have opposite signs
bool opposite_signs(int a, int b) {
    return (a ^ b) < 0;
}

// Absolute value without branching
int abs_no_branch(int n) {
    int mask = n >> 31;  // All 1s if negative, all 0s if positive
    return (n + mask) ^ mask;
}
```

### **Bit Masks and Extraction**
```c
// Extract bits from position
unsigned int extract_bits(unsigned int num, int pos, int len) {
    unsigned int mask = (1U << len) - 1;  // Create mask
    return (num >> pos) & mask;
}

// Set bits at position
unsigned int set_bits(unsigned int num, int pos, int len, unsigned int value) {
    unsigned int mask = (1U << len) - 1;
    num &= ~(mask << pos);        // Clear target bits
    num |= (value & mask) << pos; // Set new value
    return num;
}

// Rotate bits left
unsigned int rotate_left(unsigned int num, int shift) {
    shift %= 32;  // Handle shifts > 32
    return (num << shift) | (num >> (32 - shift));
}

// Rotate bits right
unsigned int rotate_right(unsigned int num, int shift) {
    shift %= 32;
    return (num >> shift) | (num << (32 - shift));
}
```

## Bit Manipulation in Algorithms

### **Fast Exponentiation**
```c
// Calculate a^b using bit manipulation
long long fast_power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return result;
}
```

### **Gray Code Generation**
```c
// Generate Gray code sequence
void generate_gray_code(int n) {
    int total = 1 << n;  // 2^n
    
    for (int i = 0; i < total; i++) {
        int gray = i ^ (i >> 1);
        
        // Print binary representation
        for (int j = n - 1; j >= 0; j--) {
            printf("%d", (gray >> j) & 1);
        }
        printf("\n");
    }
}
```

### **Subset Generation**
```c
// Generate all subsets using bit manipulation
void generate_subsets(int arr[], int n) {
    int total_subsets = 1 << n;  // 2^n
    
    for (int i = 0; i < total_subsets; i++) {
        printf("{ ");
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                printf("%d ", arr[j]);
            }
        }
        printf("}\n");
    }
}
```

## Embedded Systems Applications

### **Register Manipulation**
```c
// Simulate hardware register operations
typedef volatile unsigned int* Register;

// Set specific bits in register
void reg_set_bits(Register reg, unsigned int mask) {
    *reg |= mask;
}

// Clear specific bits in register
void reg_clear_bits(Register reg, unsigned int mask) {
    *reg &= ~mask;
}

// Read-modify-write operation
void reg_modify_bits(Register reg, unsigned int mask, unsigned int value) {
    *reg = (*reg & ~mask) | (value & mask);
}

// Wait for bit to be set (polling)
void wait_for_bit(Register reg, int bit_pos) {
    while (!(*reg & (1U << bit_pos))) {
        // Busy wait
    }
}
```

### **Checksum and Parity**
```c
// Calculate simple checksum
unsigned char calculate_checksum(unsigned char data[], int length) {
    unsigned char checksum = 0;
    for (int i = 0; i < length; i++) {
        checksum ^= data[i];
    }
    return checksum;
}

// Calculate parity bit
int calculate_parity(unsigned int data) {
    int parity = 0;
    while (data) {
        parity ^= (data & 1);
        data >>= 1;
    }
    return parity;
}

// Hamming weight (number of 1s)
int hamming_weight(unsigned int n) {
    int weight = 0;
    while (n) {
        weight += n & 1;
        n >>= 1;
    }
    return weight;
}
```

## Performance Optimizations

### **Bit Manipulation for Division/Multiplication**
```c
// Fast division by power of 2
int divide_by_power_of_2(int n, int power) {
    return n >> power;  // Equivalent to n / (2^power)
}

// Fast multiplication by power of 2
int multiply_by_power_of_2(int n, int power) {
    return n << power;  // Equivalent to n * (2^power)
}

// Check if divisible by power of 2
bool is_divisible_by_power_of_2(int n, int power) {
    int divisor = 1 << power;
    return (n & (divisor - 1)) == 0;
}
```

### **Bit Hacks for Common Operations**
```c
// Min/Max without branching
int min_no_branch(int a, int b) {
    return b ^ ((a ^ b) & -(a < b));
}

int max_no_branch(int a, int b) {
    return a ^ ((a ^ b) & -(a < b));
}

// Sign of integer
int sign(int n) {
    return (n > 0) - (n < 0);
}

// Round up to next multiple of power of 2
unsigned int round_up_power_of_2(unsigned int n, unsigned int alignment) {
    return (n + alignment - 1) & ~(alignment - 1);
}
```

## Debugging and Visualization

### **Bit Printing Functions**
```c
// Print binary representation
void print_binary(unsigned int n, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0 && i > 0) printf(" ");  // Group by 4
    }
    printf("\n");
}

// Print hex with binary
void print_hex_binary(unsigned int n) {
    printf("0x%08X = ", n);
    print_binary(n, 32);
}

// Analyze bit patterns
void analyze_bits(unsigned int n) {
    printf("Value: %u (0x%X)\n", n, n);
    printf("Binary: ");
    print_binary(n, 32);
    printf("Set bits: %d\n", popcount(n));
    printf("Trailing zeros: %d\n", count_trailing_zeros(n));
    printf("Is power of 2: %s\n", is_power_of_two(n) ? "Yes" : "No");
}
```

## Code Example

Run the demo to see bit manipulation techniques:
```bash
make run
```

The demo demonstrates:
- Basic bitwise operations and bit tricks
- Bit counting and manipulation algorithms
- Flag management and bit fields
- Advanced bit algorithms and puzzles
- Performance optimization techniques
- Embedded systems register operations
- Debugging and visualization tools

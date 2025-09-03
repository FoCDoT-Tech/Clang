#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
void demonstrate_basic_operations(void);
void demonstrate_bit_tricks(void);
void demonstrate_bit_counting(void);
void demonstrate_flags_and_fields(void);
void demonstrate_advanced_algorithms(void);
void demonstrate_embedded_operations(void);
void demonstrate_performance_hacks(void);
void demonstrate_debugging_tools(void);

// Bit manipulation macros
#define SET_BIT(x, pos)     ((x) |= (1U << (pos)))
#define CLEAR_BIT(x, pos)   ((x) &= ~(1U << (pos)))
#define TOGGLE_BIT(x, pos)  ((x) ^= (1U << (pos)))
#define CHECK_BIT(x, pos)   (((x) >> (pos)) & 1U)

// Permission flags
#define READ_PERMISSION     0x01
#define WRITE_PERMISSION    0x02
#define EXECUTE_PERMISSION  0x04
#define DELETE_PERMISSION   0x08

// Structures
typedef struct {
    unsigned int permissions;
} FilePermissions;

typedef struct {
    unsigned int red   : 5;
    unsigned int green : 6;
    unsigned int blue  : 5;
} RGB565;

typedef struct {
    unsigned int ready     : 1;
    unsigned int error     : 1;
    unsigned int overflow  : 1;
    unsigned int underflow : 1;
    unsigned int reserved  : 4;
} StatusRegister;

// Basic bit operations
bool is_power_of_two(unsigned int n) {
    return n && !(n & (n - 1));
}

unsigned int next_power_of_2(unsigned int n) {
    if (n == 0) return 1;
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}

int count_trailing_zeros(unsigned int n) {
    if (n == 0) return 32;
    int count = 0;
    while (!(n & 1)) {
        n >>= 1;
        count++;
    }
    return count;
}

// Bit counting functions
int popcount(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int popcount_fast(unsigned int n) {
    int count = 0;
    while (n) {
        n &= n - 1;
        count++;
    }
    return count;
}

// Bit reversal
unsigned int reverse_bits(unsigned int n) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

// Flag management
void set_permissions(FilePermissions* fp, unsigned int perms) {
    fp->permissions |= perms;
}

bool has_permission(FilePermissions* fp, unsigned int perm) {
    return (fp->permissions & perm) != 0;
}

void remove_permission(FilePermissions* fp, unsigned int perm) {
    fp->permissions &= ~perm;
}

// Advanced algorithms
void swap_xor(int* a, int* b) {
    if (a != b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

int find_single(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    return result;
}

bool opposite_signs(int a, int b) {
    return (a ^ b) < 0;
}

int abs_no_branch(int n) {
    int mask = n >> 31;
    return (n + mask) ^ mask;
}

// Bit extraction and manipulation
unsigned int extract_bits(unsigned int num, int pos, int len) {
    unsigned int mask = (1U << len) - 1;
    return (num >> pos) & mask;
}

unsigned int set_bits(unsigned int num, int pos, int len, unsigned int value) {
    unsigned int mask = (1U << len) - 1;
    num &= ~(mask << pos);
    num |= (value & mask) << pos;
    return num;
}

unsigned int rotate_left(unsigned int num, int shift) {
    shift %= 32;
    return (num << shift) | (num >> (32 - shift));
}

unsigned int rotate_right(unsigned int num, int shift) {
    shift %= 32;
    return (num >> shift) | (num << (32 - shift));
}

// Fast exponentiation
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

// Gray code generation
void generate_gray_code(int n, int max_display) {
    int total = 1 << n;
    int display_count = (total > max_display) ? max_display : total;
    
    printf("First %d Gray codes for n=%d:\n", display_count, n);
    for (int i = 0; i < display_count; i++) {
        int gray = i ^ (i >> 1);
        
        for (int j = n - 1; j >= 0; j--) {
            printf("%d", (gray >> j) & 1);
        }
        printf(" ");
        if ((i + 1) % 8 == 0) printf("\n");
    }
    if (display_count % 8 != 0) printf("\n");
}

// Subset generation
void generate_subsets(int arr[], int n, int max_display) {
    int total_subsets = 1 << n;
    int display_count = (total_subsets > max_display) ? max_display : total_subsets;
    
    printf("First %d subsets:\n", display_count);
    for (int i = 0; i < display_count; i++) {
        printf("{ ");
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                printf("%d ", arr[j]);
            }
        }
        printf("}\n");
    }
}

// Checksum and parity
unsigned char calculate_checksum(unsigned char data[], int length) {
    unsigned char checksum = 0;
    for (int i = 0; i < length; i++) {
        checksum ^= data[i];
    }
    return checksum;
}

int calculate_parity(unsigned int data) {
    int parity = 0;
    while (data) {
        parity ^= (data & 1);
        data >>= 1;
    }
    return parity;
}

// Performance optimizations
int divide_by_power_of_2(int n, int power) {
    return n >> power;
}

int multiply_by_power_of_2(int n, int power) {
    return n << power;
}

bool is_divisible_by_power_of_2(int n, int power) {
    int divisor = 1 << power;
    return (n & (divisor - 1)) == 0;
}

int min_no_branch(int a, int b) {
    return b ^ ((a ^ b) & -(a < b));
}

int max_no_branch(int a, int b) {
    return a ^ ((a ^ b) & -(a < b));
}

unsigned int round_up_power_of_2(unsigned int n, unsigned int alignment) {
    return (n + alignment - 1) & ~(alignment - 1);
}

// Debugging functions
void print_binary(unsigned int n, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0 && i > 0) printf(" ");
    }
}

void print_hex_binary(unsigned int n) {
    printf("0x%08X = ", n);
    print_binary(n, 32);
    printf("\n");
}

void analyze_bits(unsigned int n) {
    printf("Value: %u (0x%X)\n", n, n);
    printf("Binary: ");
    print_binary(n, 32);
    printf("\n");
    printf("Set bits: %d\n", popcount(n));
    printf("Trailing zeros: %d\n", count_trailing_zeros(n));
    printf("Is power of 2: %s\n", is_power_of_two(n) ? "Yes" : "No");
}

int main(void) {
    printf("=== Bit Manipulation Demo ===\n\n");
    
    demonstrate_basic_operations();
    demonstrate_bit_tricks();
    demonstrate_bit_counting();
    demonstrate_flags_and_fields();
    demonstrate_advanced_algorithms();
    demonstrate_embedded_operations();
    demonstrate_performance_hacks();
    demonstrate_debugging_tools();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_operations(void) {
    printf("1. BASIC BIT OPERATIONS\n");
    printf("----------------------------------------\n");
    
    unsigned int a = 0b1010;  // 10
    unsigned int b = 0b1100;  // 12
    
    printf("a = %u (binary: ", a);
    print_binary(a, 8);
    printf(")\n");
    printf("b = %u (binary: ", b);
    print_binary(b, 8);
    printf(")\n\n");
    
    printf("Bitwise operations:\n");
    printf("a & b = %u (binary: ", a & b);
    print_binary(a & b, 8);
    printf(")\n");
    
    printf("a | b = %u (binary: ", a | b);
    print_binary(a | b, 8);
    printf(")\n");
    
    printf("a ^ b = %u (binary: ", a ^ b);
    print_binary(a ^ b, 8);
    printf(")\n");
    
    printf("~a = %u (binary: ", (unsigned int)(~a & 0xFF));
    print_binary(~a & 0xFF, 8);
    printf(")\n");
    
    printf("a << 2 = %u (binary: ", a << 2);
    print_binary(a << 2, 8);
    printf(")\n");
    
    printf("a >> 1 = %u (binary: ", a >> 1);
    print_binary(a >> 1, 8);
    printf(")\n");
    
    // Bit manipulation macros
    printf("\nBit manipulation macros:\n");
    unsigned int flags = 0;
    printf("Initial flags: %u\n", flags);
    
    SET_BIT(flags, 3);
    printf("After SET_BIT(flags, 3): %u\n", flags);
    
    SET_BIT(flags, 7);
    printf("After SET_BIT(flags, 7): %u\n", flags);
    
    printf("CHECK_BIT(flags, 3): %s\n", CHECK_BIT(flags, 3) ? "Set" : "Clear");
    printf("CHECK_BIT(flags, 5): %s\n", CHECK_BIT(flags, 5) ? "Set" : "Clear");
    
    TOGGLE_BIT(flags, 3);
    printf("After TOGGLE_BIT(flags, 3): %u\n", flags);
    
    CLEAR_BIT(flags, 7);
    printf("After CLEAR_BIT(flags, 7): %u\n", flags);
    
    printf("\n");
}

void demonstrate_bit_tricks(void) {
    printf("2. BIT TRICKS AND POWER OF TWO\n");
    printf("----------------------------------------\n");
    
    unsigned int numbers[] = {1, 2, 3, 4, 8, 15, 16, 32, 63, 64};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Power of 2 checks:\n");
    for (int i = 0; i < count; i++) {
        printf("%2u: %s\n", numbers[i], 
               is_power_of_two(numbers[i]) ? "Power of 2" : "Not power of 2");
    }
    
    printf("\nNext power of 2:\n");
    for (int i = 0; i < count; i++) {
        printf("%2u -> %u\n", numbers[i], next_power_of_2(numbers[i]));
    }
    
    printf("\nTrailing zeros:\n");
    for (int i = 0; i < count; i++) {
        printf("%2u: %d trailing zeros\n", numbers[i], count_trailing_zeros(numbers[i]));
    }
    
    printf("\n");
}

void demonstrate_bit_counting(void) {
    printf("3. BIT COUNTING\n");
    printf("----------------------------------------\n");
    
    unsigned int test_values[] = {0, 1, 7, 15, 31, 63, 127, 255, 0xAAAA, 0x5555};
    int count = sizeof(test_values) / sizeof(test_values[0]);
    
    printf("Population count (number of set bits):\n");
    for (int i = 0; i < count; i++) {
        printf("0x%04X: %d bits (slow: %d, fast: %d)\n", 
               test_values[i], 
               popcount(test_values[i]),
               popcount(test_values[i]),
               popcount_fast(test_values[i]));
    }
    
    printf("\nBit reversal:\n");
    unsigned int test_reverse[] = {0x12345678, 0xAAAA, 0x5555, 0xFF00};
    int reverse_count = sizeof(test_reverse) / sizeof(test_reverse[0]);
    
    for (int i = 0; i < reverse_count; i++) {
        unsigned int original = test_reverse[i];
        unsigned int reversed = reverse_bits(original);
        printf("0x%08X -> 0x%08X\n", original, reversed);
    }
    
    printf("\n");
}

void demonstrate_flags_and_fields(void) {
    printf("4. FLAGS AND BIT FIELDS\n");
    printf("----------------------------------------\n");
    
    // File permissions
    printf("File permissions system:\n");
    FilePermissions file = {0};
    
    set_permissions(&file, READ_PERMISSION | WRITE_PERMISSION);
    printf("Set READ and WRITE permissions\n");
    printf("Has READ: %s\n", has_permission(&file, READ_PERMISSION) ? "Yes" : "No");
    printf("Has WRITE: %s\n", has_permission(&file, WRITE_PERMISSION) ? "Yes" : "No");
    printf("Has EXECUTE: %s\n", has_permission(&file, EXECUTE_PERMISSION) ? "Yes" : "No");
    
    set_permissions(&file, EXECUTE_PERMISSION);
    printf("Added EXECUTE permission\n");
    printf("Has EXECUTE: %s\n", has_permission(&file, EXECUTE_PERMISSION) ? "Yes" : "No");
    
    remove_permission(&file, WRITE_PERMISSION);
    printf("Removed WRITE permission\n");
    printf("Has WRITE: %s\n", has_permission(&file, WRITE_PERMISSION) ? "Yes" : "No");
    
    // RGB565 color
    printf("\nRGB565 color format:\n");
    RGB565 color = {31, 63, 31};  // White
    printf("Red: %u, Green: %u, Blue: %u\n", color.red, color.green, color.blue);
    printf("Size of RGB565: %zu bytes\n", sizeof(RGB565));
    
    // Status register
    printf("\nStatus register:\n");
    StatusRegister status = {1, 0, 0, 1, 0};
    printf("Ready: %u, Error: %u, Overflow: %u, Underflow: %u\n",
           status.ready, status.error, status.overflow, status.underflow);
    printf("Size of StatusRegister: %zu bytes\n", sizeof(StatusRegister));
    
    printf("\n");
}

void demonstrate_advanced_algorithms(void) {
    printf("5. ADVANCED BIT ALGORITHMS\n");
    printf("----------------------------------------\n");
    
    // XOR swap
    printf("XOR swap:\n");
    int x = 42, y = 17;
    printf("Before swap: x=%d, y=%d\n", x, y);
    swap_xor(&x, &y);
    printf("After swap: x=%d, y=%d\n", x, y);
    
    // Find single number
    printf("\nFind single number in array:\n");
    int arr[] = {1, 2, 3, 2, 1, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSingle number: %d\n", find_single(arr, size));
    
    // Opposite signs
    printf("\nOpposite signs check:\n");
    int pairs[][2] = {{5, -3}, {-7, 2}, {4, 8}, {-1, -5}};
    int pair_count = sizeof(pairs) / sizeof(pairs[0]);
    
    for (int i = 0; i < pair_count; i++) {
        printf("%d and %d have opposite signs: %s\n",
               pairs[i][0], pairs[i][1],
               opposite_signs(pairs[i][0], pairs[i][1]) ? "Yes" : "No");
    }
    
    // Absolute value without branching
    printf("\nAbsolute value without branching:\n");
    int test_abs[] = {-15, 0, 42, -128, 255};
    int abs_count = sizeof(test_abs) / sizeof(test_abs[0]);
    
    for (int i = 0; i < abs_count; i++) {
        printf("abs(%d) = %d\n", test_abs[i], abs_no_branch(test_abs[i]));
    }
    
    // Bit extraction and manipulation
    printf("\nBit extraction and manipulation:\n");
    unsigned int num = 0b11010110;  // 214
    printf("Original number: %u (binary: ", num);
    print_binary(num, 8);
    printf(")\n");
    
    unsigned int extracted = extract_bits(num, 2, 4);
    printf("Extract 4 bits from position 2: %u (binary: ", extracted);
    print_binary(extracted, 4);
    printf(")\n");
    
    unsigned int modified = set_bits(num, 2, 4, 0b1001);
    printf("Set 4 bits at position 2 to 1001: %u (binary: ", modified);
    print_binary(modified, 8);
    printf(")\n");
    
    // Rotation
    printf("\nBit rotation:\n");
    unsigned int rotate_num = 0b11010000;
    printf("Original: ");
    print_binary(rotate_num, 8);
    printf("\n");
    
    printf("Rotate left 3: ");
    print_binary(rotate_left(rotate_num, 3) & 0xFF, 8);
    printf("\n");
    
    printf("Rotate right 2: ");
    print_binary(rotate_right(rotate_num, 2) & 0xFF, 8);
    printf("\n");
    
    // Fast exponentiation
    printf("\nFast exponentiation:\n");
    printf("2^10 = %lld\n", fast_power(2, 10));
    printf("3^5 = %lld\n", fast_power(3, 5));
    printf("5^0 = %lld\n", fast_power(5, 0));
    
    // Gray code
    printf("\nGray code generation:\n");
    generate_gray_code(4, 16);
    
    // Subset generation
    printf("\nSubset generation:\n");
    int subset_arr[] = {1, 2, 3};
    generate_subsets(subset_arr, 3, 8);
    
    printf("\n");
}

void demonstrate_embedded_operations(void) {
    printf("6. EMBEDDED SYSTEMS OPERATIONS\n");
    printf("----------------------------------------\n");
    
    // Checksum calculation
    printf("Checksum calculation:\n");
    unsigned char data[] = {0x12, 0x34, 0x56, 0x78, 0x9A};
    int data_len = sizeof(data);
    
    printf("Data: ");
    for (int i = 0; i < data_len; i++) {
        printf("0x%02X ", data[i]);
    }
    printf("\n");
    
    unsigned char checksum = calculate_checksum(data, data_len);
    printf("XOR Checksum: 0x%02X\n", checksum);
    
    // Parity calculation
    printf("\nParity calculation:\n");
    unsigned int parity_values[] = {0b1010, 0b1111, 0b0001, 0b1100};
    int parity_count = sizeof(parity_values) / sizeof(parity_values[0]);
    
    for (int i = 0; i < parity_count; i++) {
        printf("0b");
        print_binary(parity_values[i], 4);
        printf(" -> parity: %d\n", calculate_parity(parity_values[i]));
    }
    
    printf("\n");
}

void demonstrate_performance_hacks(void) {
    printf("7. PERFORMANCE HACKS\n");
    printf("----------------------------------------\n");
    
    // Fast division/multiplication
    printf("Fast division and multiplication by powers of 2:\n");
    int test_num = 100;
    printf("Original number: %d\n", test_num);
    printf("Divide by 4 (>>2): %d\n", divide_by_power_of_2(test_num, 2));
    printf("Multiply by 8 (<<3): %d\n", multiply_by_power_of_2(test_num, 3));
    
    printf("Divisibility check:\n");
    printf("%d divisible by 4: %s\n", test_num, 
           is_divisible_by_power_of_2(test_num, 2) ? "Yes" : "No");
    printf("%d divisible by 8: %s\n", test_num, 
           is_divisible_by_power_of_2(test_num, 3) ? "Yes" : "No");
    
    // Min/Max without branching
    printf("\nMin/Max without branching:\n");
    int a = 15, b = 23;
    printf("a=%d, b=%d\n", a, b);
    printf("min(a,b) = %d\n", min_no_branch(a, b));
    printf("max(a,b) = %d\n", max_no_branch(a, b));
    
    // Alignment
    printf("\nRounding up to power of 2 alignment:\n");
    unsigned int sizes[] = {13, 17, 32, 45};
    int size_count = sizeof(sizes) / sizeof(sizes[0]);
    
    for (int i = 0; i < size_count; i++) {
        printf("%u aligned to 16: %u\n", 
               sizes[i], round_up_power_of_2(sizes[i], 16));
    }
    
    printf("\n");
}

void demonstrate_debugging_tools(void) {
    printf("8. DEBUGGING AND VISUALIZATION\n");
    printf("----------------------------------------\n");
    
    // Bit analysis
    printf("Bit analysis:\n");
    unsigned int analyze_values[] = {42, 128, 255, 1024};
    int analyze_count = sizeof(analyze_values) / sizeof(analyze_values[0]);
    
    for (int i = 0; i < analyze_count; i++) {
        printf("\nAnalyzing %u:\n", analyze_values[i]);
        analyze_bits(analyze_values[i]);
    }
    
    // Hex and binary display
    printf("\nHex and binary display:\n");
    unsigned int display_values[] = {0xDEADBEEF, 0x12345678, 0xAAAA5555};
    int display_count = sizeof(display_values) / sizeof(display_values[0]);
    
    for (int i = 0; i < display_count; i++) {
        print_hex_binary(display_values[i]);
    }
    
    printf("\n");
}

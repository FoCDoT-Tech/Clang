#include <stdio.h>

// Function prototypes
void demonstrate_bitwise_and(void);
void demonstrate_bitwise_or(void);
void demonstrate_bitwise_xor(void);
void demonstrate_bitwise_not(void);
void demonstrate_shift_operators(void);
void demonstrate_bit_manipulation(void);
void demonstrate_practical_applications(void);
void print_binary(unsigned int num, int bits);

int main() {
    printf("=== Bitwise Operators Demo ===\n\n");
    
    demonstrate_bitwise_and();
    demonstrate_bitwise_or();
    demonstrate_bitwise_xor();
    demonstrate_bitwise_not();
    demonstrate_shift_operators();
    demonstrate_bit_manipulation();
    demonstrate_practical_applications();
    
    printf("✓ All bitwise operators demonstrated!\n");
    return 0;
}

void print_binary(unsigned int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0 && i > 0) printf(" ");  // Space every 4 bits
    }
}

void demonstrate_bitwise_and(void) {
    printf("1. BITWISE AND (&) OPERATOR:\n");
    
    unsigned char a = 5;  // 00000101
    unsigned char b = 3;  // 00000011
    unsigned char result = a & b;  // 00000001
    
    printf("a = %d (", a); print_binary(a, 8); printf(")\n");
    printf("b = %d (", b); print_binary(b, 8); printf(")\n");
    printf("a & b = %d (", result); print_binary(result, 8); printf(")\n");
    
    printf("Rule: 1 & 1 = 1, all others = 0\n");
    printf("Use: Masking bits, checking flags\n\n");
}

void demonstrate_bitwise_or(void) {
    printf("2. BITWISE OR (|) OPERATOR:\n");
    
    unsigned char a = 5;  // 00000101
    unsigned char b = 3;  // 00000011
    unsigned char result = a | b;  // 00000111
    
    printf("a = %d (", a); print_binary(a, 8); printf(")\n");
    printf("b = %d (", b); print_binary(b, 8); printf(")\n");
    printf("a | b = %d (", result); print_binary(result, 8); printf(")\n");
    
    printf("Rule: 0 | 0 = 0, all others = 1\n");
    printf("Use: Setting bits, combining flags\n\n");
}

void demonstrate_bitwise_xor(void) {
    printf("3. BITWISE XOR (^) OPERATOR:\n");
    
    unsigned char a = 5;  // 00000101
    unsigned char b = 3;  // 00000011
    unsigned char result = a ^ b;  // 00000110
    
    printf("a = %d (", a); print_binary(a, 8); printf(")\n");
    printf("b = %d (", b); print_binary(b, 8); printf(")\n");
    printf("a ^ b = %d (", result); print_binary(result, 8); printf(")\n");
    
    printf("Rule: Different bits = 1, same bits = 0\n");
    printf("Use: Toggling bits, simple encryption\n");
    
    // XOR properties
    printf("XOR properties:\n");
    printf("a ^ a = %d (anything XOR itself = 0)\n", a ^ a);
    printf("a ^ 0 = %d (anything XOR 0 = itself)\n", a ^ 0);
    printf("(a ^ b) ^ b = %d (XOR is reversible)\n", (a ^ b) ^ b);
    printf("\n");
}

void demonstrate_bitwise_not(void) {
    printf("4. BITWISE NOT (~) OPERATOR:\n");
    
    unsigned char a = 5;  // 00000101
    unsigned char result = ~a;  // 11111010
    
    printf("a = %d (", a); print_binary(a, 8); printf(")\n");
    printf("~a = %d (", result); print_binary(result, 8); printf(")\n");
    
    printf("Rule: Flips all bits (0→1, 1→0)\n");
    printf("Use: Creating masks, bit inversion\n\n");
}

void demonstrate_shift_operators(void) {
    printf("5. SHIFT OPERATORS (<< and >>):\n");
    
    unsigned char a = 5;  // 00000101
    
    printf("Original: a = %d (", a); print_binary(a, 8); printf(")\n");
    
    // Left shift
    unsigned char left1 = a << 1;  // 00001010
    unsigned char left2 = a << 2;  // 00010100
    printf("a << 1 = %d (", left1); print_binary(left1, 8); printf(") = %d * 2\n", a);
    printf("a << 2 = %d (", left2); print_binary(left2, 8); printf(") = %d * 4\n", a);
    
    // Right shift
    unsigned char b = 20;  // 00010100
    printf("\nOriginal: b = %d (", b); print_binary(b, 8); printf(")\n");
    unsigned char right1 = b >> 1;  // 00001010
    unsigned char right2 = b >> 2;  // 00000101
    printf("b >> 1 = %d (", right1); print_binary(right1, 8); printf(") = %d / 2\n", b);
    printf("b >> 2 = %d (", right2); print_binary(right2, 8); printf(") = %d / 4\n", b);
    
    printf("Left shift: multiply by 2^n\n");
    printf("Right shift: divide by 2^n (unsigned)\n\n");
}

void demonstrate_bit_manipulation(void) {
    printf("6. BIT MANIPULATION TECHNIQUES:\n");
    
    unsigned char flags = 0;  // Start with all flags clear
    printf("Initial flags: %d (", flags); print_binary(flags, 8); printf(")\n");
    
    // Setting bits
    flags |= (1 << 2);  // Set bit 2
    printf("Set bit 2:     %d (", flags); print_binary(flags, 8); printf(")\n");
    
    flags |= (1 << 5);  // Set bit 5
    printf("Set bit 5:     %d (", flags); print_binary(flags, 8); printf(")\n");
    
    // Checking bits
    if (flags & (1 << 2)) {
        printf("Bit 2 is SET\n");
    }
    if (!(flags & (1 << 1))) {
        printf("Bit 1 is CLEAR\n");
    }
    
    // Toggling bits
    flags ^= (1 << 2);  // Toggle bit 2
    printf("Toggle bit 2:  %d (", flags); print_binary(flags, 8); printf(")\n");
    
    // Clearing bits
    flags &= ~(1 << 5);  // Clear bit 5
    printf("Clear bit 5:   %d (", flags); print_binary(flags, 8); printf(")\n");
    
    printf("\n");
}

void demonstrate_practical_applications(void) {
    printf("7. PRACTICAL APPLICATIONS:\n");
    
    // Permission system (like Unix file permissions)
    printf("File Permission System:\n");
    #define READ_PERM    4  // 100
    #define WRITE_PERM   2  // 010
    #define EXECUTE_PERM 1  // 001
    
    unsigned char permissions = 0;
    
    // Grant permissions
    permissions |= READ_PERM;
    permissions |= WRITE_PERM;
    printf("Granted read + write: %d (", permissions); print_binary(permissions, 3); printf(")\n");
    
    // Check permissions
    if (permissions & READ_PERM) {
        printf("✓ Can read\n");
    }
    if (permissions & WRITE_PERM) {
        printf("✓ Can write\n");
    }
    if (!(permissions & EXECUTE_PERM)) {
        printf("✗ Cannot execute\n");
    }
    
    // Color manipulation (RGB)
    printf("\nRGB Color Manipulation:\n");
    unsigned int color = 0x00FF80C0;  // ARGB: Alpha=0, Red=255, Green=128, Blue=192
    
    unsigned char alpha = (color >> 24) & 0xFF;
    unsigned char red   = (color >> 16) & 0xFF;
    unsigned char green = (color >> 8) & 0xFF;
    unsigned char blue  = color & 0xFF;
    
    printf("Color: 0x%08X\n", color);
    printf("Alpha: %d, Red: %d, Green: %d, Blue: %d\n", alpha, red, green, blue);
    
    // Modify green component
    color = (color & 0xFFFF00FF) | (64 << 8);  // Set green to 64
    printf("Modified green to 64: 0x%08X\n", color);
    
    // Fast multiplication/division
    printf("\nFast Arithmetic:\n");
    int num = 15;
    printf("Original: %d\n", num);
    printf("Multiply by 8 (<<3): %d\n", num << 3);
    printf("Divide by 4 (>>2): %d\n", num >> 2);
    
    // Check if power of 2
    printf("\nPower of 2 check:\n");
    int values[] = {8, 15, 16, 32, 33};
    for (int i = 0; i < 5; i++) {
        int val = values[i];
        if (val > 0 && (val & (val - 1)) == 0) {
            printf("%d is a power of 2\n", val);
        } else {
            printf("%d is NOT a power of 2\n", val);
        }
    }
    printf("\n");
}

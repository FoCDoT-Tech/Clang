#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Basic bit field examples
struct Flags {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 1;
    unsigned int value : 5;
};

// Function prototypes
void demonstrate_basic_bit_fields(void);
void demonstrate_memory_packing(void);
void demonstrate_practical_applications(void);
void demonstrate_bit_manipulation(void);
void demonstrate_limitations(void);
void demonstrate_portability_issues(void);
void set_flags(struct Flags *f, int flag1, int flag2, int flag3, int value);
void print_flags(struct Flags *f);

struct PackedData {
    unsigned int a : 3;
    unsigned int b : 5;
    unsigned int c : 8;
    unsigned int d : 16;
};

// Comparison structure without bit fields
struct UnpackedData {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
};

// Practical applications
struct StatusRegister {
    unsigned int ready     : 1;
    unsigned int error     : 1;
    unsigned int busy      : 1;
    unsigned int interrupt : 1;
    unsigned int reserved  : 4;
};

struct IPHeader {
    unsigned int version    : 4;
    unsigned int ihl        : 4;
    unsigned int tos        : 8;
    unsigned int length     : 16;
    unsigned int id         : 16;
    unsigned int flags      : 3;
    unsigned int frag_offset: 13;
};

struct DateTime {
    unsigned int second : 6;  // 0-59
    unsigned int minute : 6;  // 0-59
    unsigned int hour   : 5;  // 0-23
    unsigned int day    : 5;  // 1-31
    unsigned int month  : 4;  // 1-12
    unsigned int year   : 6;  // years since 2000
};

struct Config {
    unsigned int debug      : 1;
    unsigned int verbose    : 1;
    unsigned int log_level  : 3;  // 0-7
    unsigned int max_users  : 8;  // 0-255
    unsigned int timeout    : 16; // 0-65535
    unsigned int unused     : 3;
};

// Alignment demonstration
struct AlignmentDemo {
    unsigned int field1 : 3;
    unsigned int        : 0;  // Force alignment
    unsigned int field2 : 4;
    unsigned int field3 : 2;
};

struct PaddingDemo {
    unsigned int a : 3;
    unsigned int   : 5;  // Unnamed padding
    unsigned int b : 4;
    unsigned int c : 4;
};

int main(void) {
    printf("=== Bit Fields Demo ===\n\n");
    
    demonstrate_basic_bit_fields();
    demonstrate_memory_packing();
    demonstrate_practical_applications();
    demonstrate_bit_manipulation();
    demonstrate_limitations();
    demonstrate_portability_issues();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_bit_fields(void) {
    printf("1. BASIC BIT FIELD USAGE\n");
    printf("----------------------------------------\n");
    
    struct Flags flags = {0};
    
    printf("Bit field declaration and usage:\n");
    printf("  struct Flags {\n");
    printf("    unsigned int flag1 : 1;\n");
    printf("    unsigned int flag2 : 1;\n");
    printf("    unsigned int flag3 : 1;\n");
    printf("    unsigned int value : 5;\n");
    printf("  };\n");
    
    printf("\nInitial values (zero-initialized):\n");
    printf("  flags.flag1 = %u\n", flags.flag1);
    printf("  flags.flag2 = %u\n", flags.flag2);
    printf("  flags.flag3 = %u\n", flags.flag3);
    printf("  flags.value = %u\n", flags.value);
    
    // Set individual flags
    flags.flag1 = 1;
    flags.flag2 = 0;
    flags.flag3 = 1;
    flags.value = 15;  // 5 bits can hold 0-31
    
    printf("\nAfter setting values:\n");
    printf("  flags.flag1 = %u\n", flags.flag1);
    printf("  flags.flag2 = %u\n", flags.flag2);
    printf("  flags.flag3 = %u\n", flags.flag3);
    printf("  flags.value = %u\n", flags.value);
    
    // Test overflow behavior
    flags.value = 32;  // Exceeds 5-bit capacity (31 max)
    printf("\nAfter setting value = 32 (overflow):\n");
    printf("  flags.value = %u (truncated to fit 5 bits)\n", flags.value);
    
    // Demonstrate bit field operations
    printf("\nBit field operations:\n");
    flags.flag1 = !flags.flag1;  // Toggle
    printf("  After toggling flag1: %u\n", flags.flag1);
    
    flags.value++;
    printf("  After incrementing value: %u\n", flags.value);
    
    // Show structure size
    printf("\nMemory usage:\n");
    printf("  sizeof(struct Flags) = %zu bytes\n", sizeof(struct Flags));
    printf("  Total bits used: 1+1+1+5 = 8 bits\n");
    printf("  Fits in a single 32-bit integer\n");
    printf("\n");
}

void demonstrate_memory_packing(void) {
    printf("2. MEMORY PACKING\n");
    printf("----------------------------------------\n");
    
    struct PackedData packed = {0};
    struct UnpackedData unpacked = {0};
    
    printf("Memory efficiency comparison:\n");
    printf("  Packed structure (with bit fields):\n");
    printf("    a : 3 bits (0-7)\n");
    printf("    b : 5 bits (0-31)\n");
    printf("    c : 8 bits (0-255)\n");
    printf("    d : 16 bits (0-65535)\n");
    printf("    Total: 32 bits = %zu bytes\n", sizeof(struct PackedData));
    
    printf("  Unpacked structure (regular ints):\n");
    printf("    a, b, c, d: 4 integers × 4 bytes = %zu bytes\n", sizeof(struct UnpackedData));
    
    printf("  Memory saved: %zu bytes (%.1f%% reduction)\n", 
           sizeof(struct UnpackedData) - sizeof(struct PackedData),
           (1.0 - (double)sizeof(struct PackedData) / sizeof(struct UnpackedData)) * 100);
    
    // Demonstrate packing
    packed.a = 7;    // 3 bits: 111
    packed.b = 31;   // 5 bits: 11111
    packed.c = 255;  // 8 bits: 11111111
    packed.d = 65535; // 16 bits: 1111111111111111
    
    printf("\nPacked values:\n");
    printf("  a = %u (max for 3 bits)\n", packed.a);
    printf("  b = %u (max for 5 bits)\n", packed.b);
    printf("  c = %u (max for 8 bits)\n", packed.c);
    printf("  d = %u (max for 16 bits)\n", packed.d);
    
    // Show raw memory content
    printf("\nRaw memory content:\n");
    unsigned char *bytes = (unsigned char*)&packed;
    printf("  Bytes: ");
    for (size_t i = 0; i < sizeof(packed); i++) {
        printf("0x%02X ", bytes[i]);
    }
    printf("\n");
    
    // Alignment demonstration
    struct AlignmentDemo align = {0};
    struct PaddingDemo padding = {0};
    
    printf("\nAlignment and padding:\n");
    printf("  AlignmentDemo size: %zu bytes\n", sizeof(struct AlignmentDemo));
    printf("  PaddingDemo size: %zu bytes\n", sizeof(struct PaddingDemo));
    printf("  Zero-width fields force alignment to next storage unit\n");
    printf("  Unnamed fields provide padding between bit fields\n");
    printf("\n");
}

void demonstrate_practical_applications(void) {
    printf("3. PRACTICAL APPLICATIONS\n");
    printf("----------------------------------------\n");
    
    // Application 1: Hardware status register
    printf("Application 1: Hardware Status Register\n");
    struct StatusRegister status = {0};
    
    status.ready = 1;
    status.error = 0;
    status.busy = 0;
    status.interrupt = 1;
    
    printf("  Status register (8 bits total):\n");
    printf("    Ready: %s\n", status.ready ? "Yes" : "No");
    printf("    Error: %s\n", status.error ? "Yes" : "No");
    printf("    Busy: %s\n", status.busy ? "Yes" : "No");
    printf("    Interrupt: %s\n", status.interrupt ? "Yes" : "No");
    printf("    Reserved: %u\n", status.reserved);
    printf("    Size: %zu bytes\n", sizeof(status));
    
    // Application 2: Network protocol header
    printf("\nApplication 2: IP Header Fields\n");
    struct IPHeader ip = {0};
    
    ip.version = 4;        // IPv4
    ip.ihl = 5;           // Header length
    ip.tos = 0;           // Type of service
    ip.length = 1500;     // Total length
    ip.id = 12345;        // Identification
    ip.flags = 2;         // Don't fragment
    ip.frag_offset = 0;   // Fragment offset
    
    printf("  IP Header:\n");
    printf("    Version: %u\n", ip.version);
    printf("    IHL: %u\n", ip.ihl);
    printf("    ToS: %u\n", ip.tos);
    printf("    Length: %u\n", ip.length);
    printf("    ID: %u\n", ip.id);
    printf("    Flags: %u\n", ip.flags);
    printf("    Fragment Offset: %u\n", ip.frag_offset);
    printf("    Header size: %zu bytes\n", sizeof(ip));
    
    // Application 3: Compressed date/time
    printf("\nApplication 3: Compressed Date/Time\n");
    struct DateTime dt = {0};
    
    dt.second = 45;
    dt.minute = 30;
    dt.hour = 14;     // 2:30:45 PM
    dt.day = 15;
    dt.month = 8;     // August
    dt.year = 24;     // 2024
    
    printf("  DateTime (compressed to %zu bytes):\n", sizeof(dt));
    printf("    Date: %02u/%02u/20%02u\n", dt.month, dt.day, dt.year);
    printf("    Time: %02u:%02u:%02u\n", dt.hour, dt.minute, dt.second);
    printf("    vs normal struct tm: ~44 bytes\n");
    
    // Application 4: Configuration flags
    printf("\nApplication 4: Configuration Settings\n");
    struct Config config = {0};
    
    config.debug = 1;
    config.verbose = 0;
    config.log_level = 3;    // INFO level
    config.max_users = 100;
    config.timeout = 30000;  // 30 seconds
    
    printf("  Configuration (%zu bytes):\n", sizeof(config));
    printf("    Debug: %s\n", config.debug ? "ON" : "OFF");
    printf("    Verbose: %s\n", config.verbose ? "ON" : "OFF");
    printf("    Log Level: %u\n", config.log_level);
    printf("    Max Users: %u\n", config.max_users);
    printf("    Timeout: %u ms\n", config.timeout);
    printf("    Unused bits: %u\n", config.unused);
    printf("\n");
}

void demonstrate_bit_manipulation(void) {
    printf("4. BIT MANIPULATION WITH BIT FIELDS\n");
    printf("----------------------------------------\n");
    
    struct Flags flags = {0};
    
    printf("Bit manipulation operations:\n");
    
    // Set multiple flags at once using helper functions (defined at end of file)
    
    printf("  Initial state:\n");
    print_flags(&flags);
    
    printf("  Setting flags (1,0,1) and value 10:\n");
    set_flags(&flags, 1, 0, 1, 10);
    print_flags(&flags);
    
    printf("  Toggling all flags:\n");
    flags.flag1 = !flags.flag1;
    flags.flag2 = !flags.flag2;
    flags.flag3 = !flags.flag3;
    print_flags(&flags);
    
    printf("  Incrementing value:\n");
    for (int i = 0; i < 5; i++) {
        flags.value++;
        printf("    Step %d: value = %u\n", i + 1, flags.value);
    }
    
    // Demonstrate masking and bit operations
    printf("\nBit masking with bit fields:\n");
    struct Config config = {0};
    
    // Set multiple fields atomically
    config.debug = 1;
    config.verbose = 1;
    config.log_level = 7;  // Maximum level
    
    printf("  Config state: debug=%u, verbose=%u, log_level=%u\n",
           config.debug, config.verbose, config.log_level);
    
    // Clear all debug-related flags
    config.debug = 0;
    config.verbose = 0;
    config.log_level = 0;
    
    printf("  After clearing debug flags: debug=%u, verbose=%u, log_level=%u\n",
           config.debug, config.verbose, config.log_level);
    
    // Conditional operations
    if (config.debug) {
        printf("  Debug mode is ON\n");
    } else {
        printf("  Debug mode is OFF\n");
    }
    printf("\n");
}

void demonstrate_limitations(void) {
    printf("5. BIT FIELD LIMITATIONS\n");
    printf("----------------------------------------\n");
    
    struct Flags flags = {1, 0, 1, 15};
    
    printf("Common limitations and restrictions:\n");
    
    // Cannot take address of bit field
    printf("1. Cannot take address of bit fields:\n");
    printf("   int *ptr = &flags.flag1;  // COMPILATION ERROR\n");
    printf("   Bit fields may not have unique addresses\n");
    
    // Cannot use sizeof on bit field
    printf("\n2. Cannot use sizeof on individual bit fields:\n");
    printf("   sizeof(flags.flag1);      // COMPILATION ERROR\n");
    printf("   Can only get size of entire structure: %zu bytes\n", sizeof(flags));
    
    // Cannot create arrays of bit fields
    printf("\n3. Cannot create arrays of bit fields:\n");
    printf("   unsigned int flags[5] : 1;  // INVALID SYNTAX\n");
    printf("   Must use array of structures instead\n");
    
    // Limited operations
    printf("\n4. Limited operations available:\n");
    printf("   ✓ Assignment: flags.flag1 = 1\n");
    printf("   ✓ Comparison: if (flags.flag1 == 1)\n");
    printf("   ✓ Arithmetic: flags.value++\n");
    printf("   ✗ Address-of: &flags.flag1\n");
    printf("   ✗ Pointer arithmetic: ptr++\n");
    printf("   ✗ sizeof on individual fields\n");
    
    // Demonstrate valid operations
    printf("\n5. Valid operations demonstration:\n");
    printf("   Original: flag1=%u, value=%u\n", flags.flag1, flags.value);
    
    // Assignment
    flags.flag1 = 0;
    printf("   After assignment: flag1=%u\n", flags.flag1);
    
    // Comparison
    if (flags.flag2 == 0) {
        printf("   Comparison works: flag2 is zero\n");
    }
    
    // Arithmetic
    flags.value += 5;
    printf("   After arithmetic: value=%u\n", flags.value);
    
    // Overflow handling
    flags.value = 40;  // Exceeds 5-bit capacity
    printf("   After overflow (40 -> 5 bits): value=%u\n", flags.value);
    printf("\n");
}

void demonstrate_portability_issues(void) {
    printf("6. PORTABILITY CONSIDERATIONS\n");
    printf("----------------------------------------\n");
    
    printf("Portability issues with bit fields:\n");
    
    printf("\n1. Implementation-defined behavior:\n");
    printf("   • Bit field allocation order (left-to-right vs right-to-left)\n");
    printf("   • Alignment within storage units\n");
    printf("   • Padding between bit fields\n");
    printf("   • Sign extension for signed bit fields\n");
    
    printf("\n2. Compiler-specific differences:\n");
    printf("   • GCC vs MSVC may pack differently\n");
    printf("   • Different architectures (x86 vs ARM) may vary\n");
    printf("   • Endianness affects bit order interpretation\n");
    
    printf("\n3. Current system information:\n");
    struct PackedData test = {7, 31, 255, 65535};
    unsigned char *bytes = (unsigned char*)&test;
    
    printf("   Test structure with max values:\n");
    printf("   Raw bytes: ");
    for (size_t i = 0; i < sizeof(test); i++) {
        printf("0x%02X ", bytes[i]);
    }
    printf("\n");
    
    printf("   Field values: a=%u, b=%u, c=%u, d=%u\n", 
           test.a, test.b, test.c, test.d);
    
    printf("\n4. Best practices for portability:\n");
    printf("   ✓ Use bit fields for space optimization only\n");
    printf("   ✓ Don't rely on specific bit layouts\n");
    printf("   ✓ Use unsigned types when possible\n");
    printf("   ✓ Document assumptions about bit order\n");
    printf("   ✓ Test on target platforms\n");
    printf("   ✗ Avoid for network protocols without careful testing\n");
    printf("   ✗ Don't assume specific memory layout\n");
    
    printf("\n5. Alternative approaches:\n");
    printf("   • Use explicit bit manipulation with masks\n");
    printf("   • Use unions with bit fields and integers\n");
    printf("   • Use bitwise operations for portable bit packing\n");
    
    // Example of portable bit manipulation
    printf("\n6. Portable bit manipulation example:\n");
    uint32_t packed_value = 0;
    
    // Pack values using shifts and masks
    packed_value |= (7 & 0x7) << 0;      // 3 bits at position 0
    packed_value |= (31 & 0x1F) << 3;    // 5 bits at position 3
    packed_value |= (255 & 0xFF) << 8;   // 8 bits at position 8
    packed_value |= (65535 & 0xFFFF) << 16; // 16 bits at position 16
    
    printf("   Packed value: 0x%08X\n", packed_value);
    
    // Extract values using shifts and masks
    unsigned int a = (packed_value >> 0) & 0x7;
    unsigned int b = (packed_value >> 3) & 0x1F;
    unsigned int c = (packed_value >> 8) & 0xFF;
    unsigned int d = (packed_value >> 16) & 0xFFFF;
    
    printf("   Extracted: a=%u, b=%u, c=%u, d=%u\n", a, b, c, d);
    printf("   This approach is fully portable\n");
    printf("\n");
}

void set_flags(struct Flags *f, int flag1, int flag2, int flag3, int value) {
    f->flag1 = flag1 ? 1 : 0;
    f->flag2 = flag2 ? 1 : 0;
    f->flag3 = flag3 ? 1 : 0;
    f->value = value & 0x1F;  // Mask to 5 bits
}

void print_flags(struct Flags *f) {
    printf("    Flags: %u%u%u, Value: %u\n", 
           f->flag1, f->flag2, f->flag3, f->value);
}

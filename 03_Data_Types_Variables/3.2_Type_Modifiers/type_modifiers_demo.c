/*
 * type_modifiers_demo.c - Demonstrates type modifiers in C
 * Shows signed/unsigned, short/long/long long with sizes and ranges
 */

#include <stdio.h>
#include <limits.h>

int main() {
    printf("=== Type Modifiers Demo ===\n\n");
    
    // 1. SIGN MODIFIERS
    printf("1. SIGN MODIFIERS:\n");
    
    // Signed types (default)
    signed char s_char = -100;
    signed int s_int = -2000000000;
    
    // Unsigned types
    unsigned char u_char = 200;
    unsigned int u_int = 4000000000U;
    
    printf("Signed types (can be negative):\n");
    printf("- signed char: %d (size: %zu bytes, range: %d to %d)\n", 
           s_char, sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    printf("- signed int: %d (size: %zu bytes, range: %d to %d)\n", 
           s_int, sizeof(signed int), INT_MIN, INT_MAX);
    
    printf("\nUnsigned types (only positive):\n");
    printf("- unsigned char: %u (size: %zu bytes, range: 0 to %u)\n", 
           u_char, sizeof(unsigned char), UCHAR_MAX);
    printf("- unsigned int: %u (size: %zu bytes, range: 0 to %u)\n", 
           u_int, sizeof(unsigned int), UINT_MAX);
    printf("\n");
    
    // 2. SIZE MODIFIERS
    printf("2. SIZE MODIFIERS:\n");
    
    // Short integers
    short int short_num = 32000;
    unsigned short u_short = 65000;
    
    // Long integers
    long int long_num = 2147483648L;
    unsigned long u_long = 4294967295UL;
    
    // Long long integers
    long long int ll_num = 9223372036854775807LL;
    unsigned long long u_ll = 18446744073709551615ULL;
    
    printf("Short types (smaller):\n");
    printf("- short int: %d (size: %zu bytes, range: %d to %d)\n", 
           short_num, sizeof(short int), SHRT_MIN, SHRT_MAX);
    printf("- unsigned short: %u (size: %zu bytes, range: 0 to %u)\n", 
           u_short, sizeof(unsigned short), USHRT_MAX);
    
    printf("\nLong types (larger):\n");
    printf("- long int: %ld (size: %zu bytes, range: %ld to %ld)\n", 
           long_num, sizeof(long int), LONG_MIN, LONG_MAX);
    printf("- unsigned long: %lu (size: %zu bytes, range: 0 to %lu)\n", 
           u_long, sizeof(unsigned long), ULONG_MAX);
    
    printf("\nLong long types (largest):\n");
    printf("- long long: %lld (size: %zu bytes, range: %lld to %lld)\n", 
           ll_num, sizeof(long long int), LLONG_MIN, LLONG_MAX);
    printf("- unsigned long long: %llu (size: %zu bytes, range: 0 to %llu)\n", 
           u_ll, sizeof(unsigned long long), ULLONG_MAX);
    printf("\n");
    
    // 3. MODIFIER COMBINATIONS
    printf("3. MODIFIER COMBINATIONS:\n");
    
    unsigned short int us_combo = 50000;
    signed long long int sll_combo = -1000000000000LL;
    
    printf("- unsigned short int: %u (size: %zu bytes)\n", 
           us_combo, sizeof(unsigned short int));
    printf("- signed long long int: %lld (size: %zu bytes)\n", 
           sll_combo, sizeof(signed long long int));
    printf("\n");
    
    // 4. SIZE HIERARCHY
    printf("4. SIZE HIERARCHY (guaranteed minimums):\n");
    printf("char ≤ short ≤ int ≤ long ≤ long long\n");
    printf("Actual sizes on this system:\n");
    printf("char(%zu) ≤ short(%zu) ≤ int(%zu) ≤ long(%zu) ≤ long long(%zu)\n",
           sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(long long));
    printf("\n");
    
    // 5. PRACTICAL USAGE EXAMPLES
    printf("5. PRACTICAL USAGE EXAMPLES:\n");
    
    // File size (needs large range)
    unsigned long long file_size = 1099511627776ULL;  // 1TB
    printf("- File size: %llu bytes (1TB)\n", file_size);
    
    // Array index (always positive)
    unsigned int array_index = 1000;
    printf("- Array index: %u (unsigned - never negative)\n", array_index);
    
    // Temperature (can be negative)
    signed int temperature = -40;
    printf("- Temperature: %d°C (signed - can be negative)\n", temperature);
    
    // Memory address (large positive number)
    unsigned long memory_addr = 0x7fff5fbff000UL;
    printf("- Memory address: 0x%lx (unsigned long)\n", memory_addr);
    
    printf("\n");
    
    // 6. PLATFORM DIFFERENCES WARNING
    printf("6. PLATFORM CONSIDERATIONS:\n");
    printf("- int size varies: 16-bit (old), 32-bit (common), 64-bit (some)\n");
    printf("- long size varies: 32-bit (Windows), 64-bit (Unix/Linux)\n");
    printf("- Always use sizeof() to check actual sizes\n");
    printf("- Use fixed-width types (int32_t, uint64_t) for portability\n");
    
    printf("\n✓ All type modifiers demonstrated!\n");
    return 0;
}

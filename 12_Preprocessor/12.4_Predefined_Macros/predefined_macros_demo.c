#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void demonstrate_standard_macros(void);
void demonstrate_compiler_macros(void);
void demonstrate_platform_macros(void);
void demonstrate_debug_macros(void);
void demonstrate_utility_macros(void);
void demonstrate_practical_applications(void);

// Utility macros using predefined macros
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

// Location and context macros
#define CURRENT_LOCATION __FILE__ ":" TOSTRING(__LINE__)
#define FUNCTION_INFO() printf("Function: %s() at %s:%d\n", __func__, __FILE__, __LINE__)

// Build information macros
#define BUILD_INFO() \
    printf("Built on %s at %s\n", __DATE__, __TIME__)

#define COMPILER_INFO() do { \
    printf("Compiler: "); \
    printf("%s", get_compiler_name()); \
    printf(" version %s\n", get_compiler_version()); \
} while(0)

// Debug and error reporting macros
#ifdef DEBUG
    #define DBG_PRINT(fmt, ...) \
        printf("[DEBUG %s:%d %s()] " fmt "\n", \
               __FILE__, __LINE__, __func__, ##__VA_ARGS__)
    #define DBG_ASSERT(cond) \
        if (!(cond)) { \
            fprintf(stderr, "Assertion failed: %s at %s:%d in %s()\n", \
                    #cond, __FILE__, __LINE__, __func__); \
            abort(); \
        }
#else
    #define DBG_PRINT(fmt, ...)
    #define DBG_ASSERT(cond)
#endif

#define ERROR_MSG(msg) \
    fprintf(stderr, "ERROR [%s:%d %s()]: %s\n", \
            __FILE__, __LINE__, __func__, msg)

#define WARNING_MSG(msg) \
    fprintf(stderr, "WARNING [%s:%d %s()]: %s\n", \
            __FILE__, __LINE__, __func__, msg)

#define INFO_MSG(msg) \
    printf("INFO [%s:%d %s()]: %s\n", \
           __FILE__, __LINE__, __func__, msg)

// Tracing macros
#ifdef ENABLE_TRACING
    #define TRACE_ENTER() printf("-> %s() [%s:%d]\n", __func__, __FILE__, __LINE__)
    #define TRACE_EXIT() printf("<- %s() [%s:%d]\n", __func__, __FILE__, __LINE__)
#else
    #define TRACE_ENTER()
    #define TRACE_EXIT()
#endif

// Unique variable generation (simplified for demo)
#define TEMP_VAR(suffix) temp_##suffix

// Conditional compilation based on standards
#if defined(__STDC_VERSION__)
    #if __STDC_VERSION__ >= 201112L
        #define HAS_C11_FEATURES
    #elif __STDC_VERSION__ >= 199901L
        #define HAS_C99_FEATURES
    #endif
#endif

// Helper functions for compiler detection
const char* get_compiler_name(void) {
    #ifdef __GNUC__
        #ifdef __clang__
            return "Clang (GCC compatible)";
        #else
            return "GCC";
        #endif
    #elif defined(_MSC_VER)
        return "Microsoft Visual C++";
    #elif defined(__INTEL_COMPILER)
        return "Intel C Compiler";
    #else
        return "Unknown Compiler";
    #endif
}

const char* get_compiler_version(void) {
    static char version_str[64];
    
    #ifdef __GNUC__
        #ifdef __clang__
            snprintf(version_str, sizeof(version_str), "%d.%d.%d", 
                    __clang_major__, __clang_minor__, __clang_patchlevel__);
        #else
            snprintf(version_str, sizeof(version_str), "%d.%d.%d", 
                    __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
        #endif
    #elif defined(_MSC_VER)
        snprintf(version_str, sizeof(version_str), "%d", _MSC_VER);
    #else
        strcpy(version_str, "Unknown");
    #endif
    
    return version_str;
}

const char* get_platform_name(void) {
    #ifdef _WIN32
        #ifdef _WIN64
            return "Windows 64-bit";
        #else
            return "Windows 32-bit";
        #endif
    #elif defined(__APPLE__)
        return "macOS/iOS";
    #elif defined(__linux__)
        return "Linux";
    #elif defined(__unix__)
        return "Unix";
    #else
        return "Unknown Platform";
    #endif
}

const char* get_architecture(void) {
    #ifdef __x86_64__
        return "x86-64";
    #elif defined(__i386__)
        return "x86";
    #elif defined(__aarch64__)
        return "ARM64";
    #elif defined(__arm__)
        return "ARM";
    #else
        return "Unknown Architecture";
    #endif
}

// Example functions for demonstration
void example_function_with_tracing(void) {
    TRACE_ENTER();
    
    printf("  Doing some work in %s()...\n", __func__);
    
    // Create unique temporary variables with explicit suffixes
    int TEMP_VAR(1) = 42;
    int TEMP_VAR(2) = 100;
    
    printf("  temp_1 = %d\n", temp_1);
    printf("  temp_2 = %d\n", temp_2);
    
    TRACE_EXIT();
}

void example_error_handling(void) {
    TRACE_ENTER();
    
    INFO_MSG("Starting error handling demonstration");
    
    // Simulate different types of messages
    int test_value = 42;
    
    if (test_value > 0) {
        INFO_MSG("Test value is positive");
    }
    
    if (test_value < 100) {
        WARNING_MSG("Test value is less than 100");
    }
    
    // This would normally be an error condition
    if (test_value != 999) {
        // ERROR_MSG("Test value is not 999 (this is expected)");
        printf("  (Skipping error message to avoid stderr output)\n");
    }
    
    // Debug assertion (only active if DEBUG is defined)
    DBG_ASSERT(test_value == 42);
    DBG_PRINT("Debug assertion passed for value %d", test_value);
    
    TRACE_EXIT();
}

int main(void) {
    printf("=== Predefined Macros Demo ===\n\n");
    
    demonstrate_standard_macros();
    demonstrate_compiler_macros();
    demonstrate_platform_macros();
    demonstrate_debug_macros();
    demonstrate_utility_macros();
    demonstrate_practical_applications();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_standard_macros(void) {
    printf("1. STANDARD PREDEFINED MACROS\n");
    printf("----------------------------------------\n");
    
    printf("File and Line Information:\n");
    printf("  Current file: %s\n", __FILE__);
    printf("  Current line: %d\n", __LINE__);
    printf("  Current function: %s\n", __func__);
    
    printf("\nDate and Time Information:\n");
    printf("  Compilation date: %s\n", __DATE__);
    printf("  Compilation time: %s\n", __TIME__);
    
    printf("\nLanguage Standard Information:\n");
    #ifdef __STDC__
        printf("  Standard C compiler: YES (__STDC__ = %d)\n", __STDC__);
    #else
        printf("  Standard C compiler: NO\n");
    #endif
    
    #ifdef __STDC_VERSION__
        printf("  C standard version: %ldL", __STDC_VERSION__);
        #if __STDC_VERSION__ >= 201112L
            printf(" (C11 or later)\n");
        #elif __STDC_VERSION__ >= 199901L
            printf(" (C99)\n");
        #elif __STDC_VERSION__ >= 199409L
            printf(" (C94)\n");
        #else
            printf(" (C89/C90)\n");
        #endif
    #else
        printf("  C standard version: Not defined (likely C89/C90)\n");
    #endif
    
    #ifdef __STDC_HOSTED__
        printf("  Hosted implementation: %s\n", __STDC_HOSTED__ ? "YES" : "NO");
    #else
        printf("  Hosted implementation: Not defined\n");
    #endif
    
    printf("\nFeature Detection:\n");
    #ifdef HAS_C11_FEATURES
        printf("  ✓ C11 features available\n");
    #elif defined(HAS_C99_FEATURES)
        printf("  ✓ C99 features available\n");
    #else
        printf("  ⚠ Using C89/C90 features only\n");
    #endif
    
    printf("\n");
}

void demonstrate_compiler_macros(void) {
    printf("2. COMPILER-SPECIFIC MACROS\n");
    printf("----------------------------------------\n");
    
    printf("Compiler Detection:\n");
    printf("  Compiler: %s\n", get_compiler_name());
    printf("  Version: %s\n", get_compiler_version());
    
    printf("\nDetailed Compiler Information:\n");
    
    #ifdef __GNUC__
        printf("  GCC/GCC-compatible compiler detected\n");
        printf("  Major version: %d\n", __GNUC__);
        printf("  Minor version: %d\n", __GNUC_MINOR__);
        #ifdef __GNUC_PATCHLEVEL__
            printf("  Patch level: %d\n", __GNUC_PATCHLEVEL__);
        #endif
        
        #ifdef __clang__
            printf("  Clang-specific information:\n");
            printf("    Clang major: %d\n", __clang_major__);
            printf("    Clang minor: %d\n", __clang_minor__);
            printf("    Clang patch: %d\n", __clang_patchlevel__);
        #endif
        
        #ifdef __VERSION__
            printf("  Version string: %s\n", __VERSION__);
        #endif
    #elif defined(_MSC_VER)
        printf("  Microsoft Visual C++ detected\n");
        printf("  Version: %d\n", _MSC_VER);
        #ifdef _MSC_FULL_VER
            printf("  Full version: %d\n", _MSC_FULL_VER);
        #endif
    #else
        printf("  Unknown or unsupported compiler\n");
    #endif
    
    printf("\nCompiler Feature Support:\n");
    #ifdef __GNUC__
        printf("  ✓ GCC built-in functions available\n");
        printf("  ✓ GCC attributes supported\n");
    #endif
    
    #ifdef __clang__
        printf("  ✓ Clang-specific features available\n");
    #endif
    
    printf("\n");
}

void demonstrate_platform_macros(void) {
    printf("3. PLATFORM DETECTION MACROS\n");
    printf("----------------------------------------\n");
    
    printf("Platform Information:\n");
    printf("  Platform: %s\n", get_platform_name());
    printf("  Architecture: %s\n", get_architecture());
    
    printf("\nDetailed Platform Detection:\n");
    
    // Operating System
    printf("  Operating System:\n");
    #ifdef _WIN32
        printf("    ✓ Windows platform detected\n");
        #ifdef _WIN64
            printf("    ✓ 64-bit Windows\n");
        #else
            printf("    ⚠ 32-bit Windows\n");
        #endif
    #elif defined(__APPLE__)
        printf("    ✓ Apple platform detected\n");
        #ifdef __MACH__
            printf("    ✓ Mach kernel (macOS/iOS)\n");
        #endif
    #elif defined(__linux__)
        printf("    ✓ Linux platform detected\n");
    #elif defined(__unix__)
        printf("    ✓ Unix-like platform detected\n");
    #else
        printf("    ⚠ Unknown platform\n");
    #endif
    
    // Architecture
    printf("  Architecture:\n");
    #ifdef __x86_64__
        printf("    ✓ x86-64 (64-bit x86) architecture\n");
    #elif defined(__i386__)
        printf("    ✓ x86 (32-bit) architecture\n");
    #elif defined(__aarch64__)
        printf("    ✓ ARM64 (64-bit ARM) architecture\n");
    #elif defined(__arm__)
        printf("    ✓ ARM (32-bit) architecture\n");
    #else
        printf("    ⚠ Unknown architecture\n");
    #endif
    
    // Endianness
    printf("  Byte Order:\n");
    #if defined(__BYTE_ORDER__)
        #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
            printf("    ✓ Little-endian byte order\n");
        #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
            printf("    ✓ Big-endian byte order\n");
        #else
            printf("    ⚠ Unknown byte order\n");
        #endif
    #else
        printf("    ⚠ Byte order not determined\n");
    #endif
    
    printf("\n");
}

void demonstrate_debug_macros(void) {
    printf("4. DEBUG AND ERROR REPORTING MACROS\n");
    printf("----------------------------------------\n");
    
    printf("Current Location Information:\n");
    FUNCTION_INFO();
    printf("  Location string: %s\n", CURRENT_LOCATION);
    
    printf("\nBuild Information:\n");
    BUILD_INFO();
    COMPILER_INFO();
    
    printf("\nDebug Status:\n");
    #ifdef DEBUG
        printf("  ✓ Debug mode is ENABLED\n");
        printf("  ✓ Debug macros are active\n");
    #else
        printf("  ⚠ Debug mode is DISABLED\n");
        printf("  ⚠ Debug macros are inactive\n");
    #endif
    
    printf("\nTracing Status:\n");
    #ifdef ENABLE_TRACING
        printf("  ✓ Function tracing is ENABLED\n");
    #else
        printf("  ⚠ Function tracing is DISABLED\n");
    #endif
    
    printf("\nError Reporting Examples:\n");
    INFO_MSG("This is an informational message");
    WARNING_MSG("This is a warning message");
    // ERROR_MSG("This is an error message");  // Commented to avoid stderr
    printf("  (Error message example skipped to keep output clean)\n");
    
    printf("\n");
}

void demonstrate_utility_macros(void) {
    printf("5. UTILITY MACROS WITH PREDEFINED VALUES\n");
    printf("----------------------------------------\n");
    
    printf("Unique Variable Generation:\n");
    
    // Demonstrate unique variable names with explicit suffixes
    int TEMP_VAR(a) = 100;
    int TEMP_VAR(b) = 200;
    int TEMP_VAR(c) = 300;
    
    printf("  Created unique variables: temp_a, temp_b, temp_c\n");
    printf("  Values: %d, %d, %d\n", temp_a, temp_b, temp_c);
    
    printf("\nString Conversion:\n");
    #define TEST_MACRO 42
    printf("  STRINGIFY(TEST_MACRO) = \"%s\"\n", STRINGIFY(TEST_MACRO));
    printf("  TOSTRING(TEST_MACRO) = \"%s\"\n", TOSTRING(TEST_MACRO));
    printf("  Current line as string: \"%s\"\n", TOSTRING(__LINE__));
    
    printf("\nConditional Macro Definitions:\n");
    
    // Show how macros can be conditionally defined
    #if defined(__GNUC__) && !defined(__clang__)
        #define COMPILER_SPECIFIC_FEATURE "GCC-specific optimization"
    #elif defined(__clang__)
        #define COMPILER_SPECIFIC_FEATURE "Clang-specific optimization"
    #elif defined(_MSC_VER)
        #define COMPILER_SPECIFIC_FEATURE "MSVC-specific optimization"
    #else
        #define COMPILER_SPECIFIC_FEATURE "Generic implementation"
    #endif
    
    printf("  Compiler-specific feature: %s\n", COMPILER_SPECIFIC_FEATURE);
    
    printf("\nMacro Existence Testing:\n");
    #ifdef __STDC_VERSION__
        printf("  ✓ __STDC_VERSION__ is defined\n");
    #else
        printf("  ✗ __STDC_VERSION__ is not defined\n");
    #endif
    
    #ifdef __func__
        printf("  ✓ __func__ is available\n");
    #else
        printf("  ✗ __func__ is not available\n");
    #endif
    
    printf("\n");
}

void demonstrate_practical_applications(void) {
    printf("6. PRACTICAL APPLICATIONS\n");
    printf("----------------------------------------\n");
    
    printf("Function Tracing Example:\n");
    example_function_with_tracing();
    
    printf("\nError Handling Example:\n");
    example_error_handling();
    
    printf("\nVersion and Compatibility Information:\n");
    printf("  Application compiled with:\n");
    printf("    Compiler: %s %s\n", get_compiler_name(), get_compiler_version());
    printf("    Platform: %s (%s)\n", get_platform_name(), get_architecture());
    printf("    Build date: %s %s\n", __DATE__, __TIME__);
    printf("    Source file: %s\n", __FILE__);
    
    #ifdef HAS_C11_FEATURES
        printf("    C standard: C11 or later\n");
    #elif defined(HAS_C99_FEATURES)
        printf("    C standard: C99\n");
    #else
        printf("    C standard: C89/C90\n");
    #endif
    
    printf("\nDebugging Context:\n");
    printf("  Current execution context:\n");
    printf("    Function: %s()\n", __func__);
    printf("    File: %s\n", __FILE__);
    printf("    Line: %d\n", __LINE__);
    
    printf("\nConditional Feature Summary:\n");
    int feature_count = 0;
    
    #ifdef DEBUG
        printf("  ✓ Debug features\n");
        feature_count++;
    #endif
    
    #ifdef ENABLE_TRACING
        printf("  ✓ Function tracing\n");
        feature_count++;
    #endif
    
    #ifdef HAS_C99_FEATURES
        printf("  ✓ C99 features\n");
        feature_count++;
    #endif
    
    #ifdef HAS_C11_FEATURES
        printf("  ✓ C11 features\n");
        feature_count++;
    #endif
    
    if (feature_count == 0) {
        printf("  ⚠ No optional features enabled\n");
    } else {
        printf("  Total optional features enabled: %d\n", feature_count);
    }
    
    printf("\n");
}

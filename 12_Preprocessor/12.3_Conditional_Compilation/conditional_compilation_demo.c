#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configuration flags (normally set by build system)
#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL 1
#endif

#ifndef FEATURE_LOGGING
#define FEATURE_LOGGING 1
#endif

#ifndef FEATURE_NETWORKING
#define FEATURE_NETWORKING 0
#endif

#ifndef FEATURE_ENCRYPTION
#define FEATURE_ENCRYPTION 1
#endif

// Version information
#define VERSION_MAJOR 2
#define VERSION_MINOR 1
#define VERSION_PATCH 0

// Function prototypes
void demonstrate_basic_conditionals(void);
void demonstrate_platform_detection(void);
void demonstrate_feature_flags(void);
void demonstrate_debug_release(void);
void demonstrate_version_control(void);
void demonstrate_complex_conditions(void);

// Platform detection
#ifdef _WIN32
    #define PLATFORM_NAME "Windows"
    #define PATH_SEPARATOR '\\'
    #define NEWLINE "\r\n"
#elif defined(__linux__)
    #define PLATFORM_NAME "Linux"
    #define PATH_SEPARATOR '/'
    #define NEWLINE "\n"
#elif defined(__APPLE__)
    #define PLATFORM_NAME "macOS"
    #define PATH_SEPARATOR '/'
    #define NEWLINE "\n"
#else
    #define PLATFORM_NAME "Unknown"
    #define PATH_SEPARATOR '/'
    #define NEWLINE "\n"
#endif

// Compiler detection
#ifdef __GNUC__
    #define COMPILER_NAME "GCC"
    #define COMPILER_VERSION __GNUC__
#elif defined(__clang__)
    #define COMPILER_NAME "Clang"
    #define COMPILER_VERSION __clang_major__
#elif defined(_MSC_VER)
    #define COMPILER_NAME "MSVC"
    #define COMPILER_VERSION _MSC_VER
#else
    #define COMPILER_NAME "Unknown"
    #define COMPILER_VERSION 0
#endif

// Architecture detection
#ifdef __x86_64__
    #define ARCH_NAME "x86_64"
    #define ARCH_BITS 64
#elif defined(__i386__)
    #define ARCH_NAME "x86"
    #define ARCH_BITS 32
#elif defined(__arm__)
    #define ARCH_NAME "ARM"
    #define ARCH_BITS 32
#elif defined(__aarch64__)
    #define ARCH_NAME "ARM64"
    #define ARCH_BITS 64
#else
    #define ARCH_NAME "Unknown"
    #define ARCH_BITS 0
#endif

// Debug macros based on DEBUG_LEVEL
#if DEBUG_LEVEL >= 1
    #define DBG_PRINT(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#else
    #define DBG_PRINT(fmt, ...)
#endif

#if DEBUG_LEVEL >= 2
    #define DBG_VERBOSE(fmt, ...) printf("[VERBOSE] " fmt "\n", ##__VA_ARGS__)
#else
    #define DBG_VERBOSE(fmt, ...)
#endif

#if DEBUG_LEVEL >= 3
    #define DBG_TRACE(fmt, ...) printf("[TRACE] " fmt "\n", ##__VA_ARGS__)
#else
    #define DBG_TRACE(fmt, ...)
#endif

// Feature-dependent function declarations
#if FEATURE_LOGGING
void log_message(const char* level, const char* message);
void log_init(void);
#endif

#if FEATURE_NETWORKING
int network_send(const char* data, size_t len);
int network_receive(char* buffer, size_t max_len);
#endif

#if FEATURE_ENCRYPTION
void encrypt_data(char* data, size_t len);
void decrypt_data(char* data, size_t len);
#endif

// Conditional compilation for different build types
#ifdef RELEASE_BUILD
    #define OPTIMIZATION_LEVEL "O3"
    #define ASSERT(cond)
    #define INLINE inline
#elif defined(DEBUG_BUILD)
    #define OPTIMIZATION_LEVEL "O0"
    #define ASSERT(cond) \
        if (!(cond)) { \
            fprintf(stderr, "Assertion failed: %s at %s:%d\n", \
                    #cond, __FILE__, __LINE__); \
            abort(); \
        }
    #define INLINE
#else
    #define OPTIMIZATION_LEVEL "O1"
    #define ASSERT(cond)
    #define INLINE
#endif

// Version-based feature availability
#if (VERSION_MAJOR >= 2)
    #define HAS_NEW_API
    void new_api_function(void);
#endif

#if (VERSION_MAJOR == 1) && (VERSION_MINOR >= 5)
    #define HAS_LEGACY_FEATURE
    void legacy_feature(void);
#endif

// Complex conditional compilation
#if defined(FEATURE_LOGGING) && (DEBUG_LEVEL >= 2)
    #define ADVANCED_LOGGING_ENABLED
#endif

#if !defined(EMBEDDED_SYSTEM) || defined(FULL_FEATURES)
    #define HAS_ADVANCED_FEATURES
#endif

int main(void) {
    printf("=== Conditional Compilation Demo ===\n\n");
    
    demonstrate_basic_conditionals();
    demonstrate_platform_detection();
    demonstrate_feature_flags();
    demonstrate_debug_release();
    demonstrate_version_control();
    demonstrate_complex_conditions();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_conditionals(void) {
    printf("1. BASIC CONDITIONAL COMPILATION\n");
    printf("----------------------------------------\n");
    
    printf("Compile-time Configuration:\n");
    printf("  DEBUG_LEVEL = %d\n", DEBUG_LEVEL);
    printf("  FEATURE_LOGGING = %d\n", FEATURE_LOGGING);
    printf("  FEATURE_NETWORKING = %d\n", FEATURE_NETWORKING);
    printf("  FEATURE_ENCRYPTION = %d\n", FEATURE_ENCRYPTION);
    
    printf("\nConditional Code Execution:\n");
    
    // Basic ifdef/ifndef
    #ifdef FEATURE_LOGGING
        printf("  ✓ Logging feature is ENABLED\n");
    #else
        printf("  ✗ Logging feature is DISABLED\n");
    #endif
    
    #ifndef FEATURE_NETWORKING
        printf("  ✗ Networking feature is DISABLED\n");
    #else
        printf("  ✓ Networking feature is ENABLED\n");
    #endif
    
    // Multi-level conditions
    #if DEBUG_LEVEL >= 3
        printf("  ✓ Trace debugging enabled (level %d)\n", DEBUG_LEVEL);
    #elif DEBUG_LEVEL >= 2
        printf("  ✓ Verbose debugging enabled (level %d)\n", DEBUG_LEVEL);
    #elif DEBUG_LEVEL >= 1
        printf("  ✓ Basic debugging enabled (level %d)\n", DEBUG_LEVEL);
    #else
        printf("  ✗ Debugging disabled (level %d)\n", DEBUG_LEVEL);
    #endif
    
    printf("\nDebug Output Examples:\n");
    DBG_PRINT("This is a basic debug message");
    DBG_VERBOSE("This is a verbose debug message");
    DBG_TRACE("This is a trace debug message");
    
    printf("\n");
}

void demonstrate_platform_detection(void) {
    printf("2. PLATFORM DETECTION\n");
    printf("----------------------------------------\n");
    
    printf("Platform Information:\n");
    printf("  Operating System: %s\n", PLATFORM_NAME);
    printf("  Path Separator: '%c'\n", PATH_SEPARATOR);
    printf("  Line Ending: ");
    if (strcmp(NEWLINE, "\r\n") == 0) {
        printf("CRLF (Windows)\\r\\n\n");
    } else {
        printf("LF (Unix/Linux/macOS)\\n\n");
    }
    
    printf("Compiler Information:\n");
    printf("  Compiler: %s\n", COMPILER_NAME);
    printf("  Version: %d\n", COMPILER_VERSION);
    
    printf("Architecture Information:\n");
    printf("  Architecture: %s\n", ARCH_NAME);
    printf("  Bits: %d-bit\n", ARCH_BITS);
    
    printf("\nPlatform-specific Code:\n");
    
    // Platform-specific file path example
    char example_path[256];
    #ifdef _WIN32
        snprintf(example_path, sizeof(example_path), "C:%cUsers%cuser%cfile.txt", 
                PATH_SEPARATOR, PATH_SEPARATOR, PATH_SEPARATOR);
        printf("  Windows path: %s\n", example_path);
    #else
        snprintf(example_path, sizeof(example_path), "%chome%cuser%cfile.txt", 
                PATH_SEPARATOR, PATH_SEPARATOR, PATH_SEPARATOR);
        printf("  Unix-like path: %s\n", example_path);
    #endif
    
    // Compiler-specific features
    #ifdef __GNUC__
        printf("  Using GCC-specific optimizations\n");
    #elif defined(__clang__)
        printf("  Using Clang-specific optimizations\n");
    #elif defined(_MSC_VER)
        printf("  Using MSVC-specific optimizations\n");
    #else
        printf("  Using generic compiler settings\n");
    #endif
    
    printf("\n");
}

void demonstrate_feature_flags(void) {
    printf("3. FEATURE FLAGS\n");
    printf("----------------------------------------\n");
    
    printf("Feature Availability:\n");
    
    #if FEATURE_LOGGING
        printf("  ✓ Logging System: Available\n");
        log_init();
        log_message("INFO", "Logging system initialized");
    #else
        printf("  ✗ Logging System: Disabled\n");
    #endif
    
    #if FEATURE_NETWORKING
        printf("  ✓ Network Module: Available\n");
        printf("    - Can send data over network\n");
        printf("    - Can receive data from network\n");
    #else
        printf("  ✗ Network Module: Disabled\n");
        printf("    - Network operations not available\n");
    #endif
    
    #if FEATURE_ENCRYPTION
        printf("  ✓ Encryption Module: Available\n");
        char test_data[] = "Secret Message";
        printf("    Original: %s\n", test_data);
        encrypt_data(test_data, strlen(test_data));
        printf("    Encrypted: %s\n", test_data);
        decrypt_data(test_data, strlen(test_data));
        printf("    Decrypted: %s\n", test_data);
    #else
        printf("  ✗ Encryption Module: Disabled\n");
        printf("    - Data encryption not available\n");
    #endif
    
    printf("\nConditional Function Calls:\n");
    
    // Feature-dependent operations
    const char* sample_data = "Sample data for processing";
    
    #if FEATURE_LOGGING
        log_message("DEBUG", "Processing sample data");
    #endif
    
    printf("  Processing: %s\n", sample_data);
    
    #if FEATURE_ENCRYPTION
        printf("  ✓ Data can be encrypted if needed\n");
    #else
        printf("  ⚠ Data will be stored in plain text\n");
    #endif
    
    #if FEATURE_NETWORKING
        printf("  ✓ Data can be transmitted over network\n");
    #else
        printf("  ⚠ Data limited to local processing\n");
    #endif
    
    printf("\n");
}

void demonstrate_debug_release(void) {
    printf("4. DEBUG vs RELEASE BUILDS\n");
    printf("----------------------------------------\n");
    
    printf("Build Configuration:\n");
    
    #ifdef DEBUG_BUILD
        printf("  Build Type: DEBUG\n");
        printf("  Optimization: %s\n", OPTIMIZATION_LEVEL);
        printf("  Assertions: ENABLED\n");
        printf("  Inline Functions: DISABLED\n");
    #elif defined(RELEASE_BUILD)
        printf("  Build Type: RELEASE\n");
        printf("  Optimization: %s\n", OPTIMIZATION_LEVEL);
        printf("  Assertions: DISABLED\n");
        printf("  Inline Functions: ENABLED\n");
    #else
        printf("  Build Type: DEFAULT\n");
        printf("  Optimization: %s\n", OPTIMIZATION_LEVEL);
        printf("  Assertions: DISABLED\n");
        printf("  Inline Functions: DISABLED\n");
    #endif
    
    printf("\nDebug Features:\n");
    
    // Test assertion (only active in debug builds)
    int test_value = 42;
    printf("  Testing assertion with value %d...\n", test_value);
    ASSERT(test_value == 42);
    printf("  ✓ Assertion passed (or disabled)\n");
    
    // Debug-only code
    #ifdef DEBUG_BUILD
        printf("  ✓ Extra debugging information available\n");
        printf("  ✓ Memory leak detection enabled\n");
        printf("  ✓ Performance profiling available\n");
    #else
        printf("  ⚠ Debug features not available in this build\n");
    #endif
    
    // Performance vs debugging trade-off
    printf("\nPerformance vs Debugging Trade-off:\n");
    #ifdef RELEASE_BUILD
        printf("  ✓ Maximum performance optimization\n");
        printf("  ✗ Limited debugging information\n");
    #else
        printf("  ✓ Full debugging capabilities\n");
        printf("  ⚠ Reduced performance for debugging\n");
    #endif
    
    printf("\n");
}

void demonstrate_version_control(void) {
    printf("5. VERSION-BASED COMPILATION\n");
    printf("----------------------------------------\n");
    
    printf("Version Information:\n");
    printf("  Version: %d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    
    printf("\nAPI Availability:\n");
    
    #ifdef HAS_NEW_API
        printf("  ✓ New API (v2.0+): Available\n");
        new_api_function();
    #else
        printf("  ✗ New API (v2.0+): Not available\n");
    #endif
    
    #ifdef HAS_LEGACY_FEATURE
        printf("  ✓ Legacy Feature (v1.5+): Available\n");
        legacy_feature();
    #else
        printf("  ✗ Legacy Feature (v1.5+): Not available\n");
    #endif
    
    // Version-specific behavior
    printf("\nVersion-specific Behavior:\n");
    
    #if VERSION_MAJOR >= 2
        printf("  Using modern algorithms (v2.0+)\n");
        printf("  Enhanced error handling enabled\n");
        printf("  Improved performance optimizations\n");
    #elif VERSION_MAJOR == 1
        printf("  Using legacy algorithms (v1.x)\n");
        #if VERSION_MINOR >= 5
            printf("  Some enhanced features available (v1.5+)\n");
        #else
            printf("  Basic feature set only\n");
        #endif
    #else
        printf("  Unknown version behavior\n");
    #endif
    
    // Backward compatibility
    printf("\nBackward Compatibility:\n");
    #if VERSION_MAJOR >= 2
        printf("  ✓ Supports v1.x API for compatibility\n");
        printf("  ✓ Automatic migration of old data formats\n");
    #else
        printf("  ⚠ Limited compatibility with newer versions\n");
    #endif
    
    printf("\n");
}

void demonstrate_complex_conditions(void) {
    printf("6. COMPLEX CONDITIONS\n");
    printf("----------------------------------------\n");
    
    printf("Multi-condition Compilation:\n");
    
    // Complex AND conditions
    #if defined(FEATURE_LOGGING) && (DEBUG_LEVEL >= 2)
        printf("  ✓ Advanced logging enabled (logging + debug level 2+)\n");
        #ifdef ADVANCED_LOGGING_ENABLED
            printf("    - Advanced logging macro is defined\n");
        #endif
    #else
        printf("  ✗ Advanced logging disabled\n");
    #endif
    
    // Complex OR conditions
    #if !defined(EMBEDDED_SYSTEM) || defined(FULL_FEATURES)
        printf("  ✓ Advanced features available\n");
        #ifdef HAS_ADVANCED_FEATURES
            printf("    - Advanced features macro is defined\n");
        #endif
    #else
        printf("  ✗ Advanced features disabled for embedded system\n");
    #endif
    
    // Arithmetic conditions
    #define BUFFER_SIZE 1024
    #define MAX_CONNECTIONS 100
    
    #if (BUFFER_SIZE * MAX_CONNECTIONS) > 50000
        printf("  ✓ Large memory pool enabled (%d bytes total)\n", 
               BUFFER_SIZE * MAX_CONNECTIONS);
    #else
        printf("  ⚠ Using small memory pool (%d bytes total)\n", 
               BUFFER_SIZE * MAX_CONNECTIONS);
    #endif
    
    // Nested conditions
    printf("\nNested Conditional Logic:\n");
    
    #ifdef FEATURE_ENCRYPTION
        #if FEATURE_LOGGING
            printf("  ✓ Secure logging: Encryption + Logging both enabled\n");
            printf("    - Log entries will be encrypted\n");
        #else
            printf("  ⚠ Encryption available but logging disabled\n");
        #endif
    #else
        #if FEATURE_LOGGING
            printf("  ⚠ Logging available but encryption disabled\n");
            printf("    - Log entries will be in plain text\n");
        #else
            printf("  ✗ Neither encryption nor logging available\n");
        #endif
    #endif
    
    // Platform + feature combinations
    printf("\nPlatform + Feature Combinations:\n");
    
    #if defined(__APPLE__) && FEATURE_NETWORKING
        printf("  ✓ macOS networking optimizations available\n");
    #elif defined(_WIN32) && FEATURE_NETWORKING
        printf("  ✓ Windows networking optimizations available\n");
    #elif defined(__linux__) && FEATURE_NETWORKING
        printf("  ✓ Linux networking optimizations available\n");
    #else
        printf("  ⚠ Generic networking or networking disabled\n");
    #endif
    
    printf("\n");
}

// Feature-dependent function implementations
#if FEATURE_LOGGING
void log_init(void) {
    printf("    [LOG] Logging system initialized\n");
}

void log_message(const char* level, const char* message) {
    printf("    [LOG:%s] %s\n", level, message);
}
#endif

#if FEATURE_NETWORKING
int network_send(const char* data, size_t len) {
    printf("    [NET] Sending %zu bytes: %.20s%s\n", 
           len, data, len > 20 ? "..." : "");
    return (int)len;
}

int network_receive(char* buffer, size_t max_len) {
    const char* sample = "Received data";
    size_t len = strlen(sample);
    if (len < max_len) {
        strcpy(buffer, sample);
        printf("    [NET] Received %zu bytes: %s\n", len, buffer);
        return (int)len;
    }
    return -1;
}
#endif

#if FEATURE_ENCRYPTION
void encrypt_data(char* data, size_t len) {
    // Simple XOR encryption for demo
    for (size_t i = 0; i < len; i++) {
        data[i] ^= 0x55;
    }
}

void decrypt_data(char* data, size_t len) {
    // XOR decryption (same as encryption for XOR)
    encrypt_data(data, len);
}
#endif

// Version-dependent function implementations
#ifdef HAS_NEW_API
void new_api_function(void) {
    printf("    [API] New API function called (v2.0+ feature)\n");
}
#endif

#ifdef HAS_LEGACY_FEATURE
void legacy_feature(void) {
    printf("    [API] Legacy feature called (v1.5+ feature)\n");
}
#endif

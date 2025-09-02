# 12.3 Conditional Compilation

Conditional compilation allows code to be included or excluded during preprocessing based on conditions, enabling platform-specific code, debug builds, and feature toggles.

## Basic Conditional Directives

### **#ifdef and #ifndef**
```c
#ifdef DEBUG
    printf("Debug mode enabled\n");
#endif

#ifndef RELEASE
    printf("Not in release mode\n");
#endif
```

### **#if, #elif, #else**
```c
#if VERSION >= 2
    // Version 2.0+ code
#elif VERSION == 1
    // Version 1.x code
#else
    // Legacy code
#endif
```

## Platform Detection

### **Operating System Detection**
```c
#ifdef _WIN32
    #include <windows.h>
    #define PATH_SEPARATOR '\\'
#elif defined(__linux__)
    #include <unistd.h>
    #define PATH_SEPARATOR '/'
#elif defined(__APPLE__)
    #include <sys/types.h>
    #define PATH_SEPARATOR '/'
#else
    #error "Unsupported platform"
#endif
```

### **Compiler Detection**
```c
#ifdef __GNUC__
    #define COMPILER_GCC
    #define FORCE_INLINE __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
    #define COMPILER_MSVC
    #define FORCE_INLINE __forceinline
#elif defined(__clang__)
    #define COMPILER_CLANG
    #define FORCE_INLINE __attribute__((always_inline)) inline
#endif
```

## Feature Flags

### **Optional Features**
```c
#define FEATURE_LOGGING 1
#define FEATURE_ENCRYPTION 0
#define FEATURE_NETWORKING 1

#if FEATURE_LOGGING
    void log_message(const char* msg);
#endif

#if FEATURE_ENCRYPTION
    void encrypt_data(char* data, size_t len);
#endif
```

### **Configuration-based Compilation**
```c
#ifdef ENABLE_PROFILING
    #define PROFILE_START() start_profiler()
    #define PROFILE_END() end_profiler()
#else
    #define PROFILE_START()
    #define PROFILE_END()
#endif
```

## Debug vs Release Builds

### **Debug Macros**
```c
#ifdef DEBUG
    #define DBG_PRINT(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
    #define ASSERT(cond) \
        if (!(cond)) { \
            fprintf(stderr, "Assertion failed: %s at %s:%d\n", \
                    #cond, __FILE__, __LINE__); \
            abort(); \
        }
#else
    #define DBG_PRINT(fmt, ...)
    #define ASSERT(cond)
#endif
```

### **Optimization Levels**
```c
#if defined(DEBUG)
    #define OPTIMIZATION_LEVEL 0
    #define INLINE
#elif defined(RELEASE)
    #define OPTIMIZATION_LEVEL 3
    #define INLINE inline
#else
    #define OPTIMIZATION_LEVEL 1
    #define INLINE
#endif
```

## Version Control

### **API Version Compatibility**
```c
#define API_VERSION_MAJOR 2
#define API_VERSION_MINOR 1

#if API_VERSION_MAJOR >= 2
    // New API functions
    int new_function(void);
#endif

#if (API_VERSION_MAJOR == 1) && (API_VERSION_MINOR >= 5)
    // Functions added in v1.5
    int legacy_function(void);
#endif
```

### **Backward Compatibility**
```c
#ifdef LEGACY_SUPPORT
    // Old function names for compatibility
    #define old_function_name new_function_name
    #define OLD_CONSTANT NEW_CONSTANT
#endif
```

## Architecture-specific Code

### **CPU Architecture**
```c
#ifdef __x86_64__
    #define ARCH_64BIT
    #define CACHE_LINE_SIZE 64
#elif defined(__i386__)
    #define ARCH_32BIT
    #define CACHE_LINE_SIZE 32
#elif defined(__arm__)
    #define ARCH_ARM
    #define CACHE_LINE_SIZE 32
#endif
```

### **Endianness Detection**
```c
#if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
    #define BIG_ENDIAN_SYSTEM
#elif defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
    #define LITTLE_ENDIAN_SYSTEM
#else
    #error "Cannot determine byte order"
#endif
```

## Complex Conditions

### **Multiple Conditions**
```c
#if defined(WINDOWS) && defined(DEBUG) && (VERSION >= 2)
    // Windows debug build v2.0+
    void windows_debug_init(void);
#endif

#if !defined(EMBEDDED) || defined(FULL_FEATURES)
    // Full feature set for non-embedded or explicitly enabled
    void advanced_features(void);
#endif
```

### **Arithmetic in Conditions**
```c
#define BUFFER_SIZE 1024
#define MAX_USERS 100

#if (BUFFER_SIZE * MAX_USERS) > 50000
    #define USE_LARGE_MEMORY_POOL
#endif

#if (BUFFER_SIZE % 64) == 0
    #define BUFFER_ALIGNED
#endif
```

## Header Guards Alternative

### **#pragma once vs Traditional Guards**
```c
// Traditional header guard
#ifndef MYHEADER_H
#define MYHEADER_H
// Header content
#endif

// Or modern pragma (compiler-specific)
#pragma once
// Header content
```

## Conditional Function Definitions

### **Platform-specific Implementations**
```c
#ifdef _WIN32
void sleep_ms(int milliseconds) {
    Sleep(milliseconds);
}
#else
void sleep_ms(int milliseconds) {
    usleep(milliseconds * 1000);
}
#endif
```

### **Feature-dependent Functions**
```c
#if FEATURE_NETWORKING
int send_data(const char* data, size_t len) {
    // Network implementation
    return network_send(data, len);
}
#else
int send_data(const char* data, size_t len) {
    // Stub implementation
    (void)data; (void)len;
    return -1;  // Not supported
}
#endif
```

## Best Practices

### **Clear Condition Names**
```c
// Good - descriptive names
#ifdef ENABLE_LOGGING
#ifdef PLATFORM_WINDOWS
#ifdef API_VERSION_2

// Avoid - unclear names
#ifdef FLAG1
#ifdef TEMP
#ifdef X
```

### **Consistent Indentation**
```c
#ifdef CONDITION1
    #ifdef CONDITION2
        // Nested code
    #endif
#endif
```

### **Documentation**
```c
// Feature flag: Enable advanced encryption
#ifdef ENABLE_ENCRYPTION
    void encrypt_data(void);
#endif

// Platform: Windows-specific file handling
#ifdef _WIN32
    HANDLE open_file_win32(const char* path);
#endif
```

## Common Patterns

### **Configuration Header**
```c
// config.h
#define ENABLE_LOGGING 1
#define ENABLE_NETWORKING 0
#define DEBUG_LEVEL 2
#define MAX_CONNECTIONS 100
```

### **Build System Integration**
```c
// Typically set by build system (-DDEBUG, -DRELEASE)
#ifdef DEBUG
    // Debug-specific code
#elif defined(RELEASE)
    // Release-specific code
#else
    #error "Build type not specified"
#endif
```

## Code Example

Run the demo to see conditional compilation in action:
```bash
make run          # Standard build
make debug        # Debug build with extra features
make release      # Optimized release build
```

The demo demonstrates:
- Platform detection and adaptation
- Debug vs release build differences
- Feature flag usage and toggles
- Version-based conditional compilation
- Architecture-specific optimizations

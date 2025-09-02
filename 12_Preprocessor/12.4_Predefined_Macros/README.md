# 12.4 Predefined Macros

The C preprocessor provides several predefined macros that contain useful information about the compilation environment, source code location, and compiler features.

## Standard Predefined Macros

### **File and Line Information**
```c
__FILE__    // Current source file name (string)
__LINE__    // Current line number (integer)
__func__    // Current function name (C99, string)
```

### **Date and Time**
```c
__DATE__    // Compilation date "MMM DD YYYY"
__TIME__    // Compilation time "HH:MM:SS"
```

### **Language Standard**
```c
__STDC__           // 1 if standard C compiler
__STDC_VERSION__   // C standard version (199901L for C99)
__STDC_HOSTED__    // 1 if hosted implementation
```

## Compiler-specific Macros

### **GCC Predefined Macros**
```c
__GNUC__           // GCC major version
__GNUC_MINOR__     // GCC minor version
__GNUC_PATCHLEVEL__ // GCC patch level
__VERSION__        // Compiler version string
```

### **Clang Predefined Macros**
```c
__clang__          // Defined if using Clang
__clang_major__    // Clang major version
__clang_minor__    // Clang minor version
__clang_patchlevel__ // Clang patch level
```

### **MSVC Predefined Macros**
```c
_MSC_VER          // MSVC version number
_MSC_FULL_VER     // Full MSVC version
_WIN32            // Windows platform
_WIN64            // 64-bit Windows
```

## Platform Detection Macros

### **Operating System**
```c
_WIN32            // Windows (32-bit and 64-bit)
_WIN64            // Windows 64-bit
__linux__         // Linux
__APPLE__         // Apple platforms
__unix__          // Unix-like systems
```

### **Architecture**
```c
__x86_64__        // x86-64 architecture
__i386__          // x86 32-bit
__arm__           // ARM architecture
__aarch64__       // ARM 64-bit
```

## Debug and Optimization Macros

### **Debug Information**
```c
#ifdef DEBUG
    #define DBG_INFO() printf("File: %s, Line: %d, Function: %s\n", \
                              __FILE__, __LINE__, __func__)
#else
    #define DBG_INFO()
#endif
```

### **Assertion Macros**
```c
#define ASSERT(cond) \
    if (!(cond)) { \
        fprintf(stderr, "Assertion failed: %s at %s:%d in %s()\n", \
                #cond, __FILE__, __LINE__, __func__); \
        abort(); \
    }
```

## Utility Macros with Predefined Values

### **Build Information**
```c
#define BUILD_INFO() \
    printf("Built on %s at %s\n", __DATE__, __TIME__)

#define VERSION_INFO() \
    printf("Compiler: %s\n", __VERSION__)
```

### **Error Reporting**
```c
#define ERROR_MSG(msg) \
    fprintf(stderr, "ERROR [%s:%d]: %s\n", __FILE__, __LINE__, msg)

#define WARNING_MSG(msg) \
    fprintf(stderr, "WARNING [%s:%d]: %s\n", __FILE__, __LINE__, msg)
```

## Feature Detection

### **C Standard Features**
```c
#if __STDC_VERSION__ >= 199901L
    // C99 features available
    #define HAS_C99_FEATURES
#endif

#if __STDC_VERSION__ >= 201112L
    // C11 features available
    #define HAS_C11_FEATURES
#endif
```

### **Compiler Extensions**
```c
#ifdef __GNUC__
    #define LIKELY(x)   __builtin_expect(!!(x), 1)
    #define UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
    #define LIKELY(x)   (x)
    #define UNLIKELY(x) (x)
#endif
```

## Advanced Usage Patterns

### **Unique Identifiers**
```c
#define UNIQUE_VAR(prefix) prefix##__LINE__
#define TEMP_VAR() UNIQUE_VAR(temp_)

// Usage: int TEMP_VAR() = 42;
// Expands to: int temp_123 = 42; (where 123 is line number)
```

### **Compile-time Strings**
```c
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define LOCATION_STRING __FILE__ ":" TOSTRING(__LINE__)
#define FUNCTION_ENTRY() printf("Entering %s() at %s\n", __func__, LOCATION_STRING)
```

### **Conditional Debugging**
```c
#define DEBUG_PRINT(level, fmt, ...) \
    do { \
        if (DEBUG_LEVEL >= level) { \
            printf("[%s:%d %s()] " fmt "\n", \
                   __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
        } \
    } while(0)
```

## Practical Applications

### **Logging System**
```c
typedef enum {
    LOG_DEBUG = 1,
    LOG_INFO = 2,
    LOG_WARN = 3,
    LOG_ERROR = 4
} log_level_t;

#define LOG(level, fmt, ...) \
    log_message(level, __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
```

### **Performance Profiling**
```c
#ifdef ENABLE_PROFILING
    #define PROFILE_FUNCTION() \
        printf("PROFILE: %s() called at %s:%d\n", __func__, __FILE__, __LINE__)
#else
    #define PROFILE_FUNCTION()
#endif
```

### **Memory Debugging**
```c
#ifdef DEBUG_MEMORY
    #define MALLOC_DEBUG(size) \
        debug_malloc(size, __FILE__, __LINE__, __func__)
    #define FREE_DEBUG(ptr) \
        debug_free(ptr, __FILE__, __LINE__, __func__)
#else
    #define MALLOC_DEBUG(size) malloc(size)
    #define FREE_DEBUG(ptr) free(ptr)
#endif
```

## Best Practices

### **Consistent Naming**
```c
// Use consistent prefixes for related macros
#define APP_VERSION_MAJOR 1
#define APP_VERSION_MINOR 0
#define APP_BUILD_DATE __DATE__
#define APP_BUILD_TIME __TIME__
```

### **Safe Macro Definitions**
```c
// Always wrap multi-token replacements in parentheses
#define CURRENT_LOCATION (__FILE__ ":" TOSTRING(__LINE__))

// Use do-while(0) for multi-statement macros
#define TRACE_FUNCTION() do { \
    printf("TRACE: %s() at %s:%d\n", __func__, __FILE__, __LINE__); \
} while(0)
```

### **Documentation**
```c
/**
 * DEBUG_ASSERT - Debug-only assertion macro
 * @cond: Condition to check
 * 
 * Only active in debug builds. Prints file, line, and function
 * information when assertion fails.
 */
#ifdef DEBUG
    #define DEBUG_ASSERT(cond) ASSERT(cond)
#else
    #define DEBUG_ASSERT(cond)
#endif
```

## Common Use Cases

### **Error Context**
```c
#define CONTEXT_ERROR(msg) \
    fprintf(stderr, "Error in %s() at %s:%d: %s\n", \
            __func__, __FILE__, __LINE__, msg)
```

### **Build Timestamps**
```c
#define PRINT_BUILD_INFO() \
    printf("Built: %s %s\n", __DATE__, __TIME__)
```

### **Function Tracing**
```c
#ifdef TRACE_CALLS
    #define TRACE_ENTER() printf("-> %s()\n", __func__)
    #define TRACE_EXIT() printf("<- %s()\n", __func__)
#else
    #define TRACE_ENTER()
    #define TRACE_EXIT()
#endif
```

## Code Example

Run the demo to see predefined macros in action:
```bash
make run
```

The demo demonstrates:
- Standard predefined macro values
- Compiler and platform detection
- File and line information usage
- Date and time compilation stamps
- Practical debugging applications
- Error reporting with context information

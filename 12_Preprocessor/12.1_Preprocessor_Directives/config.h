#ifndef CONFIG_H
#define CONFIG_H

/* Configuration header for preprocessor demo */

/* Version information */
#define VERSION_MAJOR 1
#define VERSION_MINOR 2
#define VERSION_PATCH 0

/* Feature flags */
#define ENABLE_LOGGING 1
#define ENABLE_DEBUG 1
#define MAX_BUFFER_SIZE 1024

/* Platform-specific settings */
#ifdef _WIN32
    #define PLATFORM_NAME "Windows"
    #define PATH_SEPARATOR '\\'
#elif defined(__linux__)
    #define PLATFORM_NAME "Linux"
    #define PATH_SEPARATOR '/'
#elif defined(__APPLE__)
    #define PLATFORM_NAME "macOS"
    #define PATH_SEPARATOR '/'
#else
    #define PLATFORM_NAME "Unknown"
    #define PATH_SEPARATOR '/'
#endif

/* Utility macros */
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define VERSION_STRING TOSTRING(VERSION_MAJOR) "." TOSTRING(VERSION_MINOR) "." TOSTRING(VERSION_PATCH)

/* Function-like macros */
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))

/* Debug macros */
#if ENABLE_DEBUG
    #define DEBUG_PRINT(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...)
#endif

/* Logging macros */
#if ENABLE_LOGGING
    #define LOG_INFO(msg) printf("[INFO] %s\n", msg)
    #define LOG_ERROR(msg) fprintf(stderr, "[ERROR] %s\n", msg)
#else
    #define LOG_INFO(msg)
    #define LOG_ERROR(msg)
#endif

#endif /* CONFIG_H */

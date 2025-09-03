#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

static FILE* log_file = NULL;
static const char* level_names[] = {"DEBUG", "INFO", "WARN", "ERROR"};

void logger_init(const char* filename) {
    if (filename) {
        log_file = fopen(filename, "w");
        if (!log_file) {
            fprintf(stderr, "Warning: Could not open log file %s\n", filename);
        }
    }
}

void logger_cleanup(void) {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}

void logger_log(LogLevel level, const char* format, ...) {
    if (level < LOG_LEVEL_DEBUG || level > LOG_LEVEL_ERROR) {
        return;
    }
    
    // Get current time
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    char timestamp[64];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);
    
    // Format the message
    va_list args;
    va_start(args, format);
    
    char message[1024];
    vsnprintf(message, sizeof(message), format, args);
    
    va_end(args);
    
    // Write to log file if available
    if (log_file) {
        fprintf(log_file, "[%s] %s: %s\n", timestamp, level_names[level], message);
        fflush(log_file);
    }
    
    // Also write to console for INFO and above
    if (level >= LOG_LEVEL_INFO) {
        printf("[%s] %s: %s\n", timestamp, level_names[level], message);
    }
}

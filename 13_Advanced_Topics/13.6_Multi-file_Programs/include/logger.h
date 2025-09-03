#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
} LogLevel;

// Logger functions
void logger_init(const char* filename);
void logger_cleanup(void);
void logger_log(LogLevel level, const char* format, ...);

// Convenience macros
#define LOG_DEBUG(fmt, ...) logger_log(LOG_LEVEL_DEBUG, fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...)  logger_log(LOG_LEVEL_INFO, fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)  logger_log(LOG_LEVEL_WARNING, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) logger_log(LOG_LEVEL_ERROR, fmt, ##__VA_ARGS__)

#endif /* LOGGER_H */

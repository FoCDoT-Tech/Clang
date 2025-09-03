#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>
#include <stdbool.h>

// Dynamic string structure
typedef struct {
    char* data;
    size_t length;
    size_t capacity;
} StrUtils_String;

// Constructor/Destructor
StrUtils_String* strutils_create(const char* initial);
void strutils_destroy(StrUtils_String* str);

// String operations
bool strutils_append(StrUtils_String* str, const char* text);
bool strutils_prepend(StrUtils_String* str, const char* text);
char* strutils_to_cstring(const StrUtils_String* str);
size_t strutils_length(const StrUtils_String* str);
size_t strutils_capacity(const StrUtils_String* str);
void strutils_clear(StrUtils_String* str);
bool strutils_resize(StrUtils_String* str, size_t new_capacity);

#endif /* STRING_UTILS_H */

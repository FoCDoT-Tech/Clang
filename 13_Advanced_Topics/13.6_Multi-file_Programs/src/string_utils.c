#include "string_utils.h"
#include <stdlib.h>
#include <string.h>

StrUtils_String* strutils_create(const char* initial) {
    StrUtils_String* str = malloc(sizeof(StrUtils_String));
    if (!str) return NULL;
    
    size_t initial_len = initial ? strlen(initial) : 0;
    size_t initial_capacity = initial_len > 16 ? initial_len * 2 : 16;
    
    str->data = malloc(initial_capacity);
    if (!str->data) {
        free(str);
        return NULL;
    }
    
    if (initial) {
        strcpy(str->data, initial);
        str->length = initial_len;
    } else {
        str->data[0] = '\0';
        str->length = 0;
    }
    
    str->capacity = initial_capacity;
    return str;
}

void strutils_destroy(StrUtils_String* str) {
    if (str) {
        free(str->data);
        free(str);
    }
}

bool strutils_resize(StrUtils_String* str, size_t new_capacity) {
    if (!str || new_capacity <= str->length) return false;
    
    char* new_data = realloc(str->data, new_capacity);
    if (!new_data) return false;
    
    str->data = new_data;
    str->capacity = new_capacity;
    return true;
}

bool strutils_append(StrUtils_String* str, const char* text) {
    if (!str || !text) return false;
    
    size_t text_len = strlen(text);
    size_t new_length = str->length + text_len;
    
    if (new_length + 1 > str->capacity) {
        size_t new_capacity = (new_length + 1) * 2;
        if (!strutils_resize(str, new_capacity)) {
            return false;
        }
    }
    
    strcat(str->data, text);
    str->length = new_length;
    return true;
}

bool strutils_prepend(StrUtils_String* str, const char* text) {
    if (!str || !text) return false;
    
    size_t text_len = strlen(text);
    size_t new_length = str->length + text_len;
    
    if (new_length + 1 > str->capacity) {
        size_t new_capacity = (new_length + 1) * 2;
        if (!strutils_resize(str, new_capacity)) {
            return false;
        }
    }
    
    // Move existing content to make room
    memmove(str->data + text_len, str->data, str->length + 1);
    
    // Copy new text to beginning
    memcpy(str->data, text, text_len);
    
    str->length = new_length;
    return true;
}

char* strutils_to_cstring(const StrUtils_String* str) {
    return str ? str->data : NULL;
}

size_t strutils_length(const StrUtils_String* str) {
    return str ? str->length : 0;
}

size_t strutils_capacity(const StrUtils_String* str) {
    return str ? str->capacity : 0;
}

void strutils_clear(StrUtils_String* str) {
    if (str) {
        str->data[0] = '\0';
        str->length = 0;
    }
}

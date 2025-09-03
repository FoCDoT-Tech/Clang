#include "vector.h"
#include <stdlib.h>
#include <string.h>

struct Vector {
    int* data;
    size_t size;
    size_t capacity;
};

Vector* vector_create(size_t initial_capacity) {
    Vector* vec = malloc(sizeof(Vector));
    if (!vec) return NULL;
    
    if (initial_capacity == 0) initial_capacity = 1;
    
    vec->data = malloc(initial_capacity * sizeof(int));
    if (!vec->data) {
        free(vec);
        return NULL;
    }
    
    vec->size = 0;
    vec->capacity = initial_capacity;
    return vec;
}

void vector_destroy(Vector* vec) {
    if (vec) {
        free(vec->data);
        free(vec);
    }
}

void vector_push(Vector* vec, int value) {
    if (!vec) return;
    
    if (vec->size >= vec->capacity) {
        size_t new_capacity = vec->capacity * 2;
        int* new_data = realloc(vec->data, new_capacity * sizeof(int));
        if (!new_data) return;
        
        vec->data = new_data;
        vec->capacity = new_capacity;
    }
    
    vec->data[vec->size++] = value;
}

int vector_pop(Vector* vec) {
    if (!vec || vec->size == 0) return 0;
    
    return vec->data[--vec->size];
}

int vector_get(const Vector* vec, size_t index) {
    if (!vec || index >= vec->size) return 0;
    
    return vec->data[index];
}

void vector_set(Vector* vec, size_t index, int value) {
    if (!vec || index >= vec->size) return;
    
    vec->data[index] = value;
}

size_t vector_size(const Vector* vec) {
    return vec ? vec->size : 0;
}

size_t vector_capacity(const Vector* vec) {
    return vec ? vec->capacity : 0;
}

void vector_clear(Vector* vec) {
    if (vec) {
        vec->size = 0;
    }
}

void vector_resize(Vector* vec, size_t new_capacity) {
    if (!vec || new_capacity == 0) return;
    
    int* new_data = realloc(vec->data, new_capacity * sizeof(int));
    if (!new_data) return;
    
    vec->data = new_data;
    vec->capacity = new_capacity;
    
    if (vec->size > new_capacity) {
        vec->size = new_capacity;
    }
}

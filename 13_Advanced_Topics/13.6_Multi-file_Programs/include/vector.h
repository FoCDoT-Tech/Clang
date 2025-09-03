#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

// Opaque structure - implementation hidden
typedef struct Vector Vector;

// Constructor/Destructor
Vector* vector_create(size_t initial_capacity);
void vector_destroy(Vector* vec);

// Element operations
void vector_push(Vector* vec, int value);
int vector_pop(Vector* vec);
int vector_get(const Vector* vec, size_t index);
void vector_set(Vector* vec, size_t index, int value);

// Size operations
size_t vector_size(const Vector* vec);
size_t vector_capacity(const Vector* vec);
void vector_clear(Vector* vec);
void vector_resize(Vector* vec, size_t new_capacity);

#endif /* VECTOR_H */

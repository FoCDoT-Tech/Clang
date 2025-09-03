# 13.6 Multi-file Programs

Organizing large C programs across multiple source files with proper modularization, header files, and build systems.

## Project Structure

### **Typical Multi-file Layout**
```
project/
├── src/
│   ├── main.c          # Main program entry point
│   ├── module1.c       # Implementation file 1
│   ├── module2.c       # Implementation file 2
│   └── utils.c         # Utility functions
├── include/
│   ├── module1.h       # Header file 1
│   ├── module2.h       # Header file 2
│   └── utils.h         # Utility headers
├── lib/                # Static/dynamic libraries
├── tests/              # Test files
├── docs/               # Documentation
├── Makefile           # Build configuration
└── README.md          # Project documentation
```

### **Header Files (.h)**
```c
// math_utils.h
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

// Function declarations
double calculate_area(double radius);
double calculate_volume(double radius, double height);
int factorial(int n);

// Constants
#define PI 3.14159265359

// Type definitions
typedef struct {
    double x, y;
} Point2D;

typedef struct {
    double x, y, z;
} Point3D;

#endif /* MATH_UTILS_H */
```

### **Implementation Files (.c)**
```c
// math_utils.c
#include "math_utils.h"
#include <math.h>

double calculate_area(double radius) {
    return PI * radius * radius;
}

double calculate_volume(double radius, double height) {
    return calculate_area(radius) * height;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

## Header File Best Practices

### **Include Guards**
```c
// Method 1: Traditional include guards
#ifndef MYHEADER_H
#define MYHEADER_H

// Header content here

#endif /* MYHEADER_H */

// Method 2: Pragma once (compiler-specific but widely supported)
#pragma once

// Header content here
```

### **Forward Declarations**
```c
// geometry.h
#ifndef GEOMETRY_H
#define GEOMETRY_H

// Forward declarations to avoid circular dependencies
typedef struct Rectangle Rectangle;
typedef struct Circle Circle;

// Function declarations
Rectangle* create_rectangle(double width, double height);
Circle* create_circle(double radius);
double get_area(const void* shape, int shape_type);

#endif /* GEOMETRY_H */
```

### **Conditional Compilation**
```c
// config.h
#ifndef CONFIG_H
#define CONFIG_H

// Platform-specific includes
#ifdef _WIN32
    #include <windows.h>
    #define PLATFORM_WINDOWS
#elif defined(__linux__)
    #include <unistd.h>
    #define PLATFORM_LINUX
#elif defined(__APPLE__)
    #include <unistd.h>
    #define PLATFORM_MACOS
#endif

// Feature flags
#define ENABLE_LOGGING 1
#define ENABLE_DEBUG 0

// Configuration constants
#define MAX_BUFFER_SIZE 1024
#define DEFAULT_TIMEOUT 30

#endif /* CONFIG_H */
```

## Module Design Patterns

### **Object-Oriented Style in C**
```c
// vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct Vector Vector;

// Constructor/Destructor
Vector* vector_create(size_t initial_capacity);
void vector_destroy(Vector* vec);

// Methods
void vector_push(Vector* vec, int value);
int vector_pop(Vector* vec);
int vector_get(const Vector* vec, size_t index);
void vector_set(Vector* vec, size_t index, int value);
size_t vector_size(const Vector* vec);
size_t vector_capacity(const Vector* vec);

#endif /* VECTOR_H */
```

```c
// vector.c
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

// ... other implementations
```

### **Namespace Simulation**
```c
// string_utils.h
#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>
#include <stdbool.h>

// Namespace-like prefix for all functions
typedef struct {
    char* data;
    size_t length;
    size_t capacity;
} StrUtils_String;

// String operations
StrUtils_String* strutils_create(const char* initial);
void strutils_destroy(StrUtils_String* str);
bool strutils_append(StrUtils_String* str, const char* text);
bool strutils_prepend(StrUtils_String* str, const char* text);
char* strutils_to_cstring(const StrUtils_String* str);
size_t strutils_length(const StrUtils_String* str);

#endif /* STRING_UTILS_H */
```

## Static vs Dynamic Linking

### **Static Libraries (.a files)**
```bash
# Create object files
gcc -c math_utils.c -o math_utils.o
gcc -c string_utils.c -o string_utils.o

# Create static library
ar rcs libmyutils.a math_utils.o string_utils.o

# Link with static library
gcc main.c -L. -lmyutils -o program
```

### **Dynamic Libraries (.so/.dll files)**
```bash
# Create shared library (Linux/macOS)
gcc -shared -fPIC math_utils.c string_utils.c -o libmyutils.so

# Create shared library (Windows)
gcc -shared math_utils.c string_utils.c -o libmyutils.dll

# Link with dynamic library
gcc main.c -L. -lmyutils -o program

# Set library path (Linux/macOS)
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
```

## Build Systems

### **Advanced Makefile**
```makefile
# Project configuration
PROJECT_NAME = myproject
VERSION = 1.0.0

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
LIBDIR = lib
TESTDIR = tests

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g -I$(INCDIR)
LDFLAGS = -L$(LIBDIR)
LIBS = -lm

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/$(PROJECT_NAME)

# Library files
LIB_SOURCES = $(filter-out $(SRCDIR)/main.c, $(SOURCES))
LIB_OBJECTS = $(LIB_SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
STATIC_LIB = $(LIBDIR)/lib$(PROJECT_NAME).a
SHARED_LIB = $(LIBDIR)/lib$(PROJECT_NAME).so

# Test files
TEST_SOURCES = $(wildcard $(TESTDIR)/*.c)
TEST_OBJECTS = $(TEST_SOURCES:$(TESTDIR)/%.c=$(OBJDIR)/test_%.o)
TEST_TARGETS = $(TEST_SOURCES:$(TESTDIR)/%.c=$(BINDIR)/test_%)

.PHONY: all clean install uninstall test help

# Default target
all: directories $(TARGET)

# Create directories
directories:
	@mkdir -p $(OBJDIR) $(BINDIR) $(LIBDIR)

# Main executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) $(LIBS)

# Object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Static library
$(STATIC_LIB): $(LIB_OBJECTS)
	ar rcs $@ $^

# Shared library
$(SHARED_LIB): $(LIB_OBJECTS)
	$(CC) -shared -fPIC $^ -o $@ $(LIBS)

# Test object files
$(OBJDIR)/test_%.o: $(TESTDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Test executables
$(BINDIR)/test_%: $(OBJDIR)/test_%.o $(LIB_OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS) $(LIBS)

# Build and run tests
test: $(TEST_TARGETS)
	@for test in $(TEST_TARGETS); do \
		echo "Running $$test..."; \
		./$$test || exit 1; \
	done

# Libraries
libs: $(STATIC_LIB) $(SHARED_LIB)

# Install
install: $(TARGET)
	install -d /usr/local/bin
	install $(TARGET) /usr/local/bin/

# Uninstall
uninstall:
	rm -f /usr/local/bin/$(PROJECT_NAME)

# Clean
clean:
	rm -rf $(OBJDIR) $(BINDIR) $(LIBDIR)

# Help
help:
	@echo "Available targets:"
	@echo "  all       - Build the main executable"
	@echo "  libs      - Build static and shared libraries"
	@echo "  test      - Build and run tests"
	@echo "  install   - Install to system"
	@echo "  uninstall - Remove from system"
	@echo "  clean     - Remove build artifacts"
	@echo "  help      - Show this help"

# Dependencies
-include $(OBJECTS:.o=.d)

# Generate dependency files
$(OBJDIR)/%.d: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -MM -MT $(@:.d=.o) $< > $@
```

### **CMake Configuration**
```cmake
# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.c")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c")

# Library
add_library(myproject_lib STATIC ${SOURCES})

# Executable
add_executable(myproject src/main.c)
target_link_libraries(myproject myproject_lib m)

# Tests
enable_testing()
file(GLOB TEST_SOURCES "tests/*.c")
foreach(test_source ${TEST_SOURCES})
    get_filename_component(test_name ${test_source} NAME_WE)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} myproject_lib m)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()

# Installation
install(TARGETS myproject DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
```

## Dependency Management

### **Header Dependencies**
```c
// logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <time.h>

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
} LogLevel;

void logger_init(const char* filename);
void logger_cleanup(void);
void logger_log(LogLevel level, const char* format, ...);

#define LOG_DEBUG(fmt, ...) logger_log(LOG_LEVEL_DEBUG, fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...)  logger_log(LOG_LEVEL_INFO, fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)  logger_log(LOG_LEVEL_WARNING, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) logger_log(LOG_LEVEL_ERROR, fmt, ##__VA_ARGS__)

#endif /* LOGGER_H */
```

### **Circular Dependency Resolution**
```c
// Forward declarations in separate header
// forward_decls.h
#ifndef FORWARD_DECLS_H
#define FORWARD_DECLS_H

typedef struct Node Node;
typedef struct Graph Graph;
typedef struct Database Database;

#endif /* FORWARD_DECLS_H */

// node.h
#ifndef NODE_H
#define NODE_H

#include "forward_decls.h"

struct Node {
    int data;
    Node* next;
    Graph* parent_graph;  // Forward declaration used
};

Node* node_create(int data);
void node_destroy(Node* node);

#endif /* NODE_H */
```

## Testing Framework

### **Simple Unit Testing**
```c
// test_framework.h
#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>
#include <stdlib.h>

#define TEST_ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            printf("FAIL: %s - %s\n", __func__, message); \
            return 0; \
        } \
    } while(0)

#define TEST_ASSERT_EQ(expected, actual, message) \
    TEST_ASSERT((expected) == (actual), message)

#define RUN_TEST(test_func) \
    do { \
        printf("Running %s... ", #test_func); \
        if (test_func()) { \
            printf("PASS\n"); \
            tests_passed++; \
        } else { \
            tests_failed++; \
        } \
        tests_total++; \
    } while(0)

extern int tests_total;
extern int tests_passed;
extern int tests_failed;

#endif /* TEST_FRAMEWORK_H */
```

```c
// test_math_utils.c
#include "test_framework.h"
#include "math_utils.h"

int tests_total = 0;
int tests_passed = 0;
int tests_failed = 0;

int test_calculate_area(void) {
    double result = calculate_area(5.0);
    TEST_ASSERT(result > 78.5 && result < 78.6, "Area calculation incorrect");
    return 1;
}

int test_factorial(void) {
    TEST_ASSERT_EQ(1, factorial(0), "factorial(0) should be 1");
    TEST_ASSERT_EQ(1, factorial(1), "factorial(1) should be 1");
    TEST_ASSERT_EQ(24, factorial(4), "factorial(4) should be 24");
    return 1;
}

int main(void) {
    printf("Running Math Utils Tests\n");
    printf("========================\n");
    
    RUN_TEST(test_calculate_area);
    RUN_TEST(test_factorial);
    
    printf("\nResults: %d/%d tests passed, %d failed\n", 
           tests_passed, tests_total, tests_failed);
    
    return tests_failed == 0 ? 0 : 1;
}
```

## Documentation and Code Organization

### **Doxygen Documentation**
```c
/**
 * @file math_utils.h
 * @brief Mathematical utility functions
 * @author Your Name
 * @date 2024
 * @version 1.0
 */

#ifndef MATH_UTILS_H
#define MATH_UTILS_H

/**
 * @brief Calculate the area of a circle
 * @param radius The radius of the circle
 * @return The area of the circle
 * @pre radius >= 0
 * @post return value >= 0
 */
double calculate_area(double radius);

/**
 * @brief Calculate factorial of a number
 * @param n The number to calculate factorial for
 * @return The factorial of n
 * @pre n >= 0
 * @warning Large values of n may cause integer overflow
 */
int factorial(int n);

#endif /* MATH_UTILS_H */
```

### **Code Style Guidelines**
```c
// coding_style.h
#ifndef CODING_STYLE_H
#define CODING_STYLE_H

// Naming conventions:
// - Functions: snake_case
// - Variables: snake_case
// - Constants: UPPER_CASE
// - Types: PascalCase or snake_case_t

// File organization:
// 1. Copyright/license header
// 2. Include guard
// 3. System includes
// 4. Local includes
// 5. Constants and macros
// 6. Type definitions
// 7. Function declarations
// 8. Inline functions (if any)

#include <stdio.h>      // System includes first
#include <stdlib.h>
#include <string.h>

#include "local_header.h"  // Local includes after

#define MAX_SIZE 1024      // Constants
#define PI 3.14159265359

typedef struct Point {     // Type definitions
    double x, y;
} Point;

// Function declarations with clear documentation
int process_data(const char* input, char* output, size_t max_size);

#endif /* CODING_STYLE_H */
```

## Performance and Optimization

### **Link-Time Optimization**
```makefile
# Enable LTO in Makefile
CFLAGS += -flto
LDFLAGS += -flto

# Profile-guided optimization
profile: CFLAGS += -fprofile-generate
profile: $(TARGET)

optimize: CFLAGS += -fprofile-use -O3
optimize: $(TARGET)
```

### **Modular Compilation**
```c
// Fast compilation with precompiled headers
// pch.h (precompiled header)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Common project headers
#include "common_types.h"
#include "constants.h"
```

## Code Example

The demo creates a complete multi-file program structure:
```bash
make run
```

The demo demonstrates:
- Proper header file organization
- Module separation and interfaces
- Static and shared library creation
- Advanced Makefile with dependencies
- Unit testing framework
- Documentation standards
- Build system integration

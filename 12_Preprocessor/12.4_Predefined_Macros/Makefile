# Makefile for Predefined Macros Demo

# Compiler and flags
CC = gcc
BASE_CFLAGS = -Wall -Wextra -std=c99 -pedantic
TARGET = predefined_macros_demo
SOURCE = predefined_macros_demo.c

# Default build
all: $(TARGET)

# Standard build
$(TARGET): $(SOURCE)
	$(CC) $(BASE_CFLAGS) -o $(TARGET) $(SOURCE)

# Debug build with tracing
debug: $(SOURCE)
	$(CC) $(BASE_CFLAGS) -DDEBUG -DENABLE_TRACING -o $(TARGET)_debug $(SOURCE)

# Release build
release: $(SOURCE)
	$(CC) $(BASE_CFLAGS) -O3 -DNDEBUG -o $(TARGET)_release $(SOURCE)

# Run standard build
run: $(TARGET)
	./$(TARGET)

# Run debug build
run-debug: debug
	./$(TARGET)_debug

# Run release build
run-release: release
	./$(TARGET)_release

# Show all predefined macros
show-macros:
	$(CC) -dM -E - < /dev/null | sort

# Show C standard macros only
show-std-macros:
	$(CC) -dM -E - < /dev/null | grep -E "^#define __STDC|^#define __DATE__|^#define __TIME__|^#define __FILE__|^#define __LINE__" | sort

# Show compiler-specific macros
show-compiler-macros:
	$(CC) -dM -E - < /dev/null | grep -E "^#define __GNUC|^#define __clang|^#define _MSC" | sort

# Show platform macros
show-platform-macros:
	$(CC) -dM -E - < /dev/null | grep -E "^#define __linux__|^#define __APPLE__|^#define _WIN32|^#define __x86_64__|^#define __i386__|^#define __arm" | sort

# Clean up generated files
clean:
	rm -f $(TARGET) $(TARGET)_debug $(TARGET)_release

# Help target
help:
	@echo "Available targets:"
	@echo "  all               - Build standard version (default)"
	@echo "  debug             - Build debug version with tracing"
	@echo "  release           - Build optimized release version"
	@echo "  run               - Build and run standard version"
	@echo "  run-debug         - Build and run debug version"
	@echo "  run-release       - Build and run release version"
	@echo "  show-macros       - Show all predefined macros"
	@echo "  show-std-macros   - Show C standard macros only"
	@echo "  show-compiler-macros - Show compiler-specific macros"
	@echo "  show-platform-macros - Show platform-specific macros"
	@echo "  clean             - Remove generated files"
	@echo "  help              - Show this help message"

# Phony targets
.PHONY: all debug release run run-debug run-release show-macros show-std-macros show-compiler-macros show-platform-macros clean help

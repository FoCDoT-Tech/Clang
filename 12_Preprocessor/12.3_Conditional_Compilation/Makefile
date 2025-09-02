# Makefile for Conditional Compilation Demo

# Compiler and flags
CC = gcc
BASE_CFLAGS = -Wall -Wextra -std=c99 -pedantic
TARGET = conditional_compilation_demo
SOURCE = conditional_compilation_demo.c

# Default build (standard)
all: $(TARGET)

# Standard build
$(TARGET): $(SOURCE)
	$(CC) $(BASE_CFLAGS) -o $(TARGET) $(SOURCE)

# Debug build with extra features
debug: $(SOURCE)
	$(CC) $(BASE_CFLAGS) -DDEBUG_BUILD -DDEBUG_LEVEL=3 -DFEATURE_LOGGING=1 -DFEATURE_ENCRYPTION=1 -o $(TARGET)_debug $(SOURCE)

# Release build with optimizations
release: $(SOURCE)
	$(CC) $(BASE_CFLAGS) -O3 -DRELEASE_BUILD -DDEBUG_LEVEL=0 -DFEATURE_LOGGING=0 -o $(TARGET)_release $(SOURCE)

# Minimal build (embedded-like)
minimal: $(SOURCE)
	$(CC) $(BASE_CFLAGS) -DEMBEDDED_SYSTEM -DDEBUG_LEVEL=0 -DFEATURE_LOGGING=0 -DFEATURE_NETWORKING=0 -DFEATURE_ENCRYPTION=0 -o $(TARGET)_minimal $(SOURCE)

# Full features build
full: $(SOURCE)
	$(CC) $(BASE_CFLAGS) -DFULL_FEATURES -DDEBUG_LEVEL=2 -DFEATURE_LOGGING=1 -DFEATURE_NETWORKING=1 -DFEATURE_ENCRYPTION=1 -o $(TARGET)_full $(SOURCE)

# Run standard build
run: $(TARGET)
	./$(TARGET)

# Run debug build
run-debug: debug
	./$(TARGET)_debug

# Run release build
run-release: release
	./$(TARGET)_release

# Run minimal build
run-minimal: minimal
	./$(TARGET)_minimal

# Run full features build
run-full: full
	./$(TARGET)_full

# Show preprocessor output
preprocess: $(SOURCE)
	$(CC) -E $(BASE_CFLAGS) -DDEBUG_LEVEL=2 -DFEATURE_LOGGING=1 $(SOURCE) > preprocessed.i
	@echo "Preprocessor output saved to preprocessed.i"

# Clean up generated files
clean:
	rm -f $(TARGET) $(TARGET)_debug $(TARGET)_release $(TARGET)_minimal $(TARGET)_full preprocessed.i

# Help target
help:
	@echo "Available targets:"
	@echo "  all         - Build standard version (default)"
	@echo "  debug       - Build debug version with extra features"
	@echo "  release     - Build optimized release version"
	@echo "  minimal     - Build minimal version (embedded-like)"
	@echo "  full        - Build with all features enabled"
	@echo "  run         - Build and run standard version"
	@echo "  run-debug   - Build and run debug version"
	@echo "  run-release - Build and run release version"
	@echo "  run-minimal - Build and run minimal version"
	@echo "  run-full    - Build and run full features version"
	@echo "  preprocess  - Show preprocessor output"
	@echo "  clean       - Remove generated files"
	@echo "  help        - Show this help message"

# Phony targets
.PHONY: all debug release minimal full run run-debug run-release run-minimal run-full preprocess clean help

# Makefile for 15.1 Debugging Techniques Demo

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g
DEBUG_CFLAGS = -Wall -Wextra -std=c99 -pedantic -g -DDEBUG
TARGET = debugging_techniques_demo
DEBUG_TARGET = debugging_techniques_demo_debug
SOURCE = debugging_techniques_demo.c

# Default target
all: build

# Build the program (normal version)
build: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Build debug version with DEBUG macro enabled
debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(SOURCE)
	$(CC) $(DEBUG_CFLAGS) -o $(DEBUG_TARGET) $(SOURCE)

# Run the program
run: $(TARGET)
	@echo "Running Debugging Techniques Demo..."
	@echo "==================================="
	./$(TARGET)

# Run debug version
run-debug: $(DEBUG_TARGET)
	@echo "Running Debugging Techniques Demo (Debug Version)..."
	@echo "=================================================="
	./$(DEBUG_TARGET)

# Test the program (same as run for demos)
test: run

# Clean build artifacts
clean:
	rm -f $(TARGET) $(DEBUG_TARGET)
	@echo "Cleaned build artifacts"

# Help
help:
	@echo "Available targets:"
	@echo "  build      - Compile the program"
	@echo "  debug      - Compile with debug output enabled"
	@echo "  run        - Run the program"
	@echo "  run-debug  - Run the debug version"
	@echo "  test       - Test the program"
	@echo "  clean      - Remove build artifacts"
	@echo "  help       - Show this help"

.PHONY: all build debug run run-debug test clean help

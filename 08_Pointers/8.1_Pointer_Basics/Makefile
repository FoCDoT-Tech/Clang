# Makefile for Pointer Basics Demo
# Chapter 8.1: Pointer Basics

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = pointer_basics_demo
SOURCE = pointer_basics_demo.c

# Default target
all: $(TARGET)

# Compile the demo
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Run the demo
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Compile the pointer basics demo"
	@echo "  run     - Compile and run the demo"
	@echo "  clean   - Remove generated files"
	@echo "  help    - Show this help message"

# Phony targets
.PHONY: all run clean help

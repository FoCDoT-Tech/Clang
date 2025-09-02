# Makefile for Pointers and Functions Demo
# Chapter 8.4: Pointers and Functions

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = pointers_functions_demo
SOURCE = pointers_functions_demo.c

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
	@echo "  all     - Compile the pointers and functions demo"
	@echo "  run     - Compile and run the demo"
	@echo "  clean   - Remove generated files"
	@echo "  help    - Show this help message"

# Phony targets
.PHONY: all run clean help

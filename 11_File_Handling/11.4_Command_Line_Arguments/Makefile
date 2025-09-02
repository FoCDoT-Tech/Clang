# Makefile for Command Line Arguments Demo

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
TARGET = command_line_demo
SOURCE = command_line_demo.c

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Run the program with no arguments
run: $(TARGET)
	./$(TARGET)

# Run with sample arguments
test: $(TARGET)
	@echo "Testing with various command line arguments:"
	@echo "1. No arguments:"
	./$(TARGET)
	@echo "\n2. With files and flags:"
	./$(TARGET) sample1.txt -v --output result.txt
	@echo "\n3. With combined options:"
	./$(TARGET) -abc --host=localhost --port=9000
	@echo "\n4. Help flag:"
	./$(TARGET) --help

# Clean up generated files
clean:
	rm -f $(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  run     - Build and run the program with no arguments"
	@echo "  test    - Build and run with various test arguments"
	@echo "  clean   - Remove generated files"
	@echo "  help    - Show this help message"

# Phony targets
.PHONY: all run test clean help

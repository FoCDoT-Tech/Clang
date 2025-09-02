# Makefile for Function Types Demo

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -lm
TARGET = function_types_demo
SOURCE = function_types_demo.c

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all     - Build the function types demo"
	@echo "  run     - Build and run the demo"
	@echo "  clean   - Remove generated files"
	@echo "  help    - Show this help message"

# Declare phony targets
.PHONY: all run clean help

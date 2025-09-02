# Makefile for Program Structure examples

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = program_structure_demo
SOURCE = program_structure_demo.c

# Default target
all: $(TARGET)

# Compile the program structure demo
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)
	@echo "✓ Program structure demo compiled successfully!"
	@echo "Run with: ./$(TARGET)"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run with command line arguments to demonstrate argc/argv
run-with-args: $(TARGET)
	./$(TARGET) hello world 123

# Clean up generated files
clean:
	rm -f $(TARGET)
	@echo "✓ Cleaned up executable files"

# Help target
help:
	@echo "Available targets:"
	@echo "  all           - Compile the program (default)"
	@echo "  run           - Compile and run the program"
	@echo "  run-with-args - Run with command line arguments"
	@echo "  clean         - Remove executable files"
	@echo "  help          - Show this help message"

.PHONY: all run run-with-args clean help

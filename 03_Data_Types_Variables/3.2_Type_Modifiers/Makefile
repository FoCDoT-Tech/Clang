# Makefile for Type Modifiers examples

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = type_modifiers_demo
SOURCE = type_modifiers_demo.c

# Default target
all: $(TARGET)

# Compile the type modifiers demo
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)
	@echo "✓ Type modifiers demo compiled successfully!"
	@echo "Run with: ./$(TARGET)"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)
	@echo "✓ Cleaned up executable files"

# Help target
help:
	@echo "Available targets:"
	@echo "  all    - Compile the program (default)"
	@echo "  run    - Compile and run the program"
	@echo "  clean  - Remove executable files"
	@echo "  help   - Show this help message"

.PHONY: all run clean help

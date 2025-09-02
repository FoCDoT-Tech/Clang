# Makefile for Other Operators demo

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = other_operators_demo
SOURCE = other_operators_demo.c

# Default target
all: $(TARGET)

# Compile the other operators demo program
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)
	@echo "✓ Other operators demo compiled successfully!"
	@echo "Run with: ./$(TARGET)"

# Run the program after compilation
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

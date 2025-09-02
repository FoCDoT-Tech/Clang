# Makefile for Development Environment examples
# Shows how to automate compilation process

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = setup_check
SOURCE = setup_check.c

# Default target
all: $(TARGET)

# Compile the setup check program
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)
	@echo "✓ Compilation successful!"
	@echo "Run with: ./$(TARGET)"

# Run the program after compilation
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)
	@echo "✓ Cleaned up executable files"

# Show compiler version
compiler-info:
	@echo "Compiler Information:"
	@$(CC) --version

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Compile the program (default)"
	@echo "  run          - Compile and run the program"
	@echo "  clean        - Remove executable files"
	@echo "  compiler-info - Show compiler version"
	@echo "  help         - Show this help message"

# Prevent make from treating these as file targets
.PHONY: all run clean compiler-info help

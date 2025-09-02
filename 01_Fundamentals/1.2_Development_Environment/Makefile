# Makefile for Development Environment examples
# Shows how to automate compilation process

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = setup_check
SOURCE = setup_check.c
EXPLORER_TARGET = stdlib_explorer
EXPLORER_SOURCE = stdlib_explorer.c

# Default target
all: $(TARGET) $(EXPLORER_TARGET)

# Compile the setup check program
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)
	@echo "✓ Setup check compilation successful!"
	@echo "Run with: ./$(TARGET)"

# Compile the stdlib explorer program
$(EXPLORER_TARGET): $(EXPLORER_SOURCE)
	$(CC) $(CFLAGS) $(EXPLORER_SOURCE) -o $(EXPLORER_TARGET)
	@echo "✓ Stdlib explorer compilation successful!"
	@echo "Run with: ./$(EXPLORER_TARGET)"

# Run the setup check program after compilation
run: $(TARGET)
	./$(TARGET)

# Run the stdlib explorer program after compilation
run-explorer: $(EXPLORER_TARGET)
	./$(EXPLORER_TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET) $(EXPLORER_TARGET)
	@echo "✓ Cleaned up executable files"

# Show compiler version
compiler-info:
	@echo "Compiler Information:"
	@$(CC) --version

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Compile both programs (default)"
	@echo "  run          - Compile and run setup check"
	@echo "  run-explorer - Compile and run stdlib explorer"
	@echo "  clean        - Remove executable files"
	@echo "  compiler-info - Show compiler version"
	@echo "  help         - Show this help message"

# Prevent make from treating these as file targets
.PHONY: all run run-explorer clean compiler-info help

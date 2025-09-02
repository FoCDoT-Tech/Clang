# Makefile for Macros Demo

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
TARGET = macros_demo
SOURCE = macros_demo.c

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Show macro expansion
expand: $(SOURCE)
	$(CC) -E $(CFLAGS) $(SOURCE) > expanded_macros.i
	@echo "Macro expansion saved to expanded_macros.i"
	@echo "Search for 'demonstrate_' to see expanded functions"

# Clean up generated files
clean:
	rm -f $(TARGET) expanded_macros.i

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  run     - Build and run the program"
	@echo "  expand  - Show macro expansion output"
	@echo "  clean   - Remove generated files"
	@echo "  help    - Show this help message"

# Phony targets
.PHONY: all run expand clean help

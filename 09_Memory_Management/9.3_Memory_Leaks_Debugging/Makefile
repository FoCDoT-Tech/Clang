# Makefile for Memory Leaks & Debugging Demo

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
TARGET = memory_debugging_demo
SOURCE = memory_debugging_demo.c

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Build with debug symbols for Valgrind
debug: $(SOURCE)
	$(CC) $(CFLAGS) -g -o $(TARGET) $(SOURCE)

# Build with AddressSanitizer
asan: $(SOURCE)
	$(CC) $(CFLAGS) -fsanitize=address -g -o $(TARGET) $(SOURCE)

# Run with Valgrind (requires debug build)
valgrind: debug
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all      - Build the program (default)"
	@echo "  run      - Build and run the program"
	@echo "  debug    - Build with debug symbols"
	@echo "  asan     - Build with AddressSanitizer"
	@echo "  valgrind - Run with Valgrind (builds debug first)"
	@echo "  clean    - Remove generated files"
	@echo "  help     - Show this help message"

# Phony targets
.PHONY: all run debug asan valgrind clean help

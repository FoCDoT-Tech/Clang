# Makefile for Bit Manipulation Demo

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g
LDFLAGS = 
TARGET = bit_manipulation_demo
SOURCE = bit_manipulation_demo.c

.PHONY: all build run debug clean help

# Default target
all: build

# Build the program
build: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE) $(LDFLAGS)

# Run the program
run: $(TARGET)
	@echo "Running Bit Manipulation Demo..."
	@echo "================================="
	./$(TARGET)

# Debug build with extra flags
debug: CFLAGS += -DDEBUG -O0
debug: $(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET)
	@echo "Cleaned build artifacts"

# Help target
help:
	@echo "Available targets:"
	@echo "  build   - Compile the bit manipulation demo"
	@echo "  run     - Build and run the demo"
	@echo "  debug   - Build with debug flags"
	@echo "  clean   - Remove build artifacts"
	@echo "  help    - Show this help message"

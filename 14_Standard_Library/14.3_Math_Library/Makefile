# Makefile for 14.3 Math Library Demo

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g
LDFLAGS = -lm
TARGET = math_library_demo
SOURCE = math_library_demo.c

# Default target
all: build

# Build the program
build: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE) $(LDFLAGS)

# Run the program
run: $(TARGET)
	@echo "Running Math Library Demo..."
	@echo "=========================="
	./$(TARGET)

# Test the program (same as run for demos)
test: run

# Clean build artifacts
clean:
	rm -f $(TARGET)
	@echo "Cleaned build artifacts"

# Help
help:
	@echo "Available targets:"
	@echo "  build  - Compile the program"
	@echo "  run    - Run the program"
	@echo "  test   - Test the program"
	@echo "  clean  - Remove build artifacts"
	@echo "  help   - Show this help"

.PHONY: all build run test clean help

# Makefile for Preprocessor Directives Demo

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
TARGET = preprocessor_directives_demo
SOURCE = preprocessor_directives_demo.c
HEADERS = config.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCE) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Show preprocessed output
preprocess: $(SOURCE) $(HEADERS)
	$(CC) -E $(SOURCE) > preprocessed_output.i
	@echo "Preprocessed output saved to preprocessed_output.i"
	@echo "First 50 lines of preprocessed output:"
	@head -50 preprocessed_output.i

# Clean up generated files
clean:
	rm -f $(TARGET) preprocessed_output.i

# Help target
help:
	@echo "Available targets:"
	@echo "  all        - Build the program (default)"
	@echo "  run        - Build and run the program"
	@echo "  preprocess - Show preprocessed output"
	@echo "  clean      - Remove generated files"
	@echo "  help       - Show this help message"

# Phony targets
.PHONY: all run preprocess clean help

# Master Makefile for Chapter 8: Pointers

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic

# Subdirectories
SUBDIRS = 8.1_Pointer_Basics \
          8.2_Pointer_Arithmetic \
          8.3_Pointers_and_Arrays \
          8.4_Pointers_and_Functions \
          8.5_Advanced_Pointer_Concepts

# Default target - build all sections
all:
	@echo "Building Chapter 8: Pointers..."
	@for dir in $(SUBDIRS); do \
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir all || exit 1; \
	done
	@echo "Chapter 8 build complete!"

# Run all demos
run:
	@echo "Running Chapter 8: Pointers Demos..."
	@echo "======================================="
	@for dir in $(SUBDIRS); do \
		echo ""; \
		echo "Running $$dir demo:"; \
		echo "-------------------"; \
		$(MAKE) -C $$dir run || exit 1; \
		echo ""; \
	done
	@echo "All Chapter 8 demos completed!"

# Test all sections (same as run for this chapter)
test: run

# Clean all sections
clean:
	@echo "Cleaning Chapter 8..."
	@for dir in $(SUBDIRS); do \
		echo "Cleaning $$dir..."; \
		$(MAKE) -C $$dir clean; \
	done
	@echo "Chapter 8 clean complete!"

# Individual section targets
8.1: 8.1_Pointer_Basics
	@echo "Building and running 8.1 Pointer Basics..."
	$(MAKE) -C 8.1_Pointer_Basics run

8.2: 8.2_Pointer_Arithmetic
	@echo "Building and running 8.2 Pointer Arithmetic..."
	$(MAKE) -C 8.2_Pointer_Arithmetic run

8.3: 8.3_Pointers_and_Arrays
	@echo "Building and running 8.3 Pointers and Arrays..."
	$(MAKE) -C 8.3_Pointers_and_Arrays run

8.4: 8.4_Pointers_and_Functions
	@echo "Building and running 8.4 Pointers and Functions..."
	$(MAKE) -C 8.4_Pointers_and_Functions run

8.5: 8.5_Advanced_Pointer_Concepts
	@echo "Building and running 8.5 Advanced Pointer Concepts..."
	$(MAKE) -C 8.5_Advanced_Pointer_Concepts run

# Help target
help:
	@echo "Chapter 8: Pointers - Available targets:"
	@echo "  all     - Build all sections"
	@echo "  run     - Build and run all demos"
	@echo "  test    - Run all tests (same as run)"
	@echo "  clean   - Clean all generated files"
	@echo "  8.1     - Build and run 8.1 Pointer Basics"
	@echo "  8.2     - Build and run 8.2 Pointer Arithmetic"
	@echo "  8.3     - Build and run 8.3 Pointers and Arrays"
	@echo "  8.4     - Build and run 8.4 Pointers and Functions"
	@echo "  8.5     - Build and run 8.5 Advanced Pointer Concepts"
	@echo "  help    - Show this help message"

# Phony targets
.PHONY: all run test clean help 8.1 8.2 8.3 8.4 8.5

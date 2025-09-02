# Master Makefile for Chapter 9: Memory Management

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic

# Subdirectories
SUBDIRS = 9.1_Memory_Layout \
          9.2_Dynamic_Memory_Allocation \
          9.3_Memory_Leaks_Debugging

# Default target - build all sections
all:
	@echo "Building Chapter 9: Memory Management..."
	@for dir in $(SUBDIRS); do \
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir all || exit 1; \
	done
	@echo "Chapter 9 build complete!"

# Run all demos
run:
	@echo "Running Chapter 9: Memory Management Demos..."
	@echo "=============================================="
	@for dir in $(SUBDIRS); do \
		echo ""; \
		echo "Running $$dir demo:"; \
		echo "-------------------"; \
		$(MAKE) -C $$dir run || exit 1; \
		echo ""; \
	done
	@echo "All Chapter 9 demos completed!"

# Test all sections (same as run for this chapter)
test: run

# Clean all sections
clean:
	@echo "Cleaning Chapter 9..."
	@for dir in $(SUBDIRS); do \
		echo "Cleaning $$dir..."; \
		$(MAKE) -C $$dir clean; \
	done
	@echo "Chapter 9 clean complete!"

# Individual section targets
9.1: 9.1_Memory_Layout
	@echo "Building and running 9.1 Memory Layout..."
	$(MAKE) -C 9.1_Memory_Layout run

9.2: 9.2_Dynamic_Memory_Allocation
	@echo "Building and running 9.2 Dynamic Memory Allocation..."
	$(MAKE) -C 9.2_Dynamic_Memory_Allocation run

9.3: 9.3_Memory_Leaks_Debugging
	@echo "Building and running 9.3 Memory Leaks & Debugging..."
	$(MAKE) -C 9.3_Memory_Leaks_Debugging run

# Special targets for debugging tools
valgrind:
	@echo "Running all sections with Valgrind..."
	@for dir in $(SUBDIRS); do \
		echo ""; \
		echo "Valgrind analysis for $$dir:"; \
		echo "----------------------------"; \
		$(MAKE) -C $$dir valgrind 2>/dev/null || echo "Valgrind not available for $$dir"; \
		echo ""; \
	done

asan:
	@echo "Building all sections with AddressSanitizer..."
	@for dir in $(SUBDIRS); do \
		echo "Building $$dir with AddressSanitizer..."; \
		$(MAKE) -C $$dir asan || exit 1; \
	done
	@echo "AddressSanitizer builds complete!"

# Help target
help:
	@echo "Chapter 9: Memory Management - Available targets:"
	@echo "  all      - Build all sections"
	@echo "  run      - Build and run all demos"
	@echo "  test     - Run all tests (same as run)"
	@echo "  clean    - Clean all generated files"
	@echo "  9.1      - Build and run 9.1 Memory Layout"
	@echo "  9.2      - Build and run 9.2 Dynamic Memory Allocation"
	@echo "  9.3      - Build and run 9.3 Memory Leaks & Debugging"
	@echo "  valgrind - Run all sections with Valgrind"
	@echo "  asan     - Build all sections with AddressSanitizer"
	@echo "  help     - Show this help message"

# Phony targets
.PHONY: all run test clean help 9.1 9.2 9.3 valgrind asan

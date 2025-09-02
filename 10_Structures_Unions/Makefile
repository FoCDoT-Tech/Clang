# Master Makefile for Chapter 10: Structures & Unions

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic

# Subdirectories
SUBDIRS = 10.1_Structures 10.2_Pointers_and_Structures 10.3_Unions 10.4_Bit_Fields 10.5_typedef

# Default target
all: build

# Build all sections
build:
	@echo "Building Chapter 10: Structures & Unions"
	@for dir in $(SUBDIRS); do \
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir all || exit 1; \
	done
	@echo "Chapter 10 build complete!"

# Run all demos
run: build
	@echo "Running Chapter 10 demos:"
	@echo "=========================="
	@for dir in $(SUBDIRS); do \
		echo ""; \
		echo "Running $$dir demo:"; \
		echo "----------------------------------------"; \
		$(MAKE) -C $$dir run || exit 1; \
		echo ""; \
	done
	@echo "All Chapter 10 demos completed!"

# Test all sections (same as run for this chapter)
test: run

# Clean all sections
clean:
	@echo "Cleaning Chapter 10..."
	@for dir in $(SUBDIRS); do \
		echo "Cleaning $$dir..."; \
		$(MAKE) -C $$dir clean; \
	done
	@echo "Chapter 10 clean complete!"

# Individual section targets
structures:
	@echo "Building and running Structures demo..."
	@$(MAKE) -C 10.1_Structures run

pointers:
	@echo "Building and running Pointers and Structures demo..."
	@$(MAKE) -C 10.2_Pointers_and_Structures run

unions:
	@echo "Building and running Unions demo..."
	@$(MAKE) -C 10.3_Unions run

bitfields:
	@echo "Building and running Bit Fields demo..."
	@$(MAKE) -C 10.4_Bit_Fields run

typedef:
	@echo "Building and running typedef demo..."
	@$(MAKE) -C 10.5_typedef run

# Help target
help:
	@echo "Chapter 10: Structures & Unions - Available targets:"
	@echo "  all        - Build all sections (default)"
	@echo "  build      - Build all sections"
	@echo "  run        - Build and run all demos"
	@echo "  test       - Run all tests (same as run)"
	@echo "  clean      - Clean all generated files"
	@echo ""
	@echo "Individual section targets:"
	@echo "  structures - Run 10.1 Structures demo"
	@echo "  pointers   - Run 10.2 Pointers and Structures demo"
	@echo "  unions     - Run 10.3 Unions demo"
	@echo "  bitfields  - Run 10.4 Bit Fields demo"
	@echo "  typedef    - Run 10.5 typedef demo"
	@echo ""
	@echo "  help       - Show this help message"

# Phony targets
.PHONY: all build run test clean structures pointers unions bitfields typedef help

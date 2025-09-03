# Master Makefile for Chapter 14: Standard Library
# Builds all sections in the Standard Library chapter

.PHONY: all build test clean help

# Default target
all: build

# List of all sections
SECTIONS = 14.1_Standard_IO \
           14.2_String_Handling \
           14.3_Math_Library \
           14.4_Memory_Management \
           14.5_Character_Classification \
           14.6_Time_Functions

# Build all sections
build:
	@echo "Building Chapter 14: Standard Library"
	@echo "====================================="
	@for section in $(SECTIONS); do \
		if [ -d "$$section" ]; then \
			echo "Building $$section..."; \
			$(MAKE) -C "$$section" build || exit 1; \
		else \
			echo "Warning: Directory $$section not found"; \
		fi; \
	done
	@echo "All sections built successfully"

# Test all sections
test: build
	@echo "Testing Chapter 14: Standard Library"
	@echo "===================================="
	@for section in $(SECTIONS); do \
		if [ -d "$$section" ]; then \
			echo "Testing $$section..."; \
			$(MAKE) -C "$$section" test && echo "  ✓ $$section passed" || echo "  ✗ $$section failed"; \
		fi; \
	done

# Clean all sections
clean:
	@echo "Cleaning Chapter 14: Standard Library"
	@echo "===================================="
	@for section in $(SECTIONS); do \
		if [ -d "$$section" ]; then \
			echo "Cleaning $$section..."; \
			$(MAKE) -C "$$section" clean; \
		fi; \
	done
	@echo "All sections cleaned"

# Run all sections
run:
	@echo "Running Chapter 14: Standard Library Demos"
	@echo "=========================================="
	@for section in $(SECTIONS); do \
		if [ -d "$$section" ]; then \
			echo ""; \
			echo "=== Running $$section ==="; \
			$(MAKE) -C "$$section" run || true; \
		fi; \
	done

# Help target
help:
	@echo "Chapter 14: Standard Library - Available targets:"
	@echo "  build  - Build all sections"
	@echo "  test   - Test all sections"  
	@echo "  clean  - Clean all sections"
	@echo "  run    - Run all section demos"
	@echo "  help   - Show this help"
	@echo ""
	@echo "Sections:"
	@for section in $(SECTIONS); do \
		echo "  $$section"; \
	done

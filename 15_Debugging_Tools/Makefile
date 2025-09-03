# Master Makefile for Chapter 15: Debugging & Tools
# Builds all sections in the Debugging & Tools chapter

.PHONY: all build test clean help

# Default target
all: build

# List of all sections
SECTIONS = 15.1_Debugging_Techniques \
           15.2_Common_Errors \
           15.3_Development_Tools

# Build all sections
build:
	@echo "Building Chapter 15: Debugging & Tools"
	@echo "======================================"
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
	@echo "Testing Chapter 15: Debugging & Tools"
	@echo "====================================="
	@for section in $(SECTIONS); do \
		if [ -d "$$section" ]; then \
			echo "Testing $$section..."; \
			$(MAKE) -C "$$section" test && echo "  ✓ $$section passed" || echo "  ✗ $$section failed"; \
		fi; \
	done

# Clean all sections
clean:
	@echo "Cleaning Chapter 15: Debugging & Tools"
	@echo "======================================"
	@for section in $(SECTIONS); do \
		if [ -d "$$section" ]; then \
			echo "Cleaning $$section..."; \
			$(MAKE) -C "$$section" clean; \
		fi; \
	done
	@echo "All sections cleaned"

# Run all sections
run:
	@echo "Running Chapter 15: Debugging & Tools Demos"
	@echo "==========================================="
	@for section in $(SECTIONS); do \
		if [ -d "$$section" ]; then \
			echo ""; \
			echo "=== Running $$section ==="; \
			$(MAKE) -C "$$section" run || true; \
		fi; \
	done

# Help target
help:
	@echo "Chapter 15: Debugging & Tools - Available targets:"
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

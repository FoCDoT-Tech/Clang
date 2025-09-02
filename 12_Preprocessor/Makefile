# Master Makefile for Chapter 12: Preprocessor

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic

# Subdirectories
SUBDIRS = 12.1_Preprocessor_Directives 12.2_Macros 12.3_Conditional_Compilation 12.4_Predefined_Macros

# Default target
all: build-all

# Build all sections
build-all:
	@echo "Building Chapter 12: Preprocessor"
	@for dir in $(SUBDIRS); do \
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir all || exit 1; \
	done
	@echo "Chapter 12 build complete!"

# Run all demos
run-all:
	@echo "Running Chapter 12: Preprocessor Demos"
	@echo "======================================"
	@for dir in $(SUBDIRS); do \
		echo ""; \
		echo "Running $$dir demo:"; \
		echo "----------------------------------------"; \
		$(MAKE) -C $$dir run || exit 1; \
		echo ""; \
	done
	@echo "All Chapter 12 demos completed!"

# Test all sections (build and run)
test-all: build-all
	@echo "Testing Chapter 12: Preprocessor"
	@echo "================================"
	@for dir in $(SUBDIRS); do \
		echo ""; \
		echo "Testing $$dir:"; \
		echo "----------------------------------------"; \
		$(MAKE) -C $$dir run || exit 1; \
	done
	@echo "All Chapter 12 tests passed!"

# Individual section targets
12.1: 12.1_Preprocessor_Directives
12.1_Preprocessor_Directives:
	@echo "Building 12.1 Preprocessor Directives..."
	$(MAKE) -C 12.1_Preprocessor_Directives all

12.2: 12.2_Macros
12.2_Macros:
	@echo "Building 12.2 Macros..."
	$(MAKE) -C 12.2_Macros all

12.3: 12.3_Conditional_Compilation
12.3_Conditional_Compilation:
	@echo "Building 12.3 Conditional Compilation..."
	$(MAKE) -C 12.3_Conditional_Compilation all

12.4: 12.4_Predefined_Macros
12.4_Predefined_Macros:
	@echo "Building 12.4 Predefined Macros..."
	$(MAKE) -C 12.4_Predefined_Macros all

# Run individual sections
run-12.1:
	$(MAKE) -C 12.1_Preprocessor_Directives run

run-12.2:
	$(MAKE) -C 12.2_Macros run

run-12.3:
	$(MAKE) -C 12.3_Conditional_Compilation run

run-12.4:
	$(MAKE) -C 12.4_Predefined_Macros run

# Debug builds for all sections
debug-all:
	@echo "Building Chapter 12 debug versions..."
	@for dir in $(SUBDIRS); do \
		echo "Building debug version of $$dir..."; \
		$(MAKE) -C $$dir debug 2>/dev/null || echo "Debug target not available for $$dir"; \
	done

# Run debug versions
run-debug-all:
	@echo "Running Chapter 12 debug versions..."
	@for dir in $(SUBDIRS); do \
		echo ""; \
		echo "Running debug version of $$dir:"; \
		echo "----------------------------------------"; \
		$(MAKE) -C $$dir run-debug 2>/dev/null || echo "Debug run not available for $$dir"; \
	done

# Show preprocessor output for all sections
preprocess-all:
	@echo "Generating preprocessor output for Chapter 12..."
	@for dir in $(SUBDIRS); do \
		echo "Preprocessing $$dir..."; \
		$(MAKE) -C $$dir preprocess 2>/dev/null || $(MAKE) -C $$dir expand 2>/dev/null || echo "Preprocess target not available for $$dir"; \
	done

# Clean all sections
clean-all:
	@echo "Cleaning Chapter 12..."
	@for dir in $(SUBDIRS); do \
		echo "Cleaning $$dir..."; \
		$(MAKE) -C $$dir clean; \
	done
	@echo "Chapter 12 cleanup complete!"

# Clean individual sections
clean-12.1:
	$(MAKE) -C 12.1_Preprocessor_Directives clean

clean-12.2:
	$(MAKE) -C 12.2_Macros clean

clean-12.3:
	$(MAKE) -C 12.3_Conditional_Compilation clean

clean-12.4:
	$(MAKE) -C 12.4_Predefined_Macros clean

# Show chapter summary
summary:
	@echo "Chapter 12: Preprocessor - Summary"
	@echo "=================================="
	@echo "Sections:"
	@echo "  12.1 - Preprocessor Directives"
	@echo "         Basic directives, conditional compilation, header guards"
	@echo "  12.2 - Macros"
	@echo "         Object-like and function-like macros, advanced techniques"
	@echo "  12.3 - Conditional Compilation"
	@echo "         Platform detection, feature flags, debug/release builds"
	@echo "  12.4 - Predefined Macros"
	@echo "         Standard macros, compiler detection, debugging utilities"
	@echo ""
	@echo "Available targets:"
	@echo "  all, build-all    - Build all sections"
	@echo "  run-all          - Run all demos"
	@echo "  test-all         - Build and test all sections"
	@echo "  debug-all        - Build debug versions"
	@echo "  run-debug-all    - Run debug versions"
	@echo "  preprocess-all   - Show preprocessor output"
	@echo "  clean-all        - Clean all generated files"
	@echo "  12.1, 12.2, 12.3, 12.4 - Build individual sections"
	@echo "  run-12.1, run-12.2, run-12.3, run-12.4 - Run individual demos"

# Help target
help: summary

# Phony targets
.PHONY: all build-all run-all test-all debug-all run-debug-all preprocess-all clean-all \
        12.1 12.2 12.3 12.4 12.1_Preprocessor_Directives 12.2_Macros 12.3_Conditional_Compilation 12.4_Predefined_Macros \
        run-12.1 run-12.2 run-12.3 run-12.4 \
        clean-12.1 clean-12.2 clean-12.3 clean-12.4 \
        summary help

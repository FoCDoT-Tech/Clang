# Master Makefile for Chapter 11: File Handling

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic

# Section directories
SECTIONS = 11.1_File_Operations 11.2_File_IO_Functions 11.3_File_Positioning 11.4_Command_Line_Arguments

# Default target - build all sections
all: build-all

# Build all sections
build-all:
	@echo "🔨 Building Chapter 11: File Handling"
	@for section in $(SECTIONS); do \
		echo "Building $$section..."; \
		$(MAKE) -C $$section all; \
	done
	@echo "✅ Chapter 11 build complete"

# Run all demos
run-all:
	@echo "🚀 Running all File Handling demos"
	@for section in $(SECTIONS); do \
		echo ""; \
		echo "=== Running $$section ==="; \
		$(MAKE) -C $$section run; \
	done
	@echo "✅ All demos completed"

# Test all sections (build and run)
test: build-all run-all

# Individual section targets
11.1: 11.1_File_Operations/file_operations_demo
	@echo "Running File Operations demo..."
	@$(MAKE) -C 11.1_File_Operations run

11.2: 11.2_File_IO_Functions/file_io_demo
	@echo "Running File I/O Functions demo..."
	@$(MAKE) -C 11.2_File_IO_Functions run

11.3: 11.3_File_Positioning/file_positioning_demo
	@echo "Running File Positioning demo..."
	@$(MAKE) -C 11.3_File_Positioning run

11.4: 11.4_Command_Line_Arguments/command_line_demo
	@echo "Running Command Line Arguments demo..."
	@$(MAKE) -C 11.4_Command_Line_Arguments test

# Build individual sections
11.1_File_Operations/file_operations_demo:
	@$(MAKE) -C 11.1_File_Operations

11.2_File_IO_Functions/file_io_demo:
	@$(MAKE) -C 11.2_File_IO_Functions

11.3_File_Positioning/file_positioning_demo:
	@$(MAKE) -C 11.3_File_Positioning

11.4_Command_Line_Arguments/command_line_demo:
	@$(MAKE) -C 11.4_Command_Line_Arguments

# Clean all sections
clean:
	@echo "🧹 Cleaning Chapter 11: File Handling"
	@for section in $(SECTIONS); do \
		echo "Cleaning $$section..."; \
		$(MAKE) -C $$section clean; \
	done
	@echo "✅ Chapter 11 cleaned"

# Help target
help:
	@echo "Chapter 11: File Handling - Available targets:"
	@echo ""
	@echo "Building:"
	@echo "  all        - Build all sections (default)"
	@echo "  build-all  - Build all sections"
	@echo ""
	@echo "Running:"
	@echo "  run-all    - Run all demos"
	@echo "  test       - Build and run all demos"
	@echo ""
	@echo "Individual sections:"
	@echo "  11.1       - Run File Operations demo"
	@echo "  11.2       - Run File I/O Functions demo"
	@echo "  11.3       - Run File Positioning demo"
	@echo "  11.4       - Run Command Line Arguments demo"
	@echo ""
	@echo "Maintenance:"
	@echo "  clean      - Clean all generated files"
	@echo "  help       - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make           # Build all sections"
	@echo "  make test      # Build and run all demos"
	@echo "  make 11.1      # Run only File Operations demo"
	@echo "  make clean     # Clean all generated files"

# Phony targets
.PHONY: all build-all run-all test clean help 11.1 11.2 11.3 11.4

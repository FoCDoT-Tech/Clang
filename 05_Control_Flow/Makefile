# Master Makefile for Chapter 5: Control Flow

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Subdirectories
CONDITIONAL_DIR = 5.1_Conditional_Statements
LOOPS_DIR = 5.2_Loops
JUMP_DIR = 5.3_Jump_Statements

# Executables
CONDITIONAL_EXEC = $(CONDITIONAL_DIR)/conditional_demo
LOOPS_EXEC = $(LOOPS_DIR)/loops_demo
JUMP_EXEC = $(JUMP_DIR)/jump_statements_demo

# Default target - build all
all: conditional loops jump

# Individual section targets
conditional:
	@echo "Building Conditional Statements demo..."
	@$(MAKE) -C $(CONDITIONAL_DIR)

loops:
	@echo "Building Loops demo..."
	@$(MAKE) -C $(LOOPS_DIR)

jump:
	@echo "Building Jump Statements demo..."
	@$(MAKE) -C $(JUMP_DIR)

# Run all demos
run-all: all
	@echo "=== Running All Chapter 5 Demos ==="
	@echo
	@echo "--- 5.1 Conditional Statements ---"
	@$(MAKE) -C $(CONDITIONAL_DIR) run
	@echo
	@echo "--- 5.2 Loops ---"
	@$(MAKE) -C $(LOOPS_DIR) run
	@echo
	@echo "--- 5.3 Jump Statements ---"
	@$(MAKE) -C $(JUMP_DIR) run

# Run individual demos
run-conditional: conditional
	@$(MAKE) -C $(CONDITIONAL_DIR) run

run-loops: loops
	@$(MAKE) -C $(LOOPS_DIR) run

run-jump: jump
	@$(MAKE) -C $(JUMP_DIR) run

# Clean all
clean:
	@echo "Cleaning all Chapter 5 demos..."
	@$(MAKE) -C $(CONDITIONAL_DIR) clean
	@$(MAKE) -C $(LOOPS_DIR) clean
	@$(MAKE) -C $(JUMP_DIR) clean

# Test all (build and run)
test: run-all

# Help
help:
	@echo "Chapter 5: Control Flow - Available targets:"
	@echo "  all              - Build all demos"
	@echo "  conditional      - Build conditional statements demo"
	@echo "  loops            - Build loops demo"
	@echo "  jump             - Build jump statements demo"
	@echo "  run-all          - Build and run all demos"
	@echo "  run-conditional  - Build and run conditional demo"
	@echo "  run-loops        - Build and run loops demo"
	@echo "  run-jump         - Build and run jump statements demo"
	@echo "  test             - Build and run all demos (same as run-all)"
	@echo "  clean            - Clean all generated files"
	@echo "  help             - Show this help message"
	@echo ""
	@echo "Individual sections:"
	@echo "  5.1 Conditional Statements - if, if-else, switch-case"
	@echo "  5.2 Loops                 - for, while, do-while, nested"
	@echo "  5.3 Jump Statements       - break, continue, goto, return"

# Declare phony targets
.PHONY: all conditional loops jump run-all run-conditional run-loops run-jump clean test help

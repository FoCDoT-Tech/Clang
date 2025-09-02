# Master Makefile for Chapter 6: Functions

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -lm

# Subdirectories
BASICS_DIR = 6.1_Function_Basics
PARAMS_DIR = 6.2_Parameters_Arguments
TYPES_DIR = 6.3_Function_Types
ADVANCED_DIR = 6.4_Advanced_Function_Concepts

# Executables
BASICS_EXEC = $(BASICS_DIR)/function_basics_demo
PARAMS_EXEC = $(PARAMS_DIR)/parameters_demo
TYPES_EXEC = $(TYPES_DIR)/function_types_demo
ADVANCED_EXEC = $(ADVANCED_DIR)/advanced_functions_demo

# Default target - build all
all: basics params types advanced

# Individual section targets
basics:
	@echo "Building Function Basics demo..."
	@$(MAKE) -C $(BASICS_DIR)

params:
	@echo "Building Parameters & Arguments demo..."
	@$(MAKE) -C $(PARAMS_DIR)

types:
	@echo "Building Function Types demo..."
	@$(MAKE) -C $(TYPES_DIR)

advanced:
	@echo "Building Advanced Function Concepts demo..."
	@$(MAKE) -C $(ADVANCED_DIR)

# Run all demos
run-all: all
	@echo "=== Running All Chapter 6 Demos ==="
	@echo
	@echo "--- 6.1 Function Basics ---"
	@$(MAKE) -C $(BASICS_DIR) run
	@echo
	@echo "--- 6.2 Parameters & Arguments ---"
	@$(MAKE) -C $(PARAMS_DIR) run
	@echo
	@echo "--- 6.3 Function Types ---"
	@$(MAKE) -C $(TYPES_DIR) run
	@echo
	@echo "--- 6.4 Advanced Function Concepts ---"
	@$(MAKE) -C $(ADVANCED_DIR) run

# Run individual demos
run-basics: basics
	@$(MAKE) -C $(BASICS_DIR) run

run-params: params
	@$(MAKE) -C $(PARAMS_DIR) run

run-types: types
	@$(MAKE) -C $(TYPES_DIR) run

run-advanced: advanced
	@$(MAKE) -C $(ADVANCED_DIR) run

# Clean all
clean:
	@echo "Cleaning all Chapter 6 demos..."
	@$(MAKE) -C $(BASICS_DIR) clean
	@$(MAKE) -C $(PARAMS_DIR) clean
	@$(MAKE) -C $(TYPES_DIR) clean
	@$(MAKE) -C $(ADVANCED_DIR) clean

# Test all (build and run)
test: run-all

# Help
help:
	@echo "Chapter 6: Functions - Available targets:"
	@echo "  all              - Build all demos"
	@echo "  basics           - Build function basics demo"
	@echo "  params           - Build parameters & arguments demo"
	@echo "  types            - Build function types demo"
	@echo "  advanced         - Build advanced concepts demo"
	@echo "  run-all          - Build and run all demos"
	@echo "  run-basics       - Build and run function basics demo"
	@echo "  run-params       - Build and run parameters demo"
	@echo "  run-types        - Build and run function types demo"
	@echo "  run-advanced     - Build and run advanced concepts demo"
	@echo "  test             - Build and run all demos (same as run-all)"
	@echo "  clean            - Clean all generated files"
	@echo "  help             - Show this help message"
	@echo ""
	@echo "Individual sections:"
	@echo "  6.1 Function Basics        - Definition, declaration, calls, return"
	@echo "  6.2 Parameters & Arguments - Pass by value/reference, arrays"
	@echo "  6.3 Function Types         - void, return types, parameters"
	@echo "  6.4 Advanced Concepts      - Recursion, pointers, callbacks, variadic"

# Declare phony targets
.PHONY: all basics params types advanced run-all run-basics run-params run-types run-advanced clean test help

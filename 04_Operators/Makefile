# Makefile for Chapter 4: Operators
# Builds and runs all operator demonstration programs

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# All subdirectories with demos
SUBDIRS = 4.1_Arithmetic_Operators 4.2_Relational_Operators 4.3_Logical_Operators \
          4.4_Bitwise_Operators 4.5_Assignment_Operators 4.6_Other_Operators \
          4.7_Operator_Precedence_Associativity

# Default target - build all demos
all:
	@echo "=== Building Chapter 4: Operators ==="
	@for dir in $(SUBDIRS); do \
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir all; \
	done
	@echo "✓ All operator demos compiled successfully!"

# Run all demos in sequence
run-all:
	@echo "=== Running All Operator Demos ==="
	@for dir in $(SUBDIRS); do \
		echo ""; \
		echo "Running $$dir:"; \
		echo "====================================="; \
		$(MAKE) -C $$dir run; \
		echo ""; \
	done
	@echo "✓ All operator demos completed!"

# Individual run targets
run-arithmetic:
	@$(MAKE) -C 4.1_Arithmetic_Operators run

run-relational:
	@$(MAKE) -C 4.2_Relational_Operators run

run-logical:
	@$(MAKE) -C 4.3_Logical_Operators run

run-bitwise:
	@$(MAKE) -C 4.4_Bitwise_Operators run

run-assignment:
	@$(MAKE) -C 4.5_Assignment_Operators run

run-other:
	@$(MAKE) -C 4.6_Other_Operators run

run-precedence:
	@$(MAKE) -C 4.7_Operator_Precedence_Associativity run

# Clean all demos
clean:
	@echo "Cleaning Chapter 4: Operators..."
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
	@echo "✓ All operator demos cleaned!"

# Help target
help:
	@echo "Chapter 4: Operators - Available targets:"
	@echo "  all              - Build all operator demos"
	@echo "  run-all          - Run all operator demos in sequence"
	@echo "  run-arithmetic   - Run arithmetic operators demo"
	@echo "  run-relational   - Run relational operators demo"
	@echo "  run-logical      - Run logical operators demo"
	@echo "  run-bitwise      - Run bitwise operators demo"
	@echo "  run-assignment   - Run assignment operators demo"
	@echo "  run-other        - Run other operators demo"
	@echo "  run-precedence   - Run precedence & associativity demo"
	@echo "  clean            - Clean all executable files"
	@echo "  help             - Show this help message"

.PHONY: all run-all run-arithmetic run-relational run-logical run-bitwise \
        run-assignment run-other run-precedence clean help

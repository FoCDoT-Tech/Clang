# Makefile for First Program examples
# Demonstrates different compilation scenarios

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
MATHFLAGS = -lm

# All programs to build
PROGRAMS = hello_world program_structure compilation_demo

# Default target - build all programs
all: $(PROGRAMS)
	@echo "✓ All programs compiled successfully!"
	@echo "Run any program with: ./program_name"

# Individual program targets
hello_world: hello_world.c
	$(CC) $(CFLAGS) hello_world.c -o hello_world

program_structure: program_structure.c
	$(CC) $(CFLAGS) program_structure.c -o program_structure

compilation_demo: compilation_demo.c
	$(CC) $(CFLAGS) compilation_demo.c -o compilation_demo $(MATHFLAGS)

# Run all programs in sequence
run-all: $(PROGRAMS)
	@echo "=== Running hello_world ==="
	./hello_world
	@echo "\n=== Running program_structure ==="
	./program_structure
	@echo "\n=== Running compilation_demo ==="
	./compilation_demo

# Individual run targets
run-hello: hello_world
	./hello_world

run-structure: program_structure
	./program_structure

run-demo: compilation_demo
	./compilation_demo

# Clean up all executables
clean:
	rm -f $(PROGRAMS)
	@echo "✓ Cleaned up all executable files"

# Show compilation steps for educational purposes
show-steps: hello_world.c
	@echo "=== Compilation Steps Demo ==="
	@echo "1. Preprocessing:"
	$(CC) -E hello_world.c -o hello_world.i
	@echo "   Created hello_world.i (preprocessed)"
	@echo "2. Compilation:"
	$(CC) -S hello_world.i -o hello_world.s
	@echo "   Created hello_world.s (assembly)"
	@echo "3. Assembly:"
	$(CC) -c hello_world.s -o hello_world.o
	@echo "   Created hello_world.o (object file)"
	@echo "4. Linking:"
	$(CC) hello_world.o -o hello_world_steps
	@echo "   Created hello_world_steps (executable)"
	@echo "✓ All compilation steps completed!"
	rm -f hello_world.i hello_world.s hello_world.o hello_world_steps

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Compile all programs (default)"
	@echo "  run-all      - Compile and run all programs"
	@echo "  run-hello    - Run hello_world program"
	@echo "  run-structure - Run program_structure"
	@echo "  run-demo     - Run compilation_demo"
	@echo "  show-steps   - Demonstrate compilation steps"
	@echo "  clean        - Remove all executable files"
	@echo "  help         - Show this help message"

.PHONY: all run-all run-hello run-structure run-demo clean show-steps help

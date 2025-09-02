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
	@wc -l hello_world.c hello_world.i | head -2
	@echo "2. Compilation:"
	$(CC) -S hello_world.i -o hello_world.s
	@echo "   Created hello_world.s (assembly)"
	@echo "3. Assembly:"
	$(CC) -c hello_world.s -o hello_world.o
	@echo "   Created hello_world.o (object file)"
	@echo "4. Linking:"
	$(CC) hello_world.o -o hello_world_steps
	@echo "   Created hello_world_steps (executable)"
	@echo "✓ Testing the step-by-step executable:"
	@./hello_world_steps
	@echo "✓ All compilation steps completed!"

# Show file sizes after compilation steps
show-sizes: hello_world.c
	@echo "=== File Size Comparison ==="
	$(CC) -E hello_world.c -o hello_world.i
	$(CC) -S hello_world.i -o hello_world.s
	$(CC) -c hello_world.s -o hello_world.o
	$(CC) hello_world.o -o hello_world_step_by_step
	@ls -la hello_world.c hello_world.i hello_world.s hello_world.o hello_world_step_by_step
	@echo "\nFile size progression:"
	@echo "Source → Preprocessed → Assembly → Object → Executable"
	@du -h hello_world.c hello_world.i hello_world.s hello_world.o hello_world_step_by_step | awk '{print $$1}' | tr '\n' ' → '
	@echo ""

# Demonstrate preprocessing expansion
show-preprocessing: hello_world.c
	@echo "=== Preprocessing Expansion Demo ==="
	@echo "Original source code lines:"
	@wc -l hello_world.c
	@echo "\nAfter preprocessing:"
	$(CC) -E hello_world.c -o hello_world.i
	@wc -l hello_world.i
	@echo "\nFirst 10 lines of preprocessed file:"
	@head -10 hello_world.i
	@echo "\nLast 10 lines of preprocessed file:"
	@tail -10 hello_world.i
	@rm -f hello_world.i

# Show assembly code
show-assembly: hello_world.c
	@echo "=== Assembly Code Demo ==="
	$(CC) -S hello_world.c -o hello_world.s
	@echo "Generated assembly code:"
	@cat hello_world.s
	@rm -f hello_world.s

# Clean up intermediate files
clean-steps:
	rm -f hello_world.i hello_world.s hello_world.o hello_world_steps hello_world_step_by_step
	@echo "✓ Cleaned up intermediate compilation files"

# Help target
help:
	@echo "Available targets:"
	@echo "  all              - Compile all programs (default)"
	@echo "  run-all          - Compile and run all programs"
	@echo "  run-hello        - Run hello_world program"
	@echo "  run-structure    - Run program_structure"
	@echo "  run-demo         - Run compilation_demo"
	@echo "  show-steps       - Demonstrate compilation steps with line counts"
	@echo "  show-sizes       - Show file size progression through compilation"
	@echo "  show-preprocessing - Show preprocessing expansion details"
	@echo "  show-assembly    - Display generated assembly code"
	@echo "  clean            - Remove all executable files"
	@echo "  clean-steps      - Remove intermediate compilation files"
	@echo "  help             - Show this help message"

.PHONY: all run-all run-hello run-structure run-demo clean show-steps show-sizes show-preprocessing show-assembly clean-steps help

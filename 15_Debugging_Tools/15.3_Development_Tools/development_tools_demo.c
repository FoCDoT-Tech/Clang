#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void demonstrate_compiler_usage(void);
void demonstrate_make_system(void);
void demonstrate_version_control_concepts(void);
void demonstrate_debugging_tools(void);
void demonstrate_profiling_concepts(void);
void demonstrate_static_analysis(void);

// Sample functions for tool demonstration
int fibonacci(int n);
void memory_intensive_function(void);
int* create_and_fill_array(int size);
void demonstrate_code_quality(void);

int main(void) {
    printf("=== Development Tools Demo ===\n\n");
    
    demonstrate_compiler_usage();
    demonstrate_make_system();
    demonstrate_version_control_concepts();
    demonstrate_debugging_tools();
    demonstrate_profiling_concepts();
    demonstrate_static_analysis();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_compiler_usage(void) {
    printf("1. COMPILER USAGE\n");
    printf("----------------------------------------\n");
    
    printf("GCC and Clang compiler examples:\n\n");
    
    printf("Basic compilation:\n");
    printf("  gcc -o program source.c\n");
    printf("  clang -o program source.c\n\n");
    
    printf("Compilation with warnings:\n");
    printf("  gcc -Wall -Wextra -o program source.c\n");
    printf("  clang -Wall -Wextra -o program source.c\n\n");
    
    printf("Debug compilation:\n");
    printf("  gcc -g -Wall -o program source.c\n");
    printf("  clang -g -Wall -o program source.c\n\n");
    
    printf("Optimization levels:\n");
    printf("  gcc -O0 source.c  # No optimization (default)\n");
    printf("  gcc -O1 source.c  # Basic optimization\n");
    printf("  gcc -O2 source.c  # Standard optimization\n");
    printf("  gcc -O3 source.c  # Aggressive optimization\n");
    printf("  gcc -Os source.c  # Optimize for size\n\n");
    
    printf("C standard specification:\n");
    printf("  gcc -std=c89 source.c   # ANSI C\n");
    printf("  gcc -std=c99 source.c   # C99 standard\n");
    printf("  gcc -std=c11 source.c   # C11 standard\n");
    printf("  gcc -std=c17 source.c   # C17 standard\n\n");
    
    printf("Useful compiler flags:\n");
    printf("  -pedantic     # Strict standard compliance\n");
    printf("  -Werror       # Treat warnings as errors\n");
    printf("  -fstack-protector  # Stack protection\n");
    printf("  -D MACRO=value     # Define preprocessor macro\n");
    printf("  -I /path/to/headers # Include directory\n");
    printf("  -L /path/to/libs    # Library directory\n");
    printf("  -l library_name     # Link library\n\n");
    
    printf("Cross-compilation example:\n");
    printf("  arm-linux-gnueabi-gcc -o program source.c\n");
    
    printf("\n");
}

void demonstrate_make_system(void) {
    printf("2. MAKE BUILD SYSTEM\n");
    printf("----------------------------------------\n");
    
    printf("Basic Makefile structure:\n\n");
    
    printf("# Simple Makefile example\n");
    printf("CC = gcc\n");
    printf("CFLAGS = -Wall -Wextra -std=c99 -g\n");
    printf("TARGET = myprogram\n");
    printf("SOURCES = main.c utils.c\n");
    printf("OBJECTS = $(SOURCES:.c=.o)\n\n");
    
    printf("$(TARGET): $(OBJECTS)\n");
    printf("    $(CC) $(OBJECTS) -o $(TARGET)\n\n");
    
    printf("%%.o: %%.c\\n");
    printf("    $(CC) $(CFLAGS) -c $< -o $@\n\n");
    
    printf("clean:\n");
    printf("    rm -f $(OBJECTS) $(TARGET)\n\n");
    
    printf(".PHONY: clean\n\n");
    
    printf("Make commands:\n");
    printf("  make           # Build default target\n");
    printf("  make clean     # Clean build artifacts\n");
    printf("  make TARGET    # Build specific target\n");
    printf("  make -j4       # Parallel build (4 jobs)\n");
    printf("  make -n        # Dry run (show commands)\n");
    printf("  make -f other.mk # Use different makefile\n\n");
    
    printf("Advanced Makefile features:\n");
    printf("- Automatic dependency generation\n");
    printf("- Conditional compilation\n");
    printf("- Pattern rules and wildcards\n");
    printf("- Variable substitution\n");
    printf("- Include other makefiles\n\n");
    
    printf("CMake example:\n");
    printf("# CMakeLists.txt\n");
    printf("cmake_minimum_required(VERSION 3.10)\n");
    printf("project(MyProject)\n");
    printf("set(CMAKE_C_STANDARD 99)\n");
    printf("add_executable(myprogram main.c utils.c)\n\n");
    
    printf("CMake commands:\n");
    printf("  mkdir build && cd build\n");
    printf("  cmake ..\n");
    printf("  make\n");
    
    printf("\n");
}

void demonstrate_version_control_concepts(void) {
    printf("3. VERSION CONTROL (GIT)\n");
    printf("----------------------------------------\n");
    
    printf("Git workflow commands:\n\n");
    
    printf("Repository setup:\n");
    printf("  git init                    # Initialize repository\n");
    printf("  git clone <url>             # Clone remote repository\n");
    printf("  git remote add origin <url> # Add remote\n\n");
    
    printf("Basic workflow:\n");
    printf("  git status                  # Check status\n");
    printf("  git add file.c              # Stage file\n");
    printf("  git add .                   # Stage all changes\n");
    printf("  git commit -m \"message\"     # Commit changes\n");
    printf("  git push origin main        # Push to remote\n");
    printf("  git pull origin main        # Pull from remote\n\n");
    
    printf("Branching:\n");
    printf("  git branch                  # List branches\n");
    printf("  git branch feature-x        # Create branch\n");
    printf("  git checkout feature-x      # Switch branch\n");
    printf("  git checkout -b feature-y   # Create and switch\n");
    printf("  git merge feature-x         # Merge branch\n");
    printf("  git branch -d feature-x     # Delete branch\n\n");
    
    printf("History and inspection:\n");
    printf("  git log                     # View commit history\n");
    printf("  git log --oneline           # Compact history\n");
    printf("  git diff                    # Show changes\n");
    printf("  git diff --cached           # Show staged changes\n");
    printf("  git show <commit>           # Show commit details\n\n");
    
    printf("Undoing changes:\n");
    printf("  git checkout -- file.c      # Discard changes\n");
    printf("  git reset HEAD file.c       # Unstage file\n");
    printf("  git reset --hard HEAD       # Reset to last commit\n");
    printf("  git revert <commit>         # Revert commit\n\n");
    
    printf("Best practices:\n");
    printf("- Write clear commit messages\n");
    printf("- Commit frequently with logical units\n");
    printf("- Use .gitignore for build artifacts\n");
    printf("- Create feature branches\n");
    printf("- Review code before merging\n");
    
    printf("\n");
}

void demonstrate_debugging_tools(void) {
    printf("4. DEBUGGING TOOLS\n");
    printf("----------------------------------------\n");
    
    printf("GDB (GNU Debugger) usage:\n\n");
    
    printf("Starting GDB:\n");
    printf("  gdb ./program               # Start with program\n");
    printf("  gdb --args program arg1 arg2 # With arguments\n");
    printf("  gdb -c core ./program       # With core dump\n\n");
    
    printf("Basic GDB commands:\n");
    printf("  (gdb) run                   # Run program\n");
    printf("  (gdb) break main            # Set breakpoint\n");
    printf("  (gdb) break file.c:25       # Breakpoint at line\n");
    printf("  (gdb) continue              # Continue execution\n");
    printf("  (gdb) next                  # Step over\n");
    printf("  (gdb) step                  # Step into\n");
    printf("  (gdb) finish                # Step out\n\n");
    
    printf("Examining variables:\n");
    printf("  (gdb) print variable        # Print variable\n");
    printf("  (gdb) print *pointer        # Dereference pointer\n");
    printf("  (gdb) print array[0]@10     # Print array elements\n");
    printf("  (gdb) x/10i $pc             # Examine instructions\n");
    printf("  (gdb) x/10x address         # Examine memory (hex)\n\n");
    
    printf("Stack inspection:\n");
    printf("  (gdb) backtrace             # Show call stack\n");
    printf("  (gdb) frame 2               # Switch to frame\n");
    printf("  (gdb) info locals           # Show local variables\n");
    printf("  (gdb) info args             # Show function arguments\n\n");
    
    printf("Valgrind for memory debugging:\n");
    printf("  valgrind ./program          # Basic memory check\n");
    printf("  valgrind --leak-check=full ./program\n");
    printf("  valgrind --tool=cachegrind ./program\n");
    printf("  valgrind --tool=callgrind ./program\n\n");
    
    // Demonstrate a function that could be debugged
    printf("Example function for debugging:\n");
    int result = fibonacci(10);
    printf("fibonacci(10) = %d\n", result);
    printf("(Set breakpoint in fibonacci() to trace recursion)\n");
    
    printf("\n");
}

void demonstrate_profiling_concepts(void) {
    printf("5. PROFILING TOOLS\n");
    printf("----------------------------------------\n");
    
    printf("Performance profiling tools:\n\n");
    
    printf("gprof (GNU Profiler):\n");
    printf("  gcc -pg -o program source.c # Compile with profiling\n");
    printf("  ./program                   # Run program\n");
    printf("  gprof program gmon.out      # Generate profile\n\n");
    
    printf("Valgrind profiling tools:\n");
    printf("  valgrind --tool=callgrind ./program\n");
    printf("  kcachegrind callgrind.out.* # Visualize results\n\n");
    
    printf("perf (Linux performance tools):\n");
    printf("  perf record ./program       # Record performance data\n");
    printf("  perf report                 # Analyze results\n");
    printf("  perf stat ./program         # Basic statistics\n\n");
    
    printf("Time measurement in code:\n");
    clock_t start = clock();
    
    // Simulate some work
    memory_intensive_function();
    
    clock_t end = clock();
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Function execution time: %.6f seconds\n", cpu_time);
    
    printf("\nProfiling best practices:\n");
    printf("- Profile with realistic data\n");
    printf("- Focus on hotspots (80/20 rule)\n");
    printf("- Measure before and after optimization\n");
    printf("- Consider different optimization levels\n");
    printf("- Profile on target hardware\n");
    
    printf("\n");
}

void demonstrate_static_analysis(void) {
    printf("6. STATIC ANALYSIS TOOLS\n");
    printf("----------------------------------------\n");
    
    printf("Compiler-based analysis:\n");
    printf("  gcc -Wall -Wextra -Wpedantic source.c\n");
    printf("  clang --analyze source.c\n");
    printf("  clang-tidy source.c\n\n");
    
    printf("Dedicated static analyzers:\n");
    printf("  cppcheck source.c           # General purpose\n");
    printf("  splint source.c             # Annotation-based\n");
    printf("  pc-lint source.c            # Commercial tool\n\n");
    
    printf("Code quality metrics:\n");
    printf("  sloccount .                 # Line counting\n");
    printf("  complexity analysis tools\n");
    printf("  code coverage tools (gcov)\n\n");
    
    printf("Example static analysis findings:\n");
    demonstrate_code_quality();
    
    printf("\nIntegrating into workflow:\n");
    printf("- Run analysis in CI/CD pipeline\n");
    printf("- Set quality gates\n");
    printf("- Regular code reviews\n");
    printf("- Automated formatting (clang-format)\n");
    
    printf("\nCode formatting example:\n");
    printf("  clang-format -i source.c    # Format in place\n");
    printf("  clang-format --style=Google source.c\n");
    
    printf("\n");
}

// Helper function implementations

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void memory_intensive_function(void) {
    // Simulate memory-intensive work
    int* array = create_and_fill_array(10000);
    if (array) {
        // Do some work with the array
        int sum = 0;
        for (int i = 0; i < 10000; i++) {
            sum += array[i];
        }
        
        // Simulate processing
        volatile int result = sum % 1000;
        (void)result;  // Suppress unused variable warning
        
        free(array);
    }
}

int* create_and_fill_array(int size) {
    int* array = malloc(size * sizeof(int));
    if (!array) {
        return NULL;
    }
    
    for (int i = 0; i < size; i++) {
        array[i] = i * i % 1000;
    }
    
    return array;
}

void demonstrate_code_quality(void) {
    printf("Code quality examples:\n");
    
    // Good: Clear variable names
    int student_count = 25;
    double average_grade = 87.5;
    
    // Good: Proper error checking
    FILE* file = fopen("example.txt", "r");
    if (file) {
        printf("File opened successfully\n");
        fclose(file);
    } else {
        printf("Could not open file (expected for demo)\n");
    }
    
    // Good: Const correctness
    const char* const program_name = "Development Tools Demo";
    printf("Program: %s\n", program_name);
    
    // Good: Proper memory management
    char* buffer = malloc(100);
    if (buffer) {
        snprintf(buffer, 100, "Student count: %d, Average: %.1f", 
                student_count, average_grade);
        printf("Buffer content: %s\n", buffer);
        free(buffer);
    }
    
    printf("Static analysis would check for:\n");
    printf("- Uninitialized variables\n");
    printf("- Memory leaks\n");
    printf("- Buffer overflows\n");
    printf("- Dead code\n");
    printf("- Coding standard violations\n");
}

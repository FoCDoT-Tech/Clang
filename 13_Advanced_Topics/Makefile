# Master Makefile for Chapter 13: Advanced Topics

PROJECT_NAME = advanced_topics
SECTIONS = 13.1_Complex_Data_Structures 13.2_Advanced_Pointer_Techniques 13.3_Bit_Manipulation 13.4_Variable_Arguments 13.5_Signal_Handling 13.6_Multi-file_Programs

.PHONY: all build run test clean help $(SECTIONS)

# Default target
all: build

# Build all sections
build:
	@echo "Building Chapter 13: Advanced Topics"
	@echo "====================================="
	@for section in $(SECTIONS); do \
		echo "Building $$section..."; \
		$(MAKE) -C $$section build || exit 1; \
	done
	@echo "All sections built successfully"

# Run all section demos
run:
	@echo "Running Chapter 13: Advanced Topics Demos"
	@echo "=========================================="
	@for section in $(SECTIONS); do \
		echo ""; \
		echo "Running $$section demo..."; \
		echo "----------------------------------------"; \
		$(MAKE) -C $$section run || exit 1; \
		echo ""; \
	done
	@echo "All demos completed successfully"

# Test all sections
test: build
	@echo "Testing Chapter 13: Advanced Topics"
	@echo "==================================="
	@for section in $(SECTIONS); do \
		echo "Testing $$section..."; \
		$(MAKE) -C $$section run > /dev/null 2>&1 && echo "  ✓ $$section passed" || echo "  ✗ $$section failed"; \
	done

# Clean all sections
clean:
	@echo "Cleaning Chapter 13: Advanced Topics"
	@echo "===================================="
	@for section in $(SECTIONS); do \
		echo "Cleaning $$section..."; \
		$(MAKE) -C $$section clean; \
	done
	@echo "All sections cleaned"

# Individual section targets
13.1_Complex_Data_Structures:
	@echo "Building and running Complex Data Structures..."
	$(MAKE) -C $@ run

13.2_Advanced_Pointer_Techniques:
	@echo "Building and running Advanced Pointer Techniques..."
	$(MAKE) -C $@ run

13.3_Bit_Manipulation:
	@echo "Building and running Bit Manipulation..."
	$(MAKE) -C $@ run

13.4_Variable_Arguments:
	@echo "Building and running Variable Arguments..."
	$(MAKE) -C $@ run

13.5_Signal_Handling:
	@echo "Building and running Signal Handling..."
	$(MAKE) -C $@ run

13.6_Multi-file_Programs:
	@echo "Building and running Multi-file Programs..."
	$(MAKE) -C $@ run

# Debug builds for all sections
debug:
	@echo "Building Chapter 13 with debug flags"
	@echo "===================================="
	@for section in $(SECTIONS); do \
		echo "Debug building $$section..."; \
		$(MAKE) -C $$section debug || exit 1; \
	done

# Help target
help:
	@echo "Chapter 13: Advanced Topics - Master Makefile"
	@echo "=============================================="
	@echo "Available targets:"
	@echo "  all     - Build all sections (default)"
	@echo "  build   - Same as 'all'"
	@echo "  run     - Build and run all section demos"
	@echo "  test    - Build and test all sections"
	@echo "  debug   - Build all sections with debug flags"
	@echo "  clean   - Clean all sections"
	@echo "  help    - Show this help message"
	@echo ""
	@echo "Individual section targets:"
	@echo "  13.1_Complex_Data_Structures    - Complex data structures demo"
	@echo "  13.2_Advanced_Pointer_Techniques - Advanced pointer techniques demo"
	@echo "  13.3_Bit_Manipulation          - Bit manipulation demo"
	@echo "  13.4_Variable_Arguments         - Variable arguments demo"
	@echo "  13.5_Signal_Handling           - Signal handling demo"
	@echo "  13.6_Multi-file_Programs       - Multi-file programs demo"
	@echo ""
	@echo "Examples:"
	@echo "  make run                        # Run all demos"
	@echo "  make 13.1_Complex_Data_Structures # Run specific demo"
	@echo "  make clean                      # Clean all build artifacts"

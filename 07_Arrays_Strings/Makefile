# Master Makefile for Chapter 7: Arrays & Strings
# Builds and runs all sections in the chapter

# Section directories
SECTION_7_1 = 7.1_Arrays
SECTION_7_2 = 7.2_Multi_dimensional_Arrays
SECTION_7_3 = 7.3_Strings
SECTION_7_4 = 7.4_String_Functions

# All sections
SECTIONS = $(SECTION_7_1) $(SECTION_7_2) $(SECTION_7_3) $(SECTION_7_4)

# Default target - build all sections
all: build-all

# Build all sections
build-all:
	@echo "Building Chapter 7: Arrays & Strings..."
	@for section in $(SECTIONS); do \
		echo "Building $$section..."; \
		$(MAKE) -C $$section all; \
	done
	@echo "Chapter 7 build complete!"

# Run all demos
run-all:
	@echo "Running Chapter 7: Arrays & Strings Demos..."
	@echo "=============================================="
	@echo
	@echo "Section 7.1: Arrays"
	@echo "-------------------"
	@$(MAKE) -C $(SECTION_7_1) run
	@echo
	@echo "Section 7.2: Multi-dimensional Arrays"
	@echo "-------------------------------------"
	@$(MAKE) -C $(SECTION_7_2) run
	@echo
	@echo "Section 7.3: Strings"
	@echo "--------------------"
	@$(MAKE) -C $(SECTION_7_3) run
	@echo
	@echo "Section 7.4: String Functions"
	@echo "-----------------------------"
	@$(MAKE) -C $(SECTION_7_4) run
	@echo
	@echo "All Chapter 7 demos completed!"

# Individual section targets
section-7.1:
	@echo "Running Section 7.1: Arrays"
	@$(MAKE) -C $(SECTION_7_1) run

section-7.2:
	@echo "Running Section 7.2: Multi-dimensional Arrays"
	@$(MAKE) -C $(SECTION_7_2) run

section-7.3:
	@echo "Running Section 7.3: Strings"
	@$(MAKE) -C $(SECTION_7_3) run

section-7.4:
	@echo "Running Section 7.4: String Functions"
	@$(MAKE) -C $(SECTION_7_4) run

# Clean all sections
clean:
	@echo "Cleaning Chapter 7: Arrays & Strings..."
	@for section in $(SECTIONS); do \
		echo "Cleaning $$section..."; \
		$(MAKE) -C $$section clean; \
	done
	@echo "Chapter 7 cleanup complete!"

# Test all sections (build and run)
test: build-all run-all

# Help target
help:
	@echo "Chapter 7: Arrays & Strings - Available targets:"
	@echo "  all         - Build all sections"
	@echo "  build-all   - Build all sections"
	@echo "  run-all     - Run all section demos"
	@echo "  test        - Build and run all sections"
	@echo "  section-7.1 - Run Arrays demo"
	@echo "  section-7.2 - Run Multi-dimensional Arrays demo"
	@echo "  section-7.3 - Run Strings demo"
	@echo "  section-7.4 - Run String Functions demo"
	@echo "  clean       - Clean all sections"
	@echo "  help        - Show this help message"

# Phony targets
.PHONY: all build-all run-all section-7.1 section-7.2 section-7.3 section-7.4 clean test help

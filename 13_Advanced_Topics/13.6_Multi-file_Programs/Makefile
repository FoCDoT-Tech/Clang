# Makefile for Multi-file Program Demo

# Project configuration
PROJECT_NAME = multifile_demo
VERSION = 1.0.0

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
LIBDIR = lib

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g -I$(INCDIR)
LDFLAGS = -L$(LIBDIR)
LIBS = -lm

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/$(PROJECT_NAME)

# Library files (exclude main.c)
LIB_SOURCES = $(filter-out $(SRCDIR)/main.c, $(SOURCES))
LIB_OBJECTS = $(LIB_SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
STATIC_LIB = $(LIBDIR)/lib$(PROJECT_NAME).a

.PHONY: all build run clean libs help directories

# Default target
all: directories $(TARGET)

# Create directories
directories:
	@mkdir -p $(OBJDIR) $(BINDIR) $(LIBDIR)

# Main executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) $(LIBS)

# Object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Static library
$(STATIC_LIB): $(LIB_OBJECTS)
	ar rcs $@ $^

# Build libraries
libs: directories $(STATIC_LIB)

# Run the program
run: $(TARGET)
	@echo "Running Multi-file Program Demo..."
	@echo "=================================="
	./$(TARGET)
	@echo ""
	@echo "Generated files:"
	@if [ -f demo.log ]; then echo "  demo.log - Log file created"; fi

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(BINDIR) $(LIBDIR) demo.log
	@echo "Cleaned build artifacts and generated files"

# Help target
help:
	@echo "Multi-file Program Demo Makefile"
	@echo "================================"
	@echo "Available targets:"
	@echo "  all       - Build the main executable (default)"
	@echo "  build     - Same as 'all'"
	@echo "  run       - Build and run the demo"
	@echo "  libs      - Build static library"
	@echo "  clean     - Remove build artifacts and generated files"
	@echo "  help      - Show this help message"
	@echo ""
	@echo "Project structure:"
	@echo "  $(SRCDIR)/     - Source files (.c)"
	@echo "  $(INCDIR)/     - Header files (.h)"
	@echo "  $(OBJDIR)/     - Object files (.o)"
	@echo "  $(BINDIR)/     - Executable files"
	@echo "  $(LIBDIR)/     - Library files"

# Build target (alias for all)
build: all

# Dependencies (automatically generated)
-include $(OBJECTS:.o=.d)

# Generate dependency files
$(OBJDIR)/%.d: $(SRCDIR)/%.c | directories
	@$(CC) $(CFLAGS) -MM -MT $(@:.d=.o) $< > $@

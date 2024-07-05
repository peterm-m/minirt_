# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                                                  #
#                                                                              #
#    By: pedromar <pedromar@student.42madrid.com                               #
#                                                                              #
#    Created: 2024/05/13 17:51:17 by pedromar                                  #
#    Updated: 2024/07/05 19:18:05 by pedromar                                  #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME := miniRT

BINARY := miniRT

PROJECT_PATH := ../$(PROJECT_NAME)

# Gets the Operating system name
OS := $(shell uname -s)

# Default shell
SHELL := bash

# Color definition for print purpose
BROWN := \e[0;33m
BLUE := \e[1;34m
END_COLOR := \e[0m

# Source code directory structure
BINDIR := .
LOGDIR := log
BUILDDIR := .build
TESTDIR := .test
LIBDIR := ./lib
INCDIR := ./include

SRCDIR := src
# Defines the C Compiler
CC := gcc

WARNS := -Wall -Wextra -fsanitize=undefined,address,leak #-Werror -pedantic

# Flags for compiling
CFLAGS := $(WARNS) # -O3

# Debug options
DEBUG := -g3

# Dependency libraries
LIBS := -lXext -lX11 -lm \
	-I$(INCDIR) \
	-I$(LIBDIR)/libft -L$(LIBDIR)/libft -lft \
	-I$(LIBDIR)/vector -L$(LIBDIR)/vector -lvector \
	-I$(LIBDIR)/minilibx-linux -L$(LIBDIR)/minilibx-linux -lmlx \

# %.o file names
NAMES := $(notdir $(basename $(wildcard $(SRCDIR)/*.c)))

OBJECTS :=$(patsubst %,$(BUILDDIR)/%.o,$(NAMES))

#
# COMPILATION RULES
#

default: all

# Rule for link and generate the binary file

all: libs project

project: $(OBJECTS)
	@echo -en "$(BROWN)LD $(END_COLOR)";
	$(CC) -o $(BINDIR)/$(BINARY) $+ $(DEBUG) $(CFLAGS) $(LIBS)
	@echo -en "\n--\nBinary file placed at" \
			  "$(BROWN)$(BINDIR)/$(BINARY)$(END_COLOR)\n";

libs:
	@echo -e "$(BROWN)LIB: libft$(END_COLOR)";
	@make --silent -C $(LIBDIR)/libft
	@echo -e "$(BROWN)LIB: vector$(END_COLOR)";
	@make --silent -C $(LIBDIR)/vector
	@echo -e "$(BROWN)LIB: minilibx-linux$(END_COLOR)";
	@make --silent -C $(LIBDIR)/minilibx-linux

# Rule for object binaries compilation
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(BUILDDIR)
	@echo -en "$(BROWN)CC $(END_COLOR)";
	$(CC) -c $^ -o $@ $(DEBUG) $(CFLAGS) $(LIBS)

# Rule for run valgrind tool
valgrind:
	valgrind \
		--track-origins=yes --leak-check=full \
		--leak-resolution=high --log-file=$(LOGDIR)/$@.log \
		$(BINDIR)/$(BINARY)
	@echo -en "\nCheck the log file: $(LOGDIR)/$@.log\n"

profiling:
# https://valgrind.org/docs/manual/cl-manual.html
# https://developer.mantidproject.org/ProfilingWithValgrind.html
	valgrind --tool=callgrind --callgrind-out-file=$(LOGDIR)/callgrind.out \
	--dump-instr=yes --simulate-cache=yes --collect-jumps=yes \
	--log-file=$(LOGDIR)/$@.log $(BINDIR)/$(BINARY) 
	
	@echo -en "\nCheck the log file: $(LOGDIR)/$@.log\n"

# Compile tests and run the test binary
tests: libs
	@echo -en "$(BROWN)CC $(END_COLOR)";
	$(CC) $(TESTDIR)/main.c $(TESTDIR)/munit.c  src/intersections.c -o $(TESTDIR)/$(TEST_BINARY) $(DEBUG) $(CFLAGS) $(LIBS) $(TEST_LIBS)
	@echo -en "$(BROWN) Running tests: $(END_COLOR)";
	./$(TESTDIR)/$(TEST_BINARY)

# Rule for clean object
clean:
	make -C $(LIBDIR)/libft clean
	make -C $(LIBDIR)/minilibx-linux clean
	make -C $(LIBDIR)/vector clean
	@rm -rvf $(BUILDDIR)/* $(LOGDIR)/*;

# Rule for clean object, libs and binary
fclean: clean
	make -C $(LIBDIR)/libft fclean
	make -C $(LIBDIR)/minilibx-linux clean
	make -C $(LIBDIR)/vector fclean
	@rm -rvf $(BUILDDIR)/* $(LOGDIR)/*
	@rm -vf $(BINDIR)/$(BINARY) ./$(TESTDIR)/$(TEST_BINARY)

# Rule for re-make 
re: fclean all

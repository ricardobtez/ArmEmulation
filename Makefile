#!/usr/bin/make

# Arm Emulation Makefile.
# Author: Ricardo Benitez
# For information about licensing, see LICENSE.

# Setting compiler to GCC
CC = gcc
# Executable name
EX_NAME = armemu

# Compiler warnings
CFLAGS = -Wall
CFLAGS += -Wextra
CFLAGS += -Wshadow  # If one variable shadows one from parent context
CFLAGS += -Wcast-align  # Potential performance problem casts
CFLAGS += -Wunused  # Warn on anything unused
CFLAGS += -Wpedantic  # Warn if non-standard C is used
CFLAGS += -Wconversion  # Warn on type conversions that may lose data
CFLAGS += -Wsign-conversion # Warn on sign conversions
CFLAGS += -Wnull-dereference  # Warn if a null dereference is detected
CFLAGS += -Wdouble-promotion  # Warn if float is implicitly promoted to double
CFLAGS += -Wformat=2  # Warn on security issues on functions that form output (e.g. printf)
CFLAGS += -Wmisleading-indentation  # Warn if indentation implies blocks that do not exist
CFLAGS += -Wduplicated-cond  # Warn if if-else conditions has duplicated conditions
CFLAGS += -Wduplicated-branches # Warn if if-else branches have duplicated code
CFLAGS += -Wlogical-op  # Warn if logical operations is used where bitwise might be intended
#CFLAGS += -Wuseless-cast  # Warn if cast to the same type

INC = -iquote inc/
INC += -iquote src/inc/
INC_TEST = -iquote test/inc/
ODIR = obj
SDIR = src
TDIR = test

# Object files to compile
_OBJS = Conditionalbranch.o
_OBJS += Cpu.o
_OBJS += Dataprocessing.o
_OBJS += Loadstoresingle.o
_OBJS += Miscelanious.o
_OBJS += Shift.o
_OBJS += Specialdata.o

_OBJS_TEST = test_cpu.o
_OBJS_TEST += test_shift.o

_OBJS_MAIN = main.o
_OBJS_MAIN_TEST = test_main.o

OBJS_DEBUG = $(patsubst %,$(ODIR)/debug/%,$(_OBJS))
OBJS_DEBUG_MAIN = $(patsubst %,$(ODIR)/debug/%,$(_OBJS_MAIN))

OBJS_RELEASE = $(addprefix $(ODIR)/release/,$(_OBJS))
OBJS_RELEASE_MAIN = $(addprefix $(ODIR)/release/,$(_OBJS_MAIN))

OBJS_TEST = $(addprefix $(ODIR)/test/,$(_OBJS_TEST))
OBJS_TEST += $(addprefix $(ODIR)/test/,$(_OBJS_MAIN_TEST))

all : release

release : release_obj release_bin
	@echo
	@echo \******************************
	@echo \* Finished target $@
	@echo \******************************

release_obj : init init_release $(OBJS_RELEASE) init_bin_release

release_bin : $(OBJS_RELEASE_MAIN)
	@$(CC) $(OBJS_RELEASE) $(OBJS_RELEASE_MAIN) -o bin/release/$(EX_NAME)

debug : debug_obj debug_main
	@echo
	@echo \******************************
	@echo \* Finished target $@
	@echo \******************************

debug_obj : init init_debug $(OBJS_DEBUG) init_bin_debug

debug_main : $(OBJS_DEBUG_MAIN)
	@$(CC) -g $(OBJS_DEBUG) $(OBJS_DEBUG_MAIN) -o bin/debug/$(EX_NAME)

test: debug_obj init_test $(OBJS_TEST) init_bin_test
	@echo
	@echo \******************************
	@echo \* Start of unit testing
	@echo \******************************
	@echo
	@$(CC) $(OBJS_TEST) $(OBJS_DEBUG) -lcmocka -o bin/test/$(EX_NAME)
	@./bin/test/$(EX_NAME)

# Define a pattern rule that compiles every .c file into a .o file in its destination
#$(ODIR)/%.o: $(SDIR)/%.c
#	@echo this is not being run?
#	@$(CC) -c $(CFLAGS) $(INC) $(CPPFLAGS) $< -o $@

# Define a pattern rule that compiles every .c file into a .o file in its
# destination in the debug folder
$(ODIR)/debug/%.o : CPPFLAGS += -DDEBUG
$(ODIR)/debug/%.o : $(SDIR)/%.c
	$(CC) -g -c $(CFLAGS) $(INC) $(CPPFLAGS) $< -o $@

# Define a pattern rule that compiles every .c file into a .o file in its
# destination in the release folder
$(ODIR)/release/%.o : CPPFLAGS += -DRELEASE
$(ODIR)/release/%.o : $(SDIR)/%.c
	$(CC) -c $(CFLAGS) $(INC) $(CPPFLAGS) $< -o $@

# Define a pattern rule that compiles every .c file into a .o file in its
# destination in the release folder
$(ODIR)/test/%.o : CPPFLAGS += -DDEBUG
$(ODIR)/test/%.o : $(TDIR)/%.c
	$(CC) -c $(CFLAGS) $(INC) $(INC_TEST) $(CPPFLAGS) $< -o $@

.PHONY: clean

init :
	@if [ ! -d "$(ODIR)" ]; then \
		mkdir $(ODIR); \
	fi

init_debug : init_bin
	@if [ ! -d "$(ODIR)/debug" ]; then \
		mkdir $(ODIR)/debug; \
	fi

init_release :
	@if [ ! -d "$(ODIR)/release" ]; then \
		mkdir $(ODIR)/release; \
	fi

init_bin_release : init_bin
	@if [ ! -d bin/release ]; then \
		mkdir bin/release; \
	fi

init_bin_debug : init_bin
	@if [ ! -d bin/debug ]; then \
		mkdir bin/debug; \
	fi

init_bin :
	@if [ ! -d bin ]; then \
		mkdir bin; \
	fi

init_test :
	@if [ ! -d "$(ODIR)/test" ]; then \
		mkdir $(ODIR)/test; \
	fi

init_bin_test : init_bin
	@if [ ! -d bin/test ]; then \
		mkdir bin/test; \
	fi

help :
	@echo Usage make [options]
	@echo Options:
	@echo 	-D={release,debug}		Compile with the release type specified
	@echo 
	@echo For more information on the make commands, see the README.md file


clean :
	@echo Cleaning this project
	rm -rf ./$(ODIR)
	rm -rf ./bin


#!/usr/bin/make

# Arm Emulation Makefile.
# Author: Ricardo Benitez
# For information about licensing, see LICENSE.

# Setting compiler to GCC
CC = gcc

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
ODIR = obj
SDIR = src

_OBJS = Conditionalbranch.o Cpu.o Dataprocessing.o Loadstoresingle.o Miscelanious.o \
        Shift.o Specialdata.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

# Define a pattern rule that compiles every .c file into a .o file in its destination
$(ODIR)/%.o: $(SDIR)/%.c 
	@$(CC) -c $(CFLAGS) $(INC) $(CPPFLAGS) $< -o $@
# List of all the available targets
TARGETS = all debug release test


all : init $(OBJS)
	@echo Target: $@

.PHONY: clean

init :
	mkdir $(ODIR)

clean :
	@echo Cleaning this project
	rm -f $(ODIR)/*.o
	rmdir $(ODIR)


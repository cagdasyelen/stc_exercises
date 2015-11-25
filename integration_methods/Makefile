# Files
EXEC := integrate
SRC  := $(wildcard *.c)
OBJ  := $(patsubst %.c,%.o,$(SRC))
# Options
CC      := gcc
CFLAGS  := -O3
LDFLAGS := -L/usr/lib
LDLIBS  := -lm
# Rules
$(EXEC): $(OBJ)
		$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
%.o: %.c
		$(CC) $(CFLAGS) -c $<
prog.o routines.o: parameters.h
# Useful phony targets
.PHONY: clobber clean neat echo
clobber: clean
		$(RM) $(EXEC)
clean: neat
		$(RM) $(OBJ)
neat:
		$(RM) *~ .*~
echo:
		@echo $(OBJ)

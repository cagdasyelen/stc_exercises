# Files
EXEC := operator
SRC  := $(wildcard *.c)
OBJ  := $(patsubst %.c,%.o,$(SRC))
# Options
CC      := gcc
CFLAGS  := -O3
LDFLAGS := -L${MKLROOT}/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_sequential -lpthread -lm
LDLIBS  := -lm
# Rules
$(EXEC): $(OBJ)
		$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
%.o: %.c
		$(CC) $(CFLAGS) -c $<
linear_op.o routines.o: parameters.h
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

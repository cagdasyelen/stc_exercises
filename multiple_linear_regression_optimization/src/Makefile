# Files
CC :=gcc
LDFLAGS := -L/usr/lib
LDLIBS  := -lm


all: ../bin/prog ../bin/plot_all_cost ../bin/plot_gradient_cost

../bin/prog:prog.c
		$(CC) -O3 $(LFDFLAGS) $(LDLIBS) prog.c routines.c -o ../bin/prog

../bin/plot_all_cost:plot_all_cost.c
		$(CC) -O3 $(LFDFLAGS) $(LDLIBS) plot_all_cost.c routines.c -o ../bin/plot_all_cost

../bin/plot_gradient_cost:plot_gradient_cost.c
		$(CC) -O3 $(LFDFLAGS) $(LDLIBS) plot_gradient_cost.c routines.c -o ../bin/plot_gradient_cost

# Useful phony targets
.PHONY: clobber clean
clobber: clean
		$(RM)  *.o ../bin/prog ../bin/plot_all_cost ../bin/plot_gradient_cost


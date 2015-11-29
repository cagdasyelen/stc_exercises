# Files
CC :=gcc
LDFLAGS := -L/usr/lib
LDLIBS  := -lm


all: rand_uniform rand_exp rand_normal pi integral_unbiased integral_importance

rand_uniform:rand_uniform.c
		$(CC) $(LFDFLAGS) $(LDLIBS) rand_uniform.c -o rand_uniform

rand_exp:rand_exp.c
		$(CC) $(LFDFLAGS) $(LDLIBS) rand_exp.c -o rand_exp

rand_normal:rand_normal.c
		$(CC) $(LFDFLAGS) $(LDLIBS) rand_normal.c -o rand_normal

pi:pi.c
		$(CC) $(LFDFLAGS) $(LDLIBS) pi.c -o pi

integral_unbiased:integral_unbiased.c
		$(CC) $(LFDFLAGS) $(LDLIBS) integral_unbiased.c -o integral_unbiased

integral_importance:integral_importance.c
		$(CC) $(LFDFLAGS) $(LDLIBS) integral_importance.c -o integral_importance


# Useful phony targets
.PHONY: clobber clean
clobber: clean
		$(RM)  *.dat rand_uniform rand_exp rand_normal pi integral_unbiased integral_importance


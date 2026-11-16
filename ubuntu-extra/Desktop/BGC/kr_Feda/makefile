CFLAGS=-mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs
OPT=-O3

all: a.out 

%.o: %.c
	gcc -c $(CFLAGS) $(OPT) $<

%.out: %.o
	gcc $(OPT) $^ -o $@ -lm

clean:
	rm *.o*

funcs.o: funcs.c funcs.h

a.o: a.c funcs.h
a.out: a.o funcs.o


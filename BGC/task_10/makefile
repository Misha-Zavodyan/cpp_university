CFLAGS=-mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs
OPT=-O3

all: a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out a09.out a10.out

%.o: %.c
	gcc -c $(CFLAGS) $(OPT) $<

%.out: %.o
	gcc $(OPT) $^ -o $@ -lm

clean:
	rm *.o*

funcs.o: funcs.c funcs.h

tasks.o: tasks.c tasks.h

a01.o: a01.c tasks.h funcs.h
a01.out: a01.o tasks.o funcs.o

a02.o: a02.c tasks.h funcs.h
a02.out: a02.o tasks.o funcs.o

a03.o: a03.c tasks.h funcs.h
a03.out: a03.o tasks.o funcs.o

a04.o: a04.c tasks.h funcs.h
a04.out: a04.o tasks.o funcs.o

a05.o: a05.c tasks.h funcs.h
a05.out: a05.o tasks.o funcs.o

a06.o: a06.c tasks.h funcs.h
a06.out: a06.o tasks.o funcs.o

a07.o: a07.c tasks.h funcs.h
a07.out: a07.o tasks.o funcs.o


a08.o: a08.c tasks.h funcs.h
a08.out: a08.o tasks.o funcs.o

a09.o: a09.c tasks.h funcs.h
a09.out: a09.o tasks.o funcs.o

a10.o: a10.c tasks.h funcs.h
a10.out: a10.o tasks.o funcs.o

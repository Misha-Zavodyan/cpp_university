all: a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out a09.out a10.out

OPTS = -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs -O3

a01.out: task01.o io_array.o sol.o
	gcc $(OPTS) task01.o io_array.o sol.o -o a01.out

task01.o: task01.c io_array.h  io_status.h sol.h
	gcc -c $(OPTS) task01.c

io_array.o: io_array.c io_array.h
	gcc -c $(OPTS) io_array.c

a02.out: task02.o io_array.o  sol.o
	gcc $(OPTS) task02.o io_array.o sol.o -o a02.out

task02.o: task02.c io_array.h  io_status.h sol.h
	gcc -c $(OPTS) task02.c

a03.out: task03.o io_array.o  sol.o
	gcc $(OPTS) task03.o io_array.o sol.o -o a03.out

task03.o: task03.c io_array.h  io_status.h
	gcc -c $(OPTS) task03.c

a04.out: task04.o io_array.o  sol.o
	gcc $(OPTS) task04.o io_array.o sol.o -o a04.out

task04.o: task04.c io_array.h  io_status.h sol.h
	gcc -c $(OPTS) task04.c

a05.out: task05.o io_array.o  sol.o
	gcc $(OPTS) task05.o io_array.o sol.o -o a05.out

task05.o: task05.c io_array.h  io_status.h sol.h
	gcc -c $(OPTS) task05.c

a06.out: task06.o io_array.o  sol.o
	gcc $(OPTS) task06.o io_array.o  sol.o -o a06.out

task06.o: task06.c io_array.h  io_status.h sol.h
	gcc -c $(OPTS) task06.c

a07.out: task07.o io_array.o  sol.o
	gcc $(OPTS) task07.o io_array.o  sol.o -o a07.out

task07.o: task07.c io_array.h  io_status.h sol.h
	gcc -c $(OPTS) task07.c

a08.out: task08.o io_array.o  sol.o
	gcc $(OPTS) task08.o io_array.o sol.o -o a08.out

task08.o: task08.c io_array.h  io_status.h sol.h
	gcc -c $(OPTS) task08.c

a09.out: task09.o io_array.o  sol.o
	gcc $(OPTS) task09.o io_array.o sol.o -o a09.out

task09.o: task09.c io_array.h  io_status.h sol.h
	gcc -c $(OPTS) task09.c

a10.out: task10.o io_array.o  sol.o
	gcc $(OPTS) task10.o io_array.o sol.o -o a10.out

task10.o: task10.c io_array.h  io_status.h sol.h
	gcc -c $(OPTS) task10.c

clean:
	rm -f *.o all

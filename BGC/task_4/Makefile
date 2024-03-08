FLAGS= -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Wcast-qual -Wno-suggest-attribute=format

all: a.out

a.out: problem_10.o array_io.o
	gcc problem_10.o array_io.o -o a.out

problem_10.o: problem_10.o array_io.h
	gcc -c $(FLAGS) problem_10.c -o problem_10.o

array_io.o: array_io.c array_io.h
	gcc -c $(FLAGS) array_io.c -o array_io.o
	
clean:
	rm -f *.o *.out

# FLAGS= -O3 -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Wcast-qual -Wno-suggest-attribute=format

#FLAGS= -g -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Wcast-qual -Wno-suggest-attribute=format


all: a.out

a.out: problem_1.o array_io.o
	gcc problem_1.o array_io.o -o a.out -lm

problem_1.o: problem_1.o array_io.h
	gcc -c $(FLAGS) problem_1.c -o problem_1.o

array_io.o: array_io.c array_io.h
	gcc -c $(FLAGS) array_io.c -o array_io.o
	
clean:
	rm -f *.o *.out

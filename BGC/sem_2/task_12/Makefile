FLAGS= -O3 -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Wcast-qual -Wno-suggest-attribute=format

#FLAGS= -g -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Wcast-qual -Wno-suggest-attribute=format


all: a.out

a.out: problem_10.o find_root_io.o
	gcc problem_10.o find_root_io.o -o a.out -lm

problem_10.o: problem_10.o find_root_io.h 
	gcc -c $(FLAGS) problem_10.c -o problem_10.o

find_root_io.o: find_root_io.c find_root_io.h
	gcc -c $(FLAGS) find_root_io.c -o find_root_io.o


clean:
	rm -f *.o *.out

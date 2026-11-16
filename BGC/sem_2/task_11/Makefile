FLAGS= -O3 -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Wcast-qual -Wno-suggest-attribute=format

#FLAGS= -g -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Wcast-qual -Wno-suggest-attribute=format


all: a.out

a.out: problem_12.o find_root_io.o funk_io.o
	gcc problem_12.o find_root_io.o funk_io.o -o a.out -lm

problem_12.o: problem_12.o find_root_io.h funk_io.h
	gcc -c $(FLAGS) problem_12.c -o problem_12.o

find_root_io.o: find_root_io.c find_root_io.h
	gcc -c $(FLAGS) find_root_io.c -o find_root_io.o

funk_io.o: funk_io.c funk_io.h find_root_io.h
	gcc -c $(FLAGS) funk_io.c -o funk_io.o

clean:
	rm -f *.o *.out

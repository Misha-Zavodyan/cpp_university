FLAGS= -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Wcast-qual -Wno-suggest-attribute=format

all: a.out

a.out: matrix_mult_block.o array_io.o
	gcc matrix_mult_block.o array_io.o -o a.out

matrix_mult_block.o: matrix_mult_block.o array_io.h
	gcc -c $(FLAGS) matrix_mult_block.c -o matrix_mult_block.o

array_io.o: array_io.c array_io.h
	gcc -c $(FLAGS) array_io.c -o array_io.o
	
clean:
	rm -f *.o *.out

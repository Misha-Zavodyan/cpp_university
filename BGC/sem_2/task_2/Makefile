FLAGS=-O3 -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Wcast-qual -Wno-suggest-attribute=format -fsanitize=leak

all: a.out

a.out: main.o
	gcc main.o -o a.out -lasan 
	
main.o: main.c
	gcc -c $(FLAGS)  main.c -o main.o
	
clean:
	rm -f *.o *.out

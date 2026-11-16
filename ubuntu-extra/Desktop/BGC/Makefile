all: a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out a09.out a10.out 
a01.out: problem_1.o array_io.o
	gcc problem_1.o array_io.o -o a01.out -lm
	
problem_1.o: problem_1.c array_io.h
	gcc -c  problem_1.c -o problem_1.o

a02.out: problem_2.o array_io.o
	gcc problem_2.o array_io.o -o a02.out -lm
	
problem_2.o: problem_2.c array_io.h
	gcc -c  problem_2.c -o problem_2.o
	
a03.out: problem_3.o array_io.o
	gcc problem_3.o array_io.o -o a03.out -lm
	
problem_3.o: problem_3.c array_io.h
	gcc -c  problem_3.c -o problem_3.o
	
a04.out: problem_4.o array_io.o
	gcc problem_4.o array_io.o -o a04.out -lm
	
problem_4.o: problem_4.c array_io.h
	gcc -c  problem_4.c -o problem_4.o

a05.out: problem_5.o array_io.o
	gcc problem_5.o array_io.o -o a05.out -lm
	
problem_5.o: problem_5.c array_io.h
	gcc -c  problem_5.c -o problem_5.o
	
a06.out: problem_6.o array_io.o
	gcc problem_6.o array_io.o -o a06.out -lm
	
problem_6.o: problem_6.c array_io.h
	gcc -c  problem_6.c -o problem_6.o
	
a07.out: problem_7.o array_io.o
	gcc problem_7.o array_io.o -o a07.out -lm
	
problem_7.o: problem_7.c array_io.h
	gcc -c  problem_7.c -o problem_7.o
	
a08.out: problem_8.o array_io.o
	gcc problem_8.o array_io.o -o a08.out -lm
	
problem_8.o: problem_8.c array_io.h
	gcc -c  problem_8.c -o problem_8.o

a09.out: problem_9.o array_io.o
	gcc problem_9.o array_io.o -o a09.out -lm
	
problem_9.o: problem_9.c array_io.h
	gcc -c  problem_9.c -o problem_9.o
	
a10.out: problem_10.o array_io.o
	gcc problem_10.o array_io.o -o a10.out -lm
	
problem_10.o: problem_10.c array_io.h
	gcc -c  problem_10.c -o problem_10.o
	
	

array_io.o: array_io.c array_io.h
	gcc -c array_io.c -o array_io.o
	
clean:
	rm -f *.o *.out

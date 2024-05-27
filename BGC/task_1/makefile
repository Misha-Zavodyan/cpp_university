all: a01.out a02.out a03.out a04.out a05.out

OPTS = -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs -O3 

a01.out: task01.o sol.o
	gcc $(OPTS) task01.o sol.o  -o a01.out

task01.o: task01.c sol.h io_status.h  
	gcc -c $(OPTS) task01.c
	
my_string.o: sol.c sol.h io_status.h 
	gcc -c $(OPTS) sol.c

a02.out: task02.o sol.o
	gcc $(OPTS) task02.o  sol.o  -o a02.out

task02.o: task02.c sol.h io_status.h  
	gcc -c $(OPTS) task02.c
	
a03.out: task03.o sol.o
	gcc $(OPTS) task03.o  sol.o  -o a03.out

task03.o: task03.c sol.h io_status.h  
	gcc -c $(OPTS) task03.c
	
a04.out: task04.o sol.o
	gcc $(OPTS) task04.o  sol.o  -o a04.out

task04.o: task04.c sol.h io_status.h  
	gcc -c $(OPTS) task04.c		
	
a05.out: task05.o sol.o
	gcc $(OPTS) task05.o sol.o -o a05.out

task05.o: task05.c sol.h io_status.h  
	gcc -c $(OPTS) task05.c

clean:
	rm -f *.o all

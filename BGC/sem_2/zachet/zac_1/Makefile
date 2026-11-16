 FLAGS= -O3 -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs

#FLAGS= -g 


all: a.out

a.out: kr.o  
	gcc kr.o   -o a.out -lm

kr.o: 
	gcc -c $(FLAGS) kr.c -o kr.o

clean:
	rm -f *.o *.out

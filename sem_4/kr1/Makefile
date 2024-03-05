FLAGS= -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

all: a.out

a.out: main.o CComplexVector.o
	g++ main.o CComplexVector.o -o a.out
	
main.o: main.cpp CComplexVector.h
	g++ -c $(FLAGS) main.cpp -o main.o

CComplexVector.o: CComplexVector.cpp CComplexVector.h
	g++ -c $(FLAGS) CComplexVector.cpp -o CComplexVector.o
	
clean:
	rm -f *.o *.out

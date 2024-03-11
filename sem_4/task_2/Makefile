FLAGS= 

a.out: main.o CComplexVector.o
	g++ main.o CComplexVector.o 
	
main.o: main.cpp CComplexVector.h
	g++ -c $(FLAGS) main.cpp -o main.o

CComplexVector.o: CComplexVector.cpp CComplexVector.h
	g++ -c $(FLAGS) CComplexVector.cpp -o CComplexVector.o
	
clean:
	rm -f *.o *.out

pr: main.o
	g++ main.o -o pr
main.o: main.cpp class.h
	g++ -g -Wall -Wextra -Werror -pedantic -std=c++14 -c main.cpp
clean:
	rm -f *.o pr*

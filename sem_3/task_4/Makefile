pr: main.o class.o
	g++ main.o class.o -o pr
main.o: main.cpp class.h
	g++ -g -Wall -Wextra -Werror -pedantic -std=c++14 -c main.cpp
class.o: class.cpp class.h
	g++ -g -Wall -Wextra -Werror -pedantic -std=c++14 -c class.cpp
clean:
	rm -f *.o pr*
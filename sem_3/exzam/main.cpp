#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include "vector.cpp"
int main()
{
    CVector a(5), b(5), c;
    for (size_t i = 0; i < 5; i++)
        a[i] = i;
    std::cout << a;
    b = a + a;
    std::cout << b;
    std::cout << " c = b+(a+b) ";
    c = b+(a+b);
    std::cout << " c = (a + a) + a";
    c = (a + a) + a;
    std::cout << " c = a + (a + a) ";
    c = a + (a + a);
    std::cout << " c = (a + a) + (a + a) ";
    c = (a + a) + (a + a);
    return 0;
}
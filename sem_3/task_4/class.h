#ifndef DATE_H
#define DATE_H
#define Con 5
#include <iosfwd>
#include <string>
#include <cmath>
#include <cassert>
#include <iostream>
#include <array> 
#include <list>
#include <iterator>
#include <ctime>
using namespace std;


class Darr
{   
  size_t N; 
  list<array<double,Con>> mylist;

  public:
    Darr();
    Darr(size_t M);
    double push_back(double x);
    double insert(double x,size_t k);
    double* operator[](std::size_t i); 
    double size_arr(void);
    double delet(size_t k);
    double resize_arr(size_t M);
    double find(double x, size_t beg = 0,size_t en=0);
    double sort(void); // сортировка с временем gggg
    double print(void);
    friend std::ostream &operator<<(std::ostream &out, Darr &x1);

};
                         
#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

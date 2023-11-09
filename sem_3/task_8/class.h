#ifndef DATE_H
#define DATE_H
#include <iosfwd>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

template<class T> 
class Node{
  public:
    T key;
    Node<T> *left;
    Node<T> *right;
    Node(T value);

};

template<class T> 
class RBtree
{   
  Node<T> *root; 
  size_t t_size;

  public:
    RBtree(T key);
    ~RBtree();
    void delete_tree(Node<T> * curr);
    // double push_back(double x);
    // double insert(double x,size_t k);
    // double* operator[](std::size_t i); 
    // double size_arr(void);
    // double delet(size_t k);
    // double resize_arr(size_t M);
    // double find(double x, size_t beg = 0,size_t en=0);
    // double sort(void); 
    // double print(void);
    // friend std::ostream &operator<<(std::ostream &out, Darr &x1);

};
                         
#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

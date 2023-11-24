#ifndef DATE_H
#define DATE_H
#include <iosfwd>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;


template<class T>
class RBtree
{   
class Node{
  public:
    T key;
    Node  *left;
    Node *right;
    Node(T value);

};
  Node *root; 
  size_t t_size;

  public:
    RBtree(T key);
    ~RBtree();
    void delete_tree(Node * curr);
    // friend std::ostream &operator<<(std::ostream &out, Darr &x1);

};




template<class T> RBtree<T>::Node::Node(T value)
{
  key=value;
  left=nullptr;
  right=nullptr;
}

template<class T> RBtree<T>::RBtree(T key)
{
  root= new Node(key);
}

template<class T> RBtree<T>::~RBtree(){
  delete_tree(root);
}

template<class T> void RBtree<T>::delete_tree(RBtree<T>::Node * curr)
{
    if (curr)
    {
        delete_tree(curr->left);
        delete_tree(curr->right);
        delete curr;
    }
}




#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
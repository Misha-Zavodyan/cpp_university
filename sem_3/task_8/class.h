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
  public:
  Node *root; 
  size_t t_size;

  
    RBtree(T key);
    ~RBtree();
    void delete_tree(Node * curr);
    void insert(Node * curr,T key);
    Node * search(Node * curr,T key);
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

template<class T> void RBtree<T>::insert(RBtree<T>::Node * curr,T key)
{
    if (key<curr->key)
    {
        if(curr->left==nullptr) curr->left=new Node(key);
        else insert(curr->left,key);
    }
    if (key>=curr->key)
    {
        if(curr->right==nullptr) curr->right=new Node(key);
        else insert(curr->right,key);
    }
}

template<class T> RBtree<T>::Node * RBtree<T>::search(RBtree<T>::Node * curr, T key)
{
    if (curr == nullptr) return nullptr; 
    if(curr->key==key) return curr;
    return (key<curr->key)? search(curr->left,key) : search(curr->right,key);   
}

// template<class T> RBtree<T>::Node * RBtree<T>::getMin(RBtree<T>::Node * curr)
// {
//     if (curr == nullptr) return nullptr; 
//     if(curr->left==nullptr) return curr;
//     return getMin(curr->left);   
// }

// template<class T> RBtree<T>::Node * RBtree<T>::getMax(RBtree<T>::Node * curr)
// {
//     if (curr == nullptr) return nullptr; 
//     if(curr->right==nullptr) return curr;
//     return getMax(curr->right);   
}






#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

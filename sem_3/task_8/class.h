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
    Node *left;
    Node *right;
    Node *parent;
    bool color;
    Node(T value);
    Node();
    static Node * nil = static_cast<Node *>(new Node()); 
};
  public:
  Node *root; 


  
    RBtree(T key);
    ~RBtree();
    void delete_tree(Node * curr);
//     void insert(Node * curr,T key);
    void printTree(Node * curr);
    Node * search(Node * curr,T key); 
    Node * getMin(Node * curr); 
    Node * getMax(Node * curr); 
    Node * delet(Node * curr,T key);


};


template<class T> RBtree<T>::Node::Node()
{
  //key=nullptr;
  left=nullptr;
  right=nullptr;
  color=true;
}

template<class T> RBtree<T>::Node::Node(T value)
{
  key=value;
  left=nil;
  right=nil;
  parent=nil;
  color=false;
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

// template<class T> void RBtree<T>::insert(RBtree<T>::Node * curr,T key)
// {
//   RBtree<T>::Node * currentNode = root;
//   RBtree<T>::Node * parent = nil;
//   while(nodeExist(currentNode))
//   {
//     parent = currentNode;
//     if(key<currentNode->key) currentNode=currentNode->left;
//     else currentNode=currentNode->right
//   }
//   RBtree<T>::Node * newNode = Node();
//   createNode(newNode,key);
//   newNode->parent = parent;
//   if(parent==nil) root=newNode;
//   else if (key < parent.key) paretn->left = newNode;
//   else parent->right = newNode;
//   balanceTree(NewNode);//root == tree
// }
// 
// template<class T> void createNode(RBtree<T>::Node * curr, T key){
//     curr->parent=nil;
//     curr->left=nil;
//     curr->right=nil;
//     curr->key=key;
//     curr->color=false;
// }
// template<class T> bool nodeExist(RBtree<T>::Node * curr){
//     return curr!=nil;
// }

template<class T> void RBtree<T>::balanceTree(RBtree<T>::Node * curr){
  RBtree<T>::Node * uncle;
  while(newNode->parent->color ==
}

template<class T> void RBtree<T>::printTree(RBtree<T>::Node * curr)
{
    if(curr==nullptr) return;
    printTree(curr->left);
    cout<<curr->key<<" ";
    printTree(curr->right);
}

template<class T> typename RBtree<T>::Node * RBtree<T>::search(RBtree<T>::Node * curr, T key)
{
    if (curr == nullptr) return nullptr; 
    if(curr->key==key) return curr;
    return (key<curr->key)? search(curr->left,key) : search(curr->right,key);   
}

template<class T> typename RBtree<T>::Node * RBtree<T>::getMin(RBtree<T>::Node * curr)
{
    if (curr == nullptr) return nullptr; 
    if(curr->left==nullptr) return curr;
    return getMin(curr->left);   
}

template<class T>  typename RBtree<T>::Node * RBtree<T>::getMax(RBtree<T>::Node * curr)
{
    if (curr == nullptr) return nullptr; 
    if(curr->right==nullptr) return curr;
    return getMax(curr->right);   
}

template<class T> typename RBtree<T>::Node * RBtree<T>::delet(RBtree<T>::Node * curr, T key)
{
    if (curr == nullptr) return nullptr; 
    else if(key < curr->key) curr->left = delet(curr->left,key);
    else if(key > curr->key) curr->right = delet(curr->right,key);
    else 
    {
      if(curr->left == nullptr || curr->right == nullptr)
          curr=(curr->left==nullptr)?curr->right:curr->left;
      else 
      {
        RBtree<T>::Node * maxInLeft = getMax(curr->left);
        curr->key = maxInLeft->key;
        curr->right = delet(curr->right,maxInLeft->key);
        curr->left = maxInLeft->left;
//         delete maxInLeft;
      }
    }
    return curr;
}








































#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

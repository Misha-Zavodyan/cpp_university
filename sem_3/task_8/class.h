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
    int height;
    bool color;//true==RED, false == BLACK
    Node(T value);
    Node();

};
  public:
    Node *root;
    static Node *nil;

    static Node* setNil(){nil = new Node; return nil;} 

  
    RBtree(T key);
    ~RBtree();
    void delete_tree(Node * curr);
    void updateHeight(Node * curr);
    int getHeight(Node * curr);
    // int getBalance(Node * curr);
    void swap(Node * a,Node * b);
    void rightRotate(Node * curr);
    void leftRotate(Node * curr);
    void createNode(Node * curr, T key);
    bool nodeExist(Node * curr);
    void balanceTree(Node * curr);
    void insert(T key);
    void printTree(Node * curr);
    Node * search(Node * curr,T key); 
    Node * getMin(Node * curr); 
    Node * getMax(Node * curr); 
    Node * delet(Node * curr,T key);


};


template<class T> 
typename RBtree<T>::Node* RBtree<T>::nil = RBtree<T>::setNil();

template<class T> RBtree<T>::Node::Node()
{
  left=nullptr;
  right=nullptr;
  height=0;
  color=true;
}

template<class T> RBtree<T>::Node::Node(T value)
{
  key=value;
  left=nil;
  right=nil;
  parent=nil;
  height=1;
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

template<class T> void RBtree<T>::updateHeight(RBtree<T>::Node * curr){
    curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
}

template<class T> int RBtree<T>::getHeight(RBtree<T>::Node * curr){
    return (curr == nullptr) ? -1: curr->height;
}

// template<class T> int RBtree<T>::getBalance(RBtree<T>::Node * curr){
//     return (curr == nullptr) ? 0 : getHeight(curr->right) - getHeight(curr->left);
// }

template<class T> void RBtree<T>::swap(RBtree<T>::Node * a,RBtree<T>::Node * b){
    T a_key = a->key;
    a->key = b->key;
    b->key = a_key;
}

template<class T> void RBtree<T>::rightRotate(RBtree<T>::Node * curr){
    swap(curr, curr->left);
    RBtree<T>::Node * buffer = curr->right;
    curr->right = curr->left;
    curr->left = curr->right->left;
    curr->right->left = curr->right->right;
    curr->right->right = buffer;
    updateHeight(curr->right);
    updateHeight(curr);
}

template<class T> void RBtree<T>::leftRotate(RBtree<T>::Node * curr){
    swap(curr, curr->left);
    RBtree<T>::Node * buffer = curr->left;
    curr->left = curr->right;
    curr->right = curr->left->right;
    curr->left->right = curr->left->left;
    curr->left->left = buffer;
    updateHeight(curr->left);
    updateHeight(curr);
}


template<class T> void RBtree<T>::insert(T key)
{
  RBtree<T>::Node * currentNode = root;
  RBtree<T>::Node * parent = nil;
  while(nodeExist(currentNode))
  {
    parent = currentNode;
    if(key<currentNode->key) currentNode=currentNode->left;
    else currentNode=currentNode->right;
  }
  RBtree<T>::Node * newNode = new Node();
  createNode(newNode,key);
  newNode->parent = parent;
  if(parent==nil) root=newNode;
  else if (key < parent->key) parent->left = newNode;
  else parent->right = newNode;
  balanceTree(newNode);//root == tree
}

template<class T> void RBtree<T>::createNode(RBtree<T>::Node * curr, T key){
    curr->parent=nil;
    curr->left=nil;
    curr->right=nil;
    curr->key=key;
    curr->height=0;
    curr->color=true;
}
template<class T> bool RBtree<T>::nodeExist(RBtree<T>::Node * curr){
    return curr!=nil;
}

template<class T> void RBtree<T>::balanceTree(RBtree<T>::Node * newNode){
  RBtree<T>::Node * uncle;
  while(newNode->parent->color == true){
      if(newNode->parent == newNode->parent->parent->left){
          uncle=newNode->parent->parent->right;
          if(uncle->color==true){
              newNode->parent->color=false;
              uncle->color=false;
              newNode->parent->parent->color=true;
              newNode = newNode->parent->parent;
        }
        else{
            if(newNode==newNode->parent->right){
                newNode=newNode->parent;
                leftRotate(newNode);
            }
            newNode->parent->color=false;
            newNode->parent->parent->color=true;
            rightRotate(newNode->parent->parent);
            }
     }
     else{
         uncle=newNode->parent->parent->left;
         if(uncle->color==false){
             newNode->parent->color=false;
             uncle->color=true;
             newNode->parent->parent->color=true;
             newNode=newNode->parent->parent;
        }
        else{
            if(newNode==newNode->parent->left){
                newNode=newNode->parent;
                rightRotate(newNode);
            }
            newNode->parent->color=false;
            newNode->parent->parent->color=true;
            leftRotate(newNode->parent->parent);
        }
    }
  }
  root->color=false;//tree ?
}

template<class T> void RBtree<T>::printTree(RBtree<T>::Node * curr)
{
    if(curr==nil) {cout<<"NIL "<<"\n"; return;}
    if(curr==nullptr) return;
    printTree(curr->left);
    for (int i=0;i<curr->height;++i)
        cout<<" ";
    
    cout<<curr->key;
    if(curr->color==true) 
    cout<< " - RED " ;
    else
    cout<< " - BLACK " ;
    cout<<"\n";

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

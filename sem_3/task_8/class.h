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
    void swap(Node * a,Node * b);
    void rightRotate(Node * curr);
    void leftRotate(Node * curr);
    void createNode(Node * curr, T key);
    bool nodeExist(Node * curr);
    void balanceTree(Node * curr);
    void insert(T key);
    void printTree(Node * curr);
    void transplantNode(Node* toNode, Node* fromNode);
    int getChildrenCount(Node* node);
    Node * getChildOrMock(Node * node);
    void fixRulesAfterRemoval(Node* node);
    void remove(T key);
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
  parent=nullptr;
  height=0;
  color=false;
}

template<class T> RBtree<T>::Node::Node(T value)
{
  key=value;
  left=nil;
  right=nil;
  parent=nil;
  height=1;
  color=true;
}

template<class T> RBtree<T>::RBtree(T key)
{
  root= new Node(key);
  root->color=false;
}

template<class T> RBtree<T>::~RBtree(){
  delete_tree(root);
}

template<class T> void RBtree<T>::delete_tree(RBtree<T>::Node * curr)
{
    if (curr!=nil)
    {
        delete_tree(curr->left);
        delete_tree(curr->right);
        delete curr;
    }
}

template<class T> int RBtree<T>::getHeight(RBtree<T>::Node * curr){
    return (curr == nullptr) ? -1: curr->height;
}

template<class T> void RBtree<T>::updateHeight(RBtree<T>::Node * curr){
    curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
}



template<class T> void RBtree<T>::swap(RBtree<T>::Node * a,RBtree<T>::Node * b){
    T a_key = a->key;
    a->key = b->key;
    b->key = a_key;
    bool a_color = a->color;
    a->color = b->color;
    b->color = a_color;
    // RBtree<T>::Node * a_left = a->left;
    // a->left = b->left;
    // b->left = a_left;
    // RBtree<T>::Node * a_right = a->right;
    // a->right = b->right;
    // b->right = a_right;
    // RBtree<T>::Node * a_parent = a->parent;
    // a->parent = b->parent;
    // b->parent = a_parent;
    // delete a_left;
    // delete a_right;
    // delete a_parent;

}

template<class T> void RBtree<T>::rightRotate(RBtree<T>::Node * curr){
    swap(curr, curr->left);
    RBtree<T>::Node * buffer = curr->right;
    curr->right = curr->left;
    curr->left = curr->right->left;
    curr->left->parent=curr;
    curr->right->left = curr->right->right;
    curr->right->right = buffer;
    curr->right->right->parent=curr->right; 
    // updateHeight(curr->right);
    // updateHeight(curr);
}

template<class T> void RBtree<T>::leftRotate(RBtree<T>::Node * curr){
    swap(curr, curr->right);
    RBtree<T>::Node * buffer = curr->left;
    curr->left = curr->right;
    curr->right = curr->left->right;
    curr->right->parent=curr;
    curr->left->right = curr->left->left;
    curr->left->left = buffer;
    curr->left->left->parent=curr->left; 
    // updateHeight(curr->left);
    // updateHeight(curr);
}

template<class T> bool RBtree<T>::nodeExist(RBtree<T>::Node * curr){
    return curr!=nil;
}

// template<class T> void RBtree<T>::createNode(RBtree<T>::Node * curr, T key){
//     curr->parent=nil;
//     curr->left=nil;
//     curr->right=nil;
//     curr->key=key;
//     curr->height=0;
//     curr->color=true;
// }

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
                leftRotate(newNode->parent);
  //                 printTree(newNode);
  // cout<<"********************\n";

            }
            newNode->parent->color=false;
            newNode->parent->parent->color=true;
            rightRotate(newNode->parent->parent);
            }
     }
     else{
         uncle=newNode->parent->parent->left;
         if(uncle->color==true){
             newNode->parent->color=false;
             uncle->color=false;
             newNode->parent->parent->color=true;
             newNode=newNode->parent->parent;
        }
        else{
            if(newNode==newNode->parent->left){

                rightRotate(newNode->parent);
            }
            newNode->parent->color=false;
            newNode->parent->parent->color=true;
            leftRotate(newNode->parent->parent);
        }
    }
  }
  root->color=false;
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
  RBtree<T>::Node * newNode = new Node(key);
  newNode->parent = parent;
  if(parent==nil) root=newNode;
  else if (key < parent->key) parent->left = newNode;
  else parent->right = newNode;
  // printTree(root);
  // cout<<"------------\n";
  balanceTree(newNode);
}


// template<class T> void RBtree<T>::printTree(RBtree<T>::Node * curr)
// {
//     if(curr==nil) {cout<<"NIL "<<"\n"; return;}
//     if(curr==nullptr) return;
//     printTree(curr->left);
//     for (int i=0;i<curr->height;++i)
//         cout<<" ";
    
//     cout<<curr->key;
//     if(curr->color==true) 
//     cout<< " - RED " ;
//     else
//     cout<< " - BLACK " ;
//     cout<<"\n";

//     printTree(curr->right);
// }

template<class T>
void RBtree<T>::printTree(RBtree<T>::Node * node) {
	if (node == nil)
		return;
	if (node->parent == nil)
		cout << node->key << "(" << node->color << ") is root" << endl;
	else if(node->parent->left==node)
	{
		cout << node->key << "(" << node->color << ") is "<<node->parent->key<<"'s "<<"left child" << endl;
	}
	else
	{
		cout << node->key << "(" << node->color << ") is " << node->parent->key << "'s " << "right child" << endl;
	}
	printTree(node->left);
	printTree(node->right);
}

template<class T> typename RBtree<T>::Node * RBtree<T>::search(RBtree<T>::Node * curr, T key)
{
    if (curr == nil) return nil; 
    if(curr->key==key) return curr;
    return (key<curr->key)? search(curr->left,key) : search(curr->right,key);   
}

template<class T> typename RBtree<T>::Node * RBtree<T>::getMin(RBtree<T>::Node * curr)
{
    if (curr == nil) return nil; 
    if(curr->left==nil) return curr;
    return getMin(curr->left);   
}

template<class T>  typename RBtree<T>::Node * RBtree<T>::getMax(RBtree<T>::Node * curr)
{
    if (curr == nil) return nil; 
    if(curr->right==nil) return curr;
    return getMax(curr->right);   
}

// template<class T> typename RBtree<T>::Node * RBtree<T>::delet(RBtree<T>::Node * curr, T key)
// {
//     if (curr == nullptr) return nullptr; 
//     else if(key < curr->key) curr->left = delet(curr->left,key);
//     else if(key > curr->key) curr->right = delet(curr->right,key);
//     else 
//     {
//       if(curr->left == nullptr || curr->right == nullptr)
//           curr=(curr->left==nullptr)?curr->right:curr->left;
//       else 
//       {
//         RBtree<T>::Node * maxInLeft = getMax(curr->left);
//         curr->key = maxInLeft->key;
//         curr->right = delet(curr->right,maxInLeft->key);
//         curr->left = maxInLeft->left;
//       }
//     }
//     return curr;
// }


template<class T>
void RBtree<T>::transplantNode(RBtree<T>::Node * toNode, RBtree<T>::Node * fromNode) {
    if (toNode == root) root = fromNode;
    else if (toNode == toNode->parent->left) toNode->parent->left = fromNode;
    else toNode->parent->right = fromNode;
    fromNode->parent = toNode->parent;
}

template<class T>
int RBtree<T>::getChildrenCount(RBtree<T>::Node * node) {
    int count = 0;
    if (nodeExist(node->left)) count += 1;
    if (nodeExist(node->right)) count += 1;
    return count;
}

template<class T> typename RBtree<T>::Node * RBtree<T>::getChildOrMock(RBtree<T>::Node * node) {
  return nodeExist(node->left) ? node->left : node->right;
}

template<class T>
void RBtree<T>::fixRulesAfterRemoval (RBtree<T>::Node * node) {
  while(node != root && node->color == false) {
    RBtree<T>::Node * brother;
    if(node == node->parent->left) {
      brother = node->parent->right;
      if(brother->color == true) {
        brother->color = false;
        node->parent->color = true;
        leftRotate( node->parent);
        brother = node->parent->right;
      }
      if(brother->left->color == false && brother->right->color == false) {
        brother->color = true;
        node = node->parent;
      }
      else {
      if(brother->right->color == false) {
        brother->left->color = false;
        brother->color = true;
        //RBtree<T>::Node * tmp = brother;
        rightRotate( brother);//!
        brother = node->parent->right;
      }
      brother->color = node->parent->color;
      node->parent->color = false;
      brother->right->color = false;
      leftRotate( node->parent);
      node = root;
      }
    }
    else {
        brother = node->parent->left;
        if(brother->color == true) {
        brother->color = false;
        node->parent->color = true;
        rightRotate( node->parent);
        brother = node->parent->left;
        }
        if(brother->left->color == false && brother->right->color == false){
          rightRotate( node->parent);
          brother = node->parent->left;
        } else {
          if(brother->left->color == false) {
            brother->right->color = false;
            brother->color = true;
            //RBtree<T>::Node * tmp = brother;
            leftRotate( brother);//!
            brother = node->parent->left;
          }
          brother->color = node->parent->color;
          node->parent->color = false;
          brother->left->color = false;
          rightRotate(node->parent);
          node = root;
        }
    }
  }
  node->color=false;
}

template<class T>
void RBtree<T>::remove(T key) {
  RBtree<T>::Node * nodeToDelete = search(root, key);
  bool removedNodeColor = nodeToDelete->color;
  RBtree<T>::Node * child;
  if(getChildrenCount(nodeToDelete) < 2) {
    child = getChildOrMock(nodeToDelete);
    transplantNode( nodeToDelete, child);
  }
  else {
    RBtree<T>::Node * minNode = getMin(nodeToDelete->right);
    nodeToDelete->key = minNode->key;
    removedNodeColor = minNode->color;
    child = getChildOrMock(minNode);
    transplantNode( minNode, child);
    delete minNode;
  }
  if(removedNodeColor == false) fixRulesAfterRemoval(child);
}







































#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

#include "class.h"

template<class T> Node<T>::Node(T value)
{
  key=value;
  left=nullptr;
  right=nullptr;
}

template<class T> RBtree<T>::RBtree(T key)
{
  root= new Node<T>(key);
}

template<class T> RBtree<T>::~RBtree(){
  delete_tree(root);
}

template<class T> void RBtree<T>::delete_tree(Node<T> * curr)
{
    if (curr)
    {
        delete_tree(curr->left);
        delete_tree(curr->right);
        delete curr;
    }
}


// std::ostream &operator<<(std::ostream &cout, Darr &x1)
// {
//   for(list <array<double,Con>>::iterator i= x1.mylist.begin();i!=x1.mylist.end();i++){
//     for(size_t j=0;j<Con;j++){
//       cout<< (*i)[j]<<" ";
//     }
//   }
//   cout <<"   N:" << x1.N<<" ";
//   cout <<"\n";
//   return cout;
// }
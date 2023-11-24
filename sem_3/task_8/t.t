class.cpp:3:19: error: ‘RBTree’ does not name a type; did you mean ‘RBtree’?
    3 | template<class T> RBTree<T>::Node::Node(T value)
      |                   ^~~~~~
      |                   RBtree
class.cpp: In constructor ‘RBtree<T>::RBtree(T)’:
class.cpp:12:13: error: ‘RBtree<T>::Node’ is not a template
   12 |   root= new Node<T>(key);
      |             ^~~~
class.cpp: At global scope:
class.cpp:19:30: error: expected initializer before ‘<’ token
   19 | template<class T> void RBTree<T>::delete_tree(RBTree<T>::Node * curr)
      |                              ^
class.cpp:29:30: error: expected initializer before ‘<’ token
   29 | template<class T> void RBTree<T>::delete_tree(RBTree<T>::Node * curr);
      |                              ^
class.cpp:30:15: error: variable or field ‘RBTree’ declared void
   30 | template void RBTree<int>::delete_tree(RBTree<T>::Node * curr);
      |               ^~~~~~
class.cpp:30:21: error: expected ‘;’ before ‘<’ token
   30 | template void RBTree<int>::delete_tree(RBTree<T>::Node * curr);
      |                     ^
      |                     ;
make: *** [Makefile:6: class.o] Error 1

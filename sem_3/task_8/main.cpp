#include "class.h"

using namespace std;

int main()
{  
  RBtree<double> m_tree(8);
  m_tree.printTree(m_tree.root);
  cout<<endl;
  m_tree.insert(13);
  m_tree.insert(17);
  // m_tree.insert(1);
  // m_tree.insert(17);
  m_tree.printTree(m_tree.root);
  // RBtree<double> m_tree(6);
  // m_tree.printTree(m_tree.root);
  // cout<<endl;
  // m_tree.insert(4);
  // m_tree.printTree(m_tree.root);
  // cout<<endl;
  // m_tree.insert(8);
  // m_tree.printTree(m_tree.root);
  // cout<<endl;
  // m_tree.insert(9);
  // m_tree.printTree(m_tree.root);
  // cout<<endl;

// m_tree.delet(m_tree.root,4);
// m_tree.printTree(m_tree.root);
 cout<<endl;
  // cout<<"Enter the number of autotests: ";

  return 0;
}

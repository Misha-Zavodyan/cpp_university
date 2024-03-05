#include "class.h"

using namespace std;

int main()
{ 
  // cout<<"2) inserting the right child for the RED parent, RED uncle and black grandfather not the root"<<endl;
  // RBtree<double> m_tree2(15);
  // m_tree2.insert(20);
  // m_tree2.insert(6);
  // m_tree2.insert(2);
  // m_tree2.insert(8);
  // m_tree2.printTree(m_tree2.root);
  // cout<<endl;
  // m_tree2.insert(3);
  // m_tree2.printTree(m_tree2.root);
  // cout<<endl;

  // cout<<"3) insertion of the right child for the RED parent, RED uncle and black grandfather ROOT"<<endl;
  // RBtree<double> m_tree3(15);
  // m_tree3.insert(5);
  // m_tree3.insert(20);
  // m_tree3.printTree(m_tree3.root);
  // cout<<endl;
  // m_tree3.insert(6);
  // m_tree3.printTree(m_tree3.root);
  // cout<<endl;
    
  // cout<<"4) inserting the right child for the RED parent"<<endl;
  // RBtree<double> m_tree4(15);
  // m_tree4.insert(5);
  // m_tree4.printTree(m_tree4.root);
  // cout<<endl;
  // m_tree4.insert(6);
  // m_tree4.printTree(m_tree4.root);
  // cout<<endl;

  // cout<<"5) inserting the left child for the RED parent"<<endl;
  // RBtree<double> m_tree5(15);
  // m_tree5.insert(5);
  // m_tree5.printTree(m_tree5.root);
  // cout<<endl;
  // m_tree5.insert(4);
  // m_tree5.printTree(m_tree5.root);
  // cout<<endl;



  // RBtree<double> m_tree1(50);
  // m_tree1.insert(30);
  // m_tree1.insert(60);
  // m_tree1.insert(20);
  // m_tree1.insert(40);
  // m_tree1.insert(35);
  // m_tree1.insert(45);
  // m_tree1.insert(62);
  // m_tree1.insert(59);
  // m_tree1.insert(63);
  // m_tree1.printTree(m_tree1.root);
  // cout<<endl;
  //   m_tree1.remove(40); 
  // m_tree1.printTree(m_tree1.root);
  // cout<<endl;
  //     m_tree1.remove(35); 
  // m_tree1.printTree(m_tree1.root);
  // cout<<endl;

 double a,b,c,d,e;

 a=double(rand()%40);
 b=double(rand()%40);
 c=double(rand()%40);
 e=double(rand()%40);
 d=double(rand()%40);
 cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<endl;
  RBtree<double> m_tree(a);
  m_tree.printTree(m_tree.root);
  cout<<endl;
  m_tree.insert(b);
  m_tree.printTree(m_tree.root);
  cout<<endl;
  m_tree.insert(c);
  m_tree.printTree(m_tree.root);
  cout<<endl;
  m_tree.insert(d);
  m_tree.printTree(m_tree.root);
  cout<<endl;
  m_tree.insert(double(rand()%40));
  m_tree.printTree(m_tree.root);
  cout<<endl;
  m_tree.insert(double(rand()%40));
  m_tree.printTree(m_tree.root);
  cout<<endl;
  m_tree.insert(double(rand()%40));
  m_tree.printTree(m_tree.root);
  cout<<endl;
  cout<<"dele"<<endl;
  m_tree.remove(a); 
  m_tree.printTree(m_tree.root);
  cout<<endl;
  m_tree.remove(b); 
  m_tree.printTree(m_tree.root);
  cout<<endl;
  m_tree.remove(c); 
  m_tree.printTree(m_tree.root);
  cout<<endl;
 
  return 0;
}

//test.cpp
#include "RBTree.h"

int main() 
{
	vector<int> nums{ 10,40,30,60,90,70,20,50,80,100};
	RBTree<int> tree;
	for (auto num : nums)
		tree.insert(num);
	tree.preOrder();
	cout << endl;
	tree.inOrder();
	cout << endl;
	tree.postOrder();
	cout << endl;
	cout << "Serch 30: \n";
	cout << endl<<tree.search(30)->key<<endl;
	cout << "Delet 100 \n";
	tree.remove(100);
	tree.preOrder();
	cout << endl;
	cout << "\n RBTree: \n";
	tree.print();
	//cin.get();
	return 0;
}


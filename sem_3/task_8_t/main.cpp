//test.cpp
#include "RBTree.h"

int main() 
{
	
	vector<int> nums{ 8,13,27,1,6,15,25,22,11,17};
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
	//cout << endl<<tree.search(30)->key<<endl;
	//cout << "Delet 13 \n";
	//tree.remove(13);
	tree.preOrder();
	cout << endl;
	cout << "\n RBTree: \n";
	tree.print();
	//cin.get();
	return 0;
}


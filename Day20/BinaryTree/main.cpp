#include "BinaryTree.hpp"

int main()
{
	BinaryTree<int> map;
	map.insert(10);
	map.insert(12);
	map.insert(9);
	map.insert(15);
	//map.remove(10);
	//cout << temp->mData << endl;
	map.print();
	BinaryNode<int> a(nullptr, nullptr, 1);
	a.mData;

	system("pause");
	return 0;
}
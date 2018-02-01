#include <iostream>
#include <string>

using namespace std;

template<class TYPE>
struct SetNode
{
	TYPE data;
	SetNode *left = nullptr;
	SetNode *right = nullptr;
};

template<class T>
void print(SetNode<T> *node)
{
	if (node == nullptr)
		return;
	cout << node->data << endl;
	print(node->left);
	print(node->right);
}

void test()
{
	SetNode<string> root = { "A" };
	SetNode<string> nodes[7]{
		{ "B" },
		{ "C" },
		{ "D" },
		{ "E" },
		{ "F" },
		{ "G" },
		{ "H" }
	};
	root.left = &nodes[0];
	root.right = &nodes[4];
	nodes[1].left = &nodes[2];
	nodes[1].right = &nodes[3];
	nodes[4].right = &nodes[5];
	nodes[5].left = &nodes[6];

	print(&root);
}

int main()
{
	test();

	system("pause");
	return 0;
}
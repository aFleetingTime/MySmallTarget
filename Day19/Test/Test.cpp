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
void print1(SetNode<T> *node)
{
	if (node == nullptr)
		return;
	cout << node->data << ' ';
	print1(node->left);
	print1(node->right);
}

template<class T>
void print2(SetNode<T> *node)
{
	if (node == nullptr)
		return;
	print2(node->left);
	cout << node->data << ' ';
	print2(node->right);
}

template<class T>
void print3(SetNode<T> *node)
{
	if (node == nullptr)
		return;
	print3(node->left);
	print3(node->right);
	cout << node->data << ' ';
}

template<class T>
int getNum(SetNode<T> *node)
{
	if (node == nullptr)
		return 0;
	if (node->left == nullptr && node->right == nullptr)
		return 1;
	return getNum(node->right) + getNum(node->left);
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
	nodes[0].right = &nodes[1];
	nodes[1].left = &nodes[2];
	nodes[1].right = &nodes[3];
	nodes[4].right = &nodes[5];
	nodes[5].left = &nodes[6];

	print1(&root);
	cout << endl;
	print2(&root);
	cout << endl;
	print3(&root);
	cout << endl;

	cout << "叶子结点个数:" << endl;
	cout << getNum(&root) << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}
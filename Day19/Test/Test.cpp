#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

template<class TYPE>
struct SetNode
{
	TYPE data;
	SetNode *left = nullptr;
	SetNode *right = nullptr;
	~SetNode()
	{
		cout << data << "析构" << ' ';
	}
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

template<class T>
int getHeight(SetNode<T> *root)
{
	if (!root)
		return 0;
	return max(getHeight(root->left) + 1, getHeight(root->right) + 1);
}

template<class T>
SetNode<T>* copyBinaryTree(SetNode<T> *root)
{
	if (!root)
		return nullptr;
	SetNode<T> *tree = new SetNode<T>;
	tree->data = root->data;
	tree->left = copyBinaryTree(root->left);
	tree->right = copyBinaryTree(root->right);
	return tree;
}

template<class T>
void deleteBinaryTree(SetNode<T> **root)
{
	if (!*root)
		return;
	deleteBinaryTree(&(*root)->left);
	deleteBinaryTree(&(*root)->right);
	delete *root;
	*root = nullptr;
}

template<class T>
void print_binaryTree(SetNode<T> *root)
{
	stack<pair<SetNode<T>*, bool>> node;
	pair<SetNode<T>*, bool> temp;
	node.push(make_pair(root, false));
	while (!node.empty())
	{
		temp = node.top();
		node.pop();
		if (temp.second)
		{
			cout << temp.first->data << ' ';
		}
		else
		{
			if(temp.first->right != nullptr)
				node.push(make_pair(temp.first->right, false));
			if (temp.first->left != nullptr)
				node.push(make_pair(temp.first->left, false));
			temp.second = true;
			node.push(temp);
		}
	}
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
	cout << getNum(&root) << endl << endl;

	cout << "树的高度:" << endl;
	cout << getHeight(&root) << endl << endl;

	SetNode<string> *temp = copyBinaryTree(&root);
	cout << "原二叉树:";
	print1(&root);
	cout << endl;
	cout << "拷贝二叉树:";
	print_binaryTree(&root);
	cout << endl;

	deleteBinaryTree(&temp);
	cout << endl;
}

int main()
{
	test();

	system("pause");
	return 0;
}
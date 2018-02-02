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
		cout << data << "����" << ' ';
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
class FunctionClass
{
public:
	virtual void operator()(stack<pair<SetNode<T>*, bool>> &node, pair<SetNode<T>*, bool> &top) = 0;
};

template<class T>
class Push : public FunctionClass<T>
{
public:
	Push(const string &cmd)
	{
		mCmd = cmd;
	}
	void operator()(stack<pair<SetNode<T>*, bool>> &node, pair<SetNode<T>*, bool> &top) 
	{
		if (!mCmd.compare("����"))
		{
			if (top.first->right != nullptr)
				node.push(make_pair(top.first->right, false));
			node.push(top);
			if (top.first->left != nullptr)
				node.push(make_pair(top.first->left, false));
		}
		else if (!mCmd.compare("����"))
		{
			node.push(top);
			if (top.first->right != nullptr)
				node.push(make_pair(top.first->right, false));
			if (top.first->left != nullptr)
				node.push(make_pair(top.first->left, false));
		}
		else
		{
			if (top.first->right != nullptr)
				node.push(make_pair(top.first->right, false));
			if (top.first->left != nullptr)
				node.push(make_pair(top.first->left, false));
			node.push(top);
		}
	}

private:
	string mCmd;
};

template<class T>
void print_binaryTree(SetNode<T> *root, FunctionClass<T> *fun)
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
			temp.second = true;
			(*fun)(node, temp);
		}
	}
	cout << endl;
	delete fun;
}

template<class T>
SetNode<T>* createBinaryTree()
{
	char ch = cin.get();
	if (ch == '#')
		return nullptr;
	SetNode<T> *root = new SetNode<T>;
	root->data = ch;
	root->left = createBinaryTree<T>();
	root->right = createBinaryTree<T>();
	return root;
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

	cout << "Ҷ�ӽ�����:" << endl;
	cout << getNum(&root) << endl << endl;

	cout << "���ĸ߶�:" << endl;
	cout << getHeight(&root) << endl << endl;

	SetNode<string> *temp = copyBinaryTree(&root);
	cout << "ԭ������:";
	print1(&root);
	cout << endl;
	cout << "����������:";
	print1(temp);
	cout << endl << endl;

	cout << "�ǵݹ����:" << endl;
	print_binaryTree(&root, new Push<string>("����"));
	print_binaryTree(&root, new Push<string>("����"));
	print_binaryTree(&root, new Push<string>("����"));
	cout << endl;

	deleteBinaryTree(&temp);
	cout << endl;

	cout << "����������:" << endl;
	SetNode<char> *node = createBinaryTree<char>();
	print1(node);
	cout << endl;
	deleteBinaryTree(&node);
}

int main()
{
	test();

	system("pause");
	return 0;
}
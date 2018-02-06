#include <iostream>
#include <string>
#include <random>
#include "../BinaryTree/BinaryTree.hpp"

using namespace std;



template<class T>
class InitBinaryTree
{
public:
	BinaryNode<T>* hitInitBinaryTree(BinaryNode<T> *root)
	{
		BinaryNode<T> *thr = new BinaryNode<T>(nullptr, nullptr, T());
		thr->mRight = thr;
		if (!root)
			thr->mLeft = thr;
		else
		{
			thr->mLeft = root;
			pre = thr;
			hitTraversalTree(root);
			pre->mRight = thr;
			pre->rTag = 1;
			thr->mRight = pre;
		}
		return thr;
	}

private:
	BinaryNode<T> *pre;
	void hitTraversalTree(BinaryNode<T> *thr)
	{
		if (!thr)
			return;
		hitTraversalTree(thr->mLeft);
		if (!thr->mLeft)
		{
			thr->mLeft = pre;
			thr->lTag = 1;
		}
		else
		{
			thr->lTag = 0;
		}
		if (!thr->mRight)
		{
			thr->rTag = 1;
		}
		else
		{
			thr->rTag = 0;
		}
		if (pre != nullptr && pre->rTag)
		{
			pre->mRight = thr;
			pre = thr;
		}
		hitTraversalTree(thr->mRight);
	}
};
#define THREAD 0
BinaryNode<int> *pre = nullptr;
void hitTraversal(BinaryNode<int> *root)
{
	if (!root)
		return;
	hitTraversal(root->mLeft);
	if (root->mLeft == NULL)
	{
		root->lTag = THREAD;
		root->mLeft = pre;
	}
	if (pre  && pre->mRight == NULL)
	{
		pre->rTag = THREAD;
		pre->mRight = root;
	}
	pre = root;
	cout << root->mData << ' ';
	hitTraversal(root->mRight);
}

int main()
{
	random_device random;
	BinaryTree<int> tree;
	for (int i = 0; i < 5; ++i)
		tree.insert(random() % 10 + 1);
	tree.print();
	cout << endl;
	InitBinaryTree<int> inittree;
	BinaryNode<int> *root = inittree.hitInitBinaryTree(tree.getTree());
	hitTraversal(root);

	system("pause");
	return 0;
}
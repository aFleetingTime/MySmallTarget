#include <iostream>
#include <string>
#include "../BinaryTree/BinaryTree.hpp"

using namespace std;



template<class T>
class InitBinaryTree
{
public:
	ThreadedBinaryNode<T> hitInitBinaryTree(BinaryNode<T> *root)
	{
		ThreadedBinaryNode<T> *thr = new ThreadedBinaryNode<T>(nullptr, nullptr, 0, 1, T());
		thr->mRight = thr;
		if (!root)
			thr->mLeft = thr;
		else
		{
			ThreadedBinaryNode<T> *mroot = new ThreadedBinaryNode<T>(nullptr, nullptr, root->mLeft, root->mRight, root->mData);
			thr->mLeft = mroot;
			pre = thr;
			hitTraversalTree(mroot);
		}
	}

private:
	ThreadedBinaryNode<T> *pre;
	void hitTraversalTree(ThreadedBinaryNode<T> *thr)
	{
		if (!thr)
			return;
		hitTraversalTree(thr->mLeft);
		ThreadedBinaryNode<T> *node = new ThreadedBinaryNode<T>(nullptr, nullptr, root->mLeft, root->mRight, root->mData);
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

int main()
{


	system("pause");
	return 0;
}
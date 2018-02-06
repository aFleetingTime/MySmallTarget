#include <iostream>
#include <string>
#include "../BinaryTree/BinaryTree.hpp"

using namespace std;



template<class T>
class InitBinaryTree
{
public:
	ThreadedBinaryNode<T> hitInitBinaryTree(ThreadedBinaryNode<T> *root)
	{
		ThreadedBinaryNode<T> *thr = new ThreadedBinaryNode<T>(nullptr, nullptr, 0, 1, T());
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
	ThreadedBinaryNode<T> *pre;
	void hitTraversalTree(ThreadedBinaryNode<T> *thr)
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

int main()
{


	system("pause");
	return 0;
}
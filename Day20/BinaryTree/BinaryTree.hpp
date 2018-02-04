#pragma once

#include <iostream>
#include <string>
#include <stack>

using namespace std;

template<class D_Type>
struct BinaryNode
{
	BinaryNode(BinaryNode *left, BinaryNode *right, const D_Type &data)
	{
		this->mLeft = left;
		this->mRight = right;
		this->mData = data;
	}
	BinaryNode *mLeft;
	BinaryNode *mRight;
	D_Type mData;
};

template<class D_Type>
struct ThreadedBinaryNode
{
	ThreadedBinaryNode(ThreadedBinaryNode *left, ThreadedBinaryNode *right, bool lTag, bool rTag, const D_Type &data)
	{
		this->mLeft = left;
		this->mRight = right;
		this->lTag = lTag;
		this->rTag = rTag;
		this->mData = data;
	}
	ThreadedBinaryNode *mLeft;
	bool lTag;
	ThreadedBinaryNode *mRight;
	bool rTag;
	D_Type mData;
};

template<class D_Type>
class BinaryTree
{
public:
	BinaryTree() : mRoot(nullptr) {}

	~BinaryTree()
	{
		ergodic([](BinaryNode<D_Type>* root) {
			delete root;
		});
	}

	void insert(const D_Type &data)
	{
		mInsert(mRoot, data);
	}

	void print()
	{
		ergodic([](BinaryNode<D_Type>* root) {
			cout << root->mData << ' ';
		});
		cout << endl;
	}

	BinaryNode<D_Type>* getTree()
	{
		return mRoot;
	}

	BinaryNode<D_Type>* find(const D_Type &data)
	{
		if (!mRoot)
			return;
		return ergodic([](BinaryNode<D_Type>* root, const D_Type &data) {
			if (root->mData == data)
				return true;
			return false;
		}, data);
	}

	void remove(const D_Type &data)
	{
		if (!mRoot)
			return;
		mRemove(mRoot, data);




		/*if (!mRoot)
			return;
		BinaryNode<D_Type> *temp = nullptr;
		if(!(temp = ergodic([](BinaryNode<D_Type>* root, const D_Type &data) {
			if (root->mLeft && root->mLeft->mData == data)
				return true;
			else if (root->mRight && root->mRight->mData == data)
				return true;
			else
				return false;
		}, data)))
			return;
		stack<pair<BinaryNode<D_Type>*, bool>> s;
		pair<BinaryNode<D_Type>*, bool> t;
		if (temp->mRight)
		{
			s.push(make_pair(, false));
			BinaryNode<D_Type> *curRight = temp->mRight;
			BinaryNode<D_Type> *rootLeft = curRight->mLeft;
			while (rootLeft && rootLeft->mLeft)
			{
				curRight = rootLeft;
				rootLeft = curRight->mLeft;
			}
			if (temp == curRight)
			{
				temp->mData = curRight->mData;
				temp->mRight = curRight->mRight;
				delete curRight;
			}
			else
			{

			}
		}
		else if(temp->mLeft)
		{
			s.push(make_pair(temp->mLeft, false));
		}
		else
		{
			if (temp->mLeft->mData == data)
			{
				delete temp->mLeft;
				temp->mLeft = nullptr;
			}
			else
			{
				delete temp->mRight;
				temp->mRight = nullptr;
			}
		}
		*/
		
	}

	void insert_NonRecursion(const D_Type &data)
	{
		stack<BinaryNode<D_Type>**> s;
		s.push(&mRoot);
		while (!s.empty())
		{
			BinaryNode<D_Type>** temp = s.top();
			s.pop();
			if (!*temp)
				*temp = new BinaryNode<D_Type>(nullptr, nullptr, data);
			else if (data < (*temp)->mData)
				s.push(&(*temp)->mLeft);
			else if (data >(*temp)->mData)
				s.push(&(*temp)->mRight);
		}
	}

private:
	BinaryNode<D_Type> *mRoot;
	void mInsert(BinaryNode<D_Type> *&root, const D_Type &data)
	{
		if (!root)
			root = new BinaryNode<D_Type>(nullptr, nullptr, data);
		else if (data < root->mData)
			mInsert(root->mLeft, data);
		else if(data > root->mData)
			mInsert(root->mRight, data);
	}
	BinaryNode<D_Type>* ergodic(bool(*term)(BinaryNode<D_Type>*, const D_Type &), const D_Type &data)
	{
		stack<pair<BinaryNode<D_Type>*, bool>> s;
		s.push(make_pair(mRoot, false));
		pair<BinaryNode<D_Type>*, bool> temp;
		while (!s.empty())
		{
			temp = s.top();
			s.pop();
			if (!temp.first)
				continue;
			if (temp.second)
			{
				if(term(temp.first, data))
					return temp.first;
			}
			else
			{
				temp.second = true;
				s.push(make_pair(temp.first->mRight, false));
				s.push(temp);
				s.push(make_pair(temp.first->mLeft, false));
			}
		}
		return nullptr;
	}
	void ergodic(void(*term)(BinaryNode<D_Type>*))
	{
		stack<pair<BinaryNode<D_Type>*, bool>> s;
		s.push(make_pair(mRoot, false));
		pair<BinaryNode<D_Type>*, bool> temp;
		while (!s.empty())
		{
			temp = s.top();
			s.pop();
			if (!temp.first)
				continue;
			if (temp.second)
			{
				term(temp.first);
			}
			else
			{
				temp.second = true;
				s.push(make_pair(temp.first->mRight, false));
				s.push(temp);
				s.push(make_pair(temp.first->mLeft, false));
			}
		}
	}
	void mRemove(BinaryNode<D_Type> *&root, const D_Type &data)
	{
		if (!root)
			return;
		if (data < root->mData)
			mRemove(root->mLeft, data);
		else if (data > root->mData)
			mRemove(root->mRight, data);
		else if (root->mLeft && root->mRight)
		{
			BinaryNode<D_Type> *temp = findMin(root->mRight);
			root->mData = temp->mData;
			if (temp == root->mRight && !temp->mLeft && !temp->mRight)
				root->mRight = nullptr;
			else
				mRemove(root->mRight, data);
		}
		else
		{
			BinaryNode<D_Type> *old = root;
			root = (root->mLeft ? root->mLeft : root->mRight);
			delete old;
		}
	}
	BinaryNode<D_Type>* findMin(BinaryNode<D_Type> *root)
	{
		if (root)
		{
			while (root->mLeft)
				root = root->mLeft;
		}
		return root;
	}
};
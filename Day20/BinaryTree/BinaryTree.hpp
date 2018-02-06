#pragma once

#include <iostream>
#include <string>
#include <stack>

using namespace std;

template<class D_Type> struct BinaryNode;
template<class D_Type> struct ThreadedBinaryNode;

template<class D_Type>
struct ThreadedBinaryNode
{
public:
	ThreadedBinaryNode(BinaryNode<D_Type> *left, BinaryNode<D_Type> *right, bool lTag, bool rTag, const D_Type &data)
	{
		this->mLeft = left;
		this->mRight = right;
		this->lTag = lTag;
		this->rTag = rTag;
		this->mData = data;
	}
	//ThreadedBinaryNode *mLeft;
	BinaryNode<D_Type> *mLeft;
	bool lTag;
	//ThreadedBinaryNode *mRight;
	BinaryNode<D_Type> *mRight;
	bool rTag;
	D_Type mData;
};

template<class D_Type>
struct BinaryNode : public ThreadedBinaryNode<D_Type>
{
public:
	BinaryNode(BinaryNode *left, BinaryNode *right, const D_Type &data) : ThreadedBinaryNode<D_Type>(left, right, left, right, data)
	{
		//mLeft = left;
		//mRight = right;
	}
	//BinaryNode<D_Type> *mLeft;
	//BinaryNode<D_Type> *mRight;
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
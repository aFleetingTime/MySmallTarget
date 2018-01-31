#pragma once

#include <iostream>

using namespace std;

template<class TYPE> class CircularLinkedList;
template<class TYPE> struct LinkNode;

template<class TYPE>
class CircularLinkedList
{
public:
	CircularLinkedList() : mRear(new LinkNode(TYPE(), &mHead, &mHead)), mHead(0, nullptr, nullptr)
	{
		mHead.next = mRear;
		mHead.last = mRear;
		mSize = 0;
	}

	~CircularLinkedList()
	{
		LinkNode *temp = nullptr, *cur = mHead.next;
		while (cur != mRear)
		{
			temp = cur->next;
			delete cur;
			cur = temp;
		}
		delete mRear;
	}

	void push_back(const TYPE &data)
	{
		LinkNode *temp = new LinkNode(data, mRear, mRear->last);
		mRear->last->next = temp;
		mRear->last = temp;
		++mSize;
	}

	void pop_back()
	{
		if (mSize == 0)
			throw exception("没有可删除结点!");
		LinkNode *temp = mRear->last->last;
		temp->next = mRear;
		delete mRear->last;
		mRear->last = temp;
		--mSize;
	}

	void push_front(const TYPE &data)
	{
		LinkNode *temp = new LinkNode(data, mHead.next, &mHead);
		mHead.next->last = temp;
		mHead.next = temp;
		++mSize;
	}

	void pop_front()
	{
		if (mSize == 0)
			throw exception("没有可删除结点!");
		LinkNode *temp = mHead.next->next;
		delete mHead.next;
		mHead.next = temp;
		--mSize;
	}

	void print(size_t count)
	{
		LinkNode *cur = &mHead;
		for (size_t i = 0; i < mSize * count; ++i)
		{
			cur = cur->next;
			cout << cur->data << ' ';
			if (cur->next == mRear)
				cur = mRear->next;
		}
		cout << endl;
	}

	TYPE& at(size_t pos)
	{
		LinkNode *cur = mHead.next;
		for (size_t i = 0; i < pos; ++i)
		{
			cur = cur->next;
			if (cur->next == mRear)
				cur = mRear->next;
		}
		return cur->data;
	}

	void josephusProblem(int n)
	{
		LinkNode *cur = mHead.next;
		cout << "销毁顺序";
		while (mSize != 0)
		{
			for (int i = 1; i < n; ++i)
			{
				cur = cur->next;
				if (cur == mRear || cur == &mHead)
					cur = mHead.next;	
			}
			cout << " -> " << cur->data;
			cur->last->next = cur->next;
			cur->next->last = cur->last;
			LinkNode *temp = cur->next;
			delete cur;
			cur = temp;
			if (cur == mRear || cur == &mHead)
				cur = mHead.next;
			--mSize;
		}
	}

private:
	struct LinkNode;
	LinkNode mHead;
	LinkNode *mRear;
	size_t mSize;
};

template<class TYPE>
struct CircularLinkedList<TYPE>::LinkNode
{
	LinkNode(const TYPE &data, LinkNode *next, LinkNode *last)
	{
		this->data = data;
		this->next = next;
		this->last = last;
	}
	LinkNode *next;
	LinkNode *last;
	TYPE data;
};
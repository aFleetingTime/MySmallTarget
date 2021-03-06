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

	void print(size_t count)
	{
		LinkNode *cur = &mHead;
		for (size_t i = 0; i < mSize * count; ++i)
		{
			cur = cur->next;
			cout << cur->data << ' ';
			if(cur->next == &mHead || cur->next == mRear)
				cur = cur->next;
		}
		cout << endl;
	}

	void pop_back(TYPE data)
	{

	}

	void push_front(const TYPE &data)
	{

	}

	void pop_front(TYPE data)
	{

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
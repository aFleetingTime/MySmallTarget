#pragma once

#include <iostream>

template<class TYPE> class MyQueue;
template<class TYPE> class Node;

template<class TYPE> 
class MyQueue
{
public:
	MyQueue() : mHead(TYPE(), nullptr), mSize(0) {}

	~MyQueue()
	{
		Node *cur = &mHead, *temp = nullptr;
		while (cur->next != nullptr)
		{
			temp = cur->next->next;
			delete cur->next;
			cur = temp;
		}
	}

	void push(const TYPE &data)
	{
		mHead.next = new Node(data, mHead.next);
		++mSize;
	}

	void pop()
	{
		if (!mSize)
			throw std::exception("没有可出队元素!");
		Node *cur = &mHead;
		for (size_t i = 1; i < mSize; ++i)
			cur = cur->next;
		delete cur->next;
		cur->next = nullptr;
		--mSize;
	}

	TYPE& front()
	{
		if (!mSize)
			throw std::exception("队列元素为空!");
		Node *cur = &mHead;
		for (size_t i = 0; i < mSize; ++i)
			cur = cur->next;
		return cur->data;
	}

	TYPE& back()
	{
		if (!mSize)
			throw std::exception("队列元素为空!");
		return mHead.next->data;
	}

	size_t size()
	{
		return mSize;
	}

	bool empty()
	{
		return !mSize;
	}

private:
	struct Node;
	Node mHead;
	size_t mSize;
};

template<class TYPE>
struct MyQueue<TYPE>::Node
{
	Node(const TYPE &data, Node *next)
	{
		this->data = data;
		this->next = next;
	}
	TYPE data;
	Node *next;
};
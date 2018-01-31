#pragma once

using sizeType = unsigned int;

template<class TYPE> class MyLink;
template<class TYPE> struct Node;

template<class TYPE>
class MyLink
{
public:
	MyLink()
	{
		mHead = new Node(TYPE(), nullptr);
		mSize = 0;
	}

	~MyLink()
	{
		Node *temp = nullptr;
		while (mHead != nullptr)
		{
			temp = mHead->next;
			delete mHead;
			mHead = temp;
		}
	}

	void push_back(const TYPE &data)
	{
		Node *pCur = mHead;
		while (pCur->next != nullptr)
			pCur = pCur->next;
		pCur->next = new Node(data, nullptr);
		++mSize;
	}

	void pop_back()
	{
		if (mSize == 0)
			throw exception("没有可删除的结点!");
		Node *pCur = mHead;
		while (pCur->next->next != nullptr)
			pCur = pCur->next;
		delete pCur->next;
		pCur->next = nullptr;
		--mSize;
	}

	void push_front(const TYPE &data)
	{
		mHead->next = new Node(data, mHead->next);
		++mSize;
	}

	void pop_front()
	{
		if (mSize == 0)
			throw exception("没有可删除的结点!");
		Node *temp = mHead->next->next;
		delete mHead->next;
		mHead->next = temp;
		--mSize;
	}

	void print_list()
	{
		Node *pCur = mHead->next;
		cout << "size:" << mSize << endl;
		while (pCur != nullptr)
		{
			cout << pCur->data << ' ';
			pCur = pCur->next;
		}
		cout << endl;
	}

	sizeType size()
	{
		return mSize;
	}

	TYPE& insert(sizeType pos, TYPE &data)
	{
		if (pos > mSize)
			pos = mSize - 1;
		Node *pCur = mHead;
		for (sizeType i = 0; i < pos; ++i)
			pCur = pCur->next;
		pCur->next = new Node(data, pCur->next);
		++mSize;
		return pCur->next->data;
	}

	TYPE& insert(sizeType pos, TYPE &&data)
	{
		if (pos >= mSize)
			pos = mSize - 1;
		Node *pCur = mHead;
		for (sizeType i = 0; i < pos; ++i)
			pCur = pCur->next;
		pCur->next = new Node(data, pCur->next);
		++mSize;
		return pCur->next->data;
	}

	TYPE back()
	{
		if (mSize == 0)
			throw exception("元素为空!");
		Node *pCur = mHead->next;
		while (pCur->next != nullptr)
			pCur = pCur->next;
		return pCur->data;
	}

	TYPE front()
	{
		if (mSize == 0)
			throw exception("元素为空!");
		return mHead->next->data;
	}

	void sort()
	{
		Node *x = mHead->next;
		while (x->next != nullptr)
		{
			Node *y = x->next;
			Node *max = x;
			while (y != nullptr)
			{
				if (max->data > y->data)
					max = y;
				y = y->next;
			}
			if (max != x)
			{
				TYPE temp = max->data;
				max->data = x->data;
				x->data = temp;
			}
			x = x->next;
		}
	}

	template<class OBJ_TYPE>
	void sort(const OBJ_TYPE &obj)
	{
		Node *x = mHead->next;
		while (x->next != nullptr)
		{
			Node *y = x->next;
			Node *max = x;
			while (y != nullptr)
			{
				if (obj(max->data, y->data))
					max = y;
				y = y->next;
			}
			if (max != x)
			{
				TYPE temp = max->data;
				max->data = x->data;
				x->data = temp;
			}
			x = x->next;
		}
	}

	TYPE& operator[](sizeType pos)
	{
		if (mSize <= pos)
			throw exception("访问元素越界!");
		Node *pCur = mHead->next;
		for (sizeType i = 0; i < pos; ++i)
			pCur = pCur->next;
		return pCur->data;
	}


private:
	struct Node;
	Node *mHead;
	sizeType mSize;
};

template<class TYPE>
struct MyLink<TYPE>::Node
{
private:
	friend class MyLink<TYPE>;
	Node(const TYPE &data, Node *next)
	{
		this->data = data;
		this->next = next;
	}
	TYPE data;
	Node *next;
};
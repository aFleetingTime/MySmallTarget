#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
class MyLinkedList
{
public:
	MyLinkedList()
	{
		this->head = new Node;
		this->end = head;
	}
	MyLinkedList(unsigned size, T data)
	{
		this->head = new Node;
		Node *ptr = this->head;
		unsigned i = 0;
#if 0
		for (unsigned i = 0; i < size; ++i)
		{
			ptr->next = new Node(data, nullptr);
			ptr = ptr->next;
		}
#endif
		while (true)
		{
			ptr->next = new Node(data, nullptr);
			if (++i == size)
				break;
			ptr = ptr->next;
		}

		this->end = ptr;
		this->size = size;
	}
	~MyLinkedList()
	{
		Node *next = head->next, *temp = nullptr;
		delete head;
		while (next != nullptr)
		{
			temp = next;
			next = next->next;
			delete temp;
		}
		this->size = 0;
		this->head = nullptr;
		this->end = nullptr;
	}
	T& at(unsigned index)
	{
		if (index >= size)
			throw out_of_range("访问元素超过链表大小!");
		Node *ptr = this->head->next;
		unsigned i = 0;
		while (++i <= index)
			ptr = ptr->next;
		return ptr->data;
	}

	template<class T>
	void push_front(T &&data)
	{
		if (this->head->next != nullptr)
			this->head->next = new Node(data, this->head->next);
		else
			this->head->next = new Node(data, nullptr);
		++this->size;
	}
	void pop_front()
	{
		if (this->head->next == nullptr)
			throw out_of_range("没有可删除元素!");
		Node *temp = this->head->next->next;
		delete this->head->next;
		this->head = temp;
		--this->size;
	}
	void insert(unsigned index, T &&data)
	{
		if (index >= size)
			throw out_of_range("访问元素超过链表大小!");
		Node *ptr = head;
		for (unsigned int i = 0; i <= index; ++i)
			ptr = ptr->next;
		Node *temp = ptr->next;
		ptr->next = new Node(data, temp);
		++this->size;
	}
	unsigned int getSize() const
	{
		return this->size;
	}
	T& front()
	{
		if (head->next == nullptr)
			throw out_of_range("访问元素超过链表大小!");
		return head->next->data;
	}
	T& back()
	{
		if (head->next == nullptr)
			throw out_of_range("访问元素超过链表大小!");
		Node *ptr = head;
		while (ptr->next != nullptr) ptr = ptr->next;
		return ptr->data;
	}

#if 0
	template<class T>
	void push_back(T &&data)
	{
		if (end->next != nullptr)
			end->next->next = new Node(data, nullptr);
		else
			end->next = new Node(data, nullptr);

		end = end->next;
		++this->size;
	}
	void pop_back()
	{
		if (end->next == nullptr)
			throw out_of_range("没有可删除元素!");
		if (end == head)
		{
			delete end->next->next->next;
			end->next->next->next = nullptr;
		}
		else
		{
			delete end->next;
			end->next = nullptr;
		}
		Node *old = head, *ptr = old->next;
		while (ptr != nullptr)
		{
			old = ptr;
			ptr = ptr->next;
		}
		this->end = old;
		--this->size;
	}
#endif
	
private:
	struct Node
	{
	public:
		Node()
		{
			this->next = nullptr;
		}
		Node(T data, Node *next)
		{
			this->data = data;
			this->next = next;
		}
		T data;
		Node *next;
	};
	unsigned size;
	Node *head;
	Node *end;
};

int main()
{
	try
	{
		MyLinkedList<int> link;
		for (int i = 0; i < 10; i++)
		{
			link.push_front(i);
		}
		//for (int i = 0; i < link.getSize(); i++)
		//{
		//	cout << link.at(i) << endl;
		//}
		link.insert(4, 99);
		link.insert(6, 99);
		for (unsigned int i = 0; i < link.getSize(); i++)
		{
			cout << link.at(i) << endl;
		}
		cout << link.back() << endl;
		cout << link.front() << endl;
		for (unsigned i = 0; i < link.getSize(); i++)
		{
			link.pop_front();
		}
	}
	catch (out_of_range &e)
	{
		cout << e.what() << endl;
	}
	
	system("pause");
	return 0;
}
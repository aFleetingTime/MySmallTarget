#include "CircularLinkedList.h"

int main()
{
	CircularLinkedList<int> clist;
	for (int i = 0; i < 5; ++i)
	{
		clist.push_back(i);
	}
	for (int i = 10; i < 15; ++i)
	{
		clist.push_front(i);
	}
	clist.print(1);
	clist.josephusProblem(4);
	clist.print(1);
	system("pause");
	return 0;
}
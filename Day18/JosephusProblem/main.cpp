#include "CircularLinkedList.h"

int main()
{
	CircularLinkedList<int> clist;
	for (int i = 1; i <= 8; ++i)
	{
		clist.push_back(i);
	}
	clist.print(1);
	clist.josephusProblem(3);
	clist.print(1);
	system("pause");
	return 0;
}
#include "CLinkList.h"

typedef struct Person
{
	LinkNode node;
	char name[24];
	int age;
}Person;

void print_fun(LinkNode *node)
{
	Person *temp = (Person*)node;
	printf("ÐÕÃû:%s ÄêÁä:%d\n", temp->name, temp->age);
}

int main()
{
	Person p[5] = 
	{
		{ NULL, "person1", 1 },
		{ NULL,"person2", 2 },
		{ NULL,"person3", 3 },
		{ NULL,"person4", 4 },
		{ NULL,"person5", 5 }
	};

	LinkList *list = init_link();

	for (int i = 0; i < 5; ++i)
		insert_link(list, 0, (LinkNode*)(&p[i]));

	print_link(list, print_fun);

	erase_pos_link(list, 3);

	printf("---------------\n");

	print_link(list, print_fun);

	erase_value_link(list, (LinkNode*)(&p[3]));
	erase_value_link(list, (LinkNode*)(&p[0]));
	erase_value_link(list, (LinkNode*)(&p[4]));

	printf("---------------\n");

	print_link(list, print_fun);


	free_link(list);

	system("pause");
	return 0;
}
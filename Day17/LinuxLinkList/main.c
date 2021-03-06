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
	printf("姓名:%s 年龄:%d\n", temp->name, temp->age);
}

int target = 0;
char compare(LinkNode *node, void *value)
{
	return ((Person*)node)->age == ((Person*)value)->age && !strcmp(((Person*)node)->name, ((Person*)value)->name);
}

int main()
{
	Person p[5] = 
	{
		{ NULL, "person1", 1 },
		{ NULL, "person2", 2 },
		{ NULL, "person3", 3 },
		{ NULL, "person4", 4 },
		{ NULL, "person5", 5 }
	};

	LinkList *list = init_link();

	for (int i = 0; i < 5; ++i)
		insert_link(list, size_link(list), (LinkNode*)(&p[i]));

	print_link(list, print_fun);

	printf("---------------\n");

	Person *per = ((Person*)at_link(list, 4));
	printf("姓名:%s 年龄:%d\n", per->name, per->age);

	printf("---------------\n");
	erase_pos_link(list, 3);
	print_link(list, print_fun);

	printf("---------------\n查找:\n");
	per = (Person*)find_value_link(list, compare, &p[2]);
	if(per != NULL)
		printf("姓名:%s 年龄:%d\n", per->name, per->age);

	printf("---------------\n");

	print_link(list, print_fun);

	erase_value_link(list, (LinkNode*)(&p[3]));
	erase_value_link(list, (LinkNode*)(&p[0]));
	erase_value_link(list, (LinkNode*)(&p[4]));

	printf("---------------\n");

	print_link(list, print_fun);

	printf("---------------\n");
	printf("size:%d\n", size_link(list));

	printf("---------------\n");
	erase_pos_link(list, 0);
	print_link(list, print_fun);

	printf("---------------\n");
	printf("size:%d\n", size_link(list));

	free_link(list);

	system("pause");
	return 0;
}
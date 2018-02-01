#include "CStack.h"

typedef struct Test
{
	Node next;
	char name[64];
	int age;
}Test;

int main()
{
	Stack *stack = init_stack();

	Test ts[5] = {
		{ NULL, "aaa", 10 },
		{ NULL, "bbb", 20 },
		{ NULL, "ccc", 30 },
		{ NULL, "ddd", 40 },
		{ NULL, "eee", 50 }
	};

	for(int i = 0; i < 5; ++i)
		push_stack(stack, (Node*)&ts[i]);

	while (!empty_stack(stack))
	{
		Test *temp = (Test*)top_stack(stack);
		printf("ÐÕÃû:%s  ÄêÁä:%d\n", temp->name, temp->age);
		pop_stack(stack);
	}

	free_stack(&stack);

	system("pause");
	return 0;
}
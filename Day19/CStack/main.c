#include "CStack.h"
#include <string.h>

typedef struct Test
{
	Node next;
	char name[64];
	int age;
}Test;

typedef struct Char
{
	Node node;
	char ch;
	int index;
}Char;

int isLeftBracket(char ch)
{
	return ch == '(';
}

int isRightBracket(char ch)
{
	return ch == ')';
}

Char* createChar(char ch, int index)
{
	Char* buf = (Char*)malloc(sizeof(Char));
	buf->index = index;
	buf->ch = ch;
	return buf;
}

void printError(char *str, int index)
{
	printf("%s\n", str);
	for (int j = 0; j < index; ++j)
		printf(" ");
	printf("��\n");
	
}

int isMatch(char *str)
{
	char *temp = str;
	Stack *stack = init_stack();
	Char *buf = NULL;
	int len = strlen(str);
	int i = 0;
	while (i < len)
	{
		if (isLeftBracket(temp[i]))
		{
			push_stack(stack, (Node*)createChar(temp[i], i));
		}
		else if (isRightBracket(temp[i]))
		{
			Char *ch = (Char*)top_stack(stack);
			if (empty_stack(stack) || !isLeftBracket(ch->ch))
			{
				printError(str, i);
				break;
			}
			else
			{
				pop_stack(stack);
				free(ch);
			}
		}
		++i;
	}
	if (!empty_stack(stack))
	{
		printError(str, i);
	}
	free_value_stack(&stack);
	return 0;
}

int main()
{
	Stack *stack = init_stack();

	//isMatch("(1 + 2 + 3) == (1 + ( 10)");
	isMatch(")((1)) + 2 + 3) == (1 + ( 10)");





#if 0
	Test ts[5] = {
		{ NULL, "aaa", 10 },
		{ NULL, "bbb", 20 },
		{ NULL, "ccc", 30 },
		{ NULL, "ddd", 40 },
		{ NULL, "eee", 50 }
	};

	int A[5] = { 1,2,3,4,5 };

	for (int i = 0; i < 5; ++i)
		push_stack(stack, (Node*)&A[i]);

	while (!empty_stack(stack))
	{
		int *temp = (int*)top_stack(stack);
		printf("Num:%d\n", *temp);
		pop_stack(stack);
	}

	for(int i = 0; i < 5; ++i)
		push_stack(stack, (Node*)&ts[i]);

	while (!empty_stack(stack))
	{
		Test *temp = (Test*)top_stack(stack);
		printf("����:%s  ����:%d\n", temp->name, temp->age);
		pop_stack(stack);
	}
	free_stack(&stack);
#endif

	system("pause");
	return 0;
}
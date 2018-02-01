#include "CStack.h"
#include <string.h>
#include <ctype.h>

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

typedef struct Int
{
	Node node;
	int num;
}Int;


int isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int isLeftBracket(char ch)
{
	return ch == '(';
}

int isRightBracket(char ch)
{
	return ch == ')';
}

int getPriority(char ch)
{
	if (ch == '+' || ch == '-')
	{
		return 1;
	}
	else if (ch == '*' || ch == '/')
	{
		return 2;
	}
	return 0;
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
	printf("¡ü\n");
	
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

void transform(char *str)
{
	Stack *stack = init_stack();
	char *temp = str;
	int index = 0;
	while (*temp != '\0')
	{
		if (isdigit(*temp))
		{
			printf("%c ", *temp);
		}
		else if(isLeftBracket(*temp))
		{
			push_stack(stack, (Node*)createChar(*temp, index));
		}
		else if (isRightBracket(*temp))
		{
			Char *ch = (Char*)top_stack(stack);
			while (!empty_stack(stack) && !isLeftBracket(ch->ch))
			{
				printf("%c ", ch->ch);
				pop_stack(stack);
				free(ch);
				ch = (Char*)top_stack(stack);
			}
			if (ch != NULL && isLeftBracket(ch->ch))
			{
				pop_stack(stack);
				free(ch);
			}
		}
		else if (isOperator(*temp))
		{
			if (empty_stack(stack))
			{
				push_stack(stack, (Node*)createChar(*temp, index));
			}
			else
			{
				Char *ch = (Char*)top_stack(stack);
				if (getPriority(*temp) >= getPriority(ch->ch))
				{
					push_stack(stack, (Node*)createChar(*temp, index));
				}
				else
				{
					while (!empty_stack(stack))
					{
						ch = (Char*)top_stack(stack);
						if (!isLeftBracket(ch->ch))
						{
							printf("%c ", ch->ch);
						}
						if (getPriority(*temp) > getPriority(ch->ch))
						{
							push_stack(stack, (Node*)createChar(*temp, index));
							break;
						}
						pop_stack(stack);
						free(ch);
					}
				}
			}
		}
		++temp;
		++index;
	}
	Char *tempa = NULL;
	while (!empty_stack(stack))
	{
		tempa = (Char*)top_stack(stack);
		printf("%c ", tempa->ch);
		pop_stack(stack);
		free(tempa);
	}
	printf("\n");
	free_value_stack(&stack);
}

Int* make_int(int num)
{
	Int *temp = (Int*)malloc(sizeof(Int));
	temp->num = num;
	return temp;
}

int toNumber(char *str)
{
	char *temp = str;
	Stack *stack = init_stack();
	while (*temp != '\0')
	{
		if (isalnum(*temp))
		{
			push_stack(stack, (Node*)make_int(*temp - '0'));
		}
		else if (isOperator(*temp))
		{
			Int *a = (Int*)top_stack(stack);
			pop_stack(stack);
			Int *b = (Int*)top_stack(stack);
			pop_stack(stack);
			switch (*temp)
			{
			case '+':
				push_stack(stack, (Node*)make_int(b->num + a->num));
				goto FREE;
			case '-':
				push_stack(stack, (Node*)make_int(b->num - a->num));
				goto FREE;
			case '*':
				push_stack(stack, (Node*)make_int(b->num * a->num));
				goto FREE;
			case '/':
				push_stack(stack, (Node*)make_int(b->num / a->num));
			FREE:
				free(a);
				free(b);
			}
		}
		++temp;
	}
	int num = 0;
	if (!empty_stack(stack))
	{
		num = ((Int*)top_stack(stack))->num;
	}
	free_value_stack(&stack);
	return num;
}

int main()
{
	Stack *stack = init_stack();

	//isMatch("(1 + 2 + 3) == (1 + ( 10)");
	transform("(8*(3+1+1+7))*5)");
	printf("%d\n", toNumber("8 3 1 1 7 + + + * 5 *"));
	transform("(8+3+1+1+7)*5)");
	printf("%d\n", toNumber("8 3 1 1 7 + + + + 5 *"));




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
		printf("ÐÕÃû:%s  ÄêÁä:%d\n", temp->name, temp->age);
		pop_stack(stack);
	}
	free_stack(&stack);
#endif

	system("pause");
	return 0;
}
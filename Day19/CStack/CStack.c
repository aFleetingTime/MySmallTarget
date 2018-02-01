#include "CStack.h"

Stack* init_stack()
{
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->head.next = NULL;
	stack->size = 0;
	return stack;
}

void push_stack(Stack *stack, Node *node)
{
	if (stack == NULL || node == NULL)
		return;
	node->next = stack->head.next;
	stack->head.next = node;
	++stack->size;
}

void pop_stack(Stack *stack)
{
	if (stack == NULL || !stack->size)
		return;
	stack->head.next = stack->head.next->next;
	--stack->size;
}

Node* top_stack(Stack *stack)
{
	return stack->head.next;
}

int empty_stack(Stack *stack)
{
	if (stack == NULL)
		return -1;
	return !stack->size;
}

size_t size_stack(Stack *stack)
{
	if (stack == NULL)
		return 0;
	return stack->size;
}

void clear_stack(Stack *stack)
{
	if (stack == NULL)
		return;
	stack->head.next = NULL;
}

void free_stack(Stack **stack)
{
	if (stack != NULL)
	{
		free(*stack);
		*stack = NULL;
	}
}

void free_value_stack(Stack **stack)
{
	if (stack == NULL)
		return;

	Node *cur = (*stack)->head.next, *temp = NULL;
	while (cur != NULL)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	free(*stack);
	*stack = NULL;
}
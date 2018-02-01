#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *next;
}Node;

typedef struct Stack
{
	Node head;
	size_t size;
}Stack;

Stack* init_stack();

void push_stack(Stack *stack, Node *node);

void pop_stack(Stack *stack);

Node* top_stack(Stack *stack);

int empty_stack(Stack *stack);

size_t size_stack(Stack *stack);

void clear_stack(Stack *stack);

void free_stack(Stack **stack);
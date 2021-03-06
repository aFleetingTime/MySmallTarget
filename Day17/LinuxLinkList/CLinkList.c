#include "CLinkList.h"

LinkList* init_link()
{
	LinkList *list = malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}

void insert_link(LinkList *list, size_t pos, LinkNode *value)
{
	LinkNode *p = &list->head;
	for (size_t i = 0; i < pos; ++i)
	{
		p = p->next;
	}
	value->next = p->next;
	p->next = value;
	++list->size;
}

int find_link(LinkList *list, LinkNode *value)
{
	LinkNode *node = list->head.next;
	int count = 0;
	while (node != NULL)
	{
		if (node == value)
			return count;
		node = node->next;
		++count;
	}
	return -1;
}

void erase_pos_link(LinkList *list, size_t pos)
{
	LinkNode *node = &list->head;
	//LinkNode *node = list->head.next;
	for (size_t i = 0; i < pos; ++i)
	{
		node = node->next;
	}
	LinkNode *temp = node->next->next;
	node->next = temp;
	--list->size;
}

void erase_value_link(LinkList *list, LinkNode *value)
{
	LinkNode *node = &list->head;
	while (node != NULL)
	{
		if (node->next == value)
			node->next = node->next->next;
		node = node->next;
	}
	--list->size;
}

LinkNode* at_link(LinkList *list, size_t pos)
{
	LinkNode *node = list->head.next;
	for (size_t i = 0; i < pos; ++i)
	{
		node = node->next;
	}
	return node;
}

size_t size_link(LinkList *list)
{
	return list->size;
}

void free_link(LinkList *list)
{
	//LinkNode *node = list->head.next, *temp = NULL;
	//for (size_t i = 0; i < list->size; ++i)
	//{
	//	temp = node->next;
	//	free(node);
	//	node = temp;
	//}
	free(list);
}

void print_link(LinkList *list, PrintType print_fun)
{
	LinkNode *node = list->head.next;
	while (node != NULL)
	{
		print_fun(node);
		node = node->next;
	}
}

LinkNode* find_value_link(LinkList *list, Compare com, void *value)
{
	LinkNode *node = list->head.next;
	while (node != NULL)
	{
		if (com(node, value))
			return node;
		node = node->next;
	}
	return NULL;
}
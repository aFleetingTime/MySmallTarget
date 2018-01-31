#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct LINKNODE
{
	struct LINKNODE *next;
}LinkNode;

typedef struct LINKLIST
{
	struct LINKNODE head;
	size_t size;
}LinkList;

typedef void(*PrintType)(LinkNode*);
typedef char(*Compare)(LinkNode*, void*);

LinkList* init_link();

void insert_link(LinkList *list, size_t pos, LinkNode *value);

int find_link(LinkList *list, LinkNode *value);

LinkNode* find_value_link(LinkList *list, Compare com, void *value);

void erase_pos_link(LinkList *list, size_t pos);

void erase_value_link(LinkList *list, LinkNode *value);

LinkNode* at_link(LinkList *list, size_t pos);

size_t size_link(LinkList *list);

void free_link(LinkList *list);

void print_link(LinkList *list, PrintType print_fun);


#ifndef _lcthw_List_h
#define _lcthw_List_h

#include <stdlib.h>

struct ListNode;

struct ListNode{
	int value;
	struct ListNode *prev;
	struct ListNode *next;
}ListNode;

struct List{
	int count;
	struct ListNode *first;
	struct ListNode *last;
}List;



struct List *List_create();
void List_destroy(struct List *list);
void List_clear(struct List *list);
void List_clear_destroy(struct List *list);

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->value:NULL)
#define List_last(A) ((A)->last != NULL ? (A)->last->value:NULL)

void List_push(struct List *list, void *value);
void *List_pop(struct List *list);

void List_unshift(struct List *list, void *value);
void *List_shift(struct List *list);

void *List_remove(struct List *list, struct ListNode *node);

#define LIST_FOREACH(L, S, M, V) struct ListNode *_node = NULL; \
	struct ListNode *V = NULL; \
	for(V = _node = L->S; _node !=NULL; V=_node = _node->M)

#endif


#include "lcthw/dbg.h"
#include "lcthw/list.h"

// typedef struct ListNode{
// 	int value;
// 	struct ListNode *prev;
// 	struct ListNode *next
// }ListNode;
// 
// typedef struct List{
// 	int count;
// 	ListNode *first;
// 	ListNode *last;
// }List;

// #define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL; \
// 	ListNode *V = NULL; \
// 	for(V = _node = L->S; _node !=NULL; V=_node = _node->M)

List *List_create()
{
	return calloc(1, sizeof(List));
}
	


void List_destroy(struct List *list)
{
	//ListNode *_node = NULL;
	//ListNode *cur = NULL;
	//for(cur = _node = list->first; cur ! = NULL; cur = _node = _node->next)
	
	//Replace above lines with MACRO, code template
	LIST_FOREACH(list, first, next, cur){
		if(cur->prev){
			free(cur->prev);
		}
	}
	free(list->last);
	free(list);
}

void List_clear(List *list)
{
	LIST_FOREACH(list, first, next, cur){
		free(cur->value);
	}
		
}

void List_clear_destroy(List *list)
{
	List_clear(list);
	List_destroy(list);
}

void List_push(List *list, void *value)
{	
	ListNode *node = calloc(1, sizeof(ListNode));
	check_mem(node);
	node->value = value;
	
	if(list->last == NULL){
		list->first = node;
		list->last  = node;
	}else{
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}
	list->count++;
error:
	return;
	
}

void *List_pop(List *list)
{
	ListNode *node = list->last;
	return node != NULL ? List_remove(list, node): NULL;
}

void List_unshift(List *list, void *value)
{
	ListNode *node = calloc(1, sizeof(ListNode));
	check_mem(node);
	node->value = value;
	
	if(list->first == NULL){
		list->first = node;
		list->last  = node;
	}else{
		list->first->prev = node;
		node->next = list->first;
		list->first = node;
	}
	list->count++;
error:
	return;
}

void *List_shift(List *list)
{
	ListNode* node = list->first;
	return node != NULL? List_remove(list, node):NULL;
}

void *List_remove(List *list, ListNode *node)
{
	void *result = NULL;
	check(list->first && list->last, "Invalid List");
	check(node, "Node can't be NULL");
	
	if(node == list->first && node == list->last){
		list->first = NULL;
		list->last  = NULL;
	}else if(node == list->first){
		list->first = node->next;
		check(list->first != NULL, " invalid list, first is NULL");
		list->first->prev = NULL;
	}else if(node == list->last){
		list->last = node->prev;
		check(list->last != NULL, " invalid list, last is NULL");
		list->last->next = NULL;
	}else{
		ListNode *before = node->prev;
		ListNode *after  = node->next;
		
		before->next = after;
		after->prev  = before;
	}
	
	list->count--;
	result = node->value;
	free(node);
error:
	return result;
	
}




























#include "dbg.h"
#include "list.h"
#include <stdio.h>
//#include <stdlib.h>

// #define LIST_FOREACH(L, S, M, V) struct ListNode *_node = NULL; \
// 	struct ListNode *V = NULL; \
// 	for(V = _node = L->S; _node !=NULL; V=_node = _node->M)

struct List *List_create()
{
	return calloc(1, sizeof( struct List));
}
// 
void List_destroy(struct List *list)
{
	// struct ListNode *_node = NULL;
	// 	struct ListNode *cur = NULL;
	// 	for(cur = _node= list->first; _node != NULL; cur=_node= _node->next)

	//Replace the common code with macro defined LIST_FOREACH
	//Template Programming
	
	LIST_FOREACH(list, first, next, cur){
		if(cur->prev){
			free(cur->prev);
		}
	}
}

int main(int argc, char *argv[])
{
	return 0;
}
#ifndef _stack_h
#define _stack_h

#include <lcthw/list.h>

typedef List Stack;

#define Stack_create() List_create()
#define Stack_destroy(S) List_destroy(S)
#define Stack_push(S,V) List_push(S,V)
#define Stack_peek(S) List_last(S)
#define Stack_pop(S) List_pop(S)
#define Stack_count(S) List_count(S)
#define Stack_first(S) List_first(S)
#define Stack_last(S) List_last(S)

#define STACK_FOREACH(S,M) \
		ListNode *M = NULL; \
		for(M=S->first; M != NULL; M = M->next)
		
#define STACK_FOREACH_REVERSE(S,M)\
		ListNode *M = NULL; \
		for(M=S->last; M != NULL; M = M->prev)
		
#define STACK_FOREACH_ZED(S,M) LIST_FOREACH(S, first, next, M)
#define STACK_FOREACH_ZED_REV(S,M) LIST_FOREACH(S, last, prev, M)
#endif
#ifndef _queue_h
#define _queue_h

#include <lcthw/list.h>

typedef List Queue;

#define Queue_create() List_create()
#define Queue_destroy(S) List_destroy(S)
#define Queue_send(S,M) List_push(S,M)
#define Queue_recv(S) List_shift(S)
#define Queue_peek(S) List_first(S)
#define Queue_count(S) List_count(S)
#define Queue_first(S) List_first(S)
#define Queue_last(S) List_last(S)

#define QUEUE_FOREACH(S, M) \
		ListNode *M = NULL; \
		for(M = S->first; M != NULL ; M = M->next)
	
#define QUEUE_FOREACH_REVERSE(S, M)\
	ListNode *M = NULL; \
	for(M = S->last; M != NULL ; M = M->prev)
	
#define QUEUE_FOREACH_ZED(S,M) LIST_FOREACH(S, first, next, M)
#define QUEUE_FOREACH_ZED_REV(S,M) LIST_FOREACH(S, last, prev, M)

#endif
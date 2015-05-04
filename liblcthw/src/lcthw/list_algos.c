#include "list_algos.h"
#include "dbg.h"
#include <string.h>
#include <assert.h>

int count =0; 
int List_bubble_sort_for(List *list, List_compare cmp)
{
	check(list != NULL , "List is invalid");
	count =0;
	if(List_count(list) <= 1)
		return 0;
	
	ListNode *_node = NULL;
	ListNode *cur = NULL;
	ListNode *cur1 = NULL;
	for(cur=_node=list->first; cur!= NULL; cur=_node=_node->next){
		for(cur1 = list->first; cur1 != list->last; cur1 = cur1->next){	
			if(cmp(cur1->value, cur1->next->value) >0)
			{
				count++;
			    printf("%d: %s : %s\n", count, cur1->value, cur1->next->value);
				char *value = cur1->next->value;
 				cur1->next->value = cur1->value;
 				cur1->value = value;
			}
		}
		
	}
	
	return 0;

error:
	return 1;
}


inline void ListNode_swap(ListNode *a, ListNode *b)
{
    void *temp = a->value;
    a->value = b->value;
    b->value = temp;
}

int List_bubble_sort(List *list, List_compare cmp)
{
    int sorted = 1;

    if(List_count(list) <= 1) {
        return 0;  // already sorted
    }

    do {
        sorted = 1;
        LIST_FOREACH(list, first, next, cur) {
            if(cur->next) {
                if(cmp(cur->value, cur->next->value) > 0) {
                    ListNode_swap(cur, cur->next);
                    sorted = 0;
                }
            }
        }
    } while(!sorted);

    return 0;
}

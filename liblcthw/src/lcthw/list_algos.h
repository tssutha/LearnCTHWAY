#ifndef _list_algos_h
#define _list_algos_h

#include <stdlib.h>
#include "list.h"

typedef int (*List_compare)(const void *s1, const void *s2);

int List_bubble_sort(List *list, List_compare cmp);
int List_bubble_sort_for(List *list, List_compare cmp);


#endif
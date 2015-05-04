#include "minunit.h"
#include <lcthw/list_algos.h>
#include <assert.h>
#include <string.h>


char *values[] = { "xxxx", "1234", "abcd", "xjvef", "ndss" };
//char *values[] = { "123", "125", "120", "129", "121"};
#define NUM_VALUES  5

List *create_words()
{
	List *words = List_create();
	for(int i=0; i < NUM_VALUES; i++){
		List_push(words, values[i]);
	}
	
	return words;
}

int check_count(List *words)
{
	return List_count(words);
}

int is_sorted(List *words)
{
	LIST_FOREACH(words, first, next, cur){
		if(cur->next){
			log_info("+++%s : %s\n", cur->value, cur->next->value);
			if(strcmp(cur->value, cur->next->value) > 0){
				debug("%s %s", (char*)cur->value, (char*)cur->next->value);
				return 0;
			}
		}
		
	}
	return 1;
}

void print_words(List *words)
{	
	LIST_FOREACH(words, first, next, cur){
		log_info("%s ", cur->value);
	}
	
}

char *test_bubble_sort()
{
	List *words = create_words();
	
	print_words(words);
	//should work on a list that needs sorting 
	//log_info("+++++++++++++++++++%d", check_count(words));
	
	
	int rc =  List_bubble_sort(words, (List_compare)strcmp);
	mu_assert(rc==0, " Bubble sort failed");
	mu_assert(is_sorted(words), "words are not sorted after bubble sort");
	
	rc = List_bubble_sort(words, (List_compare)strcmp);
	mu_assert(rc==0, "bubble sort of already sorted array");
	mu_assert(is_sorted(words), "Words should be sorted if already bubble sorted");
	
	
	print_words(words);
	List_destroy(words);
	
	words = create_words();
	rc = List_bubble_sort(words, (List_compare)strcmp);
	mu_assert(rc==0, "Bubble sort failed");
	mu_assert(is_sorted(words), "words are not sorted after bubble sort for");
	
	mu_assert(check_count(words)==5, "count mismatch");
	List_destroy(words);
	
	//should work on an empty list
	words = List_create();
	rc = List_bubble_sort(words, (List_compare)strcmp);
	mu_assert(rc==0, "Bubble sort failed on empty list");
	mu_assert(is_sorted(words), "Words should be sorted if empty");
	
	
	
	List_destroy(words);
	
	return NULL;
}

char *all_tests()
{
	mu_suite_start();
	
	//mu_run_test(test_bubble_sort);
	//mu_run_test(test_merge_sort);
	
	return NULL;
}

RUN_TESTS(all_tests);
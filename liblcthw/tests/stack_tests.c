#include "minunit.h"
#include <lcthw/stack.h>
#include <assert.h>

static Stack *stack =  NULL;
char *tests[] = { "test1 data", "test2 data", "test3 data"};
#define NUM_TESTS 3

char *test_create()
{
	stack = Stack_create();
	mu_assert(stack != NULL, "failed to create a stack");
	return NULL;
}

char *test_destroy()
{
	mu_assert(stack != NULL, "Failed to make stack #");
	Stack_destroy(stack);
	return NULL;
}

char *test_push_pop()
{
	int i=0;
	for(i=0; i < NUM_TESTS; i++){
		Stack_push(stack, tests[i]);
		mu_assert(Stack_peek(stack) == tests[i], "Wrong next value");
		
	}
	
	mu_assert(Stack_count(stack) == NUM_TESTS, "Wrong count on push");
	
	
	// ListNode *cur = NULL;
// 	for(cur = stack->first; cur != NULL; cur = cur->next){
// 		debug("VAL : %s", (char*)cur->value);
// 	}


	 STACK_FOREACH(stack, cur){
 		debug("VAL : %s", (char*)cur->value);
 	 }
 	 
 	 debug("+++++++++++++++++++++++");
 	 
 	 STACK_FOREACH_REVERSE(stack, curR){
 	 	debug("VAL : %s", (char*)curR->value);
 	 }
 	 
 	 
	
	for(i=NUM_TESTS-1; i>=0; i--){
		char *val = Stack_pop(stack);
		mu_assert(val == tests[i], "Wrong value on pop");
	}
	
	mu_assert(Stack_count(stack) == 0, "Wrong count after pop");
	return NULL;
}

char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_create);
	mu_run_test(test_push_pop);
	mu_run_test(test_destroy);
	
	return NULL;
}

RUN_TESTS(all_tests)


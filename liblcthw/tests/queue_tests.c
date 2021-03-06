#include "minunit.h"
#include <lcthw/queue.h>
#include <assert.h>

static Queue *queue = NULL;
char *tests[] = { "test 1 data", "test 2 data", "test 3 data"};
#define NUM_TESTS 3

char *test_create()
{
	queue = Queue_create();
	mu_assert(queue != NULL, " Failed to create queue");
	return NULL;
}

char *test_destroy()
{
	mu_assert(queue != NULL, "Failed to create queue");
	Queue_destroy(queue);
	return NULL;
}

char *test_send_recv()
{
	int i =0;
	for(i=0; i <NUM_TESTS; i++){
		Queue_send(queue, tests[i]);
		mu_assert(Queue_peek(queue) == tests[0], "Wrong Next Value");
	}
	
	mu_assert(Queue_count(queue) == NUM_TESTS, "Wrong count on send");
	
	 QUEUE_FOREACH(queue, cur){
		debug("VAL: %s", (char*)cur->value);
	}
	
	debug("+++++++++++++++++++");
	
	QUEUE_FOREACH_REVERSE(queue, curR){
		debug("RVAL: %s", (char*)curR->value);
	}
	
	for(i=0; i <NUM_TESTS; i++){
		char *val = Queue_recv(queue);
		mu_assert(val == tests[i], "Wrong value on recv");
	}
	
	mu_assert(Queue_count(queue) == 0, "Wrong count after recv");
	
	return NULL;
}


char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_create);
	mu_run_test(test_send_recv);
	mu_run_test(test_destroy);
	
	return NULL;
}


RUN_TESTS(all_tests)
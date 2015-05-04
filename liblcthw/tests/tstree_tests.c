#include "minunit.h"
#include <lcthw/tstree.h>
#include <string.h>
#include <assert.h>
#include <lcthw/bstrlib.h>


TSTree *node = NULL;
char *valueA = "VALUEA";
char *valueB = "VALUEB";
char *value2 = "VALUE2";
char *value4 = "VALUE4";
char *reverse = "VALUER";

int traverse_count = 0;

struct tagbstring test1 = bsStatic("TEST");
struct tagbstring test2 = bsStatic("TEST2");
struct tagbstring test3 = bsStatic("TSET");
struct tagbstring test4 = bsStatic("T");

char *test_insert()
{
	node = TSTree_insert(node, bdata(&test1), blength(&test1), valueA);
	mu_assert(node != NULL, "Failed to insert a node into TST");
	
	node = TSTree_insert(node, bdata(&test2), blength(&test2), value2);
	mu_assert(node != NULL, "Failed to insert into TST with second value");
	
	node = TSTree_insert(node, bdata(&test3), blength(&test3), reverse);
	mu_assert(node != NULL, "Failed to insert into TST with reverse name");
	
	node = TSTree_insert(node, bdata(&test4), blength(&test4), value4);
	mu_assert(node != NULL, "Failed to insert into TST with second name.");
	
	return NULL;
}

char *test_search_exact()
{
	//TST returns the last one inserted 
	void *res = TSTree_search(node, bdata(&test1), blength(&test1));
	mu_assert(res == valueA, "Got the wrong value vack, should get A not B");
	
	//TST does not find if not exact
	res = TSTree_search(node, "TESTNO", strlen("TESTNO"));
	mu_assert(res == NULL, "should not find anything");
	
	return NULL;
}

char *test_search_prefix()
{
	void *res = TSTree_search_prefix(node, bdata(&test1), blength(&test1));
	debug("result : %s, expected: %s", res, valueA);
	mu_assert(res == valueA, "got wrong valueA by prefix");
	
	res  = TSTree_search_prefix(node, bdata(&test1), 1);
	debug("result: %s expected : %s", res, value4);
	mu_assert(res == value4, "got wrong value4 for prefix of 1.");
	
	res = TSTree_search_prefix(node, "TE", strlen("TE"));
	debug("result: %s ----expected : %s", res, valueA);
	mu_assert(res != NULL, "should find for short prefix");
	
	res = TSTree_search_prefix(node, "TE--", strlen("TE--"));
	debug("result: %s ----expected : %s", res, valueA);
	mu_assert(res != NULL, "should find for partial prefix");
	
	return NULL;
	
}

void TSTree_traverse_test_cb(void *value, void *data)
{
	assert(value != NULL && "Should not get NULL value");
	assert(data == valueA && "expecting valueA as the data");
	traverse_count++;
}

char *test_traverse()
{
	traverse_count =0;
	TSTree_traverse(node, TSTree_traverse_test_cb, valueA);
	debug("traverse count is : %d", traverse_count);
	mu_assert(traverse_count == 4, "Didn't find 4 keys");
	
	return NULL;
}

char *test_destroy()
{
	TSTree_destroy(node);
	return NULL;
}



char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_insert);
	mu_run_test(test_search_exact);
	mu_run_test(test_search_prefix);
	mu_run_test(test_traverse);
	mu_run_test(test_destroy);
	
	
	return NULL;
}

RUN_TESTS(all_tests);
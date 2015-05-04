#include <lcthw/string_algos.h>
#include <lcthw/bstrlib.h>
#include "minunit.h"
#include <time.h>


struct tagbstring IN_STR = bsStatic("I have ALPHA beta ALPHA and oranges ALPHA");
struct tagbstring ALPHA = bsStatic("ALPHA");
const int TEST_TIME = 1;

char *test_find_and_scan()
{	
	StringScanner *scan = StringScanner_create(&IN_STR);
	mu_assert(scan != NULL, "Failed to make the scanner");
	printf("test step 0   %p\n", scan);
    int find_i = String_find(&IN_STR, &ALPHA);
    mu_assert(find_i > 0, "Failed to find ALPHA in test string");
	
	printf("test step 0   %p\n", scan);
	//printf("len = %d \n", (int)scan->hlen);
	printf("test step 1\n");
	//int scan_i = StringScanner_scan(scan, &ALPHA);
	//mu_assert(scan_i >0, "Failed to find ALPHA in test string");
	//mu_assert(scan_i = find_i, "find and scan don't match");
	
// 	scan_i = StringScanner_scan(scan, &ALPHA);
// 	mu_assert(scan_i > find_i, "should find another ALPHA after the first");
// 	
// 	scan_i = StringScanner_scan(scan, &ALPHA);
// 	mu_assert(scan_i > find_i, "should find another ALPHA after the first");
// 	
// 	mu_assert(StringScanner_scan(scan, &ALPHA) == -1, "Shouldn't find it");
// 	
	StringScanner_destroy(scan);
	
	return NULL;
}

char *all_tests()
{
	//mu_suite_start();
	
	//mu_run_test(test_find_and_scan);
}

RUN_TESTS(all_tests);
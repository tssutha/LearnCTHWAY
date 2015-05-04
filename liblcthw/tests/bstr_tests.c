#include "minunit.h"
#include "lcthw/bstrlib.h"

char *test_bstrcpy()
{
	return NULL;
}

char *test_bstrlen()
{
	char *test1 = "suthakaran";
	bstring b = bfromcstr(test1);
	mu_assert(binstr(b, 0, "suthakaran") != BSTR_ERR, "Test Failed");
	
	
	return NULL;
}

char *test_bfromcstr()
{	
	return NULL;
	
}

char *all_tests()
{
	mu_suite_start();
	//mu_run_test(test_bstrcpy);
	//mu_run_test(test_bstrlen);
	//mu_run_test(test_bfromcstr);
	
	return NULL;
	
}

RUN_TESTS(all_tests);
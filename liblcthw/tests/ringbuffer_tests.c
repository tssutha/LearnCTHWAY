#include "minunit.h"
#include <lcthw/ringbuffer.h>


RingBuffer *buffer = NULL;
#define LENGTH 5

struct tagbstring test1 = bsStatic("ab");
struct tagbstring test2 = bsStatic("33");


char *test_create()
{
	buffer = RingBuffer_create(LENGTH);
	mu_assert(buffer != NULL, "failed to create ringbuffer");
	mu_assert(buffer->end == 0 && buffer->start ==0 , "start, end failed to set");
	
	return NULL;
	
}

char *test_write_read()
{
	int rc = RingBuffer_write(buffer, bdata(&test1), blength((bstring)&test1));
	mu_assert(rc==2, "failed to write data");
	mu_assert(buffer->start ==0 && buffer->end == 2, "failed to set start and end 1");
	
	rc = RingBuffer_write(buffer, bdata(&test2), blength((bstring)&test2));
	mu_assert(rc ==2, "failed to write data");
	mu_assert(buffer->start ==0 && buffer->end == 4, "failed to set start and end 2");
	
	rc = RingBuffer_write(buffer, bdata(&test1), blength((bstring)&test1));
	mu_assert(rc == -1, "should fail to write data");
	
	char ret[5] = {0};
	rc = RingBuffer_read(buffer,ret,3);
	mu_assert(rc == 3, "failed to read");
	
	ret[4] = '\0';
	
	fprintf(stderr, "%s\n:", ret);
	
	//mu_assert(bdata(ret) == "ab3", "failed to read correct data");
	mu_assert(buffer->start == 3 && buffer->end == 4, "failed to set start and end after read");
	mu_assert(RingBuffer_available_space(buffer) == 4, "failed return available space");
	 
	
	
	
	
	
	
	return NULL;
	
}

char *test_destroy()
{
	mu_assert(buffer != NULL, "failed to create ring buffer");
	RingBuffer_destroy(buffer);
	
	return NULL;
}


char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_create);
	mu_run_test(test_write_read);
	
	
	
	
	mu_run_test(test_destroy);
	
	return NULL;
}

RUN_TESTS(all_tests);
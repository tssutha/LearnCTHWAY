#include <stdio.h>
#include <string.h>
#include "dbg.h"

//#define TEST_DEBUG

// #define MY_COPY_DEVICE(M,N,C,D) {     \
// 	int t = (D + 7)/8;                \
// 	int i =0;                         \
// 	duffs_device(M,N, D%8)            \
// 	                                  \
// 	for(i=0; i<t-1; i++){             \
// 	
// 		
// 		duffs_device(M,N,
// 	}
// 	
// 
// } 

int  normal_copy(char *from, char *to, int count)
{
	int i =0;
	for(i=0; i < count; i++){
		to[i] = from[i];
	}
	return i;
}

//duffs version
int duffs_device(char *from, char *to, int count)
{
	{
		int n = (count + 7)/8;
		
		switch(count % 8){
			case 0: {
					do {
						printf("Entry do-while : n = %d \n", n);
						*to++ = *from++;
						case 7:{
							 *to++ = *from++;
							 printf("case 7 : n = %d \n", n);
							 }
						case 6:{
							 *to++ = *from++;
							 printf("case 6 : n = %d \n", n);
							 }
						case 5:{
							 *to++ = *from++;
							 printf("case 5 : n = %d \n", n);
							 
							 }
						case 4: {
							*to++ = *from++;
							printf("case 4 : n = %d \n", n);
							}
						case 3: {
							*to++ = *from++;
							printf("case 3 : n = %d \n", n);
							}
						case 2: {
							*to++ = *from++;
							printf("case 2 : n = %d \n", n);
							}
						case 1:{
							 *to++ = *from++;
							printf("case 1 : n = %d \n", n);
						 	}
						 printf("------------------\n");
					}while(--n > 0);
			}
		}
	}
	return count;
}

int zed_device(char *from, char *to, int count)
{
	{
		int n = (count + 7)/8;

		switch(count % 8){
			case 0:
			{
				again : *to++ = *from++;
				printf("case 0 : n = %d \n", n);
			}
			
			case 7:{
				 *to++ = *from++;
				 printf("case 7 : n = %d \n", n);
				 }
			case 6:{
				 *to++ = *from++;
				 printf("case 6 : n = %d \n", n);
				 }
			case 5:{
				 *to++ = *from++;
				 printf("case 5 : n = %d \n", n);
				 }
			case 4:{
				 *to++ = *from++;
				 printf("case 4 : n = %d \n", n);
				 }
			case 3: {
				*to++ = *from++;
				printf("case 3 : n = %d \n", n);
				}
			case 2:{
				 *to++ = *from++;
				 printf("case 2 : n = %d \n", n);
				 }
			case 1: {
				*to++ = *from++;
				printf("case 1 : n = %d \n", n);
				}
				printf("----------------------\n");
				if(--n > 0) goto again;
			
			

		}
	}
	
	return count;
}

int valid_copy(char *data, int count, char expects)
{	
	int i=0;
	for(i =0; i < count; i++){
		if(data[i] != expects){
			log_err("[%d] %c != %c", i , data[i], expects);
			return 0;
		}
	}
	
	return 1;
	
}
void print_array(const char *data)
{	
	printf("%s\n", data);
}

int main(int argc, char *argv[])
{
	char from[1000] = { 'a' };
	char to[1000]   = { 'c' };
	int rc = 0;
	
#ifdef TEST_DEBUG
	print_array(from);
	print_array(to);
#endif
	
	//setup the from to have some staff
	memset(from, 'x', 1000);
	//set it to a failure mode
	memset(to, 'y', 1000);
	
#ifdef TEST_DEBUG
	print_array(from);
	print_array(to);
#endif
	check(valid_copy(to, 1000, 'y'), "Not Initialised right.");
	
	
	//use normal copy to
	rc = normal_copy(from, to, 1000);
	check(rc == 1000, "Normal copy Failed : %d ", rc);
	check(valid_copy(to, 1000, 'x'), "Normal copy failed");
	
	//memory reset
	memset(to, 'y', 1000);
	
	//duffs version
	rc = duffs_device(from, to,1000);
	check(rc == 1000, "Duff's device failed : %d", rc);
	check(valid_copy(to, 1000, 'x'), "Duff's device failed");
	
	//memory reset
	memset(to, 'y', 1000);
	
	rc = zed_device(from, to, 1000);
	check(rc == 1000, "Zed's device failed : %d", rc);
	check(valid_copy(to, 1000, 'x'), "Zed's device failed");
	
	
	
	
	
	
	
	
	
	return 0;
error:
	return 1;
}
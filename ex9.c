#include <stdio.h>

int main(int argc, char *argv[])
{
	int numbers[4] = {0};
	char name[4] = {'a'};
	
	//first print them out raw
	printf("numbers %d %d %d %d \n",
	         numbers[0], numbers[1], numbers[2], numbers[3]);
	        
	printf("name each: %c %c %c %c \n",
	        name[0], name[1], name[2], name[3]);
	        
	printf("name %s\n", name);
	
	//setup the numbers 
	numbers[0] = 'Z';
	numbers[1] = 'e';
	numbers[2] = 'd';
	numbers[3] = '\0';
	
	//setup the name 
	name[0] = 101;
	name[1] = 102;
	name[2] = 103;
	name[3] =  104;
	
	//then print them out initialised
	printf("numbers %d %d %d %d \n",
	         numbers[0], numbers[1], numbers[2], numbers[3]);
	        
	printf("name each: %c %c %c %c \n",
	        name[0], name[1], name[2], name[3]);
	
	//Print the name like string 
	printf("name : %s\n", name);
	
	//another way to define the name
	char *another = "Zed";
	
	printf("another : %s\n", another);
	
	printf("another each : %c %c %c %c \n", 
	        another[0], another[1], another[2], another[3]);
	
	        
	return 0;
}
#include <stdio.h>

int main(int argc, char *argv[])
{	
	if(argc == 1)
	{
		printf("You only have one argument. You suck \n");
	}
	else if(argc > 1 && argc < 4)
	{
		printf("Here's your arguments \n");
		for(int i =0; i < argc; i++)
		{
			printf("Arg %d : %s\n", i , argv[i]);
		}
	}
	else
	{
		printf("You have too many arguments. You suck. \n");
	}
	
	//Use of comma operator in loop 
     int i =0;
     for(i =0; i++, i < 5;)
     {
     	printf(" Index = %d \n", i);
     }
	
	return 0;
}
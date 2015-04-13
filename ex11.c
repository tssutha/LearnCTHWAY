#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i =0;
	
	while(i <argc)
	{
		printf("arg %d : %s \n", i , argv[i]);
		i++;
	}
	
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};
	
	int num_states = 4;
	i =0;
	while(i < num_states)
	{
		printf("State %d : %s\n", i , states[i]);
		i++;
	}
	
	
	printf("Iterate loops backward \n");
	
	i = argc;
	
	while(i > 0)
	{
		printf("Arg %d : %s \n", i, argv[i-1]);
		i--;
	}
	
	i = num_states;
	while(i > 0)
	{
		printf("States %d : %s\n", i, states[i-1]);
		i--;
	}
	
	//Copy Argv to States 
	int nNumOfArgsToCopy = argc > num_states ? num_states : argc -1;
	i =0;
	printf("NumOfArgsToCopy : %d\n", nNumOfArgsToCopy);
	
	
	//Use new function strdup which do deep copy of string and manange 
	//memory automatically
	while(i < nNumOfArgsToCopy)
	{
		//strcpy(states[i], argv[i+1]);
		printf(" Itearte = %d \n", i);
		states[i] = strdup(argv[i+1]);
		i++;
	}
	
	i =0;
	while(i < num_states)
	{
		printf("State %d : %s \n", i , states[i]);
		i++;
	}
	

	
	
	return 0;
}
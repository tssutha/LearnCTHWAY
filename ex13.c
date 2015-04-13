#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//convert a char to lowercase
char mytolower(char c)
{
	if( c < 0x41 || c > 0x5A)
		return c;
	else
		return c|0x60;

}

//convert a string to lover case
char* mylowercasestr(char *str)
{
	for(;*str; ++str) *str = mytolower(*str);
	
	char *test = (char*) malloc(sizeof(char) * strlen(str));
	strcpy(test, str);
	printf("Test %s \n", test);
	return test;
}


int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("ERRRO : You need one argument. \n");
		//This is how you abort the program
		return 1;
	}
	
	mylowercasestr(argv[1]);
	printf("%s\n", argv[1]);
	//printf("%s\n", test);
	
	int i =0;
	for(i =0; i < argv[1][i] != '\0'; i++)
	{
		char letter = argv[1][i];
		letter = mytolower(letter);
		
		switch(letter)
		{
		case 'a':
		//case 'A':
			printf("%d: 'A'\n", i);
		break;
		
		case 'e':
		//case 'E':
			printf("%d: 'E'\n", i); 
		break;
		
		case 'i':
		//case 'I':
			printf("%d: 'I'\n", i);
		break;
		
		case 'o':
		//case 'O':
			printf("%d: 'O'\n", i);
		break;
		
		case 'u':
		//case 'U':
			printf("%d: 'U'\n", i);
		break;
		
		case 'y':
		//case 'Y':
			if(i > 2)
			{
				//it's only sometimes Y
				printf("%d : 'Y'\n", i);
				
			}
			break;
			
		
		default:
			printf("%d: %c is not a vowel\n", i, letter);
			
		}
	}
	
	return 0;
}
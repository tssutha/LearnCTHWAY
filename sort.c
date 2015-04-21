#include <stdio.h>
#include <stdlib.h>


int itr =0;
void print_array(int *numbers, int count)
{
	for(int i =0; i < count; i++)
		printf(" %d", numbers[i]);
	
	printf("\n");
}

void quicksort(int *numbers, int left, int right, int count)
{
	int i = left, j = right;
	int pivot_idx  = (left + right )/2;
	int pivot = numbers[pivot_idx];
	
	printf("Step 1  i =%d j = %d\n", i, j);
	
	while( i <= j){
		while(numbers[i] < pivot)
			i++;
			
		//printf("Step 2\n");
		while(numbers[j] > pivot){
		
			j++;
			//printf("Step 2.1  j = %d\n", j);
		}
		//printf("Step 3\n");
		if(i <= j){
			int temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
			
			i++;
			j--;
			//printf("Step 4\n");
		}
	}
	
	printf("iteratio %d  left=%d  j =%d  i =%d right =%d : \n",
			 itr++, left, j, i, right); 
	print_array(numbers, count);
	
	if(left < j)
		quicksort(numbers, left, j, count);
	if(right > i)
		quicksort(numbers, i, right, count);
}



void sort(int *numbers, int count)
{
	quicksort(numbers, 0, count-1, count);
}

int main( int argc, char *argv[])
{
	if(argc < 2)
		return 1;
	
	int *numbers = malloc (sizeof(int) * (argc -1));
	
	for(int i =1; i < argc; i++){
		numbers[i-1] = atoi(argv[i]);
	}
	
	printf("Before Sorted\n");
	print_array(numbers, argc -1);
	printf("-------------\n");
	
	sort(numbers, argc-1);
	
	printf("-------------\n");
	printf("After Sorted\n");
	print_array(numbers, argc -1);
	
	return 0;
	
}















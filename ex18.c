#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*Exit function*/
void die(const char *message)
{
	if(errno){
		perror(message);
	}else{
		printf("ERROR : %s\n", message);
	}
}

//Define a new type , function pointer

typedef int (*compare_cb)(int a , int b);

/*
	classis  bubble sort that uses the compare_cb 
	to do something
*/
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int i =0, j =0, temp =0;
	int *target = malloc(sizeof(int)*count);
	if(!target){
		die("Memory Error");
	}	
	memcpy(target, numbers, sizeof(int)*count);
	
	for(i=0; i <count; i++){
		for(j=0; j<count-1;j++){
			if(cmp(target[j], target[j+1]) > 0){
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}
	return target;
}



int sorted_order(int a , int b)
{
	return a-b;
}

int reverse_order(int a, int b)
{
	return b-a;
}

int strange_order(int a, int b)
{
	if(a==0 || b ==0){
		return 0;
	}else {
		return a % b;
	}
}

//Quick sort implementation
void quicksort(int a[], int low, int high)
{
	int pivot =0;
	if(low < high)
	{
		pivot = partition(a, low, high);
		quicksort(a, low, pivot-1);
		quicksort(a, pivot+1, high);
		
	}
	
}

void partition(int a[], int low, int high)
{
	int left, right;
	int pivot_index;
	int pivot_item;
	pivot_index = left = low;
	pivot_item = a[low];
	right = high;
	while(left < right)
	{
		while(a[left] < pivot_item)
			left++;
		while(a[right] > pivot_item)
			right--;
		if(left < right)
		{
			int temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
	}
	
	a[low] = a[right];
	a[right] = pivot_item;
	return right;
	
}


/**
	Use to test we are sorting things correctly 
	by doing the sort and printing it out
**/
void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i =0;
	int *sorted = bubble_sort(numbers, count, cmp);
	
	unsigned char *data = (unsigned char*)cmp;
	for(i=0; i < 25; i++){
		printf("%02x:", data[i]);
	}
	
	if(!sorted){
		die("Failed to sort as requested.");
	}
	for(i=0; i <count; i++){	
		printf("%d ", sorted[i]);
	}
	printf("\n");
	free(sorted);
}


int main(int argc, char *argv[])
{
	if(argc < 2){
		die("USAGE: ex18 4 3 1 5 6");
	}
	
	int count = argc - 1;
	int i =0;
	char **inputs = argv + 1;
	
	int *numbers = malloc(count * sizeof(int));
	if(!numbers){
		die("Memory Error");
	}
	
	for(i=0; i < count ; i++){
		numbers[i] = atoi(inputs[i]);
	}
	
	test_sorting(numbers, count, NULL);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);
	
	free(numbers);
	
	return 0;
}
















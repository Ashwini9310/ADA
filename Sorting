#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int minIndex(int arr[], int i, int j) 
{ 
	if (i == j) 
		return i; 

	int k = minIndex(arr, i + 1, j); 

	return (arr[i] < arr[k])? i : k; 
} 


void recurSelectionSort(int arr[], int n, int index) 
{ 
    int temp;

	if (index == n) 
	return; 


	int k = minIndex(arr, index, n-1); 


	if (k != index) {
	    temp = arr[k];
        arr[k] = arr[index];
        arr[index] = temp;
    }

	recurSelectionSort(arr, n, index + 1); 
} 

int main() 
{ 
    int size,i,n;
    clock_t start, end;
    
    printf("Enter the size of the list: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        int no = rand() % n + 1;
        arr[i] = no;

    }
    start = clock();
	recurSelectionSort(arr, n,0); 
    end = clock();
     float ti = ((double)(end - start)/CLOCKS_PER_SEC);
	for (int i = 0; i<n ; i++) 
		printf("%d ",arr[i]);
    printf("\nTime taken: %f", ti);
	return 0; 
} 

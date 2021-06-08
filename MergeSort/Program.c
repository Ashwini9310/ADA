#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void mergeSort(int [], int, int, int);
void partition(int [],int, int);
 
int main()
{

    int i,n;
    clock_t start, end;
 
    printf("Enter total number of elements:");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        int no = rand() % n + 1;
        arr[i] = no;

    }
    start = clock();
	 partition(arr, 0, n - 1);
    end = clock();
     float ti = ((double)(end - start)/CLOCKS_PER_SEC);
    partition(arr, 0, n - 1);
    printf("After merge sort:\n");
    for(i = 0;i < n; i++)
    {
         printf("%d   ",arr[i]);
    }
    printf("\nTime taken: %f", ti);
   return 0;
}
 
void partition(int arr[],int low,int high)
{
    int mid;
 
    if(low < high)
    {
        mid = (low + high) / 2;
        partition(arr, low, mid);
        partition(arr, mid + 1, high);
        mergeSort(arr, low, mid, high);
    }
}
 
void mergeSort(int arr[],int low,int mid,int high)
{
    int i, mi, k, lo, temp[50];
 
    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high))
    {
        if (arr[lo] <= arr[mi])
        {
            temp[i] = arr[lo];
            lo++;
        }
        else
        {
            temp[i] = arr[mi];
            mi++;
        }
        i++;
    }
    if (lo > mid)
    {
        for (k = mi; k <= high; k++)
        {
            temp[i] = arr[k];
            i++;
        }
    }
    else
    {
        for (k = lo; k <= mid; k++)
        {
             temp[i] = arr[k];
             i++;
        }
    }
 
    for (k = low; k <= high; k++)
    {
        arr[k] = temp[k];
    }
}

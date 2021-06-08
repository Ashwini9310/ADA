#include <stdio.h>
#include <time.h>
#include<stdlib.h>

  // Function to swap the the position of two elements
  void swap(int *a, int *b) 
  {
     int temp = *a;
     *a = *b;
     *b = temp;
   }
  
  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) 
    {
       swap(&arr[i], &arr[largest]);
       heapify(arr, n, largest);
    }
  }
  
  void heapSort(int arr[], int n) 
  {
     // Build max heap
     for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
     // Heap sort
      for (int i = n - 1; i >= 0; i--) 
      {
         swap(&arr[0], &arr[i]);
  
         // Heapify root element to get highest element at root again
         heapify(arr, i, 0);
      }
  }
  
  void printArray(int arr[], int n) 
  {
      for (int i = 0; i < n; ++i)
          printf("%d ", arr[i]);
      printf("\n");
  }
  
  int main() 
  {
     int arr[] = {1, 22, 25, 5, 14, 17, 2, 18};
     clock_t start, end;
     int n = sizeof(arr) / sizeof(arr[0]);
     start = clock();
        heapSort(arr, n);
     end = clock();
     float ti = ((double)(end - start)/CLOCKS_PER_SEC);

     printf("Sorted array is \n");
     printArray(arr, n);
     printf("\nTime taken: %f", ti);
  }

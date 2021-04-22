// C program to implement recursive Binary Search and Linear Search
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);


        return binarySearch(arr, mid + 1, r, x);
    }


    return -1;
}

int linearSearch(int arr[], int l,int n, int x)
{
    if (l>=n)
        return -1;
    if (arr[l] == x)
    {
        return l;
    }
    return linearSearch(arr, l+1,n, x);
}

int main()
{
    int x, j = 0,flag, n = 10000, sort = 0, i, ch;
    clock_t start, end;

    int arr[n];
    for (i = 0; i < n; i++)
    {
        int no = rand() % n + 1;
        arr[i] = no;

    }
    for(int m = 0; m<n; m++)
    {
        printf(" %d ",arr[m]);
    }
    printf("\n\n");
    for(;;)
    {
        printf("1.Linear Search \n2.Binary Search \n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:

            printf("Enter the element to be Searched : ");
            scanf("%d", &x);

            start = clock();
            int y = linearSearch(arr, 0, n, x);
            end = clock();
            float ti = ((double)(end - start)/CLOCKS_PER_SEC);
            // printf("Element found at index :%d \n",y);
            if(y != 1)
            {
                printf("Element Found at position %d.\n", y + 1);
            }
            else
            {
                printf("Element not found.\n");
            }

            printf("Time taken: %f\n\n", ti);
            break;
        case 2:
            j = 0;
            flag = 0;
            int temp;
            while(j < n-1 && sort == 0 )
            {
                if(arr[j] > arr[j+1])
                {
                    flag=1;
                }
                j++;
            }
            if(flag == 1)
            {
                for (int i = 0; i < n-1; i++)
                {
                    for (j = 0; j < n-i-1; j++)
                    {
                        if (arr[j] > arr[j+1])
                        {
                            temp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = temp;
                        }
                    }
                }
                for(int i=0; i<n; i++)
                {
                    printf("%d ",arr[i]);
                }
                sort = 1;
                printf("\n\n");
            }

            printf("Enter the element to be Searched : ");
            scanf("%d",&x);
            start = clock();

            int result = binarySearch(arr, 0, n - 1, x);
            end = clock();
            if(result == -1)
            {
                printf("Element Not Found.\n");
            }
            else
            {
                printf("Element found at position %d.\n", result + 1);
            }
            float tm = ((double)(end - start)/CLOCKS_PER_SEC);
            printf("Time taken: %f\n\n",tm);

            break;
        default:
            exit(0);
        }
    }

    return 0;
}

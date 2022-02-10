#include <stdio.h>

void Swap(int*,int*);
int Find_Min(int[],int, int);
void Selection_Sort(int[], int);
void main()
{
   int i, n;
   printf("Enter number of elements:\n");
   scanf("%d",&n);
   int arr[n];
   
   printf("enter the %d elements\n", n);
   
   for(i=0; i<n; i++)
    scanf("%d",&arr[i]);
    //printf("hello world");
    
    
   Selection_Sort(arr,n);
   
}
int Find_Min(int arr[], int k, int n)
{
    int i, left, right, Min_loc, min;
    left=k;
    right = n;
    min = arr[left];
    Min_loc = left;
    
    for(i=(left+1);i<right;i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
            Min_loc=i;
        }
    }
    return Min_loc;
}

void Swap(int* a, int* b)
{
    int temp;
    temp=*a;
    *a= *b;
    *b= temp;
}

void Selection_Sort(int arr[], int n)
{
    //printf("Selection Sort");
    int i, j, temp;
    
    
    for(i=0;i<(n-1);i++)
    {
        j=Find_Min(arr, i, n);
        
        if(i!=j)
        {
            Swap(&arr[i], &arr[j]);
            
        }
    }
    printf("The Sorted Array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
}







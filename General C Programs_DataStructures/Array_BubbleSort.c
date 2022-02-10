#include <stdio.h>

void Bubble_Sort_Asc(int[],int);
void Bubble_Sort_Desc(int[],int);
void main()
{
   int i, n;
   printf("Enter number of elements:\n");
   scanf("%d", &n);
   int arr[n];
   
   printf("enter the %d elements\n", n);
   for(i=0; i<n; i++)
   {
       scanf("%d", &arr[i]);
   }
   Bubble_Sort_Asc(arr, n);
   Bubble_Sort_Desc(arr, n);
   
}

void Bubble_Sort_Asc(int arr[], int n)
{
    printf("Sorted Array in Ascending order:\n");
    int i, j, temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
    
        }
         printf("%d ", arr[i]);
    }
}
void Bubble_Sort_Desc(int arr[], int n)
{
    printf("\nSorted Array in Descending order:\n");
    int i, j, temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
    
        }
         printf("%d ", arr[i]);
    }
        
}









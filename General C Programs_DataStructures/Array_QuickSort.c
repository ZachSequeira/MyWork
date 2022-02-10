#include <stdio.h>

void Swap(int*,int*);
int Partition(int[],int, int);
void Quick_Sort(int[], int, int);
void main()
{
    int i, n, first;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    int arr[n];
   
    printf("enter the %d elements\n", n);

    for(i=0; i<n; i++)
    scanf("%d",&arr[i]);
    first=0;
    Quick_Sort(arr, first, n);
    printf("the Sorted Array is:\n");
    
    for(int i=0; i<n;i++)
    {
        printf("%d ", arr[i]);
    }
   
}

int Partition(int arr[], int first, int last)
{
   int left, right, piv;
   left=first;
   right=last;
   piv=left;
   
   while(left<right)
   {
       while((arr[piv]<=arr[right]) && (piv<right))
       {
           right = right - 1;
       }
       if(arr[piv]>arr[right])
       {
           Swap(&arr[piv], &arr[right]);
           piv = right;
           left = left + 1;
       }
       
       while((arr[piv]>=arr[left]) && (piv>left))
       {
           left = left + 1;
       }
       if(arr[piv]<arr[left])
       {
           Swap(&arr[piv], &arr[left]);
           piv = left;
           right = right - 1;
       }
   }
   return piv;
}

void Swap(int* a, int* b)
{
    int temp;
    temp=*a;
    *a= *b;
    *b= temp;
}

void Quick_Sort(int arr[],int first, int n)
{
    int p, last;
    last = n;
    if(first<last)
    {
        p = Partition(arr, first, last);
        Quick_Sort(arr, first, (p-1));
        Quick_Sort(arr, (p+1), last);
    }
    
}






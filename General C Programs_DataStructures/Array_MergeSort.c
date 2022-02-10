#include <stdio.h> 


void Merge(int[], int, int, int);
void Merge_Sort(int[], int, int);
void main()
{
    int i, n, l;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    int arr[n];
   
    printf("enter the %d elements\n", n);

    for(i=0; i<n; i++)
    scanf("%d",&arr[i]);
    
    l=0;
    
    printf("Sorted Array Elements are:\n");
    Merge_Sort(arr,l, n);
    
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    
}

void Merge_Sort(int arr[], int left, int right) 
{
   int mid;
   
   if(left<right) 
   {
      mid = (left + right) / 2;
      Merge_Sort(arr,left, mid);
      Merge_Sort(arr,mid+1, right);
      Merge(arr, left, mid, right);
   } 
}

void Merge(int arr[], int left, int mid, int right) 
{
   int l1, l2, i;
   int temp[right];
   l1=left;
   l2=mid+1;

   for(i = left; l1 <= mid && l2 <= right; i++) 
   {
      if(arr[l1] <= arr[l2])
      {
        temp[i] = arr[l1++];
      }
      else
      {
        temp[i] = arr[l2++];
      }
   }
   
   while(l1 <= mid)  
   {
      temp[i++] = arr[l1++];
   }

   while(l2 <= right)
   {
      temp[i++] = arr[l2++];
   }

   for(i = left; i <= right; i++)
   {
      arr[i] = temp[i];
   }
}





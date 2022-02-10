#include <stdio.h>

void Binary_Search(int[],int,int);
void main()
{
   int i, key, n;
   printf("Enter number of elements:\n");
   scanf("%d", &n);
   int arr[n];
   
   for(i=0; i<n; i++)
   {
       printf("enter element %d\n", i+1);
       scanf("%d", &arr[i]);
   }
   
   printf("Enter Key Element to be found:\n");
   scanf("%d", &key);
   
   
   
   Binary_Search(arr, key, n);
}

void Binary_Search(int arr[], int key, int n)
{
   int low=0;
   int high=n-1;
   int mid;
   static int flag=0;
   while(low<=high && flag!=1)
   {
       mid=(low+high)/2;
       
       if(arr[mid]==key)
       {
           printf("key is found at Index %d\n", mid+1);
           flag=1;
       }
      
       if(key>arr[mid])
       {
           low=mid+1;
       }
       else 
       {
           high=mid-1;
       }
   }
   if(flag==0)
   {
       printf("Element doesn't exist in the array.\n");
   }
}










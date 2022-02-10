#include <iostream>
using namespace std;

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
    cout<<"The Sorted Array is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
   int i, n;
   cout<<"Enter number of elements:"<<endl;
   cin>>n;
   int arr[n];
   cout<<"enter the "<<n<<" elements"<<endl;
   
   for(i=0; i<n; i++)
   cin>>arr[i];

    Selection_Sort(arr,n);
   
   return 0;
   
}

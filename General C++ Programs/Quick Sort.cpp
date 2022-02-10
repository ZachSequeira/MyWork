#include <iostream>
using namespace std;

void Swap(int* a, int* b)
{
    int temp;
    temp=*a;
    *a= *b;
    *b= temp;
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

int main()
{
    int i, n, first;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    int arr[n];
   
    cout<<"enter the "<<n<<" elements"<<endl;

    for(i=0; i<n; i++)
    cin>>arr[i];
    first=0;
    Quick_Sort(arr, first, n);
    cout<<"the Sorted Array is:"<<endl;
    
    for(int i=0; i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}


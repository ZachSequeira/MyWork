#include <iostream>
using namespace std;

void Swap(int* a, int* b)
{
    int temp;
    temp=*a;
    *a= *b;
    *b= temp;
}
void Bubble_Sort_Asc(int arr[], int n)
{
    cout<<"Sorted Array in Ascending order:"<<endl;
    int i, j, temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                Swap(&arr[i],&arr[j]);
            }
    	}
        cout<<arr[i]<<endl;
    }
}

void Bubble_Sort_Desc(int arr[], int n)
{
    cout<<"Sorted Array in Descending order:"<<endl;
    int i, j, temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            {
                Swap(&arr[i],&arr[j]);
            }
    
        }
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
   {
       cin>>arr[i];
   }
   Bubble_Sort_Asc(arr, n);
   Bubble_Sort_Desc(arr, n);
   
   return 0;
   
}


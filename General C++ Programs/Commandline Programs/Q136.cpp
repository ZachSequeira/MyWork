/******************************************************************************
136.Pass any number of arguments from command line. Sort those numbers and 
display in ascending order.
*******************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}
int main(int argc, char* argv[])
{
	int i,j,temp;
	int arr[argc];
	
	for(i=1;i<=argc;i++)
	{
		arr[i]= atoi(argv[i]);
	}
	
	for(i=1;i<=argc;i++)
	{
		for(j=i+1;j<=argc;j++)
		{
			if(arr[i]>arr[j])
			{
				swap(&arr[i],&arr[j]);
			}
		}	
	}
	
	cout<<"The numbers sorted in ascending order are:"<<endl;
	
	for(i=2;i<=argc;i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}

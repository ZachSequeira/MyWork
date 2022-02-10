/******************************************************************************
179. Find the sum of all numbers given from command line argument.
*******************************************************************************/
#include <iostream>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	int i, sum=0;
	int arr[argc];
	for(i=1;i<=argc;i++)
	{
		arr[i]= atoi(argv[i]);
	}

	cout<<"The sum of the numbers are: ";
	for(i=1;i<argc;i++)
	{
		sum+=i;
	}
	cout<<sum<<endl;
	return 0;
}

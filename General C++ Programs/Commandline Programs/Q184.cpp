/******************************************************************************
184. Take one number from command line and check whether it is palindrome or not.
*******************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	int rem, rev=0;
	int num = atoi(argv[1]);
	int temp=num;

	while(temp!=0)
	{
		rem = temp%10;
		rev = (rev*10)+rem;
		temp = temp/10;		
	}

	if(num==rev)
	{
		cout<<num<<" is a palindrome number."<<endl;	
	}
	else
	{
		cout<<num<<" is not a palindrome number."<<endl;
	}
	return 0;
}

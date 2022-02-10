/******************************************************************************
182. Take one number from command line and find its factorial
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#define pi 3.14
using namespace std;

int main(int argc, char* argv[])
{
	int n, i, fact=1;
	n = atoi(argv[1]);
	for(i=1;i<=n;i++)
	{
		fact*=i;
	}
	cout<<n<<"! = "<<fact<<endl;
  
    return 0;
}

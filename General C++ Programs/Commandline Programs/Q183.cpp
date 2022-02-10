/******************************************************************************
183. Input some numbers from command line and differentiate them into even and odd.
*******************************************************************************/
#include <iostream>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	int i;
	for(i=1;i<=argc;i++)
	{
		if(atoi(argv[i])%2==0)
		{
			cout<<argv[i]<<" is Even"<<endl;
		}
		else
		{
			cout<<argv[i]<<" is Odd"<<endl;
		}
	}
	return 0;
}

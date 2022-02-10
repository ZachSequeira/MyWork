/******************************************************************************
 181. Take one number from command line and find its table.
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#define pi 3.14
using namespace std;

int main(int argc, char* argv[])
{
	int n, i;
	n = atoi(argv[1]);
	for(i=1;i<=12;i++)
	{
		cout<<n<<" x "<<i<<" = "<<n*i<<endl;
	}
	
  
    return 0;
}

/******************************************************************************
186. Take one number from command line and check whether it is Armstrong or not
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
	int rem, res=0,cnt=0, power;
	int num = atoi(argv[1]);
	int temp=num;

	while(temp!=0)
	{
		temp/=10;
		++cnt;	
	}
	
	temp=num;
	
	while(temp!=0)
	{
		rem = temp % 10;
		power = pow(rem,cnt);
		res += power;
		temp /= 10;
	}
	
	if (res == num)
	{
		cout << num << " is an Armstrong number.";
	}
      
    else
    {
    	cout << num << " is not an Armstrong number.";
	}
      
	return 0;
}

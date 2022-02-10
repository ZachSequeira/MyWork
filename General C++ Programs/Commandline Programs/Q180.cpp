/******************************************************************************
180. Take radius from command line and find area of circle.
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#define pi 3.14
using namespace std;

int main(int argc, char* argv[])
{
	int r;
	float area;
	r= atoi(argv[1]);
	area = pi * r * r;
	cout<<"Area of Circle with radius "<<r<<" is "<<area<<endl;
  
    return 0;
}


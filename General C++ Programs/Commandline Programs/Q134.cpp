/******************************************************************************
134.Input two arguments from command line and pass those arguments to the 
constructor of class and make addition of those arguments.
*******************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;
class Numbers
{
	public:
		int n1, n2;
		int sum=0;
		Numbers(int x, int y)
		{
			n1=x;
			n2=y;
		}
	
		void add()
		{
			sum=n1+n2;
			cout<<n1<<" + "<<n2<<" = "<<sum<<endl;
		}
};
int main(int argc, char* argv[])
{
	int n1,n2;
	n1= atoi(argv[1]);
	n2= atoi(argv[2]);
	Numbers n(n1,n2);
	n.add();
  
    return 0;
}


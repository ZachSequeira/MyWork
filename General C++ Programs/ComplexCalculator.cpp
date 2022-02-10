#include <iostream>
using namespace std;

class Calc
{
	private:
		float n1,n2,res;
	public:
		void Sum(float x, float y)
		{
			n1=x;
			n2=y;
			res=n1+n2;
			cout<<"The Result is: "<<res<<endl;
		}
		void Sub(float x, float y)
		{
			n1=x;
			n2=y;
			res=n1-n2;
			cout<<"The Result is: "<<res<<endl;
		}
		void Mul(float x, float y)
		{
			n1=x;
			n2=y;
			res=n1*n2;
			cout<<"The Result is: "<<res<<endl;
		}
		void Div(float x, float y)
		{
			n1=x;
			n2=y;
			res=n1/n2;
			cout<<"The Result is: "<<res<<endl;
		}
};


typedef void (Calc::*CalcFunc)(float,float);

void ExecFunc(float a, float b, Calc* c, CalcFunc Arr[], int pos)
{
	(c->*Arr[pos])(a,b);
}

int main()
{
	int uInput;
	float a,b;
	Calc c1;
	Calc* Cptr = &c1;
	
	CalcFunc Fptr;
	
	CalcFunc PArray[] = {&Calc::Sum, &Calc::Sub, &Calc::Mul, &Calc::Div};
	Fptr = &Calc::Sum;
	cout<<"Choose Your Operation: 0.)Sum, 1.) Diff, 2.) Mul, 3.) Div"<<endl;
	cin>>uInput;
	cout<<"Enter the first Operand"<<endl;
	cin>>a;
	cout<<"Enter the second Operand"<<endl;
	cin>>b;
	ExecFunc(a,b,Cptr,PArray,uInput);
	
	return 0;
}

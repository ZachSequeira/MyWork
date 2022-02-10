/******************************************************************************
135.Input name, roll number and three subjects marks from command line. Fetch 
those arguments in a function of class. Calculate percentage. Display name, 
roll, percentage of that student.
*******************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;
class Student
{
	private:
		void Calc_percentage()
		{
			perc=(float)((s1+s2+s3)/3);	
			display();
		}
		
		void display()
		{
			cout<<"Name: "<<name<<endl;
			cout<<"Roll No: "<<roll<<endl;
			cout<<"Precentage: "<<perc<<"%"<<endl;
		}
		
	public:
		int s1,s2,s3,roll;
		float perc;
		string name;
		
		void Set_Data(int a,int b,int c, int rno, string n)
		{
			s1=a;
			s2=b;
			s3=c;
			roll=rno;
			name=n;	
			Calc_percentage();
		}
};
int main(int argc, char* argv[])
{
	string name = argv[1];
	int roll = atoi(argv[2]);
	int s1 = atoi(argv[3]);
	int s2 = atoi(argv[4]);
	int s3 = atoi (argv[5]);
	
	Student s;
	s.Set_Data(s1,s2,s3,roll,name);
	
    return 0;
}


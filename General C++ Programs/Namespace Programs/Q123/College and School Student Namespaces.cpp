/******************************************************************************
123. Create two namespaces one for college student and another for school 
student. Create student class in both the namespaces with appropriate members 
and include other relevant classes in the namespaces. Create object of both 
the classes and use the methods.
*******************************************************************************/
#include <iostream>
#include "student.h"
using namespace std;
using namespace school;


int main()
{
   Contact c;
   c.display_contact();
   Details d;
   d.display_details();
   cout<<"-------------------------------------------------"<<endl;
   college::Contact c1;
   c1.display_contact();
   college::Details d1;
   d1.display_details();
   return 0;
}


/******************************************************************************
123. Create two namespaces one for college student and another for school 
student. Create student class in both the namespaces with appropriate members 
and include other relevant classes in the namespaces. Create object of both 
the classes and use the methods.
*******************************************************************************/
#include <iostream>
using namespace std;

namespace school
{
    class Contact
    {
       public:
            string address= "Pune";
            int contact=202938392;
            void display_contact()
            {
                cout<<"School Student Address: "<<address<<endl;
                cout<<"School Student Contact: "<<contact<<endl;
            }
    };
    
    class Details
    {
        public:
            string name = "ABC";
            int roll = 43;
            void display_details()
            {
                cout<<"School Student Name: "<<name<<endl;
                cout<<"School Student Roll No: "<<roll<<endl;
            }
    };
    
}

namespace college
{
    class Contact
    {
       public:
            string address= "Delhi";
            int contact=789549432; 
            void display_contact()
            {
                cout<<"College Student Address: "<<address<<endl;
                cout<<"College Student Contact: "<<contact<<endl;
            }
    };
    
    class Details
    {
        public:
            string name = "XYZ";
            int roll = 23; 
            void display_details()
            {
                cout<<"College Student Name: "<<name<<endl;
                cout<<"College Student Roll No: "<<roll<<endl;
            }
    };
    
}

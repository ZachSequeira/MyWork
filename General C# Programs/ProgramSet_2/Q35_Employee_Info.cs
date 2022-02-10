//Q35.) Write a C# program to store the information of 5 employees using structure and array. 

/*using System;

namespace Homework_Set_2
{
    struct Employee
    {
        public string name;
        public string contact;
        public string address;
    };

    class Q35_Employee_Info
    {
        static void Main()
        {
            int i;
            Employee[] e = new Employee[5];

            for(i=0;i<5;i++)
            {
                Console.WriteLine("Enter Employee "+ (i+1)+" Name:");
                e[i].name = Console.ReadLine();
                Console.WriteLine("Enter Employee " + (i+1) + " Contact:");
                e[i].contact = Console.ReadLine();
                Console.WriteLine("Enter Employee " + (i+1) + " Address:");
                e[i].address = Console.ReadLine();
            }
            
            
            Console.WriteLine("---------------------------------------");

            Console.WriteLine("The Employee Details are: ");
            for(i=0;i<5;i++)
            {
                Console.WriteLine("Employee "+ (i+1)+" Details:");
                Console.WriteLine("Name: "+ e[i].name);
                Console.WriteLine("Contact: " + e[i].contact);
                Console.WriteLine("Address: " + e[i].address);
                Console.WriteLine("---------------------------------------");

            }

        }
    }
}*/
/*Q7. Write a program to assign suitable title (Miss, Mrs, Mr) to person.
Take input one’s gender and material status if required.*/

/*using System;

namespace BSP_CS_Programs
{
    class Q7_Titles
    {
        static void Main()
        {
            string name;
            char gender;
            char status;

            Console.WriteLine("Enter you name:");
            name = Console.ReadLine();
            
            Enter:
            Console.WriteLine("Enter Your Gender. M: Male|F: Female");
            gender = Convert.ToChar(Console.ReadLine());
            Console.WriteLine("Enter Your Marital Status. S: Single|M: Married");
            status = Convert.ToChar(Console.ReadLine());

            if(gender=='M'||gender=='m')
            {
                Console.WriteLine("Your Title is: Mr. " + name);
            }
            else if(gender == 'F'||gender =='f')
            {
                if(status=='S'||status=='s')
                {
                    Console.WriteLine("Your Title is: Ms. " + name);
                }
                else
                {
                    Console.WriteLine("Your Title is: Mrs. " + name);
                }
            }
            else
            {
                Console.WriteLine("Incorrect Entry, Try Again.");
                goto Enter;
            }
        }
    }
}*/




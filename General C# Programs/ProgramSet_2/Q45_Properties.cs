//Q45.) Write the program which will implement the concept of properties in c#.

/*using System;

namespace Homework_Set_2
{
    class Q45_Properties
    {
        static void Main()
        {
            Properties p1 = new Properties();
            Console.WriteLine("Enter Name");
            p1.name = Console.ReadLine();
            Console.WriteLine("Enter Branch Code");
            p1.code = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter PIN");
            p1.PIN = Console.ReadLine();

            Console.WriteLine("Name: "+ p1.name);//calling property method directly without variable
            Console.WriteLine("Branch Code: " + p1._code);//calling the variable assigned in property method
            Console.WriteLine("Account No: " + p1.AccNo);
            

            
        }
    }

    class Properties
    {
        public int _code;
        private string _PIN;
        public int code //using properties with a variable
        { 
            get
            {
                return _code;
            }
            set
            {
                _code= value;
            }
        }

        public string name { get; set; } //using properties without a variable

        public string PIN { private get { return _PIN; } set { } }//write only property. Cannot read the data once entered.

        public string AccNo { get { return "2000212902"; } private set { } }//Read only property. User cannot enter Data.
    }

}*/

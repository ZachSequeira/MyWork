/*Q56.) Create a file which includes only data members, another file which contains all constructors of the class, another file which will include all functions related. Use the concept of partial class.*/
/*using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_Set_3
{
    partial class Q56_Demo_Partial
    {
        public Q56_Demo_Partial(int z)
        {
            a = z;
            sq = Find_Square(a);
            Console.WriteLine("The Square of "+ a +" is: "+sq );
        }

        public Q56_Demo_Partial(int x, int y)
        {
            b = x;
            c = y;
            sum = Add(b,c);
            Console.WriteLine("The Sum of " + b + " and "+c+" is " + sum);
        }

    }

    class Main_Method
    {
       static void Main()
        {
            int ch;
            Label_Choose:
            Console.WriteLine("1.) Find Square of a number\n2.) Find Sum of 2 numbers");
            ch = Convert.ToInt32(Console.ReadLine());

            switch (ch)
            {
                case 1:
                    {
                        Console.WriteLine("Enter a Number: ");
                        int n1 = Convert.ToInt32(Console.ReadLine());
                        Q56_Demo_Partial obj = new Q56_Demo_Partial(n1);
                        
                        break;
                    }
                case 2:
                    {
                        Console.WriteLine("Enter two Numbers: ");
                        int n1 = Convert.ToInt32(Console.ReadLine());
                        int n2 = Convert.ToInt32(Console.ReadLine());

                        Q56_Demo_Partial obj = new Q56_Demo_Partial(n1,n2);
                        break;
                    }
                default:
                    {
                        Console.WriteLine("Wrong selection! Try Again!");
                        goto Label_Choose;
                       
                    }

            }


        }

    }
}*/

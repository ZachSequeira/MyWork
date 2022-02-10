//Q37.) Input 3 numbers from command line argument and find greater between them using ternary operator.

/*using System;

namespace Homework_Set_2
{
    class Q37_CMD_GreaterOfThree_Ternary
    {
        static void Main(String[] args)
        {
            int n1, n2, n3, lrg;
            
            n1 = Convert.ToInt32(args[0]);
            n2 = Convert.ToInt32(args[1]);
            n3 = Convert.ToInt32(args[2]);

            Console.WriteLine("n1=" + n1);
            Console.WriteLine("n2=" + n2);
            Console.WriteLine("n3=" + n3);

            lrg = n1 > n2 ? n1 : n2;

            if(lrg==n1)
            {
                lrg = n1 > n3 ? n1 : n3;
            }
            else if(lrg==n2)
            {
                lrg = n2 > n3 ? n2 : n3;
            }

            Console.WriteLine("Largest number of the 3 is: "+ lrg);
        }
    }
}*/

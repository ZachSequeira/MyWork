/*//Q25.) Write a C# program to print all perfect numbers within given range. 

using System;

namespace Homework_Set_2
{
    class Q25_Perfect_Range
    {
        static void Main()
        {
            int low,high, i, j, sum ;
            Console.WriteLine("Enter lower limit: ");
            low = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter upper limit: ");
            high = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Your Perfect number between "+low+" and "+high+" are:");
            for (i = low; i <= high; i++)
            {
                sum = 0;
                for (j = 1; j < i; j++)
                {
                    if (i % j == 0)
                    {
                        sum += j;
                    }
                }

                if (sum == i)
                {
                    Console.WriteLine(i);
                }
            }
          
        }
    }
}*/

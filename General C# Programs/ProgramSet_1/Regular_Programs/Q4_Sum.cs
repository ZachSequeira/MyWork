//Q4. Write a program to find sum of 1 to n numbers using goto statement.

/*using System;

namespace BSP_CS_Programs
{
    class Q4_Sum
    {
        static void Main()
        {
            uint n, i = 1, sum = 0;

            Console.WriteLine("Enter the range limit:");
            n = Convert.ToUInt32(Console.ReadLine());

        Add:
            {
                sum += i;
                ++i;
                if (i <= n)
                {
                    goto Add;
                }
                else if(i > n)
                {
                    goto Answer;
                }
            }

        Answer:
            {
                Console.WriteLine("Sum of numbers between 1 and " + n + " is " + sum);
            }
        }
    }
}*/

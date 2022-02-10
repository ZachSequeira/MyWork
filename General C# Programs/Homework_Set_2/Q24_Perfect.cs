//Q24). Write a C# program to check whether given number is perfect or not.(6, 28, 496, 8128 )

/*using System;

namespace Homework_Set_2
{
    class Q24_Perfect
    {
        static void Main()
        {
            int num, i, sum=0;
            Console.WriteLine("Enter a number: ");
            num = Convert.ToInt32(Console.ReadLine());

            for (i = 1; i < num; i++)
            {
                if(num%i == 0)
                {
                    sum += i;
                }
            }
            
            if(sum == num)
            {
                Console.WriteLine(num+" is a perfect number!");
            }
            else
            {
                Console.WriteLine(num+" is not a perfect number!");
            }
        }
    }
}*/

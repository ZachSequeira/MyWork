//Q23). Write a C# program to convert decimal number to binary.

/*using System;

namespace Homework_Set_2
{
    class Q23_DecimalToBinary
    {
        static void Main()
        {
            int bin = 0, rem, DeciNum, temp, i=1;
            Console.WriteLine("Enter the Decimal number:");
            DeciNum = Convert.ToInt32(Console.ReadLine());

            temp = DeciNum;
            while(DeciNum!=0)
            {
                rem = DeciNum % 2;
                DeciNum /= 2;
                bin += rem * i;
                i *= 10;
            }

            Console.WriteLine(temp + " in Binary is : " + bin);
            
        }
    }
}*/

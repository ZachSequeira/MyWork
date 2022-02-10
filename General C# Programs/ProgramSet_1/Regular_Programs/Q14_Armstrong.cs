//Q14. Write a program to find given number is Armstrong or not.

/*using System;

namespace BSP_CS_Programs
{
    class Q14_Armstrong
    {
        static void Main()
        {
            int num, rem, temp;
            byte cnt=0;
            double sum=0, power;
            Console.WriteLine("Enter a number:");
            num = Convert.ToInt32(Console.ReadLine());

            temp = num;


            while(temp!=0)
            {
                temp /= 10;
                cnt++;
                
            }

            temp = num;
            while(temp!=0)
            {
                rem = temp % 10;
                power = Math.Pow(rem, cnt);
                sum += power;
                temp /= 10;
            }
            if(sum==num)
            {
                Console.WriteLine(num + " is an Armstrong Number!");
            }
            else
            {
                Console.WriteLine(num + " is not an Armstrong Number!");

            }

        }

    }
}*/

//Q17. Write a program to print all Armstrong numbers between given two intervals.

/*using System;

namespace BSP_CS_Programs
{
    class Q17_Armstrong_Series
    {
        static void Main()
        {
            int low,up, i, cnt;
            int temp, rem;
            double sum = 0, power;
            Console.WriteLine("Enter lower limit:");
            low = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter upper limit:");
            up = Convert.ToInt32(Console.ReadLine());

            for(i=low;i<=up;i++)
            {
                cnt = 0;
                sum = 0;
                temp = i;
                
                while (temp != 0)
                {
                    temp /= 10;
                    cnt++;
                }

                temp = i;
                while (temp != 0)
                {
                    rem = temp % 10;
                    power = Math.Pow(rem, cnt);
                    sum += power;
                    temp /= 10;
                }
                if (sum == i)
                {
                    Console.WriteLine(i);
                }
            }
        }
    }
}*/






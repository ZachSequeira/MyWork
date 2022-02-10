//Q40.) Input a number from command line argument and check it is Armstrong or not.

/*using System;

namespace Homework_Set_2
{
    class Q40_CMD_Armstrong
    {
        static void Main(String[] args)
        {
            int num, rem, temp;
            byte cnt = 0;
            double sum = 0, power;
            num = Convert.ToInt32(args[0]);

            temp = num;


            while (temp != 0)
            {
                temp /= 10;
                cnt++;

            }

            temp = num;
            while (temp != 0)
            {
                rem = temp % 10;
                power = Math.Pow(rem, cnt);
                sum += power;
                temp /= 10;
            }
            if (sum == num)
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

//Q39.) Input a number from command line argument and check whether it is palindrome or not.

/*using System;

namespace Homework_Set_2
{
    class Q39_CMD_Palindrome
    {
        static void Main(String[] args)
        {
            int num, temp, rem, rev=0;
            num = Convert.ToInt32(args[0]);
            temp = num;

            while(temp!=0)
            {
                rem = temp % 10;
                rev = (rev * 10) + rem;
                temp = temp / 10;
            }
            if(num==rev)
            {
                Console.WriteLine(num+" is a Palindrome Number!");
            }
            else
            {
                Console.WriteLine(num+" is not a Palindrome Number!");
            }
        }
    }
}*/

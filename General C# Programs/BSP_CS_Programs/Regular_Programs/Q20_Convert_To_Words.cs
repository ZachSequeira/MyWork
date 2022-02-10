/*Q20. Write a c# program to convert given number in word.
(357546  :  three five seven five four six )*/

/*using System;

namespace BSP_CS_Programs
{
    class Q20_Convert_To_Words
    {
        static void Main()
        {
             int n, rev = 0, rem, temp;
             Console.WriteLine("Enter a number:");
             n = Convert.ToInt32(Console.ReadLine());

             temp = n;
                
             while (temp != 0)
             {
                 rem = temp % 10;
                 rev = (rev * 10) + rem;
                 temp /= 10;
             }
             temp = rev;
             while(temp!=0)
             {
                 rem = temp % 10;
                 if(rem==0)
                 {
                     Console.Write(" Zero ");
                 }
                 if (rem == 1)
                 {
                     Console.Write(" One ");
                 }
                 if (rem == 2)
                 {
                     Console.Write(" Two ");
                 }
                 if (rem == 3)
                 {
                     Console.Write(" Three ");
                 }
                 if (rem == 4)
                 {
                     Console.Write(" Four ");
                 }
                 if (rem == 5)
                 {
                     Console.Write(" Five ");
                 }
                 if (rem == 6)
                 {
                     Console.Write(" Six ");
                 }
                 if (rem == 7)
                 {
                     Console.Write(" Seven ");
                 }
                 if (rem == 8)
                 {
                     Console.Write(" Eight ");
                 }
                 if (rem == 9)
                 {
                     Console.Write(" Nine ");
                 }
                 temp /= 10;
             }
        }
    }
}*/

using System;

namespace BSP_CS_Programs
{
    class Guess_The_Number
    {
        static void Main()
        {
            Random rnd = new Random();
            int num = rnd.Next(1, 999);
            int ch=0;

            Console.WriteLine("Guess the Number:");
            while(ch!=num)
            {
                ch = Convert.ToInt32(Console.ReadLine());
                
                if(ch>num)
                {
                    Console.WriteLine("Number is Smaller!");
                    Console.WriteLine("-----------------------------------------");
                }
                else
                {
                    Console.WriteLine("Number is Greater!");
                    Console.WriteLine("-----------------------------------------");
                }
            }
            Console.WriteLine("CONGRATULATIONS! THE NUMBER WAS " + num);
            Console.WriteLine("-----------------------------------------");
        }
    }
}



/*Q8. Write a program to convert 24-hour time format to 12-hour time format with am or pm
appropriately.*/

/*using System;

namespace BSP_CS_Programs
{
    class Q8_Clocks
    {
        static void Main()
        {
            byte hour, min;
            string suffix;
            Enter:
            {
                Console.WriteLine("Enter Hours and Minutes in 24 Hr format:");
                hour = Convert.ToByte(Console.ReadLine());
                min = Convert.ToByte(Console.ReadLine());
                
                if (hour > 23 || min > 59)
                {
                    Console.WriteLine("Incorrect Time Entered. Try Again.");
                    goto Enter;
                }
            }

            Console.WriteLine("Your Entered Time is: " + hour + " : " + min);

            if(hour>12)
            {
                suffix = "PM";

                if(hour == 13)
                {
                    hour = 1;
                }
                if(hour == 14)
                {
                    hour = 2;
                }
                if(hour == 15)
                {
                    hour = 3;
                }
                if(hour == 16)
                {
                    hour = 4;
                }
                if(hour ==17)
                {
                    hour = 5;
                }
                if(hour == 18)
                {
                    hour = 6;
                }
                if(hour == 19)
                {
                    hour = 7;
                }
                if(hour == 20)
                {
                    hour = 8;
                }
                if(hour == 21)
                {
                    hour = 9;
                }
                if(hour == 22)
                {
                    hour = 10;
                }
                if(hour == 23)
                {
                    hour = 11;
                }
            }
            else
            {
                suffix = "AM";
                if (hour == 0)
                {
                    hour = 12;
                }
            }

            Console.WriteLine("Time in 12 Hour Format is:\n" + hour + " : " + min +" "+ suffix);
        }
    }
}*/

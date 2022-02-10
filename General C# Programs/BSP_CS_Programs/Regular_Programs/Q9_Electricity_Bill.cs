/*Q9. Write a program to input electricity unit charge and calculate the total electricity bill according to the given 
 condition:
For first 50 units Rs. 0.50/unit
For next 100 units Rs. 0.75/unit
For next 100 units Rs. 1.20/unit
For unit above 250 Rs. 1.50/unit
An additional surcharge of 20% is added to the bill.*/

/*using System;

namespace BSP_CS_Programs
{
    class Q9_Electricity_Bill
    {
        static void Main()
        {
            int units;
            double bill=0;
            Console.WriteLine("Enter Number of Units Consumed:");
            units = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("-----------------------------------------------------");

            Console.WriteLine("Bill Breakdown:");
            Console.WriteLine("-----------------------------------------------------");
            
            if (units<=50)
            {
                bill = units * 0.50;
                Console.WriteLine(units + " x 0.50 = $" + bill);
            }
            else if(units<=150)
            {
                bill = 25 + ((units - 50) * 0.75);
                Console.WriteLine(50 + " x 0.50 = $" + (0.50 * 50));
                Console.WriteLine((units - 50) + " x 0.75 = $" + (0.75 * (units - 50)));

            }
            else if (units <= 250)
            {
                bill = 100 + ((units - 150) * 1.20);
                Console.WriteLine(50 + " x 0.50 = $" + (0.50 * 50));
                Console.WriteLine(100 + " x 0.75 = $" + (0.75 * 100));
                Console.WriteLine((units - 150) + " x 1.20 = $" + (1.20 * (units - 150)));
            }
            else if (units > 250)
            {
                bill = 220 + ((units - 250) * 1.50);
                Console.WriteLine(50 + " x 0.50 = $" + (0.50 * 50));
                Console.WriteLine(100 + " x 0.75 = $" + (0.75 * 100));
                Console.WriteLine(100 + " x 1.20 = $" + (1.20 * 100));
                Console.WriteLine((units - 250) + "x 1.50 = $" + (1.50 * (units - 250)));
            }
            Console.WriteLine("20% Surcharge = $" + (bill * 0.20));
            Console.WriteLine("-----------------------------------------------------");
            Console.WriteLine("Total Bill = $" + ((bill * 0.20)+bill));
            Console.WriteLine("-----------------------------------------------------");
        }
    }
}*/








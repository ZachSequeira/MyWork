//Q49.) Demonstrate multiple inheritance with the use of interface with suitable example.

/*using System;

namespace Homework_Set_2
{
    class Q49_Multiple_Inheritance_Interfaces
    {
        static void Main()
        {
            float a, b;
            Average obj = new Average();

            Console.WriteLine("Enter A");
            a = Convert.ToSingle(Console.ReadLine());
            obj.GetA(a);

            Console.WriteLine("Enter B");
            b = Convert.ToSingle(Console.ReadLine());
            obj.GetB(b);

            Console.WriteLine("Average of " + a + " and " + b + " is = " + obj.Avg());
        }
    }

    interface I1
    {
        void GetA(float x);

    }

    interface I2
    {
        void GetB(float y);

    }

    class Average: I1,I2
    {
        public float a, b;

        public float Avg()
        {
            return (a + b) / 2;
        }

        public void GetA(float x)
        {
            a = x;
        }

        public void GetB(float y)
        {
            b = y;
        }
           
    }

}*/
        

//Q47.) Write a C# program to demonstrate multilevel inheritance. Base class – bird, middle class – flying birds, child class – any bird. Use appropriate methods in related class.

/*using System;

namespace Homework_Set_2
{
    class Q47_MultiLevel_Inheritance
    {
        static void Main()
        {
            Eagle E = new Eagle();
            Penguin P = new Penguin();

            E.showBird();
            E.showFlyingBird();
            E.showEagle();
            Console.WriteLine("------------------------------------");
            P.showBird();
            P.showFlightlessBird();
            P.showPenguin();
        }

    }

    class Bird
    {
        public void showBird()
        {
            Console.WriteLine("This is a Bird.");
        }
    }

    class Flying_Birds:Bird
    {
        public void showFlyingBird()
        {
            Console.WriteLine("This is a Flying Bird.");
        }
    }

    class Eagle:Flying_Birds
    {
        public void showEagle()
        {
            Console.WriteLine("This is an Eagle.");
        }
    }

    class Flightless_Birds:Bird
    {
        public void showFlightlessBird()
        {
            Console.WriteLine("This is a Flightless Bird.");
        }
    }

    class Penguin:Flightless_Birds
    {
        public void showPenguin()
        {
            Console.WriteLine("This is a Penguin.");
        }
    }

}*/

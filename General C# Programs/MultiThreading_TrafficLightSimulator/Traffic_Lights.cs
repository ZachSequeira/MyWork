using System;
using System.Threading;

namespace MultiThreading
{
    class Vehicles
    {
        public void Moving_North()
        {
            for (int i = 1; i < 50; i++)
            {
                if(i==25)
                {
                    Thread.Sleep(5000);
                }
                Console.WriteLine("Vehicle Moving North");
            }
        }

        public void Moving_South()
        {
            for (int i = 1; i < 50; i++)
            {
                if (i == 25)
                {
                    Thread.Sleep(5000);
                }
                Console.WriteLine("Vehicle Moving South");
            }
        }

        public void Moving_East()
        {
            for (int i = 1; i < 50; i++)
            {
               
                Console.WriteLine("Vehicle Moving East");

            }
        }
        public void Moving_West()
        {
            for (int i = 1; i < 50; i++)
            {
               
                Console.WriteLine("Vehicle Moving West");
            }
        }

    }

    class Traffic_Lights
    {
        static void Main()
        {
            Vehicles obj = new Vehicles();
            
            

            Thread t1 = new Thread(obj.Moving_North);
            Thread t2 = new Thread(obj.Moving_South);
            Thread t3 = new Thread(obj.Moving_East);
            Thread t4 = new Thread(obj.Moving_West);


            t1.Start();
            t2.Start();
            t3.Start();
            t4.Start();


        }

    }
}
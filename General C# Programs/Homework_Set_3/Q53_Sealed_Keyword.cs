/*Q53.) Demonstrate the use of sealed keyword.(with class and methods)*/
/*using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Homework_Set_3
{
    class A
    {

        public virtual void demo1()
        {
            Console.WriteLine("Demo 1 of Class A");
        }
        public virtual void demo2()
        {
            Console.WriteLine("Demo 2 of Class A");

        }
    }

    class B : A
    {
        public override void demo1()
        {
            Console.WriteLine("Demo 1 of class B");

        }
        public sealed override void demo2()
        {
            Console.WriteLine("This is Demo 2 of class B");
        }

    }

    class C : B
    {
        public override void demo1()
        {
            Console.WriteLine("This is demo 1 of Class C");
        }

        //cannot override demo2 as it is sealed in Class B
        
    }

   
    class D
    {
        static void Main()
        {
            Console.WriteLine("For Class A:");
            A objA = new A();
            objA.demo1();
            objA.demo2();
            
            Console.WriteLine("------------------------------------");
            
            Console.WriteLine("For Class B:");
            B objB = new B();
            objB.demo1();
            objB.demo2();
            Console.WriteLine("Class B can override both demo 1 and 2 as they aren't sealed in Class A");

            Console.WriteLine("------------------------------------");

            Console.WriteLine("For Class C:");
            C objC = new C();
            objC.demo1();
            objC.demo2();
            Console.WriteLine("Class C can override only demo 1 as demo 2 is sealed in Class B and is using the demo2 overriden by Class B.");
            Console.WriteLine("------------------------------------");
        }
    }
}*/
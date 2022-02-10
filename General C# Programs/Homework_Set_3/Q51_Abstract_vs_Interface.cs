/*Q51.) Demonstrate the difference between abstract class and interface.*/
/*using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_Set_3
{
    abstract class Abs1
    {
        int a = 2, b = 3;//data fields as well as functions can be declared in an anstract class

        public int Add()//function is defined in an abstract class
        {
            return (a + b);
        }
    }

    abstract class Abs2
    {
        int x = 5, y = 10;
        public int Add()
        {
            return (x + y);
        }

    }

    interface I_1
    {
        public void demo1();//data fields cannot be declared in an interface. Function is only declared and not defined
        
    }

    interface I_2
    {
        public void demo2();
   
    }

    class A : Abs1//Only 1 class can be inherited as multiple inheritence is not supported
    { }
    class B : Abs2
    { }

    class C : I_1, I_2
    {
        public void demo1()
        {
            Console.WriteLine("This is the demo method in Interface 1");
            
        }

        public void demo2()
        {
            Console.WriteLine("This is the demo method in Interface 2");

        }
    }

    class D : Abs1, I_1, I_2//Multiple Interfaces can be inherited
    {
        public void demo1()
        {
            Console.WriteLine("This is the demo method in Interface 1");
        }

        public void demo2()
        {
            Console.WriteLine("This is the demo method in Interface 2");

        }

        
    }

   class E
    {
        static void Main()
        {
            //Abstract classes Abs1 and Abs2 cannot be made into objects. therefore their methods are being called through class A and B
            Console.WriteLine("For Class A inheriting from abstract class Abs1:");
            A a = new A();
            Console.WriteLine("Addition in class Abs1: " + a.Add());
            Console.WriteLine("----------------------------------------------------");

            Console.WriteLine("For Class B inheriting from abstract class Abs2:");
            B b = new B();
            Console.WriteLine("Addition in class Abs2: " + b.Add());
            Console.WriteLine("----------------------------------------------------");

            //Interfaces cannot be made into objects either. Their functions are defined in the class which inherits them.
            Console.WriteLine("For Class C inheriting from Interface I_1 and I_2:");
            C c = new C();
            c.demo1();
            c.demo2();
            Console.WriteLine("----------------------------------------------------");

            Console.WriteLine("For Class D inheriting from Abstract class Abs1 and Interface I_1 and I_2:");
            D d = new D();
            d.demo1();
            d.demo2();
            Console.WriteLine("Addition in class Abs1: " + a.Add());
            Console.WriteLine("----------------------------------------------------");
        }
    }

}*/




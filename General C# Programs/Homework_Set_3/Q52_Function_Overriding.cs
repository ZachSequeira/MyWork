/*Q52.) Write a program which will demonstrate the function overriding.*/
/*using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Homework_Set_3
{
    class A
    {
        virtual public void demo_method()
        {
            Console.WriteLine("Demo method of class A");
        }

        
    }

    class B : A
    {
        public override void demo_method()
        {
            Console.WriteLine("Demo method of class B");
        }

    }

    class C
    {
        static void Main()
        {
            A obj1 = new A();
            obj1.demo_method();

            A obj = new B();
            obj.demo_method();
            Console.WriteLine("Demo Method of Class A can be called and can be hidden. It has not been overwitten but has been overidden by class B");
         
            
        }
    }
}*/

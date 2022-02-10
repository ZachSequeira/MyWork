//Q36.) Demonstrate the use of all access specifiers with suitable example.

/*using System;

namespace Homework_Set_2
{
    class Q36_Access_Specifiers
    {
        class A
        {
            private int n1=1;
            protected int n2=2;
            public int n3=3;

            public void showA()
            {
                Console.WriteLine("Parent Class A:");
                Console.WriteLine("Private Variable n1= "+n1);//can only be used in this class, i.e the class where it is declared
                Console.WriteLine("Protected Variable n2= " + n2);//can be used in derived classes
                Console.WriteLine("Public Variable n1= " + n3);//can be used outside of the class

            }
        };

        class B:A
        {
           public void showB()
            {
                Console.WriteLine("Child Class B Inherited from Parent Class A:");
                Console.WriteLine("Protected Variable n2= "+ n2);//can be used since it is protected
                Console.WriteLine("Public Variable n3= "+n3);//can be used since it is public
            }

        };

        static void Main()
        {
            A a = new A();
            B b = new B();

            a.showA();
            Console.WriteLine("--------------------------------------------");
            b.showB();
            Console.WriteLine("--------------------------------------------");
            Console.WriteLine("Accessing Public variable n3 through main method:"+ a.n3);//can be used since it is public
        }
    }
}*/


           

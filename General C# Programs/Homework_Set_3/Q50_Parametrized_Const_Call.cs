/*Q50.) Declare a class name ‘A’ with some methods and one parameterised constructor. Derive another class ‘B’ from ‘class A’. 
 In class B have some methods and constructor. Demonstrate how base class parameterised constructor gets call from child class constructor.*/

/*using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sept_2021
{
    class A
    {
        int a, b, c;

        public A(int x, int y)
        {
            a = x;
            b = y;

            Console.WriteLine("Parameterised constructor with 2 values: " + a + "  " + b);
        }

        public A(int x, int y, int z)
        {
            a = x;
            b = y;
            c = z;

            Console.WriteLine("Parameterised constructor with 3 values: " + a + "  " + b + "  " + c);
        }


    }

    class B : A
    {
        

        public B(int x, int y) : base(x, y)
        {

        }

        public B(int x, int y, int z): base(x,y,z)
        {

        }

    }

    class D : B
    {
        public D(int a, int b):base (a,b)
        {

        }
        public D(int a, int b,int c) : base(a, b,c)
        {

        }
    }

    class C
    {
        static void Main()
        {
            D obj = new D(9, 9);
            D obj1 = new D(9, 9, 9);
        }
    }
}*/


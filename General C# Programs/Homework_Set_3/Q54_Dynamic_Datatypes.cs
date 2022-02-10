/*Q54.) Demonstrate the difference between var, object and dynamic data types with suitable example*/
/*using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework_Set_3
{
    class Q54_Dynamic_Datatypes
    {
        static void Main()
        {
            Console.WriteLine("For Var type:");
            var vA = 100;
            Console.WriteLine("Var vA initial value: "+ vA);
            Console.WriteLine("vA datatype: "+ vA.GetType());
            //Once Var datatypes are assigned they cannot be converted to another one unlike Object types

            vA += 300;
            Console.WriteLine("vA new value after addition is: "+vA);

            //operations can be performed on Var type unlike Object Types
            Console.WriteLine("------------------------------------------------------");


            Console.WriteLine("For Object type:");

            object oA = 500;
            Console.WriteLine("Object oA initial value: " + oA);
            Console.WriteLine("oA datatype: "+ oA.GetType());
            //Object type cannot have operations performed on it unlike Var types

            oA = "Hello";
            Console.WriteLine("oA's new datatype is: "+oA.GetType());
            //Object data type can easily change its type by reassigning a new value unlike Var types
            Console.WriteLine("------------------------------------------------------");
            
            Console.WriteLine("For Dynamic Type: ");

            dynamic dA = 700;
            Console.WriteLine("dynamic dA initial value: " + dA);
            Console.WriteLine("dA data type is: "+ dA.GetType());
            dA = 700 + 800;
            Console.WriteLine("dA value after addition is: "+ dA);
            //Dynamic types can have operations performed on them like Var types

            dA = "Hello";
            Console.WriteLine("new dA value: "+dA);
            Console.WriteLine("new dA datatype: "+dA.GetType());
            //Dynamic types can also have their types changed like object types
            Console.WriteLine("------------------------------------------------------");


        }

    }
}*/

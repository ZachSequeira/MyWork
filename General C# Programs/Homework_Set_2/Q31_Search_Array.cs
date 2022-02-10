//Q31.) Write a program in C# to search given element in array.

/*using System;

namespace Homework_Set_2
{
    class Q31_Search_Array
    {
        static void Main()
        {
            int n, i, ele, flg = 0, Indexpos=0;
            Console.WriteLine("Enter Number of elements:");
            n = Convert.ToInt32(Console.ReadLine());

            int[] arr = new int[n];

            Console.WriteLine("Enter the elements: ");
            for(i=0;i<n;i++)
            {
                arr[i] = Convert.ToInt32(Console.ReadLine());
            }

            Console.WriteLine("Enter element to be searched:");
            ele = Convert.ToInt32(Console.ReadLine());

            for(i=0;i<n;i++)
            {
                if(arr[i]==ele)
                {
                    flg = 1;
                    Indexpos = i;
                    break;
                }
                
            }

            if(flg>0)
            {
                Console.WriteLine(ele+" was found at Index: "+ Indexpos);
            }
           else
            {
                Console.WriteLine(ele + " was not found in the array!");
            }
            
            
        }
    }
}*/

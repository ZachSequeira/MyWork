//Q30.) Write a program in C# to sort the given array in descending order.

/*using System;

namespace Homework_Set_2
{
    class Q30_Array_Sort_Descending
    {
        static void Main()
        {
            int n, i,j, temp;

            Console.WriteLine("Enter number of elements: ");
            n = Convert.ToInt32(Console.ReadLine());

            int[] arr = new int[n];

            Console.WriteLine("Enter the elements:");
            for(i=0;i<n;i++)
            {
                arr[i] = Convert.ToInt32(Console.ReadLine());
            }

            for(i=0;i<n;i++)
            {
                for(j=i+1;j<n;j++)
                {
                    if(arr[j]>arr[i])
                    {
                        temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;

                    }
                }
            }
            Console.WriteLine("Elements sorted in descending order are: ");
            for(i=0;i<n;i++)
            {
                Console.WriteLine(arr[i]);
            }
        }
    }
}*/

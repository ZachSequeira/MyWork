//Q29.) Write a program in C# to find maximum and minimum element in an array.

/*using System;


namespace Homework_Set_2
{
    class Q29_Max_Min_Array
    {
        static void Main()
        {
            int i, n, min, max;
            Console.WriteLine("Enter the number of elements:");
            n = Convert.ToInt32(Console.ReadLine());

            int[] arr = new int[n];

            Console.WriteLine("Enter the elements:");
            for(i=0;i<n;i++)
            {
                arr[i] = Convert.ToInt32(Console.ReadLine());
            }
            min = Minimum(arr,n);
            max = Maximum(arr, n);

            Console.WriteLine("Minimum element is: "+ min);
            Console.WriteLine("Maximum elements is: "+ max);

        }

        static int Minimum(int[] arr,int n)
        {
            int min = arr[0], i, j;
            for(i=0;i<n;i++)
            {
               if(arr[i]<min)
                {
                    min = arr[i];
                }
               
            }
            return min;
        }

        static int Maximum(int[] arr, int n)
        {
            int max = arr[0], i;
            for (i = 0; i < n-1; i++)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                }
            }
            return max;
        }
    }
}*/

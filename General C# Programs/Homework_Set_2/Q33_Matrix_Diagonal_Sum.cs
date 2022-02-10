//Q33.)  Input a square matrix and find the sum of diagonal elements.

/*using System;

namespace Homework_Set_2
{
    class Q33_Matrix_Diagonal_Sum
    {
        static void Main()
        {
            int row, col, i, j, sum = 0;
            Console.WriteLine("Enter the number of Rows and Columns for the Square Matrix:");
            row = col = Convert.ToInt32(Console.ReadLine());

            int[,] arr = new int[row,col]; 
            Console.WriteLine("Enter the Matrix Elements one by one:");
            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                {
                    arr[i,j] = Convert.ToInt32(Console.ReadLine());
                    
                }
            }
            Console.WriteLine("-----------------------------------------------------------------");
            Console.WriteLine("Your entered "+row+"x"+col+" matrix is:");

            for (i = 0; i < row; i++)
            {
                for (j = 0; j < col; j++)
                {
                    Console.Write(arr[i, j] + "\t");
                }
                Console.Write("\n");
            }
            Console.WriteLine("-----------------------------------------------------------------");

            Console.WriteLine("Diagonal Elements are:");
            for (i = 0; i < row; i++)
            {
                for (j = 0; j < col; j++)
                {
                    if(i==j)
                    {
                        Console.WriteLine(arr[i,j]);
                        sum += arr[i, j];
                    }

                }
                
            }
            Console.WriteLine("-----------------------------------------------------------------");

            Console.WriteLine("The Sum of Diagonal Elements is: "+ sum);
            Console.WriteLine("-----------------------------------------------------------------");

        }
    }
}*/

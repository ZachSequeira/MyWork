//Q32.) Input one matrix and print its transpose.

/*using System;

namespace Homework_Set_2
{
    class Q32_Transpose_Matrix
    {
        static void Main()
        {
            int row, col, i, j;
            Console.WriteLine("Enter the number of Rows and Columns for the  Matrix:");
            row = col = Convert.ToInt32(Console.ReadLine());
           
            int[,] arr = new int[row,col];
            int[,] arr2 = new int[row,col];
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

            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                {
                    arr2[j, i] = arr[i, j];
                }
            }

            Console.WriteLine("Matrix after Transpose: ");
            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                {
                    Console.Write(arr2[i, j] + "\t");
                }
                Console.Write("\n");
            }
            
            Console.WriteLine("-----------------------------------------------------------------");

        }
    }
}*/

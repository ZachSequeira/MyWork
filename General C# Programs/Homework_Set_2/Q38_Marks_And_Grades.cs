//Q38.) Input 5 subjects marks from command line argument. Calculate percentage of student and assign appropriate grade.

/*using System;

namespace Homework_Set_2
{
    class Q38_Marks_And_Grades
    {
        static void Main(String[] args)
        {
            float s1, s2, s3, s4, s5, sum = 0, per;
            char grade = 'A';
            s1 = Convert.ToInt32(args[0]);
            s2 = Convert.ToInt32(args[1]);
            s3 = Convert.ToInt32(args[2]);
            s4 = Convert.ToInt32(args[3]);
            s5 = Convert.ToInt32(args[4]);

            sum = s1 + s2 + s3 + s4 + s5;
            per = (sum / 500) * 100;

            if(per<40)
            {
                grade = 'D';
            }
            else if(per>=40&&per<60)
            {
                grade = 'C';
            }
            else if(per>=60&&per<80)
            {
                grade = 'B';
            }
            else if(per>80)
            {
                grade = 'A';
            }

            Console.WriteLine("Subject 1 = " + s1+"/100");
            Console.WriteLine("Subject 2 = " + s2 + "/100");
            Console.WriteLine("Subject 3 = " + s3 + "/100");
            Console.WriteLine("Subject 4 = " + s4 + "/100");
            Console.WriteLine("Subject 5 = " + s5 + "/100");
            Console.WriteLine("Total Marks = " + sum+"/500");
            Console.WriteLine("Percentage = "+ per+"%");
            Console.WriteLine("Grade = "+ grade);
           
        }
    }
}*/

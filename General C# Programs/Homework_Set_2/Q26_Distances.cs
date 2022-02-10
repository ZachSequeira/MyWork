//Q26.) Write down a menu driven program using switch to convert various distance from one unit to other.

/*using System;

namespace Homework_Set_2
{
    class Q26_Distances
    {
        static void Main()
        {
            byte ch, contch;
            
        Choice:
            Console.WriteLine("-------------------------------------------------------------------------------------");
            Console.WriteLine("1.) Metric->Metric \n2.) Imperial->Imperial \n3.) Metric->Imperial\n4.) Imperial->Metric");
            ch = Convert.ToByte(Console.ReadLine());
            Console.WriteLine("-------------------------------------------------------------------------------------");
        
            switch(ch)
            {
                case 1:
                    {
                        contch = Metric();
                        if (contch == 1)
                        {
                            goto Choice;
                        }
                        else
                            break;
                    }
                case 2:
                    {
                        contch = Imperial();
                        if(contch==1)
                        {
                            goto Choice;
                        }
                        else
                            break;
                    }
                case 3:
                    {
                        contch = Metric_Imperial();
                        if(contch==1)
                        {
                            goto Choice;
                        }
                        else
                            break;
                    }
                case 4:
                    {
                        contch = Imperial_Metric();
                        if(contch==1)
                        {
                            goto Choice;
                        }
                        else
                            break;
                    }
                default:
                    {
                        Console.WriteLine("Incorrect choice. Choose Again!");
                        goto Choice;
                    }
            }
            Console.WriteLine("-------------------------------------------------------------------------------------");

            Console.WriteLine("PROGRAM ENDED!");
            Console.WriteLine("-------------------------------------------------------------------------------------");

        }

        static byte Metric()
       {
            byte ch, ch2, ch3;
            double mm, cm, m, km;
            Console.WriteLine("You have chosen Metric to Metric Conversion! Choose the unit you wish to convert!");
            
            choose:
                Console.WriteLine("-------------------------------------------------------------------------------------");
                Console.WriteLine("1.) Millimetre\n2.) Centimetre\n3.) Metre\n4.) Kilometre");
                ch = Convert.ToByte(Console.ReadLine());
                Console.WriteLine("-------------------------------------------------------------------------------------");

                switch (ch)
                {
                    case 1:
                        {
                            Console.WriteLine("Enter the distance in Milimetres:");
                            mm = Convert.ToInt32(Console.ReadLine());
                            Console.WriteLine(mm+" mm is: ");
                            cm = mm / 10;
                            m = mm / 1000;
                            km = mm / 1000000;
                            Console.WriteLine(cm+ " cm");
                            Console.WriteLine(m+ " m");
                            Console.WriteLine(km+ " km");
                            Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                            ch2 = Convert.ToByte(Console.ReadLine());
                            if(ch2 ==1)
                            {
                                goto choose;
                            }
                            else
                            break;
                        }
                    case 2:
                        {
                            Console.WriteLine("Enter the distance in Centimetres:");
                            cm = Convert.ToInt32(Console.ReadLine());
                            Console.WriteLine(cm + " cm is: ");
                            mm = cm * 10;
                            m = cm / 100;
                            km = cm / 100000;
                            Console.WriteLine(mm + " mm");
                            Console.WriteLine(m + " m");
                            Console.WriteLine(km + " km");
                            Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                            ch2 = Convert.ToByte(Console.ReadLine());
                            if (ch2 == 1)
                            {
                                goto choose;
                            }
                            else
                            break;
                        }
                    case 3:
                        {
                            Console.WriteLine("Enter the distance in Metres:");
                            m = Convert.ToInt32(Console.ReadLine());
                            Console.WriteLine(m + " m is: ");
                            mm = m * 1000;
                            cm = m * 100;
                            km = m / 1000;
                            Console.WriteLine(mm + " mm");
                            Console.WriteLine(cm + " cm");
                            Console.WriteLine(km + " km");
                            Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                            ch2 = Convert.ToByte(Console.ReadLine());
                            if (ch2 == 1)
                            {
                                goto choose;
                            }
                            else
                            break;
                        
                        }
                    case 4:
                        {
                            Console.WriteLine("Enter the distance in Kilometres:");
                            km = Convert.ToInt32(Console.ReadLine());
                            Console.WriteLine(km + " km is: ");
                            mm = km * 1000000;
                            cm = km * 100000;
                            m = km * 1000;
                            Console.WriteLine(mm + " mm");
                            Console.WriteLine(cm + " cm");
                            Console.WriteLine(m + " m");
                        Console.WriteLine("-------------------------------------------------------------------------------------");

                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                            ch2 = Convert.ToByte(Console.ReadLine());
                            if (ch2 == 1)
                            {
                                goto choose;
                            }
                            else
                            break;

                        }
                    
                    default:
                        {
                            Console.WriteLine("Incorrect choice. Choose Again");
                            goto choose;
                        }
                }
            Console.WriteLine("-------------------------------------------------------------------------------------");

            Console.WriteLine("Do you want to Choose another Conversion? 1:Y||2:N");
                ch3 = Convert.ToByte(Console.ReadLine());
                return ch3;
       }
       static byte Imperial()
        {
            byte ch, ch2, ch3;
            double inch, ft, yd, mi;
            Console.WriteLine("You have chosen Imperial to Imperial Conversion! Choose the unit you wish to convert!");

        choose:
            Console.WriteLine("-------------------------------------------------------------------------------------");
            Console.WriteLine("1.) Inches\n2.) Feet\n3.) Yards\n4.) Miles");
            ch = Convert.ToByte(Console.ReadLine());
            Console.WriteLine("-------------------------------------------------------------------------------------");


            switch (ch)
            {
                case 1:
                    {
                        Console.WriteLine("Enter the distance in Inches:");
                        inch = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(inch + " inches is: ");
                        ft = inch / 12;
                        yd = inch / 36;
                        mi = inch / 63360;
                        Console.WriteLine(ft + " Feet");
                        Console.WriteLine(yd + " Yards");
                        Console.WriteLine(mi + " Miles");
                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                        ch2 = Convert.ToByte(Console.ReadLine());
                        if (ch2 == 1)
                        {
                            goto choose;
                        }
                        else
                            break;
                    }
                case 2:
                    {
                        Console.WriteLine("Enter the distance in Feet:");
                        ft = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(ft + " Feet is: ");
                        inch = ft * 12;
                        yd = ft / 3;
                        mi = ft / 5280;
                        Console.WriteLine(inch + " Inches");
                        Console.WriteLine(yd + " Yards");
                        Console.WriteLine(mi + " Miles");
                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                        ch2 = Convert.ToByte(Console.ReadLine());
                        if (ch2 == 1)
                        {
                            goto choose;
                        }
                        else
                            break;
                    }
                case 3:
                    {
                        Console.WriteLine("Enter the distance in Yards:");
                        yd = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(yd + " Yards is: ");
                        inch = yd * 36;
                        ft = yd * 3;
                        mi = yd / 1760;
                        Console.WriteLine(inch + " Inches");
                        Console.WriteLine(ft + " Feet");
                        Console.WriteLine(mi + " Miles");
                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                        ch2 = Convert.ToByte(Console.ReadLine());
                        if (ch2 == 1)
                        {
                            goto choose;
                        }
                        else
                            break;

                    }
                case 4:
                    {
                        Console.WriteLine("Enter the distance in Miles:");
                        mi = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(mi + " Miles is: ");
                        inch = mi * 63360;
                        ft = mi * 5280;
                        yd = mi * 1760;
                        Console.WriteLine(inch + " Inches");
                        Console.WriteLine(ft + " Feet");
                        Console.WriteLine(yd + " Yards");
                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                        ch2 = Convert.ToByte(Console.ReadLine());
                        if (ch2 == 1)
                        {
                            goto choose;
                        }
                        else
                            break;

                    }

                default:
                    {
                        Console.WriteLine("Incorrect choice. Choose Again");
                        goto choose;
                    }
            }
            Console.WriteLine("-------------------------------------------------------------------------------------");

            Console.WriteLine("Do you want to Choose another Conversion? 1:Y||2:N");
            ch3 = Convert.ToByte(Console.ReadLine());
            return ch3;
        }
       static byte Metric_Imperial()
        {
            byte ch, ch2, ch3;
            double mm, cm, m, km;
            double inch, ft, yd, mi;
            Console.WriteLine("You have chosen Metric to Imperial Conversion! Choose the unit you wish to convert!");

        choose:
            Console.WriteLine("-------------------------------------------------------------------------------------");
            Console.WriteLine("1.) Millimetre\n2.) Centimetre\n3.) Metre\n4.) Kilometre");
            ch = Convert.ToByte(Console.ReadLine());
            Console.WriteLine("-------------------------------------------------------------------------------------");

            switch (ch)
            {
                case 1:
                    {
                        Console.WriteLine("Enter the distance in Milimetres:");
                        mm = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(mm + " mm is: ");
                        inch = mm / 25.4;
                        ft = mm / 305;
                        yd = mm / 914;
                        mi = mm / 1609344;
                        Console.WriteLine(inch + " Inches");
                        Console.WriteLine(ft + " Feet");
                        Console.WriteLine(yd + " Yards");
                        Console.WriteLine(mi + " Miles");
                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                        ch2 = Convert.ToByte(Console.ReadLine());
                        if (ch2 == 1)
                        {
                            goto choose;
                        }
                        else
                            break;
                    }
                case 2:
                    {
                        Console.WriteLine("Enter the distance in Centimetres:");
                        cm = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(cm + " cm is: ");
                        inch = cm / 2.54;
                        ft = cm / 30.48;
                        yd = cm / 91.44;
                        mi = cm / 160934;
                        Console.WriteLine(inch + " Inches");
                        Console.WriteLine(ft + " Feet");
                        Console.WriteLine(yd + " Yards");
                        Console.WriteLine(mi + " Miles");
                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                        ch2 = Convert.ToByte(Console.ReadLine());
                        if (ch2 == 1)
                        {
                            goto choose;
                        }
                        else
                            break;
                    }
                case 3:
                    {
                        Console.WriteLine("Enter the distance in Metres:");
                        m = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(m + " m is: ");
                        inch = m * 39.37;
                        ft = m * 3.281;
                        yd = m * 1.094;
                        mi = m / 1609;
                        Console.WriteLine(inch + " Inches");
                        Console.WriteLine(ft + " Feet");
                        Console.WriteLine(yd + " Yards");
                        Console.WriteLine(mi + " Miles");
                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                        ch2 = Convert.ToByte(Console.ReadLine());
                        if (ch2 == 1)
                        {
                            goto choose;
                        }
                        else
                            break;

                    }
                case 4:
                    {
                        Console.WriteLine("Enter the distance in Kilometres:");
                        km = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(km + " km is: ");
                        inch = km * 39370;
                        ft = km * 3281;
                        yd = km * 1094;
                        mi = km / 1.609;
                        Console.WriteLine(inch + " Inches");
                        Console.WriteLine(ft + " Feet");
                        Console.WriteLine(yd + " Yards");
                        Console.WriteLine(mi + " Miles");
                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                        ch2 = Convert.ToByte(Console.ReadLine());
                        if (ch2 == 1)
                        {
                            goto choose;
                        }
                        else
                            break;

                    }

                default:
                    {
                        Console.WriteLine("Incorrect choice. Choose Again");
                        goto choose;
                    }
            }
            Console.WriteLine("-------------------------------------------------------------------------------------");

            Console.WriteLine("Do you want to Choose another Conversion? 1:Y||2:N");
            ch3 = Convert.ToByte(Console.ReadLine());
            return ch3;
        }
       static byte Imperial_Metric()
        {
            byte ch, ch2, ch3;
            double mm, cm, m, km;
            double inch, ft, yd, mi;
            Console.WriteLine("You have chosen Imperial to Metric Conversion! Choose the unit you wish to convert!");

        choose:
            Console.WriteLine("-------------------------------------------------------------------------------------");
            Console.WriteLine("1.) Inches\n2.) Feet\n3.) Yards\n4.) Miles");
            ch = Convert.ToByte(Console.ReadLine());
            Console.WriteLine("-------------------------------------------------------------------------------------");

            switch (ch)
            {
                case 1:
                    {
                        Console.WriteLine("Enter the distance in Inches:");
                        inch = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(inch + " Inches is: ");
                        mm = inch * 25.4;
                        cm = inch * 2.54;
                        m = inch / 39.37;
                        km = inch / 39370;
                        Console.WriteLine(mm + " mm");
                        Console.WriteLine(cm + " cm");
                        Console.WriteLine(m + " m");
                        Console.WriteLine(km + " km");
                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                        ch2 = Convert.ToByte(Console.ReadLine());
                        if (ch2 == 1)
                        {
                            goto choose;
                        }
                        else
                            break;
                    }
                case 2:
                    {
                        Console.WriteLine("Enter the distance in Feet:");
                        ft = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(ft + " Feet is: ");
                        mm = ft * 305;
                        cm = ft * 30.48;
                        m = ft / 3.281;
                        km = ft / 3281;
                        Console.WriteLine(mm + " mm");
                        Console.WriteLine(cm + " cm");
                        Console.WriteLine(m + " m");
                        Console.WriteLine(km + " km");
                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                        ch2 = Convert.ToByte(Console.ReadLine());
                        if (ch2 == 1)
                        {
                            goto choose;
                        }
                        else
                            break;
                    }
                case 3:
                    {
                        Console.WriteLine("Enter the distance in Yards:");
                        yd = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(yd + " Yards is: ");
                        mm = yd * 914;
                        cm = yd * 91.44;
                        m = yd / 1.094;
                        km = yd / 1094;
                        Console.WriteLine(mm + " mm");
                        Console.WriteLine(cm + " cm");
                        Console.WriteLine(m + " m");
                        Console.WriteLine(km + " km");
                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                        ch2 = Convert.ToByte(Console.ReadLine());
                        if (ch2 == 1)
                        {
                            goto choose;
                        }
                        else
                            break;

                    }
                case 4:
                    {
                        Console.WriteLine("Enter the distance in Miles:");
                        mi = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine(mi + " Miles is: ");
                        mm = mi * 1609344;
                        cm = mi * 160934;
                        m = mi * 1609;
                        km = mi * 1.609;
                        Console.WriteLine(mm + " mm");
                        Console.WriteLine(cm + " cm");
                        Console.WriteLine(m + " m");
                        Console.WriteLine("Do you want to convert another distance in the same Conversion? 1:Y||2:N");
                        ch2 = Convert.ToByte(Console.ReadLine());
                        if (ch2 == 1)
                        {
                            goto choose;
                        }
                        else
                            break;

                    }

                default:
                    {
                        Console.WriteLine("Incorrect choice. Choose Again");
                        goto choose;
                    }
            }
            Console.WriteLine("-------------------------------------------------------------------------------------");

            Console.WriteLine("Do you want to Choose another Conversion? 1:Y||2:N");
            ch3 = Convert.ToByte(Console.ReadLine());
            return ch3;
        }
    }
}*/

//Q48.) Take Account as abstract class. Make saving a/c and current a/c as its child. Make hierarchical inheritance between them. 

/*using System;

namespace Homework_Set_2
{
    class Q48_Abstract_Class_Heirarchical_Inheritance
    {
        abstract class Account
        {
            protected double balance;
            protected double amt;
            protected int PIN;
            protected string Acc_no;
            protected string name;

        }

        class Savings_AC:Account
        {
            public Savings_AC(string n, string acc, int pin)
            {
                name = n;
                Acc_no = acc;
                PIN = pin;
                balance = 1000;
            }


            public void Deposit()
            {
                Console.WriteLine("Your current balance is: " + balance);
                Console.WriteLine("How much do you want to Deposit?");
                amt = Convert.ToDouble(Console.ReadLine());
                balance += amt;
                Console.WriteLine("Your current balance is: " + balance);
                Console.WriteLine("------------------------------------------------------------------------");

            }

            public void Withdraw()
            {
                Console.WriteLine("Your current balance is: " + balance);

            enter:
                Console.WriteLine("How much do you want to Withdraw?");
                amt = Convert.ToDouble(Console.ReadLine());
                if ((balance-amt) < 1000)
                {
                    Console.WriteLine("Remaining balance is below 1000. Enter again.");
                    goto enter;
                }
                balance -= amt;
                Console.WriteLine("Your current balance is: " + balance);
                Console.WriteLine("------------------------------------------------------------------------");

            }

            public void Display()
            {
                Console.WriteLine("Name: " + name);
                Console.WriteLine("Account Number: " + Acc_no);
                Console.WriteLine("Balance: " + balance);
                Console.WriteLine("------------------------------------------------------------------------");

            }
        }

        class Current_AC:Account
        {
            public Current_AC(string n, string acc, int pin)
            {
                name = n;
                Acc_no = acc;
                PIN = pin;
                balance = 5000;
            }

            
            public void Deposit()
            {
                Console.WriteLine("Your current balance is: "+ balance);
                Console.WriteLine("How much do you want to Deposit?");
                amt = Convert.ToDouble(Console.ReadLine());
                balance += amt;
                Console.WriteLine("Your current balance is: "+balance);
                Console.WriteLine("------------------------------------------------------------------------");

            }

            public void Withdraw()
            {
                Console.WriteLine("Your current balance is: " + balance);
                
            enter:
                Console.WriteLine("How much do you want to Withdraw?");
                amt = Convert.ToDouble(Console.ReadLine());
                if((balance-amt) < 5000)
                {
                    Console.WriteLine("Remaining balance is below 5000. Enter again.");
                    goto enter;
                }
                balance -= amt;
                Console.WriteLine("Your current balance is: " + balance);
                Console.WriteLine("------------------------------------------------------------------------");

            }

            public void Display()
            {
                Console.WriteLine("Name: "+name);
                Console.WriteLine("Account Number: "+Acc_no);
                Console.WriteLine("Balance: "+balance);
                Console.WriteLine("------------------------------------------------------------------------");

            }
        }
        static void Main()
        {
            int ch, PIN;
            string name, acc_no;
            
        choose:
            Console.WriteLine("WELCOME!!");
            Console.WriteLine("------------------------------------------------------------------------");
            Console.WriteLine("1.) Savings\n2.) Current");
            ch = Convert.ToInt32(Console.ReadLine());

            switch(ch)
            {
                case 1:
                    {
                        int op;
                        Console.WriteLine("------------------------------------------------------------------------");

                        Console.WriteLine("You have Selected Savings Account!");
                        Console.WriteLine("Enter Your name:");
                        name = Console.ReadLine();
                        Console.WriteLine("Enter your Account Number:");
                        acc_no = Console.ReadLine();
                        Console.WriteLine("Enter you 4 digit PIN");
                        PIN = Convert.ToInt32(Console.ReadLine());

                        Savings_AC Save = new Savings_AC(name, acc_no, PIN);
                        opchoose:
                        Console.WriteLine("------------------------------------------------------------------------");

                        Console.WriteLine("1.) Withdraw\n2.) Deposit\n3.) Display Details");
                        op = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine("------------------------------------------------------------------------");


                        switch (op)
                        {
                            case 1:
                                {
                                    LabelChoose:
                                    Save.Withdraw();
                                    Console.WriteLine("1.) Stay in Savings Account.\n2.) Change to another Account.\n3.) Exit");
                                    op = Convert.ToInt32(Console.ReadLine());

                                    switch (op)
                                    {
                                        case 1:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto opchoose;
                                            }
                                        case 2:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto choose;
                                            }
                                        case 3:
                                            {
                                                Console.WriteLine("TRANSACTION COMPLETE!");
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                break;
                                            }
                                        default:
                                            {
                                                Console.WriteLine("Incorrect Selection! Choose Again!");
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto LabelChoose;
                                            }
                                    }
                                    break;
                                }
                            case 2:
                                {
                                    LabelChoose:
                                    Console.WriteLine("------------------------------------------------------------------------");

                                    Save.Deposit();
                                    Console.WriteLine("1.) Stay in Savings Account.\n2.) Change to another Account.\n3.) Exit");
                                    op = Convert.ToInt32(Console.ReadLine());
                                    Console.WriteLine("------------------------------------------------------------------------");


                                    switch (op)
                                    {
                                        case 1:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto opchoose;
                                            }
                                        case 2:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto choose;
                                            }
                                        case 3:
                                            {
                                                Console.WriteLine("TRANSACTION COMPLETE!");

                                                Console.WriteLine("------------------------------------------------------------------------");

                                                break;
                                            }
                                        default:
                                            {
                                                Console.WriteLine("Incorrect Selection! Choose Again!");
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto LabelChoose;
                                            }
                                    }
                                    break;
                                }
                            case 3:
                                {
                                    LabelChoose:
                                    Console.WriteLine("------------------------------------------------------------------------");

                                    Save.Display();
                                    Console.WriteLine("1.) Stay in Savings Account.\n2.) Change to another Account.\n3.) Exit");
                                    op = Convert.ToInt32(Console.ReadLine());
                                    Console.WriteLine("------------------------------------------------------------------------");


                                    switch (op)
                                    {
                                        case 1:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto opchoose;
                                            }
                                        case 2:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto choose;
                                            }
                                        case 3:
                                            {
                                                Console.WriteLine("TRANSACTION COMPLETE!");

                                                Console.WriteLine("------------------------------------------------------------------------");

                                                break;
                                            }
                                        default:
                                            {
                                                Console.WriteLine("Incorrect Selection! Choose Again!");
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto LabelChoose;
                                            }
                                    }
                                    break;
                                }
                            default:
                                {
                                    Console.WriteLine("Incorrect selection! Choose again!");
                                    Console.WriteLine("------------------------------------------------------------------------");

                                    goto opchoose;
                                }

                        }

                        break;
                    }
                case 2:
                    {
                        int op;
                        Console.WriteLine("------------------------------------------------------------------------");

                        Console.WriteLine("You have Selected Current Account!");
                        Console.WriteLine("Enter Your name:");
                        name = Console.ReadLine();
                        Console.WriteLine("Enter your Account Number:");
                        acc_no = Console.ReadLine();
                        Console.WriteLine("Enter you 4 digit PIN");
                        PIN = Convert.ToInt32(Console.ReadLine());
                        Current_AC Curr = new Current_AC(name, acc_no, PIN);

                    opchoose:
                        Console.WriteLine("------------------------------------------------------------------------");

                        Console.WriteLine("1.) Withdraw\n2.) Deposit");
                        op = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine("------------------------------------------------------------------------");


                        switch (op)
                        {
                            case 1:
                                {
                                    LabelChoose:
                                    Curr.Withdraw();
                                    Console.WriteLine("1.) Stay in Current Account.\n2.) Change to another Account.\n3.) Exit");
                                    op = Convert.ToInt32(Console.ReadLine());
                                    Console.WriteLine("------------------------------------------------------------------------");


                                    switch (op)
                                    {
                                        case 1:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto opchoose;
                                            }
                                        case 2:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto choose;
                                            }
                                        case 3:
                                            {
                                                Console.WriteLine("TRANSACTION COMPLETE!");

                                                Console.WriteLine("------------------------------------------------------------------------");

                                                break;
                                            }
                                        default:
                                            {
                                                Console.WriteLine("Incorrect Selection! Choose Again!");
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto LabelChoose;
                                            }
                                    }
                                    break;
                                }
                            case 2:
                                {
                                    LabelChoose:
                                    Console.WriteLine("------------------------------------------------------------------------");

                                    Curr.Deposit();
                                    Console.WriteLine("1.) Stay in Current Account.\n2.) Change to another Account.\n3.) Exit");
                                    op = Convert.ToInt32(Console.ReadLine());
                                    Console.WriteLine("------------------------------------------------------------------------");


                                    switch (op)
                                    {
                                        case 1:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto opchoose;
                                            }
                                        case 2:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto choose;
                                            }
                                        case 3:
                                            {
                                                Console.WriteLine("TRANSACTION COMPLETE!");

                                                Console.WriteLine("------------------------------------------------------------------------");

                                                break;
                                            }
                                        default:
                                            {
                                                Console.WriteLine("Incorrect Selection! Choose Again!");
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto LabelChoose;
                                            }
                                    }
                                    break;
                                }
                            case 3:
                                {
                                LabelChoose:
                                    Console.WriteLine("------------------------------------------------------------------------");

                                    Curr.Display();
                                    Console.WriteLine("1.) Stay in Current Account.\n2.) Change to another Account.\n3.) Exit");
                                    op = Convert.ToInt32(Console.ReadLine());
                                    Console.WriteLine("------------------------------------------------------------------------");


                                    switch (op)
                                    {
                                        case 1:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto opchoose;
                                            }
                                        case 2:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                goto choose;
                                            }
                                        case 3:
                                            {
                                                Console.WriteLine("TRANSACTION COMPLETE!");

                                                Console.WriteLine("------------------------------------------------------------------------");

                                                break;
                                            }
                                        default:
                                            {
                                                Console.WriteLine("------------------------------------------------------------------------");

                                                Console.WriteLine("Incorrect Selection! Choose Again!");
                                                goto LabelChoose;
                                            }
                                    }
                                    break;
                                }
                            default:
                                {
                                    Console.WriteLine("Incorrect selection! Choose again!");
                                    Console.WriteLine("------------------------------------------------------------------------");

                                    goto opchoose;
                                }

                        }
                        break;
                    }
                default:
                    {
                        Console.WriteLine("Incorrect selection! Choose Again!");
                        Console.WriteLine("------------------------------------------------------------------------");

                        goto choose;
                    }
            }

        }
    }
}*/

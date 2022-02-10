#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
void main()
{
    //Setting the values of each door Randomly
    int door1, door2, door3, ch, final_door;
    char yn;
    srand(time(NULL));
    door1 = rand()%2;
    if(door1==1)
    {
        door2=0;
        door3=0;
    }
    else if(door1==0)
    {
        door2=rand()%2;
        if(door2==1)
        {
            door3=0;
        }
        else if(door2==0)
        {
            door3=1;
        }
    }
    //Player Choosing their Door
    Label_Choose_Door_First:
    {
        printf("Pick a Door 1-2-3:\n");
        scanf("%d", &ch);
        printf("--------------------------------------------------------\n");
        switch(ch)
        {
            case 1:
            {
                printf("You've selected Door 1!\n");
                if(door2==1)
                {
                    printf("Door 3 = %d\n", door3);
                }
                else if(door2==0)
                {
                    printf("Door 2 = %d\n", door2);
                }
                printf("--------------------------------------------------------\n");
                break;
            }
            case 2:
            {
                printf("You've selected Door 2!\n");
                if(door1==1)
                {
                    printf("Door 3 = %d\n", door3);
                }
                else if(door1==0)
                {
                    printf("Door 1 = %d\n", door1);
                }
                printf("--------------------------------------------------------\n");
                break;
            }
            case 3:
            {
                printf("You've selected Door 3!\n");
                if(door2==1)
                {
                    printf("Door 1 = %d\n", door1);
                }
                else if(door2==0)
                {
                    printf("Door 2 = %d\n", door2);
                }
                printf("--------------------------------------------------------\n");
                break;
            }
            default:
            {
                printf("Wrong Selection! Enter again!\n");
                printf("--------------------------------------------------------\n");
                goto Label_Choose_Door_First;
                break;
            }
        }
    }
    
    getchar();
    
    //Player Choosing to Switch Door or Not
    printf("Do you want to switch your door?Y:N?\n");
    scanf("%c",&yn);
    printf("--------------------------------------------------------\n");
    if(yn=='n'||yn=='N')
    {
       if(ch==1)
       {
           if(door1==1)
           {
               printf("Your Selected Door 1 = %d\n", door1);
               printf("The Unchosen Door had 0\n");
               printf("--------------------------------------------------------\n");
               printf("YOU WIN!\n");
           }
           else if(door1==0)
           {
               printf("Your Selected Door 1 = %d\n", door1);
               printf("The Unchosen Door had 1\n");
               printf("--------------------------------------------------------\n");
               printf("YOU LOSE!\n");  
           }
       }
       else if(ch==2)
       {
           if(door2==1)
           {
               printf("Your Selected Door 2 = %d\n", door2);
               printf("The Unchosen Door had 0\n");
               printf("--------------------------------------------------------\n");
               printf("YOU WIN!\n");
           }
           else if(door2==0)
           {
               printf("Your Selected Door 2 = %d\n", door2);
               printf("The Unchosen Door had 1\n");
               printf("--------------------------------------------------------\n");
                printf("YOU LOSE!\n");  
           }
       }
       else if(ch==3)
       {
           if(door3==1)
           {
               printf("Your Selected Door 3 = %d\n", door3);
               printf("The Unchosen Door had 0\n");
               printf("--------------------------------------------------------\n");
               printf("YOU WIN!\n");
           }
           else if(door3==0)
           {
               printf("Your Selected Door 3 = %d\n", door3);
               printf("The Unchosen Door had 1\n");
               printf("--------------------------------------------------------\n");
               printf("YOU LOSE!\n");  
           }
       }
    }
    else if(yn=='Y'||yn=='y')
    {
        if(ch==1)
        {
           if(door2==1)
           {
               final_door=door2;
               printf("The Originally Selected Door 1 had: %d\n", door1);
               printf("The Selected Door 2 has: %d\n", final_door);
               printf("--------------------------------------------------------\n");
               if(final_door==1)
               {
                   printf("YOU WIN!\n");
               }
               else if(final_door==0)
               {
                   printf("YOU LOSE!\n");
               }
           }
           else if(door2==0)
           {
               final_door=door3;
               printf("The Originally Selected Door 1 had: %d\n", door1);
               printf("The Selected Door 3 has: %d\n", final_door);
               printf("--------------------------------------------------------\n");
               if(final_door==1)
               {
                   printf("YOU WIN!\n");
               }
               else if(final_door==0)
               {
                   printf("YOU LOSE!\n");
               }
           }
        }
        else if(ch==2)
        {
            if(door1==1)
            {
                final_door=door1;
                printf("The Originally Selected Door 2 had: %d\n", door2);
                printf("The Selected Door 1 has: %d\n", final_door);
                printf("--------------------------------------------------------\n");
                if(final_door==1)
               {
                   printf("YOU WIN!\n");
               }
               else if(final_door==0)
               {
                   printf("YOU LOSE!\n");
               }
            }
            else if(door1==0)
            {
                final_door=door3;
                printf("The Originally Selected Door 2 had: %d\n", door2);
                printf("The Selected Door 3 has: %d\n", final_door);
                printf("--------------------------------------------------------\n");
                if(final_door==1)
               {
                   printf("YOU WIN!\n");
               }
               else if(final_door==0)
               {
                   printf("YOU LOSE!\n");
               }
            }
        }
        else if(ch==3)
        {
            if(door1==1)
            {
                final_door=door1;
                printf("The Originally Selected Door 3 had: %d\n", door3);
                printf("The Selected Door 1 has: %d\n", final_door);
                printf("--------------------------------------------------------\n");
                if(final_door==1)
               {
                   printf("YOU WIN!\n");
               }
               else if(final_door==0)
               {
                   printf("YOU LOSE!\n");
               }
            }
            else if(door1==0)
            {
                final_door=door2;
                printf("The Originally Selected Door 3 had: %d\n", door3);
                printf("The Selected Door 2 has: %d\n", final_door);
                printf("--------------------------------------------------------\n");
                if(final_door==1)
               {
                   printf("YOU WIN!\n");
               }
               else if(final_door==0)
               {
                   printf("YOU LOSE!\n");
               }
            }
        }
    }
    printf("--------------------------------------------------------\n");
    printf("Door 1: %d\nDoor 2: %d\nDoor 3: %d\n", door1,door2,door3);
    printf("--------------------------------------------------------\n");
}



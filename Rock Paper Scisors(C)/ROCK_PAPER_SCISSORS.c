#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

int play(char u, char cpu);

void main()
{
    
    int n, cntu=0, cntcpu=0;
    char u, cpu, res;
    printf("Best of 3 wins!\n");
    printf("-----------------------------------------------------------\n");
    printf("ENTER r for ROCK ------ p for Paper ----- s for Scissors\n");
    printf("-----------------------------------------------------------\n");
    Label_Play:
    {
    for(int i=1;i<4;i++)
    {
        scanf("%c", &u);
        srand(time(NULL));
    
        n= rand()%100;
        if (n <33)
        {
            cpu = 'r';
        }
        else if(n>33 &&n<66)
        {
            cpu = 'p';
        }
        else
        {
            cpu = 's';
        }
    
        
        res=play(u,cpu);
        
        if(res==-1)
        {
            printf("You chose : %c and Computer chose : %c\n",u, cpu);
            printf("IT's A DRAW!!\n");
            printf("Computer score = %d     Your Score = %d\n", cntcpu, cntu);
            printf("-----------------------------------------------------------\n");
            printf("ENTER r for ROCK ------ p for Paper ----- s for Scissors\n");
            printf("-----------------------------------------------------------\n");
            goto Label_Play;
        }
    
        if(res == 1)
        {
            ++cntu;
            printf("You chose : %c and Computer chose : %c\n",u, cpu);
            printf("YOU WON THE ROUND!!!\n");
            printf("Computer score = %d     Your Score = %d\n", cntcpu, cntu);
        
            if(cntu==2)
            {
                printf("-----------------------------------------------------------\n");
                printf("***********************************************************\n");
                printf("-----------------------------------------------------------\n");
                printf("CONGRATULATIONS!!! YOU WON THE GAME!\n");
                printf("Computer score = %d     Your Score = %d\n", cntcpu, cntu);
                printf("-----------------------------------------------------------\n");
                printf("***********************************************************\n");
                printf("-----------------------------------------------------------\n");
                exit(0) ;
            }
            else
            {
                printf("-----------------------------------------------------------\n");
                printf("ENTER r for ROCK ------ p for Paper ----- s for Scissors\n");
                printf("-----------------------------------------------------------\n");
                goto Label_Play;
            }
        }
        
        if(res==0)
        {
            ++cntcpu;
            printf("You chose : %c and Computer chose : %c\n",u, cpu);
            printf("YOU LOST THE ROUND!\n");
            printf("Computer score = %d     Your Score = %d\n", cntcpu, cntu);
        
            if(cntcpu==2)
            {
                printf("-----------------------------------------------------------\n");
                printf("***********************************************************\n");
                printf("-----------------------------------------------------------\n");
                printf("THE COMPUTER WON THE GAME!\n");
                printf("Computer score = %d     Your Score = %d\n", cntcpu, cntu);
                printf("-----------------------------------------------------------\n");
                printf("***********************************************************\n");
                printf("-----------------------------------------------------------\n");
                exit(0);
            }
            else
            {
                printf("-----------------------------------------------------------\n");
                printf("ENTER r for ROCK ------ p for Paper ----- s for Scissors\n");
                printf("-----------------------------------------------------------\n");
                goto Label_Play;
            }
        }
        
    }
    }
}   

int play(char u, char cpu)
{
    if(u==cpu)
    {
        return -1;
    }
    
    if(u== 'r' && cpu=='p')
    {
        return 0;
    }
    else if(u=='p' && cpu=='r')
    {
        return 1;
    }
    
    if(u=='s' && cpu=='r')
    {
        return 0;
    }
    else if(u=='r' && cpu=='s')
    {
        return 1;
    }
    
    if(u=='p' && cpu=='s')
    {
        return 0;
    }
    else if(u=='s' && cpu=='p')
    {
        return 1;
    }
}













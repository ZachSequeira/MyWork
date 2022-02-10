#include <stdio.h>
#include <stdlib.h>

int Size;
int TOP=-1;
int stack[100];
void push();
void pop();
void Status();
void Display();
void main()
{
    int ch,op;
    printf("How many items do you want in the stack?\n");
    scanf("%d", &Size);
    printf("--------------------------------------------------------------------------\n");
    label_Choose:
    {
        printf("\nEnter 1 to Push.\nEnter 2 to Pop.\nEnter 3 to display Status.\n");
        scanf("%d", &ch);
        printf("--------------------------------------------------------------------------\n");
        switch(ch)
        {
            case 1:
            {
                push();
                printf("\nDo you want to perform another operation?\nEnter 1 for YES.\nEnter 2 for NO.\n");
                scanf("%d", &op);
                 printf("--------------------------------------------------------------------------\n");
                if(op==1)
                {
                    goto label_Choose;
                }
                else if(op==2)
                {
                    printf("***PROGRAM ENDED***");
                    exit(0);
                }
            }
            case 2:
            {   
                pop();
                printf("\nDo you want to perform another operation?\nEnter 1 for YES.\nEnter 2 for NO.\n");
                scanf("%d", &op);
                printf("--------------------------------------------------------------------------\n");
                if(op==1)
                {
                    goto label_Choose;
                }
                else if(op==2)
                {
                    printf("***PROGRAM ENDED***");
                    exit(0);
                }
            }
            case 3:
            {
                Status();
                printf("Do you want to perform another operation?\nEnter 1 for YES.\nEnter 2 for NO.\n");
                scanf("%d", &op);
                printf("--------------------------------------------------------------------------\n");
                if(op==1)
                {
                    goto label_Choose;
                }
                else if(op==2)
                {
                    printf("\n***PROGRAM ENDED***");
                    exit(0);
                }
            }
            default :
            {
                printf("WRONG INPUT!\n");
                goto label_Choose;
            }
        }
    }   
}
void push()
{
    int ITEM;
    if(TOP>=Size-1)
    {
        printf("Stack is Full!\n");
    }
    else
    {
        printf("Enter Item to be inserted into the stack:\n");
        scanf("%d", &ITEM);
        TOP=TOP+1;
        stack[TOP]=ITEM;
        printf("Stack after inserting new Item: %d\n", ITEM);
        printf("\n--------------------------------------------------------------------------\n");
        Display();
        printf("\n--------------------------------------------------------------------------\n");
    }
    
}
void pop()
{
    int ITEM;
    if(TOP<0)
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        ITEM=stack[TOP];
        TOP-=1;
    }
    printf("Stack after removing Item %d:\n", ITEM);
    Display();
    printf("\n--------------------------------------------------------------------------\n");
}
void Status()
{
    double Free_Space;
    if(TOP<0)
    {
        printf("Stack is Empty!\n");
    }
    else if(TOP>=Size)
    {
        printf("Stack is Full!\n");
    }
    else
    {
        printf("The Item at the Top is: %d\n", stack[TOP]);
        Free_Space=((Size-TOP)-1)/(Size-1)*100;
        printf("The number of Free Spaces in the Stack are: %d\n", ((Size-TOP)-1));
        //printf("The percentage of free space remaining in the stack is: %lf percent\n", Free_Space);
    }
    printf("\n--------------------------------------------------------------------------\n");
}
void Display()
{
    int i;
    for(i=0;i<=TOP;i++)
    {
        printf("%d\t", stack[i]);
    }
}



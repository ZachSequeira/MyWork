#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *link;
}*HEAD;

void Create_List();
void PUSH();
void POP();
void Status();
void Display();

void main()
{
    int n, ch, op;
    printf("An Empty Single Linked List Stack has been created!\n");

    Create_List();
    Display();
    printf("--------------------------------------------------------------\n");
    
    Label_Choose:
    {
        printf("Enter 1. to PUSH.\nEnter 2. to POP.\nEnter 3. to Display Status.\n");
        scanf("%d", &ch);
        printf("--------------------------------------------------------------\n");
        switch(ch)
        {
            case 1:
            {
                PUSH();
                printf("--------------------------------------------------------------\n");
                Display();
                printf("--------------------------------------------------------------\n");
                printf("Do you want to choose another operation? 1=Y,2=N?\n");
                scanf("%d", &op);
                printf("--------------------------------------------------------------\n");
                
                if(op == 1)
                {
                    goto Label_Choose;
                }
                else if(op == 2)
                {
                    printf("PROGRAM ENDED!");
                    exit(0);
                }
                break;
            }
            case 2:
            {
                POP();
                printf("--------------------------------------------------------------\n");
                Display();
                printf("--------------------------------------------------------------\n");
                printf("Do you want to choose another operation? 1=Y,2=N?\n");
                scanf("%d", &op);
                printf("--------------------------------------------------------------\n");
                
                if(op == 1)
                {
                    goto Label_Choose;
                }
                else if(op == 2)
                {
                    printf("PROGRAM ENDED!");
                    exit(0);
                }
                break;
            }
            case 3:
            {
                Status();
                printf("--------------------------------------------------------------\n");
                Display();
                printf("--------------------------------------------------------------\n");
                printf("Do you want to choose another operation? 1=Y,2=N?\n");
                scanf("%d", &op);
                printf("--------------------------------------------------------------\n");
                
                if(op == 1)
                {
                    goto Label_Choose;
                }
                else if(op == 2)
                {
                    printf("PROGRAM ENDED!");
                    exit(0);
                }
                break;
            }
            default :
            {
                printf("--------------------------------------------------------------\n");
                printf("Wrong Selection!\n");
                printf("--------------------------------------------------------------\n");
                goto Label_Choose;
            }
        
        }
    }
}

void Create_List()
{
    
    HEAD = (struct NODE*)malloc(sizeof(struct NODE));
    
    if(HEAD==NULL)
    {
        printf("\nMemory Allocation Failure!!\n");
        exit(0);
    }
    else
    {
        HEAD->data = 0;
        HEAD->link = NULL;
    }
    printf("\n-----------------------------------------------------------------------\n");
}

void PUSH()
{
    struct NODE *newNODE;
    int DATA;
    newNODE = (struct NODE*)malloc(sizeof(struct NODE));
    
    printf("Entered DATA to be inserted into the New Node:\n");
    scanf("%d", &DATA);
    
    if(newNODE==NULL)
    {
        printf("Memory Allocation Failure!!\n");
    }
    else
    {
        newNODE->data=DATA;
        newNODE->link=HEAD->link;
        HEAD->link=newNODE;
        printf("DATA Pushed into the Stack!\n");
    }
}

void POP()
{
    struct NODE *ptr;
    struct NODE *ptr1;
    ptr=HEAD;
    
    if(ptr->link==NULL)
    {
        printf("The Stack is Empty!!\n");
    }
    else
    {
        printf("DATA has been Popped from the Stack!!\n");
        ptr1=ptr;
        ptr=ptr->link;
        ptr1->link=ptr->link;
        free(ptr);
    }
}

void Status()
{
    struct NODE *ptr;
    int i, cnt;
    ptr=HEAD;
    
    if(ptr==NULL)
    {
        printf("Stack is Currently Empty!\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            ptr=ptr->link;
            cnt++;
        }
        printf("The Stack currently has %d Items in it!\n", (cnt - 1));
    }
}
void Display()
{
    struct NODE *ptr;
    ptr=HEAD;
    if(ptr==NULL)
    {
        printf("List is Empty!\n");
    }
    else
    
    {
        while (ptr!=NULL)
        {
            printf("%d->", ptr->data);
            ptr=ptr->link;
        }
        printf("NULL");
        printf("\n");
    }
}


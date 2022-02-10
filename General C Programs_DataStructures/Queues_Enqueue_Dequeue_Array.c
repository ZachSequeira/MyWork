#include <stdio.h>
#include <stdlib.h>

int Queue[100];
int rear=-1;
int front=-1;
void EnQueue(int);
void DeQueue(int);
void Display_Queue();

void main()
{
    int size, ch, yn;
    printf("Enter max size of the Queue\n");
    scanf("%d", &size);
    printf("---------------------------------------------------------\n");
    
    
    Label_Choose:
    {
        printf("Enter 1 for Enqueue.\nEnter 2 for Dequeue.\n");
        scanf("%d", &ch);
        printf("---------------------------------------------------------\n");
        switch(ch)
        {
            case 1:
            {
                EnQueue(size);
                break;
            }
            case 2:
            {
                DeQueue(size);
                break;
            }
                default:
            {
                printf("Wrong Choice\n");
                printf("---------------------------------------------------------\n");
                goto Label_Choose;
                break;
            }
        }
        
        printf("Do you want to perform another operation?\n");
        printf("Enter 1 for Yes, 2 for No\n");
        scanf("%d", &yn);
        
        if(yn == 1)
        {
            printf("---------------------------------------------------------\n");
            goto Label_Choose;
        }
        else if(yn == 2)
        {
            printf("---------------------------------------------------------\n");
            exit(0);
        }
             
    }
}

void EnQueue(int s)
{
    int ITEM;
    
    if(rear==(s - 1))
    {
        printf("Queue is Full!\n");
    }
    else 
    {
        printf("Enter the item to be inserted:\n");
        scanf("%d", &ITEM);
        printf("---------------------------------------------------------\n");
        if((rear==-1)&&(front==-1))
        {
            front=0;
        }
        rear=rear + 1;
        Queue[rear]=ITEM;
    }
    Display_Queue();
}

void DeQueue(int s)
{
    int ITEM;
    if(front==-1)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        ITEM=Queue[front];
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front = front + 1;
        }
        Display_Queue();
    }
    
}

void Display_Queue()
{
   int i;
   printf("The updated Queue is:\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d ", Queue[i]);
    } 
   printf("\n---------------------------------------------------------\n");
}





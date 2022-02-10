#include <stdio.h>
#include <stdlib.h>

int Queue[100];
int rear=-1;
int front=-1;

void Eject_DQ(int);
void PUSH_DQ(int);

void Display_Queue1(int);

void main()
{
    int size, ch, yn;
    printf("Enter max size of the Queue\n");
    scanf("%d", &size);
    printf("---------------------------------------------------------\n");
    
    
    Label_Choose:
    {
        printf("Enter 1 Inserting at FRONT 2. Deleting at REAR.\n");
        scanf("%d", &ch);
        printf("---------------------------------------------------------\n");
        switch(ch)
        {
            case 1:
            {
                PUSH_DQ(size);
                break;
            }
            case 2:
            {
                Eject_DQ(size);
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

void PUSH_DQ(int s)
{
    int ITEM;
    
    if(front==rear + 1)
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
            rear=0;
        }
        else if(front==0)
        {
            front=s - 1;
        }
        else
        {
            front=front - 1;
        }
        Queue[front]=ITEM;
    }
    Display_Queue1(s);
}

void Eject_DQ(int s)
{
    int ITEM;
    if(front==-1)
    {
        printf("Queue is Empty!\n");
    }
    else
    {

        ITEM=Queue[rear];
        if(front==rear)
        {
            front=rear=-1;
        }
        else if(rear==0)
        {
            rear=s - 1;
        }
        else
        {
            rear=rear - 1;
        }
        Display_Queue1(s);
    }
    
}


void Display_Queue1(int s)
{
   int i;
   
   printf("The updated Queue is:\n");
   if(rear==0)
   {
    printf("%d\t",Queue[0]);
    if(front!=0)
    {
     for(i=(s - 1);i>=front;i--)
     {
        printf("%d\t", Queue[i]);
     } 
   }
  }
   else
   {
      for(i=rear;i>=front;i--)
     {
        printf("%d\t", Queue[i]);
     }  
   }
   printf("\n---------------------------------------------------------\n");
}


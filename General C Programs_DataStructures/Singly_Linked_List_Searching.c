#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *link;
}*HEAD;

void Create_List(int n);
void Search();
void Display_List();
void main()
{
    int n; 
    printf("Enter the Total number of nodes in the list:\n");
    scanf("%d", &n);
    printf("---------------------------------------------------------------------------\n");
    Create_List(n);
    Display_List();
    printf("---------------------------------------------------------------------------\n");
    Search();
    printf("---------------------------------------------------------------------------\n");
    
}

void Create_List(int n)
{
    struct NODE *new_NODE, *ptr;
    int data, i;
    HEAD=(struct NODE*)malloc(sizeof(struct NODE));
    if(HEAD==NULL)
    {
        printf("MEMORY ALLOCATION FAILURE!\n");
    }
    else
    {
        HEAD->data=0;
        HEAD->link=NULL;
        ptr=HEAD;
        for(i=1;i<=n;i++)
        {
            new_NODE=(struct NODE*)malloc(sizeof(struct NODE));
            if(new_NODE==NULL)
            {
                printf("MEMORY ALLOCATION FAILURE!\n");
                break;
            }
            else
            {
                printf("Enter the data in Node %d: ", i);
                scanf("%d", &data);
                new_NODE->data=data;
                new_NODE->link=NULL;
                ptr->link=new_NODE;
                ptr=ptr->link;
            }
        }
        
    }
    printf("---------------------------------------------------------------------------\n");
    printf("Single Linked List with %d Nodes has been created!\n", n);

}

void Search()
{
    struct NODE *ptr, *loc;
    ptr=HEAD->link;
    loc=NULL;
    int key, cnt=1;
    
    printf("Enter the Data to be Searched:\n");
    scanf("%d", &key);
    printf("---------------------------------------------------------------------------\n");
        
    while(ptr!=NULL && ptr->data!=key)
    {
        ptr=ptr->link;
        cnt++;
    }
        
    if(ptr->data!=key)
    {
        printf("Element not Found!\n");
    }
    else
    {
        loc=ptr;
        printf("Node #%d containing data %d is found at Memory Address: %p\n",cnt, key, loc );
    }
}


void Display_List()
{
    struct NODE *ptr;
    ptr=HEAD;
    if(ptr->link==NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d->", ptr->data);
            ptr=ptr->link;
        }
        printf("NULL");
        printf("\n");
    }
}



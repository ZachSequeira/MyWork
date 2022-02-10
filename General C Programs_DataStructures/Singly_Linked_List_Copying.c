#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *link;
}*HEAD, *HEAD_C;

void Create_List(int n);
void Copy();
void Display_List();
void Display_Copy();
void main()
{
    int n; 
    printf("Enter the Total number of nodes in the list:\n");
    scanf("%d", &n);
    printf("---------------------------------------------------------------------------\n");
    Create_List(n);
    Display_List();
    Copy();
    printf("---------------------------------------------------------------------------\n");
    printf("The Copied List is:\n");
    Display_Copy();
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

void Copy()
{
    struct NODE *new_NODE, *ptr, *ptr1;
    ptr=HEAD;
    HEAD_C=(struct NODE*)malloc(sizeof(struct NODE));
    ptr1=HEAD_C;
    ptr->data=0;
    
    while(ptr!=NULL)
    {
        new_NODE=(struct NODE*)malloc(sizeof(struct NODE));
        new_NODE->data=ptr->data;
        ptr1->link=new_NODE;
        new_NODE->link=NULL;
        ptr1=new_NODE;
        ptr=ptr->link;
    }
    
}

void Display_Copy()
{
    struct NODE *ptr;
    
    ptr=HEAD_C->link;
    if(ptr==NULL)
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


#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *Llink;
    struct NODE *Rlink;
}*HEAD;

void Create_List(int n);
void Insert_At_Beg(int data);
void Insert_At_End(int data);
void Insert_Anywhere(int data, int key);
void Display_List();
void main()
{
    int n, data, choice, key;
    printf("Enter the Total number of nodes:\n");
    scanf("%d", &n);
    Create_List(n);
    printf("Data in the list:\n");
    Display_List();
    printf("---------------------------------------------------------------------------\n");
    printf("Enter the Data to be inserted:");
    scanf("%d", &data);
    printf("---------------------------------------------------------------------------\n");
    printf("Enter 1 to Insert at the Beginning.\nEnter 2 to Insert at the End.\nEnter 3 to insert anywhere.\n");
    scanf("%d", &choice);
    printf("---------------------------------------------------------------------------\n");
   
    Label_Choose:
    {
        switch(choice)
        {
            case 1:
            {
                Insert_At_Beg(data);
                break;
            }
            case 2:
            {
                Insert_At_End(data);
                break;
            }
            case 3:
            {
                printf("After which element do you want to insert the new data?\n");
                scanf("%d", &key);
                Insert_Anywhere(data, key);
                break;
            }
            default :
            {
            printf("Wrong Choice.\n");
            goto Label_Choose;
            }
        }
    }
    printf("Data in the list after insertion:\n");
    Display_List();
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
        HEAD->Rlink=NULL;
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
                new_NODE->Rlink=NULL;
                ptr->Rlink=new_NODE;
                new_NODE->Llink=ptr;
                ptr=new_NODE;
            }
        }
        
    }
    printf("---------------------------------------------------------------------------\n");
    printf("Doubly Linked List with %d Nodes has been created!\n", n);
}

void Insert_Anywhere(int data, int key)
{
    struct NODE *new_NODE;
    struct NODE *ptr;
    struct NODE *ptr1, *ptr2;
    ptr=HEAD;
    
    new_NODE=(struct NODE*)malloc(sizeof(struct NODE));
    if(new_NODE==NULL)
    {
        printf("MEMORY ALLOCATION FAILURE!\n");
    }
    else
    {
        
        while(ptr->Rlink!=NULL && ptr->data!=key)
        {
            ptr1=ptr;
            ptr=ptr->Rlink;
        }
        
        if(ptr==NULL)
        {
            printf("Element not Found!\n");
        }
        else
        {
            ptr1=ptr;
            ptr2=ptr->Rlink;
            new_NODE->data=data;
            new_NODE->Rlink=ptr->Rlink;
            ptr2->Llink=new_NODE;
            ptr1->Rlink=new_NODE;
            new_NODE->Llink=ptr1;
            printf("Data Inserted after Key Element %d!\n", key);
        }
    }
}

void Insert_At_End(int data)
{
    
    struct NODE *new_NODE;
    struct NODE *ptr;
    ptr=HEAD;
    new_NODE=(struct NODE*)malloc(sizeof(struct NODE));
    if(new_NODE==NULL)
    {
        printf("MEMORY ALLOCATION FAILURE!\n");
    }
    else
    {
        printf("Data Inserted at the End!\n");
        while(ptr->Rlink!=NULL)
        {
            ptr=ptr->Rlink;
        }
        new_NODE->data=data;
        ptr->Rlink=new_NODE;
        new_NODE->Llink=ptr;
        new_NODE->Rlink=NULL;
    }
}
void Insert_At_Beg(int data)
{
    struct NODE *new_NODE, *ptr2;
    new_NODE=(struct NODE*)malloc(sizeof(struct NODE));
    if(new_NODE==NULL)
    {
        printf("MEMORY ALLOCATION FAILURE!\n");
    }
    else
    {
        ptr2=HEAD->Rlink;
        new_NODE->data=data;
        new_NODE->Rlink=HEAD->Rlink;
        ptr2->Llink=new_NODE;
        HEAD->Rlink=new_NODE;
        new_NODE->Llink=HEAD;
        printf("Data inserted at the beginning!\n");
    }
}


void Display_List()
{
    struct NODE *ptr;
    ptr=HEAD;
    if(ptr==NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d<->", ptr->data);
            ptr=ptr->Rlink;
        }
        printf("NULL");
        printf("\n");
    }
}




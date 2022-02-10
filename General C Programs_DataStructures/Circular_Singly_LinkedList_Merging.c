#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *link;
}*HEAD1, *HEAD2;

void Create_List(int n1, int n2);
void Merge();
void Display_List(int n1, int n2);
void Display_Merge();
void main()
{
    int n1,n2, data; 
    printf("Enter the Total number of nodes in list 1:\n");
    scanf("%d", &n1);
    printf("Enter the Total number of nodes in list 2:\n");
    scanf("%d", &n2);
    printf("---------------------------------------------------------------------------\n");
    Create_List(n1, n2);
    Display_List(n1, n2);
    printf("---------------------------------------------------------------------------\n");
    Merge();
    printf("Data in the Circular Linked list after Merging:\n");
    Display_Merge();
    printf("---------------------------------------------------------------------------\n");
    
}

void Create_List(int n1, int n2)
{
    struct NODE *new_NODE1, *ptr1;
    struct NODE *new_NODE2, *ptr2;
    int data, i;
    HEAD1=(struct NODE*)malloc(sizeof(struct NODE));
    HEAD2=(struct NODE*)malloc(sizeof(struct NODE));
    
    printf("LIST 1 DATA ENTRY:\n");
    if(HEAD1==NULL)
    {
        printf("MEMORY ALLOCATION FAILURE!\n");
    }
    else
    {
        HEAD1->data=0;
        HEAD1->link=NULL;
        ptr1=HEAD1;
        for(i=1;i<=n1;i++)
        {
            new_NODE1=(struct NODE*)malloc(sizeof(struct NODE));
            if(new_NODE1==NULL)
            {
                printf("MEMORY ALLOCATION FAILURE!\n");
                break;
            }
            else
            {
                printf("Enter the data in Node %d: ", i);
                scanf("%d", &data);
                new_NODE1->data=data;
                new_NODE1->link=HEAD1;
                ptr1->link=new_NODE1;
                ptr1=ptr1->link;
            }
        }
        
    }
     printf("---------------------------------------------------------------------------\n");
    printf("LIST 2 DATA ENTRY:\n");
    if(HEAD2==NULL)
    {
        printf("MEMORY ALLOCATION FAILURE!\n");
    }
    else
    {
        HEAD2->data=0;
        HEAD2->link=NULL;
        ptr2=HEAD2;
        for(i=1;i<=n2;i++)
        {
            new_NODE2=(struct NODE*)malloc(sizeof(struct NODE));
            if(new_NODE2==NULL)
            {
                printf("MEMORY ALLOCATION FAILURE!\n");
                break;
            }
            else
            {
                printf("Enter the data in Node %d: ", i);
                scanf("%d", &data);
                new_NODE2->data=data;
                new_NODE2->link=HEAD2;
                ptr2->link=new_NODE2;
                ptr2=ptr2->link;
            }
        }
    }
    printf("---------------------------------------------------------------------------\n");
}

void Merge()
{
    struct NODE *ptr1;
    struct NODE *ptr_a, *ptr_b;
    struct NODE *ptr_a1, *ptr_b1;
    ptr_a=HEAD1->link;
    ptr_b=HEAD2->link;
    HEAD1->link=ptr_b;
    while(ptr_b!=HEAD2)
    {
        ptr1=ptr_b;
        ptr_b=ptr_b->link;
    }
    ptr1->link=ptr_a;
    free(HEAD2);
}

void Display_List(int n1, int n2)
{
    struct NODE *ptr1;
    struct NODE *ptr2;
    
    printf("Circular Linked List 1 with %d nodes has been created!\n", n1);
    ptr1=HEAD1->link;
    if(ptr1==NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        printf("HEADER 1->");
        while(ptr1!=HEAD1)
        {
            printf("%d->", ptr1->data);
            ptr1=ptr1->link;
        }
        printf("HEADER 1");
        printf("\n");
    }
    
    printf("Circular Linked List 2 with %d nodes has been created!\n", n2);
    ptr2=HEAD2->link;
    if(ptr2==NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        printf("HEADER 2->");
        while(ptr2!=HEAD2)
        {
            printf("%d->", ptr2->data);
            ptr2=ptr2->link;
        }
        printf("HEADER 2");
        printf("\n");
    }
}

void Display_Merge()
{
    struct NODE *ptr1;
    
    
    ptr1=HEAD1->link;
    if(ptr1==NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        printf("HEADER 1->");
        while(ptr1!=HEAD1)
        {
            printf("%d->", ptr1->data);
            ptr1=ptr1->link;
        }
        printf("HEADER 1");
        printf("\n");
    }
}


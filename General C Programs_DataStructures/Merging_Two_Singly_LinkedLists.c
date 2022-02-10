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
    printf("Data in the list after Merging:\n");
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
                new_NODE1->link=NULL;
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
                new_NODE2->link=NULL;
                ptr2->link=new_NODE2;
                ptr2=ptr2->link;
            }
        }
    }
    printf("---------------------------------------------------------------------------\n");
}

void Merge()
{
    struct NODE *ptr_a, *ptr_b;
    struct NODE *ptr_a1, *ptr_b1;
    ptr_a=HEAD1;
    ptr_b=HEAD2;

    while(ptr_a->link!=NULL)
    {
        ptr_a=ptr_a->link;
    }
    ptr_a->link=ptr_b->link;
    free(ptr_b);
}

void Display_List(int n1, int n2)
{
    struct NODE *ptr1;
    struct NODE *ptr2;
    
    printf("Linked List 1 with %d nodes has been created!\n", n1);
    ptr1=HEAD1;
    if(ptr1==NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        while(ptr1!=NULL)
        {
            printf("%d->", ptr1->data);
            ptr1=ptr1->link;
        }
        printf("NULL");
        printf("\n");
    }
    
    printf("Linked List 2 with %d nodes has been created!\n", n2);
    ptr2=HEAD2;
    if(ptr2==NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        while(ptr2!=NULL)
        {
            printf("%d->", ptr2->data);
            ptr2=ptr2->link;
        }
        printf("NULL");
        printf("\n");
    }
}

void Display_Merge()
{
    struct NODE *ptr1;
    
    
    ptr1=HEAD1;
    if(ptr1==NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        while(ptr1!=NULL)
        {
            printf("%d->", ptr1->data);
            ptr1=ptr1->link;
        }
        printf("NULL");
        printf("\n");
    }
}




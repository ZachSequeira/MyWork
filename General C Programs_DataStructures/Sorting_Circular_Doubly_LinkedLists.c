#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *Llink;
    struct NODE *Rlink;
}*HEAD;

void Create_List(int n);
int Swap(int*, int*);
void Sort();
void Display_List();

void main()
{
    int n, data, choice;
    printf("Enter the Total number of nodes:\n");
    scanf("%d", &n);
    Create_List(n);
    printf("Data in the list:\n");
    Display_List();
    printf("---------------------------------------------------------------------------\n");
    printf("The Sorted Circular Doubly Linked List is:\n");
    Sort();
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
                new_NODE->Rlink=HEAD;
                HEAD->Llink=new_NODE;
                ptr->Rlink=new_NODE;
                new_NODE->Llink=ptr;
                ptr=new_NODE;
            } 
        }
       // <->LLink-H-RLink<->LLink-11-RLink<->LLink-New-RLink<->
       //                         ptr
    }
    printf("---------------------------------------------------------------------------\n");
    printf("Circular Doubly Linked List with %d Nodes has been created!\n", n);
}

int Swap(int *ptr1, int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void Sort()
{
    struct NODE *ptr_B, *ptr_E, *ptr1, *ptr2;
    ptr_B=HEAD->Rlink;
    ptr_E=HEAD->Llink;
    
    while(ptr_B!=ptr_E)
    {
        ptr1=ptr_B;
        ptr2=ptr1->Rlink;
        
        while(ptr1!=ptr_E)
        {
            if((ptr1->data)>(ptr2->data))
            {
                Swap(&(ptr1->data),&(ptr2->data));
            }
            
            ptr1=ptr1->Rlink;
            ptr2=ptr2->Rlink;
        }
        
        ptr_E=ptr_E->Llink;
    }
}

void Display_List()
{
    struct NODE *ptr;
    ptr=HEAD->Rlink;
    if(ptr==NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        printf("HEAD<->");
        while(ptr!=HEAD)
        {
            printf("%d<->", ptr->data);
            ptr=ptr->Rlink;
        }
        printf("HEAD");
        printf("\n");
    }
}



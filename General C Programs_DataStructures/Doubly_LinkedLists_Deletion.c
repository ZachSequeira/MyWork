#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *Llink;
    struct NODE *Rlink;
}*HEAD;

void Create_List(int n);
void Delete_At_Beg();
void Delete_At_End();
void Delete_Anywhere();
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
    printf("Enter 1 to Delete at the Beginning.\nEnter 2 to Delete at the End.\nEnter 3 to Delete anywhere.\n");
    scanf("%d", &choice);
    printf("---------------------------------------------------------------------------\n");
   
    Label_Choose:
    {
        switch(choice)
        {
            case 1:
            {
                Delete_At_Beg();
                break;
            }
            case 2:
            {
                Delete_At_End();
                break;
            }
            case 3:
            {
                printf("Which element do you want to delete?\n");
                Delete_Anywhere();
                break;
            }
            default :
            {
            printf("Wrong Choice.\n");
            goto Label_Choose;
            }
        }
    }
    printf("Data in the list after Deletion:\n");
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

void Delete_Anywhere()
{
    struct NODE *ptr;
    struct NODE *ptr1, *ptr2;
    ptr=HEAD;
    int data;
    if(ptr->Rlink!=NULL)
    {
        printf("Enter the Data to be Deleted:\n");
        scanf("%d", &data);
        printf("---------------------------------------------------------------------------\n");
        
        while(ptr->Rlink!=NULL && ptr->data!=data)
        {
            ptr1=ptr;
            ptr=ptr->Rlink;
        }
        
        if(ptr->Rlink==NULL)
        {
            printf("Element not Found!\n");
        }
        else
        {
            ptr2=ptr->Rlink;
            ptr1->Rlink=ptr->Rlink;
            ptr2->Llink=ptr1;
            free(ptr);
            printf("Key Element %d has been deleted!\n", data);
        }
    }
    else
    {
        printf("There are no nodes to be deleted!\n");
        printf("---------------------------------------------------------------------------\n");
        exit(0);
    }
}

void Delete_At_End()
{
    struct NODE *ptr;
    struct NODE *ptr1;
    ptr=HEAD;

    
    if(ptr->Rlink!=NULL)
    {
        printf("Data Deleted at the End!\n");
        while(ptr->Rlink!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->Rlink;
        }
    
        ptr1->Rlink=NULL;
        free(ptr);
    }
    else
    {
        printf("There are no nodes to be deleted!\n");
        printf("---------------------------------------------------------------------------\n");
        exit(0);
    }

}
void Delete_At_Beg()
{
    struct NODE *ptr;
    struct NODE *ptr1;
    ptr=HEAD->Rlink;

    if(ptr!=NULL)
    {
        
        printf("Data Deleted at the beginning!\n"); 
        ptr1=ptr->Rlink;
        HEAD->Rlink=ptr1;
        ptr1->Llink=HEAD;
        free(ptr);
    }
    else
    {
      printf("There are no nodes to be deleted!\n");
      printf("---------------------------------------------------------------------------\n");
      exit(0);
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


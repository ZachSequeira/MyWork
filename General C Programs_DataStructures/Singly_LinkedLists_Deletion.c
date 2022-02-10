#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    struct NODE *link;
}*HEAD;

void Create_List(int n);
void Delete_Anywhere();
void Delete_At_Beg();
void Delete_At_End();
void Display_List();
void main()
{
    int n, data, choice, yn;
    printf("Enter the Total number of nodes:\n");
    scanf("%d", &n);
    Create_List(n);
    printf("Data in the list:\n");
    Display_List();
    printf("---------------------------------------------------------------------------\n");
    
    Label_Delete_Again:
    {
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
        printf("Do you want to delete more data? Enter 1 for YES, 2 for NO.\n");
        scanf("%d", &yn);
        printf("---------------------------------------------------------------------------\n");
    
        if(yn==1)
        {
            goto Label_Delete_Again;
        }
        else if(yn==2)
        {
            printf("***PROGRAM ENDED***");
            exit(0);
        }
    }
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

void Delete_Anywhere()
{
    struct NODE *ptr;
    struct NODE *ptr1;
    ptr=HEAD;
    int key;
    if(ptr->link!=NULL)
    {
        printf("Enter the Data to be Deleted:\n");
        scanf("%d", &key);
        printf("---------------------------------------------------------------------------\n");
        
        while(ptr->link!=NULL && ptr->data!=key)
        {
            ptr1=ptr;
            ptr=ptr->link;
        }
        
        if(ptr->data!=key)
        {
            printf("Element not Found!\n");
        }
        else
        {
            ptr1->link=ptr->link;
            free(ptr);
            printf("Key Element %d has been deleted!\n", key);
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

    if(ptr->link!=NULL)
    {
        printf("Data Deleted at the End!\n");
        while(ptr->link!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->link;
        }
    
        ptr1->link=ptr->link;
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
    ptr=HEAD;

    
    
    if(ptr->link!=NULL)
    {
        printf("Data Deleted at the beginning!\n");
        ptr1=ptr;
        ptr=ptr->link;
        ptr1->link=ptr->link;
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
            printf("%d->", ptr->data);
            ptr=ptr->link;
        }
        printf("NULL");
        printf("\n");
    }
}



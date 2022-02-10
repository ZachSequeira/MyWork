#include <stdio.h>
#include <stdlib.h>
struct node 
{
    struct node *LC;
    struct node *RC;
    int data;
} *root;

void Build_Tree(int, struct node*);
void In_Order(struct node*);
void Pre_Order(struct node*);
void Post_Order(struct node*);

void main()
{
    int ch, n;
    root=(struct node*)malloc(sizeof(struct node*));
    
    printf("Enter Data of Root Node:\n");
    scanf("%d",&n);
    
    Build_Tree(n,root);
    
    Label_Choose:
    {
        printf("\nSelect which type of traversal you want to use in the Tree:\n");
        printf("1.) In Order Traversal.\n2.) Pre Order Traversal.\n3.) Post Order Traversal.\n");
        scanf("%d", &ch);
    
    
        switch(ch)
        {
            case 1: 
            {
                In_Order(root);
                goto Label_Choose;
                break;
            }
            case 2:
            {
                Pre_Order(root);
                goto Label_Choose;
                break;
            }
            case 3:
            {
                Post_Order(root);
                goto Label_Choose;
                break;
            }
            default:
            {
                printf("Incorrect Selection!\n");
                goto Label_Choose;
                break;
            }
        }
    }
}

void Build_Tree(int DATA, struct node *ptr)
{
    char ch;
    struct node *Lptr, *Rptr;
    if(ptr!=NULL)
    {
        ptr->data = DATA;
        
        
        //Entering Data into Left Sub Tree
        printf("Node %d has Left Sub Tree? Y:N\n", ptr->data);
        scanf("%c", &ch);
        
        if(ch=='y'||ch=='Y')
        {
            printf("Enter the data to be inserted into left sub tree:\n");
            scanf("%d", &DATA);
            getchar();
            Lptr=(struct node*)malloc(sizeof(struct node*));
            ptr->LC=Lptr;
            Build_Tree(DATA, Lptr);
        }
        else
        {
            getchar();
            Lptr=NULL;
            ptr->LC=Lptr;
            Build_Tree(0, Lptr);
        }
        
        //Entering Data into Right Sub Tree
        printf("Node %d has Right Sub Tree? Y:N\n", ptr->data);
        scanf("%c", &ch);
        
        if(ch=='y'||ch=='Y')
        {
            printf("Enter the data to be inserted into Right sub tree:\n");
            scanf("%d", &DATA);
            getchar();
            Rptr=(struct node*)malloc(sizeof(struct node*));
            ptr->RC=Rptr;
            Build_Tree(DATA, Rptr);
        }
        else
        {
            getchar();
            Rptr=NULL;
            ptr->RC=Rptr;
            Build_Tree(0, Rptr);
        }
    }
    
}

void In_Order(struct node *ptr)
{
    if(ptr!=NULL)
    {
        In_Order(ptr->LC);
        printf("%d\t",ptr->data);
        In_Order(ptr->RC);
    }
}
void Pre_Order(struct node *ptr)
{
    if(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        Pre_Order(ptr->LC);
        Pre_Order(ptr->RC);
    }
}
void Post_Order(struct node *ptr)
{
    if(ptr!=NULL)
    {
        Post_Order(ptr->LC);
        Post_Order(ptr->RC);
        printf("%d\t",ptr->data);
    }
}


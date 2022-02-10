#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int Size=100;
int TOP=-1;
int stack[100];
char pop();
int ISP(char);
int ICP(char);
void push(char);

void main()
{
    char symbol[20];
    char item;
    char x;
    printf("Enter the expression:");
    scanf("%s", symbol);
    push(symbol[0]);
    int i=1;
    int op;
    while(TOP>-1)
    {
      item=symbol[i];
      x=pop();
    
        if(isalnum(item))
        {
           op =1;
        }
        else if(item==')')
        {
            op=2;
        }
        else if(ISP(x)>=ICP(x))
        {
            op=3;
        }
        else if(ISP(x)<ICP(x))
        {
            op=4;
        }
        
        switch(op)
        {
            case 1: 
            {
                push(x);
                printf("%c", item);
                break;
            }
            case 2:
            {
                while(x!='(')
                {
                    printf("%c", x);
                    x=pop();
                }
                break;
            }
            case 3:
            {
                while(ISP(x)>=ICP(item))
                {
                    printf("%c", x);
                    x=pop();
                }
                push(x);
                push(item);
                break;
            }
            case 4:
            {
                push(x);
                push(item);
                break;
            }
            default:
            {
                printf("Invalid Expression");
                break;
            }
        }
        i++;
    }
    
}

void push(char item)
{
     if (TOP>=Size-1)
     {
        printf("stack is full");
     }
    else
    {
        TOP++;
        stack[TOP]=item;
    }

}
char pop()
{
    int x;
    if (TOP<0)
    {
        printf("stack is empty");
        //return;
    }
    else
    {
        x=stack[TOP];
        TOP--;
        return x;
    }

}

int ISP(char symbol)
{
	if(symbol == '^')
	{
		return(5);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(4);
	}
	else if(symbol == '+' || symbol == '-')        
	{
		return(2);
	}
	else
	{
		return(0);
	}
}
int ICP(char symbol)
{
	if(symbol == '^')
	{
		return(6);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(3);
	}
	else if(symbol == '+' || symbol == '-')        
	{
		return(1);
	}
	else if(symbol=='(')
	{
		return(9);
	}
	else
	{
	    return(0);
	}
}


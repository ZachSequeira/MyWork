#include <stdio.h>
 
void main()
{
    int a=0, b=1, c=0, n, i;
    printf("Enter the number till which you want to calculate Fibonacci numbers:\n");
    scanf("%d", &n);
   
    for(i=1; i<=n; i++)
    {
    	printf("%d\n", c);
    	a=b;
    	b=c;
    	c=a+b;
    }
}//END


















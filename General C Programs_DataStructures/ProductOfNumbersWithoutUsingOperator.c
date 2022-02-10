#include <stdio.h>
void main()
{
    int n, fact=1, i, j, num;
    printf("Enter number n:\n");
    scanf("%d", &n);
    
    for(i=1;i<n;i++)
    {
        num=fact;
        for(j=1;j<=i;j++)
        {
            fact=fact+num;
        }
    }
    printf("Factorial of %d is %d", n, fact);
}

















#include<stdio.h>
#define max 20
void main()
{
    int m1[max][max],m2[max][max],r1,c1,r2,c2,i,j,k,m3[max][max];
    printf("Enter order of first matrix\n");
    scanf("%d %d",&r1,&c1);
    printf("Enter order of second matrix\n");
    scanf("%d %d",&r2,&c2);
    printf("Enter the elements of first matrix\n");
    for(i=0;i<r1;i++)
    for(j=0;j<c1;j++)
    scanf("%d",&m1[i][j]);
    printf("Enter the elements of second matrix\n");
    for(i=0;i<r2;i++)
    for(j=0;j<c2;j++)
    scanf("%d",&m2[i][j]);
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        { 
            m3[i][j]=0;
            for(k=0;k<c2;k++)
            {
                m3[i][j]=m3[i][j]+m1[i][k]*m2[k][j];
            }
        }
    }
    printf("Resultant matrix is\n");
    for(i=0;i<r1;i++)
    {
    for(j=0;j<c2;j++)
    {
    printf("%d\t",m3[i][j]);
    }
    printf("\n");
    }
}
















#include<stdio.h>

void Insertion_Sort(int[], int);
void main()
{
 int n,i;
 printf("Enter the array size:\n");
 scanf("%d",&n);
 int arrA[n];
 printf("Enter array elements:\n");
 for(i=0;i<n;i++)
 {
    scanf("%d",&arrA[i]);
 }
Insertion_Sort(arrA, n);
}

void Insertion_Sort(int arrA[], int n)
{
    int arrB[n];
    int i,j,key,p, flg;
    arrB[0]=arrA[0];
    
    for(j=1;j<n;j++)
    {
     flg=0;
     key = arrA[j];
     i=j-1;
     
     while(flg!=1)
     {
        if(key<arrB[i])
        {
            i=i-1;
            if(i<0)
            flg=1;
        }
        else
        {
            flg=1;
        }
     }
     p=j;
     
     while(p>i+1)
     {
         arrB[p]=arrB[p-1];
         p=p-1;
     }
     arrB[i+1]=key;
 }
 printf("Sorted list is:\n");
 for(i=0;i<n;i++)
 printf("%d ",arrB[i]);
 
}








void swap(int *x,int *y)
{
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}
void main()
{
    int x,y;
    x=20;
    y=30;
    printf("\nvalues before swapingx=%d\ty=%d",x,y);
    swap(&x,&y);
    printf("\nvalues after swapingx=%d\ty=%d",x,y);
}















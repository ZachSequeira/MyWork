#include <stdio.h>
#include <math.h>
void main()
{
    int nd, i, choice, deci, bin, rem, tempd;
    long int nb, tempb;
    printf("Enter 1 to convert Binary to Decimal.\nEnter 2 to convert Decimal to Binary.\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        printf("Enter Binary Number:\n");
        scanf("%ld", &nb);
        tempb = nb;
    }
    else if(choice == 2)
    {
        printf("Enter Decimal Number:\n");
        scanf("%d", &nd);
        tempd = nd;
    }
    
    switch(choice)
    {
        case 1 : 
        deci=0;
        i=0;
        while(nb!=0)
        {
            rem=nb%10;
            nb/=10;
            deci+=rem * pow(2,i);
            i++;
        }
        printf("%ld in decimal is: %d\n", tempb, deci);
        break;
        
        case 2 :
        bin=0;
        i=1;
        while(nd!=0)
        {
            rem=nd%2;
            nd/=2;
            bin+=rem*i;
            i*=10;
        }
        printf("%d in Binary is: %ld\n", tempd, bin);
        break;
        
        default:
        printf("Wrong Input");
        break;
    }
}











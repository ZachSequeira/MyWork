#include <stdio.h>
struct contact
{
    long int phone;
    char email[30];
};
struct person
{
    int pAmt;
    int t;
    char name[20];
    struct contact c1;
};

void CalcInterest(struct person[], int);
void display(float s[], float a[], float r[], struct person p[], int);
void main()
{
    int i;
    int n;
    printf("Enter number of persons:\n");
    scanf("%d", &n);
   
    struct person p[n];
    
    for(i=0;i<n;i++)
    {
        printf("Enter details of Person %d :\n", i+1);
        printf("Enter Name:");
        scanf("%s", p[i].name);
        printf("Enter email:");
        scanf("%s", p[i].c1.email);
        printf("Enter phone:");
        scanf("%ld", &p[i].c1.phone);
        printf("Enter Principal Amount:");
        scanf("%d", &p[i].pAmt);
        printf("Enter Time Period in Months:");
        scanf("%d", &p[i].t);
    }
    CalcInterest(p, n);
}
void CalcInterest(struct person p[20], int n)
{
    int i;
    float r[n];
    float SimpInt[n];
    float TotalAmt[n];
    
    for(i=0;i<n;i++)
    {
    
        if(p[i].t<=2)
        {
            r[i]=0.08;
        }
        else if(p[i].t>2 && p[i].t<=4)
        {
            r[i]=0.06;
        }
        else if(p[i].t>4 && p[i].t<=6)
        {
            r[i]=0.04;
        }
        else if(p[i].t>6)
        {
            r[i]=0.02;
        }
    
        SimpInt[i]=(p[i].pAmt * r[i] * p[i].t)/100;
        TotalAmt[i]=SimpInt[i]+p[i].pAmt;
        
        
    }
    display(SimpInt, TotalAmt, r, p, n);
}

void display(float s[20], float a[20], float r[20], struct person p[20], int n)
{
    printf("Name\t\tEmail\t\tPhone\t\tPrincipal\t\tTime\t\tRate\t\tS.I\t\tTotal\n");
    for(int i=0; i<n;i++)
    {
        printf("%s\t\t%s\t\t%ld\t\t%d\t%d\t\t%f\t\t%f\t\t%f\n", p[i].name, p[i].c1.email, p[i].c1.phone,p[i].pAmt, p[i].t, r[i], s[i], a[i]);
    }
}












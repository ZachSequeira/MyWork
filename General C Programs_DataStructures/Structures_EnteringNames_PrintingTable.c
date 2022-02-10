#include<stdio.h>

struct contact
{
    long phone;
    char email[50];
};

struct address
{
    char country[20];
    char state
};
struct person
{
 int age;
 char name[20];
};
void display(struct person p1, struct person p2);
void main()
{
struct person p1, p2;
printf("Enter person 1 Age\n");
scanf("%d",&p1.age);
printf("Enter person 1 Name\n");
scanf("%s", p1.name);

printf("Enter person 2 Age\n");
scanf("%d",&p2.age);
printf("Enter person 2 Name\n");
scanf("%s", p2.name);
display(p1,p2);
}
void display(struct person p1, struct person p2)
{
printf("The persons details are:\n");
printf("Age\tName\n");
printf("\n%d\t%s",p1.age,p1.name);
printf("\n%d\t%s",p2.age,p2.name);
}











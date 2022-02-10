#include <stdio.h>
#include <stdlib.h>
struct gettime
{
    int hours, min, sec;
} t[3];
void Calculate(struct gettime t[3]);
void main()
{
    int i;
    
    for(int i=0;i<2;i++)
    {
        printf("Enter Hours of Time %d (0-24):\n", i+1);
        scanf("%d", &t[i].hours);
        
        Label_Minutes: 
        {
        printf("Enter Minutes of Time %d (0-60):\n", i+1);
        scanf("%d", &t[i].min);
        if(t[i].min>60)
        {
            printf("Minutes are out of bounds.\n");
            goto Label_Minutes;
        }
        }
        
        Label_Seconds:
        {
        printf("Enter Seconds of Time %d (0-60):\n", i+1);
        scanf("%d", &t[i].sec);
        if(t[i].sec>60)
        {
            printf("Seconds are out of bounds.\n");
            goto Label_Seconds;
        }
        }
    }
    Calculate(t);
}    
    
void  Calculate(struct gettime t[3])
{
   int tempsec, tempmin;
   t[2].hours = t[0].hours+t[1].hours;
   t[2].min = t[0].min+t[1].min;
   t[2].sec = t[0].sec+t[1].sec;
   
   printf("Added Time is:\n");
   printf("h- %d, m- %d, s- %d\n", t[2].hours, t[2].min, t[2].sec);
   
   if(t[2].sec>=60 && t[2].sec<120)
   {
       tempsec=(t[2].sec) - 60;
       t[2].sec=tempsec;
       t[2].min+=1;
   }
    else if(t[2].sec>=120)
   {
       tempsec=(t[2].sec) - 120;
       t[2].sec=tempsec;
       t[2].min+=2;
   }
   if(t[2].min>=60 && t[2].min<120)
   {
       tempmin=(t[2].min) - 60;
       t[2].min=tempmin;
       t[2].hours+=1;
   }
   else if(t[2].min>=120)
    {
       tempmin=(t[2].min) - 120;
       t[2].min=tempmin;
       t[2].hours+=2;
    }
   printf("Formatted Time is:\n");
   printf("h- %d, m- %d, s- %d\n", t[2].hours, t[2].min, t[2].sec);
   
}

Traversing Arrays(Data Structures)
#include <stdio.h>

void main()
{
   int i, key, n, flag=0;
   printf("Enter number of elements:\n");
   scanf("%d", &n);
   int arr[n];
   
   for(i=0; i<n; i++)
   {
       printf("enter element %d\n", i+1);
       scanf("%d", &arr[i]);
   }
   printf("Enter Key Element to be found:\n");
   scanf("%d", &key);
   
   for(i=0; i<n;i++)
   {
       if(arr[i]==key)
       {
           printf("Key is found at Index %d\n", i);
           flag = 1;
           break;
       }
    
   }
   if(flag==0)
   {
       printf("Key element not present in the array.\n");
   }
}











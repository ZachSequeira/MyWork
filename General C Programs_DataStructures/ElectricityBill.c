/*Program to Calculate electricity bill depending on number of units consumed*/
#include <stdio.h> 
void main() 
{ 
int units;  
float bill, unitsG000, unitsG200, unitsG400, unitsG600; 
printf("Enter Electricity Units consumed:\n"); 
scanf("%d", &units); 
  
if(units>=0 && units<=200)//If Else If Ladder 
{ 
 unitsG000 = 0.5 * units; 
 bill = unitsG000; 
 printf("Your rate is:\n0.5 for 0-200 units = %f.\n", unitsG000); 
 printf("Your Total bill is = %f", bill); 
} 
else if(units>=201 && units<=400) 
 { 
 	unitsG000 = 0.5 * 200; 
 	unitsG200 = 0.65 * (units-200); 
 	bill = (unitsG200) + (unitsG000); 
printf("Your rate is:\n0.5 for 0-200 units = %f.\n0.65 for 201-400 units = %f.\n", unitsG000,  unitsG200); 
 	printf("Your Total bill is = %f", bill);
 } 
 else if(units>=401 && units<=600) 
 { 
 	unitsG000 = 0.5 * 200; 
 	unitsG200 = 0.65 * 200; 
 	unitsG400 = 0.80 * (units-400); 
 	bill = (unitsG400) + (unitsG200) + (unitsG000); 
printf("Your rate is:\n0.5 for 0-200 units = %f.\n0.65 for 201-400 units = %f.\n0.80 for 401-600  units = %f.\n", unitsG000, unitsG200, unitsG400); 
 	printf("Your Total bill is = %f", bill); 
 } 
 else if(units>=601) 
 { 
 	unitsG000 = 0.5 * 200; 
 	unitsG200 = 0.65 * 200; 
 	unitsG400 = 0.80 * 200; 
 	unitsG600 = 1.00 * (units-600); 
 	bill = (unitsG600) + (unitsG400) + (unitsG200) + (unitsG000); 
printf("Your rate is:\n0.5 for 0-200 units = %f.\n0.65 for 201-400 units = %f.\n0.80 for 401-600  units = %f.\n 1.00 for 601+ units = %f.\n", unitsG000, unitsG200, unitsG400, unitsG600); 
 	printf("Your Total bill is = %f", bill); 
 } 
}//END 



















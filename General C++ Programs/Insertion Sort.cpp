#include<iostream>
using namespace std;

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
 	cout<<"Sorted list is:"<<endl;
 	for(i=0;i<n;i++)
 	{
 		cout<<arrB[i]<<endl;
	}
 	
}

int main()
{
 	int n,i;
 	cout<<"Enter the array size:"<<endl;
 	cin>>n;
 	int arrA[n];
 	cout<<"Enter array elements:"<<endl;
 	
	 for(i=0;i<n;i++)
 	{
    	cin>>arrA[i];
 	}
 	
	Insertion_Sort(arrA, n);
 
 	return 0;
}


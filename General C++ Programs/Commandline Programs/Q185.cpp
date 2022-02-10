/******************************************************************************
185. Take one string from command line and check whether it is palindrome or not
*******************************************************************************/
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char* argv[])
{
	int i;
	int len = strlen(argv[1]);
	string word = argv[1];
	int flag=0;
	
	for(i=0; i < len ;i++)
	{
		if(word[i]!=word[len-i-1])
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		cout<<word<<" is not a palindrome string."<<endl;	
	}
	else
	{
		cout<<word<<" is a palindrome string."<<endl;
	}
	return 0;
}

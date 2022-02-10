/******************************************************************************
121. Declare 3 variables with same name but different data types and different 
values in the same scope. Check what error message it gave. Then make use of 
namespace to remove that error. 
*******************************************************************************/
#include <iostream>
#include "Values.h"
using namespace std;

int main()
{
  cout<<Integer::a<<endl;
  cout<<Float::a<<endl;
  cout<<Character::a<<endl;
   
  return 0;
}

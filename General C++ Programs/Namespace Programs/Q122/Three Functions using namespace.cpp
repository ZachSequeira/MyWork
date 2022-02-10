/******************************************************************************
122.Write three functions with same signature in three different namespaces and 
call all that functions in main.
*******************************************************************************/
#include <iostream>
#include "Functions.h"
using namespace std;
int main()
{
    Func1::display();
    Func2::display();
    Func3::display();

    return 0;
}

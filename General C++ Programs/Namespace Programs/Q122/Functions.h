/******************************************************************************
122.Write three functions with same signature in three different namespaces and 
call all that functions in main.
*******************************************************************************/
using namespace std;

namespace Func1
{
    void display()
    {
        cout<<"This is Function 1"<<endl;
    }
}
namespace Func2
{
    void display()
    {
        cout<<"This is Function 2"<<endl;
    }
}
namespace Func3
{
    void display()
    {
        cout<<"This is Function 3"<<endl;
    }
}

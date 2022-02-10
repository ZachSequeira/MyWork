/******************************************************************************
121. Declare 3 variables with same name but different data types and different 
values in the same scope. Check what error message it gave. Then make use of 
namespace to remove that error. 
*******************************************************************************/
using namespace std;

namespace Integer
{
  int a =4;  
}

namespace Float
{
    float a=5.2f;
}

namespace Character
{
    char a = 'c';
}

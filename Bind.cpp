#include <iostream>
#include <functional> // for bind and function

using namespace std;
using namespace placeholders;
////////////////////////////////////////////////////////////////////////////
class Ttest
{
public:
int add(int a, int b , int c)
{
    cout <<"a: " << a << ",b: " << b << ",c: " << c <<endl;
    return (a + b + c);
}
};
/////////////////////////////////////////////////////////////////////////////
int run(function<int(int,int,int)> func)
{
    return func(7,17,77);

}
//***************************************************************************
int main()
{

   Ttest test;
   auto calc = bind(Ttest::add,test,_1,_2,_3);
   cout << run(calc) << endl;


}

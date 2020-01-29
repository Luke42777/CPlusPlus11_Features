#include <iostream>

using namespace std;
///////////////////////////////////////////////////////////////
class Ttest
{


};
//////////////////////////////////////////////////////////
void check(Ttest&)
{
    cout << "lvalue" << endl;
}
//*******************************************************
void check(Ttest&&)
{
    cout << "rvalue" << endl;
}
//*******************************************************
template <typename T>
void call(T &&arg)
{
/* in here arg changed his type to lvalue reference*/
    //check(static_cast<T>(arg)); // but we can call it as rvalue reference using function forward or static_cast
    check(forward<T>(arg)); // for is better because intends what we are doing here
}

int main()
{   Ttest &&rTest1 = Ttest();// rvalue reference must be used straight away
    check(forward<Ttest&&>(rTest1)); // here is to late rvalue is now lvalue, beacuse there is no point to keep address of object is not exist
                                     // so we need to use forward

    check(Ttest()); // here that's rvalue

    Ttest test1;
    auto &&rTest2{test1}; // reference to rvalue has been collapsed to lvalue
    check(rTest2); // prove rTest2 is now lvalue


   ///-/////////////////////////////perfect forwarding////////////////////////////////////////////////////////
   cout << endl << endl;
   call(Ttest{});

return 0;
}

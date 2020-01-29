#include <iostream>
#include <typeinfo> //we need to use this header in order to use typeid
using namespace std;

//C++14 allows us to define function using auto this way
/*
auto fun()
{
    cout << "Hello C++14";
    return 0;
}
*/
//************************************************
//C++11 doesn't so you need to do it that way
template <typename T, typename S>
auto fun1(T var1,S var2)->decltype(var1 + var2)
{
    return (var1 + var2);
}
//**********************************************
int test()
{
    return 7;
}
//*********************************************
auto fun2()->decltype(test())
{
    return test();
}

int main()
{
    string sth;
    cout << typeid(sth).name() << endl; //typeid(sth) is returning the type info about "sth" variable,
                            //we need name

    decltype(sth) name = "Greed";
    cout << name << endl;


    auto var = "Scrudge"; // const char*
    cout << typeid(var).name();
    cout << endl;

    cout << typeid(fun1(20.7f,3.14)).name();
    cout << endl;
    cout << typeid(fun2()).name();
    return 0;
}


//to remove optimization this flag needs to be set (for gcc):  -fno-elide-constructors     in compiler settings
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////
class Ttest
{
static const int Size = 100;
int * _buffer{};
public:
    Ttest()
    {
        cout << "constructor\n";
        _buffer = new int[Size]{};// all elements contain 0
    }
    //***************************
   Ttest(int i)
    {
        cout << "parameterized constructor\n";
        _buffer = new int[Size]{};// all elements contain 0

        for(int i = 0; i < Size;i++)
        {
             *(_buffer + i) = 7 * i;
        }
    }
    //***************************
    Ttest(const Ttest& other)
    {
       cout << "copy constructor\n";

     _buffer = new int[Size]{};
     memcpy(_buffer,other._buffer,Size * sizeof(int));

    }
    //******************************
    Ttest& operator=(const Ttest& other)
    {
        if(this != &other)
        {
            cout << "Assign operator\n";
            _buffer = new int[Size]{};
            memcpy(_buffer,other._buffer,Size * sizeof(int));
        }
        return *this;
    }
    //**********************************
    ~Ttest()
    {
        cout << "Destructor\n";
        delete[] _buffer;
    }
    //***********************************
    friend ostream&  operator<<(ostream &obj, const Ttest& test);



};
////////////////////////////////////////////////////////////////////////////////////////
ostream&  operator<<(ostream& obj, const Ttest& test)
{
    obj << "Hello from test\n";
    return obj;
}
//**************************************************************************************
Ttest getTtest()
{
    return Ttest();
}
//**********************************************************************************

int main()
{

Ttest test1 = getTtest();// C++11 standards RVO(Copy Ellison) so unnecessary constructors are elided
Ttest test2{Ttest()};    // It doesn't always happen, there are some situations where copy elision is
                         //not going to happen for example: if we throw exception  in fun getTtest()
Ttest &rTest1  = test1;
Ttest &&rTest2 = getTtest();

return 0;
}




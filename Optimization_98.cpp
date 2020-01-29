//to remove optimization this flag needs to be set: -fno-elide-constructors in compiler settings
#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////
class Ttest
{
public:
    Ttest()
    {
        cout << "constructor\n";
    }
    //***************************
   Ttest(int i)
    {
        cout << "parameterized constructor\n";
    }
    //***************************
    Ttest(const Ttest& other)
    {
       cout << "copy constructor\n";

    }
    //******************************
    Ttest& operator=(const Ttest& other)
    {
        cout << "Assign operator\n";
        return *this;
    }
    //**********************************
    ~Ttest()
    {
        cout << "Destructor\n";
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

int main()
{

Ttest test1 = getTtest();
cout << test1 << endl;

vector<Ttest> tests;
tests.push_back(test1);

}



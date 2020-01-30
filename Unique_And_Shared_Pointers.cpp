#include <iostream>
#include <memory>

using namespace std;
////////////////////////////////////////////////////////
class Ttest
{

public:
    Ttest()
    {
        cout << "constructor" << endl;
    }
    ~Ttest()
    {
        cout << "destructor" << endl;
    }
};
//////////////////////////////////////////////////////////
class Ttemp
{
 unique_ptr<Ttest[]> _UptrTest;
 Ttest *_ptr;
public:
    Ttemp(): _UptrTest(new Ttest[2]) // constructor of unique_ptr class needs to be called here
    {
        _ptr = new Ttest[2];
    }
    ~Ttemp()
    {
        delete [] _ptr;
        cout << "Ttemp destructor" << endl;
    }

};
using namespace std;
//*********************************************************
int main()
{
 {
    //unique_ptr<Ttest[]> UptrTest(new Ttest [3]); // where UptrTest goes out of scope  pointer variable does no longer exist,
                                           // but unique pointer runs destructor  which means deallocate memory
                                           //before c++11 it's been used often auto_ptr instead unique_ptr

    // Ttest *pTest = new Ttest;             // in this case ("normal" pointer) destructor will not start
    Ttemp temp;
 }

cout << "Program finished" << endl;

}

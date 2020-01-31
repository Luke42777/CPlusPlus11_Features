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
public:
    Ttemp(): _UptrTest(new Ttest[2]) // constructor of unique_ptr class needs to be called here
    {

    }
    ~Ttemp()
    {

        cout << "Ttemp destructor" << endl;
    }

};
using namespace std;
//*********************************************************
int main()
{
 {
    Ttemp temp; //unique pointer will call Ttest destructor and memory allocated will be destroyed
                // "normal" pointer(not unique) would have command: delete [] Ttest;  in  destructor
 }

cout << "\nShared pointers\n" << endl;
///shared pointers are similar to unique pointers
/// the only difference is they do NOT delete memory associated to their object
///until all pointers that point at that object have gone out of scope
///you cannot (in c++11,c++14) point at array
shared_ptr<Ttest> pTest1(nullptr);

    {
    cout << "Beginning of scope\n";
    shared_ptr<Ttest> pTest2(new Ttest); // or shared_ptr<Ttest> pTest2 = make_shared<Ttest>();
    pTest1  =  pTest2;
    cout << "End of scope\n";
    }

cout << "\nProgram finished\n";


}

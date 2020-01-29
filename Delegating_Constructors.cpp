#include <iostream>
using namespace std;

class Tparent
{
    int dogs{5};
    string text;

public:
   Tparent(): Tparent("HELLO")//default constructor delegates string parameter constructor
        {
           cout << "No parameter Tparent constructor on duty\n";

        }
    //*********************
    Tparent(string s)
        {
            text = s;
            cout << "String Tparent constructor on duty\n";
        }
};
//////////////////////////////////////////////////////////////////////////
class Tchild: public Tparent
{
public:
    Tchild() = default;

};
/////////////////////////////////////////////////////////////////////////////
int main()
{
    Tchild child;
}

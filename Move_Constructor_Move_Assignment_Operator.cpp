
//to remove optimization this flag needs to be set (for gcc):  -fno-elide-constructors     in compiler settings
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////
class Ttest
{
static const int Size = 100;
int *_buffer{nullptr};
public:
    Ttest()
    {
        _buffer = new int[Size]{};// all elements contain 0
        cout << "\nconstructor\n";
    }
    //***************************
   Ttest(int i)
    {
        _buffer = new int[Size]{};// all elements contain 0

        for(int i = 0; i < Size;i++)
        {
             *(_buffer + i) = 7 * i;
        }
    }
    //***********************************************************
    Ttest(const Ttest& other) //copy constructor
    {

     _buffer = new int[Size]{};
     memcpy(_buffer,other._buffer,Size * sizeof(int));

    }
    //************************************************************
     Ttest& operator=(const Ttest& other) //assignment operator
    {
        if(this != &other)
        {
            delete [] _buffer;
            _buffer = new int[Size]{};
            memcpy(_buffer,other._buffer,Size * sizeof(int));
        }
        return *this;
    }
    ///******************************moving constructor*****************************************************************
     Ttest(Ttest &&other)
    {

     this->_buffer = other._buffer;// no need to be another memory allocated we just bind this _buffer to other _buffer
                                   //object other is going to be destroyed anyway so we can "nick" his array of int
     other._buffer = {nullptr};//that's very important otherwise destructor of temporary object would destroy our array
                               //other._buffer still knows address of an array allocated using operator new
        cout << "Moving constructor on duty";
    }
   //********************************************************************************************************************
    Ttest& operator=(Ttest &&other)
    {
    if(this != &other)
    {
      delete [] this->_buffer;
      this->_buffer = other._buffer;// no need to be another memory allocated we just bind this _buffer to other _buffer
                                   //object other is going to be destroyed anyway so we can "nick" his array of int
      other._buffer = {nullptr};//that's very important otherwise destructor of temporary object would destroy our array
                               //other._buffer still knows address of an array allocated using operator new
     cout << "Moving assignment operator on duty";
    }
     return *this;
    }
     ///******************************************************************************************************************
    ~Ttest()
    {
        if(! _buffer)
            {
                    return;
            }
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

Ttest &&rTest = getTtest(); //in this when gcc compiler flag (copy elision) moving constructor is not going to work
                            // moving constructor is elided, regular constructor is used

vector<Ttest> vec;
vec.push_back(Ttest{100}); // vector uses moving constructor we created:)

rTest = getTtest();

return 0;
}




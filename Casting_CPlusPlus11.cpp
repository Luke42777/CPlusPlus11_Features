#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
class Tparent
{
    public:
   virtual void speak()
        {
            cout << "Function speak from Tbrother class" << endl;
        }


};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tbrother: public Tparent
{
public:

};
//////////////////////////////////////////////////////////////////////////////////////////////
class Tsister: public Tparent
{

};
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

   Tparent parent;
   Tbrother brother;
   Tsister sister;

  Tparent *ppb = &brother;

                        ///dynamic_cast does do runtime checking///
  //pbb = ppb;
  Tbrother *pbb = dynamic_cast<Tbrother*>(ppb);// if there is possibly dangerous(ppb pointer is set to parent object)
                                               // dynamic_cast will set pbb pointer to nullptr

  if(pbb == nullptr)
  {
     cout << "Invalid cast";
  }
  else
  {
      pbb->speak();
  }

                        ///reinterpret_cast for very weird casting, it pretty cast anything to anything///

 Tsister * pss = dynamic_cast<Tsister*>(ppb);// because ppb is pointing at brother obj dynamic_cast will not let it go
                                                // and will set pointer to nullptr

  if(pss == nullptr)
      {
         cout << "Invalid cast" << endl;
      }
  else
      {
          pbb->speak();
      }


pss = reinterpret_cast<Tsister*>(ppb);// but if use reinterpret_cast it's ok

if(pss == nullptr)
      {
         cout << "Invalid cast" << endl;
      }
  else
      {
          pbb->speak();
      }

 return 0;
}

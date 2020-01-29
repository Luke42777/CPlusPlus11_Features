#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;
class Test{
    int a,b,c,d,e;
    public:
  Test(initializer_list<int> numbers){
      for(auto ele: numbers){
        cout << ele << endl;
      }
  }
};

void print(initializer_list<string> texts){
   for(auto ele: texts){
        cout << ele << endl;
      }
}



int main()
{
vector<int> v{0,1,2,3,4,};
for(auto ele: v){
    cout << ele <<endl;
}
cout << endl;

Test{0,1,2,3,4,5,6};
cout << endl;

print({"one","two","three"});






}

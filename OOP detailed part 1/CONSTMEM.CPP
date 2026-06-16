#include<iostream>
using namespace std;
class demo{
public:
const int a;

demo(int b):a(b) 
{  
   cout<<"THE VALUE OF A IS:"<<a<<endl;
}

};
int main()

{      int a=20;
       demo d1(a);
       cout<<"the value of member is "<<d1.a<<endl;
       
        
      return 0;

}
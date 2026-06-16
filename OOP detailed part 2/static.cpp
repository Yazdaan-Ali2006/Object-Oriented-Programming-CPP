#include<iostream>
using namespace std;
class myclass{
  
    int number;
    public:
      static int count;
    myclass(){

    }
    myclass(int n){
      number=n;
      count++;
      cout<<"CONSTRUCTOR CALLED"<<endl;
    }
    display(){
        cout<<"NUMBER :"<<number<<endl;
        cout<<"COUNTER :"<<count<<endl;
    }

};
int myclass::count=0;
int main()
{
    myclass a1(10);
    a1.display();
    myclass a2(11);
    a2.display();
    myclass a3(12);
    a3.display();
    return 0;
}
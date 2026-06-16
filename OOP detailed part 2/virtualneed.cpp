#include<iostream>
using namespace std;
class base{
    public:
    virtual void print(){
        cout<<"HI I AM BASE CLASS"<<endl;
    }
};
class derived:public base{
  public:
    void print(){
        cout<<"HI I AM DERIVED CLASS"<<endl;
    }
};
int main()
{   
   base *ptr;
   derived obj;
   ptr=&obj;
   ptr->print();
     
    return 0;
}
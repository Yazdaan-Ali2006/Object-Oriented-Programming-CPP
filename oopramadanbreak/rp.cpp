#include<iostream>
using namespace std;
class base{
    public:
    void show(){
        cout<<"i am base"<<endl
    }
};
class derived:public base{
 public:
    void show(){
    cout<<"derived";
 }

};

int main()
{    derived obj;
    base *p=&obj;
    p->show();
    return 0;
}
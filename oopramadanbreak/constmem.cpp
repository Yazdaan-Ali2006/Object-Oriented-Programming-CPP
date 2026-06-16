#include <iostream>
using namespace std;
class info
{
    const int id;
    int age;
    string name;

public:
info(int a=0,string n="null",int i=0):id(i),age(a), name(n){

}
/*void setid(int i){
    id=i; ..ERROR..THIS FUNCTION IS TRYING TO CHANGE IT THAT'S WHY IT IS SHOWING ERROR
}*/
void display()const{ //const make it read-only
    cout<<"ID:"<<id<<endl;
    cout<<"AGE:"<<age<<endl;
    cout<<"NAME:"<<name<<endl;
    //id++;error

}
};

int main()
{
    info a(1,"ali",12);
    a.display();
    return 0;
}
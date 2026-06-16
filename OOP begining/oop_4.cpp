#include <iostream>
using namespace std;
class employee
{
public:
    int age;
    string name;
    int salary;
    //default constructor
    employee(){

    }
    //my own constructor
    employee(string name,int age,int salary){
        this->name=name;
        this->age=age;
        this->salary=salary;

    }

};
int main()
{ 
    employee *ptr=new employee("Yazdaan Ali",19,100000);
    cout<<
    return 0; 
}
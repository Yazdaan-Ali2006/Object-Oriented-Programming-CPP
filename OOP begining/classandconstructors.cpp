
#include <iostream>
using namespace std;

class Employee
{
public: //modifier public/protected/private
    string name;
    string company;
    int age;
    void input()
    {

        cout << "NAME -  " << name << endl;
        cout << "COMPANY -  " << company << endl;
        cout << "AGE -  " << age << endl;
    }
    Employee(string Name, string Company, int Age) // constructor-set values to the object (doest not return anything)
    {
        name = Name;
        company = Company;
        age = Age;
    }
};
int main()
{
    Employee employee1 = Employee("yazdaan", "rolls royce", 19);
    employee1.input();

    cout << endl;
    Employee employee2 = Employee("ali", "aws", 20);
    employee2.input();
    return 0;
}
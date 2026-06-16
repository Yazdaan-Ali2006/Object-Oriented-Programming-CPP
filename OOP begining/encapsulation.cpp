// encap....=binding a data,access to data within class as per MY way ,hidden data
#include <iostream>
using namespace std;

class Employee
{
private:// modifier (public/protected/private)

// in order to access this private class I have to use encapsulation method...

    string name;
    string company;
    int age;

public:
    void setname(string Name)
    { // setter
        name = Name;
    }
    string getname()
    { // getter
        return name;
    }
    void setage(int Age)
    { // setter
        if(Age>=18)
        age = Age;
    }
    int getage()
    { // getter
        return age;
    }

    void setcompany(string Company)
    { // setter
        company = Company;
    }
    string getcompany()
    { // getter
        return company;
    }
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
    //constructor is a member function it can access everything within the class

};
int main()
{
    Employee employee1 = Employee("yazdaan", "rolls royce", 19);
    employee1.input();

    cout << endl;
    Employee employee2 = Employee("ali", "aws", 20);
    employee2.input();
    //main doesnot have access too private members but constructors do 

    //using getters and setters
    cout<<endl;
    employee1.setage(10);
    cout<<employee1.getname()<<" is "<<employee1.getage()<<" year old working at "<<employee1.getcompany()<<endl;
    return 0;
}

#include <iostream>
/*
Task # 04:
You are developing a user profile registration
system for a healthcare app. You need to
validate multiple fields separately,
and handle errors differently for each field. Use multiple
catch blocks to catch each specific exception:



Validate age (> 0 and < 120)
Validate salary (> 0)
Validate height (> 0 cm)
Throw specific exceptions:



InvalidSalaryException
InvalidHeightException
*/
using namespace std;
class InvalidAgeException
{
private:
    string str;

public:
    InvalidAgeException(string msg)
    {
        str = msg;
    }
    string get_InvalidAgeException(){
        return str;

    }

};
class URS : public InvalidAgeException
{ // URS=User Registration System
private:
    int age;
    int salary;
    int height;

public:
    URS()
    {
        age = 20;
        salary = 50000;
        height = 500;
    }
    void setage(int a)
    {
        age = a;
    }
    void setsalary(int s)
    {
        salary = s;
    }
    void setheight(int h)
    {
        height = h;
    }
};
int main()
{
    URS obj1;
    int age;
    int height;
    int salary;
    try
    {
        cout << "ENTER YOUR AGE" << endl;
        cin >> age;
        cout << "ENTER YOUR HEIGHT" << endl;
        cin >> height;
        cout << "ENTER YOUR SALARY" << endl;
        cin >> salary;
        if (age > 0 && age < 120)
        {
            obj1.setage(age);
        }
        else
        {
            throw(InvalidAgeException("invalid"));
        }
        if (salary > 0)
        {
            obj1.setsalary(salary);
        }
        else
        {
            throw("InvalidSalaryException");
        }
        if (height > 0)
        {
            obj1.setage(age);
        }
        else
        {
            throw("InvalidSalaryException");
        }
    }
    catch(const InvalidAgeException msg){
        cout<<msg.get_InvalidAgeException();
    }

        return 0;
}
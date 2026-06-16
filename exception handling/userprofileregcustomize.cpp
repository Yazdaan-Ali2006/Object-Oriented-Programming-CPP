#include <iostream>
using namespace std;
class InvalidAgeException
{
public:
    string msg;
    InvalidAgeException(string msg)
    {
        this->msg = msg;
    }
};
class InvalidHeightException
{
public:
    string msg;
    InvalidHeightException(string msg)
    {
        this->msg = msg;
    }
};
class InvalidSalaryException
{
public:
    string msg;
    InvalidSalaryException(string msg)
    {
        this->msg = msg;
    }
};

class URS
{ // URS=User Registration System
private:
    int age;
    int salary;
    int height;

public:
    URS()
    {
        age = 0;
        salary = 0;
        height = 0;
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
    try  //try block for age
     {
        cout << "ENTER YOUR AGE:";
        cin >> age;
        if (age > 0 && age < 120)
        {
            obj1.setage(age);
        }
        else
        {
            throw InvalidAgeException("InvalidAgeException caught: Age must be between 1 and 119");
        }
    }
    catch (InvalidAgeException &m)
    {
        cout << m.msg << endl;
    }
    try //try block for salary 
    {
        cout << "ENTER YOUR SALARY:";
        cin >> salary;

        if (salary > 0)
        {
            obj1.setsalary(salary);
        }

        else
        {
            throw InvalidSalaryException("InvalidSalaryException caught: Salary must be positive");
        }
    }
    catch (InvalidSalaryException &m)
    {
        cout << m.msg << endl;
    }

    try  //try block for height
    {
    cout << "ENTER YOUR HEIGHT(cm):";
        cin >> height;
        if (height > 0)
        {
            obj1.setage(age);
        }
        else
        {
            throw InvalidHeightException("InvalidHeightException caught: Height must be positive ");
        }
    }

    catch (InvalidHeightException &m)
    {
        cout << m.msg << endl;
    }

}
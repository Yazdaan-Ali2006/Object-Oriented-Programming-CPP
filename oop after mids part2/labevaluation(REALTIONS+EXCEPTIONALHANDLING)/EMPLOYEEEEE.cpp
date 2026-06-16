#include <iostream>
#include <cstring>
using namespace std;
class Date
{
private:
    int Day;
    int Month;
    int Year;

public:
    Date()
    {
        Day = 0;
        Year = 0;
        Month = 0;
    }
    Date(int d, int m, int y)
    {
        Day = d;
        Month = m;
        Year = y;
    }
    void displaydate()
    {
        cout << getDay() << "/" << getMonth() << "/" << getYear() << endl;
    }
    void inputdate()
    {
        do
        {
            cout << "ENTER DAY" << endl;
            cin >> Day;
        } while (Day <= 0 || Day > 7);
        do
        {
            cout << "ENTER MONTH" << endl;
            cin >> Month;
        } while (Month <= 0 || Month > 12);
        do
        {
            cout << "ENTER YEAR" << endl;

            cin >> Year;
        } while (Year <= 0 || Year > 2026);
    }
    int getDay()
    {
        return Day;
    }
    int getMonth()
    {
        return Month;
    }
    int getYear()
    {
        return Year;
    }

    ~Date()
    {
        cout << "DATE TERMINATED" << endl;
    }
};
class Salary
{
private:
    float grosspay;
    float dedcution;
    float netpay;

public:
    Salary()
    {
        grosspay = 0;
        dedcution = 0;
        netpay = 0;
    }
    Salary(float gp, float dd, float np)
    {
        grosspay = gp;
        dedcution = dd;
        netpay = np;
    }
    void input()
    {
        do
        {
            cout << "ENTER GROSSPAY" << endl;
            cin >> grosspay;
        } while (grosspay < 0);
        do
        {
            cout << "ENTER DEDUCTION" << endl;
            cin >> dedcution;
        } while (dedcution < 0);
        do
        {
            cout << "ENTER NETPAY" << endl;
            cin >> netpay;
        } while (netpay < 0);
    }
    void display()
    {
        cout << "GROSS PAY:" << getgp() << endl;
        cout << "DEDUCTION:" << getdd() << endl;
        cout << "NET PAY:" << getnp() << endl;
    }
    float getgp()
    {
        return grosspay;
    }
    float getdd()
    {
        return dedcution;
    }
    float getnp()
    {
        return netpay;
    }
    ~Salary()
    {
        cout << "SALARY TERMINATED" << endl;
    }
};
class Employee
{
    int employee_number;
    char *name;
    Salary s;
    Date d;

public:
    Employee()
    {
        employee_number = 0;
        name = new char[4];
        strcpy(name, "NONE");
    }
    Employee(int empnum, const char *n, int d, int m, int y, float gp, float dd, float np) : d(d, m, y), s(gp, dd, np)
    {
        employee_number = empnum;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    void display()
    {
        cout << "EMPLOYEE DATA" << endl;
        cout << "NAME:" << name << endl;
        cout << "SALARY INFORMATION" << endl;
        s.display();
        cout << "DATE OF JOINING" << endl;
        d.displaydate();
    }
    friend ostream &operator<<(ostream &o, Employee e1)
    {
        o << "EMPLOYEE DETAILS" << endl;
        o << e1.name << endl;
        o << "SALARY DETAILS" << endl;
        e1.s.display();
        o << "JOINING DATE" << endl;
        e1.d.displaydate();
        return o;
    }

    friend istream &operator>>(istream &o, Employee &e1)
    {
        cout << "=============EMPLOYEE DETAILS==============" << endl;
        cout << "Enter Employee No: ";
        o >> e1.employee_number;
        char temp[50];
        cout << "Enter Name: ";
        o >> temp;
        e1.name = new char[strlen(temp) + 1];
        strcpy(e1.name, temp);

        cout << "SALARY DETAILS" << endl;
        e1.s.input();

        cout << "JOINING DATE" << endl;
        e1.d.inputdate();
        return o;
    }
    int getemployeenum()
    {
        return employee_number;
    }
    ~Employee()
    {
        cout << "EMPLOYEE IS NO MORE..." << endl;
    }
};
class Database
{
    Employee **employees;
    int numofemployees;
    int empcount;

public:
    Database(int n)
    {
        empcount = 0;

        if (n < 0)
        {
            cout << "ERROR:INCORRECT NUMBER" << endl;
        }
        else
        {
            numofemployees = n;
            employees = new Employee *[n];
        }
    }

    void addEmployee(Employee *e)
    {
        if (empcount < numofemployees)
        {
            employees[empcount++] = e;
        }
        else
        {
            cout << "DATABASE FULL" << endl;
        }
    }

    void removeEmployee(int empnum)
    {
        for (int i = 0; i < empcount; i++)
        {
            if (employees[i]->getemployeenum() == empnum)
            {
                delete employees[i];

                for (int j = i; j < empcount - 1; j++)
                {
                    employees[j] = employees[j + 1];
                }

                empcount--;
                cout << "Employee removed\n";
                return;
            }
        }

        cout << "ERROR: Employee not found" << endl;
    }

    void searchEmployee(int empnum)
    {
        for (int i = 0; i < empcount; i++)
        {
            if (employees[i]->getemployeenum() == empnum)
            {
                cout << "============EMPLOYEE FOUND=============" << endl;
                employees[i]->display();
                return;
            }
        }

        cout << "ERROR: Employee not found" << endl;
    }
};

int main()
{
    Employee e1;
    cin >> e1;

    cout << e1;

    Database obj(1);

    obj.addEmployee(&e1);

    obj.searchEmployee(e1.getemployeenum());

    return 0;
}
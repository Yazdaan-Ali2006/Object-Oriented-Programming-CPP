#include <iostream>
using namespace std;
class employee
{
protected:
    string name;
    int id;

public:
    virtual void input()
    {
        cout << "EMPLOYEE DETAILS" << endl;
        cout << "ENTER NAME" << endl;
        cin >> name;
        cout << "ENTER ID" << endl;
        cin >> id;
    }
    virtual float CalculateSalary() = 0;
    virtual void display()
    {
        cout << "NAME:" << name << endl;
        cout << "ID:" << id << endl;
        cout << "SALARY:" << CalculateSalary() << endl;
    }
    virtual ~employee()
    {
        cout << "EMPLOYEE DELETED" << endl;
    }
};
class contractemployee : public employee
{
protected:
    float hourlyrate;
    float hoursworked;

public:
    float CalculateSalary() override
    {
        return (hourlyrate * hoursworked);
    }
    void input() override
    {
        employee::input();
        cout << "ENTER YOUR HOURLY RATE" << endl;
        cin >> hourlyrate;
        cout << "ENTER HOURS WORKED" << endl;
        cin >> hoursworked;
    }
    void display() override
    {
        employee::display();
        cout << "HOURLY RATE:" << hourlyrate << endl;
        cout << "HOURS WORKED:" << hoursworked << endl;
    }
};
class permanentemployee : public employee
{
protected:
    float basicpay;
    float hra;

public:
    float CalculateSalary() override
    {
        return (basicpay + hra);
    }
    void input() override
    {
        employee::input();
        cout << "ENTER BASIC PAY" << endl;
        cin >> basicpay;
        cout << "ENTER HOUSE RENT ALLOWANCE" << endl;
        cin >> hra;
    }
    void display() override
    {
        employee::display();
        cout << "BASIC PAY:" << basicpay << endl;
        cout << "HOUSE RENT ALLOWANCE:" << hra << endl;
    }
};
void menu()
{
    cout << "EMPLOYEE SYSTEM" << endl;
    cout << "1)PERMANENT EMPLOYEE" << endl;
    cout << "2)CONTRACT EMPLOYEE" << endl;
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF EMPLOYEES" << endl;
    cin >> n;
    employee **arr = new employee *[n];
    int choice;
    for (int i = 0; i < n; i++)
    {
        menu();
        cout << "ENTER YOUR CHOICE" << endl;
        cin >> choice;
        if (choice == 1)
        {
            arr[i] = new permanentemployee();
        }
        else if (choice == 2)
        {
            arr[i] = new contractemployee();
        }
        else
        {
            cout << "INVALID" << endl;
            return 0;
        }
        arr[i]->input();
    }

    for (int i = 0; i < n; i++)
    {
        arr[i]->display();
    }

    for (int i = 0; i < n; i++)
    {
        delete arr[i];
    }
    delete[] arr;
    return 0;
}
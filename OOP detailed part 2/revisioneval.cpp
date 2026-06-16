#include <iostream>
using namespace std;
/*
Create a class Car with the following:

Attributes:

string owner_name → name of the car owner

string model → car model

double monthly_expense[12] → expenses for each month

float avg_expense → average monthly expense

Methods:

Default constructor → initialize everything to default values.

Parameterized constructor → initialize attributes from arguments.

Copy constructor → copy one Car object to another.

Setters and getters for all attributes.

calculateAvgExpense() → calculate average of 12 months’ expenses.

displayExpenseCategory() → categorize the car:

"Low Expense" → avg_expense ≤ 5000

"Medium Expense" → 5000 < avg_expense < 15000

"High Expense" → avg_expense ≥ 15000

display() → show all details including average expense and category.

Main program tasks:

Allow the user to enter n car objects dynamically.

Display the expense category of each car.

Find and display the car with the highest average expense.*/
class car
{
    string owner;
    string carname;
    double monthly_expense[3];
    float avg_expense;

public:
    car()
    {
        // default
        owner = "null";
        carname = "null";
        for (int i = 0; i < 3; i++)
        {
            monthly_expense[i] = 0;
        }
        avg_expense = 0;
    }
    car(string o, string c, double arr[])
    {

        owner = o;
        carname = c;
        int avg = 0;
        for (int i = 0; i < 3; i++)
        {

            monthly_expense[i] = arr[i];
            avg += monthly_expense[i];
        }
        avg_expense = avg;
    }
    car(car &c)
    {
        owner = c.owner;
        carname = c.carname;
        for (int i = 0; i < 2; i++)
        {
            monthly_expense[i] = c.monthly_expense[i];
        }
    }
    void setowner(string o)
    {
        owner = o;
    }

    string getownername()
    {
        return owner;
    }
    void setcarname(string c)
    {
        carname = c;
    }
    string getcarname()
    {
        return carname;
    }
    void setmonthlyexpense(double arr[])
    {
        for (int i = 0; i < 3; i++)
        {
            monthly_expense[i] = arr[i];
        }
    }
    double getindex(int i)
    { // FOR SPECIFIC INDEX
        if (i < 0)
        {
            return -1;
        }
        else
        {
            return monthly_expense[i];
        }
    }
    float getavg()
    {
        return avg_expense;
    }
    void setavg(double arr[])
    {
        int avg = 0;
        for (int i = 0; i < 3; i++)
        {
            monthly_expense[i] = arr[i];
            avg += monthly_expense[i];
        }
        avg_expense = avg / 3;
    }
    void check()
    {
        float a = getavg();
        if (a <= 10000)
        {
            cout << "EXPENSE:CHEAP" << endl;
        }
        else if (a > 10000 && a <= 50000)
        {
            cout << "EXPENSE:MODERATE" << endl;
        }
        else if (a > 50000)
        {
            cout << "EXPENSE:HIGH" << endl;
        }
    }
    void display()
    {
        cout << "========INFORMATION ABOUT THE CAR==========" << endl;
        cout << "OWNER NAME:" << getownername() << endl;
        cout << "CAR NAME:" << getcarname() << endl;
        cout << "==============MONTHLY EXPENSE==============" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "MONTH(" << i + 1 << "):" << monthly_expense[i] << endl;
        }
        cout << "AVERAGE :" << getavg() << endl;
        check();
    }
};
int main()
{
    car *obj = new car[3];
    double array[3];
    string carname;
        string owner;
    for (int k = 0; k < 3; k++)
    {
        cout<<"DATA FOR CAR ("<<k+1<<")"<<endl;
        cout << "ENTER THE NAME OF CAR:" << endl;
        cin >> carname;
        cout << "ENTER THE NAME OF OWNER:" << endl;
        cin >> owner;
        cout << "ENTER EXPENSE OF 3 MONTHS:" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "MONTH(" << i + 1 << "):";
            cin >> array[i];
        }
        obj[k].setowner(owner);
        obj[k].setcarname(carname);
        obj[k].setmonthlyexpense(array);
        obj[k].setavg(array);
    }
    for (int i = 0; i < 2 ; i++)
    {
        cout << "DATA---(" << i + 1<< ")" << endl;
         obj[i].display();
    }
    delete []obj;
}
#include <iostream>
using namespace std;
/*Assignment Question assign in today lecture:

A smartwatch is a wearable computer in the form of a watch; modern smartwatches provide a local touchscreen interface for daily use and calculate your health essentials. While exercising, you can
use a heart-rate monitor installed in your smartwatch to see that your heart rate stays within a safe range.
The formula for calculating your maximum heart rate in beats per minute is 220 minus your age in years.
Your target heart rate is a range that is 50–85% of your maximum heart rate.
Your task is to create a class called HeartRates.
 ∙ The class attributes should include the person’s first name, a unique ID, and date of birth (consisting of separate attributes for the month, day, and year of birth).
•The ID will be the third digit of your Roll_No. You are required to input your Roll_No and extract the third digit.
•Your class should have a constructor that receives this data as a parameter. For each attribute, provide set and get functions.
•The class has the following functions:
● a function getAge that calculates and returns the person’s age (in years),
● a function getMaxiumumHeartRate that calculates and returns the person’s maximum heart rate
● a function getTargetHeartRate that calculates and returns the person’s target heart rate.

Create an application that asks for the user's details, creates an instance of the HeartRates class, prints the user's first name and birthdate, and then computes and outputs the user's age in years, maximum heart rate, and target heart rate range.
*/
class HeartRate
{
    string name;
    int unique_id;
    int month;
    int year;
    int date;

public:
    float getmaxheartrate()
    {
        return (220 - getage());
    }
    float gettarget()
    {
        cout << "LOWER RANGE=" << 0.5 * getmaxheartrate() << endl;
        cout << "HIGHER RANGE=" << 0.85 * getmaxheartrate() << endl;
    }
    HeartRate()
    {
        name = "null";
        month, year, date, unique_id = 0;
    }
    HeartRate(string n, int id, int m, int y, int d)
    {
        name = n;
        unique_id = id % 10;
        month = m;
        year = y;
        date = d;
    }
    void setid(int rollno)
    {
        unique_id = rollno % 10;
    }
    int getid()
    {
        return unique_id;
    }
    string getname()
    {
        return name;
    }
    int getage()
    {
        if (year < 2026)
        {
            return 2026 - year;
        }
        else
        {
            return -1;
        }
    }
    display()
    {
        cout << "Name: " << getname() << endl;
        cout << "ID: " << getid() << endl;
        cout << "AGE: " << getage() << endl;
        cout << "MAXIMUM HEART RATE: " << getmaxheartrate() << endl;
        gettarget();
    }
};
int main()
{
    string n;
    int d;
    int m;
    int y;
    int roll;
    cout << "ENTER NAME: " << endl;
    cin >> n;
     cout << "ENTER ROLL NO: " << endl;
    cin >> roll;
    cout << "ENTER DAY: " << endl;
    cin >> d;
    cout << "ENTER MONTH: " << endl;
    cin >> m;
    cout << "ENTER YEAR: " << endl;
    cin >> y;
    HeartRate obj(n, roll, m, y, d);
    obj.display();

    return 0;
}
#include <iostream>
using namespace std;

class DateTime
{
private:
    int day, month, year;
    int hours, minutes, seconds;

public:
    DateTime()
    {
        day = month = year = 0;
        hours = minutes = seconds = 0;
    }

    void SetValue(int d, int m, int y, int h = 0, int min = 0, int s = 0)
    {
        day = d;
        month = m;
        year = y;
        hours = h;
        minutes = min;
        seconds = s;
    }

    void display()
    {
        if (day < 10)
            cout << "0";
        cout << day << "/";

        if (month < 10)
            cout << "0";
        cout << month << "/";

        cout << year << " ";

        if (hours < 10)
            cout << "0";
        cout << hours << ":";

        if (minutes < 10)
            cout << "0";
        cout << minutes << ":";

        if (seconds < 10)
            cout << "0";
        cout << seconds << endl;
    }

    bool isEarlier(DateTime d)
    {
        if (year != d.year)
            return year < d.year;
        if (month != d.month)
            return month < d.month;
        if (day != d.day)
            return day < d.day;
        if (hours != d.hours)
            return hours < d.hours;
        if (minutes != d.minutes)
            return minutes < d.minutes;
        if (seconds != d.seconds)
            return seconds < d.seconds;

        return false;
    }
};

int main()
{
    DateTime obj1, obj2;

    obj1.SetValue(10, 3, 2020);
    obj2.SetValue(10, 3, 2024, 14, 30, 45);

    cout << "DATE-TIME 1" << endl;
    obj1.display();

    cout << "DATE-TIME 2" << endl;
    obj2.display();

    if (obj1.isEarlier(obj2))
        cout << "TIME OF FIRST OBJECT IS EARLIER" << endl;
    else
        cout << "TIME OF SECOND OBJECT IS EARLIER" << endl;

    return 0;
}
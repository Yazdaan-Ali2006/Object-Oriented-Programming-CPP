#include <iostream>
using namespace std;

class DateTime
{
private:
    int day, month, year;
    int hours, minutes, seconds;

public:
    void SetValue(int d, int mo, int yr, int h = 0, int mi = 0, int s = 0)
    {
        day = d;
        month = mo;
        year = yr;
        hours = h;
        minutes = mi;
        seconds = s;
    }

    void Display() const
    {
        if (day < 10)
            cout << "0";
        cout << day << "/";
        if (month < 10)
            cout << "0";
        cout << month << "/";
        cout << year << "  ";
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

    bool isEarlier(DateTime d) const
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
        return seconds < d.seconds;
    }
};

int main()
{
    DateTime dt1, dt2;

    // Only date — hours/minutes/seconds default to 0
    dt1.SetValue(15, 3, 2024);

    // Full date and time
    dt2.SetValue(10, 3, 2024, 14, 30, 45);

    cout << "DateTime 1: ";
    dt1.Display();

    cout << "DateTime 2: ";
    dt2.Display();

    if (dt1.isEarlier(dt2))
    {
        cout << "\nDateTime 1 is EARLIER than DateTime 2." << endl;
    }
    else
    {
        cout << "\nDateTime 2 is EARLIER than or EQUAL to DateTime 1." << endl;
    }

    return 0;
}

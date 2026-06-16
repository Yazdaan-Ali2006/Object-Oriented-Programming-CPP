#include <iostream>
using namespace std;
class DateException
{
public:
    string message;
    DateException(string message)
    {
        this->message = message;
    }
    string what()
    {
        return message;
    }
};
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    void SetDate(int d, int m, int y)
    { // for day

        if ((d > 0 && d < 32) && (m > 0 && m < 13) && (y > 0 && y < 2051))
        {
            day = d;
            month = m;
            year = y;
        }
        else
        {
            throw DateException("Invalid Date");
        }
    }
};
int main()
{
    Date date;
    try
    {
        date.SetDate(0, 10, 2010);
    }
    catch (DateException &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
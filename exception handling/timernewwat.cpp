#include <iostream>
using namespace std;
class Exception
{

public:
    string msg;

    Exception(string msg)
    {
        this->msg = msg;
    }
};
class Timer
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Timer()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    void tick()
    {
        seconds++;
        if (seconds == 60)
        {
            minutes++;
            seconds = 0;
        }
        if (minutes == 60)
        {
            hours++;
            if (hours == 1)
            {
                throw Exception("TIMER OVERFLOW");
            }
            minutes = 0;
        }
        cout << "HOUR " << hours << ":MINUTES " << minutes << ":SECONDS " << seconds << endl;
    }
};
int main()
{
    Timer t1;
    while (1)
    {
        try
        {
            t1.tick();
        }
        catch (Exception &error)
        {
            cout << error.msg << endl;
            break;
        }
    }
    return 0;
}

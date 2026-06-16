#include <iostream>
#include <stdexcept>
using namespace std;

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
                throw runtime_error("TIMER OVERFLOW");
            }
            minutes = 0;
        }
        cout << "HOUR " << hours << ":MINUTES " << minutes << ":SECONDS " << seconds << endl;
    }
};
int main()
{
    Timer t1;
    try
    {
        while (1)
        {

            {
                t1.tick();
            }
        }
    }
    catch (runtime_error &msg)
    {
        cout << "ERROR:" << msg.what() << endl;
    }

    return 0;
}

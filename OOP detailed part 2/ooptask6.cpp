#include <iostream>
using namespace std;

/*6. Develop a Time class to represent time in hours, minutes, and seconds. 
Include methods to add two times together and display the result.*/
class Time
{
private:
    int hr, min, sec;

public:
    // constructor
    Time(int h = 0, int m = 0, int s = 0)
    {
        hr = h;
        min = m;
        sec = s;
    }

    // setters
    void setHr(int h)
    {
        hr = h;
    }

    void setMin(int m)
    {
        min = m;
    }

    void setSec(int s)
    {
        sec = s;
    }

    // getters
    int getHr()
    {
        return hr;
    }

    int getMin()
    {
        return min;
    }

    int getSec()
    {
        return sec;
    }

    // increment functions
    void increment_hr()
    {
        hr++;
    }

    void increment_min()
    {
        min++;
    }

    void increment_sec()
    {
        sec++;
    }

    // decrement functions
    void decrement_hr()
    {
        if (hr <= 0)
            return;
        else
            hr--;
    }

    void decrement_min()
    {
        if (min <= 0)
            return;
        else
            min--;
    }

    void decrement_sec()
    {
        if (sec <= 0)
            return;
        else
            sec--;
    }

    // display function
    void display()
    {
        cout << hr << " hr:" << min << " min:" << sec << " sec" << endl;
    }
};

int main()
{ Time t1(2,30,52);
    t1.increment_hr();
    t1.increment_min();
    t1.setSec(40);
    t1.increment_sec();
    t1.display();
    return 0;
}

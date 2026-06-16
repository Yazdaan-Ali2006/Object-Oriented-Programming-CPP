#include <iostream>
using namespace std;
class counter
{ 
    int count;

public:
    counter()
    {
        count = 0;
    }
    counter(int a)
    {
        count = a;
    }

    void increment()
    {
        count++;
    }
    void decrement()
    {
        count--;
    }

    void display()
    {
        cout << "THE CURRENT VALUE OF COUNTER IS: " << count << endl;
    }
    friend void reset(counter &c1);
};
void reset(counter &c1)
{
    c1.count = 0;
}
int main()
{
    counter c1(5);

    c1.increment();
    c1.display();
    c1.decrement();
    c1.display();
    reset(c1);
    c1.display();

    return 0;
}
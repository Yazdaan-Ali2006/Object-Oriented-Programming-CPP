#include <iostream>
using namespace std;
class engine
{
public:
    void start_engine()
    {
        cout << "ENGINE HAS BEEN STARTED..." << endl;
    }
    ~engine()
    {
        cout << "ENGINE DESTROYED  " << endl;
    }
};
class car
{
    engine e1;

public:
    void start_car()
    {
        e1.start_engine();
        cout << "CAR STARTED" << endl;
    }
    ~car(){
        cout<<"CAR DESTROYED"<<endl;
    }
};
int main()
{
    car c;
    c.start_car();
    return 0;
}
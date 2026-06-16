#include <iostream>
using namespace std;
class scooty
{
private:
    float bootspace;

public:
    int topspeed;
    int mileage;
    virtual void sound()
    {
        cout << "Vroom Vroom" << endl;
    }
};
class bike : public scooty
{
public:
    int gears;
    void sound()
    {
        cout << "Dhroom Dhroom" << endl;
    }
};
class superbike:public scooty{
public:
void sound(){
    cout<<"Boom Boom "<<endl; 
}
};
int main()
{ 
    scooty *s=new bike();
    s->sound();
    scooty *sp=new superbike(); //bike *sp=new superbike(); cant be done cuz it is inherited from scooty
    sp->sound();
    return 0;
}
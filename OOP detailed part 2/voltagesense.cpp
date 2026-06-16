#include <iostream>
using namespace std;
class voltagesensor
{
private:
    const int ID;
    float voltage;
    public:
    voltagesensor(float v, int id) : ID(id), voltage(v)
    {   cout<<"constructor is worikng "<<endl;
    }
    void setvoltage(float a){
        voltage=a;

    }
    float getvoltage() const{
        return voltage;
    }
    void display() const{
        cout<<"ID: "<<ID<<endl;
        cout<<"VOLTAGE: "<<voltage<<"V"<<endl;
    }

};
int main()

{ const voltagesensor v1(2,23.1); 
    v1.display();

    return 0;
}
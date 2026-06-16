#include <iostream>
using namespace std;
#include <stdexcept>
class bike
{
    string name;
    string engine;

public:
    bike()
    {
        name = "N/A";
        engine = "N/A";
    }
    bike(string n, string e)
    {
        if (n == " " || e == " ")
        {
            throw invalid_argument("ERROR EXCEPTIONAL CASE");
        }
        name = n;
        engine = e;
    }
    string getname()
    {
        return name;
    }
    string getengine()
    {
        return engine;
    }
    void display()
    {
        cout << "NAME:" << getname() << endl;
        cout << "ENGINE:" << getengine() << endl;
    }
};
class owner
{
    string name;

public:
    owner()
    {
        name = "";
    }
    owner(string n)
    {
        if (n == " ")
        {
            throw invalid_argument("ERROR");
        }
        name = n;
    }
    string getname()
    {
        return name;
    }
    void display()
    {
        cout << "OWNER NAME:" << getname() << endl;
    }
};
class showroom
{
    bike b[2];
    owner *o;
    int count;

public:
    showroom(owner *obj)
    {
        o = obj;
        count = 0;
    }
    void addbike()
    {
        string name, e;
        try
        {
            if (count >= 2)
            {
                throw runtime_error("COUNTER FULL");
            }
            cout << "ENTER THE NAME OF BIKE:";
            cin >> name;
            cout << "ENTER THE ENGINE OF BIKE:";
            cin >> e;
            b[count++] = bike(name, e);
        }
        catch (invalid_argument &e1)
        {
            cout << e1.what() << endl;
        }
        catch (runtime_error &e1)
        {
            cout << e1.what() << endl;
        }
    }
    void display()
    {
        o->display();
        for (int i = 0; i < count; i++)
        {
            b[i].display();
        }
    }
};
int main() 
{   owner o("ali");
    showroom s(&o);
    s.addbike();
    s.addbike();
    s.display();
    return 0;
}
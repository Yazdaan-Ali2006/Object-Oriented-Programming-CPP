#include <iostream>
using namespace std;
class car
{
public:
    int model_year;
    string name;
    string type;

    // defauly constructor
    car()
    {
    }
    // parameterised constructor
    car(string name, string type, int model_year)
    {
        this->name = name;
        this->type = type;
        this->model_year = model_year;
    }
    void print()
    {
        cout << "Name: " << name << endl
             << "Model: " << model_year << endl
             << "Type: " << type << endl;
    }
};
void change_model_year(car *c)
{
    cout << "Enter the new model year: ";
    cin >> (*c).model_year;
}

int main()
{
    car c1("Aqua", "Hatchback", 2015);
    c1.print();
    change_model_year(&c1);
    c1.print();

    return 0;
}
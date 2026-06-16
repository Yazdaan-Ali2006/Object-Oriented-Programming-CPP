#include <iostream>
using namespace std;
class address
{
private:
    int street_num;
    string area;

public:
    address()
    {
        street_num = 0;
        area = "null";
    }
    address(int street_num, string area)
    {
        this->street_num = street_num;
        this->area = area;
    }
    void display()
    {
        cout << "Street Number:" << street_num << endl;
        cout << "AREA:" << area << endl;
    }
};
class student
{
private:
    string studname;
    address *a;

public:
    student()
    {
        studname = " ";
        a = new address();
    }
    student(string studname, int street_num, string area)
    {
        this->studname = studname;
        this->a = new address(street_num, area);
    }
    void display()
    {
        cout << "NAME:" << studname << endl;
        a->display(); // a.display()
    }
    ~student()
    {
        delete a;
        cout << "destructor run" << endl;
    }
};
int main()
{
    student s1("ali", 2, "ABC SOCIETY");
    s1.display();
    return 0;
}
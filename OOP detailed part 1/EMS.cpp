#include <iostream>
using namespace std;
class employeesystem
{
public:
    string name;
    int id;
    float basic_salary;

    employeesystem()
    {
        name = "null";
        id = 0;
        basic_salary = 0;
    }
    employeesystem(string n, int i, float bs)
    {
        name = n;
        id = i;
        basic_salary = bs;
    }
    virtual float calcsalary()
    {
        return basic_salary;
    }
    virtual void display()
    {
        cout << "NAME:" << name << endl;
        cout << "ID:" << id << endl;
        cout << "BASIC SALARY:" << calcsalary() << endl;
    }
    virtual ~employeesystem()
    {
        cout << "BASE DESTERUCTOR" << endl;
    }
};
class manager : public employeesystem
{

public:
    float bonus;
    manager(string n, int i, float bs,int bn=0):employeesystem(n,i,bs){
        bonus=bn;
    }
    float calcsalary() override
    {
        return (basic_salary + bonus);
    }
    void display()
    {
        employeesystem::display();
        cout << "BONUS:" << bonus << endl;
    }
    ~manager()
    {
        cout << "CHILD DESTRUCTOR" << endl;
    }
};
int main()
{
    employeesystem *obj1 = new employeesystem("ali", 10, 12340);
    obj1->display();
    employeesystem *obj2 = new manager("ali", 10, 12340,40);
    obj2->display();
    delete obj1;
    delete obj2;

    return 0;
}
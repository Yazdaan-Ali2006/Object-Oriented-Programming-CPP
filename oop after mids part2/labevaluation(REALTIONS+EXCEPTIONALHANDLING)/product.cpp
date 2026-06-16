#include <iostream>
#include <stdexcept>
using namespace std;
class Product
{
    string name;
    int price;

public:
    Product()
    {
        name = "N/A";
        price = 1;
    }
    Product(string n, int p)
    {
        if (n == "")
        {
            throw invalid_argument("ERROR:INVALID NAME");
        }
        name = n;

        if (p <= 0)
        {
            throw invalid_argument("ERROR:INVALID PRICING");
        }
        price = p;
    }
    string getname()
    {
        return name;
    }
    int getprice()
    {
        return price;
    }
    void display()
    {
        cout << "NAME:" << getname() << endl;
        cout << "PRICE:" << getprice() << endl;
    }
};
class Manager
{
    string name;

public:
    Manager()
    {
        name = "N/A";
    }
    Manager(string n)
    {
        if (n == "")
        {
            throw invalid_argument("ERROR:EMPTY STRING NOT ALLOWED");
        }
        name = n;
    }
    string getname()
    {
        return name;
    }
    void display()
    {
        cout << "MANAGER:" << getname() << endl;
    }
};
class Store
{
    Manager *mg;
    int count;
    Product p[5];

public:
    Store(Manager *m)
    {
        mg = m;
        count = 0;
    }
    void addProduct()
    {
        string itemname;
        int pricing;
        if (count <= 2)
        {
            try
            {
                cout << "ENTER NAME OF PRODUCT:";
                cin >> itemname;
                cout << "ENTER PRICE:";
                cin >> pricing;
                p[count++] = Product(itemname, pricing);
            }
            catch (invalid_argument &e1)
            {
                cout << e1.what() << endl;
            }
        }
    }
    void display()
    {
        mg->display();
        for (int i = 0; i < count; i++)
        {
            p[i].display();
        }
    }
};

int main()
{
    try
    {
        Manager m1("Ali");
        Store s1(&m1);
        s1.addProduct();
        s1.display();
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}

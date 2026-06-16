
#include <iostream>
using namespace std;

/*Q7: Order – Item
Create:
Class Item → name, price
Class Order → Item items[5]
Tasks:
Add items
Calculate total bill
Display all items*/
class Item
{
private:
    string name;
    int price;

public:
    Item() : name("none"), price(0) {}
    Item(string name, int price)
    {
        this->name = name;
        this->price = price;
    }
    void display()
    {
        cout << "NAME:" << name << endl;
        cout << "PRICE:" << price << endl;
    }
    string getname()
    {
        return name;
    }
    int getprice()
    {
        return price;
    }
};
class Order
{
private:
    int ordernumber;
    int itemcounter;
    Item items[5];

public:
    Order(int n)
    {
        ordernumber = n;
        itemcounter = 0;
    }
    void additem(string n, int p)
    {
        if (itemcounter < 5)
        {
            items[itemcounter++] = Item(n, p);
        }
    }
    void display()
    {
        int final = 0;
        cout << "ORDER NO." << ordernumber << endl;
        for (int i = 0; i < itemcounter; i++)
        {
            items[i].display();

            final += items[i].getprice();
        }
        cout << "TOTAL BILL:" << final << endl;
    }
};

int main()
{   Order o1(1);
    o1.additem("ALFREDO FETTUCCINE",1680);
    o1.additem("DYNAMITE CHICKENS",850);
    o1.additem("BEEF SMASH",1390);
    o1.additem("PINA COLADA",750);
    o1.additem("FUDGE BROWNIE",990);
    o1.display();

    return 0;
}
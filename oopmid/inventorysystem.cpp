#include <iostream>
using namespace std;
class inventorysytem
{
protected:
    int quantity;
    float price;

public:
    inventorysytem()
    {
        quantity = 0;
        price = 0;
    }
    inventorysytem(int q, float p)
    {
        quantity = q;
        price = p;
    }
    virtual void input()
    {
        cout << "ENTER QUANTITY" << endl;
        cin >> quantity;
        cout << "ENTER PRICE" << endl;
        cin >> price;
    }
    virtual float gettotalcost()=0;
  

    virtual void display()
    {
        cout << "QUANTITY:" << quantity << endl;
        cout << "PRICE:" << gettotalcost() << endl;
    }
};
class discount : public inventorysytem
{
protected:
    float discountpercent;

public:
    void input() override
    {
        inventorysytem::input();
        cout << "ENTER DISCOUNT PERCENTAGE" << endl;
        cin >> discountpercent;
    }
    void display() override
    {
        cout << "====DISCOUNTED ITEM DETAILS" << endl;
        inventorysytem::display();
        cout << "DISCOUNT PERCENT" << discountpercent << endl;
    }
    float gettotalcost() override
    {
        return (price * (1 - discountpercent / 100));
    }
};
class imported : public inventorysytem
{
protected:
    float importtax;

public:
    void input() override
    {
        inventorysytem::input();
        cout << "ENTER TAX PERCENTAGE" << endl;
        cin >> importtax;
    }
    void display() override
    {
        cout << "====IMPORTED ITEM DETAILS" << endl;
        inventorysytem::display();
        cout << "IMPORT TAX PERCENTAGE" << importtax << endl;
    }
    float gettotalcost() override
    {
        return (price * (1 + importtax / 100));
    }
};

int main()
{
    int n;
    cout << "ENTER THE SIZE ";
    cin >> n;
    inventorysytem **arr = new inventorysytem *[n];
    for (int i = 0; i < n; i++)
    {
        int choice;
        cout << "WHICH ITEM YOU WANT TO STORE IN THE INVENTORY" << endl;
        cout << "1-discounted \n 2-imported" << endl;
        cin >> choice;
        if (choice == 1)
        {
            arr[i] = new discount();
        }
        else if (choice == 2)
        {
            arr[i] = new imported();
        }
        else
        {
            cout << "ERROR!" << endl;
            break;
        }
        arr[i]->input();
    }
    float cost = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i]->display();
        cost += arr[i]->gettotalcost();
    }
    cout << "TOTAL COST IS" << cost << endl;
    return 0;
}
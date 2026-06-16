#include <iostream>
using namespace std;

class inventorysystem
{
protected:
    string name;
    double unitprice;

public:
    virtual void input()
    {
        cout << "Enter Name:";
        cin >> name;
        do
        {
            cout << "Enter Unit Price:";
            cin >> unitprice;
        } while (unitprice <= 0);
    }
    virtual double totalcost()
    {
        return unitprice;
    }
    virtual void display()
    {
        cout << "NAME:" << name << endl;
        cout << "UNIT PRICE:" << unitprice << endl;
        cout << "TOTAL COST:" << totalcost() << endl;
    }
    virtual ~inventorysystem()
    {
        cout << "HI I AM DESTRUCTOR OF BASE CLASS" << endl;
    }
};
class bulkitem : public inventorysystem
{
protected:
    int quantity;

public:
    void input() override
    {
        inventorysystem::input();
        do
        {
            cout << "Enter Quantity";
            cin >> quantity;
        } while (quantity <= 0);
    }
    void display() override
    {    cout<<"DETAILS OF BULK ITEMS:"<<endl;
        inventorysystem::display();
        cout << "QUANTITY" << quantity << endl;
    }
    double totalcost() override
    {
        return unitprice * quantity;
    }
    ~bulkitem(){
        cout<<"BULK DESTRUCTOR"<<endl;
    }
};

class discounteditems : public inventorysystem
{
protected:
    double discountpercent;
    void input() override
    {
        inventorysystem::input();
        do
        {
            cout << "Enter discount percent:";
            cin >> discountpercent;
        } while (discountpercent <= 0 || discountpercent > 100);
    }
    void display() override
    {    cout<<"DETAILS OF DISCOUNTED ITEMS"<<endl;
        inventorysystem::display();
        cout << "DISCOUNT PERCENT:" << discountpercent << endl;
    }
    double totalcost() override
    {
        return (unitprice * (discountpercent) / 100);
    }
    ~ discounteditems(){
        cout<<"DISCOUNT DESCTRUCTOR"<<endl;
    }
};
class importeditem : public inventorysystem
{
protected:
    double importtaxpercent;

public:
    void input() override
    {
        inventorysystem::input();
        do
        {
            cout << "Enter tax on imported item";
            cin >> importtaxpercent;
        } while (importtaxpercent <= 0);
    }
    void display() override
    {   cout<<"DETAILS OF IMPORTED ITEMS:"<<endl;
        inventorysystem::display();
        cout << "IMPORTED TAX:" << importtaxpercent << endl;
    }
    double totalcost() override
    {
        return (unitprice * (importtaxpercent) / 100);
    }
    ~importeditem(){
        cout<<"IMPORTED DESTRUCTOR"<<endl;
    }
};
void displayfn()
{
    cout << "(1)-BULK ITEMS" << endl;
    cout << "(2)-DISCOUNTED ITEM" << endl;
    cout << "(3) IMPORTED ITEM" << endl;
}
int main()
{   cout<<"WELCOME TO INVENTORY SYSTEM"<<endl;
    int items;
    cout << "Enter Items:";
    cin >> items;
    inventorysystem **array = new inventorysystem *[items];
    int i;
    int choice;
    displayfn();
    cout << "ENTER YOUR CHOICE.....";
    cin >> choice;
    
        for (i = 0; i < items; i++)
        {
            if (choice == 1)
            {
                array[i] = new bulkitem();
            }
            else if (choice == 2)
            {
                    array[i] = new discounteditems();
            }

            else if(choice==3)
            {
                array[i]=new importeditem();
            }
            else{
                cout<<"INVALID INPUT......"<<endl;
            }
            array[i]->input();
        }
        for(i=0;i<items;i++)
        {
            array[i]->display();
        }
        for(i=0;i<items;i++){
            delete array[i];
        }
        
        delete array;
            

            return 0;
        }
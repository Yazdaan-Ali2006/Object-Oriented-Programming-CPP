#include <iostream>
using namespace std;
/*Write a C++ program to implement an Inventory Management system using runtime polymorphism.
• Create a base class InventoryItem with protected attributes name (string) and unitPrice (double).
• In InventoryItem, declare virtual functions input(), totalCost() and display(), and also add a virtual destructor.
• The base input() should take item name using getline() and validate that unit price is greater than 0.
• The base display() should print name, unit price, and total cost by calling totalCost().
• Create three derived classes publicly inherited from InventoryItem:
• BulkItem with an additional attribute quantity (int). Override input() to first call InventoryItem::input() and then
input quantity (validate > 0). Override totalCost() to return unitPrice * quantity. Override display() to show full
details including quantity.
• DiscountedItem with an additional attribute discountPercent (double). Override input() to input discount
percent (validate 0–100). Override totalCost() to apply discount: unitPrice * (1 - discountPercent/100). Override
display() to show discount percent and the final total.
• ImportedItem with an additional attribute importTaxPercent (double). Override input() to input tax percent
(validate 0–100). Override totalCost() to add tax: unitPrice * (1 + importTaxPercent/100). Override display() to
show tax percent and the final total.
• In main(), ask the user for n (number of items) and create a dynamic array of base-class pointers using
InventoryItem** items = new InventoryItem*[n];. For each item, ask the user to choose its type (Bulk,
Discounted, Imported), create the appropriate derived object using new, and store it in the array. Use a loop to
call items[i]->input() for all items, then use another loop to call items[i]->display() and compute the grand total
by summing items[i]->totalCost(). Finally, properly deallocate all dynamically allocated objects using delete for
each items[i] and delete[] items.*/
class inventorysystem
{
protected:
    string name;
    double unitprice;

public:
    virtual void input()
    {
        cout "Enter your name";
        cin >> name;
        do
        {
            cout "Enter Unit price";
            cin >> unitprice;
            while (unitprice <= 0)
                ;
        }
    }
    virtual double totalcost()
    {
        return unitprice;
    }
    virtual void display()
    {
        cout << "===INVENTORY REPORT===" << endl;
        cout << "NAME:" << name << endl;
        cout << "COST:" << totalcost() << endl;
    }
    virtual ~inventorysystem(){
        default;
    }
};
class bulkitem : public inventorysystem
{
private:
    int quantity;

public:
    inventorysystem::input() override
    {
        do
        {
            cout "Enter quantity" << endl;
            cin >> quantity;
            while (unitprice <= 0)
                ;
        }
    }
    inventorysystem::totalcost() override
    {
        return (unitprice + totalcost());
    }
    inventorysystem::display() override
    {
        cout << "QUANTITY:" << quantity << endl;
    }
};
class discounted : public inventorysystem
{
    double discountpercent;
    inventorysystem::input() override
    {
        cout << "ENTER DISCOUNT PERCENTAGE %" << endl;
        cin >> discountpercent :

            inventorysystem::totalcost() override
        {
            return unitprice * (1 - discountpercent / 100);
        }
        inventorysystem::display() override
        {
            cout << "DISCOUNT PERCENT:" << discountpercent << "%" << endl;
            cout << "TOTAL:" << totalcost() << endl;
        }
    };
    class importeditem: public inventorysystem{
                 double importtaxpercent;
                 inventorysystem::input()override{
                    cout<<"ENTER TAX %"<<endl;
                    cin>>importtaxpercent;
            
                 }
                 inventorysystem::totalcost() override{
                    return (unitprice*(1+importtaxpercent/100));

                 }
                 inventorysystem::display() override{
                    cout<<"TOTAL PERCENT TAX:"<<importtaxpercent<<endl;
                    cout<<"TOTAL AMOUNT:"<<totalcost()<<endl;
                 }

    };
int main()
{
    int n, choice;
    double grandTotal = 0;

    cout << "Enter number of items: ";
    cin >> n;
    cin.ignore();   // important for getline()

    InventoryItem** items = new InventoryItem*[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nChoose item type for item " << i + 1 << endl;
        cout << "1. Bulk Item\n2. Discounted Item\n3. Imported Item\n";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
            items[i] = new BulkItem();
        else if (choice == 2)
            items[i] = new DiscountedItem();
        else if (choice == 3)
            items[i] = new ImportedItem();
        else
        {
            cout << "Invalid choice! Try again.\n";
            i--;
            continue;
        }

        items[i]->input();   // runtime polymorphism
    }

    cout << "\n===== INVENTORY REPORT =====\n";

    for (int i = 0; i < n; i++)
    {
        items[i]->display();
        grandTotal += items[i]->totalCost();
    }

    cout << "\nGrand Total = " << grandTotal << endl;

    for (int i = 0; i < n; i++)
        delete items[i];

    delete[] items;

    return 0;
}

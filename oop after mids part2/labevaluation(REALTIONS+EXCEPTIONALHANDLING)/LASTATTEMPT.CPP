#include <iostream>
#include <stdexcept>

using namespace std;
// 1. Class Account
// Create a class Account with:
// char* holderName
// int accountNumber
// double balance
// Requirements:
// Default constructor
// Parameterized constructor
// Destructor (VERY IMPORTANT)
// Getter functions
// displayAccount()
// Validation:
class account
{
    string holdername;
    int accountnumber;
    double balance;

public:
    account()
    {
        holdername = "N/A";
        accountnumber = 1;
        balance = 1;
    }
    account(string h, int ac, double b)
    {
        if (h == "")
        {
            throw invalid_argument("ERROR:EMPTY STRING NOT ALLOWED");
        }
        holdername = h;
        if (ac < 0)
        {
            throw invalid_argument("INVALID ACCOUNTNUMBER");
        }
        accountnumber = ac;
        if (b < 0)
        {
            throw invalid_argument("INVALID BALANCE");
        }
        balance = b;
    }
    string getname()
    {
        return holdername;
    }
    int getbankaccount()
    {
        return accountnumber;
    }
    double getbalance()
    {
        return balance;
    }
    void display()
    {
        cout << "NAME:" << getname() << endl;
        cout << "AMOUNT:" << getbalance() << endl;
        cout << "ACCOUNT:" << getbankaccount() << endl;
    }
};
class bankmanager
{
    string name;

public:
    bankmanager()
    {
        name = "N/A";
    }
    bankmanager(string n)
    {
        if (n == "")
        {
            throw invalid_argument("ERROR:EMPTY STRING NOT ALLOWED");
        }
        name = n;
    }
    string getmanagername()
    {
        return name;
    }

    void displaymanager()
    {
        cout << "MANAGER NAME:" << getmanagername() << endl;
    }
};

// Class BankManager
// Create a class BankManager with:
// string name
// Requirements:
// Constructor
// displayManager()
// Validation:
// name must not be empty
// throw exception if invalid
class bank
{
    account a1[5];
    bankmanager *m;
    int count;

public:
    bank(bankmanager *mng)
    {
        m = mng;
        count = 0;
    }
    void addaccounts()
    {
        try
        {
            if (count >=5)
            {
                throw runtime_error("OUT OF BOUND");
            }

            string a;
            int b;
            double c;
            cout << "ENTER HOLDER NAME:";
            cin >> a;
            cout << "ENTER BANK ACCOUNT NUMBER:";
            cin >> b;
            cout << "ENTER BALANCE:";
            cin >> c;
            a1[count++] = account(a, b, c);
        }
        catch (runtime_error &e1)
        {
            cout << e1.what() << endl;
        }
        catch (invalid_argument &e1)
        {
            cout << e1.what() << endl;
        }
    }
    void displayall()
    {
        m->displaymanager();
        for (int i = 0; i < count; i++)
        {
            a1[i].display();
        }
    }
};

// 📌 3. Class Bank (MAIN CLASS)
// Attributes:
// Account accounts[5] (composition)
// BankManager* mgr (aggregation) 
int main()
{
    bankmanager b1("ali");
    bank b(&b1);
    b.addaccounts();
    b.addaccounts();
    b.addaccounts();
    b.addaccounts();
    b.addaccounts();
    b.displayall();
    return 0;
}
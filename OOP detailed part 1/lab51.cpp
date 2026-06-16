#include <iostream>
using namespace std;
/*Q4. Develop a class Post that has following attributes
 Name: a string
 To : a string that holds the reciever's address
 StampCost: a float that holds the value of postal stamp required
The class should include following:
 A constructor that initializes StampCost to 1$ and To to empty address
 Read(): a method that reads data member's values from user
 Print(): a method that displays data member's values on screen
 TotalCost(): a method that returns stampCost value

Develop another class RegisteredPost that inherits from Post class and has following additional
attributes:
 Weight: a float that holds the weight of post
 RegistrationCost: a float that holds registration charges
Also include following in the class.
 A constructor that initializes weight to 20 gms and RegisterationCost to 10$
 Read(): a method that reads data member's values from user
 Print(): a method that displays data member's values on screen
 TotalCost(): a method that returns stampCost+RegistrationCost.*/
class post
{

    string name;
    string to;
    float stamppost;

public:
    post()
    {
        stamppost = 1;
    }
    void read()
    {
        cout << "ENTER NAME: ";
        getline(cin, name);
        cout << "ENTER RECEIVER'S ADDRESS: ";
        getline(cin, to);
        cout << "ENTER THE VALUE OF POSTAL STAMP: ";
        cin >> stamppost;
    }
    void print()
    {
        cout << "NAME: " << name << endl;
        cout << "RECEIVER'S ADDRESS: " << to << endl;
        cout << "POSTAL STAMP: " << stamppost << "$" << endl;
        cout << "TOTAL COST: " << totalcost() << endl;
    }
    float totalcost()
    {
        return stamppost;
    }
};
class Registeredpost : public post
{
    float weight;
    float registrationcharges;

public:
    Registeredpost()
    {
        weight = 20;
        registrationcharges = 10;
    }
    void read()
    {
        post::read();
        cout << "ENTER WEIGHT: ";
        cin >> weight;
        cout << "ENTER REGISTRATION CHARGES ";
        cin >> registrationcharges;
    }

    void print()
    {
        post::print();
        cout << "WEIGHT: " << weight << "gm" << endl;
        cout << "REGISTRATION CHARGES: " << registrationcharges << endl;
    }
    float totalcost()
    {
        return (registrationcharges + post::totalcost
            ());
    }
};
class insuredregisteredpost : public Registeredpost
{
    float amtinsured;

public:
    insuredregisteredpost()
    {
        amtinsured = 20;
    }
    void read()
    {
        Registeredpost::read();
        cout << "ENTER THE AMOUNT TO BE INSURED:";
        cin >> amtinsured;
    }
    void print()
    {
        Registeredpost::print();
        cout << "INSURED AMOUNT: " << amtinsured << endl;
        ;
    }
    float totalcost()
    {
        return (Registeredpost::totalcost() + amtinsured);
    }
};

int main()
{
    insuredregisteredpost envelope;
    envelope.read();
    cout << "POST DETAILS.."<<endl;
    envelope.print();
    return 0;
}
#include <iostream>
using namespace std;
/*Create a Book class with attributes such as title, author, and ISBN.
Include methods to display book details and set book details.*/
class book
{
    string title;
    string author;
    string ISBN;

public:
    book() // default
    {
        title="NULL";
        author="NULL";
        ISBN="NULL";
    }
    void set_details(string a, string b, string c) // setter
    {
        title = a;
        author = b;
        ISBN = c;
    }
    string get_title()
    { // getter
        return title;
    }
    string get_author()
    { // getter
        return author;
    }
    string get_ISBN()
    { // getter
        return ISBN;
    }
    void display()
    { // display details
        cout << "TITLE: " << get_title() << endl;
        cout << "AUTHOR: " << get_author() << endl;
        cout << "ISBN: " << get_ISBN() << endl;
    }
};
int main()
{
    book b1;
    b1.set_details("Complacency Kills", "Yazdaan Ali","999-888-777");
    b1.display();
    return 0;
}
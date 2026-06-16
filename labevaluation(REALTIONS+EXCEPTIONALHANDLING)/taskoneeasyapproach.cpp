#include <iostream>
#include <stdexcept>
using namespace std;
class Book
{
    string title;
    int pages;

public:
    Book()
    {
        title = "N/A";
        pages = 0;
    }
    Book(string t, int p)
    {
        title = t;
        pages = p;
    }
    string getbooktitle()
    {
        return title;
    }
    int getpages()
    {
        return pages;
    }
    void displaybook()
    {
        cout << "TITLE:" << title << endl;
        cout << "PAGES:" << pages << endl;
    }
};
class librarian
{
    string name;

public:
    librarian()
    {
        name = "N/A";
    }
    librarian(string n)
    {
        try
        {
            if (n == "")
            {
                throw invalid_argument("INVALID LIBRARIAN NAME");
            }
            else
            {
                name = n;
            }
        }
        catch (invalid_argument &e1)
        {
            cout << "EXCEPTION:" << e1.what() << endl;
        }
    }
    string getname()
    {
        return name;
    }
    void display()
    {
        cout << "LIBRARIAN:" << getname() << endl;
    }
};
class library
{
    int counter;
    Book books[5];
    librarian *lbn;

public:
    library(librarian *l)
    {
        counter = 0;
        lbn = l;
        counter = 0;
    }
    void addbooks()
    {
        string title;
        int p;
        if (counter < 5)
        {
            cout << "ENTER BOOK DETAILS:" << endl;
            try
            {
                cout << "TITLE:";
                cin >> title;
                cout << "ENTER PAGES:";
                cin >> p;
                if (title == "")
                {
                    throw invalid_argument("ERROR INCORRECT TITLE");
                }
                if (p < 0)
                {
                    throw invalid_argument("ERROR INCORRECT PAGE");
                }
            }
            catch (invalid_argument &e1)
            {
                cout << e1.what() << endl;
            }
            books[counter++] = Book(title, p);
        }

        else
        {
            cout << "LIBRARY IS FULL" << endl;
        }
    }
    void displaylibrary()
    {
        cout << "LIBRARY" << endl;
        lbn->display();
        for (int i = 0; i < counter; i++)
        {
            books[i].displaybook();
        }
    }
};
int main()
{  librarian lbn("");
//      cout<<lbn.getname()<<endl;
    library lib(&lbn);
    lib.addbooks();
    lib.addbooks();
    lib.addbooks();
    lib.addbooks();
    lib.addbooks();
    lib.displaylibrary();
    

    return 0;
}
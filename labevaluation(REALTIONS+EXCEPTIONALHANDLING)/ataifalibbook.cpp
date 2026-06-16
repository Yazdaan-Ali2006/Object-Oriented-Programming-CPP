// exception handling
// handle the invalid input using standard C++ exception classes
// ensure that:
// book data must be valid(pages not less than or equal to 0, title not empty)
// approp. error messages are displayed when invalid data is provided

#include <iostream>
using namespace std;

// create a class book with the following attributes
// title string
// pages int
// req:
// constructor to initialize data members
// getter functions for all members
// a function displaybook() to print book details
class Book
{
    string title;
    int pages;

public:
    Book() : title("N/R"), pages(1) {}
    Book(string t, int p) : title(t)
    {
        try
        {
            if (p <= 0)

                throw logic_error("INVALID PAGE NO!");

            pages = p;
        }
        catch (const logic_error &l)
        {
            cout << "EXCEPTION:" << l.what();
        }
    }

    void settitle(string t) { title = t; }
    void setpages(int p)
    {
        try
        {
            if (p <= 0)

                throw logic_error("INVALID PAGE NO!");

            pages = p;
        }
        catch (const logic_error &l)
        {
            cout << "EXCEPTION:" << l.what();
        }
    }

    string gettitle() { return title; }
    int getpages() { return pages; }

    void input()
    {
        int p;
        cout << "ENTER TITLE:";
        cin >> title;
        do
        {
            cout << "ENTER PAGES:";
            cin >> p;
            try
            {
                if (p <= 0)

                    throw logic_error("INVALID PAGE NO!");

                pages = p;
            }
            catch (const logic_error &l)
            {
                cout << "EXCEPTION:" << l.what();
            }
        } while (p <= 0);
    }

    void setdetails(int p, string t)
    {
        title = t;
        try
        {
            if (p <= 0)

                throw logic_error("INVALID PAGE NO!");

            pages = p;
        }
        catch (const logic_error &l)
        {
            cout << "EXCEPTION:" << l.what();
        }
    }

    void displaybook()
    {

        cout << "|BOOK-TITLE:" << title << "|BOOK-PAGES:" << pages << "|" << endl;
    }
};

// create a class librarian with
// name string
// req:
// constructor to initialize name
// a fuction displayLibrarian to display librarian details

class librarian
{
    string name;

public:
    librarian() : name("UNKNOWN") {}
    librarian(string n) : name(n) {}

    void setname(string n) { name = n; }
    string getname() { return name; }

    void displaylibrarian()
    {
        cout << "====LIBRARIAN DETAILS=====" << endl;
        cout << "|LIBRARIAN NAME:" << name << "|" << endl;
    }
};

// create a class library
// this class represent library system, it should contain
// book objects(max 5)
// a ref pointer to librarian

// include appro. functions for
// add a book and display library details

class library
{
    string libname;
    Book bk[5];
    librarian *libptr;
    int bookcount;

public:
    library() : libname("N/R"), bookcount(0)
    {
        libptr = nullptr;
    }
    library(string libname, librarian *l) : libname(libname), bookcount(0)
    {
        libptr = l;
    }

    void addbooks(string title, int pages)
    {
        try
        {
            if (bookcount >= 5)
            {
                throw runtime_error("CAPACITY FULL");
            }

            bk[bookcount].setdetails(pages, title);
            bookcount++;
            cout << "BOOK ADDED!" << endl;
        }
        catch (const runtime_error &r)
        {
            cout << "EXCEPTION:" << r.what() << endl;
        }
    }

    void removebook(string title)
    {
        try
        {
            if (bookcount == 0)
            {
                throw runtime_error("NO BOOKS IN LIBRARY!");
            }

            for (int i = 0; i < bookcount; i++)
            {
                if (bk[i].gettitle() == title)
                {
                    for (int j = i; j < bookcount - 1; j++)
                    {
                        bk[j] = bk[j + 1];
                    }
                    bookcount--;
                    cout << "BOOK REMOVED!" << endl;
                    return;
                }
            }
        }
        catch (const runtime_error &r)
        {
            cout << "EXCEPTION:" << r.what() << endl;
        }

        cout << "BOOK NOT FOUND!" << endl;
    }

    void displaylibrarydetails()
    {
        try
        {
            if (bookcount == 0)
            {
                cout << "====LIBRARY DETAILS====" << endl;
                libptr->displaylibrarian();
                throw runtime_error("NO BOOKS IN LIBRARY!");
            }
        }
        catch (const runtime_error &r)
        {
            cout << "EXCEPTION:" << r.what() << endl;
        }

        cout << "====LIBRARY DETAILS====" << endl;
        libptr->displaylibrarian();
        cout << "===BOOK-LIST====" << endl;
        for (int i = 0; i < bookcount; i++)
        {
            bk[i].displaybook();
        }
    }
};

// in main()
// create required objects
// provide necessary function calls to
// add books(at least 3)
// display system  information

int main()
{
    librarian l("ANWAR");
    library L1("NED LIBRARY", &l);
    L1.addbooks("LORD OF RINGS", 300);
    L1.addbooks("HARRY POTTER", 500);
    L1.addbooks("NARNIA", 1000);
    L1.addbooks("SECRET GARDEN", -98);

    L1.displaylibrarydetails();
    L1.removebook("HARRY POTTER");
    L1.displaylibrarydetails();

    return 0;
}
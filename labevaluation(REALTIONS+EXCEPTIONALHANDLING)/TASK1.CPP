#include <iostream>
using namespace std;
// create a class book with the following attributes
// title string
// pages int

// req:
// constructor to initialize data members
// getter functions for all members
// a function displaybook() to print book details

// create a class librarian with
// name string
// req:
// constructor to initialize name
// a fuction displayLibrarian to display librarian details

// create a class library
// this class represent library system, it should contain
// book objects(max 5)
// a ref pointer to librarian

// include appro. functions for
// add a book and display library details

// in main()
// create required objects
// provide necessary function calls to
// add books(at least 3)
// display system  information

// exception handling
// handle the invalid input using standard C++ exception classes
// ensure that:
// book data must be valid(pages not less than or equal to 0, title not empty)
// approp. error messages are displayed when invalid data is provided
class book
{
private:
    string title;
    int pages;

public:
    book()
    {
        title = "N/A";
        pages = 0;
    }
    book(string title, int pages)
    {
        this->title = title;
        this->pages = pages;
    }
    string gettitle()
    {
        return title;
    }
    int pages()
    {
        return pages;
    }
    void displaybook()
    {
        cout << "BOOK TITLE:" << title << endl;
        cout << "PAGES:" << pages << endl;
    }
    void setpages(int p)
    {
        if (p < 0)
        {
            throw(-1);
        }
        else
        {
            pages = p;
        }
    }
    void settitle(string Title)
    {
        if (Title == "")
        {
            throw("ERROR:Invalid TITLE");
        }
        else
        {
            title = Title;
        }
    }
};
class librarian
{
private:
    string name;

public:
    librarian()
    {
        name = "NULL";
    }
    librarian(string name)
    {
        this->name = name;
    }
    string getlibrarianname()
    {
        return name;
    }
    void displaylibrarian()
    {
        cout << "LIBRARIAN:" << getlibrarianname() << endl;
    }
    void setlibrarianame(string name)
    {
        if (name == "")
        {
            throw("INVVALID NAME");
        }
        else
        {
            this->name = name;
        }
    }
};
class library
{
    book books[5];
    int counter;
    librarian *lbn;

public:
    library(librarian *librarianname)
    {
        lbn = librarianname;
        counter = 0;
    }
    // void input()
    // {
    //     try
    //     {
    //         string n;
    //         cout << "ENTER LIBRARIAN NAME:" << endl;
    //         cin >> n;
    //         lbn->setlibrarianame(n);
    //     }
    //     catch (const char *msg)
    //     {
    //         cout << msg << endl;
    //     }
    //     try
    //     {
    //         cout << "ENTER 5 BOOKS";
    //     }}

    void addbooks(string title, int pages)
    {
        if (counter < 5)
        {
            books[counter] = book(title, pages);
            try
            {
                books[counter].setpages(pages);
            }
            catch (int m)
            {
                cout << "ERROR:NEGATIVE PAGES NOT ALLOWED" << endl;
            }
            try
            {
                books[counter].settitle(title);
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
        }
        ++counter;
    }
    void displayall()
    {
        lbn->displaylibrarian();
        cout << "BOOKS:" << endl;
        for (int i = 0; i < counter; i++)
        {
            books[i].displaybook();
        }
    }
};
int main()
{
    librarian lbn("ali");

    library l1(&lbn);

    l1.addbooks("a", 1);
    l1.addbooks("b", 2);
    l1.addbooks("c", 3);
    l1.addbooks("d", 4);
    l1.addbooks("e", 5);
    l1.displayall();

    return 0;
}
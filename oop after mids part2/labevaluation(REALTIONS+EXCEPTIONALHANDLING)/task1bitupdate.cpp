#include <iostream>
using namespace std;
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
    int getpages()
    {
        return pages;
    }
    void displaybook()
    {
        cout << "BOOK TITLE:" << gettitle() << endl;
        cout << "PAGES:" << getpages() << endl;
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
        try
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
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }
    string getlibrarianname()
    {
        return name;
    }
    void displaylibrarian()
    {
        cout << "LIBRARIAN:" << getlibrarianname() << endl;
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

    void addbooks(string title, int pages)
    {
        if (counter < 5)
        {
            try
            {
                if (pages < 0)
                {
                    throw("INVALID pagenum");
                }
                else if (title == "")
                {
                    throw("INVALID title");
                }
                else
                {

                    books[counter++] = book(title, pages);
                }
            }
            catch (const char *msg)
            {
                cout << "ERROR:NEGATIVE PAGES NOT ALLOWED" << endl;
            }
        }
        else
        {
            cout << "LIBRARY IS FULL" << endl;
        }
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
    librarian lbn("");

    library l1(&lbn);

    l1.addbooks("a", -1);
    l1.addbooks("b", 2);
    l1.addbooks("c", 3);
    l1.addbooks("d", 4);
    l1.addbooks("e", 5);
    l1.displayall();

    return 0;
}
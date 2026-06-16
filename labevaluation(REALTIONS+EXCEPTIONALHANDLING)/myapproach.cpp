#include <iostream>
#include <cstring>
using namespace std;
class book
{
private:
    char *title;
    int pages;

public:
    book()
    {
        title = new char[5];
        strcpy(title, "N/A");
        pages = 0;
    }
    book(char *T, int pages)
    {
        title = new char[strlen(T) + 1];
        strcpy(title, T);
        this->pages = pages;
    }
    char *gettitle()
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
};
class librarian
{
private:
    char *name;

public:
    librarian()
    {
        name = new char[5];
        strcpy(name, "N/A");
    }
    librarian(char *n)
    {
        try
        {
            if (n == nullptr || n[0] == '\0')
            {
                throw("INVVALID NAME");
            }

            name = new char[strlen(n) + 1];
            strcpy(name, n);
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }
    char *getlibrarianname()
    {
        return name;
    }
    void displaylibrarian()
    {
        cout << "LIBRARIAN:" << getlibrarianname() << endl;
    }
    ~librarian()
    {
        delete[] name;
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

    void addbooks(char *title, int pages)
    {
        if (counter < 5)
        {
            try
            {
                if (pages < 0)
                {
                    throw("INVALID PAGENUMBER");
                }
                if (title == "")
                {
                    throw("INVALID TITLE");
                }

                books[counter++] = book(title, pages);
            }
            catch (const char *msg)
            {
                cout << "ERROR:" << msg << endl;
            }
        }
        else
        {
            cout << "LIBRARY IS FULL" << endl;
        }
    }
    void removebooks(string title, int pages)
    {
        for (int i = 0; i < counter; i++)
        {
            if ((books[i].gettitle() == title) && (books[i].getpages() == pages))
            {
                for (int j = i; j < counter - 1; j++)
                {
                    books[j] = books[j + 1];
                }
                --counter;
            }
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
    librarian lbn("ali");

    library l1(&lbn);

    l1.addbooks("a", -1);
    l1.addbooks("b", 2);
    l1.addbooks("c", 3);
    l1.removebooks("c", 3);
    l1.addbooks("d", 4);
    l1.addbooks("e", 5);
    l1.displayall();

    return 0;
}
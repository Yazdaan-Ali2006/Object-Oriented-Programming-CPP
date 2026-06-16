#include <iostream>
#include <stdexcept>
using namespace std;

#define SIZE 5

class Book {
private:
    string title;
    int pages;

public:
    Book() = default;

    Book(string t, int p) {
        title = t;
        pages = p;
    }

    string getTitle() {
        return title;
    }

    int getPages() {
        return pages;
    }

    void set_details(const string& t, int p) {
        if (t.empty()) {
            throw invalid_argument("Error: Title cannot be empty.");
        }
        if (p <= 0) {
            throw invalid_argument("Error: Pages must be greater than zero.");
        }
        title = t;
        pages = p;
    }

    void displayBook() {
        cout << "Title: " << title << endl;
        cout << "Pages: " << pages << endl;
    }
};

class Librarian {
private:
    string name;

public:
    Librarian() = default;

    Librarian(string n) {
        name = n;
    }

    string getName() {
        return name;
    }


    void displayLibrarian() {
        cout << "Librarian Name: " << name << endl;
    }
};

class Library
{
    private:
        Book books[SIZE];
        Librarian* librarian;
        int index;
    public:
        Library()
        {
            librarian = nullptr;
            index = 0;
        }

         void addBook() {
            if (index >= SIZE) {
                cout << "Catalog is full." << endl;
                return;
            }

            try {
                cout << "Enter book title: ";
                string title;
                getline(cin >> ws, title);

                cout << "Enter pages: ";
                int pages;
                cin >> pages;

                books[index].set_details(title, pages);
                index++;
            }
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

        void displayDetails()
        {
            if (librarian)
            {
                cout << "---------------------\n";
                cout << "Librarian Name: " << librarian->getName();
                cout << "---------------------\n";
            }
            for (int i = 0; i < SIZE; ++i)
            {
                cout << "--------------------\n";
                books[i].displayBook();
                cout << "--------------------\n";
            }
        }

        void addLibrarian(Librarian* l)
        {
            if (l) librarian = l;
        }
};

int main() {
    Librarian* librarian = new Librarian("Dr. Xyz");

    Library library;
    library.addLibrarian(librarian);

    library.addBook();
    library.addBook();
    library.addBook();
    library.addBook();
    library.addBook();

    library.displayDetails();

    return 0;
}
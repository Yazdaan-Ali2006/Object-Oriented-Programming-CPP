
/*Question: Library System
Description:
Create a Book class with attributes: title and author. 



Create a Library class that owns books (composition) and can lend books to members (aggregation).
Create a Member class that can borrow books from Library (aggregation).
Requirements:
Library should store multiple Book objects inside it. This is composition because books belong to the library.
Member can borrow books from Library using a pointer/reference to Book. 
This is aggregation because a member uses a book but does not own it.*/
#include <iostream>
using namespace std;

class Book
{
public:
    string title;
    string author;

    Book(string t, string a)
    {
        title = t;
        author = a;
    }
};

class Library
{
private:
    Book books[3];   // Composition: Library owns books

public:
    Library() : books{
        Book("C++ Basics","Bjarne"),
        Book("Data Structures","Mark"),
        Book("Algorithms","CLRS")
    }
    {
        cout << "Library created with books:" << endl;
        for(int i=0;i<3;i++)
        {
            cout << books[i].title << endl;
        }
        
    }

    Book* lendBook(int index)
    {
        return &books[index];   // returning address (aggregation use)
    }
};

class Member
{
public:
    string name;

    Member(string n)
    {
        name = n;
    }

    void borrowBook(Book* b)
    {
        cout << name << " borrowed " << b->title << endl;
    }
};

int main()
{
    Library lib;        // Library created (books created with it)

    Member m1("John");
    Member m2("Alice");

    Book* b1 = lib.lendBook(0);
    Book* b2 = lib.lendBook(1);

    m1.borrowBook(b1);   // Aggregation
    m2.borrowBook(b2);   // Aggregation

    return 0;
}
#include <iostream>
using namespace std;

class book
{
public:
    string title;
    string author;
    book(string t = "null", string b = "null") : title(t), author(b) {}
};

class lib
{
public:
    book books[3];

    lib() : books{book("good", "ali"), book("bad", "areeb"), book("nice", "aliza")}
    {
        cout << "OBJ CREATED..." << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "BOOK: " << i + 1 << endl;
            cout << "|BOOK:" << books[i].title << "| |AUTHOR:" << books[i].author << endl;
        }
    }
    book *lendbook(int index)
    {
        return &books[index];
    }
};
class member
{
public:
    string name;
    member(string n)
    {
        name = n;
    }
    void borrow(book *b1)
    {
        cout << "borrowed book is:" << b1->title << endl;
    }
};
int main()
{
    lib l1;
    member m1("ali");
    member m2("aliza");
    book *b1 = l1.lendbook(0);
    book *b2 = l1.lendbook(1);

    m1.borrow(b1);
    m2.borrow(b2);

    return 0;
}
#include <iostream>
using namespace std;
class Book
{
private:
    string title;
    string author;

public:
    Book() : title("none"), author("none") {}
    Book(string t, string a) : title(t), author(a) {}

    void display()
    {
        cout << "TITLE:" << title << endl;
        cout << "AUTHOR:" << author << endl;
    }
    string getauthor()
    {
        return author;
    }
    string gettitle()
    {
        return title;
    }
};
class Library
{
    string library_name;
    Book books[5];
    int bookcounter;

public:
    Library(string name)
    {
        bookcounter = 0;
        library_name = name;
    }
    void addbooks(string t, string a)
    {
        if (bookcounter < 5)
        {
            books[bookcounter++] = Book(t, a);
        }
        else
        {
            cout << "ERROR:LIBRARY IS FULL" << endl;
        }
    }
    void removebook(string t, string a)
    {
        for (int i = 0; i < bookcounter; i++)
        {
            if ((a== books[i].getauthor())&&(t== books[i].gettitle()))
            {
                for(int j=i;j<bookcounter-1;j++){
                    books[j]=books[j+1];
                }
                --bookcounter;

            }

        }
    } // friend ostream &operator<<(ostream &o, const Engine e)
   
    friend ostream &operator<<(ostream &o,Library l)
    {
        o << "LIBRARY:" << l.library_name << endl;
        o << "TOTAL BOOKS:" << l.bookcounter << endl;
        o << "=============DISPLAYING BOOKS===========" << endl;
        for (int i = 0; i < l.bookcounter; i++)
        {
            o << "BOOK NO." << i + 1 << " ";
            l.books[i].display();
        }
    }
};

int main()
{
    Library l1("ABC LIBRARY");
    l1.addbooks("coding c", "ali");
    l1.addbooks("coding java", "aoun");
    l1.addbooks("coding python", "harry");
    cout<<l1;
    l1.removebook("coding python", "harry");
    cout<<l1;
    return 0;
}
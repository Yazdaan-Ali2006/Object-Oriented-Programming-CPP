#include <iostream>
#include <string>
#include <stdexcept> // For exception handling
using namespace std;

// ======================
// Abstract User Class
// ======================
class User {
protected:
    int userID;
    string name;
    string email;
public:
    User(int id, string n, string e) {
        userID = id; name = n; email = e;
    }
    virtual void viewProfile() = 0;      // pure virtual
    virtual int getBorrowLimit() = 0;    // pure virtual
    int getID() { return userID; }
    virtual ~User() {}
};

// ======================
// Derived User Classes
// ======================
class Student : public User {
private:
    string department;
public:
    Student(int id, string n, string e, string dept)
        : User(id, n, e) { department = dept; }

    int getBorrowLimit() override { return 3; }

    void viewProfile() override {
        cout << "Student: " << name << ", Email: " << email
             << ", Dept: " << department << endl;
    }
};

class Faculty : public User {
private:
    string department;
    string designation;
public:
    Faculty(int id, string n, string e, string dept, string desig)
        : User(id, n, e) { department = dept; designation = desig; }

    int getBorrowLimit() override { return 10; }

    void viewProfile() override {
        cout << "Faculty: " << name << ", Email: " << email
             << ", Dept: " << department << ", Designation: " << designation << endl;
    }
};

class Guest : public User {
private:
    string purpose;
public:
    Guest(int id, string n, string e, string purp)
        : User(id, n, e) { purpose = purp; }

    int getBorrowLimit() override { return 1; }

    void viewProfile() override {
        cout << "Guest: " << name << ", Email: " << email
             << ", Purpose: " << purpose << endl;
    }
};

// ======================
// Book Class
// ======================
class Book {
private:
    int bookID;
    string title;
    string author;
    string category;
    bool availability;
public:
    Book() { availability = true; }
    Book(int id, string t, string a, string c) {
        bookID = id; title = t; author = a; category = c; availability = true;
    }
    int getID() { return bookID; }
    string getTitle() { return title; }
    bool isAvailable() { return availability; }
    void setAvailability(bool status) { availability = status; }
    void displayInfo() {
        cout << "ID: " << bookID << ", Title: " << title
             << ", Author: " << author
             << ", Category: " << category
             << ", Available: " << (availability ? "Yes" : "No") << endl;
    }
};

// ======================
// Fine Class
// ======================
class Fine {
private:
    double fineAmount;
public:
    void calculateFine(int daysLate) {
        if (daysLate <= 0) fineAmount = 0;
        else fineAmount = daysLate * 5;  // 5 per day
        cout << "Fine Amount: " << fineAmount << endl;
    }
};

// ======================
// Transaction Class
// ======================
class Transaction {
private:
    int transactionID;
    Book* book;
    User* user;
    string issueDate;
    string returnDate;
    Fine fine;  // composition
public:
    Transaction() {}
    Transaction(int tid, Book* b, User* u, string issue) {
        transactionID = tid;
        book = b;
        user = u;
        issueDate = issue;
        book->setAvailability(false);
    }

    void returnBook(string retDate, int daysLate) {
        returnDate = retDate;
        book->setAvailability(true);
        cout << "Book Returned. ";
        fine.calculateFine(daysLate);
    }

    void displayTransaction() {
        cout << "Transaction ID: " << transactionID
             << ", Book: " << book->getTitle()
             << ", UserID: " << user->getID() << endl;
    }
};

// ======================
// BookCatalog Class
// ======================
class BookCatalog {
private:
    Book* books[100];
    int count;
public:
    BookCatalog() { count = 0; }
    void addBook(Book* b) { books[count++] = b; }
    void searchByTitle(string title) {
        cout << "Search Results for '" << title << "':" << endl;
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (books[i]->getTitle() == title) {
                books[i]->displayInfo();
                found = true;
            }
        }
        if (!found) cout << "No books found with this title." << endl;
    }
};

// ======================
// Library Class
// ======================
class Library {
private:
    Book bookList[100];
    int bookCount;
    User* userList[50];
    int userCount;
    Transaction transactionList[100];
    int transactionCount;
    BookCatalog catalog;
public:
    Library() { bookCount = 0; userCount = 0; transactionCount = 0; }

    void addBook(Book b) {
        if (bookCount >= 100) throw overflow_error("Book limit reached!");
        bookList[bookCount] = b;
        catalog.addBook(&bookList[bookCount]);
        bookCount++;
        cout << "Book Added: " << b.getTitle() << endl;
    }

    void registerUser(User* u) {
        if (userCount >= 50) throw overflow_error("User limit reached!");
        userList[userCount++] = u;
        cout << "User Registered: ID " << u->getID() << endl;
    }

    void searchBook(string title) {
        catalog.searchByTitle(title);
    }

    void issueBook(int transactionID, int userID, int bookID, string issueDate) {
        try {
            User* u = nullptr;
            Book* b = nullptr;

            for (int i = 0; i < userCount; i++)
                if (userList[i]->getID() == userID) u = userList[i];

            for (int i = 0; i < bookCount; i++)
                if (bookList[i].getID() == bookID) b = &bookList[i];

            if (!u) throw runtime_error("User not found!");
            if (!b) throw runtime_error("Book not found!");
            if (!b->isAvailable()) throw runtime_error("Book not available!");

            transactionList[transactionCount++] = Transaction(transactionID, b, u, issueDate);
            cout << "Book Issued: " << b->getTitle() << " to User ID: " << userID << endl;

        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void returnBook(int transactionID, string returnDate, int daysLate) {
        try {
            if (transactionID >= transactionCount) throw out_of_range("Transaction not found!");
            transactionList[transactionID].returnBook(returnDate, daysLate);
        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void displayAllTransactions() {
        cout << "\nAll Transactions:\n";
        for (int i = 0; i < transactionCount; i++) {
            transactionList[i].displayTransaction();
        }
    }
};

// ======================
// Main Function with Menu
// ======================
int main() {
    Library lib;
    int choice;
    int transactionID = 0;

    while (true) {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n2. Register User\n3. Search Book\n";
        cout << "4. Issue Book\n5. Return Book\n6. Show Transactions\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                int id; string title, author, category;
                cout << "Book ID: "; cin >> id;
                cin.ignore();
                cout << "Title: "; getline(cin, title);
                cout << "Author: "; getline(cin, author);
                cout << "Category: "; getline(cin, category);
                lib.addBook(Book(id, title, author, category));
            }
            else if (choice == 2) {
                int type, id; string name, email, extra1, extra2;
                cout << "User Type (1=Student, 2=Faculty, 3=Guest): "; cin >> type;
                cout << "User ID: "; cin >> id;
                cin.ignore();
                cout << "Name: "; getline(cin, name);
                cout << "Email: "; getline(cin, email);
                if (type == 1) { cout << "Department: "; getline(cin, extra1); lib.registerUser(new Student(id, name, email, extra1)); }
                else if (type == 2) { cout << "Department: "; getline(cin, extra1); cout << "Designation: "; getline(cin, extra2); lib.registerUser(new Faculty(id, name, email, extra1, extra2)); }
                else if (type == 3) { cout << "Purpose: "; getline(cin, extra1); lib.registerUser(new Guest(id, name, email, extra1)); }
            }
            else if (choice == 3) {
                string title; cin.ignore(); cout << "Enter book title to search: "; getline(cin, title);
                lib.searchBook(title);
            }
            else if (choice == 4) {
                int userID, bookID; string issueDate;
                cout << "User ID: "; cin >> userID;
                cout << "Book ID: "; cin >> bookID;
                cin.ignore();
                cout << "Issue Date (YYYY-MM-DD): "; getline(cin, issueDate);
                lib.issueBook(transactionID++, userID, bookID, issueDate);
            }
            else if (choice == 5) {
                int tid, daysLate; string returnDate;
                cout << "Transaction ID: "; cin >> tid;
                cin.ignore();
                cout << "Return Date (YYYY-MM-DD): "; getline(cin, returnDate);
                cout << "Days Late: "; cin >> daysLate;
                lib.returnBook(tid, returnDate, daysLate);
            }
            else if (choice == 6) {
                lib.displayAllTransactions();
            }
            else if (choice == 7) {
                cout << "Exiting system.\n"; break;
            }
            else {
                cout << "Invalid choice!\n";
            }
        }
        catch (exception &e) {
            cout << "Exception caught: " << e.what() << endl;
        }
    }

    return 0;
}
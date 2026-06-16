#include <iostream>
using namespace std;

class book;
class Transaction;
class Fines;
class librarian;
class BookCatalog;
class User;
class User

{
protected:
    int userid;
    string name;
    string CNIC;
    string email;
    string phonenumber;
    int borrowedbook[20];
    int borrowedbookcount = 0;

public:
    User(int id, string n = "NONE", string c = "xxxxx-xxxxxxx-x", string e = "abc@gmail.com", string p = "03xxxxxxxxx", int bcount = 0, int bb[20] = nullptr)
        : userid(id), name(n), CNIC(c), email(e), phonenumber(p), borrowedbookcount(bcount)
    {
        for (int i = 0; i < 20; i++)
            borrowedbook[i] = 0; // assign all to 0
    }

    virtual ~User() { cout << "User " << name << " destroyed." << endl; }
    // SETTERS
    void setid(int id) { userid = id; }
    void setname(string n) { name = n; }
    void setemail(string e) { email = e; }
    void setphone_no(string p) { phonenumber = p; }
    void setCNIC(string c) { CNIC = c; }
    // GETTERS
    int get_userid() { return userid; }
    string get_name() { return name; }
    string get_email() { return email; }
    string get_phone() { return phonenumber; }
    string get_cnic() { return CNIC; }

    // Pure virtual functions
    virtual int getborrowlimit() = 0;
    virtual string get_usertype() = 0;
    virtual void viewdetails() = 0;
    virtual int getFineRate() = 0;

    // MENUS
    void menudetails()
    {
        cout << "PRESS 1: BORROWED BOOKS" << endl
             << "PRESS 2: FINES" << endl
             << "PRESS 3:EXIT" << endl;
    }

    void menuborrowedbooks()
    {
        cout << "PRESS 1: SEARCH BY ID" << endl
             << "PRESS 2: SEARCH BY TITLE" << endl
             << "PRESS 3: SEARCH BY AUTHOR" << endl
             << "PRESS 4: SEARCH BY PUBLISHER" << endl
             << "PRESS 5: SEARCH BY CATEGORY" << endl
             << "PRESS 6: SEARCH BY YEAR OF PUBLICATION" << endl
             << "PRESS 7: EXIT" << endl;
    }
    // BOOKS
    bool borrowbook(int id)
    {
        if (borrowedbookcount < getborrowlimit())
        {
            borrowedbook[borrowedbookcount++] = id;
            return true;
        }
        cout << "Borrow limit reached!" << endl;
        return false;
    }

    bool returnbook(int id)
    {
        for (int i = 0; i < borrowedbookcount; i++)
        {
            if (borrowedbook[i] == id)
            {
                for (int j = i; j < borrowedbookcount - 1; j++)
                    borrowedbook[j] = borrowedbook[j + 1];
                borrowedbookcount--;
                return true;
            }
        }
        cout << "Book not borrowed by this user!" << endl;
        return false;
    }

    // ---------------- Register User ----------------
    static User *registerUser();

};

// ---------------- Student ----------------
class Student : public User
{
private:
    string seatno;
    string major;

public:
    Student(int id, string n, string c, string e, string p, string s, string m)
        : User(id, n, c, e, p), seatno(s), major(m) {}

    int getborrowlimit() override { return 3; }
    string get_usertype() override { return "STUDENT"; }

    void viewdetails() override
    {
        cout << "|NAME: " << name
             << " |SEAT: " << seatno
             << " |MAJOR: " << major
             << " |TYPE: STUDENT|" << endl;
    }
    int getFineRate()
    {
        return 10;
    }
};

// ---------------- Faculty ----------------
class Faculty : public User
{
private:
    string department;
    string designation;

public:
    Faculty(int id, string n, string c, string e, string p, string dept, string des)
        : User(id, n, c, e, p), department(dept), designation(des) {}

    int getborrowlimit() override { return 5; }
    string get_usertype() override { return "FACULTY"; }

    void viewdetails() override
    {
        cout << "|NAME: " << name
             << " |DEPARTMENT: " << department
             << " |DESIGNATION: " << designation
             << " |TYPE: FACULTY|" << endl;
    }
    int getFineRate()
    {
        return 15;
    }
};

// ---------------- Guest ----------------
class Guest : public User
{
private:
    string purpose;

public:
    Guest(int id, string n, string c, string e, string p, string ps)
        : User(id, n, c, e, p), purpose(ps) {}

    int getborrowlimit() override { return 1; }
    string get_usertype() override { return "GUEST"; }

    void viewdetails() override
    {
        cout << "|NAME: " << name
             << " |PURPOSE: " << purpose
             << " |TYPE: GUEST|" << endl;
    }
    int getFineRate()
    {
        return 20;
    }

      
};
User* User::registerUser(){  int choice;
        cout << "Select User Type:\n1. Student\n2. Faculty\n3. Guest\nChoice: ";
        cin >> choice;
        cin.ignore();

        string name, CNIC, email, phone;
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter CNIC: ";
        getline(cin, CNIC);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Phone: ";
        getline(cin, phone);

        if (choice == 1) // Student
        {
            string seat, major;
            int id;
            cout << "Enter id:";
            cin >> id;
            cout << "Enter Seat Number: ";
            getline(cin, seat);
            cout << "Enter Major: ";
            getline(cin, major);

            return new Student(id, name, CNIC, email, phone, seat, major);
        }
        else if (choice == 2) // Faculty
        {
            string dept, des;
            int id;
            cout << "Enter id:";
            cin >> id;
            cout << "Enter Department: ";
            getline(cin, dept);
            cout << "Enter Designation: ";
            getline(cin, des);
            return new Faculty(id, name, CNIC, email, phone, dept, des);
        }
        else if (choice == 3) // Guest
        {
            string purpose;
            int id;
            cout << "Enter id:";
            cin >> id;
            cout << "Enter Purpose: ";
            getline(cin, purpose);
            return new Guest(id, name, CNIC, email, phone, purpose);
        }
        else
        {
            cout << "Invalid choice!\n";
            return nullptr;
        }
    }

class Book
{
private:
    int bookid;
    string title;
    string author;
    string category;
    string ISBN;
    string publisher;
    int year_of_publication;
    int available_copies = 0;
    bool avalaibility_status;
    int download_count = 0;
    int read_onsite_count = 0;
    int timesborrowed_count = 0;

public:
    // CONSTRUCTOR
    Book() : bookid(0), title("UNKNOWN"), author("UNKNOWN"), category("UNKNOWN"), ISBN("UNKNOWN"), publisher("UNKNOWN"), year_of_publication(0),
             avalaibility_status(false), download_count(0), read_onsite_count(0), timesborrowed_count(0) {}
    Book(int id, string t, string a, string c, string isbn, string p, int yop) : bookid(id), title(t), author(a), category(c), ISBN(isbn), publisher(p), year_of_publication(yop),
                                                                                 avalaibility_status(false), download_count(0), read_onsite_count(0), timesborrowed_count(0) {}

    // DESTRUCTOR
    ~Book() { cout << "BOOK DESTROYED!" << endl; }

    // GETTERS
    int get_bookid() { return bookid; }
    string get_title() { return title; }
    string get_author() { return author; }
    string get_category() { return category; }
    string get_isbn() { return ISBN; }
    string get_publisher() { return publisher; }
    int get_YOP() { return year_of_publication; }
    int getAvailableCopies() { return available_copies; }
    int get_downloadcount() { return download_count; }
    int get_read_onsitecount() { return read_onsite_count; }
    int get_timesborrowed_count() { return timesborrowed_count; }

    // SETTERS
    void set_bookid(int id) { bookid = id; }
    void set_author(string a) { author = a; }
    void set_title(string t) { title = t; }
    void set_category(string c) { category = c; }
    void set_isbn(string isbn) { ISBN = isbn; }
    void set_publisher(string p) { publisher = p; }
    void set_YOP(int yop) { year_of_publication = yop; }
    void setAvailableCopies(int ac) { available_copies = ac; }

    // FUNCTIONS
    void display()
    {
        cout << "BOOK ID:" << bookid << endl
             << "TITLE:" << title << endl
             << "AUTHOR:" << author << endl
             << "CATEGORY:" << category << endl
             << "ISBN:" << ISBN << endl
             << "PUBLISHER:" << publisher << endl
             << "YEAR OF PUBLICATION:" << year_of_publication << endl
             << "DOWNLOADED:" << download_count << "times" << endl
             << "READ ON SITE:" << read_onsite_count << "times" << endl
             << "TIMES BORROWED:" << timesborrowed_count << "times" << endl;
        cout << "-----------------------------------------------------" << endl;
    }
};

class BookCatalog
{
private:
    Book *BK[100];
    int book_count = 0;

public:
    BookCatalog() : book_count(0) {}
    ~BookCatalog() { cout << "BOOKCATALOG DESTROYED!" << endl; }

    void addbook(Book *b)
    {
        if (book_count < 100)
        {
            BK[book_count] = b;
            book_count++;
            cout << "BOOK ADDED SUCCESSFULLY!" << endl;
        }
        else
            cout << "LIBRARY FULL!" << endl;
    }

    void removeBook(string t)
    {
        int pos = -1;
        if (book_count == 0)
        {
            cout << "NO BOOKS IN CATALOG!" << endl;
            return;
        }
        for (int i = 0; i < book_count; i++)
        {
            if (BK[i]->get_title() == t)
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            cout << "BOOK NOT FOUND!" << endl;
            return;
        }
        for (int i = pos; i < book_count - 1; i++)
            BK[i] = BK[i + 1];
        delete BK[pos];
        book_count--;
        cout << "BOOK REMOVED!" << endl;
    }

    Book *SearchbyID(int id)
    {
        if (book_count == 0)
        {
            cout << "NO BOOKS IN CATALOG!" << endl;
            return nullptr;
        }
        for (int i = 0; i < book_count; i++)
        {
            if (BK[i]->get_bookid() == id)
            {
                return BK[i];
            }
        }

        cout << "BOOK NOT FOUND!" << endl;
        return nullptr;
    }

    Book *SearchbyTitle(string t)
    {
        if (book_count == 0)
        {
            cout << "NO BOOKS IN CATALOG!" << endl;
            return nullptr;
        }
        for (int i = 0; i < book_count; i++)
        {
            if (BK[i]->get_title() == t)
            {
                return BK[i];
            }
        }

        cout << "BOOK NOT FOUND!" << endl;
        return nullptr;
    }

    Book *SearchbyAuthor(string a)
    {
        if (book_count == 0)
        {
            cout << "NO BOOKS IN CATALOG!" << endl;
            return nullptr;
        }
        for (int i = 0; i < book_count; i++)
        {
            if (BK[i]->get_author() == a)
            {
                return BK[i];
            }
        }

        cout << "BOOK NOT FOUND!" << endl;
        return nullptr;
    }

    Book *SearchbyCategory(string c)
    {
        if (book_count == 0)
        {
            cout << "NO BOOKS IN CATALOG!" << endl;
            return nullptr;
        }
        for (int i = 0; i < book_count; i++)
        {
            if (BK[i]->get_category() == c)
            {
                return BK[i];
            }
        }

        cout << "BOOK NOT FOUND!" << endl;
        return nullptr;
    }

    Book *SearchbyPublisher(string p)
    {
        if (book_count == 0)
        {
            cout << "NO BOOKS IN CATALOG!" << endl;
            return nullptr;
        }
        for (int i = 0; i < book_count; i++)
        {
            if (BK[i]->get_publisher() == p)
            {
                return BK[i];
            }
        }

        cout << "BOOK NOT FOUND!" << endl;
        return nullptr;
    }

    Book *SearchbyYOP(int yop)
    {
        if (book_count == 0)
        {
            cout << "NO BOOKS IN CATALOG!" << endl;
            return nullptr;
        }
        for (int i = 0; i < book_count; i++)
        {
            if (BK[i]->get_YOP() == yop)
            {
                return BK[i];
            }
        }

        cout << "BOOK NOT FOUND!" << endl;
        return nullptr;
    }

    void ViewBookCatalog() const
    {
        if (book_count == 0)
        {
            cout << "NO BOOKS IN CATALOG!" << endl;
            return;
        }
        cout << "====BOOK CATALOG====" << endl;
        for (int i = 0; i < book_count; i++)
        {
            BK[i]->display();
        }
    }

    // GETTERS
    int get_bookcount() { return book_count; }
};

class librarian
{
private:
    int librarian_id;
    string name;
    string email;
    string phone_no;

public:
    // CONSTRUCTOR
    librarian() : librarian_id(0), name("UNKNOWN"), email("UNKNOWN"), phone_no("UNKNOWN") {}
    librarian(int id, string n, string e, string p) : librarian_id(id), name(n), email(e), phone_no(p) {}

    // DESTRUCTOR
    ~librarian() { cout << "LIBRARIAN DESTROYED!" << endl; }

    void addbook(Book *b, BookCatalog *catalog)
    {
        catalog->addbook(b);
    }

    void removeBook(string t, BookCatalog *catalog)
    {
        catalog->removeBook(t);
    }

    void displaylibrarian_details()
    {
        cout << "ID:" << librarian_id << endl
             << "NAME:" << name << endl
             << "EMAIL:" << email << endl
             << "PHONE#:" << endl;
    }
};

class Transaction
{
private:
    int transaction_id;
    int user_id;
    int book_id;
    string issue_date;
    string return_date;
    string due_date;
    bool returned;

public:
    // CONSTRUCTOR
    Transaction() : transaction_id(0), user_id(0), book_id(0), issue_date("UNKNOWN"), return_date("UNKNOWN"), due_date("UNKNOWN") {}
    Transaction(int uid, int bid, string i, string d) : transaction_id(0), user_id(uid), book_id(bid), issue_date(i), due_date(d) {}

    // DESTRUCTOR
    ~Transaction() { cout << "TRANSACTION DESTROYED!" << endl; }

    // GETTERS
    int getuserid() { return user_id; }
    int getbookid() { return book_id; }
    string getissuedate() { return issue_date; }
    string getduedate() { return due_date; }
    // SETTERS
    void setIssueDate(string i) { issue_date = i; }
    void setDueDate(string d) { due_date = d; }
    void markreturned() { returned = true; }
    // FUNCTIONS


    void displayuser(int id)
    {
        if (user_id = id)
        {
            cout << "|TRANSACTION ID:" << transaction_id << "|USER ID:" << user_id << "|BOOK ID" << book_id << "|ISSUE DATE:" << issue_date << "|DUE DATE:" << due_date << "|RETURNED: " << (returned ? "YES" : "NO") << " |" << endl;
        }
    }

    void displayAll()
    {
        cout << "|USER ID: " << user_id
             << " |BOOK ID: " << book_id
             << " |ISSUE DATE: " << issue_date
             << " |DUE DATE: " << due_date
             << " |RETURNED: " << (returned ? "YES" : "NO") << " |" << endl;
    }
};

class Fines
{
private:
    int user_id;
    int book_id;
    int dayslate;
    double rate;
    double amount;

public:
    Fines() : user_id(0), book_id(0), dayslate(0), rate(0), amount(0) {}

    Fines(int u, int b, int d, User *user)
        : user_id(u), book_id(b), dayslate(d)
    {
        rate = user->getFineRate(); // polymorphism here
        amount = rate * dayslate;
    }

    // DESTRUCTOR
    ~Fines() { cout << "FINES DESTROYED!" << endl; }

    // FUNCTIONS
    void display(int userID)
    {
        if (user_id == userID)
        {
            cout << "|USER ID: " << user_id
                 << " |BOOK ID: " << book_id
                 << " |DAYS LATE: " << dayslate
                 << " |AMOUNT: " << amount << " |" << endl;
        }
    }

    void displayAll()
    {
        cout << "|USER ID: " << user_id
             << " |BOOK ID: " << book_id
             << " |DAYS LATE: " << dayslate
             << " |AMOUNT: " << amount << " |" << endl;
    }
};

class Reservation
{
private:
    int reservationid;
    int userid;
    int bookid;
    int tableid;
    string Reservationdate;
    string Reservationtime;

public:
    Reservation() : reservationid(0), userid(0), bookid(0), tableid(0),
                    Reservationdate("UNKNOWN"), Reservationtime("UNKNOWN") {}

    Reservation(int rid, int uid, int bid, int tid, string date, string time)
        : reservationid(rid), userid(uid), bookid(bid), tableid(tid),
          Reservationdate(date), Reservationtime(time) {}

    ~Reservation() { cout << "RESERVATION DESTROYED!" << endl; }

    // GETTERS
    int get_reservationid() { return reservationid; }
    int get_userid() { return userid; }
    int get_bookid() { return bookid; }
    int get_tableid() { return tableid; }
    string get_date() { return Reservationdate; }
    string get_time() { return Reservationtime; }

    // SETTERS
    void set_reservationid(int rid) { reservationid = rid; }
    void set_userid(int uid) { userid = uid; }
    void set_bookid(int bid) { bookid = bid; }
    void set_tableid(int tid) { tableid = tid; }
    void set_date(string date) { Reservationdate = date; }
    void set_time(string time) { Reservationtime = time; }

    void display()
    {
        cout << "|RESERVATION ID: " << reservationid
             << " |USER ID: " << userid
             << " |BOOK ID: " << bookid
             << " |TABLE ID: " << tableid
             << " |DATE: " << Reservationdate
             << " |TIME: " << Reservationtime << " |" << endl;
    }
};
class library
{
private:
    BookCatalog catalog;
    Reservation *reservations[100];
    int reservation_count = 0;
    Transaction *transaction[100];
    int transaction_count = 0;

    Fines *fines[100];
    int fine_count = 0;

    User *users[100];
    int user_count = 0;

public:
    User *getUserByID(int id)
    {
        for (int i = 0; i < user_count; i++)
        {
            if (users[i]->get_userid() == id)
                return users[i];
        }
        cout << "User not found!" << endl;
        return nullptr;
    }
    void registerUserInLibrary()
    {
        User *newUser = User::registerUser();
        if (newUser)
        {
            users[user_count++] = newUser;
            cout << "User Registered Successfully!\n";
        }
        else
        {
            cout << "Registration Failed.\n";
        }
    }

    bool borrowBook(User *u, string title, string issue, string due)
    {
        Book *book = catalog.SearchbyTitle(title);
        if (!book)
            return false;

        if (book->getAvailableCopies() == 0)
        {
            cout << "NO COPIES!" << endl;
            return false;
        }

        if (u->borrowbook(book->get_bookid()))
        {
            book->setAvailableCopies(book->getAvailableCopies() - 1);
            transaction[transaction_count++] = new Transaction(u->get_userid(), book->get_bookid(), issue, due);
            cout << "BOOK BORROWED!" << endl;
            return true;
        }
        return false;
    }

    // Return book
    bool returnBook(User *u, string title, int daysLate = 0)
    {
        Book *book = catalog.SearchbyTitle(title);
        if (!book)
            return false;

        if (u->returnbook(book->get_bookid()))
        {
            book->setAvailableCopies(book->getAvailableCopies() + 1);
            if (daysLate > 0)

            {
                fines[fine_count++] = new Fines(u->get_userid(), book->get_bookid(), daysLate, u);
                cout << "FINE GENERATED!" << endl;
            }

            for (int i = 0; i < transaction_count; i++)
            {
                if (transaction[i]->getbookid() == book->get_bookid() && transaction[i]->getuserid() == u->get_userid())
                {
                    transaction[i]->markreturned();
                    break;
                }
            }
            cout << "BOOK RETURNED!" << endl;
            return true;
        }
        return false;
    }

    void viewTransactions() // all transactions of all books
    {
        cout << "==== ALL TRANSACTIONS ====" << endl;
        for (int i = 0; i < transaction_count; i++)
            transaction[i]->displayAll();
    }

    void viewFines() // all fines of all users
    {
        cout << "==== ALL FINES ====" << endl;
        for (int i = 0; i < fine_count; i++)
            fines[i]->displayAll();
    }

    void viewUserTransactions(int userID)
    {
        cout << "==== TRANSACTIONS FOR USER ID: " << userID << " ====" << endl;
        for (int i = 0; i < transaction_count; i++)
            transaction[i]->displayuser(userID);
    }

    void viewUserFines(int userID)
    {
        cout << "==== FINES FOR USER ID: " << userID << " ====" << endl;
        for (int i = 0; i < fine_count; i++)
            fines[i]->display(userID);
    }

    void viewUsers()
    {
        cout << "==== ALL USERS ====" << endl;
        for (int i = 0; i < user_count; i++)
        {
            cout << "|NAME: " << users[i]->get_name()
                 << " |EMAIL: " << users[i]->get_email()
                 << " |PHONE: " << users[i]->get_phone()
                 << " |USER TYPE: " << users[i]->get_usertype() << " |" << endl;
        }
    }

    void viewUsersByType(string type)
    {
        cout << "==== USERS OF TYPE: " << type << " ====" << endl;
        for (int i = 0; i < user_count; i++)
        {
            if (users[i]->get_usertype() == type)
            {
                cout << "|NAME: " << users[i]->get_name()
                     << " |EMAIL: " << users[i]->get_email()
                     << " |PHONE: " << users[i]->get_phone()
                     << " |USER TYPE: " << users[i]->get_usertype() << " |" << endl;
            }
        }
    }
    void reserveBook(int uid, int bkid, string date, string time)
    {
        reservations[reservation_count] = new Reservation(reservation_count, uid, bkid, 0, date, time);
        reservation_count++;
        cout << "BOOK RESERVED! UserID: " << uid << " BookID: " << bkid << endl;
    }

    void reserveTable(int uid, int tblid, string date, string time)
    {
        reservations[reservation_count] = new Reservation(reservation_count, uid, 0, tblid, date, time);
        reservation_count++;
        cout << "TABLE RESERVED! UserID: " << uid << " TableID: " << tblid << endl;
    }

    void cancelReservation(int rid)
    {
        if (rid < 0 || rid >= reservation_count)
        {
            cout << "INVALID RESERVATION ID!" << endl;
            return;
        }
        delete reservations[rid];
        reservations[rid] = nullptr;
        cout << "RESERVATION CANCELLED! ReservationID: " << rid << endl;
    }

    bool checkAvailability(int rid)
    {
        if (rid < 0 || rid >= reservation_count)
        {
            cout << "INVALID RESERVATION ID!" << endl;
            return false;
        }
        if (reservations[rid]->get_bookid() == 0 && reservations[rid]->get_tableid() == 0)
        {
            cout << "AVAILABLE!" << endl;
            return true;
        }
        cout << "NOT AVAILABLE!" << endl;
        return false;
    }

    void viewAllReservations()
    {
        cout << "==== ALL RESERVATIONS ====" << endl;
        for (int i = 0; i < reservation_count; i++)
            if (reservations[i] != nullptr)
                reservations[i]->display();
    }
};
int main()
{
    library myLib;
    librarian lib1(1, "Ali Khan", "ali@library.com", "03001234567");

    // ---- Librarian adds books at startup ----
    Book *b1 = new Book(1, "Introduction to C++", "Bjarne Stroustrup", "Programming", "978-0-13-468599-1", "Pearson", 2013);
    Book *b2 = new Book(2, "Data Structures", "Mark Allen Weiss", "Computer Science", "978-0-13-284737-7", "Pearson", 2011);
    Book *b3 = new Book(3, "Calculus", "James Stewart", "Mathematics", "978-1-285-74062-1", "Cengage", 2015);
    Book *b4 = new Book(4, "Physics Vol 1", "Halliday Resnick", "Physics", "978-0-471-32057-9", "Wiley", 2010);

    b1->setAvailableCopies(3);
    b2->setAvailableCopies(2);
    b3->setAvailableCopies(4);
    b4->setAvailableCopies(1);

    BookCatalog *catalog = new BookCatalog();
    lib1.addbook(b1, catalog);
    lib1.addbook(b2, catalog);
    lib1.addbook(b3, catalog);
    lib1.addbook(b4, catalog);

    // ---- Main Program Loop ----
    int mainChoice;
    do
    {
        cout << "\n========================================" << endl;
        cout << "     WELCOME TO LIBRARY SYSTEM          " << endl;
        cout << "========================================" << endl;
        cout << "Who are you?" << endl;
        cout << "1. Librarian" << endl;
        cout << "2. User (Student / Faculty / Guest)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> mainChoice;
        cin.ignore();

        // ==================== LIBRARIAN ====================
        if (mainChoice == 1)
        {
            string pass;
            cout << "Enter Librarian Password: ";
            getline(cin, pass);

            if (pass != "admin123")
            {
                cout << "WRONG PASSWORD!" << endl;
                continue;
            }

            cout << "Welcome, " << "Librarian!" << endl;

            int libChoice;
            do
            {
                cout << "\n---- LIBRARIAN MENU ----" << endl;
                cout << "1. Add Book" << endl;
                cout << "2. Remove Book" << endl;
                cout << "3. View Book Catalog" << endl;
                cout << "4. View All Users" << endl;
                cout << "5. View All Transactions" << endl;
                cout << "6. View All Fines" << endl;
                cout << "7. View All Reservations" << endl;
                cout << "8. Logout" << endl;
                cout << "Enter Choice: ";
                cin >> libChoice;
                cin.ignore();

                if (libChoice == 1)
                {
                    int id, yop, copies;
                    string t, a, c, isbn, p;
                    cout << "Enter Book ID: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Enter Title: ";
                    getline(cin, t);
                    cout << "Enter Author: ";
                    getline(cin, a);
                    cout << "Enter Category: ";
                    getline(cin, c);
                    cout << "Enter ISBN: ";
                    getline(cin, isbn);
                    cout << "Enter Publisher: ";
                    getline(cin, p);
                    cout << "Enter Year: ";
                    cin >> yop;
                    cout << "Enter Copies: ";
                    cin >> copies;
                    cin.ignore();

                    Book *newBook = new Book(id, t, a, c, isbn, p, yop);
                    newBook->setAvailableCopies(copies);
                    lib1.addbook(newBook, catalog);
                }
                else if (libChoice == 2)
                {
                    string title;
                    cout << "Enter Title to Remove: ";
                    getline(cin, title);
                    lib1.removeBook(title, catalog);
                }
                else if (libChoice == 3)
                {
                    catalog->ViewBookCatalog();
                }
                else if (libChoice == 4)
                {
                    myLib.viewUsers();
                }
                else if (libChoice == 5)
                {
                    myLib.viewTransactions();
                }
                else if (libChoice == 6)
                {
                    myLib.viewFines();
                }
                else if (libChoice == 7)
                {
                    myLib.viewAllReservations();
                }
                else if (libChoice == 8)
                {
                    cout << "Librarian Logged Out." << endl;
                }
                else
                {
                    cout << "Invalid Choice!" << endl;
                }

            } while (libChoice != 8);
        }

        // ==================== USER ====================
        else if (mainChoice == 2)
        {
            int userChoice;
            cout << "\n---- USER MENU ----" << endl;
            cout << "1. Register as New User" << endl;
            cout << "2. Already Registered - Login by ID" << endl;
            cout << "Enter Choice: ";
            cin >> userChoice;
            cin.ignore();

            User *currentUser = nullptr;

            if (userChoice == 1)
            {
                myLib.registerUserInLibrary();
                cout << "Please login now with your ID." << endl;
            }

            // Login by ID
            int loginID;
            cout << "Enter Your User ID: ";
            cin >> loginID;
            cin.ignore();

            currentUser = myLib.getUserByID(loginID);

            if (currentUser == nullptr)
            {
                cout << "User not found! Please register first." << endl;
                continue;
            }

            cout << "Welcome, " << currentUser->get_name() << "!" << endl;

            int uChoice;
            do
            {
                cout << "\n---- USER MENU ----" << endl;
                cout << "1. View Book Catalog" << endl;
                cout << "2. Borrow Book" << endl;
                cout << "3. Return Book" << endl;
                cout << "4. Reserve a Book" << endl;
                cout << "5. Reserve a Table" << endl;
                cout << "6. Cancel Reservation" << endl;
                cout << "7. View My Transactions" << endl;
                cout << "8. View My Fines" << endl;
                cout << "9. View My Details" << endl;
                cout << "10. Logout" << endl;
                cout << "Enter Choice: ";
                cin >> uChoice;
                cin.ignore();

                if (uChoice == 1)
                {
                    catalog->ViewBookCatalog();
                }
                else if (uChoice == 2)
                {
                    string title, issue, due;
                    cout << "Enter Book Title: ";
                    getline(cin, title);
                    cout << "Enter Issue Date (DD/MM/YYYY): ";
                    getline(cin, issue);
                    cout << "Enter Due Date (DD/MM/YYYY): ";
                    getline(cin, due);
                    myLib.borrowBook(currentUser, title, issue, due);
                }
                else if (uChoice == 3)
                {
                    string title;
                    int daysLate;
                    cout << "Enter Book Title: ";
                    getline(cin, title);
                    cout << "Enter Days Late (0 if not late): ";
                    cin >> daysLate;
                    cin.ignore();
                    myLib.returnBook(currentUser, title, daysLate);
                }
                else if (uChoice == 4)
                {
                    int bkid;
                    string date, time;
                    cout << "Enter Book ID to Reserve: ";
                    cin >> bkid;
                    cin.ignore();
                    cout << "Enter Date (DD/MM/YYYY): ";
                    getline(cin, date);
                    cout << "Enter Time (HH:MM): ";
                    getline(cin, time);
                    myLib.reserveBook(currentUser->get_userid(), bkid, date, time);
                }
                else if (uChoice == 5)
                {
                    int tblid;
                    string date, time;
                    cout << "Enter Table ID to Reserve: ";
                    cin >> tblid;
                    cin.ignore();
                    cout << "Enter Date (DD/MM/YYYY): ";
                    getline(cin, date);
                    cout << "Enter Time (HH:MM): ";
                    getline(cin, time);
                    myLib.reserveTable(currentUser->get_userid(), tblid, date, time);
                }
                else if (uChoice == 6)
                {
                    int rid;
                    cout << "Enter Reservation ID to Cancel: ";
                    cin >> rid;
                    cin.ignore();
                    myLib.cancelReservation(rid);
                }
                else if (uChoice == 7)
                {
                    myLib.viewUserTransactions(currentUser->get_userid());
                }
                else if (uChoice == 8)
                {
                    myLib.viewUserFines(currentUser->get_userid());
                }
                else if (uChoice == 9)
                {
                    currentUser->viewdetails();
                }
                else if (uChoice == 10)
                {
                    cout << "Logged Out." << endl;
                }
                else
                {
                    cout << "Invalid Choice!" << endl;
                }

            } while (uChoice != 10);
        }

        else if (mainChoice == 3)
        {
            cout << "Thank you! Goodbye." << endl;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }

    } while (mainChoice != 3);

    return 0;
}
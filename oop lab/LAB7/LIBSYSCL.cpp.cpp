#include <iostream>
using namespace std;

// Forward declarations
class Student;
class Faculty;
class Guest;

// ---------------- User Base Class ----------------
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
    User(int id, string n = "NONE", string c = "xxxxx-xxxxxxx-x", string e = "abc@gmail.com", string p = "03xxxxxxxxx", int bcount = 0)
        : userid(id), name(n), CNIC(c), email(e), phonenumber(p), borrowedbookcount(bcount)
    {
        for (int i = 0; i < 20; i++)
            borrowedbook[i] = 0;
    }

    virtual ~User() { cout << "User " << name << " destroyed." << endl; }

    // SETTERS
    void setid(int id)        { userid = id; }
    void setname(string n)    { name = n; }
    void setemail(string e)   { email = e; }
    void setphone_no(string p){ phonenumber = p; }
    void setCNIC(string c)    { CNIC = c; }

    // GETTERS
    int    get_userid() { return userid; }
    string get_name()   { return name; }
    string get_email()  { return email; }
    string get_phone()  { return phonenumber; }
    string get_cnic()   { return CNIC; }

    // Pure virtual functions
    virtual int    getborrowlimit() = 0;
    virtual string get_usertype()   = 0;
    virtual void   viewdetails()    = 0;
    virtual int    getFineRate()    = 0;

    // MENUS
    void menudetails()
    {
        cout << "PRESS 1: BORROWED BOOKS" << endl
             << "PRESS 2: FINES" << endl
             << "PRESS 3: EXIT" << endl;
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

    // registerUser defined after derived classes
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

    int    getborrowlimit() override { return 3; }
    string get_usertype()   override { return "STUDENT"; }
    int    getFineRate()    override { return 10; }

    void viewdetails() override
    {
        cout << "|NAME: " << name
             << " |SEAT: " << seatno
             << " |MAJOR: " << major
             << " |TYPE: STUDENT|" << endl;
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

    int    getborrowlimit() override { return 5; }
    string get_usertype()   override { return "FACULTY"; }
    int    getFineRate()    override { return 15; }

    void viewdetails() override
    {
        cout << "|NAME: " << name
             << " |DEPARTMENT: " << department
             << " |DESIGNATION: " << designation
             << " |TYPE: FACULTY|" << endl;
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

    int    getborrowlimit() override { return 1; }
    string get_usertype()   override { return "GUEST"; }
    int    getFineRate()    override { return 20; }

    void viewdetails() override
    {
        cout << "|NAME: " << name
             << " |PURPOSE: " << purpose
             << " |TYPE: GUEST|" << endl;
    }
};

// ---------------- registerUser (defined after derived classes) ----------------
User *User::registerUser()
{
    int choice;
    cout << "Select User Type:\n1. Student\n2. Faculty\n3. Guest\nChoice: ";
    cin >> choice;
    cin.ignore();

    string name, CNIC, email, phone;
    cout << "Enter Name: ";   getline(cin, name);
    cout << "Enter CNIC: ";   getline(cin, CNIC);
    cout << "Enter Email: ";  getline(cin, email);
    cout << "Enter Phone: ";  getline(cin, phone);

    if (choice == 1)
    {
        string seat, major;
        int id;
        cout << "Enter ID: ";           cin >> id; cin.ignore();
        cout << "Enter Seat Number: ";  getline(cin, seat);
        cout << "Enter Major: ";        getline(cin, major);
        return new Student(id, name, CNIC, email, phone, seat, major);
    }
    else if (choice == 2)
    {
        string dept, des;
        int id;
        cout << "Enter ID: ";           cin >> id; cin.ignore();
        cout << "Enter Department: ";   getline(cin, dept);
        cout << "Enter Designation: ";  getline(cin, des);
        return new Faculty(id, name, CNIC, email, phone, dept, des);
    }
    else if (choice == 3)
    {
        string purpose;
        int id;
        cout << "Enter ID: ";      cin >> id; cin.ignore();
        cout << "Enter Purpose: "; getline(cin, purpose);
        return new Guest(id, name, CNIC, email, phone, purpose);
    }
    else
    {
        cout << "Invalid choice!\n";
        return nullptr;
    }
}

// ---------------- Book ----------------
class Book
{
private:
    int    bookid;
    string title;
    string author;
    string category;
    string ISBN;
    string publisher;
    int    year_of_publication;
    int    available_copies = 0;
    bool   avalaibility_status;
    int    download_count       = 0;
    int    read_onsite_count    = 0;
    int    timesborrowed_count  = 0;

public:
    Book() : bookid(0), title("UNKNOWN"), author("UNKNOWN"), category("UNKNOWN"),
             ISBN("UNKNOWN"), publisher("UNKNOWN"), year_of_publication(0),
             avalaibility_status(false), download_count(0), read_onsite_count(0), timesborrowed_count(0) {}

    Book(int id, string t, string a, string c, string isbn, string p, int yop)
        : bookid(id), title(t), author(a), category(c), ISBN(isbn), publisher(p),
          year_of_publication(yop), avalaibility_status(false),
          download_count(0), read_onsite_count(0), timesborrowed_count(0) {}

    ~Book() { cout << "BOOK DESTROYED!" << endl; }

    // GETTERS
    int    get_bookid()              { return bookid; }
    string get_title()               { return title; }
    string get_author()              { return author; }
    string get_category()            { return category; }
    string get_isbn()                { return ISBN; }
    string get_publisher()           { return publisher; }
    int    get_YOP()                 { return year_of_publication; }
    int    getAvailableCopies()      { return available_copies; }
    int    get_downloadcount()       { return download_count; }
    int    get_read_onsitecount()    { return read_onsite_count; }
    int    get_timesborrowed_count() { return timesborrowed_count; }

    // SETTERS
    void set_bookid(int id)         { bookid = id; }
    void set_author(string a)       { author = a; }
    void set_title(string t)        { title = t; }
    void set_category(string c)     { category = c; }
    void set_isbn(string isbn)      { ISBN = isbn; }
    void set_publisher(string p)    { publisher = p; }
    void set_YOP(int yop)           { year_of_publication = yop; }
    void setAvailableCopies(int ac) { available_copies = ac; }

    void display()
    {
        cout << "BOOK ID: "           << bookid              << endl
             << "TITLE: "             << title               << endl
             << "AUTHOR: "            << author              << endl
             << "CATEGORY: "          << category            << endl
             << "ISBN: "              << ISBN                << endl
             << "PUBLISHER: "         << publisher           << endl
             << "YEAR OF PUBLICATION: "<< year_of_publication << endl
             << "AVAILABLE COPIES: "  << available_copies    << endl
             << "DOWNLOADED: "        << download_count      << " times" << endl
             << "READ ON SITE: "      << read_onsite_count   << " times" << endl
             << "TIMES BORROWED: "    << timesborrowed_count << " times" << endl;
        cout << "-----------------------------------------------------" << endl;
    }
};

// ---------------- BookCatalog ----------------
class BookCatalog
{
private:
    Book *BK[100];
    int   book_count = 0;

public:
    BookCatalog() : book_count(0) {}
    ~BookCatalog() { cout << "BOOKCATALOG DESTROYED!" << endl; }

    void addbook(Book *b)
    {
        if (book_count < 100)
        {
            BK[book_count++] = b;
            cout << "BOOK ADDED SUCCESSFULLY!" << endl;
        }
        else
            cout << "LIBRARY FULL!" << endl;
    }

    void removeBook(string t)
    {
        if (book_count == 0) { cout << "NO BOOKS IN CATALOG!" << endl; return; }
        int pos = -1;
        for (int i = 0; i < book_count; i++)
            if (BK[i]->get_title() == t) { pos = i; break; }

        if (pos == -1) { cout << "BOOK NOT FOUND!" << endl; return; }

        for (int i = pos; i < book_count - 1; i++)
            BK[i] = BK[i + 1];
        delete BK[book_count - 1];
        book_count--;
        cout << "BOOK REMOVED!" << endl;
    }

    Book *SearchbyID(int id)
    {
        if (book_count == 0) { cout << "NO BOOKS IN CATALOG!" << endl; return nullptr; }
        for (int i = 0; i < book_count; i++)
            if (BK[i]->get_bookid() == id) return BK[i];
        cout << "BOOK NOT FOUND!" << endl;
        return nullptr;
    }

    Book *SearchbyTitle(string t)
    {
        if (book_count == 0) { cout << "NO BOOKS IN CATALOG!" << endl; return nullptr; }
        for (int i = 0; i < book_count; i++)
            if (BK[i]->get_title() == t) return BK[i];
        cout << "BOOK NOT FOUND!" << endl;
        return nullptr;
    }

    Book *SearchbyAuthor(string a)
    {
        if (book_count == 0) { cout << "NO BOOKS IN CATALOG!" << endl; return nullptr; }
        for (int i = 0; i < book_count; i++)
            if (BK[i]->get_author() == a) return BK[i];
        cout << "BOOK NOT FOUND!" << endl;
        return nullptr;
    }

    Book *SearchbyCategory(string c)
    {
        if (book_count == 0) { cout << "NO BOOKS IN CATALOG!" << endl; return nullptr; }
        for (int i = 0; i < book_count; i++)
            if (BK[i]->get_category() == c) return BK[i];
        cout << "BOOK NOT FOUND!" << endl;
        return nullptr;
    }

    Book *SearchbyPublisher(string p)
    {
        if (book_count == 0) { cout << "NO BOOKS IN CATALOG!" << endl; return nullptr; }
        for (int i = 0; i < book_count; i++)
            if (BK[i]->get_publisher() == p) return BK[i];
        cout << "BOOK NOT FOUND!" << endl;
        return nullptr;
    }

    Book *SearchbyYOP(int yop)
    {
        if (book_count == 0) { cout << "NO BOOKS IN CATALOG!" << endl; return nullptr; }
        for (int i = 0; i < book_count; i++)
            if (BK[i]->get_YOP() == yop) return BK[i];
        cout << "BOOK NOT FOUND!" << endl;
        return nullptr;
    }

    void ViewBookCatalog() const
    {
        if (book_count == 0) { cout << "NO BOOKS IN CATALOG!" << endl; return; }
        cout << "====BOOK CATALOG====" << endl;
        for (int i = 0; i < book_count; i++)
            BK[i]->display();
    }

    int get_bookcount() { return book_count; }
};

// ---------------- Librarian ----------------
class librarian
{
private:
    int    librarian_id;
    string name;
    string email;
    string phone_no;

public:
    librarian() : librarian_id(0), name("UNKNOWN"), email("UNKNOWN"), phone_no("UNKNOWN") {}
    librarian(int id, string n, string e, string p) : librarian_id(id), name(n), email(e), phone_no(p) {}
    ~librarian() { cout << "LIBRARIAN DESTROYED!" << endl; }

    void addbook(Book *b, BookCatalog *catalog)   { catalog->addbook(b); }
    void removeBook(string t, BookCatalog *catalog){ catalog->removeBook(t); }

    void displaylibrarian_details()
    {
        cout << "ID: "     << librarian_id << endl
             << "NAME: "   << name         << endl
             << "EMAIL: "  << email        << endl
             << "PHONE#: " << phone_no     << endl;
    }
};

// ---------------- Transaction ----------------
class Transaction
{
private:
    int    transaction_id;
    int    user_id;
    int    book_id;
    string issue_date;
    string return_date;
    string due_date;
    bool   returned = false;   // BUG FIX: initialize to false

public:
    Transaction() : transaction_id(0), user_id(0), book_id(0),
                    issue_date("UNKNOWN"), return_date("UNKNOWN"), due_date("UNKNOWN") {}

    Transaction(int uid, int bid, string i, string d)
        : transaction_id(0), user_id(uid), book_id(bid), issue_date(i), due_date(d), returned(false) {}

    ~Transaction() { cout << "TRANSACTION DESTROYED!" << endl; }

    // GETTERS
    int    getuserid()   { return user_id; }
    int    getbookid()   { return book_id; }
    string getissuedate(){ return issue_date; }
    string getduedate()  { return due_date; }

    // SETTERS
    void setIssueDate(string i) { issue_date = i; }
    void setDueDate(string d)   { due_date = d; }

    // BUG FIX: removed duplicate markreturned()
    void markreturned() { returned = true; }

    void displayuser(int id)
    {
        // BUG FIX: == instead of =
        if (user_id == id)
        {
            cout << "|TRANSACTION ID: " << transaction_id
                 << " |USER ID: "       << user_id
                 << " |BOOK ID: "       << book_id
                 << " |ISSUE DATE: "    << issue_date
                 << " |DUE DATE: "      << due_date
                 << " |RETURNED: "      << (returned ? "YES" : "NO") << " |" << endl;
        }
    }

    void displayAll()
    {
        cout << "|USER ID: "    << user_id
             << " |BOOK ID: "   << book_id
             << " |ISSUE DATE: "<< issue_date
             << " |DUE DATE: "  << due_date
             << " |RETURNED: "  << (returned ? "YES" : "NO") << " |" << endl;
    }
};

// ---------------- Fines ----------------
class Fines
{
private:
    int    user_id;
    int    book_id;
    int    dayslate;
    double rate;
    double amount;

public:
    Fines() : user_id(0), book_id(0), dayslate(0), rate(0), amount(0) {}

    Fines(int u, int b, int d, User *user)
        : user_id(u), book_id(b), dayslate(d)
    {
        rate   = user->getFineRate();
        amount = rate * dayslate;
    }

    ~Fines() { cout << "FINES DESTROYED!" << endl; }

    void display(int userID)
    {
        if (user_id == userID)
        {
            cout << "|USER ID: "    << user_id
                 << " |BOOK ID: "   << book_id
                 << " |DAYS LATE: " << dayslate
                 << " |AMOUNT: "    << amount << " |" << endl;
        }
    }

    void displayAll()
    {
        cout << "|USER ID: "    << user_id
             << " |BOOK ID: "   << book_id
             << " |DAYS LATE: " << dayslate
             << " |AMOUNT: "    << amount << " |" << endl;
    }
};

// ---------------- Reservation ----------------
class Reservation
{
private:
    int    reservationid;
    int    userid;
    int    bookid;
    int    tableid;
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
    int    get_reservationid() { return reservationid; }
    int    get_userid()        { return userid; }
    int    get_bookid()        { return bookid; }
    int    get_tableid()       { return tableid; }
    string get_date()          { return Reservationdate; }
    string get_time()          { return Reservationtime; }

    // SETTERS
    void set_reservationid(int rid)   { reservationid = rid; }
    void set_userid(int uid)          { userid = uid; }
    void set_bookid(int bid)          { bookid = bid; }
    void set_tableid(int tid)         { tableid = tid; }
    void set_date(string date)        { Reservationdate = date; }
    void set_time(string time)        { Reservationtime = time; }

    // FUNCTIONS
    void reserveBook(int uid, int bkid)
    {
        userid = uid;
        bookid = bkid;
        cout << "BOOK RESERVED! UserID: " << uid << " BookID: " << bkid << endl;
    }

    void reserveTable(int uid, int tblid)
    {
        userid = uid;
        tableid = tblid;
        cout << "TABLE RESERVED! UserID: " << uid << " TableID: " << tblid << endl;
    }

    void cancelReservation()
    {
        bookid  = 0;
        tableid = 0;
        cout << "RESERVATION CANCELLED! ReservationID: " << reservationid << endl;
    }

    bool checkAvailability()
    {
        if (bookid == 0 && tableid == 0)
        {
            cout << "AVAILABLE!" << endl;
            return true;
        }
        cout << "NOT AVAILABLE!" << endl;
        return false;
    }

    void display()
    {
        cout << "|RESERVATION ID: " << reservationid
             << " |USER ID: "       << userid
             << " |BOOK ID: "       << bookid
             << " |TABLE ID: "      << tableid
             << " |DATE: "          << Reservationdate
             << " |TIME: "          << Reservationtime << " |" << endl;
    }
};

// ---------------- Library ----------------
class library
{
private:
    BookCatalog catalog;

    Transaction  *transaction[100];
    int           transaction_count = 0;

    Fines        *fines[100];
    int           fine_count = 0;       // BUG FIX: initialized to 0

    User         *users[100];
    int           user_count = 0;       // BUG FIX: initialized to 0

    Reservation  *reservations[100];
    int           reservation_count = 0;

public:
    // ---------------- User ----------------
    void registerUserInLibrary()
    {
        User *newUser = User::registerUser();
        if (newUser)
        {
            users[user_count++] = newUser;
            cout << "User Registered Successfully!\n";
        }
        else
            cout << "Registration Failed.\n";
    }

    void viewUsers()
    {
        cout << "==== ALL USERS ====" << endl;
        for (int i = 0; i < user_count; i++)
        {
            cout << "|NAME: "      << users[i]->get_name()
                 << " |EMAIL: "    << users[i]->get_email()
                 << " |PHONE: "    << users[i]->get_phone()
                 << " |USER TYPE: "<< users[i]->get_usertype() << " |" << endl;
        }
    }

    void viewUsersByType(string type)
    {
        cout << "==== USERS OF TYPE: " << type << " ====" << endl;
        for (int i = 0; i < user_count; i++)
        {
            if (users[i]->get_usertype() == type)
            {
                cout << "|NAME: "      << users[i]->get_name()
                     << " |EMAIL: "    << users[i]->get_email()
                     << " |PHONE: "    << users[i]->get_phone()
                     << " |USER TYPE: "<< users[i]->get_usertype() << " |" << endl;
            }
        }
    }

    // ---------------- Borrow / Return ----------------
    bool borrowBook(User *u, string title, string issue, string due)
    {
        Book *book = catalog.SearchbyTitle(title);
        if (!book) return false;

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

    bool returnBook(User *u, string title, int daysLate = 0)
    {
        Book *book = catalog.SearchbyTitle(title);
        if (!book) return false;

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
                if (transaction[i]->getbookid() == book->get_bookid() &&
                    transaction[i]->getuserid()  == u->get_userid())
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

    // ---------------- Transactions ----------------
    void viewTransactions()
    {
        cout << "==== ALL TRANSACTIONS ====" << endl;
        for (int i = 0; i < transaction_count; i++)
            transaction[i]->displayAll();
    }

    void viewUserTransactions(int userID)
    {
        cout << "==== TRANSACTIONS FOR USER ID: " << userID << " ====" << endl;
        for (int i = 0; i < transaction_count; i++)
            transaction[i]->displayuser(userID);
    }

    // ---------------- Fines ----------------
    void viewFines()
    {
        cout << "==== ALL FINES ====" << endl;
        for (int i = 0; i < fine_count; i++)
            fines[i]->displayAll();
    }

    void viewUserFines(int userID)
    {
        cout << "==== FINES FOR USER ID: " << userID << " ====" << endl;
        for (int i = 0; i < fine_count; i++)
            fines[i]->display(userID);
    }

    // ---------------- Reservations ----------------
    void makeBookReservation(int uid, int bkid, string date, string time)
    {
        reservations[reservation_count] = new Reservation(reservation_count, uid, bkid, 0, date, time);
        reservations[reservation_count]->reserveBook(uid, bkid);
        reservation_count++;
    }

    void makeTableReservation(int uid, int tblid, string date, string time)
    {
        reservations[reservation_count] = new Reservation(reservation_count, uid, 0, tblid, date, time);
        reservations[reservation_count]->reserveTable(uid, tblid);
        reservation_count++;
    }

    void cancelReservation(int rid)
    {
        if (rid < 0 || rid >= reservation_count)
        {
            cout << "INVALID RESERVATION ID!" << endl;
            return;
        }
        reservations[rid]->cancelReservation();
    }

    void viewAllReservations()
    {
        cout << "==== ALL RESERVATIONS ====" << endl;
        for (int i = 0; i < reservation_count; i++)
            reservations[i]->display();
    }

    void viewUserReservations(int userID)
    {
        cout << "==== RESERVATIONS FOR USER ID: " << userID << " ====" << endl;
        for (int i = 0; i < reservation_count; i++)
            if (reservations[i]->get_userid() == userID)
                reservations[i]->display();
    }
};

// ---------------- Main ----------------
int main()
{
    library myLib;
    myLib.registerUserInLibrary();
    myLib.viewUsers();
    return 0;
}

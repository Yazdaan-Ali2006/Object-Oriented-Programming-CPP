#include <iostream>
using namespace std;


class Notification {
public:
    virtual void send(string msg) {
        cout << "Generic Notification: " << msg << endl;
    }

    virtual ~Notification() {
        cout << "Notification destroyed" << endl;
    }
};

class EmailNotification : public Notification {
public:
    void send(string msg) override {
        cout << "Email sent: " << msg << endl;
    }

    ~EmailNotification() {
        cout << "EmailNotification destroyed" << endl;
    }
};


class SecureEmailNotification : public EmailNotification {
public:
    void send(string msg) final {
        cout << "Secure Email sent (encrypted): " << msg << endl;
    }

    ~SecureEmailNotification() {
        cout << "SecureEmailNotification destroyed" << endl;
    }
};

int main() {

    // Base class pointer pointing to base object
    Notification* n1 = new Notification();
    Notification* n2 = new EmailNotification();
    Notification* n3 = new SecureEmailNotification();

    cout << "\n--- Runtime Polymorphism Output ---\n";

    n1->send("Hello");
    n2->send("Hello");
    n3->send("Hello");

    // cleanup
    delete n1;
    delete n2;
    delete n3;

    return 0;
}

/*
6. HackedEmailNotification (This will cause ERROR)

class HackedEmailNotification : public SecureEmailNotification {
public:
    void send(string msg) override {   // ❌ ERROR: cannot override because send() is final in SecureEmailNotification
        cout << "Hacked Email: " << msg << endl;
    }
};

Reason:
- send() in SecureEmailNotification is marked final
- So no further class can override it
*/
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    time_t borrowTime = 0;
    bool hasBook = false;
    int choice;

    while (true)
    {
        cout << "\n--- Library System ---\n";
        cout << "1. Borrow a Book\n2. Return a Book\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (hasBook)
            {
                // Logic Check: Has 30 seconds passed?
                time_t currentTime = time(nullptr);
                double secondsPassed = difftime(currentTime, borrowTime);

                if (secondsPassed > 30)
                {
                    cout << "WARNING: You kept the last book for " << secondsPassed
                         << " seconds. Return it before borrowing another!\n";
                }
                else
                {
                    cout << "You already have a book! Return it first.\n";
                }
            }
            else
            {
                // Borrowing the book
                borrowTime = time(nullptr);
                hasBook = true;
                cout << "Book borrowed at: " << ctime(&borrowTime);
            }
        }
        else if (choice == 2)
        {
            hasBook = false;
            cout << "Book returned successfully!\n";
        }
        else
        {
            break;
        }
    }
    return 0;
}
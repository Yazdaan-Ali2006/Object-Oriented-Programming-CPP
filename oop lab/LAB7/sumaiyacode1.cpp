#include <iostream>
using namespace std;
class System
{
    static int activeUsers;
    int sessionID;

public:
    System()
    {
        activeUsers++;
        sessionID = activeUsers + 100;
    }
    void status()
    {
        cout << sessionID << " ";
    }
    static void log()
    {
        cout << "<" << activeUsers << "> ";
    }
};
int System::activeUsers = 0;
int main()
{
    System s1;  //au=1  sid=101
    System::log(); //1
    System s2, s3; // au2 sid 102,au3, au3 sid 103
    s2.status(); //sid 102
    s1.status(); //sid 101
    System::log(); //3
    return 0;
    /*FINAL O/P: 1 102 101 3
    */
}
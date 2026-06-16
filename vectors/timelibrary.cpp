using namespace std;
#include <ctime>
#include <iostream>
int main()
{
    time_t now = time(nullptr);
    cout << now<<endl; //this is basically printing the number of secons passed since 1070 till now
    cout << ctime(&now);

    return 0;
}
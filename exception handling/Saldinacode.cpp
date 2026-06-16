#include <iostream>
#include <string>
using namespace std;
class printer
{
private:
    int availablepages;
    string name;

public:
    printer(int ap, string n)
    {
        name = n;
        availablepages = ap;
    }

    void print(string str)
    {
        int reqdpaper = (str.length() + 9) / 10;  
        /* +9 EXPLANATION SEE IF TOTAL CHARACTERS ARE 35 THEN IF I DIVIDE IT WITH 10
           AS PER INT DIVISION IT WILL BECOME 3 BUT I NEED FOR 4 PAPERS SO 35+9=45 NOW 
           IT WILL BECOME 45/10=4 THATS WHY I DID LIKE THIS! 
        */
        if (reqdpaper > availablepages) 
        {
            throw("EXCEPTION:Max Limit Paper Reached!");
        }
        availablepages -= reqdpaper;
        cout << "DONE:NO EXCEPTION OCCURED" << endl;
    }
};
int main()
{
    printer p1(10, "HP PRINTER"); // 10 PAGES MAX 
    try
    {
        p1.print("ROUGH SEAS MAKE SKILLED SAILORS"); //34 CHARACTERS===I NEED 4 PAGES 
        p1.print("ROUGH SEAS MAKE SKILLED SAILORS"); // 4 AGAIN 
        p1.print("ROUGH SEAS MAKE SKILLED SAILORS"); // LIMIT REACHED CUZ I DONT HAVE NEXT 4 PAGES SO EXCEPTION 
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }

    return 0;
}
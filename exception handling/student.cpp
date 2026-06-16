#include <iostream>
#include <stdexcept>
using namespace std;
class student
{
private:
    int obtainedmarks;
    int totalmarks;
    string name;

public:
    student(int obm = 0, int tm = 0, string n = " ")
    {
        obtainedmarks = obm;
        totalmarks = tm;
        name = n;
    }
    void input()
    {
        cout << "ENTER YOUR NAME:";
        cin >> name;
        if (name == " ")
        {
            throw invalid_argument("ERROR:NAME CAN NEVER BE EMPTY");
        }
        cout << "ENTER YOUR OBTAINED MARKS:";
        cin >> obtainedmarks;
        if (obtainedmarks <0)
        {
             throw invalid_argument("ERROR:OBTAINED MARKS CAN NEVER BE NEGATVE");
        }
        cout << "ENTER TOTAL MARKS:";
        cin >> totalmarks;
        if (totalmarks<=00)
        {
            throw runtime_error("DIVISION BY 0 NOT POSSIBLE");
        }
    }
};
int main()
{
    student s1;
    try{
    s1.input();
    }
    catch (invalid_argument &e)
    {
        cout << e.what();
    }
        catch (runtime_error &e)
    {
        cout <<"ERRROR:"<<e.what()<<endl;
    }
    catch(...){
        cout<<"UNHANDLED EXCEPTION"<<endl;
    }


    return 0;
}
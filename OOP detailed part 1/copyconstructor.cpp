#include<iostream>
#include<cstring>
using namespace std;
class nedstudent{
   public:
    char* name;
    int roll;
    nedstudent(){
        name=nullptr;
        roll=0;
    }
    nedstudent(nedstudent &c){
        name=strdup(c.name);
        roll=c.roll;

    }

};
int main()
{   char n[]="ali";
    int rollno=30;
    nedstudent a;
    a.name=n;
    a.roll=rollno;
    nedstudent b=a;
    b.name[0]='c';
    cout<<""<<a.name<<endl;
    cout<<""<<b.name<<endl;
    

    return 0;
}
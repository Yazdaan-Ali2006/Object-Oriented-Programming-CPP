#include<iostream>
#include<cstring>
using namespace std;
class NEDStudent{
public:
int student_ID;
char*name;
NEDStudent(){
    student_ID=0;
    name=" ";
}
NEDStudent(NEDStudent &o){
    student_ID=o.student_ID;
    name=strdup(o.name);
}
};
int main()
{ 
    NEDStudent student1;
    student1.student_ID=98;
    char n[]="ali";
    student1.name=n;
    NEDStudent student2=student1;
    student2.name[0] = 's';
    
    cout<<"student1.name= "<<student1.name<<endl;
    cout<<"student2.name= "<<student2.name<<endl;


    return 0;
}
#include <iostream>
using namespace std;
class student
{
  string name;
  int rollno;
  int marks[3];

public:
  void set_name(string a) //setter
  {
     name=a;
  }
   string get_name()  //getter
  {
    return name;
  }
 void set_rollno(int a){ //setter
    rollno=a;
 } 
  int get_rollno()  //getter
  {
    return rollno;
  }

  void set_marks()
  {
    cout << "ENTER YOUR MARKS 1:\n";
    cin >> marks[0];
    cout << "ENTER YOUR MARKS 2: \n";
    cin >> marks[1];
    cout << "ENTER YOUR MARKS 3: \n";
    cin >> marks[2];
  }
  float avg()
  {
    return (marks[0] + marks[1] + marks[2]) / 3;
  }
  void display();
};
void student::display(){ 
  cout<<"NAME: "<<get_name()<<endl;
  cout<<"ROLL NO "<<get_rollno()<<endl;
  cout<<"===========MARKS=========="<<endl;
  cout<<"QUIZ 1: "<<marks[0]<<endl;
  cout<<"QUIZ 2: "<<marks[1]<<endl;
  cout<<"QUIZ 3: "<<marks[2]<<endl;
  cout<<"AVERAGE : "<<avg()<<endl;
  
}

int main()
{
  student s1;
  s1.set_name("YAZDAAN ALI");
  s1.set_rollno(30);
  s1.set_marks();
  s1.display();

      return 0;
}


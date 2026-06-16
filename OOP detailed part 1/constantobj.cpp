#include<iostream>
using namespace std;
class data{
    private:
    int age;
    public:
    data(int a):age(a){

    }
    void setage(int b) {
        age=b;
    }
    void display()const{
        cout<<"AGE:"<<age<<endl;

    }

};
int main()
{
    const data d1(10);
    d1.display();
  //  d1.setage(11); ERROR BECAUSE OF CONSTANT OBJ....
     return 0;
}
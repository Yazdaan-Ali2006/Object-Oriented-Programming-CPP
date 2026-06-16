#include<iostream>
using namespace std;
class teacher{
    string name;
    public:
    teacher(){
        name=" ";}
        teacher(string name){
            this->name=name;

        }
};
class department{
    private:
    teacher *t1;
    string deptname;
    public:
    department(){
        deptname="none";
        t1=nullptr;

    }


};
int main()
{ 
    
    return 0;
}

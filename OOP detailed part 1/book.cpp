#include<iostream>
using namespace std;
class book{
    string name;
    string author;
    string ISBN;
public:
book(string n="\0",string a="\0",string i="\0"){
    name=n;
    author=a;
    ISBN=i;

}
void setname(string n){
    name=n;
}
void setauthor(string a){
     author=a;
}
void setisbn(string i){
    ISBN=i;
}
string getname(){
    return name;
}
string getauthor(){
    return author;
}
string getisbn(){
    return ISBN;
}
void display(){
    cout<<"NAME: "<<name<<endl;
    cout<<"AUTHOR: "<<author<<endl;
    cout<<"ISBN: "<<ISBN<<endl;
}
};
int main()
{ book b1("GOOD","ALI","123-456-873");
    b1.display();
    return 0;
}

#include<iostream>
using namespace std;
class product{
    string name;
    float productid;
    public:
    product(){
        name=" ";
        productid=0;
    }
    void read(){
        cout<<"ENTER NAME:";
        getline(cin,name);
        cout<<"PRODUCT ID:";
 cin>>productid;

    }
    void display(){
        cout<<"NAME: "<<name<<endl;
        cout<<"PRODUCT ID: "<<productid<<endl;
    }
};
class utility:public product{
    float discount;
    public:
    utility(){
         discount=0;

    }
    void read(){

        product::read();
        cout<<"ENTER DISCOUNT: "; cin>>discount;
        
    }
    void display(){
        cout<<"UTILITY"<<endl;
        product::display();
        cout<<"DISCOUNT:"<<discount<<"%"<<endl;
    }

};
class food : public product{
    string  doe; //dateofexpiry
  public:
    food(){
        doe="none";
    }
    void read(){
        product::read();
        cout<<"ENTER EXPIRY DATE: ";
        cin>>doe;

    }
    void display(){
        cout<<"FOOD ITEM"<<endl;
        product::display();
        cout<<"EXPIRY DATE: "<<doe;
    }
};
int main()

{   
    utility item2;
    item2.read();
    item2.display();

    return 0;
}
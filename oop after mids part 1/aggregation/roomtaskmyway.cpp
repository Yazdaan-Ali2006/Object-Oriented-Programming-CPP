#include <iostream>
using namespace std;
class room
{
private:
    string name;
    int sqft;

public:
    room()
    {
        name = " ";
        sqft = 0;
    }
    room(string name, int sqft)
    {
        this->name = name;
        this->sqft = sqft;
    }
    void display()
    {
        cout << "NAME:" << name << " " << "AREA: " << sqft << endl;
    }
};
class house
{
private:
    string address;
    room r[3];
    int roomcount;

public:
    house(string a)
    {
        address = a;
        roomcount = 0;
    }
    void addroom(string address,int area){
        r[roomcount++]=room(address,area);
    }
    void display(){
        cout<<"HOUSE:"<<address<<" ROOMS:"<<roomcount<<endl;
        for(int i=0;i<3;i++){
            r[i].display();
        }
    }

};
int main()
{  house h1("KHI,PHASE 4");
h1.addroom("KITCHEN",200);
h1.addroom("LIVINGROOM",220);
h1.addroom("STUDYROOM",260);
h1.display();

 house h2("KHI,PHASE 3");
h2.addroom("WASHROOM",200);
h2.addroom("CHANGINGROOM",220);
h2.addroom("STOREROOM",260);
h2.display();


    return 0;
}
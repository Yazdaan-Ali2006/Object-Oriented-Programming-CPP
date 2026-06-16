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
        cout << "NAME:" << name << " Square feet:" << sqft << endl;
    }
};
class house
{
    string address;
    int roomcount;
    room r[3];

public:
    house(string a)
    {
        address = a;
        roomcount = 0;
    }
    void addroom(string name, int area)
    {    
        if(area<0){
            throw("INVALID AREA");
        }
        r[roomcount++] = room(name, area);

    }
    void display()
    {
        cout << "HOUSE ADDRESS:" << address << endl;
        cout << "ROOM COUNT:" << roomcount << endl;
        cout << "==========ALL ROOMS======" << endl;
        for (int i = 0; i < 3; i++)
        {
           r[i].display();
        }
    }
};
    int main()
    { 
        house h1("L5-MAAZ GARDEN");
       try{
        h1.addroom("STUDYROOM",-1);
        h1.addroom("LIVINGROO",250);
        h1.addroom("BEDROOM",300);
       }
       catch(const char *msg){
        cout<<"EXCEPTION OCCUR:"<<msg<<endl;
        return 0;

       }
        h1.display();
         
        return 0;
    }
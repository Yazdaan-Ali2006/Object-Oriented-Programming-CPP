#include<iostream>
using namespace std;
class points{
public:
    double x;
     double y;
};
class vector{
    public:
    points start;
    points end;
    void display(){
        cout<<"("<<start.x<<","<<start.y<<")-->("<<end.x<<","<<end.y<<")"<<endl;
    }
    void offset(double x,double y){
        start.x+=x;
        start.y+=y;
        end.x+=x;
        end.y+=y;
    }
    void distance(){
           cout<<"("<<start.x-start.y<<","<<end.x-end.y<<")"<<endl;
    
    }
};
int main()
{  vector v1;
    v1.start.x=1;
    v1.start.y=2;
    v1.end.x=5;
    v1.end.y=6;
    v1.distance();
    v1.display();

    v1.offset(1,1);
    v1.display();
    return 0;
}
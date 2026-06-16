#include<iostream>
using namespace std;
class vehicle{
  public:  
    int engine_capacity;
    int wheels;
    float fuel_average;
    
};
class bike :public vehicle{
    public:
    int guard;
    int carrier;
    bike(int engine_capacity, int wheels,float fuel average,  int guard, int carrier);
    
};
int main()
{ 
    return 0;
}
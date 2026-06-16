#include <iostream>
#include <cmath>

using namespace std;
class Point
{
private:
    double x, y;

public:
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}
    friend double calculateDistance(const Point &p1, const Point &p2);
};
double calculateDistance(const Point &p1, const Point &p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main()
{
    Point p1(1.0, 2.0);
    Point p2(4.0, 6.0);

    double dist = calculateDistance(p1,
                                    p2);
    cout << "Distance between points: "
         << dist << endl;

    return 0;
}
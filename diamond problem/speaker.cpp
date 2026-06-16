#include <iostream>
using namespace std;
class speaker
{
public:
    int volume;

    void playmusic()
    {
        cout << "Playing music of speaker...." << endl;
    }
};
class clock
{
    public:
    int volume;

    void showtime()
    {
        cout << "showing time..." << endl;
    }
    void setalarm(int b)
    {
        volume = b;
    }
};

class smartalarm : public speaker, clock
{
public:
    smartalarm(int v1, int v2)
    {
        speaker::volume = v1;
        clock::volume = v2;
    }
    void print()
    {
        cout << speaker::volume << endl;
        cout << clock::volume << endl;
    }
};
int main()
{
    smartalarm s(10, 20);
    s.print();
    return 0;
}
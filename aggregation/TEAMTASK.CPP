#include <iostream>
using namespace std;
class Player
{
private:
    string name;
    int rating;

public:
    Player()
    {
        name = " ";
        rating = 0;
    }
    Player(string n, int r)
    {
        name = n;
        rating = r;
    }
    string getname()
    {
        return name;
    }
    int getrating()
    {
        return rating;
    }
};
class team
{
    string teamname;
    Player *p[10]; // ARRAY CONTAINING POINTERS...
    int playercount;

public:
    team(string tname)
    {
        playercount = 0;

        teamname = tname;
        for (int i = 0; i < 10; i++)
        {
            p[i] = nullptr;
        }
    }
    void addplayer(Player *item)
    {
        if (playercount < 10)
        {
            p[playercount++] = item;
        }
        else
        {
            cout << "TEAM IS FULL" << endl;
        }
    }
    void removeplayer(string name)
    {
        for (int i = 0; i < playercount; i++)
        {
            if (p[i]->getname() == name)
            {
                for (int j = i; j < playercount-1; j++)
                {
                    p[j] = p[j + 1];
                }
            }
            p[--playercount] = nullptr;
        }
    }

    void displayteam()
    {
        cout << "TEAM:" << teamname << endl;
        for (int i = 0; i < playercount; i++)
        {
            cout << p[i]->getname() << endl;
            cout << p[i]->getrating() << endl;
        }
    }
};
int main()
{
    Player p1("alice", 10);
    Player p2("Bob", 23);
    team t1("alpha");
    t1.addplayer(&p1);
    t1.addplayer(&p2);
    // t1.removeplayer("alice");
    t1.displayteam();

    return 0;
}
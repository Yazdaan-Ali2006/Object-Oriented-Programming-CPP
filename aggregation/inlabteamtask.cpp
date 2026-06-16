#include <iostream>
using namespace std;
class Player
{
private:
    string playername;
    int rating;

public:
    Player()
    {
        playername = " ";
        rating = 0;
    }
    Player(string name, int rating)
    {
        playername = name;
        this->rating = rating;
    }
    void display()
    {
        cout << "PLAYER NAME:" << playername << "|" << "RATING:" << rating << endl;
        ;
    }
};
class Team
{
private:
    string teamname;
    Player *p[10];
    int playercount;

public:
    Team(string name)
    {
        playercount = 0;
        teamname = name;
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
    void display(){
        cout<<"TEAM NAME:"<<teamname<<endl;
        cout<<"NUMBER OF PLAYERS:"<<playercount<<endl;
        cout<<"DISPLAYING PLAYERS"<<endl;
        for(int i=0;i<playercount;i++){
            p[i]->display();
        }
    }
};
int main()
{
    Player p1("ali", 10);
    Player p2("azhar", 12);
    Team t1("ALPHA");
    t1.addplayer(&p1);
    t1.addplayer(&p2);
    t1.display();


    return 0;
}
#include <iostream>
#include <string>
using namespace std;
class Computer
{
private:
    string brand;
    string serialNumber;
    bool isRunning;

public:
    void start();
    void shutdown();
    void showSystemInfo();
};

class ExpansionCard
{
private:
    const string model;
    const string manufacturer;
    int powerConsumption;
    bool active;

public:
    ExpansionCard(string m, string manu, int power);

    void enable();
    void disable();
    int getPowerUsage();
    string getInfo();
};

class Motherboard
{
private:
    string chipset;
    int maxSlots;
    bool poweredOn;
    int powerCapacity;

public:
    bool installCard(ExpansionCard card);
    bool removeCard(ExpansionCard card);
    int totalCardPowerUsage();
    void powerOn();
    void powerOff();
    bool hasFreeSlots();
    bool bootCheck();
};
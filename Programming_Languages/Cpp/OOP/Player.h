#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player
{
    private:
    string name;
    int health;
    int xp;

    public:

    void set_name(string name_val)
    {
        name = name_val;
    }

    //Constructor - should same with the name of class
    Player()
    {
        cout << "No args consturctor called" << endl;
    }

    Player(std::string new_name)
    {
        cout << "Player's name is : " << name << endl;
    }


    Player(std::string name, int health, int xp)
    {
        cout << "Player's name is " << name << " and health is " << health << " and xp is " << xp << endl;
    }

    //Destructor
    ~Player()
    {
        cout << name << " distructed automatically" << endl;
    };
};
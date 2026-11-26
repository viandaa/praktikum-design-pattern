#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string name;
    int level;
public:
    Character(string n, int l) : name(n), level(l) {}
    void showStatus() {
        cout << name << " (Level " << level << ")" << endl;
    }
};

class Enemy : public Character {
public:
    Enemy(string n, int l) : Character(n, l) {}
    void attack() {
        cout << name << " attacks the player!" << endl;
    }
};

class NPC : public Character {
public:
    NPC(string n, int l) : Character(n, l) {}
    void talk() {
        cout << name << " says: Welcome, traveler!" << endl;
    }
};

//TANPA VIRTUAL : akan ada 2 Character di Boss
class Boss : public Enemy, public NPC {
public:
    Boss(string n, int l) : Enemy(n, l), NPC(n, l) {}
    void intro() {
        cout << "I am the mighty boss!" << endl;
    }
};

int main() {
    Boss b("Hydra", 50);

    //Error / Ambigu
    //b.showStatus(); // Ambigu

    b.Enemy::showStatus(); // akses via jalur Enemy
    b.NPC::showStatus(); //akses via jalur NPC

    b.attack();
    b.talk();
    b.intro();

    return 0;
}
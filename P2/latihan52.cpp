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

//PERBEDAAN: Tambahkan keyword "virtual"
class Enemy : virtual public Character {
public:
    Enemy(string n, int l) : Character(n, l) {}
    void attack() {
        cout << name << " attacks the player!" << endl;
    }
};

class NPC : virtual public Character {
public:
    NPC(string n, int l) : Character(n, l) {}
    void talk() {
        cout << name << " says: Welcome, traveler!" << endl;
    }
};

class Boss : public Enemy, public NPC {
public:
    //Hanya satu Character di memori
    Boss(string n, int l)
        : Character(n, l), Enemy(n, l), NPC(n, l) {}
    void intro() {
        cout << "I am the mighty boss!" << endl;
    }
};

int main() {
    Boss b("Hydra", 50);
    b.showStatus(); //Tidak ambigu
    b.attack();
    b.talk();
    b.intro();
    return 0;
}
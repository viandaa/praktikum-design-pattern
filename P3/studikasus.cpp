#include <iostream>
using namespace std;

class Character {
public:
    virtual void attack() {
        cout << "Character attacks!" << endl;
    }
};

class Warrior : public Character {
public:
    void attack() override {
        cout << "Warrior swings a sword!" << endl;
    }
};

class Mage : public Character {
public:
    void attack() override {
        cout << "Mage casts a fireball!" << endl;
    }
};

class Archer : public Character {
public:
    void attack() override {
        cout << "Archer shoots an arrow!" << endl;
    }
};

int main() {
    Warrior warrior;
    Mage mage;
    Archer archer;

    Character* team[3];

    team[0] = &warrior;
    team[1] = &mage;
    team[2] = &archer;

    for (int i = 0; i < 3; i++) {
        team[i]->attack();
    }

    return 0;
}
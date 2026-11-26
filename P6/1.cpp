#include <iostream>
using namespace std;

class Enemy {
protected:
    int hp; // bisa diakses turunan

public:
    Enemy(int hp) : hp(hp) {}

    void showHP() {
        cout << "HP: " << hp << "\n";
    }
};

class Slime : public Enemy {
public:
    Slime() : Enemy(30) {}
};

class Goblin : public Enemy {
public:
    Goblin() : Enemy(45) {}
};

int main() {
    Slime s;
    Goblin g;

    s.showHP();
    g.showHP();

    return 0;
}
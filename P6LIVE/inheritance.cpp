#include <iostream>
using namespace std;

class Enemy {
protected:
    int hp;

public:
    Enemy(int hp) : hp(hp) {}

    void showHP() {
        cout << "HP: " << hp << "\n";
    }
};

// Class yang sudah ada
class Slime : public Enemy {
public:
    Slime() : Enemy(30) {}
};

// Class yang sudah ada
class Goblin : public Enemy {
public:
    Goblin() : Enemy(45) {}
};

// Class baru 1
class Orc : public Enemy {
private:
    int strength;
    int armor;

public:
    Orc(int hp, int strength, int armor)
        : Enemy(hp) {
        this->strength = strength;
        this->armor = armor;
    }

    void showInfo() {
        showHP();
        cout << "Strength: " << strength << "\n";
        cout << "Armor: " << armor << "\n";
    }
};

// Class baru 2
class Dragon : public Enemy {
private:
    int firePower;
    int wingSize;

public:
    Dragon(int hp, int firePower, int wingSize)
        : Enemy(hp) {
        this->firePower = firePower;
        this->wingSize = wingSize;
    }

    void showInfo() {
        showHP();
        cout << "Fire Power: " << firePower << "\n";
        cout << "Wing Size: " << wingSize << "\n";
    }
};

int main() {
    // Object class baru
    Orc o(100, 80, 60);
    Dragon d(200, 100, 15);

    cout << "=== ORC ===" << endl;
    o.showInfo();

    cout << "\n=== DRAGON ===" << endl;
    d.showInfo();

    return 0;
}
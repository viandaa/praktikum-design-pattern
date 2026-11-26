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

    void takeDamage(int value) {
        if (value > 0) {
            hp -= value;

            if (hp < 0) {
                hp =0;
            }

            cout << "Damage: " << value << "\n";
            cout << "HP sekarang: " << hp << "\n";
        }
        else {
            cout << "Damage harus positif!" << endl;
        }
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

    cout << "\nOrc diserang!" << endl;
    o.takeDamage(30);

    cout << "\n=== DRAGON ===" << endl;
    d.showInfo();

    cout << "\nDragon diserang!" << endl;
    d.takeDamage(200);

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Enemy {
public:
    virtual ~Enemy() {}
    virtual string name() const = 0;
    virtual int attackDamage() const = 0;
    virtual void attack() const {
        cout << name() << " attacks for " << attackDamage() << " damage!\n";
    }
};

class Goblin : public Enemy {
public:
    string name() const {return "Goblin"; }
    int attackDamage() const { return 4; }
};

class Orc : public Enemy {
public:
    string name() const { return "Orc"; }
    int attackDamage() const { return 7; }
};

class Troll : public Enemy {
public:
    string name() const { return "Troll"; }
    int attackDamage() const { return 10; }
};

class Skeleton : public Enemy {
public:
    string name() const { return "Skeleton"; }
    int attackDamage() const { return 6; }
};

int main() {
    cout << "=== Percobaan 1: Hardcore Creation ===\n";
    cout << "Input: goblin/orc/troll/skeleton/mage   (q untuk keluar)\n\n";

    while (true) {
        cout << "Spawn type> ";
        string type;
        cin >> type;
        if (!cin) return 0;
        if (type == "q") break;

        Enemy* enemy = NULL;

        if (type == "goblin") enemy = new Goblin();
        else if (type == "orc") enemy = new Orc();
        else if (type == "troll") enemy = new Troll();
        else if (type == "skeleton") enemy = new Skeleton();
        else {
            cout << "[ERROR]Unknown type\n" << endl;
            continue;
        }

        cout << "[SPAWN] " << enemy->name() << "\n";
        enemy->attack();

        delete enemy;
        enemy = NULL;
        cout << "----\n";
    }
    return 0;
}
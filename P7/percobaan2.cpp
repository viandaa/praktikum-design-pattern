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

class Mage : public Enemy {
public:
    string name() const { return "Mage"; }
    int attackDamage() const { return 12; }
};

class EnemyFactory {
public:
    static Enemy* create(const string& type) {
        if (type == "goblin") return new Goblin();
        if (type == "orc") return new Orc();
        if (type == "troll") return new Troll();
        if (type == "skeleton") return new Skeleton();
        if (type == "mage") return new Mage();
        return NULL;
    }
};

int main() {
    cout << "=== Percobaan 2: Simple Factory ===\n";
    cout << "Input: goblin/orc/troll/skeleton/mage  (q untuk keluar)\n\n";

    while (true) {
        cout << "Spawn type> ";
        string type;
        cin >> type;
        if (!cin) return 0;
        if (type == "q") break;

        Enemy* enemy = EnemyFactory::create(type);
        if (enemy == NULL) {
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
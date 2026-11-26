#include <iostream>
#include <map>
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
    string name() const { return "Goblin"; }
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

class Mage : public Enemy {
public:
    string name() const { return "Mage"; }
    int attackDamage() const { return 9; }
};

class Slime : public Enemy {
public:
    string name() const { return "Slime"; }
    int attackDamage() const { return 3; }
};

typedef Enemy* (*CreatorFn) ();

Enemy* createGoblin() { return new Goblin(); }
Enemy* createOrc() { return new Orc(); }
Enemy* createTroll() { return new Troll(); }
Enemy* createMage() { return new Mage(); }
Enemy* createSlime() { return new Slime(); }

class EnemyFactory {
public: 
    void registerType(const string& type, CreatorFn fn) {
        creators[type] = fn;
    }

    Enemy* create(const string& type) const {
        map<string, CreatorFn>::const_iterator it = creators.find(type);
        if (it == creators.end()) return NULL;
        return it->second();
    }

    private:
        map<string, CreatorFn> creators;
};

int main() {
    cout << "=== Percobaan 3: Factory Registry ===\n";

    EnemyFactory factory;
    factory.registerType("goblin", createGoblin);
    factory.registerType("orc", createOrc);
    factory.registerType("troll", createTroll);
    factory.registerType("mage", createMage);
    factory.registerType("slime", createSlime);

    cout << "Input: goblin/orc/troll/mage/slime (q untuk keluar)\n\n";

    while (true) {
        cout << "Spawn type> ";
        string type;
        cin >> type;
        if (!cin) return 0;
        if (type == "q") break;

        Enemy* enemy = factory.create(type);
        if (enemy == NULL) {
            cout << "[ERROR] Unknown type\n" << endl;
            continue;
        }

        cout << "[SPAWN] " << enemy->name() << "\n";
        enemy->attack();
        delete enemy;
        enemy = NULL;
        cout << "---\n";
    }

    return 0;
}
#include <iostream>
using namespace std;

// Kelas dasar
class Character {
public:
    // Fungsi virtual
    virtual void speak() {
        cout << "I am a Character." << endl;
    }

    // Fungsi virtual kedua
    virtual void showRole() {
        cout << "Role: Character" << endl;
    }
};

// Turunan pertama
class Warrior : public Character {
public:
    void speak() override {
        cout << "I am a Warrior!" << endl;
    }

    void showRole() override {
        cout << "Role: Warrior" << endl;
    }
};

// Turunan kedua
class Mage : public Character {
public:
    void speak() override {
        cout << "I am a Mage!" << endl;
    }

    void showRole() override {
        cout << "Role: Mage" << endl;
    }
};

// Turunan ketiga
class Archer : public Character {
public:
    void speak() override {
        cout << "I am an Archer!" << endl;
    }

    void showRole() override {
        cout << "Role: Archer" << endl;
    }
};

int main() {
    Character base;
    Warrior w;
    Mage m;
    Archer a;

    // Pointer ke kelas dasar
    Character* ptr;

    // Menunjuk ke object Warrior
    ptr = &w;
    ptr->speak();
    ptr->showRole();

    // Menunjuk ke object Mage
    ptr = &m;
    ptr->speak();
    ptr->showRole();

    // Menunjuk ke object Archer
    ptr = &a;
    ptr->speak();
    ptr->showRole();

    return 0;
}
#include <iostream>
using namespace std;

// deklarasi class
class Weapon {
    public:
        string name;
        int damage;

        // inisialisasi constructor
        Weapon(string weapon_name, int weapon_damage) {
            name = weapon_name;
            damage = weapon_damage;
        }

        // deklarasi method attack()
        void attack() {
            cout << name << " menyerang dan memberikan "
                 << damage << " damage." << endl;
        }
};

int main() {
    // inisialisasi object 1
    Weapon weapon_1("Pedang", 30);

    // inisialisasi object 2
    Weapon weapon_2("Busur", 20);

    // inisialisasi object 3
    Weapon weapon_3("Tongkat Sihir", 40);

    // memanggil method attack dengan object
    weapon_1.attack();
    weapon_2.attack();
    weapon_3.attack();

    return 0;
}
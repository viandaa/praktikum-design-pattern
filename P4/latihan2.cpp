#include <iostream>

using namespace std;

// ======================================================
// ABSTRACT CLASS: WEAPON
// ======================================================

// Weapon adalah abstract class karena memiliki
// pure virtual function Attack()
class Weapon {
public:

    // ABSTRACT FUNCTION / PURE VIRTUAL FUNCTION
    // Fungsi ini wajib diimplementasikan oleh
    // setiap class turunan Weapon
    virtual void Attack() = 0;

    // Fungsi biasa yang dapat digunakan oleh
    // semua class turunan
    void Reload() {
        cout << "Reloading weapon..." << endl;
    }
};


// ======================================================
// CLASS TURUNAN: SWORD
// ======================================================

class Sword : public Weapon {
public:

    // OVERRIDE
    // Mengimplementasikan fungsi Attack() dari Weapon
    void Attack() override {
        cout << "Slash with sword!" << endl;
    }
};


// ======================================================
// CLASS TURUNAN: GUN
// ======================================================

class Gun : public Weapon {
public:

    // OVERRIDE
    // Mengimplementasikan fungsi Attack() dari Weapon
    void Attack() override {
        cout << "Shoot with gun!" << endl;
    }
};


// ======================================================
// CLASS TURUNAN: BOW
// ======================================================

class Bow : public Weapon {
public:

    // OVERRIDE
    // Mengimplementasikan fungsi Attack() dari Weapon
    void Attack() override {
        cout << "Shoot arrow with bow!" << endl;
    }
};


// ======================================================
// FUNCTION ATTACK ALL
// ======================================================

// Fungsi AttackAll menerima array pointer Weapon*
// dan jumlah senjata yang ada di dalam array
void AttackAll(Weapon* weapons[], int size) {

    // Melakukan perulangan untuk semua senjata
    for (int i = 0; i < size; i++) {

        // Memanggil Attack() dari setiap senjata
        weapons[i]->Attack();
    }
}


// ======================================================
// MAIN PROGRAM
// ======================================================

int main() {

    // Array pointer Weapon*
    Weapon* weapons[3];

    // Membuat object dari class turunan
    weapons[0] = new Sword();
    weapons[1] = new Gun();
    weapons[2] = new Bow();


    // Memanggil AttackAll()
    // untuk menyerang menggunakan semua senjata
    AttackAll(weapons, 3);

    cout << endl;


    // Reload semua senjata
    for (int i = 0; i < 3; i++) {
        weapons[i]->Reload();
    }


    // Menghapus object yang dibuat dengan new
    for (int i = 0; i < 3; i++) {
        delete weapons[i];
    }

    return 0;
}
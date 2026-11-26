#include <iostream>
using namespace std;

// deklarasi class
class Character {
    public:
        string name;
        int level;
        int experience;

        // inisialisasi constructor
        Character(string character_name) {
            name = character_name;
            level = 1;
            experience = 0;
        }

        // deklarasi method gainExperience()
        void gainExperience(int experience_amount) {
            experience += experience_amount;

            cout << name << " mendapatkan "
                 << experience_amount
                 << " experience." << endl;

            // memeriksa apakah experience sudah cukup
            if (experience >= 100) {
                levelUp();
            }
        }

        // deklarasi method levelUp()
        void levelUp() {
            level++;
            experience = 0;

            cout << name << " naik ke level "
                 << level << "!" << endl;
        }
};

int main() {
    // inisialisasi object
    Character character_1("Kyungsoo");

    // menampilkan status awal karakter
    cout << "Nama: " << character_1.name << endl;
    cout << "Level: " << character_1.level << endl;
    cout << "Experience: " << character_1.experience << endl;

    cout << endl;

    // menambahkan experience
    character_1.gainExperience(50);

    cout << "Level: " << character_1.level << endl;
    cout << "Experience: " << character_1.experience << endl;

    cout << endl;

    // menambahkan experience
    character_1.gainExperience(50);

    cout << "Level: " << character_1.level << endl;
    cout << "Experience: " << character_1.experience << endl;

    return 0;
}
#include <iostream>
using namespace std;

class Player {
private:
    int hp;
    int gold;
    int level;

public:
    // Constructor (memberi nilai awal ketika objek player sibuat)
    Player() {
        hp = 100;
        gold = 0;
        level = 1;
    }

    // Getter (untuk ambil nilai atribut private, karena atributnya tidak dapat diakses langsung dari luar class maka pakai getHP(), getGold(), getLevel())
    int getHP() {
        return hp;
    }

    int getGold() {
        return gold;
    }

    int getLevel() {
        return level;
    }

    // Heal (untuk menambah HP, parameter value menentukan jumlah hp yang ditambahkan, sebelum hp diubah lakukan validasi agar nilai heal harus lebih dari 0)
    void heal(int value) {
        if (value > 0) {
            if (hp + value > 100) {
                hp = 100;
            }
            else {
                hp = hp + value;
            }

            if (hp == 100) {
                level = level + 1;
            }

            cout << "Player healed " << value
                 << " HP. Sekarang HP = " << hp << endl;
        }
        else {
            cout << "Nilai heal harus positif!" << endl;
        }
    }

    // Damage (untuk mengurangi hp, nlainya harus + dan hp dibatasi agar tidak kurang dari 0)
    void damage(int value) {
        if (value > 0) {
            hp = hp - value;

            if (hp < 0) {
                hp = 0;
            }

            cout << "Player kena damage " << value
                 << ". Sekarang HP = " << hp << endl;
        }
        else {
            cout << "Nilai damage harus positif!" << endl;
        }
    }

    // Add Gold (untuk tambah gold)
    void addGold(int value) {
        if (value > 0) {
            gold = gold + value;

            cout << "Menambahkan " << value
                 << " gold. Total gold = " << gold << endl;
        }
        else {
            cout << "Nilai gold yang ditambah harus positif!" << endl;
        }
    }

    // Spend Gold (untuk mngurangi gold, sebelum dikurangi cek dulu apakah gold yang dipunya cukup)
    void spendGold(int value) {
        if (value > 0) {
            if (value <= gold) {
                gold = gold - value;

                cout << "Menghabiskan " << value
                     << " gold. Sisa gold = " << gold << endl;
            }
            else {
                cout << "Gold tidak cukup!" << endl;
            }
        }
        else {
            cout << "Nilai pengeluaran harus positif!" << endl;
        }
    }

    // Show Status (untuk menampilkan kondisi player)
    void showStatus() {
        cout << "HP = " << hp
             << ", Gold = " << gold
             << ", Level = " << level << endl;
    }
};

int main() {
    Player p; //objek p dri class Player, kemudian menjalani beberapa method

    cout << "=== STATUS AWAL ===" << endl;
    p.showStatus();

    cout << "\n=== SETELAH AKSI ===" << endl;

    p.damage(30);
    p.heal(20);

    p.addGold(150);
    p.spendGold(50);

    p.showStatus();

    return 0;
}
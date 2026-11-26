#include <iostream>
using namespace std;

class Player {
private:
    int hp;
    int gold;

public:
    // Constructor
    Player() {
        hp = 100;
        gold = 0;
    }

    // Getter
    int getHP() {
        return hp;
    }

    int getGold() {
        return gold;
    }

    void heal(int value) {
        if (value > 0) {
            hp = hp + value;

            if (hp > 100) {
                hp = 100;
            }

            cout << "Player healed " << value
                 << " HP. Sekarang HP = " << hp << endl;
        }
        else {
            cout << "Nilai heal harus positif!" << endl;
        }
    }

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

    void addGold(int value) {
        if (value > 0) {
            gold = gold + value;

            cout << "Gold ditambahkan " << value
                 << ". Total gold = " << gold << endl;
        }
        else {
            cout << "Nilai gold yang ditambah harus positif!" << endl;
        }
    }

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
};

int main() {
    Player p;

    cout << "=== STATUS AWAL ===" << endl;
    cout << "HP = " << p.getHP()
         << ", Gold = " << p.getGold() << endl;

    cout << "=== SETELAH AKSI ===" << endl;

    p.damage(30);
    p.heal(20);
    p.addGold(150);
    p.spendGold(50);

    cout << "=== STATUS AKHIR ===" << endl;
    cout << "HP = " << p.getHP()
         << ", Gold = " << p.getGold() << endl;

    return 0;
}
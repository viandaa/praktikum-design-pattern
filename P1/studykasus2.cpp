#include <iostream>
using namespace std;

// deklarasi class
class Player {
    public:
        string name;
        int health;

        // inisialisasi constructor
        Player(string player_name, int player_health) {
            name = player_name;
            health = player_health;
        }

        // deklarasi method attack()
        void attack(Player &enemy) {
            enemy.health -= 10;

            cout << name << " menyerang " << enemy.name << endl;
            cout << enemy.name << " menerima 10 damage." << endl;
        }

        // deklarasi method displayHealth()
        void displayHealth() {
            cout << "Health " << name << ": "
                 << health << endl;
        }
};

int main() {
    // inisialisasi object player 1
    Player player_1("Kyungsoo", 100);

    // inisialisasi object player 2
    Player player_2("KAI", 100);

    // menampilkan health awal
    player_1.displayHealth();
    player_2.displayHealth();

    cout << endl;

    // player 1 menyerang player 2
    player_1.attack(player_2);

    cout << endl;

    // menampilkan health setelah diserang
    player_1.displayHealth();
    player_2.displayHealth();

    return 0;
}
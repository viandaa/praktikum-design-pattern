#include <iostream>
using namespace std;

class Player {
    public:
        int health;
        string name;
};

int main() {
    //Membuat objek player
    Player player1;

    //Mengisi data pemain
    player1.health = 100;
    player1.name = "Dani";

    //Menampilkan informasi pemain
    cout << "Nama Pemain: " << player1.name << endl;
    cout << "Kesehatan Pemain: " << player1.health << endl;

    //Mengubah status pemain setelah menerima damage
    player1.health -= 20;

    //Menampilkan informasi setelah damage
    cout << "Kesehatan Pemain setelah diserang: " << player1.health << endl;

    return 0;
}
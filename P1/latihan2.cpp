#include <iostream>
using namespace std;

class Player {
    public:
        int health;
        string name;
        double score;
};

int main() {
    //Membuat objek player 1
    Player player1;
    //Mengisi data pemain 1
    player1.health = 100;
    player1.name = "Dhani";
    player1.score = 99.998;

    //Menampilkan informasi pemain 1
    cout << "Nama Pemain 1: " << player1.name << endl;
    cout << "Kesehatan Pemain 1: " << player1.health << endl;
    cout << "Skor yang diperoleh: " << player1.score << endl;
    cout << "\n";

    //Membuat objek player 2
    Player player2;
    //Mengisi data pemain 2
    player2.health = 100;
    player2.name = "Rian";
    player2.score = 80.89;

    //Menampilkan informasi pemain 2
    cout << "Nama Pemain 2: " << player2.name << endl;
    cout << "Kesehatan Pemain 2: " << player2.health << endl;
    cout << "Skor yang diperoleh: " << player2.score << endl;
    cout << "\n";

    //Mengubah status pemain setelah menerima damage
    player1.health -= 20;
    player1.score -= 50;

    player2.health -= 20;
    player2.score -= 50;

    //Menampilkan informasi setelah damage
    cout << "Kesehatan Pemain 1 setelah diserang: " << player1.health << endl;
    cout << "Skor Pemain 1 setelah diserang: " << player1.score << endl;
    cout << "Kesehatan Pemain 2 setelah diserang: " << player2.health << endl;
    cout << "Skor Pemain 2 setelah diserang: " << player2.score << endl;

    return 0;
}
#include <iostream>
using namespace std;

//deklarasi class
class GameCharacter{
    public:
        //Memanggil method result
        void result(string username, int health_player);

};

//deklarasi method result() di luar class
void GameCharacter::result(string username, int health_player){
    health_player -=20;

    cout << "Nama Player: " << username << endl;
    cout << "Health: " << health_player << endl;
}

int main() {
    //inisialisasi object
    GameCharacter player_1;

    //memanggil method result
    player_1.result("dhani", 90);
}
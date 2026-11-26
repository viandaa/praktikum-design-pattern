#include <iostream>
using namespace std;

//deklarasi class
class GameCharacter{
    public:
        string name;

    //deklarasi method speak() di dalam class
    void speak(){
        cout << "Halo " << name << ". ";
        cout << "Selamat datang di mata kuliah PBO" << endl;
    }
};

int main() {
    //inisialisasi object
    GameCharacter player_1;

    //input nama dengan object
    player_1.name = "Rian";

    //Memanggil method speak dengan object player 1
    player_1.speak();
}
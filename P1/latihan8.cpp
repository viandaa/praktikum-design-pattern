#include <iostream>
using namespace std;

//deklrasi class
class GameCharacter{
    public:
        string name;
        int health;
        double score;

        //memanggil constructor
        GameCharacter(string username, int health_player, double score_player);
};

//inialisasi constructor di luar class
GameCharacter::GameCharacter(string username, int health_player, double score_player){
    name = username;
    health_player = health;
    score = score_player;
}

int main() {
    //inialisasi object 1
    GameCharacter game_character_1("Dhani", 90, 99.87);

    //inialisasi object 2
    GameCharacter game_character_2("Rian", 80, 70.76);

    //menampilkan informasi 1 dengan constructor
    cout << game_character_1.name << game_character_1.health << game_character_1.score << endl;
    //menampilkan informasi 2 dengan constructor
    cout << game_character_2.name << game_character_2.health << game_character_2.score << endl;

    return 0;
}
#include <iostream>
using namespace std;

void attack() {
    cout << "Basic attack!" << endl;
}

void attack(int power) {
    cout << "Attack power: " << power << endl;
}

void attack(string skillName) {
    cout << "Using skill: " << skillName << endl;
}

int main() {
    attack(); //memanggil versi tanpa parameter
    attack(50); //memanggil versi denganint
    attack("Fireball"); //memanggil versi dengan string

    // Eksperimen
    // attack(3, 5); // <--- aktifkan ini dan coba compile!
}
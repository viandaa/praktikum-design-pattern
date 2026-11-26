#include <iostream>
using namespace std;

class Bullet {
private:
    int id;
    bool active;
public:
    Bullet(int id) {
        this->id = id;
        this->active = false;
    }

    void shoot() {
        active = true;
        cout << "Bullet "<< id << " ditembakkan." << endl;
    }

    void reset() {
        active = false;
        cout << "Bullet "<< id << " dikembalikan." << endl;
    }

    bool isActive() {
        return active;
    }

    int getId() {
        return id;
    }
};

int main() {
    Bullet b1 (1), b2 (2), b3 (3);

    b1.shoot();
    b2.shoot();
    b3.shoot();

    cout << "\nBullet 2 selesai digunakan.\n";
    b2.reset();

    cout << "\nBullet 2 digunakan kembali.\n";
    b2.shoot();

    return 0;
}
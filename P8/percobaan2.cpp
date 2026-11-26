#include <iostream>
#include <vector>
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

    bool isActive() const {
        return active;
    }

    void shoot() {
        active = true;
        cout << "Bullet " << id << " ditembakkan." << endl;
    }

    void reset() {
        active = false;
        cout << "Bullet " << id << " dikembalikan." << endl;
    }

    int getId() const {
        return id;
    }
};

class BulletPool {
private:
    vector<Bullet> bullets;
public:
    BulletPool(int size) {
        for (int i = 0; i < size; i++) {
            bullets.push_back(Bullet(i + 1));
        }
    }

    Bullet* getBullet() {
        for (int i = 0; i < bullets.size(); i++) {
            if (!bullets[i].isActive()) {
                return &bullets[i];
            }
        }
        return nullptr;
    }

    void showStatus() {
        cout << "\nStatus Bullet Pool:\n";
        for (int i = 0; i < bullets.size(); i++) {
            cout << "Bullet " << bullets[i].getId()
                 << " : "
                 <<     (bullets[i].isActive() ? "Active" : "inactive")
                 << endl;
        }
    }
};

int main() {
    BulletPool pool(3);
    
    Bullet* b1 = pool.getBullet();
    if (b1 != nullptr) b1->shoot();
    
    Bullet* b2 = pool.getBullet();
    if (b2 != nullptr) b2->shoot();
    
    Bullet* b3 = pool.getBullet();
    if (b3 != nullptr) b3->shoot();
    
    Bullet* b4 = pool.getBullet();
    if (b4 != nullptr) {
        b4->shoot();
    } else {
        cout << "Pool habis, tidak ada bullet tersedia." << endl;
    }
    
    pool.showStatus();
    
    cout << "\nMengembalikan Bullet 2...\n";
    b2->reset();
 
    Bullet* b5 = pool.getBullet();
    
    if (b5 != nullptr) b5->shoot();
    
    pool.showStatus();
    
    return 0;
}

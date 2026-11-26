#include <iostream>
#include <vector>
using namespace std;

class Enemy {
private:
    int id;
    bool active;
    int hp;

public:
    Enemy(int id) {
        this->id = id;
        this->active = false;
        this->hp = 100;
    }
    
    bool isActive() const {
        return active;
    }
    
    void spawn() {
        active = true;
        hp = 100;
        cout << "Enemy " << id << " spawn dengan HP " << hp << 
endl;
    }

    void defeat() {
        active = false;
        cout << "Enemy " << id << " dikalahkan dan kembali ke pool." << endl;
    }
 
    int getId() const {
        return id;
    }
 
    int getHp() const {
        return hp;
    }
};

class EnemyPool {
private:
    vector<Enemy> enemies;
public:
    EnemyPool(int size) {
        for (int i = 0; i < size; i++) {
            enemies.push_back(Enemy(i + 1));
        }
}

    Enemy* getEnemy() {
        for (int i = 0; i < enemies.size(); i++) {
            if (!enemies[i].isActive()) {
                return &enemies[i];
            }
        }
        return nullptr;
}

    void showStatus() {
        cout << "\nStatus Enemy Pool:\n";
        for (int i = 0; i < enemies.size(); i++) {
            cout << "Enemy " << enemies[i].getId()
                 << " : "
                 << (enemies[i].isActive() ? "Active" : "Inactive")
                 << endl;
        }
    }
};

int main() {
    EnemyPool pool(3);
    
    cout << "Wave 1 dimulai\n";
    Enemy* e1 = pool.getEnemy();
    Enemy* e2 = pool.getEnemy();
    Enemy* e3 = pool.getEnemy();
    
    if (e1) e1->spawn();
    if (e2) e2->spawn();
    if (e3) e3->spawn();
    
    pool.showStatus();
    
    cout << "\nEnemy 2 kalah.\n";
    if (e2) e2->defeat();
    
    pool.showStatus();
    
    cout << "\nSpawn enemy baru untuk wave berikutnya.\n";
    Enemy* e4 = pool.getEnemy();
    if (e4) e4->spawn();
    else cout << "Tidak ada enemy tersedia.\n";
    
    pool.showStatus();
    
    return 0;
}



#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Bullet {
public: 
    int x, y;
    bool active;

    Bullet() {
        x = 0;
        y = 0;
        active = false;
    }

    void active(int posX, int posY) {
        x = posX;
        y = posY;
        active = true;
    }

    bullet.activate(10, 9);

    void deactivate() {
        active = false;
    }

    void update() {
        if (active) {
            y--;
        }
        if (y < 0) {
            deactivate();
        }
    }

class BulletPool {
private:
    vector<Bullet> bullets;

    BulletPool() {
        for (int i = 0; i<10; i++) {
            bullets.push_back(Bullet());
        }
    }

    Bullet* getBullet() {
        for (int i = 0; i < bullets.size(); i++) {
            if (!bullets[i].active) {
                return &bullets[i];
            }
        }
        return nullptr;
    }

    vector<Bullet>& getBullets() {
        return bullets;
    }

    void update() {
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].update();
        }
    }

    int getActiveCount() {
        int count = 0;
        for (int i = 0; i < bullets.size(); i++) {
            if (bullets[i].active) {
                count++;
            }
        }
        return count;
    }
};

class Player {
public:
    int x;
    int y;

    Player() {
        x = 10;
        y = 10;
    }

    void moveleft() {
        if (x > 0) {
            x--;
        }
    }

    void moveRight() {
        if (x < 20) {
            x++;
        }
    }

    void shoot(BulletPool& pool) {
        Bullet* bullet = pool.getBullet();
        if (bullet != nullptr) {
            bullet->activate(x, y - 1);
            cout << "Robot menembakkan peluru!" << endl;
        } else {
            cout << "peluru habis! Tunggu peluru tersedia." << endl;
        }
    }
};

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

class MoveLeftCommand : public Command {
private:
    Player& player;

public:
    MoveLeftCommand(Player& p) : player(p) {}

    void execute() override {
        player.moveleft();
    }
};

class MoveRightCommand : public Command {
private:
    Player& player;

public:
    MoveRightCommand(Player& p) : player(p) {}

    void execute() override {
        player.moveRight();
    }
};

class ShootCommand : public Command {
private:
    Player& player;
    BulletPool& pool;

public:
    ShootCommand(Player& p, BulletPool& b)
        : player(p), pool(b) {}
    
    void execute() override {
        player.shoot(pool);
    }
};

class Enemy {
public:
    int x, y;
    bool alive;

    Enemy(int posX) {
        x = posX;
        y = 0;
        alive = true;
    }

    void update() {
        if (alive) {
            y++;
        }
    }

    void die() {
        alive = false;
    }
};

class Game {
private:
    Player player;
    BulletPool bulletPool;
    vector<Enemy> enemies;

    MoveLeftCommand leftCommand;
    MoveRightCommand rightCommand;

    bool running;
    int score;
    int turn;

public:
    Game() 
        : leftCommand(player),
          rightCommand(player),
          shootCommand(player, bulletPool) {

        running = true;
        score = 0;
        turn = 0;
        }

    void input() {
        char key;

        cout << "\nMasukkan aksi (A/D/Space/Q): ";

        cin.get(key);

        if (key == '\n') {
            cin.get(key);
        }

        if (key == 'a' || key == 'A') {
            leftCommand.execute();
        }
        else if (key == 'd' || key == 'D') {
            rightCommand.execute();
        }
        else if (key == ' ') {
            shootCommand.execute();
        }
        else if (key == 'q' || key == 'Q') {
            running = false;
        }
        else {
            cout << "Tombol tidak dikenali!" << endl;
        }
    }

    void update() {
        if (!running) {
            return;
        }

        turn++;

        if (turn % 4 == 0) {
            int randomX = rand() % 21;

            enemies.push_back(Enemy(randomX));

            cout << "Musuh baru muncul!" << endl;
        }

        bulletPool.update();

        if (turn % 2 == 0) {
            for (int i = 0; i < enemies.size(); i++) {
                enemies[i].update();
            }
        }

        vector<Bullet>& bullets = bulletPool.getBullets();

        for (int i = 0; i < enemies.size(); i++) {
            if (!enemies[i].alive) {
                continue;
            }

            for (int j = 0; j < bullets.size(); j++) {
                if (bullets[j].active &&
                    bullets[j].x == enemies[i].x &&
                    bullets[j].y == enemies[i].y) {

                    enemies[i].die();
                    bullets[j].deactivate();

                    score += 10;

                    cout << "Musuh berhasil dihancurkan!" << endl;
                    break;
                }
            }
        }

        for (int i = 0; i < enemies.size(); i++) {
            if (!enemies[i].alive) {
                enemies.erase(enemies.begin() + i);
                i--;
            }
        }

        for (int i = 0; i < enemies.size(); i++) {
            if (enemies[i].y >= player.y) {
                cout << "\nGAME OVER! Musuh mencapai robot!" << endl;

                running = false;
                break;
            }
        }
    }

    void render() {
        cout << "\n\n";
        cout << "=================================" << endl;
        cout << "       ROBOT DEFENSE ARENA       " << endl;
        cout << "=================================" << endl;

        cout << "Score         : " << score << endl;
        cout << "Turn          : " << turn << endl;
        cout << "Musuh aktif   : " << enemies.size() << endl;
        cout << "Peluru aktif   : " << bulletPool.getActiveCount() << endl;

        cout << "\n";

        for (int y = 0; y <=10; y++) {
            for (int x = 0; x <= 20; x++) {
                char symbol = '-';

                if (player.x == x && player.y == y) {
                    symbol = 'R';
                }

                for (int i = 0; i < enemies.size(); i++) {
                    if (enemies[i].alive &&
                        enemies[i].x == x &&
                        enemies[i].y == y) {
                        symbol = 'E';
                    }
                }

                vector<Bullet>& bullets = bulletPool.getBullets();

                for (int i = 0; i < bullets.size(); i++) {
                    if (bullets[i].active && 
                        bullets[i].x == x &&
                        bullets[i].y == y) {
                        symbol = '|';
                    }
                }

                cout << symbol << " ";
            }

            cout << endl;
        }

        cout << "\nR = Robot | E = Enemy | | = Bullet" << endl;
        cout << "A = Kiri | D = Kanan | Space = Tembak | Q = Keluar" << endl;
        cout << "=================================" << endl;
    }

    void run() {
        cout 
    }
};

int main() {

    cout << "ROBOT DEFENSE ARENA" << endl;
    cout << "game dimulai!" << endl;

    return 0;
}
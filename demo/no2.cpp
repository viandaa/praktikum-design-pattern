
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

// ==========================================
// CLASS PLAYER
// ==========================================

class Player {
private:
    int position;

public:
    Player() {
        position = 10;
    }

    void moveLeft() {
        if (position > 0)
            position--;
    }

    void moveRight() {
        if (position < 19)
            position++;
    }

    int getPosition() {
        return position;
    }

    void shoot(class BulletPool& pool);
};

// ==========================================
// CLASS ENEMY
// ==========================================

class Enemy {
private:
    int position;
    bool active;

public:
    Enemy(int pos) {
        position = pos;
        active = true;
    }

    int getPosition() {
        return position;
    }

    bool isActive() {
        return active;
    }

    void destroy() {
        active = false;
    }
};

// ==========================================
// CLASS BULLET
// ==========================================

class Bullet {
private:
    int x;
    int y;
    bool active;

public:
    Bullet() {
        x = 0;
        y = 0;
        active = false;
    }

    void activate(int posX, int posY) {
        x = posX;
        y = posY;
        active = true;
    }

    void update() {
        if (active) {
            y--;

            if (y < 0)
                active = false;
        }
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    bool isActive() {
        return active;
    }

    void deactivate() {
        active = false;
    }
};

// ==========================================
// OBJECT POOL PATTERN
// ==========================================

class BulletPool {
private:
    vector<Bullet> bullets;

public:
    BulletPool() {
        bullets.resize(5);
    }

    void getBullet(int playerPosition) {
        for (int i = 0; i < bullets.size(); i++) {
            if (!bullets[i].isActive()) {
                bullets[i].activate(playerPosition, 8);
                return;
            }
        }
    }

    void update() {
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].update();
        }
    }

    vector<Bullet>& getBullets() {
        return bullets;
    }
};

void Player::shoot(BulletPool& pool) {
    pool.getBullet(position);
}

// ==========================================
// COMMAND PATTERN
// ==========================================

class Command {
public:
    virtual void execute(Player& player,
                         BulletPool& pool) = 0;

    virtual ~Command() {}
};

class MoveLeftCommand : public Command {
public:
    void execute(Player& player,
                 BulletPool& pool) override {
        player.moveLeft();
    }
};

class MoveRightCommand : public Command {
public:
    void execute(Player& player,
                 BulletPool& pool) override {
        player.moveRight();
    }
};

class ShootCommand : public Command {
public:
    void execute(Player& player,
                 BulletPool& pool) override {
        player.shoot(pool);
    }
};

// ==========================================
// GAME LOOP PATTERN
// ==========================================

class Game {
private:
    Player player;
    BulletPool bulletPool;
    vector<Enemy> enemies;

    bool isRunning;

    MoveLeftCommand moveLeft;
    MoveRightCommand moveRight;
    ShootCommand shoot;

    int frame;
    int spawnInterval;

public:
    Game() {
        isRunning = true;
        frame = 0;
        spawnInterval = 20;
    }

    // INPUT PLAYER
    void processInput() {
        if (_kbhit()) {
            char key = _getch();

            if (key == 'a' || key == 'A') {
                moveLeft.execute(player, bulletPool);
            }
            else if (key == 'd' || key == 'D') {
                moveRight.execute(player, bulletPool);
            }
            else if (key == ' ') {
                shoot.execute(player, bulletPool);
            }
            else if (key == 'q' || key == 'Q') {
                isRunning = false;
            }
        }
    }

    // UPDATE GAME
    void update() {
        frame++;

        // Musuh muncul secara berkala
        if (frame % spawnInterval == 0) {
            int enemyPosition = rand() % 20;
            enemies.push_back(Enemy(enemyPosition));
        }

        // Update posisi peluru
        bulletPool.update();

        // Collision Detection
        vector<Bullet>& bullets =
            bulletPool.getBullets();

        for (int i = 0; i < bullets.size(); i++) {

            if (!bullets[i].isActive())
                continue;

            for (int j = 0; j < enemies.size(); j++) {

                if (enemies[j].isActive() &&
                    bullets[i].getX() ==
                    enemies[j].getPosition() &&
                    bullets[i].getY() == 0) {

                    enemies[j].destroy();
                    bullets[i].deactivate();

                    break;
                }
            }
        }
    }

    // RENDER GAME
    void render() {
        system("cls");

        cout << "===== ROBOT DEFENSE ARENA =====\n\n";

        cout << "A = Kiri | D = Kanan | "
             << "SPACE = Tembak | Q = Keluar\n\n";

        cout << "Arena:\n";

        vector<Bullet>& bullets =
            bulletPool.getBullets();

        for (int y = 0; y < 10; y++) {

            for (int x = 0; x < 20; x++) {

                char display = '.';

                // Player
                if (y == 9 &&
                    x == player.getPosition()) {
                    display = 'P';
                }

                // Enemy
                for (int i = 0; i < enemies.size(); i++) {

                    if (enemies[i].isActive() &&
                        y == 0 &&
                        x == enemies[i].getPosition()) {
                        display = 'E';
                    }
                }

                // Bullet
                for (int i = 0; i < bullets.size(); i++) {

                    if (bullets[i].isActive() &&
                        bullets[i].getX() == x &&
                        bullets[i].getY() == y) {
                        display = '|';
                    }
                }

                cout << display << " ";
            }

            cout << endl;
        }

        // Menampilkan status game
        int activeEnemies = 0;
        int activeBullets = 0;

        for (int i = 0; i < enemies.size(); i++) {
            if (enemies[i].isActive())
                activeEnemies++;
        }

        for (int i = 0; i < bullets.size(); i++) {
            if (bullets[i].isActive())
                activeBullets++;
        }

        cout << "\nJumlah musuh aktif: "
             << activeEnemies << endl;

        cout << "Peluru aktif: "
             << activeBullets << endl;
    }

    // MAIN GAME LOOP
    void run() {
        while (isRunning) {
            processInput();
            update();
            render();

            Sleep(100);
        }
    }
};

// ==========================================
// MAIN PROGRAM
// ==========================================

int main() {
    srand(time(0));

    Game game;

    game.run();

    cout << "\nGame selesai.\n";

    return 0;
}

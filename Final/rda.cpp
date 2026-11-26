
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// ==========================================
// CLASS BULLET
// ==========================================

class Bullet {
public:
    int x, y;
    bool active;

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
};

// ==========================================
// OBJECT POOL PATTERN
// ==========================================

class BulletPool {
private:
    vector<Bullet> bullets;

public:
    BulletPool() {
        // Membuat 10 peluru di awal game
        for (int i = 0; i < 10; i++) {
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

// ==========================================
// CLASS PLAYER
// ==========================================

class Player {
public:
    int x;
    int y;

    Player() {
        x = 10;
        y = 10;
    }

    void moveLeft() {
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
            cout << "Peluru habis! Tunggu peluru tersedia." << endl;
        }
    }
};

// ==========================================
// COMMAND PATTERN
// ==========================================

class Command {
public:
    virtual void execute() = 0;

    virtual ~Command() {}
};

// MOVE LEFT COMMAND

class MoveLeftCommand : public Command {
private:
    Player& player;

public:
    MoveLeftCommand(Player& p) : player(p) {}

    void execute() override {
        player.moveLeft();
    }
};

// MOVE RIGHT COMMAND

class MoveRightCommand : public Command {
private:
    Player& player;

public:
    MoveRightCommand(Player& p) : player(p) {}

    void execute() override {
        player.moveRight();
    }
};

// SHOOT COMMAND

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

// ==========================================
// CLASS ENEMY
// ==========================================

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

// ==========================================
// CLASS GAME
// ==========================================

class Game {
private:
    Player player;
    BulletPool bulletPool;

    vector<Enemy> enemies;

    MoveLeftCommand leftCommand;
    MoveRightCommand rightCommand;
    ShootCommand shootCommand;

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

    // INPUT
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

    // UPDATE
    void update() {
        if (!running) {
            return;
        }

        turn++;

        // Musuh muncul setiap 4 turn
        if (turn % 4 == 0) {
            int randomX = rand() % 21;

            enemies.push_back(Enemy(randomX));

            cout << "Musuh baru muncul!" << endl;
        }

        // Update posisi peluru
        bulletPool.update();

        // Update posisi musuh setiap 2 turn
        if (turn % 2 == 0) {
            for (int i = 0; i < enemies.size(); i++) {
                enemies[i].update();
            }
        }

        // Collision detection
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

        // Hapus musuh yang sudah mati
        for (int i = 0; i < enemies.size(); i++) {
            if (!enemies[i].alive) {
                enemies.erase(enemies.begin() + i);
                i--;
            }
        }

        // Game over jika musuh mencapai robot
        for (int i = 0; i < enemies.size(); i++) {
            if (enemies[i].y >= player.y) {
                cout << "\nGAME OVER! Musuh mencapai robot!" << endl;
                running = false;
                break;
            }
        }
    }

    // RENDER
    void render() {
        cout << "\n\n";
        cout << "=================================" << endl;
        cout << "       ROBOT DEFENSE ARENA       " << endl;
        cout << "=================================" << endl;

        cout << "Score         : " << score << endl;
        cout << "Turn          : " << turn << endl;
        cout << "Musuh Aktif   : " << enemies.size() << endl;
        cout << "Peluru Aktif  : " << bulletPool.getActiveCount() << endl;

        cout << "\n";

        // Menampilkan arena
        for (int y = 0; y <= 10; y++) {

            for (int x = 0; x <= 20; x++) {

                char symbol = '.';

                // Posisi player
                if (player.x == x && player.y == y) {
                    symbol = 'R';
                }

                // Posisi enemy
                for (int i = 0; i < enemies.size(); i++) {
                    if (enemies[i].alive &&
                        enemies[i].x == x &&
                        enemies[i].y == y) {
                        symbol = 'E';
                    }
                }

                // Posisi bullet
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
        cout << "A = Kiri | D = Kanan | Space = Tembak" << endl;
        cout << "Q = Keluar" << endl;
        cout << "=================================" << endl;
    }

    // GAME LOOP PATTERN
    void run() {
        cout << "=================================" << endl;
        cout << "       ROBOT DEFENSE ARENA       " << endl;
        cout << "=================================" << endl;

        cout << "Bertahanlah dari serangan musuh!" << endl;

        while (running) {
            render();
            input();
            update();
        }

        cout << "\n=================================" << endl;
        cout << "          GAME SELESAI           " << endl;
        cout << "Final Score: " << score << endl;
        cout << "=================================" << endl;
    }
};

// ==========================================
// MAIN PROGRAM
// ==========================================

int main() {
    srand(time(0));

    Game game;

    game.run();

    return 0;
}
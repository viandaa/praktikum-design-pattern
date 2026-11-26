
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Interface Observer
class IObserver {
public:
    virtual void onNotify(int hp) = 0;
    virtual ~IObserver() {}
};

// Subject
class Player {
private:
    int hp;
    vector<IObserver*> observers;

public:
    Player() {
        hp = 100;
    }

    void addObserver(IObserver* observer) {
        observers.push_back(observer);
    }

    void removeObserver(IObserver* observer) {
        observers.erase(
            remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    void notify() {
        for (IObserver* observer : observers) {
            observer->onNotify(hp);
        }
    }

    void takeDamage(int damage) {
        hp -= damage;

        if (hp < 0) {
            hp = 0;
        }

        cout << "\n[Player] Terkena damage: " << damage << endl;
        cout << "[Player] HP sekarang: " << hp << endl;

        notify();
    }
};

// Observer 1
class HealthBar : public IObserver {
public:
    void onNotify(int hp) override {
        cout << "[HealthBar] Menampilkan HP: " << hp << "/100" << endl;
    }
};

// Observer 2
class AudioManager : public IObserver {
public:
    void onNotify(int hp) override {
        if (hp > 0) {
            cout << "[AudioManager] Memainkan suara terkena damage" << endl;
        } else {
            cout << "[AudioManager] Memainkan suara player mati" << endl;
        }
    }
};

// Observer 3
class GameManager : public IObserver {
public:
    void onNotify(int hp) override {
        if (hp <= 0) {
            cout << "[GameManager] HP 0. Game Over!" << endl;
        } else {
            cout << "[GameManager] Player masih hidup" << endl;
        }
    }
};

// Observer 4: AchievementSystem
class AchievementSystem : public IObserver {
public:
    void onNotify(int hp) override {
        if (hp <= 20) {
            cout << "[AchievementSystem] Achievement unlocked: Almost Dead!" << endl;
        }
    }
};

int main() {
    Player player;

    HealthBar healthBar;
    AudioManager audioManager;
    GameManager gameManager;
    AchievementSystem achievementSystem;

    player.addObserver(&healthBar);
    player.addObserver(&audioManager);
    player.addObserver(&gameManager);
    player.addObserver(&achievementSystem);

    player.takeDamage(30);
    player.takeDamage(40);

    cout << "\n=== AudioManager di-unsubscribe ===" << endl;
    player.removeObserver(&audioManager);

    player.takeDamage(15);

    return 0;
}

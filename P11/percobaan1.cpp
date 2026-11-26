
#include <iostream>
#include <vector>
using namespace std;

// Interface Observer
class IObserver {
public:
    virtual void onNotify(int hp) = 0;
    virtual ~IObserver() {}
};

// Subject: Player
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

        cout << "[Player] Terkena damage: " << damage << endl;
        cout << "[Player] HP sekarang: " << hp << endl;

        notify();
    }

    // Fungsi Heal
    void heal(int amount) {
        hp += amount;

        if (hp > 100) {
            hp = 100;
        }

        cout << "[Player] Mendapat heal: " << amount << endl;
        cout << "[Player] HP sekarang: " << hp << endl;

        notify();
    }
};

// Concrete Observer: HealthBar
class HealthBar : public IObserver {
public:
    void onNotify(int hp) override {
        cout << "[HealthBar] Update tampilan HP: "
             << hp << "/100" << endl;
    }
};

int main() {
    Player player;
    HealthBar healthBar;

    player.addObserver(&healthBar);

    player.takeDamage(40);
    cout << endl;

    player.heal(20);
    cout << endl;

    player.heal(50);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Character {
private:
    string name;
public:
    Character(string n) { name = n; }
    string getName() { return name; }
};

class Player : public Character {
private:
    int score;
public:
    Player(string n, int s) : Character(n) { score = s; }
    void showInfo() {
        cout << "Player: " << getName() << " | Score: " << score << endl;
    }
};

int main() {
    Player p("Alice", 100);
    p.showInfo();
    return 0;
}

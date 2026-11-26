#include <iostream>
using namespace std;
// =====================================
// RECEIVER
// =====================================
class Player {
public:
    void jump() {
        cout << "Player jumps!" << endl;
}
    void attack() {
        cout << "Player attacks!" << endl;
}
    void defend() {
        cout << "Player defends!" << endl;
}
};
// =====================================
// COMMAND INTERFACE
// =====================================
class Command {
public:
    virtual void execute() = 0;
};
// =====================================
// CONCRETE COMMAND
// =====================================
class JumpCommand : public Command {
private:
    Player* player;

public:
    JumpCommand(Player* p) {
        player = p;
}
    void execute() {
        player->jump();
}
};

class AttackCommand : public Command {
private:
    Player* player;

public:
    AttackCommand(Player* p) {
        player = p;
}
    void execute() {
        player->attack();
}
};

class DefendCommand : public Command {
private:
    Player* player;

public:
    DefendCommand(Player* p) {
        player = p;
}
    void execute() {
        player->defend();
}
};

// =====================================
// MAIN
// =====================================
int main() {
    Player player;

    Command* jumpCmd = new JumpCommand(&player);
    Command* attackCmd = new AttackCommand(&player);
    Command* defendCmd = new DefendCommand(&player);

    cout << "=== Percobaan 1: Command Pattern Dasar ===" << endl;
 
    jumpCmd->execute();
    attackCmd->execute();
    defendCmd->execute();
 
    delete jumpCmd;
    delete attackCmd;
    delete defendCmd;

    return 0;
}
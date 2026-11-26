
#include <iostream>
using namespace std;

// =====================================
// RECEIVER
// =====================================
class Player {
public:
    void moveLeft() {
        cout << "Player moves left!" << endl;
    }

    void moveRight() {
        cout << "Player moves right!" << endl;
    }

    void jump() {
        cout << "Player jumps!" << endl;
    }

    void attack() {
        cout << "Player attacks!" << endl;
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
// CONCRETE COMMANDS
// =====================================
class MoveLeftCommand : public Command {
private:
    Player* player;

public:
    MoveLeftCommand(Player* p) {
        player = p;
    }

    void execute() {
        player->moveLeft();
    }
};

class MoveRightCommand : public Command {
private:
    Player* player;

public:
    MoveRightCommand(Player* p) {
        player = p;
    }

    void execute() {
        player->moveRight();
    }
};

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

// =====================================
// INVOKER
// =====================================
class InputHandler {
private:
    Command* keyA;
    Command* keyD;
    Command* keyW;
    Command* keyJ;

public:
    void setKeyA(Command* command) {
        keyA = command;
    }

    void setKeyD(Command* command) {
        keyD = command;
    }

    void setKeyW(Command* command) {
        keyW = command;
    }

    void setKeyJ(Command* command) {
        keyJ = command;
    }

    void handleInput(char input) {
        if (input == 'a') {
            keyA->execute();
        } else if (input == 'd') {
            keyD->execute();
        } else if (input == 'w') {
            keyW->execute();
        } else if (input == 'j') {
            keyJ->execute();
        } else {
            cout << "Unknown key!" << endl;
        }
    }
};

// =====================================
// MAIN
// =====================================
int main() {
    Player player;

    Command* moveLeft = new MoveLeftCommand(&player);
    Command* moveRight = new MoveRightCommand(&player);
    Command* jump = new JumpCommand(&player);
    Command* attack = new AttackCommand(&player);

    InputHandler inputHandler;

    inputHandler.setKeyA(moveLeft);
    inputHandler.setKeyD(moveRight);
    inputHandler.setKeyW(jump);
    inputHandler.setKeyJ(attack);

    cout << "=== Studi Kasus: Character Control System ===" << endl;
    cout << "a = Move Left" << endl;
    cout << "d = Move Right" << endl;
    cout << "w = Jump" << endl;
    cout << "j = Attack" << endl;
    cout << "q = Quit" << endl;

    char input;

    while (true) {
        cout << "\nInput: ";
        cin >> input;

        if (input == 'q') {
            cout << "Game ended!" << endl;
            break;
        }

        inputHandler.handleInput(input);
    }

    delete moveLeft;
    delete moveRight;
    delete jump;
    delete attack;

    return 0;
}
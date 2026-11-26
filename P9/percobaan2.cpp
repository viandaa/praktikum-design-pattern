#include <iostream>
using namespace std;

// =====================================
// RECEIVER
// =====================================
class Player {
public:
    void moveUp() {
        cout << "Player moves up!" << endl;
    }

    void moveDown() {
        cout << "Player moves down!" << endl;
    }

    void attack() {
        cout << "Player attacks!" << endl;
    }

    void jump() {
        cout << "Player jumps!" << endl;
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
class MoveUpCommand : public Command {
private:
    Player* player;
public:
    MoveUpCommand(Player* p) {
        player = p;
    }

    void execute() {
        player->moveUp();
    }
};

class MoveDownCommand : public Command {
private:
    Player* player;

public:
    MoveDownCommand(Player* p) {
        player = p;
    }

    void execute() {
        player->moveDown();
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

// =====================================
// NULL COMMAND
// =====================================
class NullCommand : public Command {
public:
    void execute() {
        cout << "No command assigned." << endl;
    }
};
// =====================================
// INVOKER
// =====================================
class InputHandler {
private:
    Command* keyW;
    Command* keyS;
    Command* keyJ;
    Command* keyK;
    Command* nullCommand;

public:
    InputHandler() {
        nullCommand = new NullCommand();
        keyW = nullCommand;
        keyS = nullCommand;
        keyJ = nullCommand;
        keyK = nullCommand;
    }

    void setKeyW(Command* command) {
        keyW = command;
    }

    void setKeyS(Command* command) {
        keyS = command;
    }

    void setKeyJ(Command* command) {
        keyJ = command;
    }

    void setKeyK(Command* command) {
        keyK = command;
    }

    void handleInput(char input) {
        if (input == 'w') {
            keyW->execute();
        } else if (input == 's') {
            keyS->execute();
        } else if (input == 'j') {
            keyJ->execute();
        } else if (input == 'k') {
            keyK->execute();
        } else {
            cout << "Unknown key" << endl;
        }
    }
};

// =====================================
// MAIN 
// =====================================
int main() {
    Player player;
    Command* moveUp = new MoveUpCommand(&player);
    Command* moveDown = new MoveDownCommand(&player);
    Command* attack = new AttackCommand(&player);
    Command* jump = new JumpCommand(&player);
    InputHandler inputHandler;

    inputHandler.setKeyW(moveUp);
    inputHandler.setKeyS(moveDown);
    inputHandler.setKeyJ(attack);
    inputHandler.setKeyK(jump);

    cout << "=== Percobaan 2: Input handler dengan Command ===" << endl;
    cout << "w = move up" << endl;
    cout << "s = move down" << endl;
    cout << "j = attack" << endl;
    cout << "k = jump" << endl;
    cout << "q = quit" << endl;

    char input;

    while (true) {
        cout << "\nInput: ";
        cin >> input;

        if (input == 'q')
            break;

        inputHandler.handleInput(input);
    }

    delete moveUp;
    delete moveDown;
    delete attack;
    delete jump;
    return 0;
} 
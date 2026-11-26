#include <iostream>
using namespace std;

class GameManager {
private:
    string gameState;

    // Constructor dibuat private
    GameManager() {
    gameState = "Start";
    }

public:
    // Menghapus copy constructor agar object tidak bisa disalin
    GameManager(const GameManager&) = delete;

    // Menghapus assignment operator agar object tidak bisa di-assign
    GameManager& operator=(const GameManager&) = delete;

    // Method untuk mengambil satu-satunya instance
    static GameManager& getInstance() {
        static GameManager instance;
        return instance;
    }

    void setGameState(string state) {
        gameState = state;
    }

    string getgameState() {
        return gameState;
    }

    void showGameState() {
        cout << "[Gamemanager] State game saat ini: " << gameState << endl;
    }
};

int main() {
    GameManager& gm1 = GameManager::getInstance();
    GameManager& gm2 = GameManager::getInstance();

    gm1.showGameState();

    gm1.setGameState("Playing");
    gm2.showGameState();

    gm2.setGameState("Game Over");
    gm1.showGameState();

    return 0;
}
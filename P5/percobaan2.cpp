#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Player {
    public:
        int position = 0;

        void update() {
            position += 2;
        }
        void render() {
            cout << "Player position: " << position << endl;
        }
};

int main() {
    Player player;

    int frame = 0;
    bool running = true;

    while(running) {
        cout << "\nFRAME " << frame << endl;

        player.update();
        player.render();

        frame++;

        if(frame >= 10)
            running = false;

        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return 0;
}
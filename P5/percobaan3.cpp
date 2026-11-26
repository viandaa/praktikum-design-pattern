#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;

class Player {
public:
    float position = 0;
    float speed = 10;

    void update(float deltaTime) {
        position += speed * deltaTime;
    }

    void render() {
        cout << "Player position: " << position << endl;
    }
};

int main() {
    Player player;

    auto previous = high_resolution_clock::now();

    int frame = 0;

    while(frame < 10) {
        auto current = high_resolution_clock::now();

        float deltaTime = duration<float>(current - previous).count();

        previous = current;

        player.update(deltaTime);
        player.render();

        frame++;

        this_thread::sleep_for(milliseconds(500));
    }
    return 0;
}
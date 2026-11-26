#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

class Player {
public:
    float position = 0;
    float speed = 5;

    void update(float timestep) {
        position += speed * timestep;
    }
    void render() {
        cout << "Player position: " << position << endl;
    }
};

int main() {
    Player player;

    const float timestep = 0.016f;

    auto previous = high_resolution_clock::now();
    float lag =0.0f;

    int frame = 0;

    while(frame < 10) {
        auto current = high_resolution_clock::now();
        
        float elapsed = duration<float>(current - previous).count();

        previous = current;

        lag += elapsed;

        while(lag >= timestep) {
            player.update(timestep);
            lag -= timestep;
        }

        cout << "Frame: " << frame << endl;
        player.render();

        frame++;

        this_thread::sleep_for(milliseconds(200 + rand() % 300));
    }
    return 0;
}
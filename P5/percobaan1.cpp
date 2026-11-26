#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

bool running = true;

void processInput() {
    cout << "[INPUT] membaca input pemain\n"; 
}

void update() {
    cout << "[UPDATE] memperbarui dunia game\n";
}

void render() {
    cout << "[RENDER] menggambar tampilan game\n";
}

int main() {
    int frame = 0;

    while(running) {
        cout << "\nFRAME " << frame << endl;
        processInput();
        update();
        render();

        frame++;

        if(frame >= 5)
           running = false;

        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "\nGame selesai\n";

    return 0;
}
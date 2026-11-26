#include <iostream>
using namespace std;

class AudioManager {
private:
    int volume;
    bool muted;
 
    // Constructor private agar tidak bisa membuat object langsung
    AudioManager() {
        volume = 50;
        muted = false;
    }

public:
    // Mencegah object disalin
    AudioManager(const AudioManager&) = delete;
    AudioManager& operator=(const AudioManager&) = delete;
 
    static AudioManager& getInstance() {
        static AudioManager instance;
        return instance;
}

    void setVolume(int newVolume) {
        if (newVolume < 0) {
            volume = 0;
        } else if (newVolume > 100) {
            volume = 100;
        } else {
            volume = newVolume;
        }
    }
    
    void mute() {
        muted = true;
    }

    void unmute() {
        muted = false;
    }
 
    void playBGM(string bgmName) {
        if (muted) {
            cout << "[AudioManager] Audio sedang mute. BGM tidak diputar." << endl;
        } else {
            cout << "[AudioManager] Memutar BGM: " << bgmName << " dengan volume " << volume << endl;
        }
    }
    
    void playSFX(string sfxName) {
        if (muted) {
            cout << "[AudioManager] Audio sedang mute. SFX tidak diputar." << endl;
        } else {
            cout << "[AudioManager] Memainkan SFX: " << sfxName << " dengan volume " << volume << endl;
        }
    }
 
    void showAudioStatus() {
        cout << "[AudioManager] Volume: " << volume << endl;
        cout << "[AudioManager] Muted: " << (muted ? "Ya" : "Tidak") << endl;
 }
};

// Simulasi class Player
class Player {
public:
    void attack() {
        cout << "[Player] Player menyerang enemy" << endl;
        AudioManager::getInstance().playSFX("Sword Attack");
    }
};

// Simulasi class Menu
class Menu {
public:
    void openMenu() {
        cout << "[Menu] Menu dibuka" << endl;
        AudioManager::getInstance().playSFX("Menu Click");
    }
    void changeVolume(int volume) {
        cout << "[Menu] Mengubah volume audio" << endl;
        AudioManager::getInstance().setVolume(volume);
    }
};

int main() {
    AudioManager& audio = AudioManager::getInstance();
    
    audio.showAudioStatus();
    cout << endl;
 
    audio.playBGM("Main Theme");
    cout << endl;
    
    Player player;
    Menu menu;
    
    player.attack();
    menu.openMenu();
    
    cout << endl;
    
    menu.changeVolume(80);
    player.attack();
 
    cout << endl;
 
    audio.mute();
    audio.playBGM("Battle Theme");
    player.attack();
 
    cout << endl;
 
    audio.unmute();
    audio.playBGM("Victory Theme");
 
    return 0;
}

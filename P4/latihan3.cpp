#include <iostream>

using namespace std;


// ======================================================
// INTERFACE-STYLE CLASS: IUPDATABLE
// ======================================================

// Interface untuk objek yang dapat di-update
class IUpdatable {
public:

    // PURE VIRTUAL FUNCTION
    // Setiap class yang mengimplementasikan IUpdatable
    // wajib memiliki fungsi Update()
    virtual void Update() = 0;
};


// ======================================================
// INTERFACE-STYLE CLASS: IDRAWABLE
// ======================================================

// Interface untuk objek yang dapat digambar
class IDrawable {
public:

    // PURE VIRTUAL FUNCTION
    // Setiap class yang mengimplementasikan IDrawable
    // wajib memiliki fungsi Draw()
    virtual void Draw() = 0;
};


// ======================================================
// CLASS PLAYER
// ======================================================

// Player mengimplementasikan dua interface:
// IUpdatable dan IDrawable
class Player : public IUpdatable, public IDrawable {
public:

    // OVERRIDE dari IUpdatable
    void Update() override {
        cout << "Player moves forward." << endl;
    }

    // OVERRIDE dari IDrawable
    void Draw() override {
        cout << "Draw player sprite." << endl;
    }
};


// ======================================================
// CLASS ENEMY
// ======================================================

// Enemy mengimplementasikan dua interface:
// IUpdatable dan IDrawable
class Enemy : public IUpdatable, public IDrawable {
public:

    // OVERRIDE dari IUpdatable
    void Update() override {
        cout << "Enemy patrols area." << endl;
    }

    // OVERRIDE dari IDrawable
    void Draw() override {
        cout << "Draw enemy model." << endl;
    }
};


// ======================================================
// CLASS NPC
// ======================================================

// NPC juga mengimplementasikan dua interface
class NPC : public IUpdatable, public IDrawable {
public:

    // OVERRIDE dari IUpdatable
    void Update() override {
        cout << "NPC walks around village." << endl;
    }

    // OVERRIDE dari IDrawable
    void Draw() override {
        cout << "Draw NPC model." << endl;
    }
};


// ======================================================
// GAME LOOP
// ======================================================

// GameLoop menerima daftar object yang dapat Update
// dan daftar object yang dapat Draw
void GameLoop(IUpdatable* updatable[],
              IDrawable* drawable[],
              int size) {

    // -------------------------
    // UPDATE PHASE
    // -------------------------

    cout << "=== UPDATE ===" << endl;

    for (int i = 0; i < size; i++) {
        updatable[i]->Update();
    }


    // -------------------------
    // DRAW PHASE
    // -------------------------

    cout << endl;
    cout << "=== DRAW ===" << endl;

    for (int i = 0; i < size; i++) {
        drawable[i]->Draw();
    }
}


// ======================================================
// MAIN PROGRAM
// ======================================================

int main() {

    // Membuat object
    Player player;
    Enemy enemy;
    NPC npc;


    // Array interface IUpdatable
    // Berisi object yang memiliki fungsi Update()
    IUpdatable* updatable[3] = {
        &player,
        &enemy,
        &npc
    };


    // Array interface IDrawable
    // Berisi object yang memiliki fungsi Draw()
    IDrawable* drawable[3] = {
        &player,
        &enemy,
        &npc
    };


    // Menjalankan GameLoop
    GameLoop(updatable, drawable, 3);


    return 0;
}
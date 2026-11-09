#include <iostream>

struct Vec2 { double x, y; };

class Entite {
protected:
    Vec2 position;
    const char* nom;
public:
    Entite(Vec2 p, const char* n) : position(p), nom(n) {}
};

class Ennemi : public Entite {
    int degats;
public:
    Ennemi(Vec2 p, const char* n, int d) : Entite(p, n), degats(d) {}
    void modifier() { position.x = 5; }
};

class Joueur : public Entite {
    double vie;
public:
    Joueur(Vec2 p, const char* n, double v) : Entite(p, n), vie(v) {}
};

int main() {
    Ennemi e({0, 0}, "Gobelin", 10);
    Joueur j({0, 0}, "Joueur", 100);

    e.modifier();
    // e.position.x = 10; // Accès interdit : protected

    std::cout << sizeof(Vec2) << '\n'
              << sizeof(const char*) << '\n'
              << sizeof(Entite) << '\n'
              << sizeof(Ennemi) << '\n'
              << sizeof(Joueur) << '\n';
}

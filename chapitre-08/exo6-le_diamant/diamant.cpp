#include <iostream>

struct Vec2 { double x, y; };

class Entite {
public:
    Vec2 position;
};

class Mobile : public Entite {
public:
    Vec2 vitesse;
};

class Visible : public Entite {
public:
    char glyphe;
};

class Ennemi : public Mobile, public Visible {};

int main() {
    Ennemi e;

    std::cout << sizeof(Vec2) << '\n'
              << sizeof(Entite) << '\n'
              << sizeof(Mobile) << '\n'
              << sizeof(Visible) << '\n'
              << sizeof(Ennemi) << '\n';

    // e.position.x = 3.0; // Ambigu : deux membres position

    e.Mobile::position.x = 3.0;

    Mobile& m = e;
    Visible& v = e;

    std::cout << m.position.x << '\n'
              << v.position.x << '\n';

    return 0;
}

#include <iostream>

int gEnnemi = 0, gFantome = 0, gRobot = 0;

class Ennemi {
public:
    virtual void deplacer(double dt) { ++gEnnemi; }
    virtual ~Ennemi() = default;
};

class Fantome : public Ennemi {
public:
    void deplacer(double dt) override { ++gFantome; }
};

class Robot : public Ennemi {
public:
    void deplacer(double dt) override { ++gRobot; }
};

int main() {
    Ennemi* tab[6] = {
        new Ennemi, new Robot, new Robot,
        new Fantome, new Fantome, new Fantome
    };

    for (int i = 0; i < 10; ++i)
        for (Ennemi* e : tab)
            e->deplacer(0.1);

    std::cout << gEnnemi << '\n'
              << gFantome << '\n'
              << gRobot << '\n';

    for (Ennemi* e : tab) delete e;
}

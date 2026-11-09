#include <iostream>

class Entite {
public:
    virtual const char* nom() const { return "entite"; }
    virtual ~Entite() = default;
};

class Ennemi : public Entite {
public:
    int degats;
    Ennemi() : degats(10) {}
    const char* nom() const override { return "ennemi"; }
};

void f(Entite e) { std::cout << e.nom() << '\n'; }
void g(Entite& e) { std::cout << e.nom() << '\n'; }
void h(Entite* e) { std::cout << e->nom() << '\n'; }

int main() {
    Ennemi e;
    f(e);
    g(e);
    h(&e);

    std::cout << sizeof(Entite) << '\n';
    std::cout << sizeof(Ennemi) << '\n';
}

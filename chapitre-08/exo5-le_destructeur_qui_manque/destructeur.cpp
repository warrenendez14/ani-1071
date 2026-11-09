#include <iostream>
#include <vector>

struct Trace {
    ~Trace() { std::cout << "~Trace\n"; }
};

class Ennemi {
public:
    virtual void deplacer() {}
    virtual ~Ennemi() { std::cout << "~Ennemi\n"; }
};

class Fantome : public Ennemi {
    Trace trace;
    std::vector<int> cases = std::vector<int>(1000);

public:
    ~Fantome() {
        std::cout << "~Fantome, taille : " << cases.size() << '\n';
    }
};

int main() {
    Ennemi* e = new Fantome;
    delete e;

    Fantome* f = new Fantome;
    delete f;
}

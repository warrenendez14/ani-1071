#include <cstdio>

class Trace {
    const char* nom;

public:
    Trace(const char* n) : nom(n) {
        std::printf("%s nait\n", nom);
    }

    ~Trace() {
        std::printf("%s meurt\n", nom);
    }
};

void fonction() {
    Trace f("Fonction");
    std::printf("Fin fonction\n");
}

int main() {
    Trace m("Main");

    fonction();

    {
        Trace b("Bloc");
        std::printf("Fin bloc\n");
    }

    Trace* a = new Trace("New sans delete");

    Trace* d = new Trace("New avec delete");
    delete d;

    {
        Trace t1("Premier objet");
        Trace t2("Deuxieme objet");
        std::printf("Fin bloc deux objets\n");
    }

    std::printf("Fin main\n");

    // m.~Trace(); // A tester ensuite

    return 0;
}

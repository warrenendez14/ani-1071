#include <iostream>

class Pile {
private:
    static const int CAPACITE = 100;
    int elements[CAPACITE];
    int nombre = 0;

public:
    void empiler(int v) {
        if (!pleine()) elements[nombre++] = v;
    }

    int depiler() {
        return nombre > 0 ? elements[--nombre] : -1;
    }

    int sommet() const {
        return nombre > 0 ? elements[nombre-1] : -1;
    }

    bool vide() const { return nombre == 0; }
    bool pleine() const { return nombre == CAPACITE; }
    int taille() const { return nombre; }
};

class File {
private:
    static const int CAPACITE = 100;
    int elements[CAPACITE];
    int tete = 0, queue = 0, nombre = 0;

public:
    void enfiler(int v) {
        if (pleine()) return;
        elements[queue] = v;
        queue = (queue + 1) % CAPACITE;
        nombre++;
    }

    int defiler() {
        if (nombre == 0) return -1;
        int v = elements[tete];
        tete = (tete + 1) % CAPACITE;
        nombre--;
        return v;
    }

    bool vide() const { return nombre == 0; }
    bool pleine() const { return nombre == CAPACITE; }
    int taille() const { return nombre; }
};

int main() {
    Pile p;
    File f;

    // p.nombre = -5; // Erreur : membre prive
    // f.tete = 7;     // Erreur : membre prive

    for (int i = 0; i < 150; i++) p.empiler(i);
    std::cout << "Pile apres 150 empilements : " << p.taille() << "\n";

    for (int i = 0; i < 200; i++) p.depiler();
    std::cout << "Pile apres 200 depilements : " << p.taille() << "\n";

    for (int i = 0; i < 150; i++) f.enfiler(i);
    std::cout << "File apres 150 enfilements : " << f.taille() << "\n";

    for (int i = 0; i < 50; i++) f.defiler();
    std::cout << "File apres 50 defilements : " << f.taille() << "\n";

    for (int i = 0; i < 50; i++) f.enfiler(i);
    std::cout << "File apres 50 nouveaux enfilements : " << f.taille() << "\n";
}


#include <chrono>
#include <cstdio>

double maintenant()
{
    using namespace std::chrono;
    auto t = steady_clock::now().time_since_epoch();
    return duration<double>(t).count();
}

class Chrono {
private:
    double debut;

public:
    Chrono() : debut(maintenant()) {}

    double ecoule() const {
        return maintenant() - debut;
    }

    void redemarrer() {
        debut = maintenant();
    }
};

int main()
{
    for (int n = 0; n < 3; n++) {
        Chrono c;
        long long total = 0;

        for (long long i = 0; i < 100000000; i++)
            total += i;

        std::printf("Total : %lld | Duree : %.9f s\n",
                    total, c.ecoule());
    }

    Chrono c;

    for (int i = 0; i < 5; i++) {
        c.redemarrer();
        std::printf("Duree courte : %.9f s\n", c.ecoule());
    }

    const Chrono k;
    std::printf("Const : %.9f s\n", k.ecoule());

    // k.redemarrer(); // Erreur : impossible de modifier un objet const

    return 0;
}

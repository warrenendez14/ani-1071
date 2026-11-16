#include <cstdio>
#include <NKLogger/NkLog.h>
int main() {
    nkentseu::NkLog::Initialize("Ani1071");
    auto& logger = nkentseu::NkLog::GetLogger();
    logger.Info("Demarrage du programme");
    int a = 10;
    int b = 5;
    logger.Info("Calcul en cours : {} + {}", a, b);
    int somme = a + b;
    int produit = a * b;
    printf("Somme = %d\n", somme);
    printf("Produit = %d\n", produit);
    logger.Warn("Attention : verification des valeurs");
    if (b != 0) {
        logger.Info("Division possible");
        printf("Division = %d\n", a / b);
    } else {
        logger.Error("Division impossible : diviseur nul");
    }
    logger.Debug("Message de debogage");
    logger.Info("Fin du programme");
    nkentseu::NkLog::Shutdown();
    return 0;
}

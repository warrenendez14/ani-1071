//programme original 
#include <cstdio>
int calculer(void);
int main(void)
{
    printf("%d\n", calculer());
    return 0;
}

//avec l'oublie des point-virgules
#include <cstdio>
int calculer(void)
int main(void)
{
    printf("%d\n", calculer())
    return 0
}

//avec la correction d'une seule erreur
#include <cstdio>
int calculer(void);
int main(void)
{
    printf("%d\n", calculer())
    return 0
}

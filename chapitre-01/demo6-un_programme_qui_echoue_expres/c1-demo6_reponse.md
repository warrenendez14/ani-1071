//pour le système en général :
le code de sortie 0 signifie le programme s’est terminé normalement avec succès.
le code de sortie 1 signifie le programme s’est terminé avec un résultat différent de zéro généralement utilisé pour 
signaler une erreur ou une condition particulière.
//pour mon programme 
le code de sortie 0 signifie que le nombre est pair.
le code de sortie 1 signifie que le nombre est impair.
Après avoir exécuté le programme avec 7, 9, 4 et 22 les codes de sortie observés sont respectivement 1, 1, 0 et 0.

```
#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    // Comme n est un int, la partie décimale est supprimée lors de la division.
    if (n / 2 * 2 == n) {
        return 0;
    } else {
        return 1;
    }
}
```


// Résultats observés
./c1-demo6_main
7
echo $?
1

./c1-demo6_main
9
echo $?
1

./c1-demo6_main
4
echo $?
0

./c1-demo6_main
22
echo $?
0

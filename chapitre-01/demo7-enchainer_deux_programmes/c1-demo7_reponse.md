./main && echo "pair"  //ceci est ma ligne de commande 
Cela ressemble à un système de construction car le code de sortie d’une étape permet de décider si l’étape 
suivante doit être exécutée
//programme utilisé
´´´ #include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    // Comme n est un int, la partie décimale est supprimée lors de la division.
    if (n / 2 * 2 == n) {
        return 0;
    } else {
        return 1;
    }
} ´´´

//Premier essai nombre pair
MacBook-Pro:~ macos$ ./main && echo "pair"
  10
  pair

//Deuxieme essai nombre impair 
MacBook-Pro:~ macos$ ./main && echo "pair"
  7

//le deuxieme resultat n'affiche aucune valeur
Avec 10 le programme retourne 0 donc pair s’affiche
Avec 7 le programme retourne 1 donc pair ne s’affiche pas

//mon programme
#include <cstdio>
int main()
{
    printf("Bonjour\n");
    return 0;
}

Les lignes qui commencent par # et un nombre sont des directives de repérage produites par le préprocesseur
on voit de nombreux fichiers cités plusieurs fois 
mes six lignes s'affiche vers la fin a partir de la ligne 401 du fichier sortie.txt

j'ai exécuté les commandes suivantes:
MacBook-Pro:~ macos$ clang++ -E main.cpp > sortie.txt
MacBook-Pro:~ macos$ wc -l sortie.txt
     700 sortie.txt //message du terminal
mon fichier bonjour.cpp contient 6 lignes alors que le message produit par le préprocesseur en contient 700 lignes 
La différence vient de l'étape de prétraitement la commande clang++ -E demande à clang++ d'effectuer uniquement
le prétraitement du programme et d'afficher le résultat.
Ainsi, les 6 lignes de mon fichier source deviennent 700 lignes après traitement des #include ce qui montre que 
le compilateur ne travaille pas directement sur le fichier tel que je l'ai écrit mais sur le résultat produit par 
le préprocesseur.

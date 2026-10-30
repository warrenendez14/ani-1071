Sur un projet réel on cherche surtout à reduire le temps de compilation parce que le programme est souvent recompilé après 
chaque modification ainsi un project réel peut contenir plusieurs entêtes ce qui nous pousse a tous faire pour reduire le 
temps de compilation qui nous permet ainsi dede travailler plus rapidement de tester plus rapidement les modifications et
d'améliorer la productivité pendant le développement néamoins le temps d'execution reste important pour l'utilisation finale

//avec une seule en-tête 
1-la compilation :
MacBook-Pro:~ macos$ time clang++ main.cpp -o main

real    0m0.701s
user    0m0.617s
sys     0m0.142s

2-l'execution 
MacBook-Pro:~ macos$ time ./main
Bonjour !

real    0m0.014s
user    0m0.005s
sys     0m0.008s

//avec 5 en-têtes 
1-la compilation 
MacBook-Pro:~ macos$ time clang++ main.cpp -o main5

real    0m0.678s
user    0m0.596s
sys     0m0.134s

2-l'exécution 
MacBook-Pro:~ macos$ time ./main5
Bonjour !

real    0m0.013s
user    0m0.005s
sys     0m0.008s

On constate donc une différence très faible soit 23 ms de différence pour la compilation et 1 ms pour l’exécution.
Ainsi l’augmentation du nombre d’en-têtes de 1 à 5 n’a pas entraîné d’augmentation 
mesurable du temps de compilation ni du temps d’exécution pour ce programmes

//mon programme 
#include <iostream>

int main() {
    int nombre = 10;
    std::cout << "Bonjour !\n";
    return 0;
}

//programme avec 5 entêtes
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <algorithm>
int main() {
    int nombre = 10;
    std::cout << "Bonjour !\n";
    return 0;
}

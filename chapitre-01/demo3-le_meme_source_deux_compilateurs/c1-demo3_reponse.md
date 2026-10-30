Pour comparer clang++ et g++ j'ai commencé par:
1- leurs versions 
MacBook-Pro:~ macos$ g++ --version
Apple clang version 15.0.0 (clang-1500.3.9.4)

MacBook-Pro:~ macos$ clang++ --version
Apple clang version 15.0.0 (clang-1500.3.9.4)

2-la compilation 
    clang++ c1-demo3_main.cpp -o clg+ 
    g++ c1-demo3_main.cpp -o gpp

3-la taille de l'exécutable 
  MacBook-Pro:~ macos$ ls -l gpp clg+
  -rwxr-xr-x@ 1 macos  staff  8448 21 sep 09:39 clg+
  -rwxr-xr-x@ 1 macos  staff  8448 21 sep 09:39 gpp

4-l'exécution 
    ./clg+ //la reponse est "Bonjour"
    ./gpp //la reponse est "Bonjour"

    En conclusion clang++ et g++ ont produit des exécutables de même taille 8448 octets et produisant 
    exactement la même sortie ("Bonjour") ça ne signifie toutefois pas que tous les compilateurs produiront toujours 
    des fichiers de même taille 

 //le programme utilisé est:
#include <cstdio>
int main() {
    printf("Bonjour\n");
    return 0;
}

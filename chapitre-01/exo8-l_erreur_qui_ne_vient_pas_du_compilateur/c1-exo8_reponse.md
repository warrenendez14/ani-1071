MacBook-Pro:~ macos$ clang++ -c c1-exo8_main.cpp
//Avec `-c` ça réussit car on fait seulement la compilation; le compilateur accepte que `calculer()` ne soit pas encore 
définie c'est le compilateur parle.

MacBook-Pro:~ macos$ clang++ c1-exo8_main.cpp -o exo8
Undefined symbols for architecture x86_64:
  "calculer()", referenced from:
      _main in main-d98a65.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
//Sans `-c` ça échoue car il faut faire l’édition de liens et `calculer()` n’a aucune définition c'est l’éditeur de 
liens qui parle.

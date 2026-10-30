//compilation sans aucun point-virgule 
MacBook-Pro:~ macos$ clang++ -c c1-exo9_main.cpp
MacBook-Pro:~ macos$ clang++ c1-exo9_main.cpp -o exo9
Undefined symbols for architecture x86_64:
  "calculer()", referenced from:
      _main in main-d98a65.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
MacBook-Pro:~ macos$ clang++ c1-exo9_main.cpp -o exo9
c1-exo9_main.cpp:2:19: error: expected ';' after top level declarator
int calculer(void)
                  ^
                  ;
c1-exo9_main.cpp:5:31: error: expected ';' after expression
    printf("%d\n", calculer())
                              ^
                              ;
c1-exo9_main.cpp:6:13: error: expected ';' after return statement
    return 0
            ^
            ;
3 errors generated.

//compilation après correction de la première erreur
MacBook-Pro:~ macos$ clang++ c1-exo9_main.cpp -o exo9
c1-exo9_main.cpp:5:31: error: expected ';' after expression
    printf("%d\n", calculer())
                              ^
                              ;
c1-exo9_main.cpp:6:13: error: expected ';' after return statement
    return 0
            ^
            ;
2 errors generated.

Un seul point-virgule corrigé fait disparaître une erreur. Cela montre qu'il faut toujours corriger la première
erreur puis recompiler car une première erreur peut provoquer d'autres messages.

Après avoir compilé avec la commande clang++ -Wall -Wextra c1-exo10_main.cpp -o exo10 ,la compilation du programme réussi en 
nous laissant un message  d'avertissement ```c1-exo10_main.cpp:5:9: warning: unused variable 'nombre' [-Wunused-variable]``` 
parcontre après insertion de l'erreur on obtient :
```
MacBook-Pro:~ macos$ clang++ c1-exo10_main.cpp -o main
c1-exo10_main.cpp:4:20: error: expected ';' at end of declaration
    int nombre = 10
                   ^
                   ;
1 error generated. 
```

donc la différence entre une erreur et un avertissement est que l'avertissement signale un problème potentiel mais 
sans toutefois arrêter la compilation parcontre l'erreur Une erreur est un problème dans le programme qui empêche le
compilateur de produire correctement l’exécutable.
En restant très bref l’avertissement existe pour nous  prévenir d’un problème possible sans bloquer la compilation.
Ainsi l'avertissement existe pour signaler au programmeur une situation qui n'empêche pas le programme de compiler mais qui 
peut révéler une erreur. Une variable déclarée mais jamais utilisée peut être un simple oubli (le programmeur a prévu l'utiliser mais
Finalement il ne l'a plus fait) elle peut aussi indiquer qu'une partie du programme est incomplète le compilateur prévient donc le
Programmeur pour une vérification du code

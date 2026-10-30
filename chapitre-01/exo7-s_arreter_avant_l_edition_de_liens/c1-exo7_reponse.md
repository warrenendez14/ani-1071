j'ai compilé mon fichier source "c1-exo7_main.cpp" avec l'option -c (clang++ c1-exo7_main.cpp -c) puis j'ai observé le 
fichier obtenu (ls -l c1-exo7_main.cpp) et ça m'a affiché ```-rw-r--r--@ 1 macos  staff  768 20 sep 22:48 c1-exo7_main.o```
nous constatons qu'il ne possède pas la permission x (droit d'exécution)
puis j'ai essayé de lancer directement le fichier objet (./c1-exo7_main.cpp.o) et j'ai recu comme réponse 
```bash: ./main.o: Permission denied```
puis j'ai forcé son exécution
(chmod +x main.o
./main.o) et j'ai reçu le message suivant ```bash: ./main.o: cannot execute binary file```
L'ajout du droit d'exécution ne suffit donc pas le fichier objet contient du code machine
mais ce n'est pas encore un programme exécutable.
ensuite j'ai utilisé nm pour observer les symboles présents dans le fichier objet (nm c1-exo7_main.cpp.o) m'affichant ainsi
```0000000000000000 T _main
                 U _printf```

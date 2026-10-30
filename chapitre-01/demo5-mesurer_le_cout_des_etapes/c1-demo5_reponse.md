------------------------------------------------------------------------
Programme	:             -E	         -c	       Compilation complète
------------------------------------------------------------------------
Programme simple	:    0,206 s	    0,483 s	     0,496 s
------------------------------------------------------------------------
Avec 10 en-têtes	:    0,307 s	    0,570 s    	 0,610 s
------------------------------------------------------------------------
Avec les 10 en-têtes les trois temps augmentent l’étape qui domine est la compilation.

À partir de ces mesures :

-E : 0,206 s
-c : 0,483 s donc 0,277 s de plus que -E
compilation complète : 0,496 s donc 0,013 s de plus que -c

Ainsi le coût de chaque étape :
1- préprocesseur : 0,206 s
2- compilation : 0,277 s
3- édition de liens : 0,013 s

//message du compilateur avec les sorties time avec une entête 
time clang++ -c c1-exo10_main.cpp -o exo10

real    0m0.483s
user    0m0.409s
sys     0m0.86s

time clang++ -E c1-exo10_main.cpp -o exo10

real    0m0.206s
user    0m0.164s
sys     0m0.86s

time clang++ c1-exo10_main.cpp -o exo10

real    0m0.496s
user    0m0.410s
sys     0m0.82s

//soustraction 
0.483s - 0.206s = 0.277s
0.496s - 0.483s = 0.013s

//mon programme utilisé 
#include <iostream>
int main() {
    int nombre = 10;
    std::cout << "Bonjour !\n";
    return 0;
}

//programme avec les dix entêtes 
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <algorithm>
#include <cmath>
#include <fstream>
int main() {
    int nombre = 10;
    std::cout << "Bonjour !\n";
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> noms(n);
    std::vector<long long> dates(n);
    std::vector<bool> refaire(n, false);
    std::unordered_map<std::string, int> index;
    int nr = 0, aj = 0;
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> noms[i] >> dates[i] >> k;
        refaire[i] = (dates[i] == -1);
        while (k--) {
            std::string d;
            std::cin >> d;
            if (index.count(d)) {
                int j = index[d];
                if (dates[j] > dates[i] || refaire[j]) {
                    refaire[i] = true;
                }
            }
        }
        index[noms[i]] = i;
        if (refaire[i]) nr++;
        else aj++;
    }
    for (int i = 0; i < n; i++) {
        std::cout << noms[i] << " "
                  << (refaire[i] ? "A RECONSTRUIRE" : "A JOUR")
                  << '\n';
    }
    std::cout << "A RECONSTRUIRE " << nr << '\n';
    std::cout << "A JOUR " << aj << '\n';
    return 0;
}

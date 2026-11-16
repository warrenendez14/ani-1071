#include <iostream>
#include <string>
int main() {
    std::string s, n, m;
    int a = 0, f = 0, x, y;
     std::cin >> s >> x;
    if (s == "DEBUG") y = 0;
    else if (s == "INFO") y = 1;
    else if (s == "WARN") y = 2;
    else if (s == "ERROR") y = 3;
    else y = 4;
    while (x--) {
        std::cin >> n >> m;
        int v = n == "DEBUG" ? 0 : n == "INFO" ? 1 : n == "WARN" ? 2 : n == "ERROR" ? 3 : -1;
        if (v >= y) {
            std::cout << n << " " << m << '\n';
            a++;
        } else f++;
    }
    std::cout << "AFFICHES " << a << '\n';
    std::cout << "FILTRES " << f << '\n';
}

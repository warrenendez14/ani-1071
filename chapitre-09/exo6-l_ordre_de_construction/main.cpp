#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <functional>
int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> noms(n);
    std::vector<std::vector<std::string>> deps(n);
    std::unordered_map<std::string, int> index;
    for (int i = 0; i < n; i++) {
        std::cin >> noms[i];
        int k;
        std::cin >> k;
        while (k--) {
            std::string d;
            std::cin >> d;
            deps[i].push_back(d);
        }
        index[noms[i]] = i;
    }
    std::vector<std::vector<int>> adj(n);
    std::vector<int> deg(n, 0);
    for (int i = 0; i < n; i++) {
        for (const auto& d : deps[i]) {
            if (index.count(d)) {
                adj[index[d]].push_back(i);
                deg[i]++;
            }
        }
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    std::vector<int> ordre;
    while (!q.empty()) {
        int i = q.top();
        q.pop();
        ordre.push_back(i);
        for (int j : adj[i]) {
            if (--deg[j] == 0) q.push(j);
        }
    }
    if ((int)ordre.size() != n) {
        std::cout << "CYCLE\nPROJETS 0\n";
    } else {
        for (int i : ordre) std::cout << noms[i] << '\n';
        std::cout << "PROJETS " << n << '\n';
    }
}

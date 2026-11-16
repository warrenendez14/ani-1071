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
    std::unordered_map<std::string, int> index;
    for (int i = 0; i < n; i++) {
        std::cin >> noms[i];
        index[noms[i]] = i;
    }
    std::vector<std::vector<int>> adj(n);
    std::vector<int> deg(n, 0);
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        while (k--) {
            std::string d;
            std::cin >> d;
            if (index.count(d)) {
                adj[index[d]].push_back(i);
                deg[i]++;
            }
        }
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int i = 0; i < n; i++)
        if (!deg[i]) q.push(i);
    int total = 0;
    while (!q.empty()) {
        int i = q.top();
        q.pop();
        std::cout << noms[i] << '\n';
        total++;
        for (int j : adj[i])
            if (--deg[j] == 0) q.push(j);
    }
    if (total != n)
        std::cout << "CYCLE\nPROJETS 0\n";
    else
        std::cout << "PROJETS " << n << '\n';
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> noms(n);
    std::vector<std::vector<std::string>> deps(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> noms[i] >> m;
        while (m--)
        {
            std::string s;
            std::cin >> s;
            deps[i].push_back(s);
        }
    }
    std::vector<bool> fait(n, false);
    int total = 0;
    while (total < n)
    {
        bool avance = false;
        for (int i = 0; i < n; i++)
        {
            if (fait[i])
            {
                continue;
            }
            bool pret = true;
            for (std::string s : deps[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (noms[j] == s && !fait[j])
                    {
                        pret = false;
                    }
                }
            }
            if (pret)
            {
                std::cout << noms[i] << '\n';
                fait[i] = true;
                total++;
                avance = true;
            }
        }
        if (!avance)
        {
            std::cout << "CYCLE\nPROJETS 0\n";
            return 0;
        }
    }
    std::cout << "PROJETS " << total << '\n';
    return 0;
}

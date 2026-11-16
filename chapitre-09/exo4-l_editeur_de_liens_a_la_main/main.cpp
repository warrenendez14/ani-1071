#include <iostream>
#include <vector>
#include <string>
struct F
{
    std::string nom;
    std::vector<std::string> defs, statics, usages;
};
int main()
{
    int n;
    std::cin >> n;
    std::vector<F> f(n);
    std::vector<std::string> ind, dbl;
    for (int i = 0; i < n; i++)
    {
        int d, e;
        std::cin >> f[i].nom >> d;
        while (d--)
        {
            std::string s;
            int g;
            std::cin >> s >> g;
            (g ? f[i].statics : f[i].defs).push_back(s);
        }
        std::cin >> e;
        while (e--)
        {
            std::string s;
            std::cin >> s;
            f[i].usages.push_back(s);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (std::string s : f[i].usages)
        {
            bool ok = false;
            for (int j = 0; j < n; j++)
            {
                for (std::string x : f[j].defs)
                {
                    if (x == s) ok = true;
                }
            }
            for (std::string x : f[i].statics)
            {
                if (x == s) ok = true;
            }
            if (!ok && std::find(ind.begin(), ind.end(), s) == ind.end())
            {
                ind.push_back(s);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (std::string s : f[i].defs)
        {
            int c = 0;
            for (int j = 0; j < n; j++)
            {
                for (std::string x : f[j].defs)
                {
                    if (x == s) c++;
                }
            }
            if (c > 1 && std::find(dbl.begin(), dbl.end(), s) == dbl.end())
            {
                dbl.push_back(s);
            }
        }
    }
    for (std::string s : ind) std::cout << "INDEFINI " << s << '\n';
    for (std::string s : dbl) std::cout << "DOUBLE " << s << '\n';
    std::cout << "INDEFINIS " << ind.size() << '\n';
    std::cout << "DOUBLES " << dbl.size() << '\n';
    std::cout << "VERDICT " << (ind.empty() && dbl.empty() ? "LIE" : "ECHEC") << '\n';
}

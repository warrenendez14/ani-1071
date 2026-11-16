#include <iostream>
#include <vector>
#include <string>
struct F
{
    std::string nom;
    int garde;
    std::vector<int> inc;
};
void parcours(int x, std::vector<F>& f, std::vector<int>& c,
              std::vector<bool>& v, bool avec)
{
    for (int y : f[x].inc)
    {
        if (!avec || !f[y].garde || !v[y])
        {
            c[y]++;
            v[y] = true;
            parcours(y, f, c, v, avec);
        }
    }
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<F> f(n);
    std::vector<std::vector<std::string>> noms(n);
    std::vector<int> s(n), a(n);
    std::vector<bool> v(n, false);
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> f[i].nom >> f[i].garde >> m;
        while (m--)
        {
            std::string nom;
            std::cin >> nom;
            noms[i].push_back(nom);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (std::string nom : noms[i])
        {
            for (int j = 0; j < n; j++)
            {
                if (f[j].nom == nom)
                {
                    f[i].inc.push_back(j);
                    break;
                }
            }
        }
    }
    parcours(0, f, s, v, false);
    std::fill(v.begin(), v.end(), false);
    parcours(0, f, a, v, true);
    int ts = 0, ta = 0;
    for (int i = 1; i < n; i++)
    {
        std::cout << f[i].nom << " " << s[i] << " " << a[i] << '\n';
        ts += s[i];
        ta += a[i];
    }
    std::cout << "TOTAL SANS " << ts << '\n';
    std::cout << "TOTAL AVEC " << ta << '\n';
}

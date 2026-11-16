#include <iostream>
#include <vector>
#include <string>
struct F
{
    std::string nom;
    int garde;
    std::vector<int> inc;
};
void parcours(int x, std::vector<F>& f, std::vector<int>& s,
              std::vector<int>& a, std::vector<bool>& v, bool avec)
{
    for (int y : f[x].inc)
    {
        s[y]++;
        if (!avec || !f[y].garde || !v[y])
        {
            a[y]++;
            v[y] = true;
            parcours(y, f, s, a, v, avec);
        }
    }
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<F> f(n);
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
    parcours(0, f, s, a, v, false);
    parcours(0, f, s, a, v, true);
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

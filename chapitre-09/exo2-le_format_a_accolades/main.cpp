#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
int main()
{
    char ligne[1000];
    int n;
    scanf("%[^\n]", ligne);
    scanf("%d", &n);
    std::vector<int> arguments(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arguments[i]);
    }
    std::string format = ligne;
    std::string resultat;
    int remplaces = 0;
    int manquants = 0;
    for (int i = 0; i < (int)format.length(); i++)
    {
        if (format[i] == '{' && i + 2 < (int)format.length()
            && format[i + 1] >= '0' && format[i + 1] <= '9'
            && format[i + 2] == '}')
        {
            int numero = format[i + 1] - '0';
            if (numero < n)
            {
                resultat += std::to_string(arguments[numero]);
                remplaces++;
            }
            else
            {
                resultat += format.substr(i, 3);
                manquants++;
            }
            i += 2;
        }
        else
        {
            resultat += format[i];
        }
    }
    std::cout << resultat << '\n';
    std::cout << "REMPLACES " << remplaces << '\n';
    std::cout << "MANQUANTS " << manquants << '\n';
    return 0;
}

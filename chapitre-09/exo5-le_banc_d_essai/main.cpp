
#include <iostream>
#include <string>
int main()
{
    int n, ok = 0, ko = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::string type;
        int a, b;
        std::cin >> type >> a >> b;
        bool test = false;
        if (type == "EQUAL")
        {
            test = a == b;
        }
        else if (type == "NOT_EQUAL")
        {
            test = a != b;
        }
        else if (type == "LESS")
        {
            test = a < b;
        }
        else if (type == "GREATER")
        {
            test = a > b;
        }
        else if (type == "LESS_EQUAL")
        {
            test = a <= b;
        }
        else if (type == "GREATER_EQUAL")
        {
            test = a >= b;
        }
        if (test)
        {
            std::cout << "cas " << i << " OK\n";
            ok++;
        }
        else
        {
            std::cout << "cas " << i << " ECHEC attendu "
                      << a << " obtenu " << b << '\n';
            ko++;
        }
    }
    std::cout << "REUSSIS " << ok << '\n';
    std::cout << "ECHOUES " << ko << '\n';
    std::cout << "VERDICT " << (ko == 0 ? "VERT" : "ROUGE") << '\n';
    return 0;
  
}

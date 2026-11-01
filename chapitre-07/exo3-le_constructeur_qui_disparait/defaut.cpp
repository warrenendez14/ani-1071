#include <iostream>

struct P {
    int a;

    P(int v) : a(v) {}

    // P() : a(0) {}
    P() = default;
};

int main()
{
    P x;
    P t[10];

    std::cout << "x.a = " << x.a << "\n";
    return 0;
}

#include <iostream>
#include <vec2.h>
int main() {
    Vec2 a = {3, 4};
    Vec2 b = {1, 2};
    Vec2 c = addition(a, b);
    std::cout << longueur(a) << '\n';
    std::cout << distance(a, b) << '\n';
    std::cout << c.x << " " << c.y << '\n';
    return 0;
}

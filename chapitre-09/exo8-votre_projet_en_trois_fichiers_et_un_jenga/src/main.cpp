#include <iostream>
#include <vec2.h>
int main() {
    ani::Vec2 a = {3, 4};
    ani::Vec2 b = {1, 2};
    ani::Vec2 c = ani::addition(a, b);
    std::cout << ani::longueur(a) << '\n';
    std::cout << ani::distance(a, b) << '\n';
    std::cout << c.x << " " << c.y << '\n';
    return 0;
}

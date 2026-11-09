#include <iostream>

class Base {
public:
    int publique = 1;
protected:
    int protegee = 2;
private:
    int privee = 3;
};

class Derivee : public Base {
public:
    void tester() {
        std::cout << publique << '\n';
        std::cout << protegee << '\n';
        // std::cout << privee << '\n';
    }
};

int main() {
    Derivee d;
    std::cout << d.publique << '\n';
    // std::cout << d.protegee << '\n';
    // std::cout << d.privee << '\n';

    return 0;
}

// void soigner(Base& b) {
//     b.protegee = 10;
// }

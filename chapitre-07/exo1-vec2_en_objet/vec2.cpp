#include <iostream>
#include <cmath>

struct Vec2 {
    double x, y;

    Vec2() : x(0), y(0) {}
    Vec2(double a, double b) : x(a), y(b) {}

    double length() const { return std::sqrt(x*x + y*y); }
    double dot(Vec2 b) const { return x*b.x + y*b.y; }

    Vec2 normalized() const {
        double l = length();
        return l == 0 ? Vec2() : Vec2(x/l, y/l);
    }

    void normalize() {
        double l = length();
        if (l != 0) { x /= l; y /= l; }
    }

    Vec2& operator+=(Vec2 b) { x += b.x; y += b.y; return *this; }
    Vec2& operator-=(Vec2 b) { x -= b.x; y -= b.y; return *this; }
    Vec2& operator*=(double k) { x *= k; y *= k; return *this; }
    double& operator[](int i) { return i == 0 ? x : y; }
};

Vec2 operator+(Vec2 a, Vec2 b) { return {a.x+b.x, a.y+b.y}; }
Vec2 operator-(Vec2 a, Vec2 b) { return {a.x-b.x, a.y-b.y}; }
Vec2 operator-(Vec2 a) { return {-a.x, -a.y}; }
Vec2 operator/(Vec2 a, double k) { return {a.x/k, a.y/k}; }
Vec2 operator*(Vec2 a, double k) { return {a.x*k, a.y*k}; }
Vec2 operator*(double k, Vec2 a) { return a*k; }
bool operator==(Vec2 a, Vec2 b) { return a.x==b.x && a.y==b.y; }
bool operator!=(Vec2 a, Vec2 b) { return !(a==b); }

std::ostream& operator<<(std::ostream& os, Vec2 v) {
    return os << "(" << v.x << ", " << v.y << ")";
}

int main() {
    Vec2 a, b(3,4), c(2,1);

    std::cout << a << " " << b << "\n";
    std::cout << b.length() << " " << b.dot(c) << "\n";
    std::cout << b.normalized() << "\n";
    b.normalize();
    std::cout << b << "\n";

    a = Vec2(2,3);
    std::cout << a+c << " " << a-c << " " << -a << "\n";
    std::cout << a/2 << " " << a*2 << " " << 2*a << "\n";
    std::cout << (a==c) << " " << (a!=c) << "\n";
    a += c; a -= c; a *= 2; a[1] = 5;
    std::cout << a << "\n";

    Vec2 p(0,10), v(3,0), g(0,-9.81);
    double dt = 0.1, t = 0;

    while (p.y >= 0) {
        v += g * dt;
        p += v * dt;
        t += dt;
        std::cout << t << " " << p << " " << v << "\n";
    }

    std::cout << "Contact exact : " << std::sqrt(20.0/9.81) << " s\n";
}

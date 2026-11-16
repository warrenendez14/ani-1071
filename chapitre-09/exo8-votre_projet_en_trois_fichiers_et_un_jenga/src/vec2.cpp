#include <cmath>
#include <vec2.h>
namespace {
float carreNorme(Vec2 v) {
    return v.x * v.x + v.y * v.y;
}
}
Vec2 addition(Vec2 a, Vec2 b) {
    return {a.x + b.x, a.y + b.y};
}
float longueur(Vec2 v) {
    return std::sqrt(carreNorme(v));
}
float distance(Vec2 a, Vec2 b) {
    Vec2 d = {a.x - b.x, a.y - b.y};
    return std::sqrt(carreNorme(d));
}

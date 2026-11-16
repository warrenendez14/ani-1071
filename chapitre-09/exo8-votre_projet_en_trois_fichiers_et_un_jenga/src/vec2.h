#ifndef VEC2_H
#define VEC2_H
namespace ani {
struct Vec2 {
    float x;
    float y;
};
Vec2 addition(Vec2 a, Vec2 b);
float longueur(Vec2 v);
float distance(Vec2 a, Vec2 b);
}
#endif

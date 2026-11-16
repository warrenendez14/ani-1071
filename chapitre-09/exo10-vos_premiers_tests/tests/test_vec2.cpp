#include <NKTest/NkTest.h>
#include <vec2.h>
TEST(Vec2, Addition) {
    Vec2 a = {2, 3};
    Vec2 b = {4, 5};
    ASSERT_EQUAL(Vec2{6, 8}, addition(a, b));
}
TEST(Vec2, AdditionZero) {
    Vec2 a = {0, 0};
    Vec2 b = {3, 4};
    ASSERT_EQUAL(Vec2{3, 4}, addition(a, b));
}
TEST(Vec2, Longueur) {
    Vec2 a = {3, 4};
    ASSERT_EQUAL(5.0f, longueur(a));
}
TEST(Vec2, Distance) {
    Vec2 a = {1, 2};
    Vec2 b = {4, 6};
    ASSERT_EQUAL(5.0f, distance(a, b));
}
TEST(Vec2, ValeurBordBas) {
    Vec2 a = {0, 0};
    ASSERT_EQUAL(0.0f, longueur(a));
}
TEST(Vec2, ValeurBordHaut) {
    Vec2 a = {6, 8};
    ASSERT_EQUAL(10.0f, longueur(a));
}
TEST(Vec2, CasDegenere) {
    Vec2 a = {0, 0};
    ASSERT_EQUAL(0.0f, distance(a, a));
}
TEST(Vec2, Flottant) {
    Vec2 a = {1, 1};
    ASSERT_EQUAL(1.4142135f, longueur(a));
    ASSERT_NEAR(1.4142135f, longueur(a), 0.0001f);
}

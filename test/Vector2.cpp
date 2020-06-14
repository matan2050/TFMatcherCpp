#include "../third_party/doctest/doctest.h"
#include "../include/Vector2.h"

// unit tests
TEST_CASE("test vector functions")
{
    Vector2 zeroVector(0.0f, 0.0f);
    Vector2 negativeVector(-1.0f, -10.0f);
	Vector2 vec1(1.0f, 1.0f);
	Vector2 vec2(2.0f, 3.0f);
    

    SUBCASE("test equality operator, copy constructor and assignment operator");
    Vector2 vec1Clone(vec1);
    CHECK(vec1 == vec1Clone);
    Vector2 vec1Clone2 = vec1;
    CHECK(vec1 == vec1Clone2);
    CHECK(vec1 != vec2);


    SUBCASE("test dot product");
	CHECK(abs(vec1.Dot(vec2) - 5.0f) < EPSILON);
    CHECK(abs(vec1.Dot(zeroVector)) < EPSILON);
    CHECK(abs(vec1.Dot(negativeVector) - (-11.0f)) < EPSILON);

	CHECK((abs(vec3.GetElement1() - vec1.GetElement1()) < EPSILON));
	CHECK((abs(vec3.GetElement2() - vec1.GetElement2()) < EPSILON));

	vec3 += vec1;
}
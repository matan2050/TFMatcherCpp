#include "../third_party/doctest/doctest.h"
#include "../include/Vector2.h"

// unit tests
TEST_CASE("test vector functions")
{
	Vector2 vec1(1.0f, 1.0f);
	Vector2 vec2(2.0f, 3.0f);

	CHECK(vec1.Dot(vec2) - 5.0f < EPSILON);

	Vector2 vec3 = vec1;

	CHECK((abs(vec3.GetElement1() - vec1.GetElement1()) < EPSILON));
	CHECK((abs(vec3.GetElement2() - vec1.GetElement2()) < EPSILON));

	vec3 += vec1;
}
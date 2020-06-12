#include <math.h>
#include "../include/Vector2.h"

#include "../third_party/doctest/doctest.h"

// constructors
Vector2::Vector2() : element1(0), element2(0) {}
Vector2::Vector2(double _element1, double _element2) : element1(_element1), element2(_element2) {}

// getters
double Vector2::GetElement1() const { return element1; }
double Vector2::GetElement2() const { return element2; }

// operator overloads
void Vector2::operator=(const Vector2& _otherVec)
{
	element1 = _otherVec.element1;
	element2 = _otherVec.element2;
}

void Vector2::operator+(const Vector2& _otherVec)
{
	element1 += _otherVec.element1;
	element2 += _otherVec.element2;
}

void Vector2::operator+=(const Vector2& _otherVec)
{
	*this + _otherVec;
}

bool Vector2::operator==(const Vector2& _otherVec)
{
	return ((abs(element1 - _otherVec.element1) < EPSILON) &&
		(abs(element2 - _otherVec.element2) < EPSILON));
}

// vector algebra functions
double Vector2::Dot(Vector2 _otherVec) const
{
	return element1*_otherVec.element1 + element2*_otherVec.element2;
}

double Vector2::CrossDirection(Vector2 _vec2) const
{
	double zCross = GetElement1() * _vec2.GetElement2() - GetElement2() *_vec2.GetElement1();

	if (zCross > 0) { return 1.0; }
	else { return -1.0; }
}

double Vector2::Magnitude() const
{
	return sqrt(element1*element1 + element2*element2);
}

string Vector2::ToString() const
{
	ostringstream ss;
	ss << element1 << ", " << element2;
	return ss.str();
}

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
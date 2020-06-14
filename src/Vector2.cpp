#include "../include/Vector2.h"
#include "../third_party/doctest/doctest.h"

// constructors
Vector2::Vector2() : element1(0), element2(0) {}
Vector2::Vector2(double _element1, double _element2) : 
    element1(_element1), element2(_element2) {}

Vector2::Vector2(const Vector2& _other) : 
    element1(_other.element1), element2(_other.element2) {}

// getters
double Vector2::GetElement1() const { return element1; }
double Vector2::GetElement2() const { return element2; }

// operator overloads
void Vector2::operator=(const Vector2& _other)
{
	element1 = _other.element1;
	element2 = _other.element2;
}

void Vector2::operator+(const Vector2& _other)
{
	element1 += _other.element1;
	element2 += _other.element2;
}

void Vector2::operator+=(const Vector2& _other)
{
	*this + _other;
}

bool Vector2::operator==(const Vector2& _other) const
{
	return ((abs(element1 - _other.element1) < EPSILON) &&
		(abs(element2 - _other.element2) < EPSILON));
}

bool Vector2::operator!=(const Vector2& _other) const
{
    if (element1 != _other.element1 || element2 != _other.element2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// vector algebra functions
double Vector2::Dot(Vector2 _other) const
{
	return element1*_other.element1 + element2*_other.element2;
}

double Vector2::CrossDirection(Vector2 _vec2) const
{
	double zCross = 
        GetElement1() * _vec2.GetElement2() -
        GetElement2() *_vec2.GetElement1();

	if (zCross > 0) 
    { 
        return 1.0; 
    }
	else 
    { 
        return -1.0; 
    }
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
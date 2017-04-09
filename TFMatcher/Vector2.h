#pragma once

#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class Vector2 
{
private:
	double element1;
	double element2;

public:
	Vector2();
	Vector2(double, double);

	//Vector2 operator=(const Vector2&);

	double GetElement1() const;
	double GetElement2() const;

	double Dot(Vector2) const;
	double Magnitude() const;
	string ToString() const;
};
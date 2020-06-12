#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include "SharedDefinitions.h"
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

struct Vector2 
{
private:
	double element1;
	double element2;

public:
	Vector2();
	Vector2(double, double);

	void operator=(const Vector2&);
	void operator+(const Vector2&);
	void operator+=(const Vector2&);

	double GetElement1() const;
	double GetElement2() const;

	double Dot(Vector2) const;
	double CrossDirection(Vector2) const;

	double Magnitude() const;
	string ToString() const;
};

#endif
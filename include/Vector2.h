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
	// constructors --------
	Vector2();
	Vector2(double, double);
    Vector2(const Vector2&);
	// ---------------------

	// operator overloads ----------
	void operator=(const Vector2&);
	void operator+(const Vector2&);
	void operator+=(const Vector2&);
    void operator-(const Vector2&);
    void operator-=(const Vector2&);
	bool operator==(const Vector2&) const;
    bool operator!=(const Vector2&) const;
	// -----------------------------

	// getters ----------------
	double GetElement1() const;
	double GetElement2() const;
	// ------------------------

	// vector algebra functions ---------
	double Dot(Vector2) const;
	double CrossDirection(Vector2) const;
	double Magnitude() const;
	// ----------------------------------

	// auxiliary methods ---
	string ToString() const;
	// ---------------------
};

#endif
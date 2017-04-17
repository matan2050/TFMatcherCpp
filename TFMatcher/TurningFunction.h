#pragma once
#include <vector>
#include <math.h>
#include "Polygon.h"
#include "SharedDefinitions.h"
#include "StringUtils.h"

#define RANGE_MIN 0
#define RANGE_MAX 1

class TurningFunction
{
private:
	vector<double> range;
	vector<double> image;

public:

	// CONSTRUCTORS
	TurningFunction::TurningFunction();
	TurningFunction(Polygon);
	TurningFunction(TurningFunction&);
	
	// FUNCTION RANGE AND IMAGE GENERATORS
	vector<double> CalculateNormalizedRange(Polygon);
	vector<double> CalculateImage(Polygon);

	double ValueAt(float) const;

	// GETTERS
	vector<double> GetRange() const;
	vector<double> GetImage() const;

	// HELPER FUNCTIONS
	string ToString() const;
};

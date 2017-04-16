#pragma once
#include <vector>
#include <math.h>
#include "Polygon.h"
#include "SharedDefinitions.h"

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
	string OutputMatlabVector(string, const vector<double>&) const;
};

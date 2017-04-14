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
	
	// FUNCTION RANGE AND IMAGE GENERATORS
	vector<double> CalculateNormalizedRange(Polygon);
	vector<double> CalculateImage(Polygon);

	double ValueAt(float);
	double Distance(TurningFunction);

	// GETTERS
	vector<double> GetRange();
	vector<double> GetImage();

	// HELPER FUNCTIONS
	string ToString() const;
	string OutputMatlabVector(string, const vector<double>&) const;
};

#pragma once
#include <vector>
#include <math.h>
#include "Polygon.h"

class TurningFunction
{
private:
	vector<double> range;
	vector<double> image;

public:
	TurningFunction();
	TurningFunction(Polygon);
	
	vector<double> CalculateNormalizedRange(Polygon);
	vector<double> CalculateImage(Polygon);

	string ToString() const;
	string OutputMatlabVector(string, const vector<double>&) const;
};

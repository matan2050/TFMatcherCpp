#ifndef _TURNING_FUNCTION_H_
#define _TURNING_FUNCTION_H_
#include <vector>
#include <math.h>
#include "Polygon.h"
#include "SharedDefinitions.h"
#include "StringUtils.h"

constexpr double RANGE_MIN = 0;
constexpr double RANGE_MAX = 1;

class TurningFunction
{
private:
	std::vector<double> range;
	std::vector<double> image;

public:

	// CONSTRUCTORS
	TurningFunction();
	TurningFunction(const Polygon&);
	TurningFunction(const TurningFunction&);
	
	// FUNCTION RANGE AND IMAGE GENERATORS
	std::vector<double> CalculateNormalizedRange(const Polygon&);
	std::vector<double> CalculateImage(const Polygon&);

	double ValueAt(double) const;

	// GETTERS
	std::vector<double> GetRange() const;
	std::vector<double> GetImage() const;

	// HELPER FUNCTIONS
	string ToString() const;
};

#endif
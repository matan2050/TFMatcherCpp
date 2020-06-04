#ifndef _MATCHER_H_
#define _MATCHER_H_

#include <vector>
#include "Polygon.h"
#include "TurningFunction.h"
#include "AlignedTF.h"

class Matcher
{
private:
	double distance = 0.0f;
	TurningFunction turningFunctionA;
	vector<TurningFunction> reshapedTurningFunctionB;

public:
	Matcher(const Polygon&, const Polygon&);
	vector<TurningFunction> GenerateReshapedFunction(const Polygon&);
	Polygon GenerateReshapedPolygon(const Polygon&, int, int, int);
	double Distance() const;
};

#endif
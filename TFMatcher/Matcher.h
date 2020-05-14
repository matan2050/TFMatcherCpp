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
	Matcher(Polygon, Polygon);
	vector<TurningFunction> GenerateReshapedFunction(Polygon);
	Polygon GenerateReshapedPolygon(Polygon, int, int, int);
	double Distance();
};

#endif
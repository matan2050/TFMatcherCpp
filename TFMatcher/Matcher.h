#pragma once
#include <vector>
#include "Polygon.h"
#include "TurningFunction.h"
#include "AlignedTF.h"

class Matcher
{
private:
	double distance = NULL;
	TurningFunction turningFunctionA;
	vector<TurningFunction> reshapedTurningFunctionB;

public:
	Matcher(Polygon, Polygon);
	vector<TurningFunction> GenerateReshapedFunction(Polygon);
	Polygon GenerateReshapedPolygon(Polygon, int, int, int);
	double Distance();
};

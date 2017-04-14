#pragma once
#include <vector>

#include "SharedDefinitions.h"
#include "Vector2.h"
#include "TurningFunction.h"

class AlignedTF
{
private:
	vector<double> sharedRangeEvents;
	TurningFunction turningFunctionA;
	TurningFunction turningFunctionB;

public:
	//AlignedTF();
	AlignedTF(TurningFunction, TurningFunction);

	double Distance();
};
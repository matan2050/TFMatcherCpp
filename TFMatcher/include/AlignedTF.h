#ifndef _ALIGNED_TF_H
#define _ALIGNED_TF_H

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

#endif
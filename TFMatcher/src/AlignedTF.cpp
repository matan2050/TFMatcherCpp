#include "../include/AlignedTF.h"

/*AlignedTF::AlignedTF()
{
}*/

AlignedTF::AlignedTF(TurningFunction _tfA, TurningFunction _tfB) : turningFunctionA(_tfA), turningFunctionB(_tfB)
{
	vector<double> rangeA = _tfA.GetRange();
	vector<double> rangeB = _tfB.GetRange();

	vector<double>::const_iterator iterA = rangeA.begin();
	vector<double>::const_iterator iterB = rangeB.begin();

	// assuming both ranges start at 0
	sharedRangeEvents.push_back(*iterA);

	iterA++;
	iterB++;

	while (iterA != rangeA.end())
	{
		// *iterA == *iterB
		if (*iterB - *iterA > EPSILON)
		{
			sharedRangeEvents.push_back(*iterA);

			if (iterA != rangeA.end())
			{
				iterA++;
				continue;
			}
			
		}

		// *iterA > *iterB
		if (*iterA - *iterB > EPSILON)
		{
			sharedRangeEvents.push_back(*iterB);

			if (iterB != rangeB.end())
			{
				iterB++;
				continue;
			}
		}

		// *iterA < *iterB
		if (*iterA - *iterB < EPSILON)
		{
			sharedRangeEvents.push_back(*iterA);
			iterA++;
			iterB++;
			continue;
		}
	}

	while (iterB != rangeB.end())
	{
		sharedRangeEvents.push_back(*iterB);
	}
}

double AlignedTF::Distance()
{
	double distance = 0;

	double currentX, nextX;
	double valueA, valueB;

	for (int i = 0; i < sharedRangeEvents.size() - 1; i++)
	{
		currentX = sharedRangeEvents[i];
		valueA = turningFunctionA.ValueAt(currentX);
		valueB = turningFunctionB.ValueAt(currentX);

		nextX = sharedRangeEvents[i + 1];

		distance += (nextX - currentX)*(valueB - valueA)*(valueB - valueA);
	}

	distance = sqrt(distance);
	return distance;
}
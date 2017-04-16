#include "Matcher.h"

Matcher::Matcher(Polygon _polyA, Polygon _polyB)
{
	turningFunctionA = TurningFunction(_polyA);
	reshapedTurningFunctionB = GenerateReshapedFunction(_polyB);
}

Polygon Matcher::GenerateReshapedPolygon(Polygon _poly, int startIndex, int endIndex, int numVertices)
{
	Polygon reshapedPoly = Polygon();

	for (int vertex = startIndex; vertex < numVertices; vertex++)
	{
		reshapedPoly.AddVertex(_poly.GetVertex(vertex));
	}

	for (int vertex = 0; vertex <= endIndex; vertex++)
	{
		reshapedPoly.AddVertex(_poly.GetVertex(vertex));
	}

	return reshapedPoly;
}

vector<TurningFunction> Matcher::GenerateReshapedFunction(Polygon _poly)
{
	int numReshapedFuncs = _poly.GetEdgeCount();
	vector<TurningFunction> reshapedFunc(numReshapedFuncs);

	for (int poly = 0; poly < numReshapedFuncs; poly++)
	{
		int startIndex = poly;
		int endIndex = (poly + numReshapedFuncs) % numReshapedFuncs;

		Polygon reshapedPoly = GenerateReshapedPolygon(_poly, startIndex, endIndex, numReshapedFuncs);
		TurningFunction thisFunc = TurningFunction(reshapedPoly);

		reshapedFunc[poly] = thisFunc;
	}

	return reshapedFunc;
}

double Matcher::Distance()
{
	double minDistance = INT32_MAX;

	for (int i = 0; i < reshapedTurningFunctionB.size(); i++)
	{
		AlignedTF matchedPair = AlignedTF(turningFunctionA, reshapedTurningFunctionB[i]);
		double distance = matchedPair.Distance();

		if (distance < minDistance)
		{
			minDistance = distance;
		}
	}

	return minDistance;
}
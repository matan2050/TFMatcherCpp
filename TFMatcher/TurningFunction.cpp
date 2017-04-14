#include <assert.h>
#include "TurningFunction.h"

// #define NDEBUG

TurningFunction::TurningFunction()
{

}

TurningFunction::TurningFunction(Polygon _poly) : TurningFunction()
{
	range = CalculateNormalizedRange(_poly);
	image = CalculateImage(_poly);
}

vector<double> TurningFunction::CalculateNormalizedRange(Polygon _poly)
{
	vector<double> tempRange;
	tempRange.push_back(0);

	double polygonPerimeter = _poly.GetPerimeter();
	vector<Vector2> edges = _poly.GetEdges();
	double perimeterAccumulator = 0;

	for (vector<Vector2>::const_iterator iter = edges.begin(); iter != edges.end(); iter++)
	{
		double segmentPerimeter = iter->Magnitude();
		double currentSegment = segmentPerimeter / polygonPerimeter;
		
		perimeterAccumulator += currentSegment;

		tempRange.push_back(perimeterAccumulator);
	}

	return tempRange;
}

vector<double> TurningFunction::CalculateImage(Polygon _poly)
{
	vector<double> tempImage;
	vector<Vector2> edges = _poly.GetEdges();
	double angleAccumulator = 0;
	tempImage.push_back(angleAccumulator);

	for (vector<Vector2>::const_iterator iter = edges.begin(); iter != edges.end(); iter++)
	{
		Vector2 edgeA = *iter;
		Vector2 edgeB;

		if ((iter + 1) == edges.end())
			edgeB = *edges.begin();
		else
			edgeB = *(iter+1);

		double angle;

		angle = edgeA.Dot(edgeB);
			
		double magA = edgeB.Magnitude();
		double magB = edgeB.Magnitude();

		assert((magA != 0) && (magB != 0));

		angle /= magA*magB;
		angle = acos(angle);

		angleAccumulator += angle;
		tempImage.push_back(angleAccumulator);
	}
	return tempImage;
}

vector<double> TurningFunction::GetRange()
{
	return range;
}

vector<double> TurningFunction::GetImage()
{
	return image;
}

double TurningFunction::ValueAt(float _x)
{
	int polygonLength = range.size();
	int mid = polygonLength / 2;

	while ((mid >= 0) || (mid < polygonLength))
	{
		// range[mid] == _x
		if (abs(range[mid] - _x) < EPSILON)
		{
			return image[mid];
		}

		if (range[mid] < _x)
		{
			if (range[mid + 1] < polygonLength)
			{
				if ((range[mid + 1]) > _x)
					return image[mid];
			}

			mid += mid / 2;
		}

		if (range[mid] > _x)
		{
			if (range[mid - 1] >= 0)
			{
				if (range[mid - 1] < _x)
					return image[mid - 1];
			}

			mid /= 2;
		}
	}

}

double Distance(TurningFunction _other)
{
	return 0;
}

string TurningFunction::ToString() const
{
	string rangeString = OutputMatlabVector("range", range);
	string imageString = OutputMatlabVector("image", image);

	return rangeString + imageString;
}

//TODO: move function to a shared library
string TurningFunction::OutputMatlabVector(string _vectorName, const vector<double>& _vec) const
{
	ostringstream ss;

	ss << _vectorName << " = [";
	for (vector<double>::const_iterator iter = _vec.begin(); iter != _vec.end(); iter++)
	{
		if (iter + 1 != _vec.end())
			ss << *iter << ", ";
		else
			ss << *iter << "]" << endl;
	}

	return ss.str();
}
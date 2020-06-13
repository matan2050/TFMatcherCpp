#include <assert.h>
#include "../include/TurningFunction.h"

// #define NDEBUG

TurningFunction::TurningFunction() {}

TurningFunction::TurningFunction(const Polygon& _poly) : TurningFunction()
{
	range = CalculateNormalizedRange(_poly);
	image = CalculateImage(_poly);
}

TurningFunction::TurningFunction(const TurningFunction& other)
{
	image = other.GetImage();
	range = other.GetRange();
}

vector<double> TurningFunction::CalculateNormalizedRange(const Polygon& _poly)
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
		
		perimeterAccumulator += currentSegment * RANGE_MAX;	// scale range according to RANGE_MAX

		tempRange.push_back(perimeterAccumulator);
	}

	return tempRange;
}

vector<double> TurningFunction::CalculateImage(const Polygon& _poly)
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
			
		double magA = edgeA.Magnitude();
		double magB = edgeB.Magnitude();

		assert((magA != 0) && (magB != 0));

		angle /= magA*magB;
		angle = acos(angle);

		angleAccumulator += edgeA.CrossDirection(edgeB) * angle;
		tempImage.push_back(angleAccumulator);
	}
	return tempImage;
}

vector<double> TurningFunction::GetRange() const
{
	return range;
}

vector<double> TurningFunction::GetImage() const
{
	return image;
}

double TurningFunction::ValueAt(double _x) const
{
	if ((_x < RANGE_MIN) || (_x > RANGE_MAX))
	{
		throw new std::invalid_argument("invalid range value");
	}

	size_t polygonLength = range.size();
	size_t mid = polygonLength / 2;

	while ((mid >= 0) || (mid < polygonLength))
	{
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

string TurningFunction::ToString() const
{
	string rangeString = StringUtils::OutputMatlabVector("range", range);
	string imageString = StringUtils::OutputMatlabVector("image", image);

	return rangeString + imageString;
}

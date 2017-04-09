#include <iostream>
#include "Vector2.h"
#include "Polygon.h"
#include "TurningFunction.h"

using namespace std;

int main()
{
	Vector2 vec(1, 5);
	cout << vec.Magnitude() << endl;

	Vector2 otherVector(10, 2);
	cout << vec.Dot(otherVector) << endl;

	Vector2* vecPtr;
	vecPtr = &vec;

	Vector2 newVec = *vecPtr;

	Polygon poly = Polygon();

	poly.AddVertex(Vector2(0, 0));
	poly.AddVertex(Vector2(0, 1));
	poly.AddVertex(Vector2(1, 1));
	poly.AddVertex(Vector2(1, 0));
	poly.AddVertex(Vector2(0, 0));

	cout << poly.ToString();
	cout << poly.GetPerimeter();
	
	TurningFunction tf = TurningFunction(poly);
	cout << tf.ToString();

	system("pause");
	return 0;
}
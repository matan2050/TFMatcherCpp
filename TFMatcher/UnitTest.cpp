#include <iostream>
#include "Vector2.h"
#include "Polygon.h"
#include "TurningFunction.h"
#include "Matcher.h"
#include "AlignedTF.h"

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

	double val1 = tf.ValueAt(0.23);
	double val2 = tf.ValueAt(0.26);
	double val3 = tf.ValueAt(1);
	double val4 = tf.ValueAt(0.99);

	Matcher match = Matcher(poly, poly);
	match.GenerateReshapedFunction(poly);

	auto polyB = Polygon();
	polyB.AddVertex(Vector2(0, 0));
	polyB.AddVertex(Vector2(0, 2));
	polyB.AddVertex(Vector2(1, 2));
	polyB.AddVertex(Vector2(1, 0));
	polyB.AddVertex(Vector2(0, 0));

	auto tfB = TurningFunction(polyB);
	AlignedTF tfAB = AlignedTF(tf, tfB);

	std::system("pause");
	return 0;
}
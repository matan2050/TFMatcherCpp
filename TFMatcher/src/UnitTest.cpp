#include <iostream>
#include "../include/Vector2.h"
#include "../include/Polygon.h"
#include "../include/TurningFunction.h"
#include "../include/Matcher.h"
#include "../include/AlignedTF.h"

using namespace std;

int main()
{
	Vector2 vec(1, 5);
	cout << vec.Magnitude() << endl;

	Vector2 otherVector(10, 2);
	cout << vec.Dot(otherVector) << endl;

	Vector2* vecPtr;
	vecPtr = &vec;

	auto poly = Polygon();
	poly.AddVertex(Vector2(0, 0));
	poly.AddVertex(Vector2(0, 1));
	poly.AddVertex(Vector2(1, 1));
	poly.AddVertex(Vector2(1, 0));
	poly.AddVertex(Vector2(0, 0));
	TurningFunction tf = TurningFunction(poly);
	cout << poly.ToString();
	cout << tf.ToString();
	cout << poly.GetPerimeter();
	
	auto otherPoly = Polygon();
	otherPoly.AddVertex(Vector2(0, 0));
	otherPoly.AddVertex(Vector2(1, 0));
	otherPoly.AddVertex(Vector2(1, 1));
	otherPoly.AddVertex(Vector2(0, 1));
	otherPoly.AddVertex(Vector2(0, 0));
	auto otherTf = TurningFunction(otherPoly);
	cout << otherPoly.ToString();
	cout << otherTf.ToString();

	double val1 = tf.ValueAt(0.23);
	double val2 = tf.ValueAt(0.26);
	double val3 = tf.ValueAt(1);
	double val4 = tf.ValueAt(0.99);

	std::cout<<val1<<","<<val2<<","<<val3<<","<<val4<<"\n";

	Matcher match = Matcher(poly, poly);
	match.GenerateReshapedFunction(poly);

	auto polyB = Polygon();
	polyB.AddVertex(Vector2(0, 0));
	polyB.AddVertex(Vector2(0, 2));
	polyB.AddVertex(Vector2(1, 2));
	polyB.AddVertex(Vector2(1, 0));
	polyB.AddVertex(Vector2(0, 0));

	auto tfB = TurningFunction(polyB);
	cout << tfB.ToString();
	AlignedTF tfAB = AlignedTF(tf, tfB);

	auto polyC = Polygon();
	polyC.AddVertex(Vector2(0, 0));
	polyC.AddVertex(Vector2(2, 0));
	polyC.AddVertex(Vector2(5, 1));
	polyC.AddVertex(Vector2(30, 2));
	polyC.AddVertex(Vector2(20, 3));
	polyC.AddVertex(Vector2(5, 4));
	polyC.AddVertex(Vector2(0, 0));

	auto tfC = TurningFunction(polyC);
	cout << tfC.ToString();
	std::system("pause");
	return 0;
}
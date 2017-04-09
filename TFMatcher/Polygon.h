#pragma once

#include <vector>
#include <sstream>
#include <string>
#include "Vector2.h"

using namespace std;

class Polygon
{
private:
	vector<Vector2> vertices;
	vector<Vector2> edges;
	double perimeter;

public:
	Polygon();
	Polygon(vector<Vector2>);
	
	void AddVertex(Vector2);
	void AddEdge(Vector2);
	double GetPerimeter() const;
	vector<Vector2> GetVertices() const;
	vector<Vector2> GetEdges() const;
	string ToString() const;

};

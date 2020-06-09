#ifndef _POLYGON_H_
#define _POLYGON_H_

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
	int edgeCount = 0;
	int vertexCount = 0;
	double perimeter;

public:
	
	// CONSTRUCTORS
	Polygon();
	Polygon(const vector<Vector2>&);
	Polygon(const Polygon&);
	
	// VERTEX AND EDGE ADDING FUNCTIONS
	void AddVertex(Vector2);
	void AddEdge(Vector2);

	// GETTERS
	vector<Vector2> GetVertices() const;
	vector<Vector2> GetEdges() const;
	int GetEdgeCount() const;
	int GetVertexCount() const;
	double GetPerimeter() const;
	Vector2 GetVertex(unsigned int index) const;

	// HELPER FUNCTIONS
	string ToString() const;
};

#endif
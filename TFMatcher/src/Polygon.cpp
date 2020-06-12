#include "../include/Polygon.h"
#include "../third_party/doctest/doctest.h"

// ctor & dtor
Polygon::Polygon() {}

Polygon::Polygon(const vector<Vector2>& _vertices)
{
	vertices = _vertices;
	
	for (vector<Vector2>::const_iterator iter = _vertices.begin(); iter != _vertices.end(); iter++)
	{
		perimeter += iter->Magnitude();
	}
}


void Polygon::AddVertex(Vector2 _vertex)
{
	Vector2 lastVertex;

	vertices.push_back(_vertex);
	vertexCount++;

	if (vertices.size() == 1)
		return;
	else
		lastVertex = vertices[vertices.size() - 2];

	Vector2 edge = Vector2(_vertex.GetElement1() - lastVertex.GetElement1(), _vertex.GetElement2() - lastVertex.GetElement2());
	AddEdge(edge);
	edgeCount++;
}

void Polygon::AddEdge(Vector2 _edge)
{
	edges.push_back(_edge);
	perimeter += _edge.Magnitude();
}

string Polygon::ToString() const
{
	ostringstream ss;

	for (vector<Vector2>::const_iterator iter = vertices.begin(); iter != vertices.end(); iter++)
	{
		ss << iter->ToString() << endl;
	}

	return ss.str();
}

double Polygon::GetPerimeter() const
{
	return perimeter;
}

Vector2 Polygon::GetVertex(unsigned int index) const
{
	return vertices[index];
}

vector<Vector2> Polygon::GetVertices() const
{
	return vertices;
}

vector<Vector2> Polygon::GetEdges() const
{
	return edges;
}

int Polygon::GetEdgeCount() const
{
	return edgeCount;
}

int Polygon::GetVertexCount() const
{
	return vertexCount;
}
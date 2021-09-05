#include <cassert>
#include "graph.h"

using namespace std;

Graph::Graph(int maxVertices) :
	maxVertices{maxVertices},
	nVertices{0},
	vertices{new char[maxVertices + 1]},	// extra char at end so that ...
	adjacencyMatrix{maxVertices, false}
{
	for (int i{0}; i < maxVertices + 1; i++)
		vertices[i] = '\0';					// ... gdb can print as C string ...
}											// ... even when full

Graph::~Graph()
{
	delete[] vertices;
}

void Graph::createVertex(char vName)
{
	if (nVertices < maxVertices)
		vertices[nVertices++] = vName;
	else
		assert(false);
}

bool Graph::edgeExists(char v1Name, char v2Name)
{
	int	v1Index{vertexIndex(v1Name)};
	int	v2Index{vertexIndex(v2Name)};

	return adjacencyMatrix.item(v1Index, v2Index);
}

void Graph::createEdge(char v1Name, char v2Name)
{
	setEdge(v1Name, v2Name, true);
}

void Graph::deleteEdge(char v1Name, char v2Name)
{
	setEdge(v1Name, v2Name, false);
}

void Graph::setEdge(char v1Name, char v2Name, bool edgeExists)
{
	int	v1Index{vertexIndex(v1Name)};
	int	v2Index{vertexIndex(v2Name)};

	adjacencyMatrix.item(v1Index, v2Index) = edgeExists;
}

void Graph::traverse(char vName, TraversalOrder order, ostream& out)
{
	int		nBuffered;
	int*	traverseBuffer	{new int[nVertices]};
	bool*	buffered		{new bool[nVertices]};
	int		currentIndex	{vertexIndex(vName)};

	cout << (order == Graph::TraversalOrder::DEPTH_FIRST ?
				"depth-first traversal   (" :
				"breadth-first traversal (")
		 << vName
		 << "): ";

	for (int i{0}; i < nVertices; i++)
		buffered[i] = false;

	// add specified vertex's index to traverseBuffer
	traverseBuffer[0] = currentIndex;
	nBuffered = 1;
	buffered[currentIndex] = true;

	// while there are still "untraversed" vertices, traverse next vertex
	// (the index of the next vertex always comes from traverseBuffer[0])
	do {
		if (order == Graph::TraversalOrder::DEPTH_FIRST)
			// use traverseBuffer like a stack
			currentIndex = traverseBuffer[--nBuffered];
		else {	  // Graph::TraversalOrder::BREADTH_FIRST
			// use traverseBuffer like a queue
			currentIndex = traverseBuffer[0];
			for (int i{1}; i < nBuffered; i++)
				traverseBuffer[i - 1] = traverseBuffer[i];
			nBuffered--;
			}
		out << vertices[currentIndex] << " ";
		for (int i{0}; i < nVertices; i++)
			if (adjacencyMatrix.item(currentIndex, i) && ! buffered[i]) {
				traverseBuffer[nBuffered++] = i;
				buffered[i] = true;
				}
		} while (nBuffered > 0);
	
	out << endl;

	delete[] traverseBuffer;
	delete[] buffered;
}

int Graph::vertexIndex(char name)
{
	for (int i{0}; i < nVertices; i++)
		if (name == vertices[i])
			return i;
	assert(false);
}

char Graph::vertexName(int index)
{
	assert(index >= 0 && index < nVertices);
	return vertices[index];
}

ostream& operator<<(ostream& out, Graph& graph)
{
	char	spacer[]{"  "};

	out << spacer << "vertices: ";
	for (int i{0}; i < graph.nVertices; i++)
		out << graph.vertices[i] << " ";
	out << endl << endl;

	out << spacer << "edges:" << endl;
	for (int i{0}; i < graph.nVertices; i++)
		for (int j{0}; j <= i; j++)
			if (graph.adjacencyMatrix.item(i, j))
				out << spacer << spacer
					<< graph.vertices[i]
					<< " -- "
					<< graph.vertices[j]
					<< endl;

	return out;
}

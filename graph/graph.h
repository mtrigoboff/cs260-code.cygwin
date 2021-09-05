#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include "triangulararray.h"

class Graph
{
public:
	enum class TraversalOrder{DEPTH_FIRST, BREADTH_FIRST};

	Graph(int nVertices);
	~Graph();
	void createVertex(char vName);
	bool edgeExists(char v1Name, char v2Name);
	void createEdge(char v1Name, char v2Name);
	void deleteEdge(char v1Name, char v2Name);
	void traverse(char vName, TraversalOrder order, std::ostream& out);

	friend std::ostream& operator<<(std::ostream& out, Graph& graph);

private:
	int				maxVertices;
	int				nVertices;
	char			*vertices;
	TriangularArray	adjacencyMatrix;

	void setEdge(char v1Name, char v2Name, bool edgeExists);
	int vertexIndex(char name);
	char vertexName(int index);
};

#endif	// _GRAPH_H_

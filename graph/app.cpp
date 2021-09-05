#include <cstring>
#include <iostream>
#include "graph.h"

using namespace std;

/* This is the graph:

      A-----B     F
     / \   / \   /
    /   \ /   \ /
   E     D-----C

*/

int main(int argc, char** argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	char	vertexNames[]{"ABCDEF"};
	int		nVertices{(int) strlen(vertexNames)};
	Graph	graph{nVertices};

	cout << "CS260 Undirected Graph" << endl << endl;

	cout << "     A-----B     F"	<< endl;
	cout << "    / \\   / \\   /"	<< endl;
	cout << "   /   \\ /   \\ /"	<< endl;
	cout << "  E     D-----C"		<< endl << endl;

	for (int i{0}; i < nVertices; i++)
		graph.createVertex(vertexNames[i]);

	graph.createEdge('A', 'B');
	graph.createEdge('A', 'D');
	graph.createEdge('A', 'E');
	graph.createEdge('B', 'C');
	graph.createEdge('B', 'D');
	graph.createEdge('C', 'D');
	graph.createEdge('C', 'F');

	cout << graph << endl;

	graph.traverse('A', Graph::TraversalOrder::BREADTH_FIRST, cout);
	cout << endl;

	graph.traverse('A', Graph::TraversalOrder::DEPTH_FIRST, cout);
	cout << endl;

	graph.traverse('F', Graph::TraversalOrder::BREADTH_FIRST, cout);
	cout << endl;

	graph.traverse('B', Graph::TraversalOrder::DEPTH_FIRST, cout);
	cout << endl;

	cout << endl;
	return 0;
}

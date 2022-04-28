#include <iostream>
using namespace std;
#include <limits.h>
#define totalVertices 9
int minimum_Distance(int distance[], bool shortest_distance[])
{
	int minimum_value = INT_MAX, min_index;

	for (int x = 0; x < totalVertices; x++)
		if (shortest_distance[x] == false && distance[x] <= minimum_value)
			minimum_value = distance[x], min_index = x;

	return min_index;
}
void display(int distance[])
{
	cout <<"total Distance from Source \t Vertex" << endl;
	for (int x= 0; x < totalVertices; x++)
		cout <<distance[x]<<"\t \t \t \t  "<< x << endl;
}
void function_dijkstra_algorithm(int graph_for_dijkstra_algorithm[totalVertices][totalVertices], int source_vertex)
{
	int distance[totalVertices];
	bool shortest_distance[totalVertices];

	for (int x = 0; x < totalVertices; x++)
		distance[x] = INT_MAX, shortest_distance[x] = false;

	distance[source_vertex] = 0;

	for (int y = 0; y < totalVertices - 1;y++)
        {
            int m = minimum_Distance(distance, shortest_distance);

            shortest_distance[m] = true;

            for (int z = 0; z < totalVertices; z++)
			if (!shortest_distance[z] && graph_for_dijkstra_algorithm[m][z] && distance[m] != INT_MAX && distance[m] + graph_for_dijkstra_algorithm[m][z] < distance[z])
				distance[z] = distance[m] + graph_for_dijkstra_algorithm[m][z];
	     }
	display(distance);
}
int main()
{
	int graph_for_dijkstra_algorithm[totalVertices][totalVertices] = {{ 0, 3, 0, 0, 1, 0, 0, 8, 0 },
			{ 5, 0, 8, 0, 0, 0, 0, 9, 0 },
			{ 0, 7, 0, 0, 0, 9, 0, 0, 2 },
			{ 0, 0, 5, 0, 19, 0, 0, 0, 20 },
			{ 0, 0, 0, 7, 0, 10, 0, 0, 2 },
			{ 0, 0, 4, 24, 0, 0, 0, 0, 10},
			{ 0, 0, 0, 12, 0, 0, 0, 11, 0 },
			{ 10, 0, 0, 0, 15, 0, 1, 0, 0 },
			{ 0, 0, 12, 0, 0, 0, 16, 0, 0 } };

	function_dijkstra_algorithm(graph_for_dijkstra_algorithm, 0);

	return 0;
}


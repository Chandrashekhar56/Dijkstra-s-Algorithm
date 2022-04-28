import sys
class dijkstra_algorithm():

	def __init__(self, total_vertices):
		self.Vertices = total_vertices
		self.graph_DijkstraAlgorithm = [[0 for cols in range(total_vertices)]
					for rows in range(total_vertices)]

	def display(self, distance):
		print("total Distance from Source \t Vertex")
		for x in range(self.Vertices):
			print(distance[x],"\t\t\t\t", x)
			
	def minimum_Distance(self, distance, shortes_distance):

		minimum_value = sys.maxsize

		for x in range(self.Vertices):
			if distance[x] <minimum_value and shortes_distance[x] == False:
				minimum_value = distance[x]
				minimum_index = x

		return minimum_index

	def function_dijkstra_algorithm(self, source):

		distance = [sys.maxsize] * self.Vertices
		distance[source] = 0
		shortes_distance = [False] * self.Vertices

		for z in range(self.Vertices):

			m= self.minimum_Distance(distance, shortes_distance)

			shortes_distance[m] = True

			for x in range(self.Vertices):
				if self.graph_DijkstraAlgorithm[m][x] > 0 and shortes_distance[x] == False and \
				distance[x] > distance[m] + self.graph_DijkstraAlgorithm[m][x]:
						distance[x] = distance[m] + self.graph_DijkstraAlgorithm[m][x]

		self.display(distance)

g1 = dijkstra_algorithm(9)
g1.graph_DijkstraAlgorithm= [ [ 0, 3, 0, 0, 1, 0, 0, 8, 0 ],
			[ 5, 0, 8, 0, 0, 0, 0, 9, 0 ],
			[ 0, 7, 0, 0, 0, 9, 0, 0, 2 ],
			[ 0, 0, 5, 0, 19, 0, 0, 0, 20],
			[ 0, 0, 0, 7, 0, 10, 0, 0, 2 ],
			[ 0, 0, 4, 24, 0, 0, 0, 0, 10],
			[ 0, 0, 0, 12, 0, 0, 0, 11, 0 ],
			[ 10, 0, 0, 0, 15, 0, 1, 0, 0 ],
			[ 0, 0, 12, 0, 0, 0, 16, 0, 0 ] ]
g1.function_dijkstra_algorithm(0);


#include <iostream>
#include <string>


void printGraph(std::string& adjacencyMatrixString, int verticesQuantity) {
	for (int i = 0; i < verticesQuantity; i++) {
		for (int j = 0; j < verticesQuantity; j++) {
			std::cerr << adjacencyMatrixString[i * verticesQuantity + j] << " ";
		}

		std::cerr << std::endl;
	}
}


void DFS(int vertex, bool* visited, std::string& adjacencyMatrixString, int verticesQuantity) {
	visited[vertex] = true;

	for (int i = 0; i < verticesQuantity; i++) {
		if (adjacencyMatrixString[vertex * verticesQuantity + i] == '1' && !visited[i]) {
			DFS(i, visited, adjacencyMatrixString, verticesQuantity);
		}
	}
}


bool cycleDFS(int vertex, int parent, bool* visited, std::string& adjacencyMatrixString, int verticesQuantity, int& verticesVisited) {
	visited[vertex] = true;
	verticesVisited++;

	for (int i = 0; i < verticesQuantity; i++) {
		if (adjacencyMatrixString[vertex * verticesQuantity + i] == '1') {
			if (!visited[i]) {
				if (cycleDFS(i, vertex, visited, adjacencyMatrixString, verticesQuantity, verticesVisited)) {
					return true;
				}
			}
			else if (i != parent) {
				return true;
			}
		}
	}

	return false;
}


bool hasOneCycle(std::string& adjacencyMatrixString, int verticesQuantity) {
	int cycles = 0;
	int verticesVisited = 0;
	bool* visited = new bool[verticesQuantity];

	for (int i = 0; i < verticesQuantity; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < verticesQuantity; i++) {
		if (!visited[i]) {

			verticesVisited = 0;

			if (cycleDFS(i, -1, visited, adjacencyMatrixString, verticesQuantity, verticesVisited)) {
				cycles++;
			}

			if (cycles > 1 or verticesVisited < verticesQuantity) {
				return false;
			}
		}
	}

	return (bool)(cycles == 1);
}


int main()
{
	int graphsQuantity = 0;
	std::cin >> graphsQuantity;

	for (int i = 0; i < graphsQuantity; i++) {
		int verticesQuantity = 0;
		std::string adjacencyMatrixString = "";
		std::cin >> verticesQuantity >> adjacencyMatrixString;

		printGraph(adjacencyMatrixString, verticesQuantity);

		if (hasOneCycle(adjacencyMatrixString, verticesQuantity)) {
			std::cout << "1" << std::endl;
		}
		else {
			std::cout << "0" << std::endl;
		}
	}

	return 0;
}

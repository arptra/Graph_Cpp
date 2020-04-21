#include <iostream>

using namespace std;

class graph {
private:
	int** adjMatrix{};
	int numVertices;
public:
	graph(int numVertices)
	{
		this->numVertices = numVertices;
		adjMatrix = new int*[numVertices];
		for (int i = 0; i < numVertices; i++)
		{
			adjMatrix[i] = new int[numVertices];
			for (int j = 0; j < numVertices; j++)
				adjMatrix[i][j] = 0;
		}
	}
	void addEdge(int i, int j, int weight)
	{
		adjMatrix[i][j] = weight;
		adjMatrix[j][i] = weight;
	}

	void removeEdge(int i, int j) {
		adjMatrix[i][j] = 0;
		adjMatrix[j][i] = 0;
	}

	int isEdge(int i, int j) {
		return adjMatrix[i][j];
	}
	void print_matrix() {
		for (int i = 0; i < numVertices; i++) {
			cout << i << " : ";
			for (int j = 0; j < numVertices; j++)
				cout << adjMatrix[i][j] << " ";
			cout << "\n";
		}
	}

	~graph() {
		for (int i = 0; i < numVertices; i++)
			delete[] adjMatrix[i];
		delete[] adjMatrix;
	}
};
int main()
{
	graph g(4);

	g.addEdge(0, 1, 3);
	g.addEdge(0, 2, 4);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 0,6);
	g.addEdge(2, 3, 9);
	g.print_matrix();
}

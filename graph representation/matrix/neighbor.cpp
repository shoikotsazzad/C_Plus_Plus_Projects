#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;
    int adjMatrix[MAX][MAX] = {0};
    int vertices, edges;

    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    cout << "Enter each edge (start end):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // assuming undirected graph
    }

    int vertex;
    cout << "Enter the vertex to see its neighbors: ";
    cin >> vertex;

    if (vertex < 0 || vertex >= vertices) {
        cout << "Invalid vertex number!" << endl;
        return 1;
    }

    cout << "Neighbors of vertex " << vertex << ": ";
    bool hasNeighbor = false;

    for (int j = 0; j < vertices; j++) {
        if (adjMatrix[vertex][j] == 1) {
            cout << j << " ";
            hasNeighbor = true;
        }
    }

    if (!hasNeighbor) {
        cout << "No neighbors found.";
    }

    cout << endl;
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    int adjMatrix[100][100] = {0}; // assuming max 100 vertices

    cout << "Enter each edge (start & end vertex):\n";

    // Input all edges
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        // Assuming undirected graph
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // Display adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

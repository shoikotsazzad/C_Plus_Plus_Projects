#include <iostream>
#include <queue>
using namespace std;

int main() {
    const int MAX = 100;
    int adjMatrix[MAX][MAX] = {0};
    int vertices, edges;

    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    // Input edges
    cout << "Enter each edge (start end):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    bool flag[MAX] = {false};          // Visited flag
    int visited_sequence[MAX];         // Store BFS order
    int visit_index = 0;               // Index for visited_sequence[]

    queue<int> q;
    q.push(start);
    flag[start] = true;

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();
        visited_sequence[visit_index++] = current_node;

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current_node][i] == 1 && !flag[i]) {
                q.push(i);
                flag[i] = true;
            }
        }
    }

    // Output the visited sequence
    cout << "\nBFS Visit Order: ";
    for (int i = 0; i < visit_index; i++) {
        cout << visited_sequence[i] << " ";
    }
    cout << endl;

    return 0;
}

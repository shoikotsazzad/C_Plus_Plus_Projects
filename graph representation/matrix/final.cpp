#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef vector<vector<int> > Graph;


bool isConnected(const Graph &G) {
    int V = G.size();
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int i = 0; i < V; i++) {
            if (G[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) return false;
    }

    return true;
}


bool isTreeUtil(const Graph &G, int u, vector<bool> &visited, int parent) {
    visited[u] = true;
    for (int v = 0; v < G.size(); v++) {
        if (G[u][v]) {
            if (!visited[v]) {
                if (!isTreeUtil(G, v, visited, u)) return false;
            } else if (v != parent) {
                return false; // cycle detected
            }
        }
    }
    return true;
}

bool isTree(const Graph &G) {
    int V = G.size();
    vector<bool> visited(V, false);
    if (!isTreeUtil(G, 0, visited, -1)) return false;
    return isConnected(G);
}


bool isBipartite(const Graph &G) {
    int V = G.size();
    vector<int> color(V, -1);

    for (int start = 0; start < V; start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v = 0; v < V; v++) {
                    if (G[u][v]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

bool isTwoColorable(const Graph &G) {
    return isBipartite(G);
}

int bfsLongestShortestPath(const Graph &G, int src) {
    int V = G.size();
    vector<int> dist(V, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);
    int maxDist = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < V; v++) {
            if (G[u][v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                if (dist[v] > maxDist) maxDist = dist[v];
                q.push(v);
            }
        }
    }

    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] == -1) return -1;
    }

    return maxDist;
}

int diameter(const Graph &G) {
    if (!isConnected(G)) return -1;

    int maxDiameter = 0;
    for (int i = 0; i < G.size(); i++) {
        int d = bfsLongestShortestPath(G, i);
        if (d > maxDiameter) maxDiameter = d;
    }
    return maxDiameter;
}


int cascadingFailureSteps(const Graph &G, int failedNode) {
    int V = G.size();
    vector<bool> failed(V, false);
    failed[failedNode] = true;

    int steps = 0;
    while (true) {
        vector<int> toFail;
        for (int i = 0; i < V; i++) {
            if (failed[i]) continue;
            int aliveNeighbors = 0;
            int totalNeighbors = 0;
            for (int j = 0; j < V; j++) {
                if (G[i][j]) {
                    totalNeighbors++;
                    if (!failed[j]) aliveNeighbors++;
                }
            }
            if (aliveNeighbors < totalNeighbors) {
                toFail.push_back(i);
            }
        }

        if (toFail.empty()) break;

        for (int i = 0; i < toFail.size(); i++) {
            failed[toFail[i]] = true;
        }

        steps++;
    }

    for (int i = 0; i < failed.size(); i++) {
        if (!failed[i]) return INT_MAX;
    }

    return steps;
}

int mostCriticalVertex(const Graph &G) {
    int V = G.size();
    int minSteps = INT_MAX;
    int criticalNode = -1;

    for (int i = 0; i < V; i++) {
        int steps = cascadingFailureSteps(G, i);
        if (steps < minSteps) {
            minSteps = steps;
            criticalNode = i;
        }
    }

    return criticalNode;
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph G(V, vector<int>(V, 0));
    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }

    cout << "Is Tree: " << (isTree(G) ? "Yes" : "No") << endl;
    cout << "Is Bipartite: " << (isBipartite(G) ? "Yes" : "No") << endl;
    cout << "Is 2-Colorable: " << (isTwoColorable(G) ? "Yes" : "No") << endl;
    cout << "Diameter: " << diameter(G) << endl;
    cout << "Most Critical Vertex: " << mostCriticalVertex(G) << endl;

    return 0;
}

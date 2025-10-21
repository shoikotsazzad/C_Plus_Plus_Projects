#include <iostream>
using namespace std;

int parent[100];
int sizeArr[100];

int findParent(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionNodes(int a, int b) {
    int rootA = findParent(a);
    int rootB = findParent(b);

    if (rootA != rootB) {
        if (sizeArr[rootA] < sizeArr[rootB]) {
            parent[rootA] = rootB;
            sizeArr[rootB] += sizeArr[rootA];
        } else {
            parent[rootB] = rootA;
            sizeArr[rootA] += sizeArr[rootB];
        }
    }
}

int main() {
    int n = 6;
    int m = 4;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sizeArr[i] = 1;
    }

    int edges[4][2] = {{0,1},{1,2},{3,4},{4,5}};
    for (int i = 0; i < m; i++) {
        unionNodes(edges[i][0], edges[i][1]);
    }

    int components = 0;
    for (int i = 0; i < n; i++) {
        if (findParent(i) == i)
            components++;
    }

    cout << components << endl;

    int queries[3][2] = {{0,2},{1,3},{3,5}};
    for (int i = 0; i < 3; i++) {
        int u = queries[i][0];
        int v = queries[i][1];

        if (findParent(u) == findParent(v))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDistance(const vector<int>& dist, const vector<bool>& used) {
    int mn = INT_MAX, idx = -1;
    for (int i = 0; i < (int)dist.size(); ++i)
        if (!used[i] && dist[i] <= mn) mn = dist[i], idx = i;
    return idx;
}

void dijkstra(const vector<vector<int>>& g, int src) {
    int V = g.size();
    vector<int> dist(V, INT_MAX);
    vector<bool> used(V, false);
    dist[src] = 0;

    for (int i = 0; i < V - 1; ++i) {
        int u = minDistance(dist, used);
        if (u == -1) break; // disconnected
        used[u] = true;
        for (int v = 0; v < V; ++v) {
            if (!used[v] && g[u][v] > 0 && dist[u] != INT_MAX &&
                dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }

    cout << "\nVertex\tDistance from Source (" << src << ")\n";
    for (int v = 0; v < V; ++v)
        cout << v << "\t" << dist[v] << "\n";
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> g(V, vector<int>(V));
    cout << "Enter weighted adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> g[i][j];

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(g, src);
    return 0;
}

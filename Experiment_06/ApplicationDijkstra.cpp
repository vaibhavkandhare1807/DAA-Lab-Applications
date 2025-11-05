#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int pickMin(const vector<int>& dist, const vector<bool>& used) {
    int mn = INT_MAX, idx = -1;
    for (int i = 0; i < (int)dist.size(); ++i)
        if (!used[i] && dist[i] < mn) mn = dist[i], idx = i;
    return idx;
}

void dijkstraCity(const vector<vector<int>>& g, const vector<string>& city, int src) {
    int n = g.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> used(n, false);
    dist[src] = 0;

    for (int iter = 0; iter < n - 1; ++iter) {
        int u = pickMin(dist, used);
        if (u == -1) break;
        used[u] = true;
        for (int v = 0; v < n; ++v) {
            if (!used[v] && g[u][v] > 0 && dist[u] != INT_MAX &&
                dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }

    cout << "\nShortest travel distances from " << city[src] << ":\n";
    for (int i = 0; i < n; ++i)
        cout << city[src] << " -> " << city[i] << " : " << dist[i] << " units\n";
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<string> city(n);
    cout << "Enter city names:\n";
    for (int i = 0; i < n; ++i) cin >> city[i];

    vector<vector<int>> g(n, vector<int>(n));
    cout << "Enter distance matrix (0 for no direct road, positive weights only):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];

    string srcName;
    cout << "Enter source city: ";
    cin >> srcName;

    int src = find(city.begin(), city.end(), srcName) - city.begin();
    if (src < 0 || src >= n) {
        cout << "Invalid source city.\n";
        return 0;
    }

    dijkstraCity(g, city, src);
    return 0;
}

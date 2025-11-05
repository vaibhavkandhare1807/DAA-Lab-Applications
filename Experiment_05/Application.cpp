#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent, rankv;
    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

int main() {
    int N, M;
    cout << "Enter number of offices (vertices) and possible links (edges): ";
    cin >> N >> M;

    if (N <= 0 || M <= 0) {
        cout << "Number of vertices and edges must be positive.\n";
        return 0;
    }

    vector<Edge> edges(M);
    cout << "Enter each link as: u v cost (0-based indices)\n";
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        if (edges[i].u < 0 || edges[i].u >= N || edges[i].v < 0 || edges[i].v >= N) {
            cout << "Invalid vertex index. Must be between 0 and " << N - 1 << ".\n";
            return 0;
        }
    }

    sort(edges.begin(), edges.end());
    DSU dsu(N);
    long long totalCost = 0;
    vector<Edge> mstEdges;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mstEdges.push_back(e);
            totalCost += e.w;
            if ((int)mstEdges.size() == N - 1)
                break;
        }
    }

    if ((int)mstEdges.size() != N - 1) {
        cout << "\n Not all offices can be connected (graph not connected).\n";
    } else {
        cout << "\n Minimum total cable cost: " << totalCost << "\n";
        cout << "Links used in MST:\n";
        for (auto &e : mstEdges)
            cout << e.u << " - " << e.v << " : " << e.w << "\n";
    }

    return 0;
}

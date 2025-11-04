#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0); 
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            if (rank[px] < rank[py]) swap(px, py);
            parent[py] = px;
            if (rank[px] == rank[py]) rank[px]++;
        }
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    DSU dsu(m * n);
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                for (const auto &dir : directions) { 
                    int dx = dir.first, dy = dir.second;
                    int ni = i + dx, nj = j + dy;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '.') {
                        dsu.unite(i * n + j, ni * n + nj);
                    }
                }
            }
        }
    }

    unordered_set<int> unique_components;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                unique_components.insert(dsu.find(i * n + j));
            }
        }
    }

    cout << unique_components.size() << '\n';
    return 0;
}

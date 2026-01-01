#include<bits/stdc++.h>
using namespace std;

pair<int, int> bfs(int u, vector<vector<int>>& g, vector<int>& vis) {
    queue<pair<int, int>> q;
    q.push({u, 0});
    vis[u] = 1;
    int farthest_node = u;
    int max_dist = 0;

    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();
        if (dist > max_dist) {
            max_dist = dist;
            farthest_node = node;
        }
        for (int neighbor : g[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push({neighbor, dist + 1});
            }
        }
    }
    return {farthest_node, max_dist};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<int> vis(n + 1, 0);
    auto [farthest, dist1] = bfs(1, g, vis);
    
    fill(vis.begin(), vis.end(), 0);
    auto [other_end, diameter] = bfs(farthest, g, vis);
    
    cout << diameter << "\n";
    return 0;
}
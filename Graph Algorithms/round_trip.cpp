#include<bits/stdc++.h>
using namespace std;

vector<int> dfs(int u, vector<vector<int>>&g, vector<int> &vis, vector<int> &p) {
    vis[u] = 1;
    for(auto v: g[u]){
        if(vis[v] == 0){
            p[v] = u;
            auto res = dfs(v, g, vis, p);
            if(!res.empty()){
                return res;
            }
        }
        else{
            if(v != p[u]){
                vector<int> cycle;
                cycle.push_back(v);
                int curr = u;
                while(v != curr){
                    cycle.push_back(curr);
                    curr = p[curr];
                }
                cycle.push_back(v);
                reverse(cycle.begin(), cycle.end());
                return cycle;
            }
        }
    }
    return {};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1, 0), p(n + 1, -1);
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            auto res = dfs(i, g, vis, p);
            if(!res.empty()){
                cout << res.size() << "\n";
                for(auto x: res){
                    cout << x << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}

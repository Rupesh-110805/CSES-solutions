#include <bits/stdc++.h>
using namespace std;

// Bi-Partite Check

bool check(int u, vector<vector<int>> &adj, vector<int> &t)
{
    t[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        /*for(int i = 0; i < adj[v].size(); i++){
            if(t[adj[v][i]] != 0) {
                return false;
            }
            q.push(adj[v][i]);
            t[adj[v][i]] = 3 - t[v];
        }*/
        for (int nei : adj[v])
        {
            if (t[nei] == 0)
            {
                t[nei] = 3 - t[v];
                q.push(nei);
            }
            else if (t[nei] == t[v])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(0));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> t(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (t[i] == 0)
        {
            if (check(i, adj, t) == false)
            {
                cout << "IMPOSSIBLE" << '\n';
                return 0;
            }
            else
            {
            };
        }
        else
        {
            continue;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << t[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


int dfs(int node , vector<vector<int>>& t, vector<int>& sub) {
    int count = 0;
    for(int child : t[node]) {
        count += 1 + dfs(child, t, sub);
    }
    sub[node] = count;
    return count;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> t;
    vector<int> sub;
    t.resize(n + 1);
    sub.resize(n + 1);
    
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        t[p].push_back(i);
    }
    
    dfs(1, t, sub);
    
    for(int i = 1; i <= n; i++){
        cout << sub[i];
        if(i < n) cout << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
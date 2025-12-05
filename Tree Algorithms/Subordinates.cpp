#include <bits/stdc++.h>
using namespace std;

int fn(int idx, const vector<vector<int>>& tree, vector<int>& dp) {
    if(dp[idx] != -1) {
        return dp[idx];
    }
    if (tree[idx].empty()) {
        return 0;  
    }
    int cnt = 0;
    for (int child : tree[idx]) {
        cnt += 1 + fn(child, tree, dp);  
    }
    return dp[idx] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    vector<int> dp(n + 1, -1);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        tree[x].push_back(i + 1);
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << fn(i, tree, dp) << " ";
    }
    cout << "\n";
    return 0;
}
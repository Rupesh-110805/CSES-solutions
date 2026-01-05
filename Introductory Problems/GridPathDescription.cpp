#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '
#define len(x) int((x).size())
#define vi vector<int>
#define vvi vector<vector<int>>

const int N = 7;
int ans = 0;
vvi vis(N, vi(N, 0));
string path;
bool fn(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

void dfs(int x, int y, int step) {
    if (step == N * N - 1 || (x == N - 1 && y == 0)) {
        ans += (step == N * N - 1 && (x == N - 1 && y == 0));
        return;
    }


    if ((!fn(x - 1, y) || vis[x - 1][y]) && (!fn(x + 1, y) || vis[x + 1][y]))
        if (fn(x, y - 1) && !vis[x][y - 1] && fn(x, y + 1) && !vis[x][y + 1])
            return;


    if ((!fn(x, y - 1) || vis[x][y - 1]) && (!fn(x, y + 1) || vis[x][y + 1]))
        if (fn(x - 1, y) && !vis[x - 1][y] && fn(x + 1, y) && !vis[x + 1][y])
            return;

    vis[x][y] = 1;


    if (path[step] == '?' || path[step] == 'L')
        if (fn(x, y - 1) && !vis[x][y - 1])
            dfs(x, y - 1, step + 1);

    if (path[step] == '?' || path[step] == 'R')
        if (fn(x, y + 1) && !vis[x][y + 1])
            dfs(x, y + 1, step + 1);

    if (path[step] == '?' || path[step] == 'U')
        if (fn(x - 1, y) && !vis[x - 1][y])
            dfs(x - 1, y, step + 1);

    if (path[step] == '?' || path[step] == 'D')
        if (fn(x + 1, y) && !vis[x + 1][y])
            dfs(x + 1, y, step + 1);

    vis[x][y] = 0;
}

void solve() {
    cin >> path;
    dfs(0, 0, 0);

    cout << ans << '\n';
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
}
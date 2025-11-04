#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define pii pair<int, int>

vector<char> path;
const int dr[] = {-1, 1, 0, 0}; 
const int dc[] = {0, 0, -1, 1};
const char dir_char[] = {'U', 'D', 'L', 'R'};

bool bfs(int sr, int sc, vector<vector<char>> &grid, vector<vector<char>> &dirs, vector<vector<bool>> &vis) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pii> q;
    q.push({sr, sc});
    vis[sr][sc] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (grid[r][c] == 'B') {
            while (!(r == sr && c == sc)) {
                char d = dirs[r][c];
                path.push_back(d);
                if (d == 'U') r++;
                else if (d == 'D') r--;
                else if (d == 'L') c++;
                else if (d == 'R') c--;
            }
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] != '#') {
                q.push({nr, nc});
                vis[nr][nc] = true;
                dirs[nr][nc] = dir_char[i];
            }
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int sr, sc; 
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<char>> dirs(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                sr = i;
                sc = j;
            }
        }
    }

    if (bfs(sr, sc, grid, dirs, vis)) {
        cout << "YES\n";
        cout << path.size() << "\n";
        reverse(path.begin(), path.end());
        for (char ch : path) cout << ch;
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    path.clear(); 
}

int main() {
    fastio
    solve();
    return 0;
}

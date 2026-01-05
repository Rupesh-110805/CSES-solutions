#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    grid[0][0] = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<pair<int,int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        int x = front.first;
        int y = front.second;
        for(auto dir : directions){
            int dx = dir.first;
            int dy = dir.second;
            int nx = x + dx;
            int ny = y + dy;
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && !(nx == 0 && ny == 0)){
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
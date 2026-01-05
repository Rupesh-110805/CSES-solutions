#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> mp;
    long long ans = 0;
    int i = 0, j = 0;
    while (j < n) {
        mp[arr[j]]++; 

        while (mp[arr[j]] > 1) {  
            mp[arr[i]]--;
            if (mp[arr[i]] == 0)
                mp.erase(arr[i]);
            i++;
        }
        ans += mp.size(); 
        j++;
    }

    cout << ans << '\n';
}  

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
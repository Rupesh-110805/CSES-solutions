#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    
    vector<long long> arr(k);
    long long sum = 0;
    long long ans = 0;
    int idx = 0;
    
    for (int i = 0; i < n; i++) {
        if (i >= k) {
            sum -= arr[idx];
        }
        arr[idx] = x;
        sum += x;        
        idx = (idx + 1) % k;        
        if (i >= k - 1) {
            ans ^= sum;
        }        
        x = (a * x + b) % c;
    }
    
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
ll modInverse(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

int main()
{
    int t, M = 0;
    cin >> t;
    vector<pair<int, int>> inputs;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        M = max(max(M, a), b);
        inputs.push_back({a, b});
    }
    vector<ll> fact(M + 1, 1);
    for (int i = 2; i <= M; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    for (auto p : inputs){
        int n = p.first, k = p.second;
        ll res = (fact[n] * modInverse((fact[k] * fact[n - k]) % MOD, MOD)) % MOD;
        cout << res << endl;
    }
    return 0;
}
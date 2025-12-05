#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mex(vector<ll> &v)
{
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll m = 0;
    for (ll x : v)
    {
        if (x == m)
        {
            ++m;
        }
        else if (x > m)
        {
            break;
        }
    }
    return m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll limit = 2000;
    vector<ll> g(limit + 1, 0);
    g[0] = g[1] = g[2] = 0;
    for (ll i = 3; i <= limit; ++i)
    {
        vector<ll> s;
        for (ll j = 1; 2*j < i; ++j)
        {
            s.push_back(g[j] ^ g[i - j]);
        }
        g[i] = mex(s);
    }

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n <= limit)
        {
            cout << (g[n] ? "first" : "second") << "\n";
        }
        else
        {
            cout << "first\n";
        }
    }
    return 0;
}
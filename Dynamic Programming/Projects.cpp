#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Project {
    int start, end;
    ll reward;
};

bool cmp(const Project &a, const Project &b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    vector<Project> projects(n);
    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(projects.begin(), projects.end(), cmp);

    vector<ll> dp(n);
    vector<int> ends(n); 
    for (int i = 0; i < n; ++i) {
        ends[i] = projects[i].end;
    }

    dp[0] = projects[0].reward;
    for (int i = 1; i < n; ++i) {
        
        int l = 0, r = i - 1, j = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (projects[mid].end < projects[i].start) {
                j = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        dp[i] = max(dp[i - 1], (j != -1 ? dp[j] : 0LL) + projects[i].reward);
    }

    cout << dp[n - 1] << '\n';
    return 0;
}

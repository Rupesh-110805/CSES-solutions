#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    multiset<int> window(v.begin(), v.begin() + K);
    auto mid = next(window.begin(), K / 2);

    for (int i = K; i <= N; i++) {
        cout << (*mid);
        if (i < N) {
            window.insert(v[i]);
            if (v[i] < *mid) {
                mid--;
            }
            if (v[i - K] <= *mid) {
                mid++;
            }
            window.erase(window.lower_bound(v[i - K]));
        }
        cout << " ";
    }

    return 0;
}


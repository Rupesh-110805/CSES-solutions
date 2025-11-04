#include <bits/stdc++.h>
using namespace std;

int fn(string s) {
    int val = 1;
    int max = 1;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            val++;
        } else {
            if (val > max) {
                max = val;
            }
            val = 1; 
        }
    }
    if (val > max) {
        max = val;
    }
    return max;
}

int main() {
    string s;
    cin >> s;
    cout << fn(s) << endl;
    return 0;
}
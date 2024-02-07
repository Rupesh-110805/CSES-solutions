#include <iostream>
#include <vector>

using namespace std;

vector<int> fn(int n) {
    vector<int> sol;
    if(n==1){
        sol.push_back(1);
    }
    // A permutation is beautiful if no two elements adjacent are with difference equal to one
    if(n!=1){
    if (n < 4) {
        cout << "NO SOLUTION" << endl;
    } else {
        for (int i = 2; i <= n; i += 2) {
            sol.push_back(i);
        }
        for (int i = 1; i <= n; i += 2) {
            sol.push_back(i);
        }
    }
    }
    return sol;
}

int main() {
    int n;
   // cout << "Enter the n: ";
    cin >> n;
    cout << "\n";
    vector<int> sol = fn(n);
    if (sol.size() > 0) {
        for (auto i : sol) {
            cout << i << " ";
        }
    }
    return 0;
}

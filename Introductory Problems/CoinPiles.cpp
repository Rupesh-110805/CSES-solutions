#include <iostream>
using namespace std;

string fn(int x, int y) {
    int total = x + y;
    if (total % 3 == 0 && min(x, y) * 2 >= max(x, y)) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int x, y;
        cin >> x >> y;
        cout << fn(x, y) << endl;
    }
    return 0;
}


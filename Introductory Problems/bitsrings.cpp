#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long int n;
    cin >> n;
    int val = 2;
    while (n > 1) {
        val = (val * 2) % int(pow(10, 9) + 7);
        n--;
    }
    cout << val;
    return 0;
}

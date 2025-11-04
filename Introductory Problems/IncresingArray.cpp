#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    long long moves = 0;
    int prev;
    cin >> prev;

    for (int i = 1; i < n; i++)
    {
        int current;
        cin >> current;

        if (current < prev)
        {

            moves += (long long)(prev - current);
        }
        else
        {
            prev = current;
        }
    }
    cout << moves << endl;

    return 0;
}

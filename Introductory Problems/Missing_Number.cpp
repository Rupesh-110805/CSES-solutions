#include <bits/stdc++.h>
using namespace std;
int findMissingNumber(int n, const vector<int> &arr)
{
    vector<bool> seen(n + 1, false);

    for (int num : arr)
    {
        seen[num] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!seen[i])
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    int missingNumber = findMissingNumber(n, arr);
    cout << missingNumber << endl;

    return 0;

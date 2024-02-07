#include <iostream>
using namespace std;
void fn(long n)
{
    if (n < 1)
        return;
    cout << n << " ";
    if (n == 1)
        return;
    if (n % 2 == 1)
    {
        fn(3 * n + 1);
    }
    if (n % 2 == 0)
    {
        fn(n / 2);
    }
}
int main()
{
    long N;
    cin >> N;
    fn(N);
}
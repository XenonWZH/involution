// Q1.4.1.4. 过河问题2
// WzhDnwzWzh

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, t[2001], ans = 0, i, j;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];

    sort(t + 1, t + n + 1);
    if (n % 2 == 0 && t[1] + t[n / 2] > 2 * t[2])
    {
        ans += 2 * t[2];
        n--;
    }
    for (i = 3; 4 * t[2] > t[1] + t[i] && i < n; i++);
    if (4 * t[2] <= t[1] + t[i])
        i--;
    for (j = n; j >= 2 * i; j--)
        ans += 2 * t[2];
    for (j = (2 * i <= n ? i : ceil(n / 2.0)); j >= 2; j--)
        ans += t[1] + t[j];
    ans -= t[1];

    cout << ans << endl;
    return 0;
}
// Q1.5.5.5. 水星人
// WzhDnwzWzh

#include <bits/stdc++.h>

using namespace std;

unsigned long long a[21];
bool used[21] = {0};
unsigned long long m, n;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int x = a[i];
        for (int j = 1; j <= a[i]; j++)
            x -= used[j];
        used[a[i]] = 1;
        a[i] = x - 1;
    }

    a[n] += m;
    for (int i = n; i > 0; i--)
    {
        a[i - 1] += a[i] / (n - i + 1);
        a[i] %= n - i + 1;
    }

    memset(used, 0, sizeof(used));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= a[i]; j++)
            if (used[j])
                a[i]++;
        cout << a[i] + 1 << " ";
        used[a[i]] = 1;
    }
    cout << endl;
    return 0;
}
// Q2.2.1.3. 算24点
// WzhDnwzWzh

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

double f(double x, int k, double y)
{
    if (k == 0)
        return x + y;
    else if (k == 1)
        return x - y;
    else if (k == 2)
        return x * y;
    else
        return x / y;
}

int main()
{
    double a[5];
    int ans[101];
    int t;
    string s;
    memset(ans, 0, sizeof(ans));

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        for (int j = 0; j < 4; j++)
        {
            if (s[j] == 'O')
                a[j] = 10;
            else if (s[j] == 'A')
                a[j] = 1;
            else if (s[j] == 'J')
                a[j] = 11;
            else if (s[j] == 'Q')
                a[j] = 12;
            else if (s[j] == 'K')
                a[j] = 13;
            else
                a[j] = s[j] - '0';
        }

        sort(a, a + 4);
        do
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        if (f(f(f(a[0], j, a[1]), k, a[2]), l, a[3]) == 24)
                            ans[i] = 1;
                        else if (f(f(a[0], j, f(a[1], k, a[2])), l, a[3]) == 24)
                            ans[i] = 1;
                        else if (f(a[0], j, f(f(a[1], k, a[2]), l, a[3])) == 24)
                            ans[i] = 1;
                        else if (f(f(a[0], j, a[1]), l, f(a[2], k, a[3])) == 24)
                            ans[i] = 1;
                        else if (f(a[0], j, f(a[1], k, f(a[2], l, a[3]))) == 24)
                            ans[i] = 1;
                    }
                }
            }
        } while (next_permutation(a, a + 4));
    }

    for (int i = 0; i < t; i++)
    {
        cout << ans[i] << ' ';
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    if (t % 10 != 0)
        cout << endl;
    return 0;
}

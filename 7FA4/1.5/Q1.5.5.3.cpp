// Q1.5.5.3. 多项式加减乘
// WzhDnwzWzh

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int f1[1001], f2[1001], ans[1000001], n1, n2, n_ans;
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    memset(ans, 0, sizeof(ans));

    cin >> n1 >> n2;
    for (int i = 0; i <= n1; i++)
        cin >> f1[i];
    for (int i = 0; i <= n2; i++)
        cin >> f2[i];

    n_ans = n1 < n2 ? n2 : n1;
    for (int i = 0; i <= n_ans; i++)
        ans[i] = f1[i] + f2[i];
    while (ans[n_ans] == 0 && n_ans >= 1)
        n_ans--;
    for (int i = 0; i <= n_ans; i++)
        cout << ans[i] << " ";
    cout << endl;

    memset(ans, 0, sizeof(ans));
    n_ans = n1 < n2 ? n2 : n1;
    for (int i = 0; i <= n_ans; i++)
        ans[i] = f1[i] - f2[i];
    while (ans[n_ans] == 0 && n_ans >= 1)
        n_ans--;
    for (int i = 0; i <= n_ans; i++)
        cout << ans[i] << " ";
    cout << endl;

    memset(ans, 0, sizeof(ans));
    n_ans = n1 * n2;
    for (int i = 0; i <= n1; i++)
        for (int j = 0; j <= n2; j++)
            ans[i + j] += f1[i] * f2[j];
    while (ans[n_ans] == 0 && n_ans >= 1)
        n_ans--;
    for (int i = 0; i <= n_ans; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
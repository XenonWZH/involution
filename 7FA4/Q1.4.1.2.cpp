// Q1.4.1.2. 纸牌游戏
// WzhDnwzWzh

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int card[1001], tmp[1001], n, cntu = 0, cntd = 0, sum = 0;
    bool next = true;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> card[i];
        sum += card[i];
    }
    if (sum != (n * n + n) / 2)
    {
        cout << "-1" << endl;
        return 0;
    }

    memcpy(tmp, card, sizeof(card));
    for (int i = 1; i < n; i++)
    {
        if (tmp[i] != i)
            cntu++;
        tmp[i + 1] += tmp[i] - i;
        tmp[i] = i;
    }
    memcpy(tmp, card, sizeof(card));
    for (int i = 1; i < n; i++)
    {
        if (tmp[i] != n + 1 - i)
            cntd++;
        tmp[i + 1] += tmp[i] - n - 1 + i;
        tmp[i] = n + 1 - i;
    }

    cout << (cntu < cntd ? cntu : cntd) << endl;
    return 0;
}
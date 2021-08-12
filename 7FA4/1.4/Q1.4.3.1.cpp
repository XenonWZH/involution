// Q1.4.3.1. 合并果子2
// WzhDnwzWzh

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, ans = 0, tmp;
    priority_queue<int, vector<int>, greater<int> > a;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push(tmp);
    }

    tmp = 0;
    for (int i = 0; i < (n % 3 <= 1 ? n % 3 + 3 : n % 3); i++)
        if (!a.empty())
        {
            tmp += a.top();
            a.pop();
        }
    ans += tmp;
    a.push(tmp);
    while (a.size() > 1)
    {
        tmp = 0;
        for (int i = 0; i < 4; i++)
            if (!a.empty())
            {
                tmp += a.top();
                a.pop();
            }
        ans += tmp;
        a.push(tmp);
    }

    cout << ans << endl;
    return 0;
}
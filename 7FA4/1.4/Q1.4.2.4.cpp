// Q1.4.2.4. 狂暴的老师2
// WzhDnwzWzh

#include <iostream>
#include <algorithm>

using namespace std;

struct student
{
    int t, p, c;
};

bool comp(student a, student b)
{
    return max(b.c - a.p, a.t - b.p) < max(a.c - b.p, b.t - a.p);
}

int main()
{
    int n, time = 0, ans, tmp;
    student st[3000];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> st[i].t >> st[i].p >> st[i].c;

    sort(st, st + n, comp);
    tmp = time - st[0].p;
    for (int j = 1; j < n; j++)
        tmp += st[j].c;
    ans = tmp;
    time += st[0].t;
    for (int i = 1; i < n; i++)
    {
        tmp = time - st[i].p;
        for (int j = i + 1; j < n; j++)
            tmp += st[j].c;
        if (ans < tmp)
            ans = tmp;
        time += st[i].t;
    }

    cout << ans << endl;
    return 0;
}
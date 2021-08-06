// Q1.4.2.3. 狂暴的老师
// WzhDnwzWzh

#include <iostream>
#include <algorithm>

using namespace std;

struct student
{
    int t, p;
};

bool comp(student a, student b)
{
    return a.t + a.p < b.t + b.p;
}

int main()
{
    int n, time = 0, ans = 0;
    student st[1000];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> st[i].t >> st[i].p;

    sort(st, st + n, comp);
    ans = -st[0].p, time = st[0].t;
    for (int i = 1; i < n; i++)
    {
        if (time - st[i].p > ans)
            ans = time - st[i].p;
        time += st[i].t;
    }

    cout << ans << endl;
    return 0;
}
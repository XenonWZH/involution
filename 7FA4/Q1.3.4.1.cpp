// Q1.3.4.1. 求排名
// WzhDnwzWzh

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct student
{
    int a, c, d;
};

bool comp1(student a, student b)
{
    if (a.a != b.a)
        return a.a > b.a;
    else
        return a.c < b.c;
}

bool comp2(student a, student b)
{
    return a.c < b.c;
}

int main()
{
    int n;
    student a[1000], b[1000];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].a;
        a[i].c = i + 1;
    }

    sort(a, a + n, comp1);
    for (int i = 0; i < n; i++)
        a[i].d = i + 1;
    memcpy(b, a, sizeof(a));
    sort(b, b + n, comp2);

    for (int i = 0; i < n; i++)
        cout << a[i].c << " " << b[i].d << endl;
    return 0;
}